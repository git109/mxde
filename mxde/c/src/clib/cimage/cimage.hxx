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
#include "cexportbase.hxx"
#include "cbresenhamlineimage.hxx"
#include "cmidpointcircleimage.hxx"
#include "cmidpointellipseimage.hxx"
#include "chollowmidpointellipseimage.hxx"
#include "cfilltriangle.hxx"
#include "cbaseimage.hxx"

/* cImage definition
 */
class c_EXPORT_CLASS cImage;

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
 class TExportBase=cExportBase,
 class TImplements=TImageImplement,
 class TExtends=TExportBase>
 
class c_EXPORT_CLASS cImageT
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
     *     Date: 8/8/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageInterface& image,
     tOffset x,
     tOffset y) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        error = image.Plot(x,y);
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        tImageInterface* prevImage = SelectImage(&image);
        error = Plot(x,y);
        SelectAsImage(prevImage);
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 8/8/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageInterface& image,
     tOffset x,
     tOffset y,
     tSize w,
     tSize h) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        error = image.Fill(x,y, w,h);
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        tImageInterface* prevImage = SelectImage(&image);
        error = Fill(x,y, w,h);
        SelectAsImage(prevImage);
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
        cImageInterface* image;
        if ((image = Image()))
        {
            cBresenhamLineImage line(*image);
            line.DrawLine(*image, x,y, x2,y2);
        }
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
     eOctant o=e_OCTANT_ALL) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        if ((image = Image()))
        {
            cMidpointCircleImage circle(*image);
            circle.PlotCircle(*image, x,y, r, o);
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
        {
            cFilledMidpointCircleImage circle(*image);
            circle.PlotCircle(*image, x,y, r, q);
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
        {
            cMidpointEllipseImage ellipse(*image);
            ellipse.PlotEllipse(*image, x,y, w,h, q);
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
        {
            cFilledMidpointEllipseImage ellipse(*image);
            ellipse.PlotEllipse(*image, x,y, w,h, q);
        }
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: HollowEllipse
     *
     *   Author: $author$
     *     Date: 2/9/2010
     **********************************************************************
     */
    virtual eError HollowEllipse
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
        {
            cHollowMidpointEllipseImage ellipse(*image);
            ellipse.PlotEllipse(*image, x,y, w,h, q);
        }
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DrawTriangle
     *
     *   Author: $author$
     *     Date: 1/28/2010
     **********************************************************************
     */
    virtual eError DrawTriangle
    (tOffset x1, tOffset y1,
     tOffset x2, tOffset y2,
     tOffset x3, tOffset y3) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FillTriangle
     *
     *   Author: $author$
     *     Date: 1/28/2010
     **********************************************************************
     */
    virtual eError FillTriangle
    (tOffset x1, tOffset y1,
     tOffset x2, tOffset y2,
     tOffset x3, tOffset y3) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        if ((image = Image()))
        {
            cBaseImage baseImage(*this);
            FillTriangleT
            <cBaseImage, cImageInterface, 
             cBresenhamLineContext, cSortedImagePointTriangle,
             cImagePoint, tInt, tLength>
            (baseImage, *image, x1,y1, x2,y2, x3,y3);
        }
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SelectAsImage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual tImageInterface* SelectAsImage
    (tImageInterface* image) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* prevImage = 0;
        if (image)
            prevImage = image->SelectAsImage();
        else
        prevImage = SetImage(image);
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SelectAsImage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual tImageInterface* SelectAsImage() 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* prevImage = Image();
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetAsImage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual tImageInterface* SetAsImage
    (tImageInterface* image) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* prevImage = 0;
        if (image)
            prevImage = image->SetAsImage();
        else
        prevImage = Image();
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
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
        tImageInterface* prevImage = Image();
#if !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SelectImage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual tImageInterface* SelectImage
    (tImageInterface* image) 
#if defined(CIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGE_MEMBER_FUNCS_INTERFACE */
    {
        tImageInterface* prevImage = Image();
        SetImage(image);
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
class c_EXPORT_CLASS cImage
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

