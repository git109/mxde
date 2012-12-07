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
 *   File: cimageextend.hxx
 *
 * Author: $author$
 *   Date: 11/27/2009
 **********************************************************************
 */
#if !defined(_CIMAGEEXTEND_HXX) || defined(CIMAGEEXTEND_MEMBERS_ONLY)
#if !defined(_CIMAGEEXTEND_HXX) && !defined(CIMAGEEXTEND_MEMBERS_ONLY)
#define _CIMAGEEXTEND_HXX
#endif /* !defined(_CIMAGEEXTEND_HXX) && !defined(CIMAGEEXTEND_MEMBERS_ONLY) */

#if !defined(CIMAGEEXTEND_MEMBERS_ONLY)
#include "cimagebase.hxx"
#include "cmidpointellipse.hxx"
#include "cmidpointcircle.hxx"
#include "cfilltriangle.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cImageExtend;

#undef CDB_CLASS
#define CDB_CLASS "cImageExtendT"
/**
 **********************************************************************
 *  Class: cImageExtendT
 *
 * Author: $author$
 *   Date: 11/27/2009
 **********************************************************************
 */
template
<class TDerives=cImageExtend,
 class TImageBase=cImageBase,
 class TImageBaseInterface=cImageBaseInterface,
 class TFilledMidpointEllipse=cFilledMidpointEllipse,
 class TFilledMidpointCircle=cFilledMidpointCircle,
 class TBresenhamLineContext=cBresenhamLineContext,
 class TSortedImagePointTriangle=cSortedImagePointTriangle,
 class TImagePoint=cImagePoint,
 class TInt=INT,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TOffset=TOFFSET,
 class TBase=cBase,
 class TExtends=TImageBase>

class c_EXPORT_CLASS cImageExtendT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    
/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    typedef TFilledMidpointEllipse tFilledMidpointEllipse;
    typedef TFilledMidpointCircle tFilledMidpointCircle;
    typedef TBresenhamLineContext tBresenhamLineContext;
    typedef TSortedImagePointTriangle tSortedImagePointTriangle;
    typedef TImagePoint tImagePoint;
    typedef TLength tLength;
    
    tFilledMidpointEllipse m_filledEllipse;
    tFilledMidpointCircle m_filledCircle;
    
    /**
     **********************************************************************
     *  Constructor: cImageExtendT
     *
     *       Author: $author$
     *         Date: 11/27/2009
     **********************************************************************
     */
    cImageExtendT
    (tImageBaseInterface& image) 
    : cExtends(image),
      m_filledEllipse(*this),
      m_filledCircle(*this)
    {
    }
#else /* !defined(CIMAGEEXTEND_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEEXTEND_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: FillEllipse
     *
     *    Author: $author$
     *      Date: 11/27/2009
     **********************************************************************
     */
    virtual eError FillEllipse
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT)
        MidpointEllipseT
        <tFilledMidpointEllipse, tImageBaseInterface, TInt>
        (m_filledEllipse, pixel, x,y, w,h, quadrant);
#else /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tSize xRadius = w/2;
        tSize yRadius = h/2;
        if (w & 1)
        {
            if (h & 1)
                FillEllipse
                (pixel, x+xRadius,y+yRadius, 
                 xRadius+1,yRadius+1, quadrant);
            else
            {
                FillEllipse
                (pixel, x+xRadius,y+yRadius-1, 
                 xRadius+1,yRadius, quadrant & (e_QUADRANT_1 | e_QUADRANT_4));
                FillEllipse
                (pixel, x+xRadius,y+yRadius, 
                 xRadius+1,yRadius, quadrant & (e_QUADRANT_2 | e_QUADRANT_3));
            }
        }
        else
        {
            if (h & 1)
            {
                FillEllipse
                (pixel, x+xRadius-1,y+yRadius, 
                 xRadius+1,yRadius, quadrant & (e_QUADRANT_1 | e_QUADRANT_2));
                FillEllipse
                (pixel, x+xRadius,y+yRadius, 
                 xRadius,yRadius+1, quadrant & (e_QUADRANT_3 | e_QUADRANT_4));
            }
            else
            {
                FillEllipse
                (pixel, x+xRadius-1,y+yRadius-1, 
                 xRadius,yRadius, quadrant & e_QUADRANT_1);
                FillEllipse
                (pixel, x+xRadius-1,y+yRadius, 
                 xRadius,yRadius, quadrant & e_QUADRANT_2);
                FillEllipse
                (pixel, x+xRadius,y+yRadius-1, 
                 xRadius,yRadius, quadrant & e_QUADRANT_3);
                FillEllipse
                (pixel, x+xRadius,y+yRadius, 
                 xRadius,yRadius, quadrant & e_QUADRANT_4);
            }
        }
#if !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */


    /**
     **********************************************************************
     *  Function: FillCircle
     *
     *    Author: $author$
     *      Date: 11/27/2009
     **********************************************************************
     */
    virtual eError FillCircle
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize r,
     eQuadrant quadrant=e_QUADRANT_ALL)
#if defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT)
        MidpointCircleT
        <tFilledMidpointCircle, tImageBaseInterface, TInt>
        (m_filledCircle, pixel, x,y, r, quadrant);
#else /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) 
        FillTriangleT
        <tImageBaseInterface, tImageBaseInterface, 
         tBresenhamLineContext, tSortedImagePointTriangle,
         tImagePoint, tInt, tLength>
        (*this, pixel, x1,y1, x2,y2, x3,y3);
#else /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEEXTEND_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEEXTEND_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEEXTEND_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImageExtendExtends
 *
 *  Author: $author$
 *    Date: 11/28/2009
 **********************************************************************
 */
typedef cImageExtendT<>
cImageExtendExtends;
/**
 **********************************************************************
 *  Class: cImageExtend
 *
 * Author: $author$
 *   Date: 11/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageExtend
: public cImageExtendExtends
{
public:
    typedef cImageExtendExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cImageExtend
     *
     *       Author: $author$
     *         Date: 11/28/2009
     **********************************************************************
     */
    cImageExtend
    (tImageBaseInterface& image) 
    : cExtends(image)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cImageExtend
     *
     *      Author: $author$
     *        Date: 11/28/2009
     **********************************************************************
     */
    virtual ~cImageExtend()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEEXTEND_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEEXTEND_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEEXTEND_HXX) || defined(CIMAGEEXTEND_MEMBERS_ONLY) */
