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
//   File: cWxService.cpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#include "cWxService.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
//  Class: cWxService
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
cWxService* cWxService::m_theWxService = 0;

///////////////////////////////////////////////////////////////////////
//  Class: cWxInstallServiceMainArg
//
// Author: John Boyd
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxInstallServiceMainArg
: public cWxMainArg
{
public:
    typedef cWxMainArg cExtends;
    typedef cWxInstallServiceMainArg cDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxInstallServiceMainArg
    //
    //      Author: John Boyd
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxInstallServiceMainArg
    (const wxChar* shortName=wxT("i"),
     const wxChar* name=wxT("install"),
     const wxChar* description=wxT("install service"),
     const wxChar* parameters=wxT("")) 
    : cExtends(shortName, name, description, parameters)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: John Boyd
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args,
     int argn,
     const wxChar* arg,
     int argc,
     const wxChar** argv,
     const wxChar** env) const
    {
        int argon = argn;
        cWxService* theWxService;
        if (theWxService = (cWxService::m_theWxService))
        if (!(theWxService->InstallService()))
            argon = -1;
        return argon;
    }
} g_cWxInstallServiceMainArg;
///////////////////////////////////////////////////////////////////////
//  Class: cWxUnInstallServiceMainArg
//
// Author: John Boyd
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxUnInstallServiceMainArg
: public cWxMainArg
{
public:
    typedef cWxMainArg cExtends;
    typedef cWxUnInstallServiceMainArg cDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxUnInstallServiceMainArg
    //
    //      Author: John Boyd
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxUnInstallServiceMainArg
    (const wxChar* shortName=wxT("u"),
     const wxChar* name=wxT("uninstall"),
     const wxChar* description=wxT("uninstall service"),
     const wxChar* parameters=wxT("")) 
    : cExtends(shortName, name, description, parameters)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: John Boyd
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args,
     int argn,
     const wxChar* arg,
     int argc,
     const wxChar** argv,
     const wxChar** env) const
    {
        int argon = argn;
        cWxService* theWxService;
        if (theWxService = (cWxService::m_theWxService))
        if (!(theWxService->UnInstallService()))
            argon = -1;
        return argon;
    }
} g_cWxUnInstallServiceMainArg;
///////////////////////////////////////////////////////////////////////
//  Class: cWxStartServiceMainArg
//
// Author: John Boyd
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxStartServiceMainArg
: public cWxMainArg
{
public:
    typedef cWxMainArg cExtends;
    typedef cWxStartServiceMainArg cDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxStartServiceMainArg
    //
    //      Author: John Boyd
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxStartServiceMainArg
    (const wxChar* shortName=wxT("s"),
     const wxChar* name=wxT("start"),
     const wxChar* description=wxT("start service"),
     const wxChar* parameters=wxT("")) 
    : cExtends(shortName, name, description, parameters)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: John Boyd
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args,
     int argn,
     const wxChar* arg,
     int argc,
     const wxChar** argv,
     const wxChar** env) const
    {
        int argon = argn;
        cWxService* theWxService;
        if (theWxService = (cWxService::m_theWxService))
        if (!(theWxService->StartService()))
            argon = -1;
        return argon;
    }
} g_cWxStartServiceMainArg;
///////////////////////////////////////////////////////////////////////
//  Class: cWxStopServiceMainArg
//
// Author: John Boyd
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxStopServiceMainArg
: public cWxMainArg
{
public:
    typedef cWxMainArg cExtends;
    typedef cWxStopServiceMainArg cDerives;
    ///////////////////////////////////////////////////////////////////////
    // Constructor: cWxStopServiceMainArg
    //
    //      Author: John Boyd
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxStopServiceMainArg
    (const wxChar* shortName=wxT("t"),
     const wxChar* name=wxT("stop"),
     const wxChar* description=wxT("stop service"),
     const wxChar* parameters=wxT("")) 
    : cExtends(shortName, name, description, parameters)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: John Boyd
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args,
     int argn,
     const wxChar* arg,
     int argc,
     const wxChar** argv,
     const wxChar** env) const
    {
        int argon = argn;
        cWxService* theWxService;
        if (theWxService = (cWxService::m_theWxService))
        if (!(theWxService->StopService()))
            argon = -1;
        return argon;
    }
} g_cWxStopServiceMainArg;

#if defined(CWXSERVICE_INSTANCE_TEST)
cWxService g_cWxService;
#endif // defined(CWXSERVICE_INSTANCE_TEST) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
