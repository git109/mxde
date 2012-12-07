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
 *   File: cbresenham.hxx
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
#ifndef _CBRESENHAM_HXX
#define _CBRESENHAM_HXX

#include "cbase.hxx"

/**
 **********************************************************************
 * Function: BresenhamLineT
 *
 *   Author: $author$
 *     Date: 5/27/2009
 **********************************************************************
 */
template<class TImage, class TPixel>
void BresenhamLineT
(TImage &image, TPixel &pixel, int x1, int y1, int x2, int y2)
{
    int dx,dy,i1,i2,d,x,y;

    if (0 > (dx = x2-x1))
        dx = -dx;

    if (0 > (dy = y2-y1))
        dy = -dy;

    if (dx < dy)
    {
        if (y1 > y2)
        {
            x = x2;
            x2 = x1;
            x1 = x;
            y = y2;
            y2 = y1;
            y1 = y;
        }
        else 
        {
            x = x1;
            y = y1;
        }

        d = 2*dx-dy;
        i1 = 2*dx;
        i2 = 2*(dx - dy);

        image.Plot(pixel, x, y);

        if (x1 < x2)
        {
            while ((++y) <= y2)
            {
                if (d < 0)
                    d += i1;
                else
                {
                    d += i2;
                    --x;
                }
                image.Plot(pixel, x, y);
            }
        }
        else
        {
            while ((++y) <= y2)
            {
                if (d < 0)
                    d += i1;
                else
                {
                    d += i2;
                    x++;
                }
                image.Plot(pixel, x, y);
            }
        }
    }
    else
    {
        if (x1 > x2)
        {
            x = x2;
            x2 = x1;
            x1 = x;
            y = y2;
            y2 = y1;
            y1 = y;
        }
        else 
        {
            x = x1;
            y = y1;
        }

        d = 2*dy-dx;
        i1 = 2*dy;
        i2 = 2*(dy - dx);

        image.Plot(pixel, x, y);

        if (y2 < y1)
        {
            while ((++x) <= x2)
            {
                if (d < 0)
                    d += i1;
                else
                {
                    d += i2;
                    --y;
                }
                image.Plot(pixel, x, y);
            }
        }
        else
        {
            while ((++x) <= x2)
            {
                if (d < 0)
                    d += i1;
                else
                {
                    d += i2;
                    y++;
                }
                image.Plot(pixel, x, y);
            }
        }
    }
}

/**
 **********************************************************************
 * Function: BresenhamCircleT
 *
 *   Author: $author$
 *     Date: 5/27/2009
 **********************************************************************
 */
template<class TImage, class TPixel>
void BresenhamCircleT
(TImage &image, TPixel &pixel, int x, int y, int r)
{
    int xi,yi,d;

    if (1 == r)
        image.Plot(pixel,x,y);

    else if (0 < (yi = --r))
    {
        d=3-2*r;

        for (xi=0; xi<yi; xi++)
        {
            image.CirclePlot(pixel,x,y,xi,yi);

            if (d<0) 
                d=d+4*xi+6;
            else
            {
                d=d+4*(xi-yi)+10;
                --yi;
            }
        }

        image.CirclePlot(pixel,x,y,xi,yi);
    }
}

/**
 **********************************************************************
 * Function: BresenhamEllipseT
 *
 *   Author: $author$
 *     Date: 5/27/2009
 **********************************************************************
 */
template<class TImage, class TPixel>
void BresenhamEllipseT
(TImage &image, TPixel &pixel, int cx, int cy, int a, int b)
{
    int x, y, a2, b2, S, T;

    if ((1 == a) && (1 == b))
        image.Plot(pixel,cx,cy);

    else if ((1 == a) && (1 < b))
            image.Fill(pixel,cx,cy-b+1,1,b+b-1);

    else if ((1 < a) && (1 == b))
            image.Fill(pixel,cx-a+1,cy,a+a-1,1);

    else if ((0 < --a) && (0 < --b))
    {
        a2 = a*a;
        b2 = b*b;
        x = 0;
        y = b;
        S = a2*(1-2*b) + 2*b2;
        T = b2 - 2*a2*(2*b-1);

        image.EllipsePlot(pixel, cx, cy, x, y);

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

            image.EllipsePlot(pixel, cx, cy, x, y);
        }
        while (y>0);
    }
}

/**
 **********************************************************************
 *  Class: cBresenhamCircleT
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
template <class TImage, class TPixel, class TExtends>
class cBresenhamCircleT
: public TExtends
{
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cBresenhamCircleT
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamCircleT(TImage &image)
    : cExtends(image)
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
     void CirclePlot(TPixel &pixel, int cx, int cy, int x, int y)
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
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledCircleT
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
template <class TImage, class TPixel, class TExtends>
class cBresenhamFilledCircleT
: public TExtends
{
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledCircleT
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamFilledCircleT(TImage &image)
    : cExtends(image)
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
     void CirclePlot(TPixel &pixel, int cx, int cy, int x, int y)
     {
         Fill(pixel, cx-x, cy-y, x+x+1, 1);
         Fill(pixel, cx-y, cy-x, y+y+1, 1);
         Fill(pixel, cx-y, cy+x, y+y+1, 1);
         Fill(pixel, cx-x, cy+y, x+x+1, 1);
     }
};

/**
 **********************************************************************
 *  Class: cBresenhamEllipseT
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
template <class TImage, class TPixel, class TExtends>
class cBresenhamEllipseT
: public TExtends
{
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cBresenhamEllipseT
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamEllipseT(TImage &image)
    : cExtends(image)
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
     void EllipsePlot(TPixel &pixel, int cx, int cy, int x, int y)
     {
        Plot(pixel, cx + x, cy + y);
        Plot(pixel, cx - x, cy - y);
        Plot(pixel, cx + x, cy - y);
        Plot(pixel, cx - x, cy + y);
     }
};

/**
 **********************************************************************
 *  Class: cBresenhamFilledEllipseT
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
template <class TImage, class TPixel, class TExtends>
class cBresenhamFilledEllipseT
: public TExtends
{
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cBresenhamFilledEllipseT
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cBresenhamFilledEllipseT(TImage &image)
    : cExtends(image)
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
     void EllipsePlot(TPixel &pixel, int cx, int cy, int x, int y)
     {
        Fill(pixel, cx - x, cy + y, x+x+1, 1);
        Fill(pixel, cx - x, cy - y, x+x+1, 1);
     }
};

#endif /* _CBRESENHAM_HXX */
