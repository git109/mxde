/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cimage.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIMAGE_HXX
#define _CIMAGE_HXX

#include "ccreate.hxx"
#include "cimageinterfacelist.hxx"
#include "cbresenhamimage.hxx"
#include "cimageinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cImage
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cImage
: virtual public cImageImplement,
  public cCreate
{
public:
    typedef cCreate cIs;

    bool m_is_dynamic;
    cImageInterface *m_image;
    cImageInterfaceItem m_item;
    cImageInterfaceList m_list;

    /**
     **********************************************************************
     * Constructor: cImage
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cImage
    (bool is_dynamic=false, 
     cImageInterface *image=0) 
    : m_is_dynamic(is_dynamic),
      m_image(image),
      m_item(*this)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cImage
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    virtual ~cImage()
    {
        eError error = e_ERROR_NONE;
        eError error2;
        cImageInterfaceItem* item;

        while ((item = m_list.Pull()))
        {
            cImageInterface& image = item->m_image;

            if ((error2 = image.Destroy()))
            if (!error)
                error = error2;

            if ((error2 = image.FreeInstance()))
            if (!error)
                error = error2;
        }

        if (error)
            throw(error);
    }

    /**
     **********************************************************************
     * Function: CreateFilledCircleImage
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateFilledCircleImage
    (cImageInterface& color, int r, int q=-1) ;
    /**
     **********************************************************************
     * Function: CreateFilledEllipseImage
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateFilledEllipseImage
    (cImageInterface& color, int w, int h) ;
    /**
     **********************************************************************
     * Function: DestroyImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual eError DestroyImage(cImageInterface& image)
    {
        eError error = e_ERROR_NOT_CREATED;
        eError error2;
        cImageInterfaceItem* item;

        for (item=m_list.GetFirst(); item; item=item->GetNext())
        {
            if (&item->m_image == &image)
            {
                m_list.Delete(item);

                error = image.Destroy();

                if ((error2 = image.FreeInstance()))
                if (!error)
                    error = error2;

                break;
            }
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *SetImage(cImageInterface *image)
    {
        cImageInterface *old_image = m_image;

        m_image = image;
        return old_image;
    }
    /**
     **********************************************************************
     * Function: GetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *GetImage() const
    {
        return m_image;
    }

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual void Plot(int x, int y) 
    {
        if (m_image)
            m_image->Plot(x, y);
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual void Fill(int x, int y, int w, int h) 
    {
        int i, j;

        for (j=0; j<h; j++)
        for (i=0; i<w; i++)
            Plot(x+i, y+j);
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

/**
 **********************************************************************
 *  Class: cFilledCircleImage
 *
 * Author: $author$
 *   Date: 1/23/2006
 **********************************************************************
 */
class cFilledCircleImage
: public cImage
{
public:
    typedef cImage cIs;

    cImageInterface& m_color;
    cBresenhamFilledCircleImageQuadrant m_circle;
    int m_radius, m_quadrant;

    /**
     **********************************************************************
     * Constructor: cFilledCircleImage
     *
     *      Author: $author$
     *        Date: 1/23/2006
     **********************************************************************
     */
    cFilledCircleImage
    (cImageInterface& color, int r, int q=-1) 
    : m_color(color),
      m_circle(color, q),
      m_radius(r),
      m_quadrant(q) 
    {
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual void Plot(int x, int y) 
    {
        BresenhamCircleT
        (m_circle, m_color, x,y, m_radius);
    }
};

/**
 **********************************************************************
 *  Class: cFilledEllipseImage
 *
 * Author: $author$
 *   Date: 1/23/2006
 **********************************************************************
 */
class cFilledEllipseImage
: public cImage
{
public:
    typedef cImage cIs;

    cImageInterface& m_color;
    cBresenhamFilledEllipseImage m_ellipse;
    int m_width, m_height;

    /**
     **********************************************************************
     * Constructor: cFilledEllipseImage
     *
     *      Author: $author$
     *        Date: 1/23/2006
     **********************************************************************
     */
    cFilledEllipseImage
    (cImageInterface& color, int w, int h) 
    : m_color(color),
      m_ellipse(color),
      m_width(w),
      m_height(h)
    {
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual void Plot(int x, int y) 
    {
        BresenhamEllipseT
        (m_ellipse, m_color, x,y, m_width,m_height);
    }
};

#endif /* _CIMAGE_HXX */


