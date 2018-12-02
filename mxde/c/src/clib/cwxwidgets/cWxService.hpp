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
//   File: cWxService.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXSERVICE_HPP) || defined(CWXSERVICE_MEMBERS_ONLY)
#if !defined(_CWXSERVICE_HPP) && !defined(CWXSERVICE_MEMBERS_ONLY)
#define _CWXSERVICE_HPP
#endif // !defined(_CWXSERVICE_HPP) && !defined(CWXSERVICE_MEMBERS_ONLY) 

#if !defined(CWXSERVICE_MEMBERS_ONLY)
#include "cWxApp.hpp"
#include "cWxMainArg.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxServiceImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
//typedef wxAppImplement
//cWxServiceImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxServiceExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cWxApp
cWxServiceExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxService
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxService
: //virtual public cWxServiceImplement,
  public cWxServiceExtend
{
public:
    //typedef cWxServiceImplement cImplements;
    typedef cWxServiceExtend cExtends;

    static cWxService* m_theWxService;
    cWxService* m_oldWxService;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxService
    //
    //       Author: $author$
    //         Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxService()
    : m_oldWxService(m_theWxService)
    {
        m_theWxService = this;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWxService
    //
    //      Author: $author$
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxService()
    {
        if (this == (m_theWxService))
            m_theWxService = m_oldWxService;
    }
#else // !defined(CWXSERVICE_MEMBERS_ONLY) 
#endif // !defined(CWXSERVICE_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: InstallService
    //
    //    Author: $author$
    //      Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool InstallService()
#if defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 
    {
        bool success = false;
#if !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
        return success;
    }
#endif // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: UnInstallService
    //
    //    Author: $author$
    //      Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool UnInstallService()
#if defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 
    {
        bool success = false;
#if !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
        return success;
    }
#endif // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: StartService
    //
    //    Author: $author$
    //      Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool StartService()
#if defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 
    {
        bool success = false;
#if !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
        return success;
    }
#endif // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: StopService
    //
    //    Author: $author$
    //      Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool StopService()
#if defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 
    {
        bool success = false;
#if !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXSERVICE_MEMBER_FUNCS_IMPLEMENT) 
        return success;
    }
#endif // defined(CWXSERVICE_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWXSERVICE_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    // Function: OnInit
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool OnInit() 
    {
        wxChar env00=0;
        const wxChar* c_env0=&env00;
        const wxChar** c_env=&c_env0;
        const wxChar** c_argv=(const wxChar**)((wxChar**)(argv));
        bool result = true;
        tInt args;
        if (0 > (args = MainArgs(argc, c_argv, c_env)))
            result = false;
        return result;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnExit
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int OnExit() 
    {
        int result = cExtends::OnExit();
        return result;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: OnRun
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int OnRun() 
    {
        int result = 0;
        return result;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXSERVICE_MEMBERS_ONLY) 
#endif // !defined(CWXSERVICE_MEMBERS_ONLY) 

#endif // !defined(_CWXSERVICE_HPP) || defined(CWXSERVICE_MEMBERS_ONLY) 
