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
 *   File: cwinbitmapfilereadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEREADEREVENTSINTERFACE_HXX) || defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEREADEREVENTSINTERFACE_HXX) && !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CWINBITMAPFILEREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CWINBITMAPFILEREADEREVENTSINTERFACE_HXX) && !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cwinbitmapreadereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapFileReaderEventsInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/15/2009
 **********************************************************************
 */
typedef cWinBitmapReaderEventsInterface
cWinBitmapFileReaderEventsInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinBitmapFileReaderEventsInterface
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinBitmapFileReaderEventsInterface
: virtual public cWinBitmapFileReaderEventsInterfaceImplements
{
public:
    typedef cWinBitmapFileReaderEventsInterfaceImplements cImplements;
#else /* !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cWinBitmapFileReaderEvents member functions interface
 */
#define CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY
#define CWINBITMAPFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cwinbitmapfilereaderevents.hxx"
#undef CWINBITMAPFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY
};

#if !defined(CWINBITMAPFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinBitmapFileReaderEventsImplement
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinBitmapFileReaderEventsImplement
: virtual public cWinBitmapReaderEventsImplement,
  virtual public cWinBitmapFileReaderEventsInterface
{
public:
    typedef cWinBitmapFileReaderEventsInterface cImplements;
#else /* !defined(CWINBITMAPFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/* include cWinBitmapFileReaderEvents member functions implement
 */
#define CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY
#define CWINBITMAPFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cwinbitmapfilereaderevents.hxx"
#undef CWINBITMAPFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY
};
#else /* !defined(CWINBITMAPFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEREADEREVENTSINTERFACE_HXX) || defined(CWINBITMAPFILEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
