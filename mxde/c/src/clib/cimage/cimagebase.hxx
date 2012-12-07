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
 *   File: cimagebase.hxx
 *
 * Author: $author$
 *   Date: 6/7/2009
 **********************************************************************
 */
#if !defined(_CIMAGEBASE_HXX) || defined(CIMAGEBASE_MEMBERS_ONLY)
#if !defined(_CIMAGEBASE_HXX) && !defined(CIMAGEBASE_MEMBERS_ONLY)
#define _CIMAGEBASE_HXX
#endif /* !defined(_CIMAGEBASE_HXX) && !defined(CIMAGEBASE_MEMBERS_ONLY) */

#if !defined(CIMAGEBASE_MEMBERS_ONLY)
#include "cimagebaseinterface.hxx"
#include "cbase.hxx"

/* cImageBase definition
 */
class c_EXPORT_CLASS cImageBase;

#undef CDB_CLASS
#define CDB_CLASS "cImageBaseT"
/**
 **********************************************************************
 *  Class: cImageBaseT
 *
 * Author: $author$
 *   Date: 6/7/2009
 **********************************************************************
 */
template
<class TDerives=cImageBase,
 class TImageBaseImplement=cImageBaseImplement,
 class TImageBaseInterface=cImageBaseInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TBase=cBase,
 class TImplements=TImageBaseImplement,
 class TExtends=TBase>
 
class cImageBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cImageBaseT cDerives;

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    tImageBaseInterface& m_image;

    /**
     **********************************************************************
     * Constructor: cImageBaseT
     *
     *      Author: $author$
     *        Date: 6/7/2009
     **********************************************************************
     */
    cImageBaseT
    (tImageBaseInterface& image) 
    : m_image(image) 
    {
    }
#else /* !defined(CIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEBASE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 6/7/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y) 
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGEBASE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) 
        pixel.Plot(m_image, x,y);
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 6/7/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h) 
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGEBASE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) 
        pixel.Fill(m_image, x,y, w,h);
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FillEllipse
     *
     *    Author: $author$
     *      Date: 11/26/2009
     **********************************************************************
     */
    virtual eError FillEllipse
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FillEllipseRectangle
     *
     *    Author: $author$
     *      Date: 11/28/2009
     **********************************************************************
     */
    virtual eError FillEllipseRectangle
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: HollowEllipse
     *
     *    Author: $author$
     *      Date: 2/9/2010
     **********************************************************************
     */
    virtual eError HollowEllipse
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: HollowEllipseRectangle
     *
     *    Author: $author$
     *      Date: 2/9/2010
     **********************************************************************
     */
    virtual eError HollowEllipseRectangle
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FillCircle
     *
     *    Author: $author$
     *      Date: 11/26/2009
     **********************************************************************
     */
    virtual eError FillCircle
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize r,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: FillTriangle
     *
     *   Author: $author$
     *     Date: 1/28/2010
     **********************************************************************
     */
    virtual eError FillTriangle
    (tImageBaseInterface& pixel,
     tOffset x1, tOffset y1,
     tOffset x2, tOffset y2,
     tOffset x3, tOffset y3) 
#if defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEBASE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEBASE_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImageBaseExtends
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cImageBaseT<>
cImageBaseExtends;
/**
 **********************************************************************
 *  Class: cImageBase
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageBase
: public cImageBaseExtends
{
public:
    typedef cImageBaseExtends cExtends;
    typedef cImageBase cDerives;
    /**
     **********************************************************************
     * Constructor: cImageBase
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cImageBase
    (cImageBaseInterface& image) 
    : cExtends(image)
    {
    }
#if defined(CIMAGEBASE_INSTANCE_TEST) 
    /**
     **********************************************************************
     * Constructor: cImageBase
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cImageBase() 
    : cExtends(*this)
    {
    }
#endif /* defined(CIMAGEBASE_INSTANCE_TEST) */
};

#else /* !defined(CIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEBASE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEBASE_HXX) || defined(CIMAGEBASE_MEMBERS_ONLY) */
