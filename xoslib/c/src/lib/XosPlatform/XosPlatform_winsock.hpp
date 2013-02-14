///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosPlatform_winsock.hpp
///
/// Author: $author$
///   Date: 3/25/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSPLATFORM_WINSOCK_HPP
#define _XOSPLATFORM_WINSOCK_HPP

#include "XosPlatform_build.hpp"

#if defined(WINDOWS) 
// Windows Sockets
// ...
#if defined(WINSOCK_2_API) 
// Use Windows Sockets 2 API 
#include <winsock2.h>
#include <ws2tcpip.h>
#elif defined(WINSOCK_1_API) 
// Use Windows Sockets 1 API 
#include <winsock.h>
#else // defined(WINSOCK_2_API)
// Use Default Windows Sockets API 
// <windows.h>
#endif // defined(WINSOCK_2_API)
// ...
// Windows Sockets
#endif // defined(WINDOWS) 

#endif // _XOSPLATFORM_WINSOCK_HPP 
