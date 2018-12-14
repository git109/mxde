/*
        hpscanpbm
        User-level SCSI HP Scanjet driver
        Written by David Etherton, etherton@netcom.com
        HPUX Port by John Fehr, fehr@ninja.aes.mb.doe.ca
        Little hacks by Steve Enns  ennss@nhrisv.nhrc.sk.doe.ca
        Copyright 1995, David Etherton
        Released under the terms of the GPL.
        *NO WARRANTY*

        Thanks to Les Johnson (les@ulysses.homer.att.com) for
        suggesting some Linux documentation clarifications.

 Modified for FreeBSD and HP ScanJet5 by Luigi Rizzo
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> /* varargs... */
#include <string.h> /* str... */
#include <fcntl.h>
#include <sys/scsiio.h>
#include </sys/scsi/scsi_all.h>

#define BLKSZ	4000

typedef int ScsiStatus;
 
typedef struct scsi_sense_data *ScsiSense;
typedef struct scsi_inquiry_data *ScsiInquiry;

typedef enum { PNM, RAW, LJ } out_format ;


/* this might eventually go into a header file */
#define THRESHOLDED     0
#define DITHERED        1
#define GREYSCALE       2
#define TRUECOLOR       3

#define	UNIT	300.0	/* native unit of measure */
typedef struct {
    int             xdpi, ydpi;
    int             xres, yres;	/* in pixels */
    int             x, y, width, height;	/* in 1/UNIT inches */
    int             format;
    double          brightness, contrast;
    int             bpp;
    out_format	    ofmt ;
}               ScanSettings;

/*
 * default is 200dpi binarized A4 image. This corresponds to
 * hires fax.
 */
ScanSettings settings = {
    200, 200,		/* xdpi, ydpi			*/
    0, 0,		/* xres, yres, pixels		*/
    0, 0,		/* xofs, yofs 1/UNIT		*/
#if 1 /* A4 size, 21x29.7mm */
    21*UNIT/2.54, 29.7*UNIT/2.54,	/* wid, hei 1/UNIT */
#else /* USletter, 8.5*11in */
    8.5*UNIT, 11*UNIT,
#endif
    THRESHOLDED,		/* format		*/
    0.0, 0.0,		/* brightness, contrast		*/
    8,			/* bpp (usually 8, or 8/4 for grey) */
    PNM			/* out format (PNM, LJ, ...)	*/
};

int 
min(int a, int b)
{
    return a < b ? a : b;
}

static int      quiet;

static int
decode_status(ScsiStatus status, ScsiSense sense, char *name)
{
    if (status == 0)             /* Success */
        return 0;

    if (status == -1) {          /* Error from ioctl */
        perror(name);
        return -1;
    }
    
    if (status > 256) {          /* Error in scsi command */
        fprintf(stderr, "%s: error %d\n", name, status - 256);
        return -1;
    }
    
    if (status == 2) {           /* Sense data available */
        fprintf(stderr, "%s: sense error %d\n", name, sense->error_code);
        return -1;
    }
    
    /* Other scsi error */

    fprintf(stderr, "%s: scsi error %d\n", name, status);
    return -1;
}



/*
 * Send a command to the scanner.
 * The number of bytes transferred is returned.  
 * If an error occurs sending the command, -1 is returned and and
 * error message printed.  (This applies only to errors detected
 * by the operating system; not SCL errors.)
 */

static ScsiStatus
scsi_do_command(int fd, scsireq_t *req, ScsiSense *sense)
{   
    req->senselen = SENSEBUFLEN;
    req->timeout = 30000;               /* milliseconds */
    
    if (ioctl(fd, SCIOCCOMMAND, req) == -1)
        return -1;
    
    if (req->retsts != SCCMD_OK)
        return req->retsts + 256;

    /* Has OS filled in sense data?  I dunno. */
    *sense = req->status == 2 ? (ScsiSense)req->sense : 0;
    
    return req->status;
}   

