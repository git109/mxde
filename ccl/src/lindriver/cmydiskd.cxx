/**
 **********************************************************************
 * Copyright (c) $author$ 1988-2005
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cmydiskd.cxx
 *
 * Author: $author$
 *   Date: 8/6/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mydisk.h"
#include "cmydisk.hxx"
#include "cmain.hxx"
#include "csockets.hxx"
#include "cusbbulkmasstcpconnector.hxx"

#define CMYDISK_SIZE_KB 360
#define CMYDISK_SIZE (CMYDISK_SIZE_KB*1024)

/**
 **********************************************************************
 *  Class: cMydiskDaemon
 *
 * Author: $author$
 *   Date: 8/6/2005
 **********************************************************************
 */
class cMydiskDaemon
: public cMain
{
public:
    typedef cMain cIs;

    int m_n;
    int m_virtual;
    int m_geometry_start;
    int m_geometry_heads;
    int m_geometry_sectors;
    int m_lba;
    int m_usb_port;
    const char *m_usb_host;
    const char *m_device_name;
    cMydisk m_device;
    cUsbBulkMassTcpConnector m_usb;
    usb_ufi_capacity_data_t m_capacity;
    usb_ufi_block_data_t m_block;
    mydisk_request_t m_request;
    int m_disk_block_size, m_disk_blocks, m_disk_size;
    unsigned char m_disk[CMYDISK_SIZE];
    
    /**
     **********************************************************************
     * Constructor: cMydiskDaemon
     *
     *      Author: $author$
     *        Date: 8/6/2005
     **********************************************************************
     */
    cMydiskDaemon
    (int usb_port=776, const char *usb_host="localhost",
     const char *device_name="/dev/mydisk")
    : m_n(0),
      m_virtual(0),
      m_lba(0),
      m_geometry_start(0),
      m_geometry_heads(2),
      m_geometry_sectors(8),
      m_usb_port(usb_port),
      m_usb_host(usb_host),
      m_device_name(device_name),
      m_disk_blocks(0),
      m_disk_size(0)
    {
        memset(&m_request, 0, sizeof(m_request));
        m_request.type = e_MYDISK_NULL_REQUEST;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnUsage(int argc, char **argv) 
    {
        int result = 0;
        const char *filename=__FILE__;
        const char *exename=(argc>0)?argv[0]:filename;
        const char *extension;
        const char *substr;
        
        if ((substr = strrchr(exename, '/')))
            exename = substr+1;
        
        extension = exename+strlen(exename);
        
        if (exename == filename)
        if ((substr = strrchr(exename, '.')))
            extension = substr;
            
        printf("usage: %.*s\n", extension-exename, exename);
        return result;
    }
    /**
     **********************************************************************
     * Function: OnResetModule
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnResetModule(int argc, char **argv) 
    {
        int result = 0;
        int err, err2;

        if (!(err = OpenDevice()))
        {
            err = m_device.ResetModule();

            if ((err2 = CloseDevice()))
                err = err?err:err2;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: ReadCapacity
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    int ReadCapacity
    (int disk_size, int sector_size)
    {
        BYTE lun = 0;
        DWORD lba = 0;
        DWORD blocks;
        DWORD block_size;
        long length;

        if (!m_usb.GetIsConnected())
        {
            if ((disk_size <= 0) 
                || (disk_size > sizeof(m_disk)/1024))
                disk_size = sizeof(m_disk)/1024;

            if (sector_size <= 0)
                sector_size = MYDISK_BLOCKSIZE;

            blocks = (disk_size*1024)/sector_size;

            dword2be(m_capacity.lba, blocks-1);
            dword2be(m_capacity.length, sector_size);

            m_disk_size = disk_size;
            m_disk_block_size = sector_size;
            m_disk_blocks = blocks;
            length = sizeof(m_capacity);
        }

        else if (0 < (length = m_usb.ReadCapacity
                (&m_capacity, lba, lun)))
        {
            blocks = be2dword(m_capacity.lba)+1;
            block_size = be2dword(m_capacity.length);

            printf
            ("Received capacity lba=%d length=%d\n",
             blocks-1, block_size);

            m_disk_size = (blocks*block_size)/1024;
            m_disk_block_size = block_size;
            m_disk_blocks = blocks;

            printf
            ("Disk size=%d blocks=%d\n",
             m_disk_size, m_disk_blocks);
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: ReadBlock
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    int ReadBlocks
    (BYTE *byte, int blocks, int lba, int lun)
    {
        long length = -1;

        if (!m_usb.GetIsConnected())
        {
            if (lba < m_disk_blocks)
            {
                memcpy
                (byte, 
                 m_disk+(lba*m_disk_block_size), 
                 blocks*m_disk_block_size);
                length = blocks*m_disk_block_size;
            }
        }
        else length = m_usb.ReadBlocks
        ((usb_ufi_block_data_t*)
         byte, blocks, lba, (BYTE)lun);
        return length;
    }
    /**
     **********************************************************************
     * Function: WriteBlock
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    int WriteBlocks
    (const BYTE *byte, int blocks, int lba, int lun)
    {
        long length = -1;

        if (!m_usb.GetIsConnected())
        {
            if (lba < m_disk_blocks)
            {
                memcpy
                (m_disk+(lba*m_disk_block_size), 
                 byte, blocks*m_disk_block_size);
                length = blocks*m_disk_block_size;
            }
        }
        else length = m_usb.WriteBlocks
        ((usb_ufi_block_data_t*)
         byte, blocks, lba, (BYTE)lun);
        return length;
    }
    /**
     **********************************************************************
     * Function: OnReceivedGeometryRequest
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnReceivedGeometryRequest(int argc, char **argv) 
    {
        int result = 0;
        long length;
        int disk_size, head_size, cylinder_size, sector_size;

        printf
        ("Received geometry request "
         "heads=%d cylinders=%d sectors=%d start=%d\n",
         m_request.geometry.heads,
         m_request.geometry.cylinders,
         m_request.geometry.sectors,
         m_request.geometry.start);

        sector_size = m_request.geometry.sectors;
        disk_size = m_request.geometry.start;

        if ((m_request.geometry.status 
            = (0 >= (length = ReadCapacity
               (disk_size, sector_size)))))
            return result;

        if (disk_size > m_disk_size)
            disk_size = m_disk_size;

        m_request.geometry.start = m_geometry_start;
        m_request.geometry.heads = m_geometry_heads;
        m_request.geometry.sectors = m_geometry_sectors;

        cylinder_size = sector_size*m_request.geometry.sectors;
        head_size = cylinder_size*m_request.geometry.heads;

        printf
        ("Disk size=%d cylinder_size=%d head_size=%d\n", 
         disk_size, cylinder_size, head_size);

        m_request.geometry.cylinders = disk_size/(head_size/1024);

        printf
        ("Geometry heads=%d cylinders=%d sectors=%d start=%d\n",
         m_request.geometry.heads,
         m_request.geometry.cylinders,
         m_request.geometry.sectors,
         m_request.geometry.start);

        return result;
    }
    /**
     **********************************************************************
     * Function: OnReceivedBlockRequest
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnReceivedBlockRequest(int argc, char **argv) 
    {
        int result = 0;
        long length;

        m_request.block.status = 1;

        if (!m_disk_blocks)
            ReadCapacity(-1, -1);

        if (m_request.block.lba >= (unsigned)m_disk_blocks)
            return 1;

        switch(m_request.block.type)
        {
        case e_MYDISK_READ_BLOCK_REQUEST:
            printf
            ("Received read block request lba=%lu length=%lu\n",
             m_request.block.lba, m_request.block.length);

            if (0 < (length = ReadBlocks
                (m_request.block.block[0].byte, m_request.block.length,
                 m_request.block.lba, m_request.block.lun)))
                m_request.block.status = 0;
            break;

        case e_MYDISK_WRITE_BLOCK_REQUEST:
            printf
            ("Received write block request lba=%lu length=%lu\n",
             m_request.block.lba, m_request.block.length);

            if (0 < (length = WriteBlocks
                (m_request.block.block[0].byte, m_request.block.length,
                 m_request.block.lba, m_request.block.lun)))
                m_request.block.status = 0;
            break;
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnReceivedRequest
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnReceivedRequest(int argc, char **argv) 
    {
        int err, result = 0;

        //printf
        //("...Received request id=%u type=%u\n", 
        // m_request.id, m_request.type);

        switch(m_request.type)
        {
        case e_MYDISK_GEOMETRY_REQUEST:
            OnReceivedGeometryRequest(argc, argv);
            break;

        case e_MYDISK_BLOCK_REQUEST:
            OnReceivedBlockRequest(argc, argv);
            break;
        }

        //printf
        //("Serivce... request id=%u type=%u\n", 
        // m_request.id, m_request.type);

        err = m_device.ServiceRequest(m_request);

        //printf
        //("...Serviced request id=%u type=%u\n", 
        // m_request.id, m_request.type);

        return result;
    }
    /**
     **********************************************************************
     * Function: OnSendRequest
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnSendRequest(int argc, char **argv) 
    {
        int result = 0;
        int err, err2;

        printf("o...");
        fflush(stdout);

        if (!(err = OpenDevice()))
        {
            printf("...o");
            fflush(stdout);

            err = m_device.SendRequest(m_request);

            printf("c...");
            fflush(stdout);

            if ((err2 = CloseDevice()))
                err = err?err:err2;

            printf("...c");
            fflush(stdout);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnReceiveRequest
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnReceiveRequest(int argc, char **argv) 
    {
        int result = 0;
        int err, err2;

        printf("o...");
        fflush(stdout);

        if (!(err = OpenDevice()))
        {
            printf("...o");
            fflush(stdout);

            if (!(err = m_device.ReceiveRequest(m_request)))
            {
                OnReceivedRequest(argc, argv);
            }

            printf("c...");
            fflush(stdout);

            if ((err2 = CloseDevice()))
                err = err?err:err2;

            printf("...c");
            fflush(stdout);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnListenRequest
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnListenRequest(int argc, char **argv) 
    {
        int result = 0;
        int err, err2, n = m_n;
        eError error;

        //printf("o...");
        //fflush(stdout);

        if (!(err = OpenDevice()))
        {
            //printf("...o");
            //fflush(stdout);

            if (!(error = ConnectUSB()))
            {
                while (!(err = m_device.ReceiveRequest(m_request)))
                {
                    OnReceivedRequest(argc, argv);

                    if (0 < n)
                    if (0 >= --n)
                        break;
                }
                DisconnectUSB();
            }

            //printf("c...");
            //fflush(stdout);

            if ((err2 = CloseDevice()))
                err = err?err:err2;

            //printf("...c");
            //fflush(stdout);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnReadCapacity(int argc, char **argv) 
    {
        int result = 0;
        long length;
        DWORD lba, len;
        eError error;

        if (!(error = ConnectUSB()))
        {
            if (0 < (length = m_usb.ReadCapacity(&m_capacity, 0, 0)))
            {
                lba = be2dword(m_capacity.lba);
                len = be2dword(m_capacity.length);
                printf("...Read capacity lba=%u length=%u\n", lba, len);
            }
            DisconnectUSB();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnReadBlock(int argc, char **argv) 
    {
        int result = 0;
        long length;
        eError error;

        memset(&m_block, 0x12, sizeof(m_block));

        if (!(error = ConnectUSB()))
        {
            if (!m_disk_blocks)
                ReadCapacity(-1, -1);

            if (0 < (length = ReadBlocks
                (m_block.byte, 1, m_lba, 0)))
            {
                printf("...Read block 0\n");
                PrintHex(m_block.byte, sizeof(m_block));
            }
            DisconnectUSB();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: On
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnWriteBlock(int argc, char **argv) 
    {
        int result = 0;
        eError error;

        memset(&m_block, 0x12, sizeof(m_block));

        if (!(error = ConnectUSB()))
        {
            if (!m_disk_blocks)
                ReadCapacity(-1, -1);

            WriteBlocks(m_block.byte, 1, m_lba, 0);
            DisconnectUSB();
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv) 
    {
        int arg, args, result = 0;

        if (argc<2)
            return OnUsage(argc, argv);
            
        cSockets::Initialize();

        for (args=0, arg=1; arg<argc; arg++)
        {
        switch(argv[arg][0])
        {
        case '-':
            switch(argv[arg][1])
            {
            case 'h':
                m_usb_host = argv[++arg];
                m_usb.SetHost(m_usb_host);
                break;

            case 'p':
                m_usb_port = atoi(argv[++arg]);
                m_usb.SetPort(m_usb_port);
                break;

            case 'n':
                m_n = atoi(argv[++arg]);
                break;

            case 'b':
                m_lba = atoi(argv[++arg]);
                m_request.type = e_MYDISK_BLOCK_REQUEST;
                m_request.block.type = e_MYDISK_READ_BLOCK_REQUEST;
                m_request.block.lun = 0;
                m_request.block.lba = 0;
                m_request.block.length = 0;
                break;

            case 'v':
                m_virtual = 1;
                break;

            default:
                args = 1;
            }
            break;

        default:
            args = 1;
        }
        if (args)
            break;
        }

        if (arg >= argc)
            return OnUsage(argc, argv);
            
        switch(argv[arg][0])
        {
        case '-':
            switch(argv[arg][1])
            {
            case 'l':
                result = OnListenRequest(argc, argv);
                break;
                
            case 's':
                return OnSendRequest(argc, argv);
                
            case 't':
                return OnReceiveRequest(argc, argv);
                
            case 'c':
                return OnReadCapacity(argc, argv);
                
            case 'r':
                return OnReadBlock(argc, argv);
                
            case 'w':
                return OnWriteBlock(argc, argv);
                
            case 'x':
                return OnResetModule(argc, argv);
                
            default:
                return OnUsage(argc, argv);
            }
            break;
            
        default:
            return OnUsage(argc, argv);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: ConnectUSB
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    eError ConnectUSB()
    {
        eError error = e_ERROR_NONE;

        if (m_virtual)
            return error;

        if ((error = m_usb.m_connector.Connect()))
            printf("Unable to connect to \"%s:%d\"\n", m_usb_host, m_usb_port);

        return error;
    }
    /**
     **********************************************************************
     * Function: DisconnectUSB
     *
     *   Author: $author$
     *     Date: 8/30/2005
     **********************************************************************
     */
    eError DisconnectUSB()
    {
        eError error = e_ERROR_NONE;

        if (m_virtual)
            return error;

        if ((error = m_usb.m_connector.Connect()))
            printf("Unable to disconnect from \"%s:%d\"\n", m_usb_host, m_usb_port);

        return error;
    }
    /**
     **********************************************************************
     * Function: OpenDevice
     *
     *   Author: $author$
     *     Date: 8/30/2005
     **********************************************************************
     */
    int OpenDevice()
    {
        int err;

        if ((err = m_device.Open(m_device_name)))
            printf("Unable to open device \"%s\"\n", m_device_name);

        return err;
    }
    /**
     **********************************************************************
     * Function: CloseDevice
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    int CloseDevice()
    {
        int err;

        if ((err = m_device.Close()))
            printf("Unable to close device \"%s\"\n", m_device_name);

        return err;
    }
    /**
     **********************************************************************
     * Function: PrintHex
     *
     *   Author: $author$
     *     Date: 8/6/2005
     **********************************************************************
     */
    void PrintHex(const unsigned char *byte, int length)
    {
        unsigned col;

        for (col=0; 0 < length; --length)
        {
            printf("%2.2X", *(byte++));

            if (32 <= ++col)
            {
                printf("\n");
                col = 0;
            }
        }
        if (col)
            printf("\n");
    }
} g_mydisk_daemon;
