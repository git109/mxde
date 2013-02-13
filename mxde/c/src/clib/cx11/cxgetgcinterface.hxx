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
 *   File: cxgetgcinterface.hxx
 *
 * Author: $author$           
 *   Date: 5/30/2010
 **********************************************************************
 */
#if !defined(_CXGETGCINTERFACE_HXX) || defined(CXGETGCINTERFACE_MEMBERS_ONLY)
#if !defined(_CXGETGCINTERFACE_HXX) && !defined(CXGETGCINTERFACE_MEMBERS_ONLY)
#define _CXGETGCINTERFACE_HXX
#endif /* !defined(_CXGETGCINTERFACE_HXX) && !defined(CXGETGCINTERFACE_MEMBERS_ONLY) */

#if !defined(CXGETGCINTERFACE_MEMBERS_ONLY)
#include "cxgcinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXGetGCInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 5/30/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXGetGCInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXGetGCInterface
 *
 * Author: $author$           
 *   Date: 5/30/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXGetGCInterface
: virtual public cXGetGCInterfaceImplement
{
public:
    typedef cXGetGCInterfaceImplement cImplements;
#else /* !defined(CXGETGCINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXGETGCINTERFACE_MEMBERS_ONLY) */

#if !defined(CXGETGCINTERFACE_MEMBERS_ONLY)
/* include cXGetGC member functions interface
 */
#define CXGETGC_MEMBERS_ONLY
#define CXGETGC_MEMBER_FUNCS_INTERFACE
#include "cxgetgc.hxx"
#undef CXGETGC_MEMBER_FUNCS_INTERFACE
#undef CXGETGC_MEMBERS_ONLY
};

#if !defined(CXGETGCIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXGetGCImplement
 *
 * Author: $author$           
 *   Date: 5/30/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXGetGCImplement
: virtual public cXGetGCInterface
{
public:
    typedef cXGetGCInterface cImplements;
#else /* !defined(CXGETGCIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXGETGCIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXGETGCIMPLEMENT_MEMBERS_ONLY)
/* include cXGetGC member functions implement
 */
#define CXGETGC_MEMBERS_ONLY
#define CXGETGC_MEMBER_FUNCS_IMPLEMENT
#include "cxgetgc.hxx"
#undef CXGETGC_MEMBER_FUNCS_IMPLEMENT
#undef CXGETGC_MEMBERS_ONLY
};
#else /* !defined(CXGETGCIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXGETGCIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXGETGCINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXGETGCINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXGETGCINTERFACE_HXX) || defined(CXGETGCINTERFACE_MEMBERS_ONLY) */
