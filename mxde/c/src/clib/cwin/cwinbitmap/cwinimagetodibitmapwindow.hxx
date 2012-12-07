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
 *   File: cwinimagetodibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CWINIMAGETODIBITMAPWINDOW_HXX) || defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINIMAGETODIBITMAPWINDOW_HXX) && !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINIMAGETODIBITMAPWINDOW_HXX
#endif /* !defined(_CWINIMAGETODIBITMAPWINDOW_HXX) && !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
#include "cimagereaderinterface.hxx"
#include "cimagereadereventsinterface.hxx"
#include "cwindibitmapwindow.hxx"
#include "cwinbitmapinfoheader.hxx"
#include "cwinbitmapinfo.hxx"
#include "cwindropfiles.hxx"
#include "cwindc.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinImageToDIBitmapWindow;

#undef CDB_CLASS
#define CDB_CLASS "cWinImageToDIBitmapWindowT"
/**
 **********************************************************************
 *  Class: cWinImageToDIBitmapWindowT
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
template
<class TDerives=cWinImageToDIBitmapWindow,
 class TWinImageToDIBitmapWindowExtend=cWinDIBitmapWindow,
 class TImageReaderInterface=cImageReaderInterface,
 class TImageReaderEventsInterface=cImageReaderEventsInterface,
 class TImageReaderEventsImplement=cImageReaderEventsImplement,
 class TImplements=TImageReaderEventsImplement,
 class TExtends=TWinImageToDIBitmapWindowExtend>

class c_EXPORT_CLASS cWinImageToDIBitmapWindowT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    
    typedef TImageReaderInterface tImageReaderInterface;
    typedef TImageReaderEventsInterface tImageReaderEventsInterface;
    
    const TCHAR* m_fileNameChars;
    
    cWinBITMAPINFOHEADER m_diBitmapInfoHeader;
    cWinBitmapInfo m_diBitmapInfo;
    cWinDC m_diBitmapDC;

    BYTE* m_diBitmapRowByte;
    TSIZE m_diBitmapRowBytes;
        
    /**
     **********************************************************************
     *  Constructor: cWinImageToDIBitmapWindowT
     *
     *       Author: $author$
     *         Date: 1/13/2010
     **********************************************************************
     */
    cWinImageToDIBitmapWindowT
    (COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_fileNameChars(0),
      
      m_diBitmapRowByte(0),
      m_diBitmapRowBytes(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinImageToDIBitmapWindowT
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cWinImageToDIBitmapWindowT()
    {
    }
#else /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const TCHAR* fileNameChars=0) 
#if defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        tImageReaderInterface* reader;
        eError error;
        HWND hWnd;
        HDC hDC;
        
        if (!(fileNameChars))
            fileNameChars = m_fileNameChars;
            
        if ((fileNameChars))
        if ((reader = GetImageReader
             (error, fileNameChars, 
              (tImageReaderEventsInterface*)(this))))
        {
            if ((hWnd = Attached()))
            if ((hDC = GetDC(hWnd)))
            {
                bool isCreated = m_diBitmap.IsCreated();
                HBITMAP hBitmap = m_diBitmap.Detach();
                
                if ((m_diBitmapDC.Attach(hDC)))
                {
                    if (0 > (count = reader->Read(fileNameChars)))
                    {
                        m_diBitmap.Attach(hBitmap);
                        m_diBitmap.SetIsCreated(isCreated);
                    }
                    m_diBitmapDC.Detach();
                }
                ReleaseDC(hWnd, hDC);
            }
            error = FreeImageReader(*reader);
        }
#else /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetImageReader
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual tImageReaderInterface* GetImageReader
    (eError& error,
     const WCHAR* fileName,
     tImageReaderEventsInterface* delegated=0) 
#if defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        tImageReaderInterface* reader = 0;
        TLENGTH length;
        const CHAR* chars;
        cString fileNameString;
        if (0 < (length = fileNameString.AssignW(fileName)))
        if ((chars = fileNameString.HasChars(length)))
            reader = GetImageReader(error, chars, delegated); 
#if !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return reader;
    }
#endif /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetImageReader
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual tImageReaderInterface* GetImageReader
    (eError& error,
     const CHAR* fileName,
     tImageReaderEventsInterface* delegated=0) 
#if defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        tImageReaderInterface* reader = 0;
#if !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return reader;
    }
