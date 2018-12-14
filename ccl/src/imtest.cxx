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
        Image *&m_image;

        /**
         **********************************************************************
         * Constructor: cImage
         *
         *      Author: $author$
         *        Date: 2/20/2004
         **********************************************************************
         */
        cImage(Image *&image)
        : m_image(image) 
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
         void Plot
         (PixelPacket &color, int x, int y)
         {
             Fill(color, x,y, 1,1);
         }
        /**
         **********************************************************************
         * Function: Fill
         *
         *   Author: $author$
         *     Date: 2/20/2004
         **********************************************************************
         */
         void Fill
         (PixelPacket &color, int x, int y, int w, int h)
         {
            int xi,x2,y2;
            PixelPacket *pixel;

            if ((pixel = SetImagePixels
                (m_image, x, y, w, h)))
            {
                for (x2=x+w, y2=y+h; y < y2; y++)
                for (xi = x; xi < x2; xi++,pixel++)
                {
                    pixel->red=color.red;
                    pixel->green=color.green;
                    pixel->blue=color.blue;
                    pixel->opacity=color.opacity;
                }
                SyncImagePixels(m_image);
            }
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
    : public cBresenhamFilledCircleT<Image*,PixelPacket,cImage>
    {
    public:
        typedef cBresenhamFilledCircleT<Image*,PixelPacket,cImage> cIs;

        /**
         **********************************************************************
         * Constructor: cCircle
         *
         *      Author: $author$
         *        Date: 2/20/2004
         **********************************************************************
         */
        cCircle(Image *&image)
        : cIs(image)
        {
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
        cLine(Image *&image)
        : circle(image)
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
        void Plot
        (PixelPacket &color, int x, int y)
        {
            BresenhamCircleT(circle, color, x, y, 10);
        }
    };

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
        int err;
        ImageInfo *image_info;
        Image *image;
        PixelPacket pixel;
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

        pixel.red=255;
        pixel.green=0;
        pixel.blue=0;
        pixel.opacity=255;

        circle.Fill(pixel, 0,0, 255,255);
        pixel.blue = 255;
        BresenhamCircleT(circle, pixel, 100,100,25);

        err = WriteImage(image_info,image);

        if (image->exception.severity != UndefinedException)
            CatchException(&image->exception);

        return 0;
    }
} g_main;
