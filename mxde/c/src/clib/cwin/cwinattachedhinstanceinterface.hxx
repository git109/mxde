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
 *   File: cwinattachedhinstanceinterface.hxx
 *
 * Author: $author$
 *   Date: 12/13/2009
 **********************************************************************
 */
#if !defined(_CWINATTACHEDHINSTANCEINTERFACE_HXX) || defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINATTACHEDHINSTANCEINTERFACE_HXX) && !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY)
#define _CWINATTACHEDHINSTANCEINTERFACE_HXX
#endif /* !defined(_CWINATTACHEDHINSTANCEINTERFACE_HXX) && !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY)
#include "cwininterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinAttachedHINSTANCEInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/13/2009
 **********************************************************************
 */
typedef cWinInterfaceBase
cWinAttachedHINSTANCEInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinAttachedHINSTANCEInterface
 *
 * Author: $author$
 *   Date: 12/13/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinAttachedHINSTANCEInterface
: virtual public cWinAttachedHINSTANCEInterfaceImplements
{
public:
    typedef cWinAttachedHINSTANCEInterfaceImplements cImplements;
#else /* !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY)
/* include cWinAttachedHINSTANCE member functions interface
 */
#define CWINATTACHEDHINSTANCE_MEMBERS_ONLY
#define CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE
#include "cwinattachedhinstance.hxx"
#undef CWINATTACHEDHINSTANCE_MEMBER_FUNCS_INTERFACE
#undef CWINATTACHEDHINSTANCE_MEMBERS_ONLY
};

/**
 **********************************************************************
 * Typedef: cWinAttachedHINSTANCEImplementImplements
 *
 *  Author: $author$
 *    Date: 12/13/2009
 **********************************************************************
 */
typedef cWinAttachedHINSTANCEInterface
cWinAttachedHINSTANCEImplementImplements;
/**
 **********************************************************************
 *  Class: cWinAttachedHINSTANCEImplement
 *
 * Author: $author$
 *   Date: 12/13/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinAttachedHINSTANCEImplement
: virtual public cWinAttachedHINSTANCEImplementImplements
{
public:
    typedef cWinAttachedHINSTANCEImplementImplements cImplements;
#else /* !defined(CWINATTACHEDHINSTANCEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINATTACHEDHINSTANCEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINATTACHEDHINSTANCEIMPLEMENT_MEMBERS_ONLY)
/* include cWinAttachedHINSTANCE member functions implement
 */
#define CWINATTACHEDHINSTANCE_MEMBERS_ONLY
#define CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT
#include "cwinattachedhinstance.hxx"
#undef CWINATTACHEDHINSTANCE_MEMBER_FUNCS_IMPLEMENT
#undef CWINATTACHEDHINSTANCE_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINATTACHEDHINSTANCEINTERFACE_HXX) || defined(CWINATTACHEDHINSTANCEINTERFACE_MEMBERS_ONLY) */
