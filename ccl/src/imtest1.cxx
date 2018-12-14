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

#include <line>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <magick/api.h>
#include <magick/static.h>

#include "smile.h"
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
        int x,y,err;
        Image *image,*pen;
        ImageInfo *image_info,*pen_info;
        DrawInfo *draw_info;
        PixelPacket *pp;
        unsigned char *p;
        ExceptionInfo ex;

        SetRegisterStaticModules(RegisterStaticModules);

        InitializeMagick(*argv);
        image_info=CloneImageInfo((ImageInfo *) NULL);
  strcpy(image_info->filename,"imtest.gif");
        image=AllocateImage(image_info);
        if (image == (Image *) NULL)
          MagickError(ResourceLimitError,"Unable to display image",
            "MemoryAllocationFailed");
        
  image->columns=smile_width;
  image->rows=smile_height;

  p=smile_bits;

  for (y=0; y < image->rows; y++)
  {
    pp=SetImagePixels(image,0,y,image->columns,1);
    if (pp == (PixelPacket *) NULL)
      break;

    for (x=0; x < image->columns; x++)
    {
      pp->red=MaxRGB*(*p);
      pp->green=MaxRGB*(*p);
      pp->blue=MaxRGB*(*p);
      pp++;
      p++;
    }

    if (!SyncImagePixels(image))
      break;
  }

  draw_info = CloneDrawInfo(image_info, NULL);
  if (draw_info)
  {
      draw_info->fill.red = 255;
      draw_info->fill.green = 0;
      draw_info->fill.blue = 0;

      draw_info->stroke.red = 0;
      draw_info->stroke.green = 255;
      draw_info->stroke.blue = 0;

      draw_info->stroke_antialias = 0;
      draw_info->stroke_width = 4;

      pen_info=CloneImageInfo(NULL);
      if (pen_info)
      {
          strcpy(pen_info->filename,"imtest.gif");
      pen=AllocateImage(pen_info);
      if (pen)
      {
          pen->rows = 1;
          pen->columns = 1;

          pp=SetImagePixels(pen,0,0,1,1);
          if (pp)
          {
              pp->red = 0;
              pp->green = 0;
              pp->blue = 255;

              SyncImagePixels(pen);
              draw_info->tile = pen;
          }
      }
      }

      draw_info->primitive = "circle 20,20 25,25";
      err = DrawImage(image, draw_info);

      draw_info->primitive = "line 10,10 20,20";
      err = DrawImage(image, draw_info);
  }

  err = GetImageDepth(image, &ex);
  err = WriteImage(image_info,image);


      if (image->exception.severity != UndefinedException)
        CatchException(&image->exception);

  return 0;
    }
} g_main;
