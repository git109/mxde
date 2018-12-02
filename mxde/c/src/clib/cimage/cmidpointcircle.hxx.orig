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
 *   File: cmidpointcircle.hxx
 *
 * Author: $author$
 *   Date: 6/6/2009
 **********************************************************************
 */
#ifndef _CMIDPOINTCIRCLE_HXX
#define _CMIDPOINTCIRCLE_HXX

#include "cimagebase.hxx"

/**
 **********************************************************************
 *   Enum: eCircleOctant
 *
 * Author: $author$
 *   Date: 6/9/2009
 **********************************************************************
 */
typedef unsigned int 
eCircleOctant;
enum
{
    e_CIRCLE_OCTANT_NONE = 0,

    e_CIRCLE_OCTANT_1 = (1 << 1),
    e_CIRCLE_OCTANT_2 = (1 << 2),
    e_CIRCLE_OCTANT_3 = (1 << 3),
    e_CIRCLE_OCTANT_4 = (1 << 4),
    e_CIRCLE_OCTANT_5 = (1 << 5),
    e_CIRCLE_OCTANT_6 = (1 << 6),
    e_CIRCLE_OCTANT_7 = (1 << 7),
    e_CIRCLE_OCTANT_8 = (1 << 8),
    
    e_CIRCLE_OCTANT_NEXT = (e_CIRCLE_OCTANT_8 << 1),
    e_CIRCLE_OCTANT_ALL  = (e_CIRCLE_OCTANT_NEXT-1)
};
/**
 **********************************************************************
 *   Enum: eCircleQuadrant
 *
 * Author: $author$
 *   Date: 6/9/2009
 **********************************************************************
 */
typedef eCircleOctant 
eCircleQuadrant;
enum
{
    e_CIRCLE_QUADRANT_ALL = e_CIRCLE_OCTANT_ALL,

    e_CIRCLE_QUADRANT_1 = (e_CIRCLE_OCTANT_1|e_CIRCLE_OCTANT_2),
    e_CIRCLE_QUADRANT_2 = (e_CIRCLE_OCTANT_3|e_CIRCLE_OCTANT_4),
    e_CIRCLE_QUADRANT_3 = (e_CIRCLE_OCTANT_5|e_CIRCLE_OCTANT_6),
    e_CIRCLE_QUADRANT_4 = (e_CIRCLE_OCTANT_7|e_CIRCLE_OCTANT_8),
};

/**
 **********************************************************************
 * Function: MidpointCircleT
 *
 *   Author: $author$
 *     Date: 6/6/2009
 **********************************************************************
 */
template
<class TImage, class TPixel, class TInt>

void MidpointCircleT
(TImage &image, TPixel &pixel, TInt cx, TInt cy, TInt r, 
 eCircleOctant o=e_CIRCLE_OCTANT_ALL) 
{
    TInt x, y, d;

    if (1 == r)
        image.Plot(pixel, cx,cy);

    else if (0 < (y = --r))
    {
        d = 1-r;

        for (x = 0; x < y; x++)
        {
            image.CirclePlot(pixel, cx,cy, x,y, o);

            if (d<0) 
                d += 2*x+3;
            else
            {
                d += 2*(x-y)+5;
                --y;
            }
        }
        image.CirclePlot(pixel, cx,cy, x,y, o);
    }
}

class cMidpointCircle;

#undef CDB_CLASS
#define CDB_CLASS "cMidpointCircleT"
/**
 **********************************************************************
 *  Class: cMidpointCircleT
 *
 * Author: $author$
 *   Date: 6/6/2009
 **********************************************************************
 */
template
<class TDerives=cMidpointCircle,
 class TImageBase=cImageBase,
 class TImageBaseInterface=cImageBaseInterface,
 class TImage=TImageBaseInterface, 
 class TPixel=TImageBaseInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExtends=TImageBase>
 
class cMidpointCircleT
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

    typedef TPixel tPixel;

    /**
     **********************************************************************
     * Constructor: cMidpointCircleT
     *
     *      Author: $author$
     *        Date: 6/6/2009
     **********************************************************************
     */
    cMidpointCircleT
    (tImageBaseInterface& image) 
    : cExtends(image)
    {
    }
    /**
     **********************************************************************
     * Function: CirclePlot
     *
     *   Author: $author$
     *     Date: 6/7/2009
     **********************************************************************
     */
    virtual void CirclePlot
    (TPixel &pixel, tInt cx,tInt cy, tInt x,tInt y, 
     eCircleOctant o=e_CIRCLE_OCTANT_ALL) 
    {
        if (o != e_CIRCLE_OCTANT_ALL)
        {
            if (o & e_CIRCLE_OCTANT_8) Plot(pixel, cx-x, cy-y);
            if (o & e_CIRCLE_OCTANT_1) Plot(pixel, cx+x, cy-y);

            if (o & e_CIRCLE_OCTANT_7) Plot(pixel, cx-y, cy-x);
            if (o & e_CIRCLE_OCTANT_2) Plot(pixel, cx+y, cy-x);

            if (o & e_CIRCLE_OCTANT_6) Plot(pixel, cx-y, cy+x);
            if (o & e_CIRCLE_OCTANT_3) Plot(pixel, cx+y, cy+x);

            if (o & e_CIRCLE_OCTANT_5) Plot(pixel, cx-x, cy+y);
            if (o & e_CIRCLE_OCTANT_4) Plot(pixel, cx+x, cy+y);
        }
        else
        {
            Plot(pixel, cx-x, cy-y);
            Plot(pixel, cx+x, cy-y);

            Plot(pixel, cx-y, cy-x);
            Plot(pixel, cx+y, cy-x);

            Plot(pixel, cx-y, cy+x);
            Plot(pixel, cx+y, cy+x);

            Plot(pixel, cx-x, cy+y);
            Plot(pixel, cx+x, cy+y);
        }
    }
};
#undef CDB_CLASS

