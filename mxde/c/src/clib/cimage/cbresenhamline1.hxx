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
 *   File: cbresenhamline.hxx
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
#if !defined(_CBRESENHAMLINE_HXX) || defined(CBRESENHAMLINE_MEMBERS_ONLY)
#if !defined(_CBRESENHAMLINE_HXX) && !defined(CBRESENHAMLINE_MEMBERS_ONLY)
#define _CBRESENHAMLINE_HXX
#endif /* !defined(_CBRESENHAMLINE_HXX) && !defined(CBRESENHAMLINE_MEMBERS_ONLY) */

#if !defined(CBRESENHAMLINE_MEMBERS_ONLY)
#include "cimagebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Function: BresenhamLineT
 *
 *   Author: $author$
 *     Date: 7/20/2009
 **********************************************************************
 */
template <class TImage, class TPixel, class TInt>

void BresenhamLineT
(TImage &image, TPixel &pixel, TInt x1, TInt y1, TInt x2, TInt y2)
{
    TInt dx,dy,i1,i2,d,x,y;

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

class c_EXPORT_CLASS cBresenhamLine;

#undef CDB_CLASS
#define CDB_CLASS "cBresenhamLineT"
/**
 **********************************************************************
 *  Class: cBresenhamLineT
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
template
<class TDerives=cBresenhamLine,
 class TImageBase=cImageBase,
 class TImageBaseInterface=cImageBaseInterface,
 class TImage=TImageBaseInterface, 
 class TPixel=TImageBaseInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TExtends=TImageBase>

class c_EXPORT_CLASS cBresenhamLineT
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

    /**
     **********************************************************************
     *  Constructor: cBresenhamLineT
     *
     *       Author: $author$
     *         Date: 7/20/2009
     **********************************************************************
     */
    cBresenhamLineT
    (tImageBaseInterface& image)
    : cExtends(image)
    {
    }
#else /* !defined(CBRESENHAMLINE_MEMBERS_ONLY) */
#endif /* !defined(CBRESENHAMLINE_MEMBERS_ONLY) */

#if !defined(CBRESENHAMLINE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cBresenhamLineExtends
 *
 *  Author: $author$
 *    Date: 7/20/2009
 **********************************************************************
 */
typedef cBresenhamLineT<>
cBresenhamLineExtends;
/**
 **********************************************************************
 *  Class: cBresenhamLine
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cBresenhamLine
: public cBresenhamLineExtends
{
public:
    typedef cBresenhamLineExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cBresenhamLine
     *
     *       Author: $author$
     *         Date: 7/20/2009
     **********************************************************************
     */
    cBresenhamLine
    (tImageBaseInterface& image)
    : cExtends(image)
    {
    }
    /**
     **********************************************************************
     * Function: DrawLine
     *
     *   Author: $author$
     *     Date: 7/20/2009
     **********************************************************************
     */
    virtual void DrawLine
    (tPixel &pixel, tInt x1,tInt y1, tInt x2,tInt y2) 
    {
        BresenhamLineT<cExtends, tPixel, tInt>
        (*this, pixel, x1,y1, x2,y2);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBRESENHAMLINE_MEMBERS_ONLY) */
#endif /* !defined(CBRESENHAMLINE_MEMBERS_ONLY) */

#endif /* !defined(_CBRESENHAMLINE_HXX) || defined(CBRESENHAMLINE_MEMBERS_ONLY) */
