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
 *   File: cwinbrush.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINBRUSH_HXX
#define _CWINBRUSH_HXX

#include "cwingdi.hxx"
#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinBrush
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinBrush
: public cHandleIsHandleT<HBRUSH, NULL, cWinGDIObject>
{
public:
    typedef cHandleIsHandleT<HBRUSH, NULL, cWinGDIObject> cIs;

    /**
     **********************************************************************
     * Constructor: cWinBrush
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinBrush(HBRUSH handle=NULL, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinBrush
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinBrush(int id) 
    {
        eError error;

        if ((error = GetStock(id)))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: GetStock
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError GetStock(int id)
    {
        eError error;

        if (!(error = cIs::GetStock(id)))
            m_handle = (HBRUSH)cHandleIs::GetHandle();

        return error;
    }
    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError CreateSolid(BYTE red, BYTE green, BYTE blue)
    {
        return CreateSolid(RGB(red, green, blue));
    }
    /**
     **********************************************************************
     * Function: CreateSolid
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError CreateSolid(COLORREF color)
    {
        eError error=e_ERROR_FAILED;
        HBRUSH handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (handle = CreateSolidBrush(color)))
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
};

#endif /* _CWINBRUSH_HXX */


