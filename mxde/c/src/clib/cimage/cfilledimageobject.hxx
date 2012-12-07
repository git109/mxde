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
 *   File: cfilledimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/12/2010
 **********************************************************************
 */
#if !defined(_CFILLEDIMAGEOBJECT_HXX) || defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CFILLEDIMAGEOBJECT_HXX) && !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY)
#define _CFILLEDIMAGEOBJECT_HXX
#endif /* !defined(_CFILLEDIMAGEOBJECT_HXX) && !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY)
#include "cimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFilledImageObject
 *
 * Author: $author$
 *   Date: 2/12/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;

    /**
     **********************************************************************
     *  Constructor: cFilledImageObject
     *
     *       Author: $author$
     *         Date: 2/12/2010
     **********************************************************************
     */
    cFilledImageObject
    (cImageInterface& image,
     tSize width=1, tSize height=1)
    : cExtends(image, width, height)
    {
    }
#else /* !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/13/2010
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h) 
    {
        eError error = e_ERROR_NONE;
        m_image.Fill(x,y, w*m_width,h*m_height);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CFILLEDIMAGEOBJECT_HXX) || defined(CFILLEDIMAGEOBJECT_MEMBERS_ONLY) */
