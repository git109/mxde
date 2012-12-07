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
 *   File: cximageobject.hxx
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXIMAGEOBJECT_HXX) || defined(CXIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CXIMAGEOBJECT_HXX) && !defined(CXIMAGEOBJECT_MEMBERS_ONLY)
#define _CXIMAGEOBJECT_HXX
#endif /* !defined(_CXIMAGEOBJECT_HXX) && !defined(CXIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CXIMAGEOBJECT_MEMBERS_ONLY)
#include "cximageinterface.hxx"
#include "cimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXImageObjectExtend
 *
 *  Author: $author$
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cImageObject
cXImageObjectExtend;
/**
 **********************************************************************
 *  Class: cXImageObject
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXImageObject
: /*virtual public cXImageObjectImplement,
  */public cXImageObjectExtend
{
public:
    /*typedef cXImageObjectImplement cImplements;
    */typedef cXImageObjectExtend cExtends;

    cXImageInterface& m_xImage;

    /**
     **********************************************************************
     *  Constructor: cXImageObject
     *
     *       Author: $author$
     *         Date: 6/9/2010
     **********************************************************************
     */
    cXImageObject
    (cXImageInterface& xImage) 
    : cExtends(xImage),
      m_xImage(xImage)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXImageObject
     *
     *      Author: $author$
     *        Date: 6/9/2010
     **********************************************************************
     */
    virtual ~cXImageObject()
    {
    }
#else /* !defined(CXIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CXIMAGEOBJECT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGEOBJECT_HXX) || defined(CXIMAGEOBJECT_MEMBERS_ONLY) */
