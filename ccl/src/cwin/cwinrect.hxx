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
 *   File: cwinrect.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINRECT_HXX
#define _CWINRECT_HXX

#include "cwinpoint.hxx"
#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinRect
 *
 * Author: $author$
 *   Date: 2/28/2004
 **********************************************************************
 */
class cWinRect
: public RECT
{
public:
    typedef RECT cIs;

    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 2/28/2004
     **********************************************************************
     */
    cWinRect
    (int p_left=0, int p_top=0, int p_right=0, int p_bottom=0) 
    {
        left = p_left;
        top = p_top;
        right = p_right;
        bottom = p_bottom;
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinRect(HWND window) 
    {
        eError error;

        if (window)
        if ((error = GetWindow(window)))
            throw(error);
    }
    /**
     **********************************************************************
     * Constructor: cWinRect
     *
     *      Author: $author$
     *        Date: 4/13/2004
     **********************************************************************
     */
    cWinRect(cWinRect &r1, cWinRect &r2)
    {
        left = r1.left;
        top = r1.top;
        right = r1.right;
        bottom = r1.bottom;

        if (left > r2.left)
            left = r2.left;

        if (top > r2.top)
            top = r2.top;

        if (right < r2.right)
            right = r2.right;

        if (bottom < r2.bottom)
            bottom = r2.bottom;
    }

    /**
     **********************************************************************
     * Function: ToClient
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    eError ToClient(HWND hwnd)
    {
        cWinPoint p1(left, top),p2(right,bottom);

        if (ScreenToClient(hwnd, &p1))
        if (ScreenToClient(hwnd, &p2))
        {
            left = p1.x;
            top =p1.y;
            right = p2.x;
            bottom = p2.y;
            return e_ERROR_NONE;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetClient
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    eError GetClient(HWND hwnd)
    {
        if (GetClientRect(hwnd, this))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetWindow
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError GetWindow(HWND hwnd)
    {
        if (GetWindowRect(hwnd, this))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetUpdate
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    eError GetUpdate(HWND hwnd, BOOL erase=FALSE)
    {
        if (GetUpdateRect(hwnd, this, erase))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cWinClientRect
 *
 * Author: $author$
 *   Date: 5/12/2004
 **********************************************************************
 */
class cWinClientRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinClientRect
     *
     *      Author: $author$
     *        Date: 5/12/2004
     **********************************************************************
     */
    cWinClientRect(HWND window=NULL) 
    {
        eError error;

        if (window)
        if ((error = GetClient(window)))
            throw(error);
    }
};

/**
 **********************************************************************
 *  Class: cWinWindowRect
 *
 * Author: $author$
 *   Date: 2/1/2006
 **********************************************************************
 */
class cWinWindowRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinWindowRect
     *
     *      Author: $author$
     *        Date: 2/1/2006
     **********************************************************************
     */
    cWinWindowRect(HWND window=NULL) 
    {
        eError error;

        if (window)
        if ((error = GetWindow(window)))
            throw(error);
    }
};

/**
 **********************************************************************
 *  Class: cWinWindowToClientRect
 *
 * Author: $author$
 *   Date: 2/1/2006
 **********************************************************************
 */
class cWinWindowToClientRect
: public cWinRect
{
public:
    typedef cWinRect cIs;

    /**
     **********************************************************************
     * Constructor: cWinWindowToClientRect
     *
     *      Author: $author$
     *        Date: 2/1/2006
     **********************************************************************
     */
    cWinWindowToClientRect
    (HWND window=NULL, HWND client=NULL) 
    {
        eError error;

        if (window && client)
        if ((error = GetWindow(window)))
            throw(error);
        else if ((error = ToClient(client)))
                throw(error);
    }
};

#endif /* _CWINRECT_HXX */
