/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   Date: 5/24/2009
 **********************************************************************
 */
#if !defined(_CIMAGE_HXX) || defined(CIMAGE_MEMBERS_ONLY)
#if !defined(_CIMAGE_HXX) && !defined(CIMAGE_MEMBERS_ONLY)
#define _CIMAGE_HXX
#endif /* !defined(_CIMAGE_HXX) && !defined(CIMAGE_MEMBERS_ONLY) */

#if !defined(CIMAGE_MEMBERS_ONLY)
#include "cimageinterface.hxx"
#include "cbase.hxx"
#include "cbresenhamimage.hxx"
#include "cmidpointellipseimage.hxx"

/* cImage definition
 */
class cImage;

#undef CDB_CLASS
#define CDB_CLASS "cImageT"
/**
 **********************************************************************
 *  Class: cImageT
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
template
<class TDerives=cImage,
 class TImageImplement=cImageImplement,
 class TImageInterface=cImageInterface,
 class TInt=INT,
 class TOffset=TOFFSET,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TBase=cBase,
 class TImplements=TImageImplement,
 class TExtends=TBase>
 
class cImageT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cImageT cDerives;

/* include cImage interface member definitions
 */
#define CIMAGEINTERFACE_MEMBERS_ONLY
#include "cimageinterface.hxx"
#undef CIMAGEINTERFACE_MEMBERS_ONLY

    tImageInterface* m_image;

    /**
     **********************************************************************
     * Constructor: cImageT
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cImageT
    (tImageInterface* image=0)
    : m_image(image) 
    {
    }
#else /* !defined(CIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CreateColor
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual tImageInterface* CreateColor
    (tSize r,
     tSize g,
     tSize b,
     tSize o=0,
     tSize w=1,
     tSize h=1) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* image = 0;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return image;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError Destroy
    (tImageInterface& image) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x,
     tOffset y) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        if (m_image)
            error = m_image->Plot(x, y);
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = Fill(x,y, 1,1);
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        if (m_image)
            error = m_image->Fill(x,y, w,h);
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Draw
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError Draw
    (tOffset x,
     tOffset y,
     tOffset x2,
     tOffset y2) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        if (m_image)
            error = m_image->Draw(x,y, x2,y2);
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DrawCircle
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError DrawCircle
    (tOffset x,
     tOffset y,
     tSize r,
     eQuadrant q=e_QUADRANT_ALL) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        if ((image = Image()))
        if (e_QUADRANT_ALL == (e_QUADRANT_ALL & q))
        {
            cBresenhamCircleImage circle(*image);
            BresenhamCircleT(circle, *image, x,y, r);
        }
        else
        {
            cBresenhamCircleQuadrantImage circle(*image, q);
            BresenhamCircleT(circle, *image, x,y, r);
        }
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FillCircle
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError FillCircle
    (tOffset x,
     tOffset y,
     tSize r,
     eQuadrant q=e_QUADRANT_ALL) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        if ((image = Image()))
        if (e_QUADRANT_ALL == (e_QUADRANT_ALL & q))
        {
            cBresenhamFilledCircleImage circle(*image);
            BresenhamCircleT(circle, *image, x,y, r);
        }
        else
        {
            cBresenhamFilledCircleQuadrantImage circle(*image, q);
            BresenhamCircleT(circle, *image, x,y, r);
        }
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DrawEllipse
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError DrawEllipse
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h,
     eQuadrant q=e_QUADRANT_ALL) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        if ((image = Image()))
        if (e_QUADRANT_ALL == (e_QUADRANT_ALL & q))
        {
            cBresenhamEllipseImage ellipse(*image);
            BresenhamEllipseT(ellipse, *image, x,y, w,h);
        }
/*
        else
        {
            cMidpointEllipseImage ellipse(*image);
            ellipse.PlotEllipse(*image, x,y, w,h, q);
        }
*/
        else
        {
            cBresenhamEllipseQuadrantImage ellipse(*image, q);
            BresenhamEllipseT(ellipse, *image, x,y, w,h);
        }

#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FillEllipse
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual eError FillEllipse
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h,
     eQuadrant q=e_QUADRANT_ALL) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        if ((image = Image()))
        if (e_QUADRANT_ALL == (e_QUADRANT_ALL & q))
        {
            cBresenhamFilledEllipseImage ellipse(*image);
            BresenhamEllipseT(ellipse, *image, x,y, w,h);
        }
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetAsImage
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual tImageInterface* SetAsImage() 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* prevImage = 0;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual tImageInterface* SetImage
    (tImageInterface* image) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* prevImage = 0;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        prevImage = m_image;
        m_image = image;
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Image
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual tImageInterface* Image() const 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* image = 0;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        image = m_image;
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return image;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGE_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImageExtends
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cImageT<cImage,cImageImplement,cImageInterface>
cImageExtends;
/**
 **********************************************************************
 *  Class: cImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cImage
: public cImageExtends
{
public:
    typedef cImageExtends cExtends;
    typedef cImage cDerives;

    /**
     **********************************************************************
     * Constructor: cImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cImage
    (cImageInterface* image=0) 
    : cExtends(image)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImage
     *
     *     Author: $author$
     *       Date: 5/27/2009
     **********************************************************************
     */
    virtual ~cImage()
    {
    }
};
#else /* !defined(CIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGE_HXX) || defined(CIMAGE_MEMBERS_ONLY) */

