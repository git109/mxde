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
 *   File: cwindc.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINDC_HXX
#define _CWINDC_HXX

#include "cwinrect.hxx"
#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinDC
 *
 * Author: $author$
 *   Date: 2/28/2004
 **********************************************************************
 */
class cWinDC
: public cCreatedHandleT<HDC, NULL>
{
public:
    typedef cCreatedHandleT<HDC, NULL> cIs;

    HWND m_hwnd;

    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 2/28/2004
     **********************************************************************
     */
    cWinDC(HDC handle=NULL, bool created=false) 
    : cIs(handle, created),
      m_hwnd(NULL)
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 2/28/2004
     **********************************************************************
     */
    cWinDC(HWND hwnd, HDC handle=NULL) 
    : cIs(handle),
      m_hwnd(hwnd)
    {
        eError error;

        if (hwnd && !handle)
        if ((error = Get(hwnd)))
            throw(error);
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDC
     *
     *     Author: $author$
     *       Date: 2/28/2004
     **********************************************************************
     */
    virtual ~cWinDC()
    {
        eError error;

        if (m_created)
        if ((error = Destroy()))
            throw(error);

        if (m_hwnd)
        if ((error = Release()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError Get(HWND hwnd)
    {
        eError error=e_ERROR_FAILED;

        if (m_hwnd)
            return e_ERROR_ALREADY_CREATED;

        if ((m_handle = GetDC(hwnd)))
        {
            error = e_ERROR_NONE;
            m_hwnd = hwnd;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError Release()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (NULL == m_hwnd)
            return e_ERROR_NOT_CREATED;

        if (ReleaseDC(m_hwnd, m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_hwnd = NULL;
        return error;
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual eError Create(HWND hwnd)
    {
        eError error=e_ERROR_FAILED;
        HDC handle;

        if (m_hwnd)
            return e_ERROR_ALREADY_CREATED;

        if ((handle = GetDC(hwnd)))
        {
            if ((m_handle = CreateCompatibleDC(handle)))
            {
                error = e_ERROR_NONE;
                m_hwnd = hwnd;
                m_created = true;
            }

            ReleaseDC(hwnd, handle);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 1/29/2006
     **********************************************************************
     */
    virtual eError Create(HDC hdc)
    {
        eError error=e_ERROR_FAILED;

        if (m_handle)
            return e_ERROR_ALREADY_CREATED;

        if ((m_handle = CreateCompatibleDC(hdc)))
        {
            error = e_ERROR_NONE;
            m_created = true;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DeleteDC(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_hwnd = NULL;
        m_created = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: SelectObject
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual HGDIOBJ SelectObject(HGDIOBJ hobj)
    {
        if (m_handle)
            hobj = ::SelectObject(m_handle, hobj);
        else hobj = NULL;
        return hobj;
    }
    /**
     **********************************************************************
     * Function: FillRect
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError FillRect
    (int left, int top, int right, int bottom, HBRUSH hbrush)
    {
        eError error=e_ERROR_NOT_ATTACHED;

        if (m_handle)
        {
            cWinRect rect(left, top, right, bottom);

            if (::FillRect(m_handle, &rect, hbrush))
                return e_ERROR_NONE;

            error = e_ERROR_FAILED;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: BitBlt
     *
     *   Author: $author$
     *     Date: 2/28/2004
     **********************************************************************
     */
    virtual eError BitBlt
    (int x, int y, int width, int height, 
     HDC hdc, int dc_x, int dc_y, DWORD rop=SRCCOPY)
    {
        eError error=e_ERROR_NOT_ATTACHED;

        if (m_handle)
        {
            if (::BitBlt
                (m_handle, x, y, width, height, 
                 hdc, dc_x, dc_y, rop))
                return e_ERROR_NONE;

            error = e_ERROR_FAILED;
        }
        return error;
    }
};

#endif /* _CWINDC_HXX */


