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
//   File: cWxWinServiceStatusInterface.hpp
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXWINSERVICESTATUSINTERFACE_HPP) || defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY)
#if !defined(_CWXWINSERVICESTATUSINTERFACE_HPP) && !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY)
#define _CWXWINSERVICESTATUSINTERFACE_HPP
#endif // !defined(_CWXWINSERVICESTATUSINTERFACE_HPP) && !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY)
#include "cWxWin_SERVICE_STATUS_Opened.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxWinServiceStatusInterfaceImplement
//
//  Author: $author$
//    Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
typedef cWxWin_SERVICE_STATUS_OpenedInterface
cWxWinServiceStatusInterfaceImplement;
///////////////////////////////////////////////////////////////////////
//  Class: cWxWinServiceStatusInterface
//
// Author: $author$
//   Date: 8/29/2010
///////////////////////////////////////////////////////////////////////
class c_INTERFACE_CLASS cWxWinServiceStatusInterface
: virtual public cWxWinServiceStatusInterfaceImplement
{
public:
    typedef cWxWinServiceStatusInterfaceImplement cImplements;
#else // !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY) 

#if !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWXWINSERVICESTATUSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWxWinServiceStatusImplementImplement
 *
 *  Author: $author$
 *    Date: 8/29/2010
 **********************************************************************
 */
typedef cWxWinServiceStatusInterface
cWxWinServiceStatusImplementImplement;
/**
 **********************************************************************
 *  Class: cWxWinServiceStatusImplement
 *
 * Author: $author$
 *   Date: 8/29/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWxWinServiceStatusImplement
: virtual public cWxWinServiceStatusImplementImplement
{
public:
    typedef cWxWinServiceStatusImplementImplement cImplements;
#else /* !defined(CWXWINSERVICESTATUSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWXWINSERVICESTATUSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWXWINSERVICESTATUSIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWXWINSERVICESTATUSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWXWINSERVICESTATUSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY) 
#endif // !defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY) 

#endif // !defined(_CWXWINSERVICESTATUSINTERFACE_HPP) || defined(CWXWINSERVICESTATUSINTERFACE_MEMBERS_ONLY) 
