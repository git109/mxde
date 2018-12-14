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
 *   File: cwinprocess.hxx
 *
 * Author: $author$
 *   Date: 10/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINPROCESS_HXX
#define _CWINPROCESS_HXX

#if defined(WIN32)
#include <windows.h>

/**
 **********************************************************************
 *  Class: cWinStartupInfo
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cWinStartupInfo
: public STARTUPINFO
{
public:
    typedef STARTUPINFO cIs;

    /**
     **********************************************************************
     * Constructor: cWinStartupInfo
     *
     *      Author: $author$
     *        Date: 10/28/2004
     **********************************************************************
     */
    cWinStartupInfo() 
    {
        memset((cIs*)this, 0, sizeof(cIs));
    }

    /**
     **********************************************************************
     * Function: SetStdInput
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    HANDLE SetStdInput(HANDLE handle) 
    {
        if ((hStdInput = handle))
            dwFlags |= STARTF_USESTDHANDLES;
        return hStdInput;
    }
    /**
     **********************************************************************
     * Function: SetStdOutput
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    HANDLE SetStdOutput(HANDLE handle) 
    {
        if ((hStdOutput = handle))
            dwFlags |= STARTF_USESTDHANDLES;
        return hStdOutput;
    }
    /**
     **********************************************************************
     * Function: SetStdError
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    HANDLE SetStdError(HANDLE handle) 
    {
        if ((hStdError = handle))
            dwFlags |= STARTF_USESTDHANDLES;
        return hStdError;
    }
};

/**
 **********************************************************************
 *  Class: cWinProcessInformation
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cWinProcessInformation
: public PROCESS_INFORMATION
{
public:
    typedef PROCESS_INFORMATION cIs;

    /**
     **********************************************************************
     * Constructor: cWinProcessInformation
     *
     *      Author: $author$
     *        Date: 10/28/2004
     **********************************************************************
     */
    cWinProcessInformation() 
    {
        memset((cIs*)this, 0, sizeof(cIs));
    }
};
#endif /* defined(WIN32) */

#endif /* ndef _CWINPROCESS_HXX */
