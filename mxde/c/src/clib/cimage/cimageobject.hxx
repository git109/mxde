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
 *  Class: cImageObject
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageObject
: virtual public cImageObjectImplement
{
public:
    typedef cImageObjectImplement cImplements;
    
    cImageObjectItem m_item;
    cImageInterface& m_image;
    cImageInterface* m_selectedImage;
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
     tSize width=0, tSize height=0,
     cImageInterface* selectedImage=0)
    : m_item(*this),
      m_image(image),
      m_width(width),
      m_height(height),
      m_selectedImage(selectedImage)
    {
    }
#else /* !defined(CIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SelectAsImage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual cImageInterface* SelectAsImage() 
#if defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) 
        cImageInterface* prevImage = m_image.SelectImage(this);
#else /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        cImageInterface* prevImage = 0;
#endif /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
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

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual cImageInterface* SetImage
    (cImageInterface* image) 
#if defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
        cImageInterface* prevImage = Image();
#if !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT)
        m_selectedImage = image; 
#else /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return prevImage;
    }
#endif /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Image
     *
     *   Author: $author$
     *     Date: 8/7/2009
     **********************************************************************
     */
    virtual cImageInterface* Image() const 
#if defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) 
        cImageInterface* image = m_selectedImage;
#else /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        cImageInterface* image = 0;
#endif /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return image;
    }
#endif /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetSize
     *
     *    Author: $author$
     *      Date: 6/10/2010
     **********************************************************************
     */
    virtual eError SetSize
    (tSize width, tSize height)
#if defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        m_width = width;
        m_height = height;
        error = OnSetSize(width, height);
#else /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnSetSize
     *
     *    Author: $author$
     *      Date: 6/10/2010
     **********************************************************************
     */
    virtual eError OnSetSize
    (tSize width, tSize height)
#if defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
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
