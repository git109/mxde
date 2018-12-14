/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: platform_hostent.h
 *
 * Author: $author$
 *   Date: 3/15/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _PLATFORM_HOSTENT_H
#define _PLATFORM_HOSTENT_H

/*
HOSTENT

Windows Sockets allocates this structure is allocated. An application should never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, and so the application should copy any information that it needs before issuing any other Windows Sockets API calls.

struct hostent {
    char FAR *       h_name;
    char FAR * FAR * h_aliases;
    short            h_addrtype;
    short            h_length;
    char FAR * FAR * h_addr_list;
};
 
Members

h_name 
Official name of the host (PC).If using the DNS or similar resolution system, it is the Fully Qualified Domain Name (FQDN) that caused the server to return a reply. If using a local "hosts" file, it is the first entry after the IP address. 

h_aliases 
A NULL-terminated array of alternate names. 

h_addrtype 
The type of address being returned. 

h_length 
The length, in bytes, of each address. 

h_addr_list 
A NULL-terminated list of addresses for the host. Addresses are returned in network byte order. The macro h_addr is defined to be h_addr_list[0] for compatibility with older software. 
*/

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _PLATFORM_HOSTENT_H */
