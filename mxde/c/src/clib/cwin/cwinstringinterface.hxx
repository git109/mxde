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
 *   File: cwinstringinterface.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINSTRINGINTERFACE_HXX) || defined(CWINSTRINGINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINSTRINGINTERFACE_HXX) && !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY)
#define _CWINSTRINGINTERFACE_HXX
#endif /* !defined(_CWINSTRINGINTERFACE_HXX) && !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY)
#include "cstringbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinStringInterfaceImplement
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cTCHARStringBaseInterface
cWinStringInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinStringInterface
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinStringInterface
: virtual public cWinStringInterfaceImplement
{
public:
    typedef cWinStringInterfaceImplement cImplements;
#else /* !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY)
/* include cWinString member functions interface
 */
#define CWINSTRING_MEMBERS_ONLY
#define CWINSTRING_MEMBER_FUNCS_INTERFACE
#include "cwinstring.hxx"
#undef CWINSTRING_MEMBER_FUNCS_INTERFACE
#undef CWINSTRING_MEMBERS_ONLY
};

#if !defined(CWINSTRINGIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinStringImplementImplement
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinStringInterface
cWinStringImplementImplement;
/**
 **********************************************************************
 *  Class: cWinStringImplement
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinStringImplement
: virtual public cWinStringImplementImplement
{
public:
    typedef cWinStringImplementImplement cImplements;
#else /* !defined(CWINSTRINGIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINSTRINGIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINSTRINGIMPLEMENT_MEMBERS_ONLY)
/* include cWinString member functions implement
 */
#define CWINSTRING_MEMBERS_ONLY
#define CWINSTRING_MEMBER_FUNCS_IMPLEMENT
#include "cwinstring.hxx"
#undef CWINSTRING_MEMBER_FUNCS_IMPLEMENT
#undef CWINSTRING_MEMBERS_ONLY
};
#else /* !defined(CWINSTRINGIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINSTRINGIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINSTRINGINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINSTRINGINTERFACE_HXX) || defined(CWINSTRINGINTERFACE_MEMBERS_ONLY) */
