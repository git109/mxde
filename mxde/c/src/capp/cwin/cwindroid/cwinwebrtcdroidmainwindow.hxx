/**
 **********************************************************************
 * Copyright (c) 1988-2012 $organization$
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
 *   File: cwinwebrtcdroidmainwindow.hxx
 *
 * Author: $author$
 *   Date: 12/11/2012
 **********************************************************************
 */
#ifndef _CWINWEBRTCDROIDMAINWINDOW_HXX
#define _CWINWEBRTCDROIDMAINWINDOW_HXX

#include "cwindroidmainwindow.hxx"
#include "XosWinWebRtcClientPluginDLibrary.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinWebRtcDroidMainWindowExtend
 *
 *  Author: $author$
 *    Date: 12/11/2012
 **********************************************************************
 */
typedef cWinDroidMainWindow
cWinWebRtcDroidMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinWebRtcDroidMainWindow
 *
 * Author: $author$
 *   Date: 12/11/2012
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWebRtcDroidMainWindow
: public cWinWebRtcDroidMainWindowExtend
{
public:
    typedef cWinWebRtcDroidMainWindowExtend cExtends;

    XosWinWebRtcClientPluginInterface* m_plugin;
    XosWinWebRtcClientPluginDLibrary m_dlibrary;

    /**
     **********************************************************************
     *  Constructor: cWinWebRtcDroidMainWindow
     *
     *       Author: $author$
     *         Date: 12/11/2012
     **********************************************************************
     */
    cWinWebRtcDroidMainWindow()
    : m_plugin(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinWebRtcDroidMainWindow
     *
     *      Author: $author$
     *        Date: 12/11/2012
     **********************************************************************
     */
    virtual ~cWinWebRtcDroidMainWindow()
    {
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: LoadPlugin
    ///
    ///    Author: $author$
    ///      Date: 12/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosWinWebRtcClientPluginInterface* LoadPlugin(XosError& error)
    {
        XosWinWebRtcClientPluginInterface* plugin = 0;
        error = XOS_ERROR_FAILED;
        if (!(error = m_dlibrary.Open()))
            plugin = m_dlibrary.AcquirePlugin(error);
        return plugin;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: UnloadPlugin
    ///
    ///    Author: $author$
    ///      Date: 12/11/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError UnloadPlugin
    (XosWinWebRtcClientPluginInterface* plugin)
    {
        XosError error = XOS_ERROR_FAILED;
        if (!(error = m_dlibrary.ReleasePlugin(plugin)))
            error = m_dlibrary.Close();
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnOpen
    ///
    ///    Author: $author$
    ///      Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnOpen()
    {
        XosError error = XOS_ERROR_NONE;
        if (!(m_plugin))
        if ((m_plugin = LoadPlugin(error)))
            m_plugin->OnWindowAttached(Attached());
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnClose
    ///
    ///    Author: $author$
    ///      Date: 12/10/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnClose()
    {
        if ((m_plugin))
        {
            m_plugin->OnWindowDetached(Attached());
            UnloadPlugin(m_plugin);
            m_plugin = 0;
        }
    }

    /**
     **********************************************************************
     * Function: On_WM_LBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/11/2012
     **********************************************************************
     */
    virtual LRESULT On_WM_LBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_RBUTTONUP_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/11/2012
     **********************************************************************
     */
    virtual LRESULT On_WM_RBUTTONUP_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        OnClose();
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        Destroy();
        return lResult;
    }
    /**
     **********************************************************************
     * Function: On_WM_PAINT_WindowMessage
     *
     *   Author: $author$
     *     Date: 12/11/2012
     **********************************************************************
     */
    virtual LRESULT On_WM_PAINT_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 12/11/2012
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;

        if ((m_plugin))
        if ((m_plugin->OnWindowMessage(hWnd, msg, wParam, lParam)))
            return lResult;

        lResult = cExtends::OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnMainWindowCreated
     *
     *   Author: $author$
     *     Date: 12/11/2012
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
        error = cExtends::OnMainWindowCreated
        (windowClass, hInstance, hPrevinst, cmdLine, cmdShow);
        OnOpen();
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CWINWEBRTCDROIDMAINWINDOW_HXX */
        

