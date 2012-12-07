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
 *   File: cwinbitmapfilereaderinterface.hxx
 *
 * Author: $author$
 *   Date: 12/17/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEREADERINTERFACE_HXX) || defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEREADERINTERFACE_HXX) && !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY)
#define _CWINBITMAPFILEREADERINTERFACE_HXX
#endif /* !defined(_CWINBITMAPFILEREADERINTERFACE_HXX) && !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY)
#include "cwinbitmapfilereadereventsinterface.hxx"
#include "creaderinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapFileReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/17/2009
 **********************************************************************
 */
typedef cWinBitmapFileReaderEventsInterface
cWinBitmapFileReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinBitmapFileReaderInterface
 *
 * Author: $author$
 *   Date: 12/17/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinBitmapFileReaderInterface
: virtual public cWinBitmapFileReaderInterfaceImplements
{
public:
    typedef cWinBitmapFileReaderInterfaceImplements cImplements;
#else /* !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY)
/* include cWinBitmapFileReader member functions interface
 */
#define CWINBITMAPFILEREADER_MEMBERS_ONLY
#define CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE
#include "cwinbitmapfilereader.hxx"
#undef CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE
#undef CWINBITMAPFILEREADER_MEMBERS_ONLY
};

#if !defined(CWINBITMAPFILEREADERIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinBitmapFileReaderImplement
 *
 * Author: $author$
 *   Date: 12/17/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinBitmapFileReaderImplement
: virtual public cWinBitmapFileReaderEventsImplement,
  virtual public cWinBitmapFileReaderInterface
{
public:
    typedef cWinBitmapFileReaderInterface cImplements;
#else /* !defined(CWINBITMAPFILEREADERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADERIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADERIMPLEMENT_MEMBERS_ONLY)
/* include cWinBitmapFileReader member functions implement
 */
#define CWINBITMAPFILEREADER_MEMBERS_ONLY
#define CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT
#include "cwinbitmapfilereader.hxx"
#undef CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT
#undef CWINBITMAPFILEREADER_MEMBERS_ONLY
};
#else /* !defined(CWINBITMAPFILEREADERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADERIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEREADERINTERFACE_HXX) || defined(CWINBITMAPFILEREADERINTERFACE_MEMBERS_ONLY) */
