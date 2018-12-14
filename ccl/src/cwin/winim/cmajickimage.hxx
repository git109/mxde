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
 *   File: cmajickimage.hxx
 *
 * Author: $author$
 *   Date: 3/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMAJICKIMAGE_HXX
#define _CMAJICKIMAGE_HXX

#include <stdio.h>
#include <time.h>
#include <sys/types.h>

#include <magick/api.h>
#include <magick/static.h>

#include "chandlet.hxx"
#include "cinstance.hxx"
#include "cimageinterface.hxx"

/**
 **********************************************************************
 *  Class: cMajickImage
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cMajickImage
: virtual public cImageImplement,
  public cHandleT<Image*, NULL, cErrorInstance>
{
public:
    typedef cHandleT<Image*, NULL, cErrorInstance> cIs;

    class cObject;

    /**
     **********************************************************************
     *  Class: cObjectList
     *
     * Author: $author$
     *   Date: 3/28/2004
     **********************************************************************
     */
    class cObjectList
    : public cListT<cObject, cObjectList>
    {
    public:
        typedef cListT<cObject, cObjectList> cIs;
    };

    /**
     **********************************************************************
     *  Class: cObject
     *
     * Author: $author$
     *   Date: 3/28/2004
     **********************************************************************
     */
    class cObject
    : virtual public cImageImplement,
      public cListItemT<cObject, cErrorInstance>
    {
    public:
        typedef cListItemT<cObject, cErrorInstance> cIs;

        cMajickImage &m_image;

        /**
         **********************************************************************
         * Constructor: cObject
         *
         *      Author: $author$
         *        Date: 3/28/2004
         **********************************************************************
         */
        cObject(cMajickImage &image)
        : m_image(image) 
        {
        }
    };

    /**
     **********************************************************************
     *  Class: cColor
     *
     * Author: $author$
     *   Date: 2/29/2004
     **********************************************************************
     */
    class cColor
    : public cObject
    {
    public:
        typedef cObject cIs;

        PixelPacket m_color;
        int m_width,m_height;

        /**
         **********************************************************************
         * Constructor: cColor
         *
         *      Author: $author$
         *        Date: 2/29/2004
         **********************************************************************
         */
        cColor(cMajickImage &image)
        : cIs(image),
          m_width(1),
          m_height(1)
        {
        }
        /**
         **********************************************************************
         * Constructor: cColor
         *
         *      Author: $author$
         *        Date: 2/29/2004
         **********************************************************************
         */
        cColor(cMajickImage &image, int w, int h, int r, int g, int b, int o)
        : cIs(image),
          m_width(w),
          m_height(h)
        {
            eError error;

            if ((error = Create(w,h, r,g,b,o)))
                throw(error);
        }
        /**
         **********************************************************************
         * Function: Create
         *
         *   Author: $author$
         *     Date: 2/29/2004
         **********************************************************************
         */
        virtual eError Create(int w, int h, int r, int g, int b, int o)
        {
            eError error=e_ERROR_NONE;

            if (0 > o)
                o = 255;

            m_width = w;
            m_height = h;
            m_color.red = r;
            m_color.green = g;
            m_color.blue = b;
            m_color.opacity = o;
            return error;
        }

        /**
         **********************************************************************
         * Function: SetImage
         *
         *   Author: $author$
         *     Date: 3/1/2004
         **********************************************************************
         */
        virtual cImageInterface *SetImage()
        {
            cImageInterface *old_image=m_image.GetImage();

            m_image.m_image = this;
            return old_image;
        }
        /**
         **********************************************************************
         * Function: Fill
         *
         *   Author: $author$
         *     Date: 3/1/2004
         **********************************************************************
         */
        virtual void Fill(int x, int y, int w, int h)
        {
            int xi,x2,y2;
            PixelPacket *pixel;

            if ((pixel = SetImagePixels
                (m_image.GetHandle(), x, y, w, h)))
            {
                for (x2=x+w, y2=y+h; y < y2; y++)
                for (xi = x; xi < x2; xi++,pixel++)
                {
                    pixel->red=m_color.red;
                    pixel->green=m_color.green;
                    pixel->blue=m_color.blue;
                    pixel->opacity=m_color.opacity;
                }
                SyncImagePixels(m_image.GetHandle());
            }
        }
    };

    cImageInterface *m_image;
    cObjectList m_object_list;

    /**
     **********************************************************************
     * Constructor: cMajickImage
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cMajickImage(Image *handle=NULL, cImageInterface *image=0)
    : cIs(handle),
      m_image(image) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cMajickImage
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cMajickImage()
    {
    }

    /**
     **********************************************************************
     * Function: DestroyImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual eError DestroyImage(cImageInterface *image)
    {
        eError error=e_ERROR_NOT_CREATED;
        cObject *object;

        for (object=m_object_list.GetFirst(); object; object=object->GetNext())
        {
            if (image == object)
            {
                m_object_list.Delete(object);
                delete object;
                error = e_ERROR_NONE;
                break;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateColor
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColor
    (int w, int h, int r, int g, int b, int o=-1)
    {
        cColor *color=0;
        eError error;

        if ((color = new cColor(*this)))
        if ((error = color->Create(w,h, r,g,b,o)))
        {
            delete color;
            color = 0;
        }
        else m_object_list.Add(color);
        return color;
    }
    /**
     **********************************************************************
     * Function: GetImage
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    virtual cImageInterface *GetImage() const
    {
        cImageInterface *image=m_image;
        return image;
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Fill(int x, int y, int w, int h)
    {
        if (m_image)
            m_image->Fill(x,y, w,h);
    }
    /**
     **********************************************************************
     * Function: Draw
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Draw(int x1, int y1, int x2, int y2)
    {
        if (m_image)
        {
            cBresenhamImage image(*m_image);

            BresenhamLineT(image, *m_image, x1,y1,x2,y2);
        }
    }
    /**
     **********************************************************************
     * Function: DrawCircle
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void DrawCircle
    (int x, int y, int r, int quadrant=-1)
    {
        if (m_image)
        {
            cBresenhamCircleImage circle(*m_image);

            BresenhamCircleT(circle, *m_image, x,y,r);
        }
    }
    /**
     **********************************************************************
     * Function: FillCircle
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void FillCircle
    (int x, int y, int r, int quadrant=-1)
    {
        if (m_image)
        {
            cBresenhamFilledCircleImageQuadrant filled_circle(*m_image,quadrant);

            BresenhamCircleT(filled_circle, *m_image, x,y,r);
        }
    }
    /**
     **********************************************************************
     * Function: DrawEllipse
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void DrawEllipse
    (int x, int y, int a, int b, int quadrant=-1)
    {
        if (m_image)
        {
            cBresenhamEllipseImage ellipse(*m_image);

            BresenhamEllipseT(ellipse, *m_image, x,y,a,b);
        }
    }
    /**
     **********************************************************************
     * Function: FillEllipse
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void FillEllipse
    (int x, int y, int a, int b, int quadrant=-1)
    {
        if (m_image)
        {
            cBresenhamFilledEllipseImage ellipse(*m_image);

            BresenhamEllipseT(ellipse, *m_image, x,y,a,b);
        }
    }
};

#endif /* ndef _CMAJICKIMAGE_HXX */
