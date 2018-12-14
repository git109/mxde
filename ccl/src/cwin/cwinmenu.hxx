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
 *   File: cwinmenu.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINMENU_HXX
#define _CWINMENU_HXX

#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinMenu
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cWinMenu
: public cCreatedHandleT<HMENU, NULL>
{
public:
    typedef cCreatedHandleT<HMENU, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinMenu
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cWinMenu(HMENU menu=NULL, bool created=false) 
    : cIs(menu, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinMenu
     *
     *     Author: $author$
     *       Date: 3/29/2004
     **********************************************************************
     */
    virtual ~cWinMenu()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Create(HINSTANCE instance, WORD id)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = LoadMenu
            (instance, MAKEINTRESOURCE(id))))
        {
            m_created = true;
            error = e_ERROR_NONE;
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DestroyMenu(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_created = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetSubMenu
     *
     *   Author: $author$
     *     Date: 4/4/2004
     **********************************************************************
     */
    virtual eError GetSubMenu(HMENU menu, int pos)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = ::GetSubMenu(menu, pos)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: TrackPopup
     *
     *   Author: $author$
     *     Date: 4/4/2004
     **********************************************************************
     */
    virtual eError TrackPopup
    (HWND hwnd, int x=0, int y=0, 
     UINT flags=TPM_BOTTOMALIGN | TPM_LEFTALIGN
#if defined(_WIN32_WCE) 
#else /* defined(_WIN32_WCE) */
     | TPM_RIGHTBUTTON
#endif /* defined(_WIN32_WCE) */
     )
    {
        eError error=e_ERROR_FAILED;
        int reserved=0;
        RECT rect;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (TrackPopupMenu
            (m_handle, flags, x, y, reserved, hwnd, &rect))
            error = e_ERROR_NONE;

        return error;
    }
};

#endif /* _CWINMENU_HXX */


