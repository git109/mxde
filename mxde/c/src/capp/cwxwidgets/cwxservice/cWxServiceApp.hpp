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
//   File: cWxServiceApp.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXSERVICEAPP_HPP) || defined(CWXSERVICEAPP_MEMBERS_ONLY)
#if !defined(_CWXSERVICEAPP_HPP) && !defined(CWXSERVICEAPP_MEMBERS_ONLY)
#define _CWXSERVICEAPP_HPP
#endif // !defined(_CWXSERVICEAPP_HPP) && !defined(CWXSERVICEAPP_MEMBERS_ONLY) 

#if !defined(CWXSERVICEAPP_MEMBERS_ONLY)
#include "cWxService.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxServiceAppImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
//typedef cWxServiceImplement
//cWxServiceAppImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxServiceAppExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef cWxService
cWxServiceAppExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxServiceApp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxServiceApp
: //virtual public cWxServiceAppImplement,
  public cWxServiceAppExtend
{
public:
    //typedef cWxServiceAppImplement cImplements;
    typedef cWxServiceAppExtend cExtends;

    ///////////////////////////////////////////////////////////////////////
    // Function: OnRun
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual int OnRun() 
    {
        int result = 0;
        MainArgs(argc, argv, 0);
        return result;
    }
#else // !defined(CWXSERVICEAPP_MEMBERS_ONLY) 
#endif // !defined(CWXSERVICEAPP_MEMBERS_ONLY) 

#if !defined(CWXSERVICEAPP_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXSERVICEAPP_MEMBERS_ONLY) 
#endif // !defined(CWXSERVICEAPP_MEMBERS_ONLY) 

#endif // !defined(_CWXSERVICEAPP_HPP) || defined(CWXSERVICEAPP_MEMBERS_ONLY) 
