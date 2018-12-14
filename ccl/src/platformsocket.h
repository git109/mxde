/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: platformsocket.h
 *
 * Author: $author$
 *   Date: 10/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _PLATFORMSOCKET_H
#define _PLATFORMSOCKET_H

#if defined(WIN32)
/*
 * Windows sockets
 */
#include <windows.h>

#define socklen_t int
#define SD_RECEIVE 0
#define SD_SEND    1
#define SD_BOTH    2

#define SOCKET_GET_H_ERRNO() WSAGetLastError()
#define SOCKET_NODELAY_ON(on) !on
#define IN_ADDR_GET_ADDRESS(in_addr) \
    (&in_addr.S_un.S_un_b.s_b1)
#else /* defined(WIN32) */
/*
 * Unix sockets
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define SOCKET int
#define INVALID_SOCKET -1
#define SD_RECEIVE SHUT_RD
#define SD_SEND SHUT_WR
#define SD_BOTH SHUT_RDWR

#define SOCKET_GET_H_ERRNO() h_errno
#define SOCKET_NODELAY_ON(on) on
#define closesocket(handle) close(handle)
#define IN_ADDR_GET_ADDRESS(in_addr) \
    ((unsigned char*)&in_addr.s_addr)

typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct in_addr IN_ADDR;
typedef struct hostent HOSTENT;
#endif /* defined(WIN32) */

#define DEFAULT_SOCKET_BACKLOG 5

#define HOSTENT_GET_ADDRESS(hostent) \
    ((hostent)->h_addr)

#define HOSTENT_GET_IN_ADDR(hostent) \
    *((IN_ADDR*)(HOSTENT_GET_ADDRESS(hostent)))

#define HOSTENT_GET_ADDRESS_INDEX(hostent, index) \
    ((hostent)->h_addr_list[index])

#define HOSTENT_GET_IN_ADDR_INDEX(hostent, index) \
    *((IN_ADDR*)(HOSTENT_GET_ADDRESS_INDEX(hostent, index)))

#define IN_ADDR_SET_INADDR_ANY(in_addr) \
    ((in_addr).s_addr = INADDR_ANY)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif
