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
 *   File: cwindibitmapfilewindow.hxx
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
#if !defined(_CWINDIBITMAPFILEWINDOW_HXX) || defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#if !defined(_CWINDIBITMAPFILEWINDOW_HXX) && !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#define _CWINDIBITMAPFILEWINDOW_HXX
#endif /* !defined(_CWINDIBITMAPFILEWINDOW_HXX) && !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY)
#include "cwindibitmapwindow.hxx"
#include "cwindibitmapfilereader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDIBitmapFileWindowExtend
 *
 *  Author: $author$
 *    Date: 12/18/2009
 **********************************************************************
 */
typedef cWinDIBitmapWindow
cWinDIBitmapFileWindowExtend;
/**
 **********************************************************************
 *  Class: cWinDIBitmapFileWindow
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDIBitmapFileWindow
: virtual public cWinBitmapFileReaderEventsImplement,
  public cWinDIBitmapFileWindowExtend
{
public:
    typedef cWinDIBitmapFileWindowExtend cExtends;
    typedef cWinDIBitmapFileWindow cDerives;
    
    const TCHAR* m_bitmapFileNameChars;
    
    cWinDC m_diBitmapDC;
    cWinBitmapInfo m_diBitmapInfo;
    cWinDIBitmapFileReader m_diBitmapFileReader;
    
    /**
     **********************************************************************
     *  Constructor: cWinDIBitmapFileWindow
     *
     *       Author: $author$
     *         Date: 12/18/2009
     **********************************************************************
     */
    cWinDIBitmapFileWindow
    (const TCHAR* bitmapFileNameChars=0,
     COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
      
      m_bitmapFileNameChars(bitmapFileNameChars),
      
      m_diBitmapFileReader
      (m_diBitmapDC, m_diBitmap, m_diBitmapInfo,
       ((cWinBitmapFileReaderEventsInterface*)(this)))
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDIBitmapFileWindow
     *
     *      Author: $author$
     *        Date: 12/18/2009
     **********************************************************************
     */
    virtual ~cWinDIBitmapFileWindow()
    {
    }
#else /* !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINDIBITMAPFILEWINDOW_HXX) || defined(CWINDIBITMAPFILEWINDOW_MEMBERS_ONLY) */
