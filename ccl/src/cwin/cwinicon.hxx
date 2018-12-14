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
 *   File: cwinicon.hxx
 *
 * Author: $author$
 *   Date: 1/28/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINICON_HXX
#define _CWINICON_HXX

#include "cwinhandle.hxx"

/**
 **********************************************************************
 *  Class: cWinIcon
 *
 * Author: $author$
 *   Date: 1/25/2004
 **********************************************************************
 */
class cWinIcon
: public cCreatedHandleT<HICON, NULL>
{
public:
    typedef cCreatedHandleT<HICON, NULL> cIs;

    /**
     **********************************************************************
     * Constructor: cWinIcon
     *
     *      Author: $author$
     *        Date: 1/25/2004
     **********************************************************************
     */
    cWinIcon(HICON icon=NULL, bool created=false) 
    : cIs(icon, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinIcon
     *
     *     Author: $author$
     *       Date: 1/25/2004
     **********************************************************************
     */
    virtual ~cWinIcon()
    {
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Create(HINSTANCE instance, WORD id)
    {
        eError error=e_ERROR_FAILED;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (NULL != (m_handle = LoadIcon(instance, MAKEINTRESOURCE(id))))
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
     *     Date: 1/25/2004
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error=e_ERROR_FAILED;

        if (NULL == m_handle)
            return e_ERROR_NOT_ATTACHED;

        if (DestroyIcon(m_handle))
            error = e_ERROR_NONE;

        m_handle = NULL;
        m_created = false;
        return error;
    }
};

#endif /* _CWINICON_HXX */


