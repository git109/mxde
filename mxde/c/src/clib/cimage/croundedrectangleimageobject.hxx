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
 *   File: croundedrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 8/30/2009
 **********************************************************************
 */
#if !defined(_CROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CROUNDEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "crectangleimageobject.hxx"
#include "croundedrectangle.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cRoundedRectangleImageObject
 *
 * Author: $author$
 *   Date: 8/30/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cRoundedRectangleImageObject
: public cRectangleImageObject
{
public:
    typedef cRectangleImageObject cExtends;
    
    cImageObject& m_bottomLeftTopColor;
    cImageObject& m_bottomLeftBottomColor;
    cImageObject& m_topLeftTopColor;
    cImageObject& m_topLeftBottomColor;
    cImageObject& m_topRightTopColor;
    cImageObject& m_topRightBottomColor;
    cImageObject& m_bottomRightTopColor;
    cImageObject& m_bottomRightBottomColor;

    tSize m_cornerRadius;
    eRoundedRectangleCorner m_corner;
    
    /**
     **********************************************************************
     *  Constructor: cRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 8/30/2009
     **********************************************************************
     */
    cRoundedRectangleImageObject
    (cImageInterface& image,
     cImageObject& color,
     tSize cornerRadius,
     tSize width, tSize height, tSize thick=1,
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends
      (image, color, 
       width, height, thick, side),

       m_bottomLeftTopColor(color),
       m_bottomLeftBottomColor(color),
       m_topLeftTopColor(color),
       m_topLeftBottomColor(color),
       m_topRightTopColor(color),
       m_topRightBottomColor(color),
       m_bottomRightTopColor(color),
       m_bottomRightBottomColor(color),

       m_cornerRadius(cornerRadius),
       m_corner(corner)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 8/30/2009
     **********************************************************************
     */
    cRoundedRectangleImageObject
    (cImageInterface& image,
     cImageObject& topColor,
     cImageObject& bottomColor,
     tSize cornerRadius,
     tSize width, tSize height, tSize thick=1, 
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends
      (image, topColor, bottomColor, 
       width, height, thick, side),

       m_bottomLeftTopColor(topColor),
       m_bottomLeftBottomColor(bottomColor),
       m_topLeftTopColor(topColor),
       m_topLeftBottomColor(topColor),
       m_topRightTopColor(topColor),
       m_topRightBottomColor(bottomColor),
       m_bottomRightTopColor(bottomColor),
       m_bottomRightBottomColor(bottomColor),

       m_cornerRadius(cornerRadius),
       m_corner(corner)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 8/30/2009
     **********************************************************************
     */
    cRoundedRectangleImageObject
    (cImageInterface& image,
     cImageObject& bottomLeftTopColor,
     cImageObject& bottomLeftBottomColor,
     cImageObject& leftColor,
     cImageObject& topLeftTopColor,
     cImageObject& topLeftBottomColor,
     cImageObject& topColor,
     cImageObject& topRightTopColor,
     cImageObject& topRightBottomColor,
     cImageObject& rightColor,
     cImageObject& bottomRightTopColor,
     cImageObject& bottomRightBottomColor,
     cImageObject& bottomColor,
     tSize cornerRadius,
     tSize width, tSize height, tSize thick=1, 
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends
      (image, leftColor, topColor, rightColor, 
       bottomColor, width, height, thick, side),

       m_bottomLeftTopColor(bottomLeftTopColor),
       m_bottomLeftBottomColor(bottomLeftBottomColor),
       m_topLeftTopColor(topLeftTopColor),
       m_topLeftBottomColor(topLeftBottomColor),
       m_topRightTopColor(topRightTopColor),
       m_topRightBottomColor(topRightBottomColor),
       m_bottomRightTopColor(bottomRightTopColor),
       m_bottomRightBottomColor(bottomRightBottomColor),

       m_cornerRadius(cornerRadius),
       m_corner(corner)
    {
    }
#else /* !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 8/30/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = 
            
        m_leftColor.SelectAsImage();
        m_image.Fill(x-m_cornerRadius+1, y, 1, m_height-m_thick+1);

        m_topLeftBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x, y, m_cornerRadius, e_OCTANT_7);

        m_topLeftTopColor.SelectAsImage();
        m_image.DrawCircle
        (x, y, m_cornerRadius, e_OCTANT_8);

        m_topColor.SelectAsImage();
        m_image.Fill
        (x, y-m_cornerRadius+1, m_width-m_thick+1, 1);

        m_topRightTopColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y,
         m_cornerRadius, e_OCTANT_1);

        m_topRightBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y,
         m_cornerRadius, e_OCTANT_2);

        m_rightColor.SelectAsImage();
        m_image.Fill
        (x+m_width+m_cornerRadius-m_thick-1, y, 1, m_height-m_thick+1);

        m_bottomRightTopColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y+m_height-m_thick,
         m_cornerRadius, e_OCTANT_3);

        m_bottomRightBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y+m_height-m_thick,
         m_cornerRadius, e_OCTANT_4);

        m_bottomColor.SelectAsImage();
        m_image.Fill
        (x, y+m_height+m_cornerRadius-m_thick-1, m_width-m_thick+1, 1);

        m_bottomLeftBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x, y+m_height-m_thick, 
         m_cornerRadius, e_OCTANT_5);

        m_bottomLeftTopColor.SelectAsImage();
        m_image.DrawCircle
        (x, y+m_height-m_thick, 
         m_cornerRadius, e_OCTANT_6);

        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
