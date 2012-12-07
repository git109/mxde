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
 *   File: cwinroundedframeimagetodibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_HXX) || defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_HXX) && !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_HXX) && !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwinroundedframedibitmapwindow.hxx"
#include "cwinimagetodibitmapwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinRoundedFrameImageToDIBitmapWindow;
/**
 **********************************************************************
 * Typedef: cWinRoundedFrameImageToDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cWinImageToDIBitmapWindowT
<cWinRoundedFrameImageToDIBitmapWindow,
 cWinRoundedFrameDIBitmapWindow>
cWinRoundedFrameImageToDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameImageToDIBitmapWindow
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRoundedFrameImageToDIBitmapWindow
: public cWinRoundedFrameImageToDIBitmapWindowExtend
{
public:
    typedef cWinRoundedFrameImageToDIBitmapWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameImageToDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 1/13/2010
     **********************************************************************
     */
    cWinRoundedFrameImageToDIBitmapWindow
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
     *  Destructor: ~cWinRoundedFrameImageToDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cWinRoundedFrameImageToDIBitmapWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_HXX) || defined(CWINROUNDEDFRAMEIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */
