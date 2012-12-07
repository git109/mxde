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
 *   File: cbresenhamimage.hxx
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
#ifndef _CBRESENHAMIMAGE_HXX
#define _CBRESENHAMIMAGE_HXX

#include "cimageinterface.hxx"
#include "cbresenham.hxx"

/**
 **********************************************************************
 *  Class: cBresenhamImageBase
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamImageBase
{
public:
    typedef cBresenhamImageBase cDerives;

    cImageInterface& m_image;

    /**
     **********************************************************************
     * Constructor: cBresenhamImageBase
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamImageBase
    (cImageInterface& image) 
    : m_image(image)
    {
    }

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual void Plot
    (cImageInterface& pixel, int x, int y) 
    {
        m_image.Fill(x,y, 1,1);
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual void Fill
    (cImageInterface& pixel, int x, int y, int w, int h) 
    {
        m_image.Fill(x,y, w,h);
    }
};

/**
 **********************************************************************
 * Typedef: cBresenhamCircleImageExtends
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cBresenhamCircleT
<cImageInterface, cImageInterface, cBresenhamImageBase>
cBresenhamCircleImageExtends;
/**
 **********************************************************************
 *  Class: cBresenhamCircleImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamCircleImage
: public cBresenhamCircleImageExtends
{
public:
    typedef cBresenhamCircleImageExtends cExtends;
    typedef cBresenhamCircleImage cDerives;
    /**
     **********************************************************************
     * Constructor: cBresenhamCircleImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamCircleImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamCircleQuadrantImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamCircleQuadrantImage
: public cBresenhamCircleImage
{
public:
    typedef cBresenhamCircleImage cExtends;
    typedef cBresenhamCircleQuadrantImage cDerives;

    eQuadrant m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamCircleQuadrantImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamCircleQuadrantImage
    (cImageInterface& image,
     eQuadrant quadrant=e_QUADRANT_ALL) 
    : cExtends(image),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Function: CirclePlot
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual void CirclePlot
    (cImageInterface& pixel, int cx, int cy, int x, int y) 
    {
         switch(m_quadrant)
         {
         case e_QUADRANT_TOP_RIGHT:
             Plot(pixel, cx+x, cy-y);
             Plot(pixel, cx+y, cy-x);
             break;
         case e_QUADRANT_BOTTOM_RIGHT:
             Plot(pixel, cx+x, cy+y);
             Plot(pixel, cx+y, cy+x);
             break;
         case e_QUADRANT_BOTTOM_LEFT:
             Plot(pixel, cx-x, cy+y);
             Plot(pixel, cx-y, cy+x);
             break;
         case e_QUADRANT_TOP_LEFT:
             Plot(pixel, cx-x, cy-y);
             Plot(pixel, cx-y, cy-x);
             break;

         case e_QUADRANT_TOP_RIGHT | e_QUADRANT_BOTTOM_RIGHT:
             Plot(pixel, cx+x, cy-y);
             Plot(pixel, cx+y, cy-x);
             Plot(pixel, cx+x, cy+y);
             Plot(pixel, cx+y, cy+x);
             break;
         case e_QUADRANT_BOTTOM_RIGHT | e_QUADRANT_BOTTOM_LEFT:
             Plot(pixel, cx+x, cy+y);
             Plot(pixel, cx+y, cy+x);
             Plot(pixel, cx-x, cy+y);
             Plot(pixel, cx-y, cy+x);
             break;
         case e_QUADRANT_BOTTOM_LEFT | e_QUADRANT_TOP_LEFT:
             Plot(pixel, cx-x, cy+y);
             Plot(pixel, cx-y, cy+x);
             Plot(pixel, cx-x, cy-y);
             Plot(pixel, cx-y, cy-x);
             break;
         case e_QUADRANT_TOP_LEFT | e_QUADRANT_TOP_RIGHT:
             Plot(pixel, cx-x, cy-y);
             Plot(pixel, cx-y, cy-x);
             Plot(pixel, cx+x, cy-y);
             Plot(pixel, cx+y, cy-x);
             break;

         default:
             Plot(pixel, cx+x, cy-y);
             Plot(pixel, cx+y, cy-x);
             Plot(pixel, cx+x, cy+y);
             Plot(pixel, cx+y, cy+x);
             Plot(pixel, cx-x, cy+y);
             Plot(pixel, cx-y, cy+x);
             Plot(pixel, cx-x, cy-y);
             Plot(pixel, cx-y, cy-x);
         }
    }
};

/**
 **********************************************************************
 * Typedef: cBresenhamFilledCircleImageExtends
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cBresenhamFilledCircleT
<cImageInterface, cImageInterface, cBresenhamImageBase>
cBresenhamFilledCircleImageExtends;
/**
 **********************************************************************
 *  Class: cBresenhamFilledCircleImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamFilledCircleImage
: public cBresenhamFilledCircleImageExtends
{
public:
    typedef cBresenhamFilledCircleImageExtends cExtends;
    typedef cBresenhamFilledCircleImage cDerives;
    /**
     **********************************************************************
     * Constructor: cBresenhamFilledCircleImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamFilledCircleImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledCircleQuadrantImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamFilledCircleQuadrantImage
: public cBresenhamFilledCircleImage
{
public:
    typedef cBresenhamFilledCircleImage cExtends;
    typedef cBresenhamFilledCircleQuadrantImage cDerives;

    eQuadrant m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledCircleQuadrantImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamFilledCircleQuadrantImage
    (cImageInterface& image,
     eQuadrant quadrant=e_QUADRANT_ALL) 
    : cExtends(image),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Function: CirclePlot
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual void CirclePlot
    (cImageInterface& pixel, int cx, int cy, int x, int y) 
    {
         switch(m_quadrant)
         {
         case e_QUADRANT_TOP_RIGHT:
             Fill(pixel, cx, cy-y, x+1, 1);
             Fill(pixel, cx, cy-x, y+1, 1);
             break;
         case e_QUADRANT_BOTTOM_RIGHT:
             Fill(pixel, cx, cy+x, y+1, 1);
             Fill(pixel, cx, cy+y, x+1, 1);
             break;
         case e_QUADRANT_BOTTOM_LEFT:
             Fill(pixel, cx-y, cy+x, y+1, 1);
             Fill(pixel, cx-x, cy+y, x+1, 1);
             break;
         case e_QUADRANT_TOP_LEFT:
             Fill(pixel, cx-x, cy-y, x+1, 1);
             Fill(pixel, cx-y, cy-x, y+1, 1);
             break;

         case e_QUADRANT_TOP_RIGHT | e_QUADRANT_BOTTOM_RIGHT:
             Fill(pixel, cx, cy-y, x+1, 1);
             Fill(pixel, cx, cy-x, y+1, 1);
             Fill(pixel, cx, cy+x, y+1, 1);
             Fill(pixel, cx, cy+y, x+1, 1);
             break;
         case e_QUADRANT_BOTTOM_RIGHT | e_QUADRANT_BOTTOM_LEFT:
             Fill(pixel, cx, cy+x, y+1, 1);
             Fill(pixel, cx, cy+y, x+1, 1);
             Fill(pixel, cx-y, cy+x, y+1, 1);
             Fill(pixel, cx-x, cy+y, x+1, 1);
             break;
         case e_QUADRANT_BOTTOM_LEFT | e_QUADRANT_TOP_LEFT:
             Fill(pixel, cx-y, cy+x, y+1, 1);
             Fill(pixel, cx-x, cy+y, x+1, 1);
             Fill(pixel, cx-x, cy-y, x+1, 1);
             Fill(pixel, cx-y, cy-x, y+1, 1);
             break;
         case e_QUADRANT_TOP_LEFT | e_QUADRANT_TOP_RIGHT:
             Fill(pixel, cx-x, cy-y, x+1, 1);
             Fill(pixel, cx-y, cy-x, y+1, 1);
             Fill(pixel, cx, cy-y, x+1, 1);
             Fill(pixel, cx, cy-x, y+1, 1);
             break;

         default:
             Fill(pixel, cx-x, cy-y, x+x+1, 1);
             Fill(pixel, cx-y, cy-x, y+y+1, 1);
             Fill(pixel, cx-y, cy+x, y+y+1, 1);
             Fill(pixel, cx-x, cy+y, x+x+1, 1);
         }
    }
};

/**
 **********************************************************************
 * Typedef: cBresenhamEllipseImageExtends
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cBresenhamEllipseT
<cImageInterface, cImageInterface, cBresenhamImageBase>
cBresenhamEllipseImageExtends;
/**
 **********************************************************************
 *  Class: cBresenhamEllipseImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamEllipseImage
: public cBresenhamEllipseImageExtends
{
public:
    typedef cBresenhamEllipseImageExtends cExtends;
    typedef cBresenhamEllipseImage cDerives;
    /**
     **********************************************************************
     * Constructor: cBresenhamEllipseImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamEllipseImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamEllipseQuadrantImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamEllipseQuadrantImage
: public cBresenhamEllipseImage
{
public:
    typedef cBresenhamEllipseImage cExtends;
    typedef cBresenhamEllipseQuadrantImage cDerives;

    eQuadrant m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamEllipseQuadrantImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamEllipseQuadrantImage
    (cImageInterface& image,
     eQuadrant quadrant=e_QUADRANT_ALL) 
    : cExtends(image),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual void EllipsePlot
    (cImageInterface& pixel, int cx, int cy, int x, int y) 
    {
         switch(m_quadrant)
         {
         case e_QUADRANT_TOP_RIGHT:
            Plot(pixel, cx + x, cy - y);
            break;
         case e_QUADRANT_BOTTOM_RIGHT:
            Plot(pixel, cx + x, cy + y);
            break;
         case e_QUADRANT_BOTTOM_LEFT:
            Plot(pixel, cx - x, cy + y);
            break;
         case e_QUADRANT_TOP_LEFT:
            Plot(pixel, cx - x, cy - y);
            break;

         case e_QUADRANT_TOP_RIGHT | e_QUADRANT_BOTTOM_RIGHT:
            Plot(pixel, cx + x, cy - y);
            Plot(pixel, cx + x, cy + y);
            break;
         case e_QUADRANT_BOTTOM_RIGHT | e_QUADRANT_BOTTOM_LEFT:
            Plot(pixel, cx + x, cy + y);
            Plot(pixel, cx - x, cy + y);
            break;
         case e_QUADRANT_BOTTOM_LEFT | e_QUADRANT_TOP_LEFT:
            Plot(pixel, cx - x, cy + y);
            Plot(pixel, cx - x, cy - y);
            break;
         case e_QUADRANT_TOP_LEFT | e_QUADRANT_TOP_RIGHT:
            Plot(pixel, cx - x, cy - y);
            Plot(pixel, cx + x, cy - y);
            break;

         default:
            Plot(pixel, cx + x, cy - y);
            Plot(pixel, cx + x, cy + y);
            Plot(pixel, cx - x, cy + y);
            Plot(pixel, cx - x, cy - y);
         }
    }
};

/**
 **********************************************************************
 * Typedef: cBresenhamFilledEllipseImageExtends
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cBresenhamFilledEllipseT
<cImageInterface, cImageInterface, cBresenhamImageBase>
cBresenhamFilledEllipseImageExtends;
/**
 **********************************************************************
 *  Class: cBresenhamFilledEllipseImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamFilledEllipseImage
: public cBresenhamFilledEllipseImageExtends
{
public:
    typedef cBresenhamFilledEllipseImageExtends cExtends;
    typedef cBresenhamFilledEllipseImage cDerives;
    /**
     **********************************************************************
     * Constructor: cBresenhamFilledEllipseImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamFilledEllipseImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledEllipseQuadrantImage
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class cBresenhamFilledEllipseQuadrantImage
: public cBresenhamFilledEllipseImage
{
public:
    typedef cBresenhamFilledEllipseImage cExtends;
    typedef cBresenhamFilledEllipseQuadrantImage cDerives;

    eQuadrant m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledEllipseQuadrantImage
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamFilledEllipseQuadrantImage
    (cImageInterface& image,
     eQuadrant quadrant=e_QUADRANT_ALL) 
    : cExtends(image),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual void EllipsePlot
    (cImageInterface& pixel, int cx, int cy, int x, int y) 
    {
         switch(m_quadrant)
         {
         case e_QUADRANT_TOP_RIGHT:
            Fill(pixel, cx, cy - y, x+1, 1);
            break;
         case e_QUADRANT_BOTTOM_RIGHT:
            Fill(pixel, cx, cy + y, x+1, 1);
            break;
         case e_QUADRANT_BOTTOM_LEFT:
            Fill(pixel, cx - x, cy + y, x+1, 1);
            break;
         case e_QUADRANT_TOP_LEFT:
            Fill(pixel, cx - x, cy - y, x+1, 1);
            break;

         case e_QUADRANT_TOP_RIGHT | e_QUADRANT_BOTTOM_RIGHT:
            Fill(pixel, cx, cy - y, x+1, 1);
            Fill(pixel, cx, cy + y, x+1, 1);
            break;
         case e_QUADRANT_BOTTOM_RIGHT | e_QUADRANT_BOTTOM_LEFT:
            Fill(pixel, cx, cy + y, x+1, 1);
            Fill(pixel, cx - x, cy + y, x+1, 1);
            break;
         case e_QUADRANT_BOTTOM_LEFT | e_QUADRANT_TOP_LEFT:
            Fill(pixel, cx - x, cy + y, x+1, 1);
            Fill(pixel, cx - x, cy - y, x+1, 1);
            break;
         case e_QUADRANT_TOP_LEFT | e_QUADRANT_TOP_RIGHT:
            Fill(pixel, cx - x, cy - y, x+1, 1);
            Fill(pixel, cx, cy - y, x+1, 1);
            break;

         default:
            Fill(pixel, cx - x, cy + y, x+x+1, 1);
            Fill(pixel, cx - x, cy - y, x+x+1, 1);
         }
    }
};
#endif /* _CBRESENHAMIMAGE_HXX */
