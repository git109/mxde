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
 *   File: cwinimagetodibitmapmainwindow.hxx
 *
 * Author: $author$
 *   Date: 11/8/2010
 **********************************************************************
 */
#if !defined(_CWINIMAGETODIBITMAPMAINWINDOW_HXX) || defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGETODIBITMAPMAINWINDOW_HXX) && !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY)
#define _CWINIMAGETODIBITMAPMAINWINDOW_HXX
#endif /* !defined(_CWINIMAGETODIBITMAPMAINWINDOW_HXX) && !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY)
#include "cwinroundedframeimagetodibitmapwindow.hxx"
#include "cwinmainwindow.hxx"
#include "cwincmdline.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinImageToDIBitmapMainWindow;
/**
 **********************************************************************
 * Typedef: cWinImageToDIBitmapMainWindowExtend
 *
 *  Author: $author$
 *    Date: 11/8/2010
 **********************************************************************
 */
typedef cWinMainWindowT
<cWinImageToDIBitmapMainWindow,
 cWinRoundedFrameImageToDIBitmapWindow>
cWinImageToDIBitmapMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinImageToDIBitmapMainWindow
 *
 * Author: $author$
 *   Date: 11/8/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinImageToDIBitmapMainWindow
: //virtual public cWinImageToDIBitmapMainWindowImplement,
  public cWinImageToDIBitmapMainWindowExtend
{
public:
    //typedef cWinImageToDIBitmapMainWindowImplement cImplements;
    typedef cWinImageToDIBitmapMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinImageToDIBitmapMainWindow
     *
     *       Author: $author$
     *         Date: 11/8/2010
     **********************************************************************
     */
    cWinImageToDIBitmapMainWindow
    (COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageToDIBitmapMainWindow
     *
     *      Author: $author$
     *        Date: 11/8/2010
     **********************************************************************
     */
    virtual ~cWinImageToDIBitmapMainWindow()
    {
    }
#else /* !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnMainWindowCreated
     *
     *   Author: $author$
     *     Date: 11/9/2010
     **********************************************************************
     */
    virtual eError OnMainWindowCreated
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error = e_ERROR_NONE;
        const TCHAR* fileNameChars = m_fileNameChars;
        cWinCmdLine cmd(cmdLine);
        cTCHARString fileName;
        const TCHAR* cmdArg;
        TLENGTH cmdArgLength;
        HWND hWnd;
        
        if ((cmdArg = cmd.FirstArg(cmdArgLength)))
        if (0 < (fileName.Assign(cmdArg, cmdArgLength)))
        if ((cmdArg = fileName.HasChars(cmdArgLength)))
            fileNameChars = cmdArg;
            
        if ((hWnd = Attached()))
            DragAcceptFiles(hWnd, TRUE);
            
        if ((fileNameChars))
            Read(fileNameChars);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 11/9/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        Destroy();
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_DESTROY_WindowMessage
     *
     *   Author: $author$
     *     Date: 11/9/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_DESTROY_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        PostQuitMessage(0);
        return lResult;
    }
    
    /**
     **********************************************************************
     * Function: WindowStyle
     *
     *   Author: $author$
     *     Date: 1/8/2010
     **********************************************************************
     */
    virtual DWORD WindowStyle() const 
    {
        DWORD style = WS_POPUP;
        return style;
    }
    /**
     **********************************************************************
     * Function: ChangeDefaultWindowSize
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        HWND hWnd;
        RECT rect;
        
        width = 100;
        height = 100;
        
        if ((hWnd = GetDesktopWindow()))
        if ((GetClientRect(hWnd, &rect)))
        {
            width = (rect.right-rect.left)/4;
            height = (rect.bottom-rect.top)/4;
        }
        return error;
    }
    
    /**
     **********************************************************************
     * Function: GetImageReader
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual tImageReaderInterface* GetImageReader
    (eError& error,
     const CHAR* fileName,
     tImageReaderEventsInterface* delegated=0) 
    {
        tImageReaderInterface* reader = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return reader;
    }
    /**
     **********************************************************************
     * Function: FreeImageReader
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError FreeImageReader
    (tImageReaderInterface& reader) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }     
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGETODIBITMAPMAINWINDOW_HXX) || defined(CWINIMAGETODIBITMAPMAINWINDOW_MEMBERS_ONLY) */
