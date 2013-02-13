/**
 *
 * $Id: Protocols.h,v 1.1 2004/08/28 19:23:25 dannybackx Exp $
 *
 * Copyright (C) 1995 Free Software Foundation, Inc.
 * Copyright (C) 1995-2001 LessTif Development Team
 *
 * This file is part of the GNU LessTif Library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 **/

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
 *   File: cplatform_Xm_Protocols.h
 *
 * Author: $author$           
 *   Date: 5/2/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_XM_PROTOCOLS_H
#define _CPLATFORM_XM_PROTOCOLS_H

#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <Xm/Protocols.h>
#else /* !defined(WINDOWS) */
/* Windows
 */
#include "cplatform_Xm_Xm.h"
#include "cplatform_Xm_AtomMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

#define XmCR_WM_PROTOCOLS 6666

/* Some macros being defined here are called
   "convenience" interfaces in the Motif docs and 
   specified as of type 
     void foo(...,...);
   Since Motif only provides some of them as macros we dare
   to do the very same! */

#define XM_WM_PROTOCOL_ATOM(shell) \
    XmInternAtom(XtDisplay(shell), "WM_PROTOCOLS", FALSE)

#define XmAddWMProtocols(shell, protocols, num_protocols) \
    XmAddProtocols(shell, XM_WM_PROTOCOL_ATOM(shell), \
		   protocols, num_protocols)

#define XmRemoveWMProtocols(shell, protocols, num_protocols) \
    XmRemoveProtocols(shell, XM_WM_PROTOCOL_ATOM(shell), \
		      protocols, num_protocols)

#define XmAddWMProtocolCallback(shell, protocol, callback, closure) \
    XmAddProtocolCallback(shell, XM_WM_PROTOCOL_ATOM(shell), \
			  protocol, callback, closure)

#define XmRemoveWMProtocolCallback(shell, protocol, callback, closure) \
    XmRemoveProtocolCallback(shell, XM_WM_PROTOCOL_ATOM(shell), \
			     protocol, callback, closure)

#define XmActivateWMProtocol(shell, protocol) \
      XmActivateProtocol(shell, XM_WM_PROTOCOL_ATOM(shell), \
			 protocol)

#define XmDeactivateWMProtocol(shell, protocol) \
      XmDeactivateProtocol(shell, XM_WM_PROTOCOL_ATOM(shell), \
			   protocol)

#define XmSetWMProtocolHooks(shell, protocol, pre_h, pre_c, post_h, post_c) \
      XmSetProtocolHooks(shell, XM_WM_PROTOCOL_ATOM(shell), \
			 protocol, pre_h, pre_c, post_h, post_c)


XMLIBEXPORT extern WidgetClass xmProtocolClass;

XMLIBEXPORT void XmActivateProtocol(Widget shell,
			Atom property,
			Atom protocol);

XMLIBEXPORT void XmAddProtocolCallback(Widget shell,
			   Atom property,
			   Atom protocol,
			   XtCallbackProc callback,
			   XtPointer closure);

XMLIBEXPORT void XmAddProtocols(Widget shell,
		    Atom property,
		    Atom *protocol,
		    Cardinal num_protocols);

XMLIBEXPORT void XmRemoveProtocolCallback(Widget shell,
			      Atom property,
			      Atom protocol,
			      XtCallbackProc callback,
			      XtPointer closure);

XMLIBEXPORT void XmRemoveProtocols(Widget shell,
		       Atom property,
		       Atom *protocols,
		       Cardinal num_protocols);

XMLIBEXPORT void XmDeactivateProtocol(Widget shell,
				 Atom property,
				 Atom proto_atom);

XMLIBEXPORT void XmSetProtocolHooks(Widget shell,
			       Atom property,
			       Atom proto_atom,
			       XtCallbackProc pre_hook,
			       XtPointer pre_closure,
			       XtCallbackProc post_hook,
			       XtPointer post_closure);

#ifdef __cplusplus
}
#endif

/* Windows
 */
#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_XM_PROTOCOLS_H */
