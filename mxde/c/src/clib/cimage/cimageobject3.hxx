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
 *   File: cimageobject.hxx
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
#if !defined(_CIMAGEOBJECT_HXX) || defined(CIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CIMAGEOBJECT_HXX) && !defined(CIMAGEOBJECT_MEMBERS_ONLY)
#define _CIMAGEOBJECT_HXX
#endif /* !defined(_CIMAGEOBJECT_HXX) && !defined(CIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CIMAGEOBJECT_MEMBERS_ONLY)
#include "cimageobjectinterface.hxx"
#include "cimageobjectitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cImageObjectExtends
 *
 *  Author: $author$
 *    Date: 7/16/2009
 **********************************************************************
 */
typedef cImageObjectItem
cImageObjectExtends;

/**
 **********************************************************************
 *  Class: cImageObject
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageObject
: virtual public cImageImplement,
  virtual public cImageObjectImplement,
  public cImageObjectExtends
{
public:
    typedef cImageObjectImplement cImplements;
    typedef cImageObjectExtends cExtends;

    cImageInterface& m_image;
    tSize m_width, m_height;

    /**
     **********************************************************************
     *  Constructor: cImageObject
     *
     *       Author: $author$
     *         Date: 7/16/2009
     **********************************************************************
     */
    cImageObject
    (cImageInterface& image,
     tSize width=0, tSize height=0)
    : cExtends(*this),
      m_image(image),
      m_width(width),
      m_height(height)
    {
    }
#else /* !defined(CIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetAsImage
     *
     *   Author: $author$
     *     Date: 7/16/2009
     **********************************************************************
     */
    virtual cImageInterface* SetAsImage() 
#if defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) 
        cImageInterface* prevImage = m_image.SetImage(this);
#else /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        cImageInterface* prevImage = 0;
#endif /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEOBJECT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEOBJECT_HXX) || defined(CIMAGEOBJECT_MEMBERS_ONLY) */
