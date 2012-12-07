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
 *   File: cwinsuperclassedwindow.hxx
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
#if !defined(_CWINSUPERCLASSEDWINDOW_HXX) || defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY)
#if !defined(_CWINSUPERCLASSEDWINDOW_HXX) && !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY)
#define _CWINSUPERCLASSEDWINDOW_HXX
#endif /* !defined(_CWINSUPERCLASSEDWINDOW_HXX) && !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY)
#include "cwinwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinSuperClassedWindowExtend
 *
 *  Author: $author$
 *    Date: 1/1/2010
 **********************************************************************
 */
typedef cWinWindow
cWinSuperClassedWindowExtend;
/**
 **********************************************************************
 *  Class: cWinSuperClassedWindow
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinSuperClassedWindow
: public cWinSuperClassedWindowExtend
{
public:
    typedef cWinSuperClassedWindowExtend cExtends;
    
    WNDPROC m_windowSubclassProc;
    
    /**
     **********************************************************************
     *  Constructor: cWinSuperClassedWindow
     *
     *       Author: $author$
     *         Date: 1/1/2010
     **********************************************************************
     */
    cWinSuperClassedWindow
    (WNDPROC windowSubclassProc=NULL,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends(hInstance, attached, isCreated),
      m_windowSubclassProc(windowSubclassProc)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinSuperClassedWindow
     *
     *      Author: $author$
     *        Date: 1/1/2010
     **********************************************************************
     */
    virtual ~cWinSuperClassedWindow()
    {
    }
#else /* !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        WNDPROC windowSubclassProc = 0;
        DWORD wndClassExtra;
        DWORD wndClassIndex;
        
        if (!(windowSubclassProc = m_windowSubclassProc))
        if (sizeof(windowSubclassProc) <= (wndClassExtra = GetClassLong(hWnd, GCL_CBCLSEXTRA)))
        if (0 <= (wndClassIndex = wndClassExtra-sizeof(windowSubclassProc)))
        if ((windowSubclassProc = (WNDPROC)(GetClassLongPtr(hWnd, wndClassIndex))))
            m_windowSubclassProc = windowSubclassProc;
            
        if (windowSubclassProc)
            lResult = CallWindowProc
            (windowSubclassProc, hWnd, msg, wParam, lParam);
        else
        lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINSUPERCLASSEDWINDOW_HXX) || defined(CWINSUPERCLASSEDWINDOW_MEMBERS_ONLY) */
