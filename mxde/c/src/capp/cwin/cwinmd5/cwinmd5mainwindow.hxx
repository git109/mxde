/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cwinmd5mainwindow.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINMD5MAINWINDOW_HXX) || defined(CWINMD5MAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINMD5MAINWINDOW_HXX) && !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY)
#define _CWINMD5MAINWINDOW_HXX
#endif /* !defined(_CWINMD5MAINWINDOW_HXX) && !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY)
#include "cwincryptohashmainwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CWINMD5MAINWINDOW_CAPTION "WinMD5"
/**
 **********************************************************************
 * Typedef: cWinMD5MainWindowExtend
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cWinCryptoHashMainWindowDeriveT<cMD5>
cWinMD5MainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinMD5MainWindow
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinMD5MainWindow
: public cWinMD5MainWindowExtend
{
public:
    typedef cWinMD5MainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMD5MainWindow
     *
     *       Author: $author$
     *         Date: 8/1/2010
     **********************************************************************
     */
    cWinMD5MainWindow
    (const TCHAR* captionText=_T(CWINMD5MAINWINDOW_CAPTION),
     COLORREF bgColor=CWINCRYPTOHASHMAINWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINCRYPTOHASHMAINWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends
      (captionText, bgColor, 
       hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
#else /* !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINMD5MAINWINDOW_HXX) || defined(CWINMD5MAINWINDOW_MEMBERS_ONLY) */
