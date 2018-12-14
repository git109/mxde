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
 *   File: cwincommoncontrolwindow.hxx
 *
 * Author: $author$
 *   Date: 5/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINCOMMONCONTROLWINDOW_HXX
#define _CWINCOMMONCONTROLWINDOW_HXX

#include "cwincontrolwindow.hxx"
#include "cwincommoncontrol.hxx"

/**
 **********************************************************************
 *  Class: cWinCommonControlWindow
 *
 * Author: $author$
 *   Date: 5/13/2004
 **********************************************************************
 */
class cWinCommonControlWindow
: public cWinControlWindow
{
public:
    typedef cWinControlWindow cIs;

    cWinImageList m_image_list;

    /**
     **********************************************************************
     * Constructor: cWinCommonControlWindow
     *
     *      Author: $author$
     *        Date: 5/13/2004
     **********************************************************************
     */
    cWinCommonControlWindow(HINSTANCE instance=NULL, HWND handle=NULL, bool created=false) 
    : cIs(instance, handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinCommonControlWindow
     *
     *     Author: $author$
     *       Date: 5/13/2004
     **********************************************************************
     */
    virtual ~cWinCommonControlWindow()
    {
    }

    /**
     **********************************************************************
     * Function: OnWMDestroy
     *
     *   Author: $author$
     *     Date: 5/13/2004
     **********************************************************************
     */
    virtual LRESULT OnWMDestroy(WPARAM wparam, LPARAM lparam)
    {
        if (m_image_list.GetIsCreated())
        {
		    m_image_list.Destroy();
        }
        return cIs::OnWMDestroy(wparam, lparam);
    }
};

#endif /* ndef _CWINCOMMONCONTROLWINDOW_HXX */
