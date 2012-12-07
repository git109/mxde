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
 *   File: cfilledroundedrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/4/2010
 **********************************************************************
 */
#if !defined(_CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cfilledrectangleimageobject.hxx"
#include "croundedrectangle.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFilledRoundedRectangleImageObject
 *
 * Author: $author$
 *   Date: 2/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledRoundedRectangleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    
    cImageObject& m_color;
    
    tSize m_thick;
    eRectangleSide m_side;

    tSize m_cornerRadius;
    eRoundedRectangleCorner m_corner;
    
    /**
     **********************************************************************
     *  Constructor: cFilledRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 2/4/2010
     **********************************************************************
     */
    cFilledRoundedRectangleImageObject
    (cImageInterface& image, cImageObject& color,
     tSize cornerRadius, tSize width, tSize height, tSize thick=1,
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends(image, width, height),
      m_color(color),
      m_thick(thick),
      m_side(side),
      m_cornerRadius(cornerRadius),
      m_corner(corner)
    {
    }
#else /* !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
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
        
        m_image.FillCircle
        (x, y, m_cornerRadius, e_QUADRANT_4);
        
        m_image.Fill
        (x+1,y-m_cornerRadius+1, 
         m_width-2, m_cornerRadius);
        
        m_image.FillCircle
        (x+m_width-1, y, m_cornerRadius, e_QUADRANT_1);
        
        m_image.Fill
        (x+m_width-1,y+1, 
         m_cornerRadius, m_height-2);
        
        m_image.FillCircle
        (x+m_width-1, y+m_height-1, m_cornerRadius, e_QUADRANT_2);
        
        m_image.Fill
        (x+1,y+m_height-1, 
         m_width-2, m_cornerRadius);
        
        m_image.FillCircle
        (x, y+m_height-1, m_cornerRadius, e_QUADRANT_3);
        
        m_image.Fill
        (x-m_cornerRadius+1,y+1, 
         m_cornerRadius, m_height-2);
        
        m_image.Fill(x+1,y+1, m_width-2, m_height-2);
        
        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CFILLEDROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
