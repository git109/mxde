/**
 *
 * $Id: VirtKeys.h,v 1.1 2004/08/28 19:23:27 dannybackx Exp $
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
 *   File: cplatform_Xm_VirtKeys.h
 *
 * Author: $author$           
 *   Date: 5/2/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_XM_VIRTKEYS_H
#define _CPLATFORM_XM_VIRTKEYS_H

#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <Xm/VirtKeys.h>
#else /* !defined(WINDOWS) */
/* Windows
 */

#include "cplatform_Xm_Xm.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * All those nasty virtual (but quite real) keysyms, which have been
 * invented by the closed software foundation (csf).
 */
#define osfXK_Activate          0x1004FF44
#define osfXK_AddMode           0x1004FF31
#define osfXK_BackSpace         0x1004FF08
#define osfXK_BeginLine         0x1004FF58
#define osfXK_Cancel            0x1004FF69
#define osfXK_Clear             0x1004FF0B
#define osfXK_Copy              0x1004FF02
#define osfXK_Cut               0x1004FF03
#define osfXK_Delete            0x1004FFFF
#define osfXK_Down              0x1004FF54
#define osfXK_EndLine           0x1004FF57
#define osfXK_Help              0x1004FF6A
#define osfXK_Insert            0x1004FF63
#define osfXK_Left              0x1004FF51
#define osfXK_Menu              0x1004FF67
#define osfXK_MenuBar           0x1004FF45
#define osfXK_PageLeft          0x1004FF40
#define osfXK_PageDown          0x1004FF42
#define osfXK_PageRight         0x1004FF43
#define osfXK_PageUp            0x1004FF41
#define osfXK_Paste             0x1004FF04
#define osfXK_PrimaryPaste      0x1004FF32
#define osfXK_QuickPaste        0x1004FF33
#define osfXK_Right             0x1004FF53
#define osfXK_Select            0x1004FF60
#define osfXK_Undo              0x1004FF65
#define osfXK_Up                0x1004FF52


XMLIBEXPORT extern void XmTranslateKey(Display *Dsp, KeyCode Keycode,
                           Modifiers modifiers, Modifiers *modifiers_return,
                           KeySym *Keysym_return);

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

#endif /* _CPLATFORM_XM_VIRTKEYS_H */
