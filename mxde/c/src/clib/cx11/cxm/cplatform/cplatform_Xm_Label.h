/**
 *
 * $Id: Label.h,v 1.1 2004/08/28 19:23:25 dannybackx Exp $
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
 *   File: cplatform_Xm_Label.h
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#ifndef _CPLATFORM_XM_LABEL_H
#define _CPLATFORM_XM_LABEL_H

#include "cplatform.h"

#if !defined(WINDOWS) 
/* Unix
 */
#include <Xm/Label.h>
#else /* !defined(WINDOWS) */
/* Windows
 */
#include "cplatform_Xm_Xm.h"

#ifdef __cplusplus
extern "C" {
#endif

XMLIBEXPORT extern WidgetClass xmLabelWidgetClass;

typedef struct _XmLabelRec *XmLabelWidget;
typedef struct _XmLabelClassRec *XmLabelWidgetClass;

XMLIBEXPORT extern Widget XmCreateLabel(Widget parent,
			    char *name,
			    Arg *arglist,
			    Cardinal argCount);

#ifndef XmIsLabel
#define XmIsLabel(w) XtIsSubclass((w), xmLabelWidgetClass)
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

#endif /* _CPLATFORM_XM_LABEL_H */
