/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: cwinroundedframewindowmainwindow.hxx
 *
 * Author: $author$
 *   Date: 11/26/2011
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEWINDOWMAINWINDOW_HXX) || defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEWINDOWMAINWINDOW_HXX) && !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEWINDOWMAINWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEWINDOWMAINWINDOW_HXX) && !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY)
#include "cwinroundedframemainwindow.hxx"
#include "cwindropfiles.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRoundedFrameWindowMainWindowExtend
 *
 *  Author: $author$
 *    Date: 11/26/2011
 **********************************************************************
 */
typedef cWinRoundedFrameMainWindow
cWinRoundedFrameWindowMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameWindowMainWindow
 *
 * Author: $author$
 *   Date: 11/26/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRoundedFrameWindowMainWindow
: //virtual public cWinRoundedFrameWindowMainWindowImplement,
  public cWinRoundedFrameWindowMainWindowExtend
{
public:
    //typedef cWinRoundedFrameWindowMainWindowImplement cImplements;
    typedef cWinRoundedFrameWindowMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameWindowMainWindow
     *
     *       Author: $author$
     *         Date: 11/26/2011
     **********************************************************************
     */
    cWinRoundedFrameWindowMainWindow
    (COLORREF bgColor=CWINFRAMEWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINROUNDEDFRAMEMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
#else /* !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnMainWindowCreated
     *
     *   Author: $author$
     *     Date: 11/20/2011
     **********************************************************************
     */
    virtual eError OnMainWindowCreated
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error;
        if (!(error = cExtends::OnMainWindowCreated
            (windowClass,hInstance,hPrevinst,cmdLine,cmdShow)))
            DragAcceptFiles(Attached(),TRUE);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFileDropped
     *
     *   Author: $author$
     *     Date: 11/27/2011
     **********************************************************************
     */
    virtual void OnFileDropped(const char* fileName)
    {
    }
    /**
     **********************************************************************
     * Function: On_WM_DROPFILES_WindowMessage
     *
     *   Author: $author$
     *     Date: 11/27/2011
     **********************************************************************
     */
    virtual LRESULT On_WM_DROPFILES_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        const TCHAR* tfileNameChars;
        TLENGTH length;
        HDROP hDrop;
        cWinDropFiles dropFiles;
        
        if ((hDrop = (HDROP)(wParam)))
        if (0 < (length = dropFiles.Open(hDrop)))
        {
            if ((tfileNameChars = dropFiles.GetFirstFileName(length)))
            {
                cString fileName(tfileNameChars);
                const CHAR* fileNameChars;
                if ((fileNameChars = fileName.Chars()))
                    OnFileDropped(fileNameChars);
            }
            dropFiles.Close();
        }
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 11/20/2011
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        PostQuitMessage(0);
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEWINDOWMAINWINDOW_HXX) || defined(CWINROUNDEDFRAMEWINDOWMAINWINDOW_MEMBERS_ONLY) */
