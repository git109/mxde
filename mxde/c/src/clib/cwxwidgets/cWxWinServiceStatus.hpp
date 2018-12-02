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
//   File: cWxWinServiceStatus.hpp
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWINSERVICESTATUS_HPP) || defined(CWXWINSERVICESTATUS_MEMBERS_ONLY)
#if !defined(_CWXWINSERVICESTATUS_HPP) && !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY)
#define _CWXWINSERVICESTATUS_HPP
#endif // !defined(_CWXWINSERVICESTATUS_HPP) && !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY) 

#if !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY)
#include "cWxWinServiceStatusInterface.hpp"
#include "cWxWin_SERVICE_STATUS.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxWinServiceStatusExtend
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cWxWin_SERVICE_STATUS_Opened
cWxWinServiceStatusExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWinServiceStatus
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cWxWinServiceStatus
: virtual public cWxWinServiceStatusImplement,
  public cWxWinServiceStatusExtend
{
public:
    typedef cWxWinServiceStatusImplement cImplements;
    typedef cWxWinServiceStatusExtend cExtends;

    cWxWin_SERVICE_STATUS m_status;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxWinServiceStatus
    //
    //       Author: $author$
    //         Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    cWxWinServiceStatus
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWxWinServiceStatus
    //
    //      Author: $author$
    //        Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxWinServiceStatus()
    {
        eError error;
        if ((error = Closed()))
            throw(error);
    }
#else // !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Set
    //
    //    Author: $author$
    //      Date: 8/31/2010
    ///////////////////////////////////////////////////////////////////////
    virtual eError Set()
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        tAttachedTo attached;
        if ((attached = Attached()))
        if ((SetServiceStatus(attached, &m_status)))
            error = e_ERROR_NONE;
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    //  Function: Get
    //
    //    Author: $author$
    //      Date: 8/31/2010
    ///////////////////////////////////////////////////////////////////////
    virtual eError Get()
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    // Function: OpenDetached
    //
    //   Author: $author$
    //     Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tAttachedTo OpenDetached
    (eError& error) const 
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
        tAttachedTo attached = (tAttachedTo)(vUnattached);
        error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        return attached;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    // Function: CloseDetached
    //
    //   Author: $author$
    //     Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual eError CloseDetached
    (tAttachedTo detached) const 
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    // Function: SetState
    //
    //   Author: $author$
    //     Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual SERVICE_STATE SetState
    (SERVICE_STATE state) 
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        m_status.dwCurrentState = state;
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        state = 0;
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        return state;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    // Function: State
    //
    //   Author: $author$
    //     Date: 8/29/2010
    ///////////////////////////////////////////////////////////////////////
    virtual SERVICE_STATE State() const 
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
        SERVICE_STATE state = 0;
#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        state = m_status.dwCurrentState;
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
        return state;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 

#if !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    //  Function: SERVICE_STATUS
    //
    //    Author: $author$
    //      Date: 8/31/2010
    ///////////////////////////////////////////////////////////////////////
    virtual operator SERVICE_STATUS&() const
#if defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
    {
        SERVICE_STATUS& status = (SERVICE_STATUS&)(*this);
        return status;
    }
#endif // defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_INTERFACE) 
#else // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CWXWINSERVICESTATUS_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICESTATUS_MEMBERS_ONLY) 

#endif // !defined(_CWXWINSERVICESTATUS_HPP) || defined(CWXWINSERVICESTATUS_MEMBERS_ONLY) 
