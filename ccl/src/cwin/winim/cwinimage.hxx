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
 *   File: cwinimage.hxx
 *
 * Author: $author$
 *   Date: 2/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINIMAGE_HXX
#define _CWINIMAGE_HXX

#include "cbresenhamimage.hxx"
#include "cinstance.hxx"
#include "cimageinterface.hxx"
#include "cwinobject.hxx"

/**
 **********************************************************************
 *  Class: cWinImage
 *
 * Author: $author$
 *   Date: 2/29/2004
 **********************************************************************
 */
class cWinImage
: virtual public cImageImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

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

        cWinImage &m_image;

        /**
         **********************************************************************
         * Constructor: cObject
         *
         *      Author: $author$
         *        Date: 3/28/2004
         **********************************************************************
         */
        cObject(cWinImage &image)
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

        cWinBrush m_brush;
        int m_width,m_height;

        /**
         **********************************************************************
         * Constructor: cColor
         *
         *      Author: $author$
         *        Date: 2/29/2004
         **********************************************************************
         */
        cColor(cWinImage &image)
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
        cColor(cWinImage &image, int w, int h, int r, int g, int b)
        : cIs(image),
          m_width(w),
          m_height(h)
        {
            eError error;

            if ((error = Create(w,h, r,g,b)))
                throw(error);
        }
        /**
         **********************************************************************
         * Constructor: cColor
         *
         *      Author: $author$
         *        Date: 2/29/2004
         **********************************************************************
         */
        cColor(cWinImage &image, int w, int h, COLORREF color)
        : cIs(image),
          m_width(w),
          m_height(h)
        {
        }
        /**
         **********************************************************************
         *  Destructor: ~cColor
         *
         *      Author: $author$
         *        Date: 3/29/2007
         **********************************************************************
         */
        virtual ~cColor()
        {
        }
        /**
         **********************************************************************
         * Function: Create
         *
         *   Author: $author$
         *     Date: 2/29/2004
         **********************************************************************
         */
        virtual eError Create(int w, int h, int r, int g, int b)
        {
            eError error;

            m_width = w;
            m_height = h;
            error = m_brush.CreateSolid(r,g,b);
            return error;
        }
        /**
         **********************************************************************
         * Function: Create
         *
         *   Author: $author$
         *     Date: 2/29/2004
         **********************************************************************
         */
        virtual eError Create(int w, int h, COLORREF color)
        {
            eError error;

            m_width = w;
            m_height = h;
            error = m_brush.CreateSolid(color);
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
            HBRUSH hbrush=m_brush.GetHandle();

            m_image.m_dc.FillRect
            (x, y, x+w+m_width-1, y+h+m_height-1, hbrush);
        }
    };

    /**
     **********************************************************************
     *  Class: cSolidEllipse
     *
     * Author: $author$
     *   Date: 3/1/2004
     **********************************************************************
     */
    class cSolidEllipse
    : public cColor
    {
    public:
        typedef cColor cIs;

        cColor m_color;

        /**
         **********************************************************************
         * Constructor: cSolidEllipse
         *
         *      Author: $author$
         *        Date: 3/1/2004
         **********************************************************************
         */
        cSolidEllipse(cWinImage &image)
        : cIs(image),
          m_color(image)
        {
        }
        /**
         **********************************************************************
         *  Destructor: ~cSolidEllipse
         *
         *      Author: $author$
         *        Date: 3/29/2007
         **********************************************************************
         */
        virtual ~cSolidEllipse()
        {
        }
        /**
         **********************************************************************
         * Function: Create
         *
         *   Author: $author$
         *     Date: 2/29/2004
         **********************************************************************
         */
        virtual eError Create(int w, int h, int r, int g, int b)
        {
            eError error;

            if (!(error = cIs::Create(w,h,r,g,b)))
                error = m_color.Create(1,1,r,g,b);
            return error;
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
            cImageInterface *image=m_color.SetImage();

            m_image.FillEllipse(x, y, m_width, m_height);
            image->SetImage();
        }
    };

    cWinDC &m_dc;
    cImageInterface *m_image;
    cObjectList m_object_list;

    /**
     **********************************************************************
     * Constructor: cWinImage
     *
     *      Author: $author$
     *        Date: 2/29/2004
     **********************************************************************
     */
    cWinImage(cWinDC &dc, cImageInterface *image=0)
    : m_dc(dc),
      m_image(image)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImage
     *
     *     Author: $author$
     *       Date: 2/29/2004
     **********************************************************************
     */
    virtual ~cWinImage()
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
        if ((error = color->Create(w,h, r,g,b)))
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
            cBresenhamEllipseImageQuadrant ellipse(*m_image, quadrant);

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

#endif /* ndef _CWINIMAGE_HXX */
