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
 *   File: cfilledellipticalroundedrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/8/2010
 **********************************************************************
 */
#if !defined(_CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cfilledrectangleimageobject.hxx"
#include "croundedrectangle.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFilledEllipticalRoundedRectangleImageObject
 *
 * Author: $author$
 *   Date: 2/8/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledEllipticalRoundedRectangleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    
    cImageObject& m_color;
    
    tSize m_thick;
    eRectangleSide m_side;

    tSize m_cornerRadiusWidth;
    tSize m_cornerRadiusHeight;
    eRoundedRectangleCorner m_corner;
    bool m_center;
    
    /**
     **********************************************************************
     *  Constructor: cFilledEllipticalRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 2/8/2010
     **********************************************************************
     */
    cFilledEllipticalRoundedRectangleImageObject
    (cImageInterface& image, cImageObject& color,
     tSize cornerRadiusWidth, tSize cornerRadiusHeight, 
     tSize width, tSize height, tSize thick=1,
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL,
     bool center=true)
    : cExtends(image, width, height),
      m_color(color),
      m_thick(thick),
      m_side(side),
      m_cornerRadiusWidth(cornerRadiusWidth),
      m_cornerRadiusHeight(cornerRadiusHeight),
      m_corner(corner),
      m_center(center)
    {
    }
#else /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 2/4/2010
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = m_image.SelectAsImage(&m_color);
        
        if (e_ROUNDED_RECTANGLE_CORNER_TOP_LEFT & m_corner)
        m_image.FillEllipse
        (x, y, m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_4);
        
        if (e_RECTANGLE_SIDE_TOP & m_side)
        m_image.Fill
        (x+1,y-m_cornerRadiusHeight+1, 
         m_width-2, m_cornerRadiusHeight);
        
        if (e_ROUNDED_RECTANGLE_CORNER_TOP_RIGHT & m_corner)
        m_image.FillEllipse
        (x+m_width-1, y, 
         m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_1);
        
        if (e_RECTANGLE_SIDE_RIGHT & m_side)
        m_image.Fill
        (x+m_width-1,y+1, 
         m_cornerRadiusWidth, m_height-2);
        
        if (e_ROUNDED_RECTANGLE_CORNER_BOTTOM_RIGHT & m_corner)
        m_image.FillEllipse
        (x+m_width-1, y+m_height-1, 
         m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_2);
        
        if (e_RECTANGLE_SIDE_BOTTOM & m_side)
        m_image.Fill
        (x+1,y+m_height-1, 
         m_width-2, m_cornerRadiusHeight);
        
        if (e_ROUNDED_RECTANGLE_CORNER_BOTTOM_LEFT & m_corner)
        m_image.FillEllipse
        (x, y+m_height-1, 
         m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_3);
        
        if (e_RECTANGLE_SIDE_LEFT & m_side)
        m_image.Fill
        (x-m_cornerRadiusWidth+1,y+1, 
         m_cornerRadiusWidth, m_height-2);
        
        if (m_center)
        m_image.Fill(x+1,y+1, m_width-2, m_height-2);
        
        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CFILLEDELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
