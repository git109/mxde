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
 *   File: cwinshapeddibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 1/23/2010
 **********************************************************************
 */
#if !defined(_CWINSHAPEDDIBITMAPWINDOW_HXX) || defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINSHAPEDDIBITMAPWINDOW_HXX) && !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINSHAPEDDIBITMAPWINDOW_HXX
#endif /* !defined(_CWINSHAPEDDIBITMAPWINDOW_HXX) && !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwindibitmapwindow.hxx"
#include "cwinshapedwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinShapedDIBitmapWindow;
/**
 **********************************************************************
 * Typedef: cWinShapedDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 1/23/2010
 **********************************************************************
 */
typedef cWinDIBitmapWindowT
<cWinShapedDIBitmapWindow, cWinShapedWindow>
cWinShapedDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinShapedDIBitmapWindow
 *
 * Author: $author$
 *   Date: 1/23/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinShapedDIBitmapWindow
: public cWinShapedDIBitmapWindowExtend
{
public:
    typedef cWinShapedDIBitmapWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinShapedDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 1/23/2010
     **********************************************************************
     */
    cWinShapedDIBitmapWindow
    (COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinShapedDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 1/23/2010
     **********************************************************************
     */
    virtual ~cWinShapedDIBitmapWindow()
    {
    }
#else /* !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINSHAPEDDIBITMAPWINDOW_HXX) || defined(CWINSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */
