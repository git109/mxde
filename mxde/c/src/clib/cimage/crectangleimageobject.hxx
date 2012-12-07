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
 *   File: crectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
#if !defined(_CRECTANGLEIMAGEOBJECT_HXX) || defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CRECTANGLEIMAGEOBJECT_HXX) && !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CRECTANGLEIMAGEOBJECT_HXX) && !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cimageobject.hxx"
#include "crectangle.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cRectangleImageObject
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cRectangleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;

    cImageObject& m_leftColor;
    cImageObject& m_topColor;
    cImageObject& m_rightColor;
    cImageObject& m_bottomColor;
    tSize m_thick;
    eRectangleSide m_side;

    /**
     **********************************************************************
     *  Constructor: cRectangleImageObject
     *
     *       Author: $author$
     *         Date: 8/30/2009
     **********************************************************************
     */
    cRectangleImageObject
    (cImageInterface& image,
     cImageObject& color,
     tSize width, tSize height, tSize thick=1, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends(image, width, height),
      m_leftColor(color),
      m_topColor(color),
      m_rightColor(color),
      m_bottomColor(color),
      m_thick(thick),
      m_side(side)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cRectangleImageObject
     *
     *       Author: $author$
     *         Date: 8/30/2009
     **********************************************************************
     */
    cRectangleImageObject
    (cImageInterface& image,
     cImageObject& topColor,
     cImageObject& bottomColor,
     tSize width, tSize height, tSize thick=1, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends(image, width, height),
      m_leftColor(topColor),
      m_topColor(topColor),
      m_rightColor(bottomColor),
      m_bottomColor(bottomColor),
      m_thick(thick),
      m_side(side)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cRectangleImageObject
     *
     *       Author: $author$
     *         Date: 7/16/2009
     **********************************************************************
     */
    cRectangleImageObject
    (cImageInterface& image,
     cImageObject& leftColor,
     cImageObject& topColor,
     cImageObject& rightColor,
     cImageObject& bottomColor,
     tSize width, tSize height, tSize thick=1, 
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends(image, width, height),
      m_leftColor(leftColor),
      m_topColor(topColor),
      m_rightColor(rightColor),
      m_bottomColor(bottomColor),
      m_thick(thick),
      m_side(side)
    {
    }
#else /* !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 7/16/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = m_topColor.SelectAsImage();

        m_image.Fill(x, y, m_width-m_thick+1, 1);

        m_rightColor.SelectAsImage();
        m_image.Fill(x+m_width-m_thick, y, 1, m_height-m_thick+1);

        m_bottomColor.SelectAsImage();
        m_image.Fill(x, y+m_height-m_thick, m_width-m_thick+1, 1);

        m_leftColor.SelectAsImage();
        m_image.Fill(x, y, 1, m_height-m_thick+1);

        if (image)
            image->SelectAsImage();
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CRECTANGLEIMAGEOBJECT_HXX) || defined(CRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