#define SEND 0x0a
#define RECEIVE 0x08
struct scsi_send_receive {   
    u_char op_code;
    u_char byte2;
    u_char length[3];
    u_char unused;
};  
 
ScsiStatus
scsi_send(int fd, ScsiSense *sense, u_char *data, int *len)
{   
    static scsireq_t req;
    struct scsi_send_receive *cmd = (struct scsi_send_receive *)&req.cmd;
    ScsiStatus status;
    
    cmd->op_code = SEND;
    cmd->length[0] = (u_char)(*len >> 16);
    cmd->length[1] = (u_char)(*len >> 8);
    cmd->length[2] = (u_char)(*len >> 0);
    req.cmdlen = sizeof(*cmd);
    req.databuf = data;
    req.datalen = *len;
    req.flags = SCCMD_WRITE;
    
    status = scsi_do_command(fd, &req, sense);
    
    /* Unfortunately, datalen_used seems to be wrong in case of error */
    *len = req.datalen_used;
    
    return status;
}   

ScsiStatus
scsi_receive(int fd, ScsiSense *sense, u_char *data, int *len)
{   
    static scsireq_t req;
    struct scsi_send_receive *cmd = (struct scsi_send_receive *)&req.cmd;
    ScsiStatus status;
    
    cmd->op_code = RECEIVE;
    cmd->length[0] = (u_char)(*len >> 16);
    cmd->length[1] = (u_char)(*len >> 8);
    cmd->length[2] = (u_char)(*len >> 0);
    req.cmdlen = sizeof(*cmd);
    req.databuf = data;
    req.datalen = *len;
    req.flags = SCCMD_READ;
    
    status = scsi_do_command(fd, &req, sense);
#if 0
    fprintf(stderr, "do_command returns %d bytes\n", req.datalen_used);
#endif
    if (*len == req.datalen_used) {
#if 0
	fprintf(stderr, "boh...\n");
	data[*len -1] = 0;
#endif
    } else {
	data[req.datalen_used] = 0 ;
    }

    /* Unfortunately, datalen_used seems to be wrong in case of error */
    *len = req.datalen_used;
    
    return status;
}   

int
scanner_send(int fd, char *data, int length)
{
    ScsiStatus status;
    ScsiSense sense;
    char buf[128];
    
    status = scsi_send(fd, &sense, data, &length);

    if (decode_status(status, sense, "scanner_send") == -1) {
	strncpy(buf, data, length);
	buf[length] = 0;
	fprintf(stderr, "scanner_send %s: status is %d\n", data, status);
        return -1;
    }
    else
        return length;
    
}

/*
 * Receive some data from the scanner. 
 * The number of bytes transferred is returned.
 * If an error occurs sending the command, -1 is returned and and
 * error message printed.  (This applies only to errors detected
 * by the operating system; not SCL errors.)
 */ 
        
int
scanner_receive(int fd, char *data, int length)
{   
    ScsiStatus status;
    ScsiSense sense; 
    
    status = scsi_receive(fd, &sense, data, &length);
    
    if (decode_status(status, sense, "scanner_receive") == -1)
        return -1;
    else
        return length;
}

int
inquire (int fd, char *s)
{
    char buf[2048];
    char *p;

    bzero(buf, sizeof(buf));
    scanner_send(fd, s, strlen(s));
    scanner_receive(fd, buf, sizeof(buf));
#if 0
    fprintf(stderr, "%s --> %s\n", s+1, buf+1);
#endif
    p = strchr(buf,'d');
    if (p)
        return atoi(strchr(buf,'d') + 1);
    else
 	return -1 ;
}

void 
write_string(int fid, char *format,...)
{
    va_list         args;
    char            buf[1024];
    va_start(args, format);
    vsprintf(buf, format, args);
#if 1
    scanner_send(fid, buf, strlen(buf));
#else
    inquire(fid, buf);
#endif
}

int 
norm8(double value)
{
    if (value < -1.0)
	value = -1.0;
    else if (value > 1.0)
	value = 1.0;
    return (int) (value * 127.0);
}

