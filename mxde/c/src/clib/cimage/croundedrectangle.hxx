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
 *   File: croundedrectangle.hxx
 *
 * Author: $author$
 *   Date: 8/31/2009
 **********************************************************************
 */
#ifndef _CROUNDEDRECTANGLE_HXX
#define _CROUNDEDRECTANGLE_HXX

#include "cmidpointellipse.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum:  eRoundedRectangleCorner
 *
 * Author: $author$
 *   Date: 8/31/2009
 **********************************************************************
 */
typedef int eRoundedRectangleCorner;
enum
{
    e_ROUNDED_RECTANGLE_CORNER_NONE         = 0,

    e_ROUNDED_RECTANGLE_CORNER_TOP_LEFT     = (1 << 0),
    e_ROUNDED_RECTANGLE_CORNER_TOP_RIGHT    = (1 << 1),
    e_ROUNDED_RECTANGLE_CORNER_BOTTOM_LEFT  = (1 << 2),
    e_ROUNDED_RECTANGLE_CORNER_BOTTOM_RIGHT = (1 << 3),

    e_ROUNDED_RECTANGLE_CORNER_ALL          = ((1 << 4)-1)
};

#if !defined(CROUNDEDRECTANGLEBASE_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cRoundedRectangleBase
 *
 * Author: $author$
 *   Date: 5/26/2010
 **********************************************************************
 */
class cRoundedRectangleBase
: public cImageBase
{
public:
    typedef cImageBase cExtends;

    typedef cImageBaseInterface tImage;
    typedef cImageBaseInterface tPixel;

    /**
     **********************************************************************
     *  Constructor: cRoundedRectangleBase
     *
     *       Author: $author$
     *         Date: 5/26/2010
     **********************************************************************
     */
    cRoundedRectangleBase
    (tImage& image)
    : cExtends(image)
    {
    }
#else /* !defined(CROUNDEDRECTANGLEBASE_MEMBERS_ONLY) */
#endif /* !defined(CROUNDEDRECTANGLEBASE_MEMBERS_ONLY) */

#if !defined(CROUNDEDRECTANGLEBASE_MEMBERS_ONLY)
};
#else /* !defined(CROUNDEDRECTANGLEBASE_MEMBERS_ONLY) */
#endif /* !defined(CROUNDEDRECTANGLEBASE_MEMBERS_ONLY) */

#if !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cEllipticalRoundedRectangleExtend
 *
 *  Author: $author$
 *    Date: 5/26/2010
 **********************************************************************
 */
typedef cRoundedRectangleBase
cEllipticalRoundedRectangleExtend;
/**
 **********************************************************************
 *  Class: cEllipticalRoundedRectangle
 *
 * Author: $author$
 *   Date: 5/26/2010
 **********************************************************************
 */
class cEllipticalRoundedRectangle
: public cEllipticalRoundedRectangleExtend
{
public:
    typedef cEllipticalRoundedRectangleExtend cExtends;

    cMidpointEllipse m_midpointEllipse;

    /**
     **********************************************************************
     *  Constructor: cEllipticalRoundedRectangle
     *
     *       Author: $author$
     *         Date: 5/26/2010
     **********************************************************************
     */
    cEllipticalRoundedRectangle
    (tImage& image)
    : cExtends(image),
      m_midpointEllipse(image)
    {
    }
#else /* !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */
#endif /* !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: PlotEllipticalRoundedRectangle
     *
     *    Author: $author$
     *      Date: 5/27/2010
     **********************************************************************
     */
    virtual void PlotEllipticalRoundedRectangle
    (tPixel &pixel, tInt cx,tInt cy, 
     tSize cWidth,tSize cHeight, 
     tSize radiusWidth,tSize radiusHeight, 
     tSize thickness = 1)
#if defined(CELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_IMPLEMENT)
        m_midpointEllipse.PlotEllipse
        (pixel, cx,cy, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_4);

        Fill(pixel, cx+thickness,cy-radiusHeight+1, cWidth-thickness-1,1);

        m_midpointEllipse.PlotEllipse
        (pixel, cx+cWidth-thickness,cy, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_1);

        Fill(pixel, cx+cWidth+radiusWidth-thickness-1,cy, 1,cHeight-thickness-1);

        m_midpointEllipse.PlotEllipse
        (pixel, cx+cWidth-thickness,cy+cHeight-thickness, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_2);

        Fill(pixel, cx+thickness,cy+cHeight+radiusHeight-thickness-1, cWidth-thickness-1,1);

        m_midpointEllipse.PlotEllipse
        (pixel, cx,cy+cHeight-thickness, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_3);

        Fill(pixel, cx-radiusWidth+1,cy, 1,cHeight-thickness-1);
#else /* !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY)
};
#else /* !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */
#endif /* !defined(CELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */

#if !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cFilledEllipticalRoundedRectangleExtend
 *
 *  Author: $author$
 *    Date: 5/26/2010
 **********************************************************************
 */
typedef cRoundedRectangleBase
cFilledEllipticalRoundedRectangleExtend;
/**
 **********************************************************************
 *  Class: cFilledEllipticalRoundedRectangle
 *
 * Author: $author$
 *   Date: 5/26/2010
 **********************************************************************
 */
class cFilledEllipticalRoundedRectangle
: public cFilledEllipticalRoundedRectangleExtend
{
public:
    typedef cFilledEllipticalRoundedRectangleExtend cExtends;

    cFilledMidpointEllipse m_midpointEllipse;

    /**
     **********************************************************************
     *  Constructor: cFilledEllipticalRoundedRectangle
     *
     *       Author: $author$
     *         Date: 5/26/2010
     **********************************************************************
     */
    cFilledEllipticalRoundedRectangle
    (tImage& image)
    : cExtends(image),
      m_midpointEllipse(image)
    {
    }
#else /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: PlotEllipticalRoundedRectangle
     *
     *    Author: $author$
     *      Date: 5/26/2010
     **********************************************************************
     */
    virtual void PlotEllipticalRoundedRectangle
    (tPixel &pixel, tInt cx,tInt cy, 
     tSize cWidth,tSize cHeight, 
     tSize radiusWidth,tSize radiusHeight)
#if defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_IMPLEMENT)
        m_midpointEllipse.PlotEllipse
        (pixel, cx,cy, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_4);

        Fill(pixel, cx+1,cy-radiusHeight+1, cWidth-2,radiusHeight-1);

        m_midpointEllipse.PlotEllipse
        (pixel, cx+cWidth-1,cy, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_1);

        Fill(pixel, cx-radiusWidth+1,cy, cWidth+radiusWidth*2-2,cHeight);

        m_midpointEllipse.PlotEllipse
        (pixel, cx+cWidth-1,cy+cHeight-1, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_2);

        Fill(pixel, cx+1,cy+cHeight, cWidth-2,radiusHeight-1);

        m_midpointEllipse.PlotEllipse
        (pixel, cx,cy+cHeight-1, radiusWidth,radiusHeight, e_ELLIPSE_QUADRANT_3);
#else /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY)
};
#else /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLE_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CROUNDEDRECTANGLE_HXX */
