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
 *   File: cfilledrectangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/4/2010
 **********************************************************************
 */
#if !defined(_CFILLEDRECTANGLEIMAGEOBJECT_HXX) || defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CFILLEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CFILLEDRECTANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CFILLEDRECTANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "crectangleimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFilledRectangleImageObject
 *
 * Author: $author$
 *   Date: 2/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledRectangleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    cImageObject& m_color;
    
    tSize m_thick;
    eRectangleSide m_side;

    /**
     **********************************************************************
     *  Constructor: cFilledRectangleImageObject
     *
     *       Author: $author$
     *         Date: 2/4/2010
     **********************************************************************
     */
    cFilledRectangleImageObject
    (cImageInterface& image, cImageObject& color,
     tSize width, tSize height, tSize thick=1,
     eRectangleSide side=e_RECTANGLE_SIDE_ALL)
    : cExtends(image, width, height),
      m_color(color),
      m_thick(thick),
      m_side(side)
    {
    }
#else /* !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY)
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
        
        m_image.Fill(x,y, m_width, m_height);
        
        m_image.SelectAsImage(image);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CFILLEDRECTANGLEIMAGEOBJECT_HXX) || defined(CFILLEDRECTANGLEIMAGEOBJECT_MEMBERS_ONLY) */
