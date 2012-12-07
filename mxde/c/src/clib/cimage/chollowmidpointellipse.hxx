/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: chollowmidpointellipse.hxx
 *
 * Author: $author$
 *   Date: 2/9/2010
 **********************************************************************
 */
#if !defined(_CHOLLOWMIDPOINTELLIPSE_HXX) || defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY)
#if !defined(_CHOLLOWMIDPOINTELLIPSE_HXX) && !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY)
#define _CHOLLOWMIDPOINTELLIPSE_HXX
#endif /* !defined(_CHOLLOWMIDPOINTELLIPSE_HXX) && !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY) */

#if !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY)
#include "cmidpointellipse.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cHollowMidpointEllipse;

#undef CDB_CLASS
#define CDB_CLASS "cHollowMidpointEllipseT"
/**
 **********************************************************************
 *  Class: cHollowMidpointEllipseT
 *
 * Author: $author$
 *   Date: 2/9/2010
 **********************************************************************
 */
template
<class TDerives=cHollowMidpointEllipse,
 class TMidpointEllipse=cMidpointEllipse,
 class TImageBaseInterface=cImageBaseInterface,
 class TImage=TImageBaseInterface, 
 class TPixel=TImageBaseInterface,
 class TInt=int,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExtends=TMidpointEllipse>

class c_EXPORT_CLASS cHollowMidpointEllipseT
: public TExtends
{
public:
    typedef TExtends cExtends;

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    typedef TImage tImage;
    typedef TPixel tPixel;

    tInt m_x1,m_y1,m_w1;
    tInt m_x2,m_y2,m_w2;
    tInt m_x3,m_y3,m_w3;
    tInt m_x4,m_y4,m_w4;
    
    /**
     **********************************************************************
     *  Constructor: cHollowMidpointEllipseT
     *
     *       Author: $author$
     *         Date: 2/9/2010
     **********************************************************************
     */
    cHollowMidpointEllipseT
    (tImage& image)
    : cExtends(image),
      m_x1(0),m_y1(0),m_w1(0),
      m_x2(0),m_y2(0),m_w2(0),
      m_x3(0),m_y3(0),m_w3(0),
      m_x4(0),m_y4(0),m_w4(0)
    {
    }
#else /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 2/9/2010
     **********************************************************************
     */
    virtual void EllipsePlot
    (tPixel &pixel, tInt a,tInt b, 
     tInt cx,tInt cy, tInt x,tInt y, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) 
        if (q != e_ELLIPSE_QUADRANT_ALL)
        {
            if (q & e_ELLIPSE_QUADRANT_1)
            //Fill(pixel, cx, cy - y, x+1, 1);
            EllipseHollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, a-x);

            if (q & e_ELLIPSE_QUADRANT_2)
            //Fill(pixel, cx, cy + y, x+1, 1);
            EllipseHollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, a-x);

            if (q & e_ELLIPSE_QUADRANT_3)
            //Fill(pixel, cx - x, cy + y, x+1, 1);
            EllipseHollow(pixel, m_x3,m_y3,m_w3, cx-a, cy + y, a-x);

            if (q & e_ELLIPSE_QUADRANT_4)
            //Fill(pixel, cx - x, cy - y, x+1, 1);
            EllipseHollow(pixel, m_x4,m_y4,m_w4, cx-a, cy - y, a-x);
        }
        else
        {
            //Fill(pixel, cx - x, cy + y, x+x+1, 1);
            //Fill(pixel, cx - x, cy - y, x+x+1, 1);
            EllipseHollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, a-x);
            EllipseHollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, a-x);
            EllipseHollow(pixel, m_x3,m_y3,m_w3, cx-a, cy + y, a-x);
            EllipseHollow(pixel, m_x4,m_y4,m_w4, cx-a, cy - y, a-x);
        }
#else /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: EllipseHollow
     *
     *   Author: $author$
     *     Date: 2/10/2010
     **********************************************************************
     */
    virtual void EllipseHollow
    (tPixel &pixel, 
     tInt& xQ,tInt& yQ, tInt& wQ,
     tInt x,tInt y, tInt w) 
#if defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) 
        if ((0 < wQ) && (yQ != y))
            Fill(pixel, xQ,yQ, wQ,1);
            
        xQ = x;
        yQ = y;
        wQ = w;
#else /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: EllipseStart
     *
     *   Author: $author$
     *     Date: 2/10/2010
     **********************************************************************
     */
    virtual void EllipseStart() 
#if defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) 
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
#else /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: EllipseFinish
     *
     *   Author: $author$
     *     Date: 2/10/2010
     **********************************************************************
     */
    virtual void EllipseFinish
    (tPixel &pixel) 
#if defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) 
        if ((0 < m_w1))
            Fill(pixel, m_x1,m_y1, m_w1,1);
            
        if ((0 < m_w2))
            Fill(pixel, m_x2,m_y2, m_w2,1);
            
        if ((0 < m_w3))
            Fill(pixel, m_x3,m_y3, m_w3,1);
            
        if ((0 < m_w4))
            Fill(pixel, m_x4,m_y4, m_w4,1);
            
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
#else /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CHOLLOWMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cHollowMidpointEllipseExtend
 *
 *  Author: $author$
 *    Date: 2/9/2010
 **********************************************************************
 */
typedef cHollowMidpointEllipseT<>
cHollowMidpointEllipseExtend;
/**
 **********************************************************************
 *  Class: cHollowMidpointEllipse
 *
 * Author: $author$
 *   Date: 2/9/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cHollowMidpointEllipse
: public cHollowMidpointEllipseExtend
{
public:
    typedef cHollowMidpointEllipseExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cHollowMidpointEllipse
     *
     *       Author: $author$
     *         Date: 2/9/2010
     **********************************************************************
     */
    cHollowMidpointEllipse
    (tImage& image)
    : cExtends(image)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY) */

#endif /* !defined(_CHOLLOWMIDPOINTELLIPSE_HXX) || defined(CHOLLOWMIDPOINTELLIPSE_MEMBERS_ONLY) */
