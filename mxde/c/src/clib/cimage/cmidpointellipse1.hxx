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
 *   File: cmidpointellipse.hxx
 *
 * Author: $author$
 *   Date: 7/8/2009
 **********************************************************************
 */
#if !defined(_CMIDPOINTELLIPSE_HXX) || defined(CMIDPOINTELLIPSE_MEMBERS_ONLY)
#if !defined(_CMIDPOINTELLIPSE_HXX) && !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY)
#define _CMIDPOINTELLIPSE_HXX
#endif /* !defined(_CMIDPOINTELLIPSE_HXX) && !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */

#if !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY)
#include "cmidpointcircle.hxx"
#include "cimagebaseposition.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum:  eEllipseQuadrant
 *
 * Author: $author$
 *   Date: 7/8/2009
 **********************************************************************
 */
typedef int 
eEllipseQuadrant;
enum
{
    e_ELLIPSE_QUADRANT_ALL = e_CIRCLE_QUADRANT_ALL,

    e_ELLIPSE_QUADRANT_1 = e_CIRCLE_QUADRANT_1,
    e_ELLIPSE_QUADRANT_2 = e_CIRCLE_QUADRANT_2,
    e_ELLIPSE_QUADRANT_3 = e_CIRCLE_QUADRANT_3,
    e_ELLIPSE_QUADRANT_4 = e_CIRCLE_QUADRANT_4,
};

/**
 **********************************************************************
 * Function: MidpointEllipseT
 *
 *   Author: $author$
 *     Date: 7/8/2009
 **********************************************************************
 */
template<class TImage, class TPixel, class TInt>

void MidpointEllipseT
(TImage &image, TPixel &pixel, 
 TInt cx, TInt cy, TInt a, TInt b, 
 eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL)
{
    TInt x, y, a2, b2, S, T;

    if ((1 == a) && (1 == b))
        image.Plot(pixel, cx,cy);

    else if ((1 == a) && (1 < b))
            image.Fill(pixel, cx,cy-b+1, 1,b+b-1);

    else if ((1 < a) && (1 == b))
            image.Fill(pixel, cx-a+1,cy, a+a-1,1);

    else if ((0 < --a) && (0 < --b))
    {
        a2 = a*a;
        b2 = b*b;
        x = 0;
        y = b;
        S = a2*(1-2*b) + 2*b2;
        T = b2 - 2*a2*(2*b-1);

        image.EllipsePlot(pixel, cx, cy, x, y, q);

        do
        {
            if (S<0)
            {
                S += 2*b2*(2*x+3);
                T += 4*b2*(x+1);
                x++;
            }
            else if (T<0)
            {
                S += 2*b2*(2*x+3) - 4*a2*(y-1);
                T += 4*b2*(x+1) - 2*a2*(2*y-3);
                x++;
                y--;
            }
            else
            {
                S -= 4*a2*(y-1);
                T -= 2*a2*(2*y-3);
                y--;
            }

            image.EllipsePlot(pixel, cx, cy, x, y, q);
        }
        while (y>0);
    }
}

class cMidpointEllipse;

#undef CDB_CLASS
#define CDB_CLASS "cMidpointEllipseT"
/**
 **********************************************************************
 *  Class: cMidpointEllipseT
 *
 * Author: $author$
 *   Date: 7/8/2009
 **********************************************************************
 */
template
<class TDerives=cMidpointEllipse,
 class TImageBase=cImageBase,
 class TImageBaseInterface=cImageBaseInterface,
 class TImage=TImageBaseInterface, 
 class TPixel=TImageBaseInterface,
 class TInt=int,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExtends=TImageBase>

class cMidpointEllipseT
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

    typedef TInt tInt;
    typedef TImage tImage;
    typedef TPixel tPixel;

    /**
     **********************************************************************
     *  Constructor: cMidpointEllipseT
     *
     *       Author: $author$
     *         Date: 7/8/2009
     **********************************************************************
     */
    cMidpointEllipseT
    (tImage& image)
    : cExtends(image)
    {
    }
#else /* !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual void EllipsePlot
    (tPixel &pixel, tInt cx,tInt cy, tInt x,tInt y, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE */
    {
        if (q != e_ELLIPSE_QUADRANT_ALL)
        {
            if (q & e_ELLIPSE_QUADRANT_1)
            Plot(pixel, cx + x, cy - y);

            if (q & e_ELLIPSE_QUADRANT_2)
            Plot(pixel, cx + x, cy + y);

            if (q & e_ELLIPSE_QUADRANT_3)
            Plot(pixel, cx - x, cy + y);

            if (q & e_ELLIPSE_QUADRANT_4)
            Plot(pixel, cx - x, cy - y);
        }
        else
        {
            Plot(pixel, cx + x, cy + y);
            Plot(pixel, cx - x, cy - y);
            Plot(pixel, cx + x, cy - y);
            Plot(pixel, cx - x, cy + y);
        }
    }
#endif /* defined(CMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY)
};
#undef CDB_CLASS

class cFilledMidpointEllipse;

#undef CDB_CLASS
#define CDB_CLASS "cFilledMidpointEllipseT"
/**
 **********************************************************************
 *  Class: cFilledMidpointEllipseT
 *
 * Author: $author$
 *   Date: 7/8/2009
 **********************************************************************
 */
template
<class TDerives=cFilledMidpointEllipse,
 class TMidpointEllipse=cMidpointEllipse,
 class TImageBaseInterface=cImageBaseInterface,
 class TImage=TImageBaseInterface, 
 class TPixel=TImageBaseInterface,
 class TInt=int,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExtends=TMidpointEllipse>

