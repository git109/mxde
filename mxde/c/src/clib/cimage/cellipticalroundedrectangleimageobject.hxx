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
 *   File: cellipticalroundedrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
#if !defined(_CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "crectangleimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cEllipticalRoundedRectangleImageObject
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cEllipticalRoundedRectangleImageObject
: public cRectangleImageObject
{
public:
    typedef cRectangleImageObject cExtends;

    cImageObject& m_bottomLeftColor;
    cImageObject& m_topLeftColor;
    cImageObject& m_topRightColor;
    cImageObject& m_bottomRightColor;

    tSize m_cornerRadiusWidth;
    tSize m_cornerRadiusHeight;

    /**
     **********************************************************************
     *  Constructor: cEllipticalRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 7/16/2009
     **********************************************************************
     */
    cEllipticalRoundedRectangleImageObject
    (cImageInterface& image,
     cImageObject& bottomLeftColor,
     cImageObject& leftColor,
     cImageObject& topLeftColor,
     cImageObject& topColor,
     cImageObject& topRightColor,
     cImageObject& rightColor,
     cImageObject& bottomRightColor,
     cImageObject& bottomColor,
     tSize cornerRadiusWidth, tSize cornerRadiusHeight,
     tSize width, tSize height, tSize thick=1)
    : cExtends
      (image, leftColor, topColor, rightColor, 
       bottomColor, width, height, thick),

       m_bottomLeftColor(bottomLeftColor),
       m_topLeftColor(topLeftColor),
       m_topRightColor(topRightColor),
       m_bottomRightColor(bottomRightColor),

       m_cornerRadiusWidth(cornerRadiusWidth),
       m_cornerRadiusHeight(cornerRadiusHeight)
    {
    }
#else /* !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = 
            
        m_leftColor.SelectAsImage();
        m_image.Fill(x-m_cornerRadiusWidth+1, y, 1, m_height-m_thick+1);

        m_topLeftColor.SelectAsImage();
        m_image.DrawEllipse
        (x, y, m_cornerRadiusWidth, 
         m_cornerRadiusHeight, e_QUADRANT_TOP_LEFT);

        m_topColor.SelectAsImage();
        m_image.Fill
        (x, y-m_cornerRadiusHeight+1, m_width-m_thick+1, 1);

        m_topRightColor.SelectAsImage();
        m_image.DrawEllipse
        (x+m_width-m_thick, y, m_cornerRadiusWidth, 
         m_cornerRadiusHeight, e_QUADRANT_TOP_RIGHT);

        m_rightColor.SelectAsImage();
        m_image.Fill
        (x+m_width+m_cornerRadiusWidth-m_thick-1, y, 1, m_height-m_thick+1);

        m_bottomRightColor.SelectAsImage();
        m_image.DrawEllipse
        (x+m_width-m_thick, y+m_height-m_thick, m_cornerRadiusWidth,
         m_cornerRadiusHeight, e_QUADRANT_BOTTOM_RIGHT);

        m_bottomColor.SelectAsImage();
        m_image.Fill
        (x, y+m_height+m_cornerRadiusHeight-m_thick-1, m_width-m_thick+1, 1);

        m_bottomLeftColor.SelectAsImage();
        m_image.DrawEllipse
        (x, y+m_height-m_thick, m_cornerRadiusWidth, 
         m_cornerRadiusHeight, e_QUADRANT_BOTTOM_LEFT);

        image->SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(CELLIPTICALROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
