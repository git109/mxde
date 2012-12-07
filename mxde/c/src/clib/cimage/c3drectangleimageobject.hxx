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
 *   File: c3drectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
#if !defined(_C3DRECTANGLEIMAGEOBJECT_HXX) || defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_C3DRECTANGLEIMAGEOBJECT_HXX) && !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _C3DRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_C3DRECTANGLEIMAGEOBJECT_HXX) && !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "crectangleimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: c3dRectangleImageObject
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
class c_EXPORT_CLASS c3dRectangleImageObject
: public cRectangleImageObject
{
public:
    typedef cRectangleImageObject cExtends;
    
    cImageObject** m_topColor;
    cImageObject** m_bottomColor;
    tSize m_deep;
    
    /**
     **********************************************************************
     *  Constructor: c3dRectangleImageObject
     *
     *       Author: $author$
     *         Date: 12/31/2009
     **********************************************************************
     */
    c3dRectangleImageObject
    (cImageInterface& image,
     cImageObject** topColor,
     cImageObject** bottomColor,
     tSize width, tSize height,
     tSize thick=1, tSize deep=1, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends
      (image, **topColor, **bottomColor, 
       width, height, thick, side),
       
      m_topColor(topColor),
      m_bottomColor(bottomColor),
      m_deep(deep)
    {
    }
#else /* !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 12/31/2009
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
     *     Date: 12/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y, tSize depth) 
    {
        eError error = e_ERROR_NONE;
        tSize width = m_width-depth-depth;
        tSize height = m_height-depth-depth;
        cImageObject& leftColor              = **((m_topColor)+depth);
        cImageObject& topColor               = **((m_topColor)+depth);
        cImageObject& rightColor             = **((m_bottomColor)+depth);
        cImageObject& bottomColor            = **((m_bottomColor)+depth);
        cImageInterface* image = 
            
        leftColor.SelectAsImage();
        m_image.Fill
        (x+=depth, y+=depth, 1, height-m_thick+1);

        topColor.SelectAsImage();
        m_image.Fill
        (x, y, width-m_thick+1, 1);

        rightColor.SelectAsImage();
        m_image.Fill
        (x+width-m_thick, y, 1, height-m_thick+1);

        bottomColor.SelectAsImage();
        m_image.Fill
        (x, y+height-m_thick, width-m_thick+1, 1);

        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_C3DRECTANGLEIMAGEOBJECT_HXX) || defined(C3DRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
