/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: imtest.cxx
 *
 * Author: $author$
 *   Date: 2/17/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <magick/api.h>
#include <magick/static.h>

#include "bresenham.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cIMTest
 *
 * Author: $author$
 *   Date: 2/17/2004
 **********************************************************************
 */
class cIMTest
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     *  Class: cImage
     *
     * Author: $author$
     *   Date: 2/20/2004
     **********************************************************************
     */
    class cImage
    {
    public:
        Image *&image;

        /**
         **********************************************************************
         * Constructor: cImage
         *
         *      Author: $author$
         *        Date: 2/20/2004
         **********************************************************************
         */
        cImage(Image *&p_image)
        : image(p_image) 
        {
        }
        /**
         **********************************************************************
         * Function: Plot
         *
         *   Author: $author$
         *     Date: 2/20/2004
         **********************************************************************
         */
         void Plot(int pixel, int ix, int iy, int x, int y)
         {
         }
    };

    /**
     **********************************************************************
     *  Class: cCircle
     *
     * Author: $author$
     *   Date: 2/20/2004
     **********************************************************************
     */
    class cCircle
    {
    public:
        cImage image;

        /**
         **********************************************************************
         * Constructor: cCircle
         *
         *      Author: $author$
         *        Date: 2/20/2004
         **********************************************************************
         */
        cCircle(Image *&p_image)
        : image(p_image)
        {
        }
        /**
         **********************************************************************
         * Function: Plot
         *
         *   Author: $author$
         *     Date: 2/17/2004
         **********************************************************************
         */
        void Plot(int color, int ix, int iy, int x, int y)
        {
            int i;
            PixelPacket *pixel;

            if ((pixel = SetImagePixels(image, ix-x, iy-y, x+x, 1)))
            {
                for (i=ix-x; i<ix+x; i++,pixel++)
                {
                    pixel->red=color;
                    pixel->green=0;
                    pixel->blue=0;
                    pixel->opacity=color;
                }
                SyncImagePixels(image);
            }

            if ((pixel = SetImagePixels(image, ix-y, iy-x, y+y, 1)))
            {
                for (i=ix-y; i<ix+y; i++,pixel++)
                {
                    pixel->red=color;
                    pixel->green=0;
                    pixel->blue=0;
                    pixel->opacity=color;
                }
                SyncImagePixels(image);
            }

            if ((pixel = SetImagePixels(image, ix-y, iy+x, y+y, 1)))
            {
                for (i=ix-y; i<ix+y; i++,pixel++)
                {
                    pixel->red=color;
                    pixel->green=0;
                    pixel->blue=0;
                    pixel->opacity=color;
                }
                SyncImagePixels(image);
            }

            if ((pixel = SetImagePixels(image, ix-x, iy+y, x+x, 1)))
            {
                for (i=ix-x; i<ix+x; i++,pixel++)
                {
                    pixel->red=color;
                    pixel->green=0;
                    pixel->blue=0;
                    pixel->opacity=color;
                }
                SyncImagePixels(image);
            }
        }
    };

    /**
     **********************************************************************
     *  Class: cLine
     *
     * Author: $author$
     *   Date: 2/20/2004
     **********************************************************************
     */
    class cLine
    {
    public:
        cCircle circle;

        /**
         **********************************************************************
         * Constructor: cLine
         *
         *      Author: $author$
         *        Date: 2/20/2004
         **********************************************************************
         */
        cLine(Image *&p_image)
        : circle(p_image)
        {
        }
        /**
         **********************************************************************
         * Function: Plot
         *
         *   Author: $author$
         *     Date: 2/17/2004
         **********************************************************************
         */
        void Plot(int color, int ix, int iy, int x, int y)
        {
            BresenhamCircleT(circle, color, x, y, 10);
        }
    };

    Image *image;

    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
    static void RegisterStaticModules(void)
    {
        RegisterGIFImage();
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 2/17/2004
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int i,x,y,r,d,err;
        ImageInfo *image_info;
        PixelPacket *pixel;
        ExceptionInfo ex;
        cCircle circle(image);
        cLine line(image);

        SetRegisterStaticModules(RegisterStaticModules);

        InitializeMagick(*argv);
        image_info=CloneImageInfo(NULL);
        strcpy(image_info->filename,"imtest.gif");

        image=AllocateImage(image_info);
        if (image == (Image *) NULL)
          MagickError
          (ResourceLimitError,
           "Unable to display image",
           "MemoryAllocationFailed");
        
        image->rows=256;
        image->columns=256;

        pixel=SetImagePixels
        (image,0,0,image->columns,image->rows);

        if (pixel)
        for (y=0; y < image->rows; y++)
        {
            for (x=0; x < image->columns; x++)
            {
                pixel->red=255;
                pixel->green=255;
                pixel->blue=255;
                pixel->opacity=255;
                pixel++;
            }
        }

        SyncImagePixels(image);

        for (i=0; i<128; i++)
            BresenhamCircleT
            (circle, 255, 21+i, 21+i, 21);

        BresenhamLineT(line, 127+63, 20,20, 60,25);

        err = WriteImage(image_info,image);

        if (image->exception.severity != UndefinedException)
            CatchException(&image->exception);

        return 0;
    }
} g_main;
