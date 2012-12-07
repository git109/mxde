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
 *   File: cplatform_socket.h
 *
 * Author: $author$
 *   Date: 3/1/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_SOCKET_H
#define _CPLATFORM_SOCKET_H

#include "cplatform_build.h"

#if defined(WINDOWS) 
/* Windows
 */

#if defined(WINDOWS_WCE)
#if !defined(WINSOCK_2) && !defined(WINSOCK_1)
#define WINSOCK_1
#endif /* !defined(WINSOCK_2) && !defined(WINSOCK_1) */
#else /* defined(WINDOWS_WCE) */
#if !defined(WINSOCK_2) && !defined(WINSOCK_1)
#define WINSOCK_2
#endif /* !defined(WINSOCK_2) && !defined(WINSOCK_1) */
#endif /* defined(WINDOWS_WCE) */

#if defined(WINSOCK_2) 
/* Use Windows Sockets 2 API 
 */
#include <winsock2.h>
#include <ws2tcpip.h>
#elif defined(WINSOCK_1) 
/* Use Windows Sockets 1 API 
 */
#include <winsock.h>
#else /* defined(WINSOCK_2) */
/* Use Default Windows Sockets API 
 * <windows.h>
 */
#endif /* defined(WINSOCK_2) */
#else /* defined(WINDOWS) */
/* Unix
 */
#endif /* defined(WINDOWS) */

#include "cplatform.h"

#if defined(WINDOWS) 
/* Windows
 * ...
 */
#if defined(_WINSOCK2API_) 
/* Windows Sockets 2 API
 * <winsock2.h>
 */
#define WINDOWS_SOCKETS_2_API
/* WinSock 1 Other NT-specific options.
 */
#define SO_UPDATE_ACCEPT_CONTEXT 0x700B

typedef addrinfo ADDRINFO;
#else /* defined(_WINSOCK2API_) */
/* Windows Sockets 1 API (_WINSOCKAPI_)
 * <winsock.h>
 */
#define WINDOWS_SOCKETS_1_API
/* WinSock 2 extension -- manifest constants for shutdown()
 */
#define SD_RECEIVE 0x00
#define SD_SEND    0x01
#define SD_BOTH    0x02

typedef int socklen_t;
typedef struct addrinfo {
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  size_t ai_addrlen;
  TCHAR* ai_canonname;  
  struct sockaddr* ai_addr;  
  struct addrinfo* ai_next;
} addrinfo, ADDRINFO;
#endif /* defined(_WINSOCK2API_) */

typedef SOCKET INVALID_SOCKET_T;
typedef int SOCKET_SIZE_T;
typedef int SOCKET_SSIZE_T;
typedef DWORD SOCKET_NAME_SIZE_T;
typedef char SOCKET_ADDR_VALUE;
typedef char SOCKET_DATA_VALUE;

#define GET_SOCKET_ERROR(err) WSAGetLastError()
#define IN_SOCKET_NODELAY_ON(on) !on
#define OUT_SOCKET_NODELAY_ON(on) !on

#if !defined(SO_UPDATE_ACCEPT_CONTEXT) 
#define SO_UPDATE_ACCEPT_CONTEXT 0x700B
#endif // !defined(SO_UPDATE_ACCEPT_CONTEXT)

#define IN_ADDR_GET_ADDRESS(in_addr) \
    (&in_addr.S_un.S_addr)

#define IN_ADDR_SET_INADDR_ANY(in_addr) \
    ((in_addr).S_un.S_addr = INADDR_ANY)

#define IN_ADDR_SET_ADDRESS(in_addr, addr) \
    ((in_addr).S_un.S_addr = (addr))
/* ...
 * Windows
 */
