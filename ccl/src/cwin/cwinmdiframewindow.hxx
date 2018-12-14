/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cwinmdiframewindow.hxx
 *
 * Author: $author$
 *   Date: 6/6/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINMDIFRAMEWINDOW_HXX
#define _CWINMDIFRAMEWINDOW_HXX

#include "cwinmdiclientwindow.hxx"
#include "cwinwindow.hxx"

/**
 **********************************************************************
 *  Class: cWinMDIFrameWindow
 *
 * Author: $author$
 *   Date: 6/6/2007
 **********************************************************************
 */
class cWinMDIFrameWindow
: public cWinWindow
{
public:
    typedef cWinWindow cExtends;
    typedef cWinMDIFrameWindow cDerives;

    cWinMDIClientWindow m_client_window;

    /**
     **********************************************************************
     * Constructor: cWinMDIFrameWindow
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    cWinMDIFrameWindow
    (HINSTANCE instance=NULL, HWND handle=NULL, 
     bool created=false, HINSTANCE old_instance=NULL) 
    : cExtends(instance, handle, created, old_instance) 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIFrameWindow
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    virtual ~cWinMDIFrameWindow()
    {
    }

    /**
     **********************************************************************
     * Function: GetClientWindow
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cWinMDIClientWindow& GetClientWindow() const 
    {
        return (cWinMDIClientWindow&)(m_client_window);
    }

    /**
     **********************************************************************
     * Function: OnWMCreate
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnWMCreate(WPARAM wparam, LPARAM lparam)
    {
        cWinMDIClientWindow& client_window = GetClientWindow();
        eError error;

        if (!(error = client_window.Create(m_instance, m_handle)))
            client_window.SetIsCreated(false);
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnDefWindowProc
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual LRESULT OnDefWindowProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        return OnDefFrameProc(message, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: OnDefFrameProc
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual LRESULT OnDefFrameProc
    (UINT message, WPARAM wparam, LPARAM lparam)
    {
        cWinMDIClientWindow& client_window = GetClientWindow();
        HWND handle = 0;

        if ((handle = client_window.GetHandle()))
            return DefFrameProc
            (m_handle, handle, message, wparam, lparam);

        return DefWindowProc
        (m_handle, message, wparam, lparam);
    }
};

#endif /* _CWINMDIFRAMEWINDOW_HXX */
