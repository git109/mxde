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
 *   File: cwinimagemainwindow.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CWINIMAGEMAINWINDOW_HXX) || defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGEMAINWINDOW_HXX) && !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY)
#define _CWINIMAGEMAINWINDOW_HXX
#endif /* !defined(_CWINIMAGEMAINWINDOW_HXX) && !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY)
#include "cwinimagetodibitmapmainwindow.hxx"
#include "cimagereaderinterface.hxx"
#include "cstaicimagereaderlist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinImageMainWindowExtend
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cWinImageToDIBitmapMainWindow
cWinImageMainWindowExtend;
/**
 **********************************************************************
 *  Class: cWinImageMainWindow
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinImageMainWindow
: //virtual public cWinImageMainWindowImplement,
  public cWinImageMainWindowExtend
{
public:
    //typedef cWinImageMainWindowImplement cImplements;
    typedef cWinImageMainWindowExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinImageMainWindow
     *
     *       Author: $author$
     *         Date: 11/12/2010
     **********************************************************************
     */
    cWinImageMainWindow
    (COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     bool hasDropShadow=true,
     bool isLayeredWindow=false,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hasDropShadow, isLayeredWindow,
       hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageMainWindow
     *
     *      Author: $author$
     *        Date: 11/12/2010
     **********************************************************************
     */
    virtual ~cWinImageMainWindow()
    {
    }
#else /* !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: GetImageReader
     *
     *   Author: $author$
     *     Date: 11/12/2010
     **********************************************************************
     */
    virtual tImageReaderInterface* GetImageReader
    (eError& error,
     const CHAR* fileName,
     tImageReaderEventsInterface* delegated=0) 
    {
        tImageReaderInterface* reader = 0;
        cStaicImageReaderList& readerList = cStaicImageReaderList::m_instance;
        cImageReaderItem* readerItem;
        
        for (readerItem = readerList.GetFirstItem(); 
             readerItem; readerItem = readerItem->GetNextItem())
        {
            if (!(error = readerItem->m_imageReader.Accept(fileName)))
            if (delegated = (readerItem->m_imageReader.Delegate(delegated)))
                return reader = &readerItem->m_imageReader;
        }
        return reader;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEMAINWINDOW_HXX) || defined(CWINIMAGEMAINWINDOW_MEMBERS_ONLY) */
