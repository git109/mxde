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
 *   File: cwinroundedframedibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEDIBITMAPWINDOW_HXX) || defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEDIBITMAPWINDOW_HXX) && !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEDIBITMAPWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEDIBITMAPWINDOW_HXX) && !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwinroundedframewindow.hxx"
#include "cwindibitmapwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinRoundedFrameDIBitmapWindow;
/**
 **********************************************************************
 * Typedef: cWinRoundedFrameDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 12/31/2009
 **********************************************************************
 */
typedef cWinDIBitmapWindowT
<cWinRoundedFrameDIBitmapWindow, cWinRoundedFrameWindow>
cWinRoundedFrameDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameDIBitmapWindow
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRoundedFrameDIBitmapWindow
: public cWinRoundedFrameDIBitmapWindowExtend
{
public:
    typedef cWinRoundedFrameDIBitmapWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 12/31/2009
     **********************************************************************
     */
    cWinRoundedFrameDIBitmapWindow
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
     *  Destructor: ~cWinRoundedFrameDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 12/31/2009
     **********************************************************************
     */
    virtual ~cWinRoundedFrameDIBitmapWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEDIBITMAPWINDOW_HXX) || defined(CWINROUNDEDFRAMEDIBITMAPWINDOW_MEMBERS_ONLY) */
