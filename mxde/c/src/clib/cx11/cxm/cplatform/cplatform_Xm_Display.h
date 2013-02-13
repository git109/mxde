/**
 *
 * $Id: Display.h,v 1.1 2004/08/28 19:23:24 dannybackx Exp $
 *
 * Copyright (C) 1995 Free Software Foundation, Inc.
 * Copyright (C) 1995-2000 LessTif Development Team
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
 *   File: cplatform_Xm_Display.h
 *
 * Author: $author$           
 *   Date: 5/2/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_XM_DISPLAY_H
#define _CPLATFORM_XM_DISPLAY_H
#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <Xm/Display.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_Xm_Xm.h"
#include "cplatform_X11_Shell.h"
#include "cplatform_Xm_DragC.h"
#include "cplatform_Xm_DropSMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    XmDRAG_NONE,
    XmDRAG_DROP_ONLY,
    XmDRAG_PREFER_PREREGISTER,
    XmDRAG_PREREGISTER,
    XmDRAG_PREFER_DYNAMIC,
    XmDRAG_DYNAMIC,
    XmDRAG_PREFER_RECEIVER
};

XMLIBEXPORT extern WidgetClass xmDisplayClass;

typedef struct _XmDisplayRec *XmDisplay;
typedef struct _XmDisplayClassRec *XmDisplayClass;

XMLIBEXPORT extern Widget XmGetXmDisplay(Display *Dsp);
XMLIBEXPORT extern Widget XmGetDragContext(Widget w, Time time);

#define XmGetDisplay(w) XmGetXmDisplay(XtDisplayOfObject(w))

#ifndef XmIsDisplay
#define XmIsDisplay(w) XtIsSubclass((w), xmDisplayClass)
#endif

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

#endif /* _CPLATFORM_XM_DISPLAY_H */
