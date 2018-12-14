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
 *   File: ceventt.hxx
 *
 * Author: $author$
 *   Date: 11/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CEVENTT_HXX
#define _CEVENTT_HXX

#if defined(WIN32)
#include <windows.h>
#define EVENT HANDLE
#define INVALID_EVENT NULL
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cEventT
 *
 * Author: $author$
 *   Date: 11/26/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cEventT
: public cOpenedHandleT<EVENT, INVALID_EVENT, TIs>
{
public:
    typedef cOpenedHandleT<EVENT, INVALID_EVENT, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cEventT
     *
     *      Author: $author$
     *        Date: 11/26/2003
     **********************************************************************
     */
    cEventT(EVENT handle=INVALID_EVENT, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cEventT
     *
     *     Author: $author$
     *       Date: 11/26/2003
     **********************************************************************
     */
    virtual ~cEventT()
    {
        eError error;

        if (m_opened)
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
    virtual eError Create
    (bool is_manual_reset=false, bool is_initially_set=false)
    {
        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

#if defined(WIN32)
        LPSECURITY_ATTRIBUTES security_attributes=NULL;
        LPCTSTR named=NULL;

        if (INVALID_EVENT != (m_handle = CreateEvent
            (security_attributes, is_manual_reset, 
             is_initially_set, named)))
        {
            m_opened = true;
            return e_ERROR_NONE;
        }
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
        if (m_opened)
            return e_ERROR_ALREADY_OPEN;

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
        EVENT handle=m_handle;

        if (INVALID_EVENT == m_handle)
            return e_ERROR_NOT_ATTACHED;

        m_opened = FALSE;
        m_handle = INVALID_EVENT;

#if defined(WIN32)
        if (CloseHandle(m_handle))
            return e_ERROR_NONE;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Wait
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Wait(int milliseconds=-1)
    {
        if (INVALID_EVENT == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        DWORD dw_milliseconds=(milliseconds>=0)?milliseconds:INFINITE;

        switch(WaitForSingleObject(m_handle, dw_milliseconds))
        {
        case WAIT_ABANDONED:
            return e_ERROR_WAIT_ABANDONED;

        case WAIT_TIMEOUT:
            return e_ERROR_WAIT_TIMEOUT;

        case WAIT_OBJECT_0:
            return e_ERROR_NONE;
        }
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Set()
    {
        if (INVALID_EVENT == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        if (SetEvent(m_handle))
            return e_ERROR_NONE;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Reset
     *
     *   Author: $author$
     *     Date: 11/26/2003
     **********************************************************************
     */
    virtual eError Reset()
    {
        if (INVALID_EVENT == m_handle)
            return e_ERROR_NOT_ATTACHED;

#if defined(WIN32)
        if (ResetEvent(m_handle))
            return e_ERROR_NONE;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
};

#endif /* ndef _CEVENTT_HXX */
