/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwinmaindialog.hxx
 *
 * Author: $author$
 *   Date: 5/18/2009
 **********************************************************************
 */
#ifndef _CWINMAINDIALOG_HXX
#define _CWINMAINDIALOG_HXX

#include "cwindialog.hxx"
#include "cstring.hxx"
#include "ctypes.hxx"

/**
 **********************************************************************
 *  Class: cWinMainDialog
 *
 * Author: $author$
 *   Date: 5/18/2009
 **********************************************************************
 */
class cWinMainDialog
: public cWinDialog
{
public:
    typedef cWinDialog cExtends;
    typedef cWinMainDialog cDerives;

    cString m_cmdLine;

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance,
     HINSTANCE hPrevinst,
     LPCMDLINE cmdLine,
     INT cmdShow,
     INT id,
     HWND hWndParent=NULL) 
    {
        eError error = e_ERROR_FAILED;
        TLENGTH length;

        if (!hWndParent)
        if (!(hWndParent = GetDesktopWindow()))
            return error;

        if (cmdLine)
        if (0 > (length = m_cmdLine.Assign(cmdLine)))
            return error = -length;

        error = cExtends::Create(hInstance, hWndParent, id);
        return error;
    }

    /**
     **********************************************************************
     * Function: FirstCmdLineArg
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual const CHAR* FirstCmdLineArg
    (TLENGTH& length) const 
    {
        const CHAR* chars = 0;

        if ((chars = m_cmdLine.HasChars(length)))
        if (0 > (length = cCHARS::Count(chars, ' ', length)))
            chars = 0;
        return chars;
    }
    /**
     **********************************************************************
     * Function: NextCmdLineArg
     *
     *   Author: $author$
     *     Date: 5/18/2009
     **********************************************************************
     */
    virtual const CHAR* NextCmdLineArg
    (TLENGTH& length, const CHAR* prevChars) const 
    {
        const CHAR* chars = 0;
        return chars;
    }
};
#endif /* _CWINMAINDIALOG_HXX */
