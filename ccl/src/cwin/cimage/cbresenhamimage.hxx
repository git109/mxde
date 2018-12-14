/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cbresenhamimage.hxx
 *
 * Author: $author$
 *   Date: 4/7/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBRESENHAMIMAGE_HXX
#define _CBRESENHAMIMAGE_HXX

#include "cimageinterface.hxx"
#include "bresenham.hxx"

/**
 **********************************************************************
 *  Class: cBresenhamImage
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cBresenhamImage
{
public:
    cImageInterface &m_image;

    /**
     **********************************************************************
     * Constructor: cBresenhamImage
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cBresenhamImage(cImageInterface &image)
    : m_image(image)
    {
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    void Plot(cImageInterface &pixel, int x, int y)
    {
        m_image.Fill(x,y, 1,1);
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    void Fill(cImageInterface &pixel, int x, int y, int w, int h)
    {
        m_image.Fill(x,y, w,h);
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamCircleImage
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cBresenhamCircleImage
: public cBresenhamCircleT
  <cImageInterface, cImageInterface, cBresenhamImage>
{
public:
    typedef cBresenhamCircleT
    <cImageInterface, cImageInterface, cBresenhamImage> cIs;

    /**
     **********************************************************************
     * Constructor: cBresenhamCircleImage
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cBresenhamCircleImage(cImageInterface &image)
    : cIs(image) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledCircleImage
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cBresenhamFilledCircleImage
: public cBresenhamFilledCircleT
  <cImageInterface, cImageInterface, cBresenhamImage>
{
public:
    typedef cBresenhamFilledCircleT
    <cImageInterface, cImageInterface, cBresenhamImage> cIs;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledCircleImage
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cBresenhamFilledCircleImage(cImageInterface &image)
    : cIs(image) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledCircleImageQuadrant
 *
 * Author: $author$
 *   Date: 4/7/2004
 **********************************************************************
 */
class cBresenhamFilledCircleImageQuadrant
: public cBresenhamFilledCircleImage
{
public:
    typedef cBresenhamFilledCircleImage cIs;

    int m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledCircleImageQuadrant
     *
     *      Author: $author$
     *        Date: 4/7/2004
     **********************************************************************
     */
    cBresenhamFilledCircleImageQuadrant
    (cImageInterface &image, int quadrant=-1)
    : cIs(image),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Function: CirclePlot
     *
     *   Author: $author$
     *     Date: 4/7/2004
     **********************************************************************
     */
     void CirclePlot(cImageInterface &pixel, int cx, int cy, int x, int y)
     {
         switch(m_quadrant)
         {
         case 0:
             Fill(pixel, cx, cy-y, x+1, 1);
             Fill(pixel, cx, cy-x, y+1, 1);
             break;

         case 1:
             Fill(pixel, cx, cy+x, y+1, 1);
             Fill(pixel, cx, cy+y, x+1, 1);
             break;

         case 2:
             Fill(pixel, cx-y, cy+x, y+1, 1);
             Fill(pixel, cx-x, cy+y, x+1, 1);
             break;

         case 3:
             Fill(pixel, cx-x, cy-y, x+1, 1);
             Fill(pixel, cx-y, cy-x, y+1, 1);
             break;

         case 4:
             Fill(pixel, cx, cy-y, x+1, 1);
             Fill(pixel, cx, cy-x, y+1, 1);
             Fill(pixel, cx, cy+x, y+1, 1);
             Fill(pixel, cx, cy+y, x+1, 1);
             break;

         case 5:
             Fill(pixel, cx, cy+x, y+1, 1);
             Fill(pixel, cx, cy+y, x+1, 1);
             Fill(pixel, cx-y, cy+x, y+1, 1);
             Fill(pixel, cx-x, cy+y, x+1, 1);
             break;

         case 6:
             Fill(pixel, cx-y, cy+x, y+1, 1);
             Fill(pixel, cx-x, cy+y, x+1, 1);
             Fill(pixel, cx-x, cy-y, x+1, 1);
             Fill(pixel, cx-y, cy-x, y+1, 1);
             break;

         case 7:
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
 *  Class: cBresenhamEllipseImage
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cBresenhamEllipseImage
: public cBresenhamEllipseT
  <cImageInterface, cImageInterface, cBresenhamImage>
{
public:
    typedef cBresenhamEllipseT
    <cImageInterface, cImageInterface, cBresenhamImage> cIs;

    /**
     **********************************************************************
     * Constructor: cBresenhamEllipseImage
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cBresenhamEllipseImage(cImageInterface &image)
    : cIs(image) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamEllipseImageQuadrant
 *
 * Author: $author$
 *   Date: 1/23/2006
 **********************************************************************
 */
class cBresenhamEllipseImageQuadrant
: public cBresenhamEllipseImage
{
public:
    typedef cBresenhamEllipseImage cIs;

    int m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamEllipseImageQuadrant
     *
     *      Author: $author$
     *        Date: 1/23/2006
     **********************************************************************
     */
    cBresenhamEllipseImageQuadrant
    (cImageInterface &image, int quadrant=-1)
    : cIs(image),
      m_quadrant(quadrant) 
    {
    }
    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    void EllipsePlot
    (cImageInterface &pixel, int cx, int cy, int x, int y)
    {
        switch(m_quadrant)
        {
        case 0:
            break;

        default:
            Plot(pixel, cx + x, cy + y);
            Plot(pixel, cx - x, cy - y);
            Plot(pixel, cx + x, cy - y);
            Plot(pixel, cx - x, cy + y);
        }
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledEllipseImage
 *
 * Author: $author$
 *   Date: 3/1/2004
 **********************************************************************
 */
class cBresenhamFilledEllipseImage
: public cBresenhamFilledEllipseT
  <cImageInterface, cImageInterface, cBresenhamImage>
{
public:
    typedef cBresenhamFilledEllipseT
    <cImageInterface, cImageInterface, cBresenhamImage> cIs;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledEllipseImage
     *
     *      Author: $author$
     *        Date: 3/1/2004
     **********************************************************************
     */
    cBresenhamFilledEllipseImage(cImageInterface &image)
    : cIs(image) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledEllipseImageQuadrant
 *
 * Author: $author$
 *   Date: 1/23/2006
 **********************************************************************
 */
class cBresenhamFilledEllipseImageQuadrant
: public cBresenhamFilledEllipseImage
{
public:
    typedef cBresenhamFilledEllipseImage cIs;

    int m_quadrant;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledEllipseImageQuadrant
     *
     *      Author: $author$
     *        Date: 1/23/2006
     **********************************************************************
     */
    cBresenhamFilledEllipseImageQuadrant
    (cImageInterface &image, int quadrant=-1)
    : cIs(image),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Function: EllipsePlot
     *
     *   Author: $author$
     *     Date: 3/1/2004
     **********************************************************************
     */
    void EllipsePlot
    (cImageInterface &pixel, int cx, int cy, int x, int y)
    {
        switch(m_quadrant)
        {
        case 0:
            break;

        default:
            Fill(pixel, cx - x, cy + y, x+x+1, 1);
            Fill(pixel, cx - x, cy - y, x+x+1, 1);
        }
    }
};

#endif /* ndef _CBRESENHAMIMAGE_HXX */