void 
do_scan(char *dest, int fid, ScanSettings * ss)
{
    char    buf[BLKSZ];
    int     lmax, len, mode;
    FILE    *f = dest ? fopen(dest, "w") : stdout;
    int     pixels_per_line, bytes_per_line, lines, tot_bytes;

    /* reset scanner; returns all paramters to defaults */
    write_string(fid, "\033E");

    /* set resolution, in DPI */
    write_string(fid, "\033*a%dR", ss->xdpi);
    write_string(fid, "\033*a%dS", ss->ydpi);

#if 0
	/*
	 * sizes in decipoints. Not supported by the Scanjet5p
	 */
#define SIZE_PREFIX "\033*a"
#else
	/*
	 * sizes in 1/UNIT of an inch
	 */
#define SIZE_PREFIX "\033*f"
#endif
    /* set scan extents */
    write_string(fid, "%s%dX", SIZE_PREFIX, ss->x);
    write_string(fid, "%s%dY", SIZE_PREFIX, ss->y);
    write_string(fid, "%s%dP", SIZE_PREFIX, ss->width);
    write_string(fid, "%s%dQ", SIZE_PREFIX, ss->height);

    /* (the original scanjet only allows -1, 0, or 1) */
    write_string(fid, "\033*a%dL", norm8(ss->brightness));
    write_string(fid, "\033*a%dK", norm8(ss->contrast));

    /*
     * greyscale and color modes seems to need to have their outputs
     * inverted; thresholded and dithered modes do not (the default)
     */
    if (ss->format > DITHERED)
	write_string(fid, "\033*a1I");
    mode = 4;
    /*
     * data format is thresholded by default; pixel format is 8 pixels/byte
     */
    if (ss->format == DITHERED) {
	/* data format: dithered */
	write_string(fid, "\033*a3T");
    } else if (ss->format == GREYSCALE) {
	/*
	 * data format is greyscale, pixel format is one pixel/byte
	 */
	write_string(fid, "\033*a4T");
	write_string(fid, "\033*a%dG", ss->bpp); /* 8bits/pixel... */
	mode = 5;
    } else if (ss->format == TRUECOLOR) {
	/*
	 * data format is 24bit color, pixel format is one pixel/three bytes
	 */
	write_string(fid, "\033*a5T");
	write_string(fid, "\033*a%dG", ss->bpp*3); /* 24 bits/pixel... */
	mode = 6;
    }
    /* inquire resulting size of image after setting it up */
    pixels_per_line = inquire(fid, "\033*s1024E");
    bytes_per_line = inquire(fid, "\033*s1025E");
    lines = inquire(fid, "\033*s1026E");

    if (!quiet) {
	fprintf(stderr, "%d pixels per line, %d bytes, %d lines high\n",
		pixels_per_line, bytes_per_line, lines);
	fprintf(stderr, "xdpi %d, ydpi %d\n", ss->xdpi, ss->ydpi);
    }
    lmax = sizeof(buf) ;

    switch (ss->ofmt) {
    case PNM :
	fprintf(f, "P%d\n# created by hpscanpbm\n%d %d\n",
	    mode, pixels_per_line, lines);
	if (mode > 4)
	    fprintf(f, "%d\n", (1 << ss->bpp) - 1);
	break ;
    case LJ :
	lmax = (lmax / bytes_per_line) * bytes_per_line ;

	    /* ljII cmd: reset, top margin 0, res., enter gr. */
	fprintf(f, "\033E" "\033&l0E" "\033*t%dR" "\033*r1A",
	    ss->xdpi);
	break;
    case RAW: /* no action for raw mode */
	break ;
    }
    tot_bytes = bytes_per_line * lines;
    write_string(fid, "\033*f0S");	/* begin scan! */

    /* consume all data */
    while (tot_bytes > 0 &&
	(len = scanner_receive(fid, buf, min(lmax, tot_bytes)))) {
	u_char buf1[2*BLKSZ] ;
	int j ;
	u_char *b ;

	tot_bytes -= len ;

	switch (ss->ofmt) {
	case LJ : /* LJ outout -- only for grey */
	    for (j = 0 ; j < len ; j += bytes_per_line) {
		fprintf(f, "\033*b%dW", bytes_per_line);
		fwrite(buf+j, bytes_per_line, 1, f);
	    }
	    break ;

	case RAW :
	    fwrite(buf, len, 1, f);
	    break ;

	case PNM :
	    switch (ss->bpp) {
	    case 8 : /* working with 8bits/pixel */
		fwrite(buf, len, 1, f);
		break ;
	    case 4 :
		for (j=0, b = buf1 ; j<len ; j++) {
		    *b++ = (buf[j] >> 4) & 0xf ;
		    *b++ = buf[j] & 0xf ;
		}
		fwrite(buf1, 2*len, 1, f);
		break ;
	    }
	}
    }
    if (ss->ofmt == LJ)
	fprintf(f, "\033*rB" ); /* end raster */

    if (dest)
	fclose(f);
}

