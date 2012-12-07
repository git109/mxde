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
 *   File: cwinpaintedwindow.hxx
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
#if !defined(_CWINPAINTEDWINDOW_HXX) || defined(CWINPAINTEDWINDOW_MEMBERS_ONLY)
#if !defined(_CWINPAINTEDWINDOW_HXX) && !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY)
#define _CWINPAINTEDWINDOW_HXX
#endif /* !defined(_CWINPAINTEDWINDOW_HXX) && !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY)
#include "cwinwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinPaintedWindowExtend
 *
 *  Author: $author$
 *    Date: 1/1/2010
 **********************************************************************
 */
typedef cWinWindow
cWinPaintedWindowExtend;
/**
 **********************************************************************
 *  Class: cWinPaintedWindow
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinPaintedWindow
: public cWinPaintedWindowExtend
{
public:
    typedef cWinPaintedWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinPaintedWindow
     *
     *       Author: $author$
     *         Date: 1/1/2010
     **********************************************************************
     */
    cWinPaintedWindow
    (COLORREF bgColor=0,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=0,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false)
    : cExtends(hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinPaintedWindow
     *
     *      Author: $author$
     *        Date: 1/1/2010
     **********************************************************************
     */
    virtual ~cWinPaintedWindow()
    {
    }
#else /* !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY) */

#if !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINPAINTEDWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINPAINTEDWINDOW_HXX) || defined(CWINPAINTEDWINDOW_MEMBERS_ONLY) */
