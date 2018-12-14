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
 *   File: cwinsecurity.hxx
 *
 * Author: $author$
 *   Date: 10/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINSECURITY_HXX
#define _CWINSECURITY_HXX

#if defined(WIN32)
#include <windows.h>
/**
 **********************************************************************
 *  Class: cWinSecurityAttributes
 *
 * Author: $author$
 *   Date: 10/29/2004
 **********************************************************************
 */
class cWinSecurityAttributes
: public SECURITY_ATTRIBUTES
{
public:
    typedef SECURITY_ATTRIBUTES cIs;

    /**
     **********************************************************************
     * Constructor: cWinSecurityAttributes
     *
     *      Author: $author$
     *        Date: 10/29/2004
     **********************************************************************
     */
    cWinSecurityAttributes() 
    {
        memset((cIs*)this, 0, sizeof(cIs));
        nLength = sizeof(cIs);
    }

    /**
     **********************************************************************
     * Function: SetInheritHandle
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    BOOL SetInheritHandle(BOOL on=TRUE) 
    {
        bInheritHandle = on;
        return bInheritHandle;
    }
    /**
     **********************************************************************
     * Function: GetInheritHandle
     *
     *   Author: $author$
     *     Date: 10/29/2004
     **********************************************************************
     */
    BOOL GetInheritHandle() const
    {
        return bInheritHandle;
    }
};
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#endif /* ndef _CWINSECURITY_HXX */
