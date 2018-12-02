///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2010 $organization$
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
//   File: cWxWin_SERVICE_STATUS.hpp
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWIN_SERVICE_STATUS_HPP) || defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY)
#if !defined(_CWXWIN_SERVICE_STATUS_HPP) && !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY)
#define _CWXWIN_SERVICE_STATUS_HPP
#endif // !defined(_CWXWIN_SERVICE_STATUS_HPP) && !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY) 

#if !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY)
#include "cplatform_wxwidgets.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxWin_SERVICE_STATUS_Extend
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef SERVICE_STATUS
cWxWin_SERVICE_STATUS_Extend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWin_SERVICE_STATUS
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cWxWin_SERVICE_STATUS
: public cWxWin_SERVICE_STATUS_Extend
{
public:
    typedef cWxWin_SERVICE_STATUS_Extend cExtends;
    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxWin_SERVICE_STATUS
    //
    //       Author: $author$
    //         Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    cWxWin_SERVICE_STATUS()
    {
        dwServiceType = SERVICE_WIN32_OWN_PROCESS;
        dwCurrentState = SERVICE_STOPPED;
        dwControlsAccepted 
        = SERVICE_ACCEPT_STOP 
        | SERVICE_ACCEPT_PAUSE_CONTINUE
        | SERVICE_ACCEPT_SHUTDOWN;
        dwWin32ExitCode = 0;
        dwServiceSpecificExitCode = 0;
        dwCheckPoint = 0;
        dwWaitHint = 0;
    }
#else // !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY) 
#endif // !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY) 

#if !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY) 
#endif // !defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY) 

#endif // !defined(_CWXWIN_SERVICE_STATUS_HPP) || defined(CWXWIN_SERVICE_STATUS_MEMBERS_ONLY) 
