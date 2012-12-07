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
 *   File: cwinwindowmessage.hxx
 *
 * Author: $author$
 *   Date: 8/11/2010
 **********************************************************************
 */
#if !defined(_CWINWINDOWMESSAGE_HXX) || defined(CWINWINDOWMESSAGE_MEMBERS_ONLY)
#if !defined(_CWINWINDOWMESSAGE_HXX) && !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY)
#define _CWINWINDOWMESSAGE_HXX
#endif /* !defined(_CWINWINDOWMESSAGE_HXX) && !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY) */

#if !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY)
#include "cwinbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinWindowMessageExtend
 *
 *  Author: $author$
 *    Date: 8/11/2010
 **********************************************************************
 */
typedef cWinBase
cWinWindowMessageExtend;
/**
 **********************************************************************
 *  Class: cWinWindowMessage
 *
 * Author: $author$
 *   Date: 8/11/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinWindowMessage
: //virtual public cWinWindowMessageImplement,
  public cWinWindowMessageExtend
{
public:
    //typedef cWinWindowMessageImplement cImplements;
    typedef cWinWindowMessageExtend cExtends;

    HWND m_hWnd;
    UINT m_msg;
    WPARAM m_wParam;
    LPARAM m_lParam;
    
    /**
     **********************************************************************
     *  Constructor: cWinWindowMessage
     *
     *       Author: $author$
     *         Date: 8/11/2010
     **********************************************************************
     */
    cWinWindowMessage
    (HWND hWnd = NULL,
     UINT msg = 0,
     WPARAM wParam = 0,
     LPARAM lParam = 0)
    : m_hWnd(hWnd),
      m_msg(msg),
      m_wParam(wParam),
      m_lParam(lParam)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinWindowMessage
     *
     *      Author: $author$
     *        Date: 8/11/2010
     **********************************************************************
     */
    virtual ~cWinWindowMessage()
    {
    }
#else /* !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY) */

#if !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGE_MEMBERS_ONLY) */

#endif /* !defined(_CWINWINDOWMESSAGE_HXX) || defined(CWINWINDOWMESSAGE_MEMBERS_ONLY) */
