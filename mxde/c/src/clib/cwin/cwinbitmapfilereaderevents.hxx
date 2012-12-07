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
 *   File: cwinbitmapfilereaderevents.hxx
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEREADEREVENTS_HXX) || defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEREADEREVENTS_HXX) && !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY)
#define _CWINBITMAPFILEREADEREVENTS_HXX
#endif /* !defined(_CWINBITMAPFILEREADEREVENTS_HXX) && !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY)
#include "cwinbitmapfilereadereventsinterface.hxx"
#include "cwinbitmapreaderevents.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapFileReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 12/15/2009
 **********************************************************************
 */
typedef cWinBitmapReaderEvents
cWinBitmapFileReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cWinBitmapFileReaderEvents
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapFileReaderEvents
: virtual public cWinBitmapFileReaderEventsImplement,
  public cWinBitmapFileReaderEventsExtend
{
public:
    typedef cWinBitmapFileReaderEventsImplement cImplements;
    typedef cWinBitmapFileReaderEventsExtend cExtends;
    
    cWinBitmapFileReaderEventsInterface* m_delegated;
    
    /**
     **********************************************************************
     *  Constructor: cWinBitmapFileReaderEvents
     *
     *       Author: $author$
     *         Date: 12/15/2009
     **********************************************************************
     */
    cWinBitmapFileReaderEvents
    (cWinBitmapFileReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_delegated(delegated)
    {
    }
#else /* !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEREADEREVENTS_HXX) || defined(CWINBITMAPFILEREADEREVENTS_MEMBERS_ONLY) */
