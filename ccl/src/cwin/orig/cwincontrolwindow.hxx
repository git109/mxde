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
 *   File: cwincontrolwindow.hxx
 *
 * Author: $author$
 *   Date: 5/12/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINCONTROLWINDOW_HXX
#define _CWINCONTROLWINDOW_HXX

#include "cwinwindow.hxx"

/**
 **********************************************************************
 *  Class: cWinControlWindow
 *
 * Author: $author$
 *   Date: 5/12/2004
 **********************************************************************
 */
class cWinControlWindow
: public cWinWindow
{
public:
    typedef cWinWindow cIs;

    HWND m_control;

    /**
     **********************************************************************
     * Constructor: cWinControlWindow
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinControlWindow(HINSTANCE instance=NULL, HWND handle=NULL, bool created=false) 
    : cIs(instance, handle, created),
      m_control(NULL)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinControlWindow
     *
     *     Author: $author$
     *       Date: 5/12/2004
     **********************************************************************
     */
    virtual ~cWinControlWindow()
    {
    }

    /**
     **********************************************************************
     * Function: SetControl
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual HWND SetControl(HWND control)
    {
        return m_control = control;
    }
    /**
     **********************************************************************
     * Function: GetControl
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual HWND GetControl() const
    {
        return m_control;
    }

    /**
     **********************************************************************
     * Function: OnCreateControl
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual eError OnCreateControl()
    {
        eError error=e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnDestroyControl
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual eError OnDestroyControl()
    {
        eError error=e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        if (m_control)
        {
            cWinClientRect rect(m_handle);

            MoveWindow
            (m_control, 0,0, 
             rect.right-rect.left+1,
             rect.bottom-rect.top+1, TRUE);
        }
        return cIs::OnWMCreate(wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnWMSize
     *
     *   Author: $author$
     *     Date: 5/12/2004
     **********************************************************************
     */
    virtual LRESULT OnWMSize(WPARAM wparam, LPARAM lparam)
    {
        if (m_control && (SIZE_RESTORED == wparam))
        {
            int width=LOWORD(lparam), height=HIWORD(lparam);

            MoveWindow(m_control, 0,0, width, height, TRUE);
        }
        return cIs::OnWMSize(wparam, lparam);
    }
};

#endif /* ndef _CWINCONTROLWINDOW_HXX */
