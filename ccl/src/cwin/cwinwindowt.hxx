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
 *   File: cwinwindowt.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINWINDOWT_HXX
#define _CWINWINDOWT_HXX

#include "cwinwindow.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowT
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
template
<class TAs, class TIs=cWinWindow>
class cWinWindowT
: public TIs
{
public:
    typedef TIs cIs;
    typedef TAs cAs;

    /**
     **********************************************************************
     * Constructor: cWinWindowT
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cWinWindowT
    (HINSTANCE instance=NULL, HWND handle=NULL, 
     bool created=false, HINSTANCE old_instance=NULL) 
    : cIs(instance, handle, created, old_instance) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateInstanceWindowProc
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    static LRESULT CALLBACK CreateInstanceWindowProc
    (HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        cAs *window = 0;
        LRESULT result;
        eError error;

        switch(message)
        {
#if defined(_WIN32_WCE) 
        case WM_CREATE:
#else /* defined(_WIN32_WCE) */
        case WM_NCCREATE:
#endif /* defined(_WIN32_WCE) */
            if ((window = CreateInstance(error, handle)))
                SetWindowLong(handle, GWL_USERDATA, (LONG)window);
            break;

#if defined(_WIN32_WCE) 
        case WM_DESTROY:
#else /* defined(_WIN32_WCE) */
        case WM_NCDESTROY:
#endif /* defined(_WIN32_WCE) */
            if ((window = (cAs*)GetWindowLong(handle, GWL_USERDATA)))
            {
                result = window->OnWindowProc(message, wparam, lparam);
                error = window->DestroyInstance();
                return result;
            }
            result = DefWindowProc(handle, message, wparam, lparam);
            return result;

        default:
            window = (cAs*)GetWindowLong(handle, GWL_USERDATA);
        }

        if (window)
            return window->OnWindowProc(message, wparam, lparam);

        return DefWindowProc(handle, message, wparam, lparam);
    }
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 1/21/2006
     **********************************************************************
     */
    static cAs* CreateInstance(eError& error, HWND handle) 
    {
        cAs* window = 0;

        if ((window = new cAs()))
        {
            if ((error = window->Attach(handle)))
            {
                delete window;
                window = 0;
            }
            else error = e_ERROR_NONE;
        }
        else error = e_ERROR_FAILED;
        return window;
    }
};

#endif /* _CWINWINDOWT_HXX */