class cFilledMidpointCircle;

#undef CDB_CLASS
#define CDB_CLASS "cFilledMidpointCircleT"
/**
 **********************************************************************
 *  Class: cFilledMidpointCircleT
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
template
<class TDerives=cFilledMidpointCircle,
 class TMidpointCircle=cMidpointCircle,
 class TImageBaseInterface=cImageBaseInterface,
 class TImage=TImageBaseInterface, 
 class TPixel=TImageBaseInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExtends=TMidpointCircle>
 
class cFilledMidpointCircleT
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

    typedef TPixel tPixel;

    /**
     **********************************************************************
     * Constructor: cFilledMidpointCircleT
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cFilledMidpointCircleT
    (tImageBaseInterface& image) 
    : cExtends(image) 
    {
    }
    /**
     **********************************************************************
     * Function: CirclePlot
     *
     *   Author: $author$
     *     Date: 6/8/2009
     **********************************************************************
     */
    virtual void CirclePlot
    (TPixel &pixel, tInt cx,tInt cy, tInt x,tInt y,
     eCircleOctant o=e_CIRCLE_OCTANT_ALL) 
    {
        if (o != e_CIRCLE_OCTANT_ALL)
        {
            if ((o & e_CIRCLE_QUADRANT_4)
                  == e_CIRCLE_QUADRANT_4) 
            {
                Fill(pixel, cx-x, cy-y, x+1, 1);
                Fill(pixel, cx-y, cy-x, y+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_1)
                  == e_CIRCLE_QUADRANT_1) 
            {
                Fill(pixel, cx, cy-y, x+1, 1);
                Fill(pixel, cx, cy-x, y+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_3)
                  == e_CIRCLE_QUADRANT_3) 
            {
                Fill(pixel, cx-y, cy+x, y+1, 1);
                Fill(pixel, cx-x, cy+y, x+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_2)
                  == e_CIRCLE_QUADRANT_2) 
            {
                Fill(pixel, cx, cy+x, y+1, 1);
                Fill(pixel, cx, cy+y, x+1, 1);
            }
        }
        else
        {
            //Plot(pixel, cx-x, cy-y);
            //Plot(pixel, cx+x, cy-y);
            if (1 > x)
                Plot(pixel, cx, cy-y);
            else
            Fill(pixel, cx-x, cy-y, x+x-1, 1);

            //Plot(pixel, cx-y, cy-x);
            //Plot(pixel, cx+y, cy-x);
            if (1 > y)
                Plot(pixel, cx, cy-x);
            else
            Fill(pixel, cx-y, cy-x, y+y-1, 1);

            //Plot(pixel, cx-y, cy+x);
            //Plot(pixel, cx+y, cy+x);
            if (1 > y)
                Plot(pixel, cx, cy+x);
            else
            Fill(pixel, cx-y, cy+x, y+y-1, 1);

            //Plot(pixel, cx-x, cy+y);
            //Plot(pixel, cx+x, cy+y);
            if (1 > x)
                Plot(pixel, cx, cy+y);
            else
            Fill(pixel, cx-x, cy+y, x+x-1, 1);
        }
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cMidpointCircleExtends
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cMidpointCircleT<>
cMidpointCircleExtends;
/**
 **********************************************************************
 *  Class: cMidpointCircle
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class cMidpointCircle
: public cMidpointCircleExtends
{
public:
    typedef cMidpointCircleExtends cExtends;
    typedef cMidpointCircle cDerives;
    /**
     **********************************************************************
     * Constructor: cMidpointCircle
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cMidpointCircle
    (cImageBaseInterface& image) 
    : cExtends(image)
    {
    }
    /**
     **********************************************************************
     * Function: PlotCircle
     *
     *   Author: $author$
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual void PlotCircle
    (tImageBaseInterface &pixel, tInt cx,tInt cy, tInt r, 
     eCircleOctant o=e_CIRCLE_OCTANT_ALL) 
    {
        MidpointCircleT<cExtends, tImageBaseInterface, tInt>
        (*this, pixel, cx,cy,r, o);
    }
};

/**
 **********************************************************************
 * Typedef: cFilledMidpointCircleExtends
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cFilledMidpointCircleT<>
cFilledMidpointCircleExtends;
/**
 **********************************************************************
 *  Class: cFilledMidpointCircle
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class cFilledMidpointCircle
: public cFilledMidpointCircleExtends
{
public:
    typedef cFilledMidpointCircleExtends cExtends;
    typedef cFilledMidpointCircle cDerives;
    /**
     **********************************************************************
     * Constructor: cFilledMidpointCircle
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cFilledMidpointCircle
    (cImageBaseInterface& image) 
    : cExtends(image)
    {
    }
    /**
     **********************************************************************
     * Function: PlotCircle
     *
     *   Author: $author$
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual void PlotCircle
    (tImageBaseInterface &pixel, tInt cx,tInt cy, tInt r, 
     eCircleOctant o=e_CIRCLE_OCTANT_ALL) 
    {
        MidpointCircleT<cExtends, tImageBaseInterface, tInt>
        (*this, pixel, cx,cy,r, o);
    }
};
#endif /* _CMIDPOINTCIRCLE_HXX */
