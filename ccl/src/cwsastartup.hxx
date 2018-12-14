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
 *   File: cwsastartup.hxx
 *
 * Author: $author$
 *   Date: 10/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWSASTARTUP_HXX
#define _CWSASTARTUP_HXX

#if defined(WIN32)
#include <windows.h>

#include "csingleinstancet.hxx"

/**
 **********************************************************************
 *  Class: cWSAStartup
 *
 * Author: $author$
 *   Date: 10/26/2003
 **********************************************************************
 */
class cWSAStartup
: public cSingleInstanceT<cWSAStartup>
{
public:
    typedef cSingleInstanceT<cWSAStartup> cIs;

    int m_startup;
    int m_version;
    WSADATA m_data;

    /**
     **********************************************************************
     * Constructor: cWSAStartup
     *
     *      Author: $author$
     *        Date: 10/26/2003
     **********************************************************************
     */
    cWSAStartup(int version = 0x0002)
    : cIs(this),
      m_version(version),
      m_startup(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWSAStartup
     *
     *     Author: $author$
     *       Date: 10/26/2003
     **********************************************************************
     */
    virtual ~cWSAStartup()
    {
        eError error;

        if (m_startup > 0)
        if ((error = Cleanup()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Startup
     *
     *   Author: $author$
     *     Date: 10/26/2003
     **********************************************************************
     */
    virtual eError Startup()
    {
        int err;

        if (m_startup < 0)
            return e_ERROR_NONE;

        if (++m_startup > 1)
            return e_ERROR_NONE;

        if ((err = WSAStartup(m_version, &m_data)))
        {
            --m_startup;
            return e_ERROR_FAILED;
        }

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Cleanup
     *
     *   Author: $author$
     *     Date: 10/26/2003
     **********************************************************************
     */
    virtual eError Cleanup()
    {
        int err;

        if (m_startup <= 0)
            return e_ERROR_NONE;

        if (--m_startup > 0)
            return e_ERROR_NONE;

        if ((err = WSACleanup()))
            return e_ERROR_FAILED;

        return e_ERROR_NONE;
    }
};
#endif /* defined(WIN32) */

#endif /* ndef _CWSASTARTUP_HXX */
