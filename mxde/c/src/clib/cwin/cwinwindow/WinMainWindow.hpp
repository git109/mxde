///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: WinMainWindow.hpp
//
// Author: $author$
//   Date: 11/28/2011
///////////////////////////////////////////////////////////////////////
#ifndef _WINMAINWINDOW_HPP
#define _WINMAINWINDOW_HPP

#include "cwinroundedframewindowmainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: WinMainWindowExtend
//
//  Author: $author$
//    Date: 11/28/2011
///////////////////////////////////////////////////////////////////////
typedef cWinRoundedFrameWindowMainWindow
WinMainWindowExtend;
///////////////////////////////////////////////////////////////////////
//  Class: WinMainWindow
//
// Author: $author$
//   Date: 11/28/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS WinMainWindow
: public WinMainWindowExtend
{
public:
    typedef WinMainWindowExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMainWindowCreated
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void OnMainWindowCreated() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMainWindowDestroy
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual void OnMainWindowDestroy() 
    {
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMainWindowCreated
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnMainWindowCreated
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error;
        if (!(error = Extends::OnMainWindowCreated
            (windowClass,hInstance,hPrevinst,cmdLine,cmdShow)))
            OnMainWindowCreated();
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMainWindowDestroy
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError OnMainWindowDestroy
    (const cWinWindowClass& windowClass,
     HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow) 
    {
        eError error;
        OnMainWindowDestroy();
        error = Extends::OnMainWindowDestroy
        (windowClass,hInstance,hPrevinst,cmdLine,cmdShow);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: ChangeDefaultWindowSize
    ///
    ///   Author: $author$
    ///     Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError ChangeDefaultWindowSize
    (int& width, int& height) const
    {
        eError error = e_ERROR_NONE;
        width = 480+m_leftMargin+m_rightMargin+m_cornerRadius*2;
        height = 240+m_topMargin+m_bottomMargin+m_cornerRadius*2;
        return error;
    }
};



#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _WINMAINWINDOW_HPP 
