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
 *   File: cthreadt.hxx
 *
 * Author: $author$
 *   Date: 11/10/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTHREADT_HXX
#define _CTHREADT_HXX

#if defined(WIN32)
#include <windows.h>
#define THREAD HANDLE
#define INVALID_THREAD NULL
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cThreadT
 *
 * Author: $author$
 *   Date: 11/10/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cThreadT
: public cOpenedHandleT<THREAD, (int)INVALID_THREAD, TIs>
{
public:
    typedef cOpenedHandleT<THREAD, (int)INVALID_THREAD, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cThreadT
     *
     *      Author: $author$
     *        Date: 11/10/2003
     **********************************************************************
     */
    cThreadT(THREAD thread=INVALID_THREAD, bool opened=false) 
    : cIs(thread, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cThreadT
     *
     *     Author: $author$
     *       Date: 11/10/2003
     **********************************************************************
     */
    virtual ~cThreadT()
    {
    }

    /**
     **********************************************************************
     * Function: AttachCurrent
     *
     *   Author: $author$
     *     Date: 11/11/2003
     **********************************************************************
     */
    virtual eError AttachCurrent()
    {
        if (INVALID_THREAD != m_handle)
            return e_ERROR_ALREADY_ATTACHED;

        if (INVALID_THREAD == (m_handle = GetCurrentThread()))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
};

#endif
