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
 *   File: cfilledtriangleimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/5/2010
 **********************************************************************
 */
#if !defined(_CFILLEDTRIANGLEIMAGEOBJECT_HXX) || defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CFILLEDTRIANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CFILLEDTRIANGLEIMAGEOBJECT_HXX
#endif /* !defined(_CFILLEDTRIANGLEIMAGEOBJECT_HXX) && !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFilledTriangleImageObject
 *
 * Author: $author$
 *   Date: 2/5/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledTriangleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    
    cImageObject& m_color;
    tInt m_x1,m_y1, m_x2,m_y2, m_x3,m_y3;
    tSize m_thick;
    
    /**
     **********************************************************************
     *  Constructor: cFilledTriangleImageObject
     *
     *       Author: $author$
     *         Date: 2/5/2010
     **********************************************************************
     */
    cFilledTriangleImageObject
    (cImageInterface& image, cImageObject& color,
     tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3, 
     tSize thick=1)
    : cExtends(image, 0,0),
      m_x1(x1), m_y1(y1),
      m_x2(x2), m_y2(y2),
      m_x3(x3), m_y3(y3),
      m_color(color),
      m_thick(thick)
    {
        tInt min,max;
        
        if ((max = x1) < x2)
        {
            if ((max = x2) < x3)
                max = x3;
        }    
        if ((min = x1) > x2)
        {
            if ((min = x2) > x3)
                min = x3;
        }
        m_width = max-min+1;
        if ((max = y1) < y2)
        {
            if ((max = y2) < y3)
                max = y3;
        }    
        if ((min = y1) > y2)
        {
            if ((min = y2) > y3)
                min = y3;
        }
        m_height = max-min+1;
    }
#else /* !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 2/5/2010
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = m_image.SelectAsImage(&m_color);
        
        m_image.FillTriangle
        (x+m_x1,y+m_y1, x+m_x2,y+m_y2, x+m_x3,y+m_y3);
        
        m_image.SelectAsImage(image);
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CFILLEDTRIANGLEIMAGEOBJECT_HXX) || defined(CFILLEDTRIANGLEIMAGEOBJECT_MEMBERS_ONLY) */

