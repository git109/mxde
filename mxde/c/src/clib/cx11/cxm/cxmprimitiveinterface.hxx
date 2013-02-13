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
 *   File: cxmprimitiveinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMPRIMITIVEINTERFACE_HXX) || defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMPRIMITIVEINTERFACE_HXX) && !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY)
#define _CXMPRIMITIVEINTERFACE_HXX
#endif /* !defined(_CXMPRIMITIVEINTERFACE_HXX) && !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_Primitive.h"
#include "cxtwindowobjinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmPrimitiveInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXtWindowObjInterface
cXmPrimitiveInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmPrimitiveInterface
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmPrimitiveInterface
: virtual public cXmPrimitiveInterfaceImplement
{
public:
    typedef cXmPrimitiveInterfaceImplement cImplements;
#else /* !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXMPRIMITIVEIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXmPrimitiveImplement
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmPrimitiveImplement
: virtual public cXmPrimitiveInterface
{
public:
    typedef cXmPrimitiveInterface cImplements;
#else /* !defined(CXMPRIMITIVEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMPRIMITIVEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMPRIMITIVEIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXMPRIMITIVEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMPRIMITIVEIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMPRIMITIVEINTERFACE_HXX) || defined(CXMPRIMITIVEINTERFACE_MEMBERS_ONLY) */
