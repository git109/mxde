/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: csockets.hxx
 *
 * Author: $author$
 *   Date: 10/13/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSOCKETS_HXX
#define _CSOCKETS_HXX

#include "cerror.hxx"

#if defined(WIN32) 
#include "cwsastartup.hxx"
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

/**
 **********************************************************************
 *  Class: cSockets
 *
 * Author: $author$
 *   Date: 10/13/2004
 **********************************************************************
 */
class cSockets
{
public:

#if defined(WIN32) 
    static cWSAStartup *m_wsa;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 10/13/2004
     **********************************************************************
     */
    static eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        
#if defined(WIN32)
        if (m_wsa)
            return e_ERROR_ALREADY_INITIALIZED;

        if ((m_wsa = cWSAStartup::GetInstance()))
        if ((error = m_wsa->Startup()))
        {
            m_wsa->FreeInstance();
            m_wsa = 0;
        }
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 10/13/2004
     **********************************************************************
     */
    static eError Finalize() 
    {
        eError error2, error = e_ERROR_NONE;
        
#if defined(WIN32) 
        if (!m_wsa)
            return e_ERROR_NOT_INITIALIZED;

        error = m_wsa->Cleanup();

        if ((error2 = m_wsa->FreeInstance()))
        if (!error)
            error = error2;

#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return error;
    }
};

#endif /* ndef _CSOCKETS_HXX */
