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
 *   File: cwindialogwindowclass.hxx
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
#ifndef _CWINDIALOGWINDOWCLASS_HXX
#define _CWINDIALOGWINDOWCLASS_HXX

#include "cwinwindowclass.hxx"

#define CWINDIALOGWINDOWCLASS_CLASSNAME_CHARS "cWinDialogWindowClass"

/**
 **********************************************************************
 *  Class: cWinDialogWindowClass
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDialogWindowClass
: public cWinWindowClass
{
public:
    typedef cWinWindowClass cExtends;
    typedef cWinDialogWindowClass cDerives;

    /**
     **********************************************************************
     * Constructor: cWinDialogWindowClass
     *
     *      Author: $author$
     *        Date: 5/8/2009
     **********************************************************************
     */
    cWinDialogWindowClass
    (LPCTSTR windowClassNameChars=_T
     (CWINDIALOGWINDOWCLASS_CLASSNAME_CHARS),
     WNDPROC wndProc=DefDlgProc,
     int windowExtra=WindowExtra(),
     int windowExtraOffset=WindowExtraOffset()) 
    : cExtends
      (windowClassNameChars, wndProc, 
       windowExtra, windowExtraOffset)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDialogWindowClass
     *
     *     Author: $author$
     *       Date: 5/8/2009
     **********************************************************************
     */
    virtual ~cWinDialogWindowClass()
    {
    }

    /**
     **********************************************************************
     * Function: WindowExtra
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    static int WindowExtra() 
    {
        int count = WindowExtraOffset()+(int)(sizeof(cWinInterfaceBase*));
        return count;
    }
    /**
     **********************************************************************
     * Function: WindowExtraOffset
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    static int WindowExtraOffset() 
    {
        int count = DLGWINDOWEXTRA;
        return count;
    }
};
#endif /* _CWINDIALOGWINDOWCLASS_HXX */
