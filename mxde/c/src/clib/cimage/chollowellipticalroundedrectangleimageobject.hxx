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
 *   File: chollowellipticalroundedrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/11/2010
 **********************************************************************
 */
#if !defined(_CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cfilledellipticalroundedrectangleimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cHollowEllipticalRoundedRectangleImageObject
 *
 * Author: $author$
 *   Date: 2/11/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cHollowEllipticalRoundedRectangleImageObject
: public cFilledEllipticalRoundedRectangleImageObject
{
public:
    typedef cFilledEllipticalRoundedRectangleImageObject cExtends;
    /**
     **********************************************************************
     *  Constructor: cHollowEllipticalRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 2/11/2010
     **********************************************************************
     */
    cHollowEllipticalRoundedRectangleImageObject
    (cImageInterface& image, cImageObject& color,
     tSize cornerRadiusWidth, tSize cornerRadiusHeight, 
     tSize width, tSize height, tSize thick=1,
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_NONE,
     bool center=false)
    : cExtends
      (image, color, 
       cornerRadiusWidth, cornerRadiusHeight, 
       width, height, thick, corner, side, center)
    {
    }
#else /* !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
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
        m_image.HollowEllipse
        (x, y, m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_4);
        
        if (e_ROUNDED_RECTANGLE_CORNER_TOP_RIGHT & m_corner)
        m_image.HollowEllipse
        (x+m_width-1, y, 
         m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_1);
        
        if (e_ROUNDED_RECTANGLE_CORNER_BOTTOM_RIGHT & m_corner)
        m_image.HollowEllipse
        (x+m_width-1, y+m_height-1, 
         m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_2);
        
        if (e_ROUNDED_RECTANGLE_CORNER_BOTTOM_LEFT & m_corner)
        m_image.HollowEllipse
        (x, y+m_height-1, 
         m_cornerRadiusWidth, m_cornerRadiusHeight, e_QUADRANT_3);
        
        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CHOLLOWELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
