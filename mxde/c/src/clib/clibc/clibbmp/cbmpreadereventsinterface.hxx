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
 *   File: cbmpreadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 1/18/2010
 **********************************************************************
 */
#if !defined(_CBMPREADEREVENTSINTERFACE_HXX) || defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CBMPREADEREVENTSINTERFACE_HXX) && !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CBMPREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CBMPREADEREVENTSINTERFACE_HXX) && !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cBMPReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/18/2010
 **********************************************************************
 */
typedef cInterfaceBase
cBMPReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cBMPReaderEventsInterface
 *
 * Author: $author$
 *   Date: 1/18/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cBMPReaderEventsInterface
: virtual public cBMPReaderEventsInterfaceImplement
{
public:
    typedef cBMPReaderEventsInterfaceImplement cImplements;
#else /* !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cBMPReaderEvents member functions interface
 */
#define CBMPREADEREVENTS_MEMBERS_ONLY
#define CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cbmpreaderevents.hxx"
#undef CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CBMPREADEREVENTS_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cBMPReaderEventsImplement
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBMPReaderEventsImplement
: virtual public cBMPReaderEventsInterface
{
public:
    typedef cBMPReaderEventsInterface cImplements;
/* include cBMPReaderEvents member functions implement
 */
#define CBMPREADEREVENTS_MEMBERS_ONLY
#define CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cbmpreaderevents.hxx"
#undef CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CBMPREADEREVENTS_MEMBERS_ONLY
};
    
#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CBMPREADEREVENTSINTERFACE_HXX) || defined(CBMPREADEREVENTSINTERFACE_MEMBERS_ONLY) */
