/**
 **********************************************************************
 * Copyright (c) 1988-2013 $organization$
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
 *   File: cplatform_Xm_ScrolledW.h
 *
 * Author: $author$
 *   Date: 6/24/2013
 **********************************************************************
 */
#ifndef _CPLATFORM_XM_SCROLLEDW_H
#define _CPLATFORM_XM_SCROLLEDW_H

#include <cplatform.h>

#if !defined(WINDOWS)  
/* Unix
 */
#include <Xm/ScrolledW.h>
#else /* !defined(WINDOWS)  */
/* Windows
 */
#include "cplatform_Xm_Xm.h"

#ifdef __cplusplus
extern "C" {
#endif

XMLIBEXPORT extern WidgetClass xmScrolledWindowWidgetClass;

typedef struct _XmScrolledWindowRec *XmScrolledWindowWidget;
typedef struct _XmScrolledWindowClassRec *XmScrolledWindowWidgetClass;

#ifndef XmIsScrolledWindow
#define XmIsScrolledWindow(w) XtIsSubclass((w), xmScrolledWindowWidgetClass)
#endif

XMLIBEXPORT extern Widget XmCreateScrolledWindow(Widget parent, char *name, Arg *argList, Cardinal argcount);
XMLIBEXPORT extern void XmScrollVisible(Widget scrollw_widget, Widget widget, Dimension left_right_margin, Dimension top_bottom_margin);
XMLIBEXPORT extern void XmScrolledWindowSetAreas(Widget widget, Widget h_scrollbar, Widget v_scrollbar, Widget work_region);

#ifdef __cplusplus
}
#endif

#endif /* !defined(WINDOWS)  */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* _CPLATFORM_XM_SCROLLEDW_H */
        

