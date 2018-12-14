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
 *   File: cwinpoint.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINPOINT_HXX
#define _CWINPOINT_HXX

#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinPoint
 *
 * Author: $author$
 *   Date: 4/5/2004
 **********************************************************************
 */
class cWinPoint
: public POINT
{
public:
    typedef POINT cIs;

    /**
     **********************************************************************
     * Constructor: cWinPoint
     *
     *      Author: $author$
     *        Date: 4/5/2004
     **********************************************************************
     */
    cWinPoint(LONG p_x=0, LONG p_y=0) 
    {
        x = p_x;
        y = p_y;
    }
    /**
     **********************************************************************
     * Function: ToScreen
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    eError ToScreen(HWND hwnd)
    {
        if (ClientToScreen(hwnd, this))
            return e_ERROR_NONE;

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Operator: =
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    cWinPoint &operator = (cWinPoint &point)
    {
        x = point.x;
        y = point.y;
        return *this;
    }
};

#endif /* _CWINPOINT_HXX */


