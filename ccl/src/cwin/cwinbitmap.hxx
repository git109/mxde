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
 *   File: cwinbitmap.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINBITMAP_HXX
#define _CWINBITMAP_HXX

#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinBitmap
 *
 * Author: $author$
 *   Date: 4/8/2004
 **********************************************************************
 */
class cWinBitmap
: public cHandleIsHandleT<HBITMAP, NULL, cWinGDIObject>
{
public:
    typedef cHandleIsHandleT<HBITMAP, NULL, cWinGDIObject> cIs;

    int m_width, m_height;

    /**
     **********************************************************************
     * Constructor: cWinBitmap
     *
     *      Author: $author$
     *        Date: 4/8/2004
     **********************************************************************
     */
    cWinBitmap
    (HBITMAP handle=NULL, bool created=false,
     int width=-1, int height=-1) 
    : cIs(handle, created),
      m_width(width),
      m_height(height)
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual eError Create(HDC hdc, int width, int height)
    {
        eError error=e_ERROR_FAILED;
        HBITMAP handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (handle = CreateCompatibleBitmap
            (hdc, width, height)))
        {
            if ((error = Attach(handle)))
                DeleteObject(handle);
            else
            {
                m_width = width;
                m_height = height;
                m_created = true;
                error = e_ERROR_NONE;
            }
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Load
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    virtual eError Load
    (HINSTANCE instance, LPCTSTR name)
    {
        eError error=e_ERROR_FAILED;
        HBITMAP handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (handle = LoadBitmap(instance, name)))
        {
            if ((error = Attach(handle)))
                DeleteObject(handle);
            else
            {
                m_created = true;
                error = e_ERROR_NONE;
            }
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: Load
     *
     *   Author: $author$
     *     Date: 4/8/2004
     **********************************************************************
     */
    inline eError Load(HINSTANCE instance, int id)
    {
        return Load(instance, MAKEINTRESOURCE(id));
    }
};

#endif /* _CWINBITMAP_HXX */


