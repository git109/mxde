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
 *   File: cxtobjectinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTOBJECTINTERFACE_HXX) || defined(CXTOBJECTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTOBJECTINTERFACE_HXX) && !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY)
#define _CXTOBJECTINTERFACE_HXX
#endif /* !defined(_CXTOBJECTINTERFACE_HXX) && !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY)
#include "cxtwidgetinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtObjectInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtWidgetInterface
cXtObjectInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtObjectInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtObjectInterface
: virtual public cXtObjectInterfaceImplement
{
public:
    typedef cXtObjectInterfaceImplement cImplements;
#else /* !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY)
/* include cXtObject member functions interface
 */
#define CXTOBJECT_MEMBERS_ONLY
#define CXTOBJECT_MEMBER_FUNCS_INTERFACE
//#include "cxtobject.hxx"
#undef CXTOBJECT_MEMBER_FUNCS_INTERFACE
#undef CXTOBJECT_MEMBERS_ONLY
};

#if !defined(CXTOBJECTIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtObjectImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtObjectImplement
: virtual public cXtObjectInterface
{
public:
    typedef cXtObjectInterface cImplements;
#else /* !defined(CXTOBJECTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTOBJECTIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTOBJECTIMPLEMENT_MEMBERS_ONLY)
/* include cXtObject member functions implement
 */
#define CXTOBJECT_MEMBERS_ONLY
#define CXTOBJECT_MEMBER_FUNCS_IMPLEMENT
//#include "cxtobject.hxx"
#undef CXTOBJECT_MEMBER_FUNCS_IMPLEMENT
#undef CXTOBJECT_MEMBERS_ONLY
};
#else /* !defined(CXTOBJECTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTOBJECTIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTOBJECTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTOBJECTINTERFACE_HXX) || defined(CXTOBJECTINTERFACE_MEMBERS_ONLY) */
