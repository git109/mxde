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
 *   File: cxtwindowobjinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTWINDOWOBJINTERFACE_HXX) || defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTWINDOWOBJINTERFACE_HXX) && !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY)
#define _CXTWINDOWOBJINTERFACE_HXX
#endif /* !defined(_CXTWINDOWOBJINTERFACE_HXX) && !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY)
#include "cxtrectobjinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWindowObjInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtRectObjInterface
cXtWindowObjInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtWindowObjInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWindowObjInterface
: virtual public cXtWindowObjInterfaceImplement
{
public:
    typedef cXtWindowObjInterfaceImplement cImplements;
#else /* !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY)
/* include cXtWindowObj member functions interface
 */
#define CXTWINDOWOBJ_MEMBERS_ONLY
#define CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE
#include "cxtwindowobj.hxx"
#undef CXTWINDOWOBJ_MEMBER_FUNCS_INTERFACE
#undef CXTWINDOWOBJ_MEMBERS_ONLY
};

#if !defined(CXTWINDOWOBJIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtWindowObjImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWindowObjImplement
: virtual public cXtWindowObjInterface
{
public:
    typedef cXtWindowObjInterface cImplements;
#else /* !defined(CXTWINDOWOBJIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWINDOWOBJIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTWINDOWOBJIMPLEMENT_MEMBERS_ONLY)
/* include cXtWindowObj member functions implement
 */
#define CXTWINDOWOBJ_MEMBERS_ONLY
#define CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT
#include "cxtwindowobj.hxx"
#undef CXTWINDOWOBJ_MEMBER_FUNCS_IMPLEMENT
#undef CXTWINDOWOBJ_MEMBERS_ONLY
};
#else /* !defined(CXTWINDOWOBJIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWINDOWOBJIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTWINDOWOBJINTERFACE_HXX) || defined(CXTWINDOWOBJINTERFACE_MEMBERS_ONLY) */
