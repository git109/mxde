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
 *   File: cximage.hxx
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXIMAGE_HXX) || defined(CXIMAGE_MEMBERS_ONLY)
#if !defined(_CXIMAGE_HXX) && !defined(CXIMAGE_MEMBERS_ONLY)
#define _CXIMAGE_HXX
#endif /* !defined(_CXIMAGE_HXX) && !defined(CXIMAGE_MEMBERS_ONLY) */

#if !defined(CXIMAGE_MEMBERS_ONLY)
#include "cximageinterface.hxx"
#include "cimage.hxx"
#include "cxgc.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXImageExtend
 *
 *  Author: $author$
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cImage
cXImageExtend;
/**
 **********************************************************************
 *  Class: cXImage
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXImage
: virtual public cXImageImplement,
  public cXImageExtend
{
public:
    typedef cXImageImplement cImplements;
    typedef cXImageExtend cExtends;

    cXGCInterface& m_gc;

    /**
     **********************************************************************
     *  Constructor: cXImage
     *
     *       Author: $author$
     *         Date: 6/9/2010
     **********************************************************************
     */
    cXImage
    (cXGCInterface& gc,
     cImageInterface* image=0) 
    : cExtends(image),
      m_gc(gc)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXImage
     *
     *      Author: $author$
     *        Date: 6/9/2010
     **********************************************************************
     */
    virtual ~cXImage()
    {
    }
#else /* !defined(CXIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGE_MEMBERS_ONLY) */

#if !defined(CXIMAGE_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: GCInterface
     *
     *    Author: $author$
     *      Date: 6/9/2010
     **********************************************************************
     */
    virtual cXGCInterface& GCInterface() const
#if defined(CXIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
        return (cXGCInterface&)(m_gc);
    }
#endif /* defined(CXIMAGE_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CXIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXIMAGE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXIMAGE_MEMBER_FUNCS_IMPLEMENT)
    /**
     **********************************************************************
     *  Function: DisplayInterface
     *
     *    Author: $author$
     *      Date: 6/9/2010
     **********************************************************************
     */
    virtual cXDisplayInterface& DisplayInterface() const
#if defined(CXIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
        return m_gc.DisplayInterface();
    }
#endif /* defined(CXIMAGE_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CXIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXIMAGE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXIMAGE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGE_HXX) || defined(CXIMAGE_MEMBERS_ONLY) */
