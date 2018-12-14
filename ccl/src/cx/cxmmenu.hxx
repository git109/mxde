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
 *   File: cxmmenu.hxx
 *
 * Author: $author$
 *   Date: 4/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMMENU_HXX
#define _CXMMENU_HXX

#include "cxmwidget.hxx"

/**
 **********************************************************************
 *   Enum: 
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
enum
{
    e_XM_MENU_END,
    e_XM_MENU_ITEM,
    e_XM_MENU_LABEL,
    e_XM_MENU_SEPARATOR,
    e_XM_MENU_PULLDOWN,
    e_XM_MENU_POPUP,
    e_XM_MENU_BAR,
    e_XM_MENU_LIST
};

/**
 **********************************************************************
 * Struct: sXmMenuDef
 *
 * Author: $author$
 *   Date: 4/29/2004
 **********************************************************************
 */
struct sXmMenuDef
{
    int m_type;
    char *m_label;
    char *m_accel;
    int m_id;
};

#define c_XM_MENU_DECLARE(id) static sXmMenuDef id[];
#define c_XM_MENU(id) sXmMenuDef id[]={{e_XM_MENU_LIST},
#define c_XM_MENU_POPUP(id,label) sXmMenuDef id[]={{e_XM_MENU_POPUP,label},
#define c_XM_MENU_BAR(id,help) sXmMenuDef id[]={{e_XM_MENU_BAR,0,0,help},
#define c_XM_MENU_PULLDOWN(label) {e_XM_MENU_PULLDOWN,label},
#define c_XM_MENU_ITEM(label,accel,id) {e_XM_MENU_ITEM,label,accel,id},
#define c_XM_MENU_LABEL(label) {e_XM_MENU_LABEL,label},
#define c_XM_MENU_SEPARATOR {e_XM_MENU_SEPARATOR},
#define c_XM_MENU_PULLDOWN_END {e_XM_MENU_END},
#define c_XM_MENU_POPUP_END {e_XM_MENU_END}};
#define c_XM_MENU_END {e_XM_MENU_END}};

#endif /* ndef _CXMMENU_HXX */