int 
find_hp_scanner(void)
{
    int fd;
    char *s = "/dev/scanner";

    if ((fd = open(s, O_RDWR)) != -1) {
	if (!quiet)
	    fprintf(stderr, "HP Scanjet found on '%s'\n", s);
    }
    return fd;
}

int 
loadsettings(char *filename)
{
    FILE           *fin;
    if ((fin = fopen(filename, "rb")) == NULL) {
	fprintf(stderr, "Can't open settings file %s for read.\n", filename);
	exit(1);
    }
    if (fread(&settings, sizeof(settings), 1, fin) != 1) {
	fprintf(stderr, "Can't read settings file %s\n", filename);
	exit(1);
    }
    return 0;
}


int 
savesettings(char *filename)
{
    FILE           *fin;
    if ((fin = fopen(filename, "wb")) == NULL) {
	fprintf(stderr, "Can't open settings file %s for write.\n", filename);
	exit(1);
    }
    if (fwrite(&settings, sizeof(settings), 1, fin) != 1) {
	fprintf(stderr, "Can't write settings file %s\n", filename);
	exit(1);
    }
    return 0;
}


#define nextargi (--argc, atoi(*++argv))
#define nextargf (--argc, atof(*++argv))
#define nextargs (--argc, *++argv)

void 
main(int argc, char **argv)
{
    double          posfactor = UNIT;

    char           *devname = (char *) 0, *outname = (char *) 0;
    int             fd;

    while (--argc && **++argv == '-') {
	if (!strcmp(argv[0], "-l") || !strcmp(argv[0], "-load"))
	    loadsettings(nextargs);
	else if (!strcmp(argv[0], "-dpi"))
	    settings.xdpi = settings.ydpi = nextargi;
	else if (!strcmp(argv[0], "-xdpi"))
	    settings.xdpi = nextargi;
	else if (!strcmp(argv[0], "-ydpi"))
	    settings.ydpi = nextargi;

	else if (!strcmp(argv[0], "-lj")) {
	    settings.ofmt = LJ ;
	    settings.xdpi = settings.ydpi = 300;
	}
	else if (!strcmp(argv[0], "-faxh")) {
	    settings.format = THRESHOLDED;
	    settings.ofmt = PNM ;
	    settings.xdpi = settings.ydpi = 200;
	}
	else if (!strncmp(argv[0], "-fax", 4) ) {
	    settings.format = THRESHOLDED;
	    settings.ofmt = PNM ;
	    settings.xdpi = 200 ;
	    settings.xdpi = 100 ;
	}
	else if (!strcmp(argv[0], "-raw"))
	    settings.ofmt = RAW ;
	else if (!strcmp(argv[0], "-pbm"))
	    settings.ofmt = PNM ;

	else if (!strcmp(argv[0], "-bpp"))
	    settings.bpp = nextargi;
	else if (!strcmp(argv[0], "-xres"))
	    settings.xres = nextargi;
	else if (!strcmp(argv[0], "-yres"))
	    settings.yres = nextargi;
	else if (!strcmp(argv[0], "-in"))
	    posfactor = UNIT;
	else if (!strcmp(argv[0], "-cm"))
	    posfactor = UNIT / 2.54;
	else if (!strcmp(argv[0], "-mm"))
	    posfactor = UNIT / 25.4;
	else if (!strcmp(argv[0], "-x")) {
	    double a = nextargf;
	    settings.x = (int)(a * posfactor);
	}
	else if (!strcmp(argv[0], "-y"))
	    settings.y = (int)(posfactor * nextargf);
	else if (!strncmp(argv[0], "-width", 3))
	    settings.width = (int)(posfactor * nextargf);
	else if (!strncmp(argv[0], "-height", 4))
	    settings.height = (int)(posfactor * nextargf);
	else if (!strcmp(argv[0], "-bright"))
	    settings.brightness = (double)nextargf;
	else if (!strcmp(argv[0], "-cont"))
	    settings.contrast = (double)nextargf;
	else if (!strcmp(argv[0], "-dev"))
	    devname = nextargs;
	else if (!strcmp(argv[0], "-o") || !strcmp(argv[0], "-out"))
	    outname = nextargs;
	else if (!strcmp(argv[0], "-q") || !strcmp(argv[0], "-quiet"))
	    quiet = 1;
	else if (!strcmp(argv[0], "-format")) {
	    char           *mn = nextargs;
	    if (!strncmp(mn, "thresh", 6))
		settings.format = THRESHOLDED;
	    else if (!strncmp(mn, "dith", 4))
		settings.format = DITHERED;
	    else if (!strncmp(mn, "grey", 4) || !strncmp(mn, "gray", 4))
		settings.format = GREYSCALE;
	    else if (!strcmp(mn, "color"))
		settings.format = TRUECOLOR;
	    else {
		fprintf(stderr, "invalid mode %s ", mn);
		goto oops;
	    }
	} else if (!strcmp(argv[0], "-s") || !strcmp(argv[0], "-save"))
	    savesettings(nextargs);
	else {
	    if (strcmp(argv[0], "-help"))
		fprintf(stderr, "unknown option '%s'; ", argv[0]);
oops:
	    fprintf(stderr, "valid options are:\n"
	"-dpi,-xdpi,-ydpi scan resolution in dots per inch (def.200)\n"
	"-faxh,-faxl      set parameters for fax hi/low res\n"
	"-xres, -yres     width/height on output image\n"
	"-in, -cm, -mm    scan region in inches (default), cm or mm\n"
	"-lj,-raw,-pbm    output format: hp laserjet, raw bytes, pbm/pgm\n"
	"-x,-y            upper left coords of scan region (default 0.0)\n"
	"-width,-height   width/height of scan region (default 8.5x11in)\n"
	"-bpp             bits per pixel (default 8)\n"
	"-bright          brightness adjustment (-1.0 to 1.0, default 0.0)\n"
	"-cont            contrast adjustment (-1.0 to 1.0, default 0.0)\n"
	"-dev    scsi generic device of scanner (default autoprobe)\n"
	"-o,-out output file (default stdout)\n"
	"-quiet  turn off informational messages\n"
	"-load   read parameter settings from file\n"
	"-save   save current parameter settings to file\n"
	"-format pixel format: thresholded, dithered, greyscale, color\n"
		);
	    exit(1);
	}
    }
    if (argc)
	goto oops;
    if (!devname) {
	fd = find_hp_scanner();
	if (fd == -1) {
	    fprintf(stderr, "No HP Scanjet found.\n");
	    exit(2);
	}
    } else if ((fd = open(devname, O_RDWR)) == -1) {
	fprintf(stderr, "'%s' is not an HP Scanjet.\n", devname);
	exit(2);
    }

    if (settings.xres != 0)
	settings.xdpi = (settings.xres / (settings.width / UNIT) + 0.5);
    if (settings.yres != 0)
	settings.ydpi = (settings.yres / (settings.height / UNIT) + 0.5);

    do_scan(outname, fd, &settings);
    close(fd);
}
