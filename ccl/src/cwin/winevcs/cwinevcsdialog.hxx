/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cwinevcsdialog.hxx
 *
 * Author: $author$
 *   Date: 6/7/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CWINEVCSDIALOG_HXX
#define _CWINEVCSDIALOG_HXX

#include "cwinobject.hxx"

/**
 **********************************************************************
 *  Class: cWinEvcsHelpDialog
 *
 * Author: $author$
 *   Date: 6/6/2007
 **********************************************************************
 */
class cWinEvcsHelpDialog
: public cWinDialog
{
public:
    typedef cWinDialog cExtends;
    typedef cWinEvcsHelpDialog cDerives;

    /**
     **********************************************************************
     * Constructor: cWinEvcsHelpDialog
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    cWinEvcsHelpDialog() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEvcsHelpDialog
     *
     *      Author: $author$
     *        Date: 6/6/2007
     **********************************************************************
     */
    virtual ~cWinEvcsHelpDialog()
    {
    }
    /**
     **********************************************************************
     * Function: OnWMInitDialog
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual BOOL OnWMInitDialog(WPARAM wparam, LPARAM lparam)
    {
        return TRUE;
    }
    /**
     **********************************************************************
     * Function: OnDialogOk
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual BOOL OnDialogOK(WPARAM wparam, LPARAM lparam)
    {
        return cExtends::OnDialogOK(wparam, lparam);
    }

    /**
     **********************************************************************
     * Function: Modal
     *
     *   Author: $author$
     *     Date: 6/6/2007
     **********************************************************************
     */
    virtual int Modal(HINSTANCE instance, HWND window, int id)
    {
        int result;
        result = cExtends::Modal(instance, window, id);
        return result;
    }
};

#endif /* _CWINEVCSDIALOG_HXX */
