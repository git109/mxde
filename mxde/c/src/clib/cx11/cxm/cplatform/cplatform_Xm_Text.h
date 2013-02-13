/**
 *
 * $Id: Text.h,v 1.1 2004/08/28 19:23:26 dannybackx Exp $
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
 *   File: cplatform_Xm_Text.h
 *
 * Author: $author$           
 *   Date: 7/2/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_XM_TEXT_H
#define _CPLATFORM_XM_TEXT_H

#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <Xm/Text.h>
#else /* !defined(WINDOWS) */
/* Windows
 */
#include "cplatform_Xm_Xm.h"

#ifdef __cplusplus
extern "C" {
#endif

XMLIBEXPORT extern WidgetClass xmTextWidgetClass;

typedef struct _XmTextRec *XmTextWidget;
typedef struct _XmTextClassRec *XmTextWidgetClass;

XMLIBEXPORT extern Widget XmCreateText(Widget parent,
			    char *name,
			    Arg *arglist,
			    Cardinal argCount);

XMLIBEXPORT extern Widget XmCreateScrolledText(Widget parent,
				   char *name,
				   Arg *arglist,
				   Cardinal argcount);

#ifndef XmIsText
#define XmIsText(w) XtIsSubclass((w), xmTextWidgetClass)
#endif

typedef struct _XmTextSourceRec *XmTextSource;

XMLIBEXPORT void XmTextClearSelection(Widget widget, Time time);
XMLIBEXPORT Boolean XmTextCopy(Widget widget, Time time);
XMLIBEXPORT Boolean XmTextCut(Widget widget, Time time);
XMLIBEXPORT void XmTextDisableRedisplay(Widget widget);
XMLIBEXPORT void XmTextEnableRedisplay(Widget widget);
XMLIBEXPORT Boolean XmTextFindString(Widget widget, XmTextPosition start, char *string, 
			 XmTextDirection direction, XmTextPosition *position);
XMLIBEXPORT Boolean XmTextFindStringWcs(Widget widget, XmTextPosition start, wchar_t *wcstring, 
			    XmTextDirection direction, XmTextPosition *position);
XMLIBEXPORT int XmTextGetBaseline(Widget widget);
XMLIBEXPORT XmTextPosition XmTextGetCursorPosition(Widget widget);
XMLIBEXPORT Boolean XmTextGetEditable(Widget widget);
XMLIBEXPORT XmTextPosition XmTextGetInsertionPosition(Widget widget);
XMLIBEXPORT XmTextPosition XmTextGetLastPosition(Widget widget);
XMLIBEXPORT int XmTextGetMaxLength(Widget widget);
XMLIBEXPORT char *XmTextGetSelection(Widget widget);
XMLIBEXPORT Boolean XmTextGetSelectionPosition(Widget widget, XmTextPosition *left, XmTextPosition *right);
XMLIBEXPORT wchar_t *XmTextGetSelectionWcs(Widget widget);
XMLIBEXPORT XmTextSource XmTextGetSource(Widget widget);
XMLIBEXPORT char *XmTextGetString(Widget widget);
XMLIBEXPORT wchar_t *XmTextGetStringWcs(Widget widget);
XMLIBEXPORT  int XmTextGetSubstring(Widget widget, XmTextPosition start, int num_chars, int buffer_size,
		       char *buffer);
XMLIBEXPORT int XmTextGetSubstringWcs(Widget widget, XmTextPosition start, int num_chars, int buffer_size,
			  wchar_t *buffer);
XMLIBEXPORT XmTextPosition XmTextGetTopCharacter(Widget widget);
XMLIBEXPORT void XmTextInsert(Widget widget, XmTextPosition position, char *string);
XMLIBEXPORT void XmTextInsertWcs(Widget widget, XmTextPosition position, wchar_t *wcstring);
XMLIBEXPORT Boolean XmTextPaste(Widget widget);
XMLIBEXPORT Boolean XmTextPosToXY(Widget widget, XmTextPosition position, Position *x, Position *y);
XMLIBEXPORT Boolean XmTextRemove(Widget widget);
XMLIBEXPORT void XmTextReplace(Widget widget, XmTextPosition from_pos, XmTextPosition to_pos,
		   char *value);
XMLIBEXPORT void XmTextReplaceWcs(Widget widget, XmTextPosition from_pos, XmTextPosition to_pos,
		      wchar_t *wcstring);
XMLIBEXPORT void XmTextScroll(Widget widget, int lines);
XMLIBEXPORT void XmTextSetAddMode(Widget widget, Boolean state);
XMLIBEXPORT void XmTextSetCursorPosition(Widget widget, XmTextPosition position);
XMLIBEXPORT void XmTextSetEditable(Widget widget, Boolean editable);
XMLIBEXPORT void XmTextSetHighlight(Widget widget, XmTextPosition left, XmTextPosition right, XmHighlightMode mode);
XMLIBEXPORT void XmTextSetInsertionPosition(Widget widget, XmTextPosition position);
XMLIBEXPORT void XmTextSetMaxLength(Widget widget, int max_length);
XMLIBEXPORT void XmTextSetSelection(Widget widget, XmTextPosition first, XmTextPosition last, Time time);
XMLIBEXPORT void XmTextSetSource(Widget widget, XmTextSource source, XmTextPosition top_character, XmTextPosition cursor_position);
XMLIBEXPORT void XmTextSetString(Widget widget, char *value);
XMLIBEXPORT void XmTextSetStringWcs(Widget widget, wchar_t *wcstring);
XMLIBEXPORT void XmTextSetTopCharacter(Widget widget, XmTextPosition top_character);
XMLIBEXPORT void XmTextShowPosition(Widget widget, XmTextPosition position);
XMLIBEXPORT XmTextPosition XmTextXYToPos(Widget widget, Position x, Position y);

#if XmVERSION >= 2
XMLIBEXPORT Boolean XmTextCopyLink(Widget widget,
                       Time time);
#endif

#ifdef __cplusplus
}
#endif

#endif /* !defined(WINDOWS) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_XM_TEXT_H */