class cFilledMidpointEllipseT
: public TExtends
{
public:
    typedef TExtends cExtends;

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    typedef TInt tInt;
    typedef TImage tImage;
    typedef TPixel tPixel;

    /**
     **********************************************************************
     *  Constructor: cFilledMidpointEllipseT
     *
     *       Author: $author$
     *         Date: 7/8/2009
     **********************************************************************
     */
    cFilledMidpointEllipseT
    (tImage& image)
    : cExtends(image)
    {
    }
#else /* !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual void EllipsePlot
    (tPixel &pixel, tInt cx,tInt cy, tInt x,tInt y, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CFILLEDMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CFILLEDMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE */
    {
        if (q != e_ELLIPSE_QUADRANT_ALL)
        {
            if (q & e_ELLIPSE_QUADRANT_1)
            Fill(pixel, cx, cy - y, x+1, 1);

            if (q & e_ELLIPSE_QUADRANT_2)
            Fill(pixel, cx, cy + y, x+1, 1);

            if (q & e_ELLIPSE_QUADRANT_3)
            Fill(pixel, cx - x, cy + y, x+1, 1);

            if (q & e_ELLIPSE_QUADRANT_4)
            Fill(pixel, cx - x, cy - y, x+1, 1);
        }
        else
        {
            Fill(pixel, cx - x, cy + y, x+x+1, 1);
            Fill(pixel, cx - x, cy - y, x+x+1, 1);
        }
    }
#endif /* defined(CFILLEDMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cMidpointEllipseExtends
 *
 *  Author: $author$
 *    Date: 7/8/2009
 **********************************************************************
 */
typedef cMidpointEllipseT<>
cMidpointEllipseExtends;
/**
 **********************************************************************
 *  Class: cMidpointEllipse
 *
 * Author: $author$
 *   Date: 7/8/2009
 **********************************************************************
 */
class cMidpointEllipse
: public cMidpointEllipseExtends
{
public:
    typedef cMidpointEllipseExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cMidpointEllipse
     *
     *       Author: $author$
     *         Date: 7/8/2009
     **********************************************************************
     */
    cMidpointEllipse
    (tImage& image)
    : cExtends(image)
    {
    }
#else /* !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotEllipse
     *
     *   Author: $author$
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE */
    {
        MidpointEllipseT<cExtends, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
    }
#endif /* defined(CMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY)
};

#if !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cFilledMidpointEllipseExtends
 *
 *  Author: $author$
 *    Date: 7/8/2009
 **********************************************************************
 */
typedef cFilledMidpointEllipseT<>
cFilledMidpointEllipseExtends;
/**
 **********************************************************************
 *  Class: cFilledMidpointEllipse
 *
 * Author: $author$
 *   Date: 7/8/2009
 **********************************************************************
 */
class cFilledMidpointEllipse
: public cFilledMidpointEllipseExtends
{
public:
    typedef cFilledMidpointEllipseExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cFilledMidpointEllipse
     *
     *       Author: $author$
     *         Date: 7/8/2009
     **********************************************************************
     */
    cFilledMidpointEllipse
    (tImage& image)
    : cExtends(image)
    {
    }
#else /* !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotEllipse
     *
     *   Author: $author$
     *     Date: 7/8/2009
     **********************************************************************
     */
    virtual void PlotEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CFILLEDMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CFILLEDMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE */
    {
        MidpointEllipseT<cExtends, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
    }
#endif /* defined(CFILLEDMIDPOINTELLIPSE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY)
};
#else /* !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSE_MEMBERS_ONLY) */

#if !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBERS_ONLY)
class c_EXPORT_CLASS cFilledMidpointEllipseSpace;
/**
 **********************************************************************
 * Typedef: cFilledMidpointEllipseSpaceExtends
 *
 *  Author: $author$
 *    Date: 7/26/2009
 **********************************************************************
 */
typedef cFilledMidpointEllipseT
<cFilledMidpointEllipseSpace, 
 cImageBase, cImageBaseInterface, 
 cImageBase, cImageBasePosition>
cFilledMidpointEllipseSpaceExtends;
/**
 **********************************************************************
 *  Class: cFilledMidpointEllipseSpace
 *
 * Author: $author$
 *   Date: 7/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledMidpointEllipseSpace
: public cFilledMidpointEllipseSpaceExtends
{
public:
    typedef cFilledMidpointEllipseSpaceExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cFilledMidpointEllipseSpace
     *
     *       Author: $author$
     *         Date: 7/26/2009
     **********************************************************************
     */
    cFilledMidpointEllipseSpace()
    : cExtends(*this)
    {
    }
#else /* !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: IsInEllipse
     *
     *   Author: $author$
     *     Date: 7/26/2009
     **********************************************************************
     */
    virtual bool IsInEllipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL)
#if defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CFILLEDMIDPOINTELLIPSESPACE_MEMBER_FUNCS_INTERFACE */
    {
        bool isIn = false;
        pixel.SetIsIn(false);
        MidpointEllipseT<cExtends, tPixel, tInt>
        (*this, pixel, cx,cy, a,b, q);
        isIn = pixel.IsIn();
#if !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBER_FUNCS_IMPLEMENT) */
        return isIn;
    }
#endif /* defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBERS_ONLY)
};
#else /* !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSESPACE_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */

#endif /* !defined(_CMIDPOINTELLIPSE_HXX) || defined(CMIDPOINTELLIPSE_MEMBERS_ONLY) */
