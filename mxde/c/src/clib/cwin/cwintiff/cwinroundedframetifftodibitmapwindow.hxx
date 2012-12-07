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
 *   File: cwinroundedframetifftodibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
#if !defined(_CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_HXX) || defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_HXX) && !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_HXX
#endif /* !defined(_CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_HXX) && !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwinroundedframedibitmapwindow.hxx"
#include "cwintifftodibitmapwindow.hxx"
#include "cwintiffreader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinRoundedFrameTIFFToDIBitmapWindow;
/**
 **********************************************************************
 * Typedef: cWinRoundedFrameTIFFToDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 12/31/2009
 **********************************************************************
 */
typedef cWinTIFFToDIBitmapWindowT
<cWinRoundedFrameTIFFToDIBitmapWindow,
 cWinRoundedFrameDIBitmapWindow>
cWinRoundedFrameTIFFToDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinRoundedFrameTIFFToDIBitmapWindow
 *
 * Author: $author$
 *   Date: 12/31/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRoundedFrameTIFFToDIBitmapWindow
: public cWinRoundedFrameTIFFToDIBitmapWindowExtend
{
public:
    typedef cWinRoundedFrameTIFFToDIBitmapWindowExtend cExtends;
    
    /**
     **********************************************************************
     *  Constructor: cWinRoundedFrameTIFFToDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 12/31/2009
     **********************************************************************
     */
    cWinRoundedFrameTIFFToDIBitmapWindow
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
     *  Constructor: cWinRoundedFrameTIFFToDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 12/31/2009
     **********************************************************************
     */
    cWinRoundedFrameTIFFToDIBitmapWindow
    (const TCHAR* fileNameChars,
     COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
        m_fileNameChars = fileNameChars;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRoundedFrameTIFFToDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 12/31/2009
     **********************************************************************
     */
    virtual ~cWinRoundedFrameTIFFToDIBitmapWindow()
    {
    }
#else /* !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_HXX) || defined(CWINROUNDEDFRAMETIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */
