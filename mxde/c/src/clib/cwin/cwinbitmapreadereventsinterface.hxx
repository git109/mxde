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
 *   File: cwinbitmapreadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPREADEREVENTSINTERFACE_HXX) || defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINBITMAPREADEREVENTSINTERFACE_HXX) && !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CWINBITMAPREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CWINBITMAPREADEREVENTSINTERFACE_HXX) && !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cwininterfacebase.hxx"
#include "cwinpixelinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapReaderEventsInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/15/2009
 **********************************************************************
 */
typedef cWinInterfaceBase
cWinBitmapReaderEventsInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinBitmapReaderEventsInterface
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinBitmapReaderEventsInterface
: virtual public cWinBitmapReaderEventsInterfaceImplements
{
public:
    typedef cWinBitmapReaderEventsInterfaceImplements cImplements;
#else /* !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cWinBitmapReaderEvents member functions interface
 */
#define CWINBITMAPREADEREVENTS_MEMBERS_ONLY
#define CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cwinbitmapreaderevents.hxx"
#undef CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CWINBITMAPREADEREVENTS_MEMBERS_ONLY
};

#if !defined(CWINBITMAPREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinBitmapReaderEventsImplement
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinBitmapReaderEventsImplement
: virtual public cWinBitmapReaderEventsInterface
{
public:
    typedef cWinBitmapReaderEventsInterface cImplements;
#else /* !defined(CWINBITMAPREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINBITMAPREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/* include cWinBitmapReaderEvents member functions implement
 */
#define CWINBITMAPREADEREVENTS_MEMBERS_ONLY
#define CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cwinbitmapreaderevents.hxx"
#undef CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CWINBITMAPREADEREVENTS_MEMBERS_ONLY
};
#else /* !defined(CWINBITMAPREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPREADEREVENTSINTERFACE_HXX) || defined(CWINBITMAPREADEREVENTSINTERFACE_MEMBERS_ONLY) */
