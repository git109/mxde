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
 *   File: cjpegreadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#if !defined(_CJPEGREADEREVENTSINTERFACE_HXX) || defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CJPEGREADEREVENTSINTERFACE_HXX) && !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CJPEGREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CJPEGREADEREVENTSINTERFACE_HXX) && !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cjpeginterfacebase.hxx"
#include "cimagepixelinterface.hxx"
#include "cdelegatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cJPEGReaderEventsInterface;
/**
 **********************************************************************
 * Typedef: cJPEGReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cDelegatedInterfaceT
<cJPEGReaderEventsInterface, 
 cJPEGInterfaceBase>
cJPEGReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cJPEGReaderEventsInterface
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cJPEGReaderEventsInterface
: virtual public cJPEGReaderEventsInterfaceImplement
{
public:
    typedef cJPEGReaderEventsInterfaceImplement cImplements;
#else /* !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cJPEGReaderEvents member functions interface
 */
#define CJPEGREADEREVENTS_MEMBERS_ONLY
#define CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cjpegreaderevents.hxx"
#undef CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CJPEGREADEREVENTS_MEMBERS_ONLY
};

#if !defined(CJPEGREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cJPEGReaderEventsImplement;
/**
 **********************************************************************
 * Typedef: cJPEGReaderEventsImplementImplement
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cDelegatedImplementT
<cJPEGReaderEventsImplement, 
 cJPEGReaderEventsInterface>
cJPEGReaderEventsImplementImplement;
/**
 **********************************************************************
 *  Class: cJPEGReaderEventsImplement
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cJPEGReaderEventsImplement
: virtual public cJPEGReaderEventsImplementImplement
{
public:
    typedef cJPEGReaderEventsImplementImplement cImplements;
#else /* !defined(CJPEGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CJPEGREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/* include cJPEGReaderEvents member functions implement
 */
#define CJPEGREADEREVENTS_MEMBERS_ONLY
#define CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cjpegreaderevents.hxx"
#undef CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CJPEGREADEREVENTS_MEMBERS_ONLY
};
#else /* !defined(CJPEGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGREADEREVENTSINTERFACE_HXX) || defined(CJPEGREADEREVENTSINTERFACE_MEMBERS_ONLY) */
