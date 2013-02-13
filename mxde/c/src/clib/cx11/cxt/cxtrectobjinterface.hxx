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
 *   File: cxtrectobjinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTRECTOBJINTERFACE_HXX) || defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTRECTOBJINTERFACE_HXX) && !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY)
#define _CXTRECTOBJINTERFACE_HXX
#endif /* !defined(_CXTRECTOBJINTERFACE_HXX) && !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY)
#include "cxtobjectinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtRectObjInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtObjectInterface
cXtRectObjInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtRectObjInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtRectObjInterface
: virtual public cXtRectObjInterfaceImplement
{
public:
    typedef cXtRectObjInterfaceImplement cImplements;
#else /* !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY)
/* include cXtRectObj member functions interface
 */
#define CXTRECTOBJ_MEMBERS_ONLY
#define CXTRECTOBJ_MEMBER_FUNCS_INTERFACE
#include "cxtrectobj.hxx"
#undef CXTRECTOBJ_MEMBER_FUNCS_INTERFACE
#undef CXTRECTOBJ_MEMBERS_ONLY
};

#if !defined(CXTRECTOBJIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtRectObjImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtRectObjImplement
: virtual public cXtRectObjInterface
{
public:
    typedef cXtRectObjInterface cImplements;
#else /* !defined(CXTRECTOBJIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTRECTOBJIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTRECTOBJIMPLEMENT_MEMBERS_ONLY)
/* include cXtRectObj member functions implement
 */
#define CXTRECTOBJ_MEMBERS_ONLY
#define CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT
#include "cxtrectobj.hxx"
#undef CXTRECTOBJ_MEMBER_FUNCS_IMPLEMENT
#undef CXTRECTOBJ_MEMBERS_ONLY
};
#else /* !defined(CXTRECTOBJIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTRECTOBJIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTRECTOBJINTERFACE_HXX) || defined(CXTRECTOBJINTERFACE_MEMBERS_ONLY) */
