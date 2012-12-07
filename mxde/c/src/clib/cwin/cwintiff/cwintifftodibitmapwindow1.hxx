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
 *   File: cwintifftodibitmapwindow.hxx
 *
 * Author: $author$
 *   Date: 12/25/2009
 **********************************************************************
 */
#if !defined(_CWINTIFFTODIBITMAPWINDOW_HXX) || defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
#if !defined(_CWINTIFFTODIBITMAPWINDOW_HXX) && !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
#define _CWINTIFFTODIBITMAPWINDOW_HXX
#endif /* !defined(_CWINTIFFTODIBITMAPWINDOW_HXX) && !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
#include "cwindibitmapwindow.hxx"
#include "cwinbitmapinfoheader.hxx"
#include "cwinbitmapinfo.hxx"
#include "cwindc.hxx"
#include "cwintiffreadereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinTIFFToDIBitmapWindowExtend
 *
 *  Author: $author$
 *    Date: 12/25/2009
 **********************************************************************
 */
typedef cWinDIBitmapWindow
cWinTIFFToDIBitmapWindowExtend;
/**
 **********************************************************************
 *  Class: cWinTIFFToDIBitmapWindow
 *
 * Author: $author$
 *   Date: 12/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinTIFFToDIBitmapWindow
: virtual public cWinTIFFReaderEventsImplement,
  public cWinTIFFToDIBitmapWindowExtend
{
public:
    typedef cWinTIFFToDIBitmapWindowExtend cExtends;
    
    const TCHAR* m_fileNameChars;
    
    cWinBITMAPINFOHEADER m_diBitmapInfoHeader;
    cWinBitmapInfo m_diBitmapInfo;
    cWinDC m_diBitmapDC;

    BYTE* m_diBitmapRowByte;
    TSIZE m_diBitmapRowBytes;
        
    /**
     **********************************************************************
     *  Constructor: cWinTIFFToDIBitmapWindow
     *
     *       Author: $author$
     *         Date: 12/25/2009
     **********************************************************************
     */
    cWinTIFFToDIBitmapWindow
    (const TCHAR* fileNameChars=0,
     COLORREF bgColor=CWINDIBITMAPWINDOW_BG_COLOR,
     HBRUSH hBgBrush=NULL,
     const TCHAR* windowClassNameChars=_T(CWINDIBITMAPWINDOW_WINDOW_CLASSNAME),
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (bgColor, hBgBrush, windowClassNameChars, 
       hInstance, attached, isCreated),
       
      m_fileNameChars(fileNameChars),
      
      m_diBitmapRowByte(0),
      m_diBitmapRowBytes(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinTIFFToDIBitmapWindow
     *
     *      Author: $author$
     *        Date: 12/25/2009
     **********************************************************************
     */
    virtual ~cWinTIFFToDIBitmapWindow()
    {
    }
#else /* !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */

#if !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnTIFFPixel
     *
     *   Author: $author$
     *     Date: 12/29/2009
     **********************************************************************
     */
    virtual eError OnTIFFPixel
    (cWinPixelInterface& pixel,
     BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
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
     * Function: OnBeginTIFFRow
     *
     *   Author: $author$
     *     Date: 12/29/2009
     **********************************************************************
     */
    virtual eError OnBeginTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        TLENGTH length;
        
        if ((m_diBitmapRowByte = m_diBitmap.Row
            (length, imageLength-imageRow-1)))
            m_diBitmapRowBytes = length;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEndTIFFRow
     *
     *   Author: $author$
     *     Date: 12/29/2009
     **********************************************************************
     */
    virtual eError OnEndTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        m_diBitmapRowByte = 0;
        m_diBitmapRowBytes = 0;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginTIFFImage
     *
     *   Author: $author$
     *     Date: 12/29/2009
     **********************************************************************
     */
    virtual eError OnBeginTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        BITMAPINFO* bmi;
        HDC hDC;
        
        m_diBitmapInfoHeader.biPlanes = 1;
        m_diBitmapInfoHeader.biHeight = imageLength;
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
     * Function: OnEndTIFFImage
     *
     *   Author: $author$
     *     Date: 12/29/2009
     **********************************************************************
     */
    virtual eError OnEndTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        HBITMAP hBitmap;
        if ((hBitmap = m_diBitmap.Attached()))
            SizeClientArea(imageWidth,imageLength,FALSE);
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CWINTIFFTODIBITMAPWINDOW_HXX) || defined(CWINTIFFTODIBITMAPWINDOW_MEMBERS_ONLY) */
