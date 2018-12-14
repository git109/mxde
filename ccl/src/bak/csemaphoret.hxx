/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: csemaphoret.hxx
 *
 * Author: $author$
 *   Date: 11/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSEMAPHORET_HXX
#define _CSEMAPHORET_HXX

#if defined(WIN32)
#include <windows.h>
#define SEMAPHORE HANDLE
#define INVALID_SEMAPHORE NULL
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cSemaphoreT
 *
 * Author: $author$
 *   Date: 11/26/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cSemaphoreT
: public cOpenedHandleT<SEMAPHORE, INVALID_SEMAPHORE, TIs>
{
public:
    typedef cOpenedHandleT<SEMAPHORE, INVALID_SEMAPHORE, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cSemaphoreT
     *
     *      Author: $author$
     *        Date: 11/26/2003
     **********************************************************************
     */
    cSemaphoreT(SEMAPHORE handle=INVALID_SEMAPHORE, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cSemaphoreT
     *
     *     Author: $author$
     *       Date: 11/26/2003
     **********************************************************************
     */
    virtual ~cSemaphoreT()
    {
        eError error;

        if (opened)
        if ((error = Close()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Create()
    {
#if defined(WIN32)
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Open()
    {
#if defined(WIN32)
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Close()
    {
        SEMAPHORE handle=m_handle;

        if (INVALID_SEMAPHORE == m_handle)
            return e_ERROR_NOT_ATTACHED;

        m_opened = FALSE;
        m_handle = INVALID_HANDLE;

#if defined(WIN32)
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Lock
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Lock()
    {
        if (INVALID_SEMAPHORE == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Unlock
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Unlock()
    {
        if (INVALID_SEMAPHORE == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
};

#endif /* ndef _CSEMAPHORET_HXX */
