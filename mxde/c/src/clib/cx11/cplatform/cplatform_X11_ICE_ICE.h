/* $Xorg: ICE.h,v 1.4 2001/02/09 02:03:26 xorgcvs Exp $ */
/******************************************************************************


Copyright 1993, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

Author: Ralph Mor, X Consortium

******************************************************************************/

/**
 **********************************************************************
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
 *   File: cplatform_X11_ICE_ICE.h
 *
 * Author: $author$           
 *   Date: 5/4/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_X11_ICE_ICE_H
#define _CPLATFORM_X11_ICE_ICE_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <X11/ICE/ICE.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

/*
 * Protocol Version
 */

#define IceProtoMajor 1
#define IceProtoMinor 0


/*
 * Byte Order
 */

#define IceLSBfirst		0
#define IceMSBfirst		1


/*
 * ICE minor opcodes
 */

#define ICE_Error 		0
#define ICE_ByteOrder		1
#define ICE_ConnectionSetup	2
#define ICE_AuthRequired	3
#define ICE_AuthReply 		4
#define ICE_AuthNextPhase	5
#define ICE_ConnectionReply	6
#define ICE_ProtocolSetup	7
#define ICE_ProtocolReply	8
#define ICE_Ping		9
#define ICE_PingReply		10
#define ICE_WantToClose		11
#define ICE_NoClose		12


/*
 * Error severity
 */

#define IceCanContinue		0
#define IceFatalToProtocol	1
#define IceFatalToConnection	2


/*
 * ICE error classes that are common to all protocols
 */

#define IceBadMinor	0x8000
#define IceBadState	0x8001
#define IceBadLength	0x8002
#define IceBadValue	0x8003


/*
 * ICE error classes that are specific to the ICE protocol
 */

#define IceBadMajor			0
#define IceNoAuth			1
#define IceNoVersion			2
#define IceSetupFailed			3
#define IceAuthRejected			4
#define IceAuthFailed			5
#define IceProtocolDuplicate		6
#define IceMajorOpcodeDuplicate		7
#define IceUnknownProtocol		8

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_X11_ICE_ICE_H */
