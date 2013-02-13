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
 *   File: cxtcoreinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
#if !defined(_CXTCOREINTERFACE_HXX) || defined(CXTCOREINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTCOREINTERFACE_HXX) && !defined(CXTCOREINTERFACE_MEMBERS_ONLY)
#define _CXTCOREINTERFACE_HXX
#endif /* !defined(_CXTCOREINTERFACE_HXX) && !defined(CXTCOREINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCOREINTERFACE_MEMBERS_ONLY)
#include "cxtwindowobjinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCoreInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/22/2010
 **********************************************************************
 */
typedef cXtWindowObjInterface
cXtCoreInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtCoreInterface
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtCoreInterface
: virtual public cXtCoreInterfaceImplement
{
public:
    typedef cXtCoreInterfaceImplement cImplements;
#else /* !defined(CXTCOREINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCOREINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCOREINTERFACE_MEMBERS_ONLY)
/* include cXtCore member functions interface
 */
#define CXTCORE_MEMBERS_ONLY
#define CXTCORE_MEMBER_FUNCS_INTERFACE
//#include "cxtcore.hxx"
#undef CXTCORE_MEMBER_FUNCS_INTERFACE
#undef CXTCORE_MEMBERS_ONLY
};

#if !defined(CXTCOREIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtCoreImplement
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtCoreImplement
: virtual public cXtCoreInterface
{
public:
    typedef cXObjectImplement cXObjectImplements;
    typedef cXtCoreInterface cImplements;
#else /* !defined(CXTCOREIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTCOREIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTCOREIMPLEMENT_MEMBERS_ONLY)
/* include cXtCore member functions implement
 */
#define CXTCORE_MEMBERS_ONLY
#define CXTCORE_MEMBER_FUNCS_IMPLEMENT
//#include "cxtcore.hxx"
#undef CXTCORE_MEMBER_FUNCS_IMPLEMENT
#undef CXTCORE_MEMBERS_ONLY
};
#else /* !defined(CXTCOREIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTCOREIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCOREINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCOREINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTCOREINTERFACE_HXX) || defined(CXTCOREINTERFACE_MEMBERS_ONLY) */
