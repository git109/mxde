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
 *   File: cgiffilereadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 11/10/2010
 **********************************************************************
 */
#if !defined(_CGIFFILEREADEREVENTSINTERFACE_HXX) || defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CGIFFILEREADEREVENTSINTERFACE_HXX) && !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CGIFFILEREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CGIFFILEREADEREVENTSINTERFACE_HXX) && !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cimagepixelinterface.hxx"
#include "cgiffileinterface.hxx"
#include "cdelegatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cGifFileReaderEventsInterface;
/**
 **********************************************************************
 * Typedef: cGifFileReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 11/10/2010
 **********************************************************************
 */
typedef cDelegatedInterfaceT
<cGifFileReaderEventsInterface>
cGifFileReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cGifFileReaderEventsInterface
 *
 * Author: $author$
 *   Date: 11/10/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifFileReaderEventsInterface
: virtual public cGifFileReaderEventsInterfaceImplement
{
public:
    typedef cGifFileReaderEventsInterfaceImplement cImplements;
#else /* !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cGifFileReaderEvents member functions interface
 */
#define CGIFFILEREADEREVENTS_MEMBERS_ONLY
#define CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cgiffilereaderevents.hxx"
#undef CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CGIFFILEREADEREVENTS_MEMBERS_ONLY
};

#if !defined(CGIFFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cGifFileReaderEventsImplement;
/**
 **********************************************************************
 * Typedef: cGifFileReaderEventsImplementImplement
 *
 *  Author: $author$
 *    Date: 11/10/2010
 **********************************************************************
 */
typedef cDelegatedImplementT
<cGifFileReaderEventsImplement, 
 cGifFileReaderEventsInterface>
cGifFileReaderEventsImplementImplement;
/**
 **********************************************************************
 *  Class: cGifFileReaderEventsImplement
 *
 * Author: $author$
 *   Date: 11/10/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cGifFileReaderEventsImplement
: virtual public cGifFileReaderEventsImplementImplement
{
public:
    typedef cGifFileReaderEventsImplementImplement cImplements;
#else /* !defined(CGIFFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CGIFFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/* include cGifFileReaderEvents member functions implement
 */
#define CGIFFILEREADEREVENTS_MEMBERS_ONLY
#define CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cgiffilereaderevents.hxx"
#undef CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CGIFFILEREADEREVENTS_MEMBERS_ONLY
};
#else /* !defined(CGIFFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILEREADEREVENTSINTERFACE_HXX) || defined(CGIFFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