#else /* defined(WINDOWS) */
/* Unix
 * ...
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SD_RECEIVE SHUT_RD
#define SD_SEND SHUT_WR
#define SD_BOTH SHUT_RDWR
#define INVALID_SOCKET -1

typedef int SOCKET;
typedef SOCKET INVALID_SOCKET_T;
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct hostent HOSTENT;
typedef struct addrinfo ADDRINFO;

typedef size_t SOCKET_SIZE_T;
typedef ssize_t SOCKET_SSIZE_T;
typedef size_t SOCKET_NAME_SIZE_T;
typedef void SOCKET_ADDR_VALUE;
typedef void SOCKET_DATA_VALUE;

#define GET_SOCKET_ERROR(err) err
#define IN_SOCKET_NODELAY_ON(on) on
#define OUT_SOCKET_NODELAY_ON(on) on
#define closesocket(fd) close(fd)

#define IN_ADDR_GET_ADDRESS(in_addr) \
    (&in_addr.s_addr)

#define IN_ADDR_SET_INADDR_ANY(in_addr) \
    ((in_addr).s_addr = INADDR_ANY)

#define IN_ADDR_SET_ADDRESS(in_addr, addr) \
    ((in_addr).s_addr = (addr))
/* ...
 * Unix
 */
#endif /* defined(WINDOWS) */

#define DEFAULT_SOCKET_BACKLOG 10

typedef USHORT SOCKET_PORT;
#define INVALID_SOCKET_PORT ((SOCKET_PORT)-1)

typedef int SOCKET_ADDR_LENGTH;
typedef int SOCKET_ADDR_FAMILY;
typedef SOCKET_ADDR_FAMILY SOCKET_ADDR_TYPE;
typedef int SOCKET_TYPE;
typedef int SOCKET_PROTOCOL;
typedef socklen_t SOCKLEN;

typedef int SOCKET_OPT_LEVEL;
typedef int SOCKET_OPT_NAME;
typedef void SOCKET_OPT_VALUE;
typedef socklen_t SOCKET_OPT_LENGTH;

typedef struct linger SOCKET_LINGER;
#define DEFAULT_SOCKET_LINGER_SECONDS 10

#define SET_SOCKET_LINGER_ON(linger, on) linger.l_onoff = on
#define SET_SOCKET_DONT_LINGER_ON(linger, on) linger.l_onoff = !on
#define SET_SOCKET_LINGER_SECONDS(linger, lingerSeconds) linger.l_linger = lingerSeconds

#define GET_SOCKET_LINGER_ON(linger) linger.l_onoff
#define GET_SOCKET_DONT_LINGER_ON(linger) !linger.l_onoff
#define GET_SOCKET_LINGER_SECONDS(linger) linger.l_linger

#define SOCKET_WAITFOREVER -1

#define HOSTENT_GET_ADDRESS(hostent) \
    ((hostent)->h_addr)

#define HOSTENT_GET_IN_ADDR(hostent) \
    *((IN_ADDR*)(HOSTENT_GET_ADDRESS(hostent)))

#define HOSTENT_GET_ADDRESS_INDEX(hostent, index) \
    ((hostent)->h_addr_list[index])

#define HOSTENT_GET_IN_ADDR_INDEX(hostent, index) \
    *((IN_ADDR*)(HOSTENT_GET_ADDRESS_INDEX(hostent, index)))

