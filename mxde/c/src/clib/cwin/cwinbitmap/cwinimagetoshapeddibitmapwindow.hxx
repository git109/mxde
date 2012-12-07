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
 *   File: cwinimagetoshapeddibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 1/23/2010
 **********************************************************************
 */
#if !defined(_CWINIMAGETOSHAPEDDIBITMAPWINDOW_HXX) || defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGETOSHAPEDDIBITMAPWINDOW_HXX) && !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINIMAGETOSHAPEDDIBITMAPWINDOW_HXX
#endif /* !defined(_CWINIMAGETOSHAPEDDIBITMAPWINDOW_HXX) && !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwinimagetodibitmapwindow.hxx"
#include "cwinshapeddibitmapwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinImageToShapedDIBitmapWindow;
/**
 **********************************************************************
 * Typedef: cWinImageToShapedDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 1/23/2010
 **********************************************************************
 */
typedef cWinImageToDIBitmapWindowT
<cWinImageToShapedDIBitmapWindow, 
 cWinShapedDIBitmapWindow>
cWinImageToShapedDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinImageToShapedDIBitmapWindow
 *
 * Author: $author$
 *   Date: 1/23/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageToShapedDIBitmapWindow
: public cWinImageToShapedDIBitmapWindowExtend
{
public:
    typedef cWinImageToShapedDIBitmapWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinImageToShapedDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 1/23/2010
     **********************************************************************
     */
    cWinImageToShapedDIBitmapWindow
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
     *  Destructor: ~cWinImageToShapedDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 1/23/2010
     **********************************************************************
     */
    virtual ~cWinImageToShapedDIBitmapWindow()
    {
    }
#else /* !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGETOSHAPEDDIBITMAPWINDOW_HXX) || defined(CWINIMAGETOSHAPEDDIBITMAPWINDOW_MEMBERS_ONLY) */
