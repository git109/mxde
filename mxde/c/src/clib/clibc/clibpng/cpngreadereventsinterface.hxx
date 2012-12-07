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
 *   File: cpngreadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGREADEREVENTSINTERFACE_HXX) || defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGREADEREVENTSINTERFACE_HXX) && !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CPNGREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CPNGREADEREVENTSINTERFACE_HXX) && !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cimagepixelinterface.hxx"
#include "cpnginterface.hxx"
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPNGReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cInterfaceBase
cPNGReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cPNGReaderEventsInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPNGReaderEventsInterface
: virtual public cPNGReaderEventsInterfaceImplement
{
public:
    typedef cPNGReaderEventsInterfaceImplement cImplements;
#else /* !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cPNGReaderEvents member functions interface
 */
#define CPNGREADEREVENTS_MEMBERS_ONLY
#define CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cpngreaderevents.hxx"
#undef CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CPNGREADEREVENTS_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cPNGReaderEventsImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPNGReaderEventsImplement
: virtual public cPNGReaderEventsInterface
{
public:
    typedef cPNGReaderEventsInterface cImplements;
/* include cPNGReaderEvents member functions implement
 */
#define CPNGREADEREVENTS_MEMBERS_ONLY
#define CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cpngreaderevents.hxx"
#undef CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CPNGREADEREVENTS_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGREADEREVENTSINTERFACE_HXX) || defined(CPNGREADEREVENTSINTERFACE_MEMBERS_ONLY) */
