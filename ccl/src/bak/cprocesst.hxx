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
 *   File: cprocesst.hxx
 *
 * Author: $author$
 *   Date: 11/10/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CPROCESST_HXX
#define _CPROCESST_HXX

#if defined(WIN32)
#include <windows.h>
#define PROCESS HANDLE
#define INVALID_PROCESS NULL
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "chandlet.hxx"

/**
 **********************************************************************
 *  Class: cProcessT
 *
 * Author: $author$
 *   Date: 11/10/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cProcessT
: public cOpenedHandleT<PROCESS, (int)INVALID_PROCESS, TIs>
{
public:
    typedef cOpenedHandleT<PROCESS, (int)INVALID_PROCESS, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cProcessT
     *
     *      Author: $author$
     *        Date: 11/10/2003
     **********************************************************************
     */
    cProcessT(PROCESS process=INVALID_PROCESS, bool opened=false) 
    : cIs(process, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cProcessT
     *
     *     Author: $author$
     *       Date: 11/10/2003
     **********************************************************************
     */
    virtual ~cProcessT()
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
        if (INVALID_PROCESS != m_handle)
            return e_ERROR_ALREADY_ATTACHED;

        if (INVALID_PROCESS == (m_handle = GetCurrentProcess()))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
};

#endif