#if defined(CPLATFORM_SOCKET_EXTENSIONS) 
#else /* defined(CPLATFORM_SOCKET_EXTENSIONS) */
#define cplatform_closesocket closesocket
#define cplatform_socket socket
#define cplatform_bind bind
#define cplatform_listen listen
#define cplatform_accept accept
#define cplatform_connect connect
#define cplatform_send send
#define cplatform_recv recv
#define cplatform_setsockopt setsockopt
#define cplatform_getsockopt getsockopt
#define cplatform_gethostname gethostname
#define cplatform_gethostbyname gethostbyname
#define cplatform_gethostbyaddr gethostbyaddr
#if defined(WINDOWS_SOCKETS_1_API) 
#else /* defined(WINDOWS_SOCKETS_1_API) */
#define cplatform_getnameinfo getnameinfo
#define cplatform_getaddrinfo getaddrinfo
#define cplatform_freeaddrinfo freeaddrinfo
#endif /* defined(WINDOWS_SOCKETS_1_API) */
#endif /* defined(CPLATFORM_SOCKET_EXTENSIONS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(CPLATFORM_SOCKET_EXTENSIONS) 
/**
 **********************************************************************
 * Function: cplatform_socket
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
SOCKET cplatform_socket
(SOCKET_FAMILY family, SOCKET_TYPE type, SOCKET_PROTOCOL protocol);
/**
 **********************************************************************
 * Function: cplatform_closesocket
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
int cplatform_closesocket(SOCKET sock);

/**
 **********************************************************************
 * Function: cplatform_bind
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
int cplatform_bind
(SOCKET sock, const SOCKADDR *addr, SOCKLEN addrlen);
/**
 **********************************************************************
 * Function: cplatform_listen
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
int cplatform_listen(SOCKET sock, int backlog);

/**
 **********************************************************************
 * Function: cplatform_accept
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
SOCKET cplatform_accept
(SOCKET sock, SOCKADDR *addr, SOCKLEN *addrlen);
/**
 **********************************************************************
 * Function: cplatform_connect
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
int cplatform_connect
(SOCKET sock, const SOCKADDR *addr, SOCKLEN addrlen);

/**
 **********************************************************************
 * Function: cplatform_send
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
SOCKET_SSIZE_T cplatform_send
(SOCKET sock, const SOCKET_DATA_VALUE *buf, SOCKET_SIZE_T len, int flags);
/**
 **********************************************************************
 * Function: cplatform_recv
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
SOCKET_SSIZE_T cplatform_recv
(SOCKET sock, SOCKET_DATA_VALUE *buf, SOCKET_SIZE_T len, int flags);

/**
 **********************************************************************
 * Function: cplatform_setsockopt
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
int cplatform_setsockopt
(SOCKET sock, SOCKET_OPT_LEVEL level, SOCKET_OPT_NAME optname, 
 const SOCKET_OPT_VALUE *optval, SOCKET_OPT_LENGTH optlen);
/**
 **********************************************************************
 * Function: cplatform_getsockopt
 *
 *   Author: $author$
 *     Date: 3/1/2010
 **********************************************************************
 */
int cplatform_getsockopt
(SOCKET sock, SOCKET_OPT_LEVEL level, SOCKET_OPT_NAME optname, 
 SOCKET_OPT_VALUE *optval, SOCKET_OPT_LENGTH *optlen);

/**
 **********************************************************************
 * Function: cplatform_gethostname
 *
 *   Author: $author$
 *     Date: 3/2/2010
 **********************************************************************
 */
int cplatform_gethostname
(char* name, SOCKET_SIZE_T len);
/**
 **********************************************************************
 * Function: cplatform_gethostbyname
 *
 *   Author: $author$
 *     Date: 3/2/2010
 **********************************************************************
 */
HOSTENT* cplatform_gethostbyname(const char* name);
/**
 **********************************************************************
 * Function: cplatform_gethostbyaddr
 *
 *   Author: $author$
 *     Date: 3/2/2010
 **********************************************************************
 */
HOSTENT* cplatform_gethostbyaddr
(const SOCKET_ADDR_VALUE* addr, SOCKLEN len, int type);
#else /* defined(CPLATFORM_SOCKET_EXTENSIONS) */
#endif /* defined(CPLATFORM_SOCKET_EXTENSIONS) */

#if defined(CPLATFORM_SOCKET_EXTENSIONS) || defined(WINDOWS_SOCKETS_1_API) 
/**
 **********************************************************************
 * Function: cplatform_getnameinfo
 *
 *   Author: $author$
 *     Date: 3/12/2010
 **********************************************************************
 */
int cplatform_getnameinfo
(const SOCKADDR* addr, SOCKLEN addrLen,
 TCHAR* host, SOCKET_NAME_SIZE_T hostLen,
 TCHAR* serv, SOCKET_NAME_SIZE_T servLen,
 int flags);
/**
 **********************************************************************
 * Function: cplatform_getaddrinfo
 *
 *   Author: $author$
 *     Date: 3/12/2010
 **********************************************************************
 */
int cplatform_getaddrinfo
(const TCHAR* nodeName, const TCHAR* serviceName,
 const ADDRINFO* addrHints, ADDRINFO** addrInfo);
/**
 **********************************************************************
 * Function: cplatform_freeaddrinfo
 *
 *   Author: $author$
 *     Date: 3/12/2010
 **********************************************************************
 */
void cplatform_freeaddrinfo(ADDRINFO* addrInfo);
#else /* defined(CPLATFORM_SOCKET_EXTENSIONS) || defined(WINDOWS_SOCKETS_1_API) */
#endif /* defined(CPLATFORM_SOCKET_EXTENSIONS) || defined(WINDOWS_SOCKETS_1_API) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_SOCKET_H */