#endif /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: FreeImageReader
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError FreeImageReader
    (tImageReaderInterface& reader) 
#if defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINIMAGETODIBITMAPWINDOW_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On_WM_DROPFILES_WindowMessage
     *
     *   Author: $author$
     *     Date: 1/6/2010
     **********************************************************************
     */
    virtual LRESULT On_WM_DROPFILES_WindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam)
    {
        LRESULT lResult = 0;
        const TCHAR* fileNameChars;
        TLENGTH length;
        HDROP hDrop;
        cWinDropFiles dropFiles;
        
        if ((hDrop = (HDROP)(wParam)))
        if (0 < (length = dropFiles.Open(hDrop)))
        {
            if ((fileNameChars = dropFiles.GetFirstFileName(length)))
                Read(fileNameChars);
                
            dropFiles.Close();
        }
        lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        return lResult;
    }
    /**
     **********************************************************************
     * Function: OnImagePixel
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnImagePixel
    (cImagePixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageCol, TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        RGBTRIPLE* rgb;
        if ((rgb = (m_diBitmapRowByte)?
            ((RGBTRIPLE*)(m_diBitmapRowByte)+imageCol):(0)))
        {
            rgb->rgbtRed = pixel.Red();
            rgb->rgbtGreen = pixel.Green();
            rgb->rgbtBlue = pixel.Blue();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginImageRow
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnBeginImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;        
        if ((m_diBitmapRowByte = m_diBitmap.Row
            (length, imageHeight-imageRow-1)))
            m_diBitmapRowBytes = length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndImageRow
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnEndImageRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imagePlane, 
     TSIZE imagePlanes, TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        m_diBitmapRowByte = 0;
        m_diBitmapRowBytes = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginImage
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnBeginImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        BITMAPINFO* bmi;
        HDC hDC;
        
        m_diBitmapInfoHeader.biPlanes = 1;
        m_diBitmapInfoHeader.biHeight = imageHeight;
        m_diBitmapInfoHeader.biWidth = imageWidth;
        m_diBitmapInfoHeader.biBitCount = 24;
        m_diBitmapInfoHeader.biClrUsed = 0;
        
        if (!(error = m_diBitmapInfo.Allocate(m_diBitmapInfoHeader)))
        {
            error = e_ERROR_NOT_ATTACHED;

            if ((bmi = m_diBitmapInfo.Attached()))
            if ((hDC = m_diBitmapDC.Attached()))
                error = m_diBitmap.Create(*bmi, hDC);

            if ((error2 = m_diBitmapInfo.Free()))
            if (!error)
                error = error2;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndImage
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual eError OnEndImage
    (TSIZE imagePlanes, 
     TSIZE imageHeight, TSIZE imageWidth,
     TSIZE valuesPerPixel, TSIZE bitsPerValue,
     eImagePixelValueInterpretation pixelValueInterpretation) 
    {
        eError error = e_ERROR_NONE;
        HBITMAP hBitmap;
        if ((hBitmap = m_diBitmap.Attached()))
            SizeClientArea(imageWidth,imageHeight,TRUE);
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinImageToDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cWinImageToDIBitmapWindowT
<cWinImageToDIBitmapWindow, cWinDIBitmapWindow>
cWinImageToDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinImageToDIBitmapWindow
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageToDIBitmapWindow
: public cWinImageToDIBitmapWindowExtend
{
public:
    typedef cWinImageToDIBitmapWindowExtend cExtends;
    typedef cWinImageToDIBitmapWindow cDerives;
    /**
     **********************************************************************
     * Constructor: cWinImageToDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    cWinImageToDIBitmapWindow
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
     * Destructor: ~cWinImageToDIBitmapWindow
     *
     *     Author: $author$
     *       Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cWinImageToDIBitmapWindow()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGETODIBITMAPWINDOW_HXX) || defined(CWINIMAGETODIBITMAPWINDOW_MEMBERS_ONLY) */
