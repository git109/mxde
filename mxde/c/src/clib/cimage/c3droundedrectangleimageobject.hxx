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
 *   File: c3droundedrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 8/31/2009
 **********************************************************************
 */
#if !defined(_C3DROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_C3DROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _C3DROUNDEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_C3DROUNDEDRECTANGLEIMAGEOBJECT_HXX) && !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "croundedrectangleimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: c3dRoundedRectangleImageObject
 *
 * Author: $author$
 *   Date: 8/31/2009
 **********************************************************************
 */
class c_EXPORT_CLASS c3dRoundedRectangleImageObject
: public cRoundedRectangleImageObject
{
public:
    typedef cRoundedRectangleImageObject cExtends;
    
    cImageObject** m_topColor;
    cImageObject** m_bottomColor;
    tSize m_deep;
    
    /**
     **********************************************************************
     *  Constructor: c3dRoundedRectangleImageObject
     *
     *       Author: $author$
     *         Date: 8/31/2009
     **********************************************************************
     */
    c3dRoundedRectangleImageObject
    (cImageInterface& image,
     cImageObject** topColor,
     cImageObject** bottomColor,
     tSize cornerRadius,
     tSize width, tSize height,
     tSize thick=1, tSize deep=1, 
     eRoundedRectangleCorner corner=e_ROUNDED_RECTANGLE_CORNER_ALL, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends
      (image, **topColor, **bottomColor, 
       cornerRadius, width, height, thick, corner, side),
       
      m_topColor(topColor),
      m_bottomColor(bottomColor),
      m_deep(deep)
    {
    }
#else /* !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 8/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        tSize depth;
        for (depth = 0; depth < m_deep; depth++)
            Plot(x,y, depth);
        return error;
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 8/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y, tSize depth) 
    {
        cImageObject& leftColor              = **((m_topColor)+depth);
        cImageObject& topColor               = **((m_topColor)+depth);
        cImageObject& rightColor             = **((m_bottomColor)+depth);
        cImageObject& bottomColor            = **((m_bottomColor)+depth);
        cImageObject& bottomLeftTopColor     = **((m_topColor)+depth);
        cImageObject& bottomLeftBottomColor  = **((m_bottomColor)+depth);
        cImageObject& topLeftTopColor        = **((m_topColor)+depth);
        cImageObject& topLeftBottomColor     = **((m_topColor)+depth);
        cImageObject& topRightTopColor       = **((m_topColor)+depth);
        cImageObject& topRightBottomColor    = **((m_bottomColor)+depth);
        cImageObject& bottomRightTopColor    = **((m_bottomColor)+depth);
        cImageObject& bottomRightBottomColor = **((m_bottomColor)+depth);
       
        tSize cornerRadius = m_cornerRadius-(m_thick*depth);
        //tSize thick = m_thick+(m_thick*depth);
        
        eError error = e_ERROR_NONE;
        cImageInterface* image = 
            
        leftColor.SelectAsImage();
        m_image.Fill(x-cornerRadius+1, y, 1, m_height-m_thick+1);

        topLeftBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x, y, cornerRadius, e_OCTANT_7);

        topLeftTopColor.SelectAsImage();
        m_image.DrawCircle
        (x, y, cornerRadius, e_OCTANT_8);

        topColor.SelectAsImage();
        m_image.Fill
        (x, y-cornerRadius+1, m_width-m_thick+1, 1);

        topRightTopColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y,
         cornerRadius, e_OCTANT_1);

        topRightBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y,
         cornerRadius, e_OCTANT_2);

        rightColor.SelectAsImage();
        m_image.Fill
        (x+m_width+cornerRadius-m_thick-1, y, 1, m_height-m_thick+1);

        bottomRightTopColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y+m_height-m_thick,
         cornerRadius, e_OCTANT_3);

        bottomRightBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x+m_width-m_thick, y+m_height-m_thick,
         cornerRadius, e_OCTANT_4);

        bottomColor.SelectAsImage();
        m_image.Fill
        (x, y+m_height+cornerRadius-m_thick-1, m_width-m_thick+1, 1);

        bottomLeftBottomColor.SelectAsImage();
        m_image.DrawCircle
        (x, y+m_height-m_thick, 
         cornerRadius, e_OCTANT_5);

        bottomLeftTopColor.SelectAsImage();
        m_image.DrawCircle
        (x, y+m_height-m_thick, 
         cornerRadius, e_OCTANT_6);

        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_C3DROUNDEDRECTANGLEIMAGEOBJECT_HXX) || defined(C3DROUNDEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
