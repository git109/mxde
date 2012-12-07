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
 *   File: casn1readereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
#if !defined(_CASN1READEREVENTSINTERFACE_HXX) || defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CASN1READEREVENTSINTERFACE_HXX) && !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CASN1READEREVENTSINTERFACE_HXX
#endif /* !defined(_CASN1READEREVENTSINTERFACE_HXX) && !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"
#include "casn1block.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cASN1ReaderEventsInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/21/2010
 **********************************************************************
 */
typedef cInterfaceBase
cASN1ReaderEventsInterfaceImplements;
/**
 **********************************************************************
 *  Class: cASN1ReaderEventsInterface
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cASN1ReaderEventsInterface
: virtual public cASN1ReaderEventsInterfaceImplements
{
public:
    typedef cASN1ReaderEventsInterfaceImplements cImplements;
#else /* !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cASN1ReaderEvents member functions interface
 */
#define CASN1READEREVENTS_MEMBERS_ONLY
#define CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE
#include "casn1readerevents.hxx"
#undef CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CASN1READEREVENTS_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cASN1ReaderEventsImplement
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cASN1ReaderEventsImplement
: virtual public cASN1ReaderEventsInterface
{
public:
    typedef cASN1ReaderEventsInterface cImplements;

/* include cASN1ReaderEvents member functions implement
 */
#define CASN1READEREVENTS_MEMBERS_ONLY
#define CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "casn1readerevents.hxx"
#undef CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CASN1READEREVENTS_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CASN1READEREVENTSINTERFACE_HXX) || defined(CASN1READEREVENTSINTERFACE_MEMBERS_ONLY) */
