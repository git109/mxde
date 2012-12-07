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
 *   File: cwintiffreader.hxx
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
#if !defined(_CWINTIFFREADER_HXX) || defined(CWINTIFFREADER_MEMBERS_ONLY)
#if !defined(_CWINTIFFREADER_HXX) && !defined(CWINTIFFREADER_MEMBERS_ONLY)
#define _CWINTIFFREADER_HXX
#endif /* !defined(_CWINTIFFREADER_HXX) && !defined(CWINTIFFREADER_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADER_MEMBERS_ONLY)
#include "cwintiffreaderinterface.hxx"
#include "cwintiffreaderevents.hxx"
#include "cwinrgbtriplepixel.hxx"
#include "ctiffinterface.hxx"
#include "ctchartostring.hxx"
#include "cbuffer.hxx"

#define CWINTIFFREADER_8BIT_MAX 255
#define CWINTIFFREADER_16BIT_MAX 32767

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinTIFFReaderExtend
 *
 *  Author: $author$
 *    Date: 12/26/2009
 **********************************************************************
 */
typedef cWinTIFFReaderEvents
cWinTIFFReaderExtend;
/**
 **********************************************************************
 *  Class: cWinTIFFReader
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinTIFFReader
: virtual public cWinTIFFReaderImplement,
  public cWinTIFFReaderExtend
{
public:
    typedef cWinTIFFReaderImplement cImplements;
    typedef cWinTIFFReaderExtend cExtends;
    typedef cWinTIFFReader cDerives;
    
    typedef eError (cDerives::*MOnTIFFPixel)
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation);
     
    typedef eError (cDerives::*MOnTIFFRow)
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation);
     
    cTIFFInterface* m_tiff;
    UINT16* m_paletteRed;
    UINT16* m_paletteGreen;
    UINT16* m_paletteBlue;
    TSIZE m_paletteColors;
    TSIZE m_paletteBitsPerColor;
    MOnTIFFRow m_onTIFFRow;
    MOnTIFFPixel m_onTIFFPixel;
    cBYTEBuffer m_stripBuffer;
    
    /**
     **********************************************************************
     *  Constructor: cWinTIFFReader
     *
     *       Author: $author$
     *         Date: 12/26/2009
     **********************************************************************
     */
    cWinTIFFReader
    (cWinTIFFReaderEventsInterface* delegated=0,
     cTIFFInterface* tiff=0)
    : cExtends(delegated),
      m_tiff(tiff),
      m_onTIFFRow(0),
      m_onTIFFPixel(0),
      m_paletteRed(0),
      m_paletteGreen(0),
      m_paletteBlue(0),
      m_paletteColors(0),
      m_paletteBitsPerColor(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinTIFFReader
     *
     *      Author: $author$
     *        Date: 12/28/2009
     **********************************************************************
     */
    virtual ~cWinTIFFReader()
    {
        eError error;
        if ((m_tiff))
        if ((error = m_tiff->DeleteInstance()))
            throw error;
    }
#else /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */

#if defined(TCHAR_NOT_CHAR) 
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (const TCHAR* fileName) 
#if defined(CWINTIFFREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINTIFFREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = 0;
        TLENGTH length;
        const CHAR* chars;
        cTCHARToString fileNameString;
        if (0 < (length = fileNameString.AssignT(fileName)))
        if ((chars = fileNameString.HasChars(length)))
            count = Read(chars);
#else /* !defined(CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINTIFFREADER_MEMBER_FUNCS_INTERFACE) */
#endif /* defined(TCHAR_NOT_CHAR) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CWINTIFFREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINTIFFREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = 0;
        eError error;
        TLENGTH imageLength;
        TLENGTH imageWidth;
        TLENGTH rowsPerStrip;
        TLENGTH samplesPerPixel;
        TLENGTH bitsPerSample;
        TLENGTH photometricInterpretation;
        
        if (!(m_tiff))
        if (!(m_tiff = cTIFFInterface::CreateInstance(error)))
            return count = -error;
            
        if (!(error = m_tiff->Open(fileName)))
        {
            if (0 < (imageLength = m_tiff->ImageLength()))
            if (0 < (imageWidth = m_tiff->ImageWidth()))
            if (0 < (rowsPerStrip = m_tiff->RowsPerStrip()))
            if (0 < (samplesPerPixel = m_tiff->SamplesPerPixel()))
            if (0 < (bitsPerSample = m_tiff->BitsPerSample()))
            if (0 < (photometricInterpretation = m_tiff->PhotometricInterpretation()))
            if (!(error = OnBeginTIFFImage
                (imageLength,imageWidth,rowsPerStrip,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            if (!(error = OnTIFFImage
                (imageLength,imageWidth,rowsPerStrip,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            if (!(error = OnEndTIFFImage
                (imageLength,imageWidth,rowsPerStrip,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            {
            }
            m_tiff->Close();
        }
#else /* !defined(CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINTIFFREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINTIFFREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On16BitPalette16BitTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/7/2010
     **********************************************************************
     */
    virtual eError On16BitPalette16BitTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: On8BitPalette16BitTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/7/2010
     **********************************************************************
     */
    virtual eError On8BitPalette16BitTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: On16BitPalette8BitTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/7/2010
     **********************************************************************
     */
    virtual eError On16BitPalette8BitTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        BYTE pixelColor = (pixelByte[0]);
        
        if ((pixelColor < m_paletteColors) && (m_paletteRed) 
             && (m_paletteGreen) && (m_paletteBlue))
        {
            RGBTRIPLE rgb = 
            {(m_paletteBlue[pixelColor]*CWINTIFFREADER_8BIT_MAX)/CWINTIFFREADER_16BIT_MAX, 
             (m_paletteGreen[pixelColor]*CWINTIFFREADER_8BIT_MAX)/CWINTIFFREADER_16BIT_MAX, 
             (m_paletteRed[pixelColor]*CWINTIFFREADER_8BIT_MAX)/CWINTIFFREADER_16BIT_MAX};
             
            cWinRGBTRIPLEPixel pixel(rgb);
            
            eError error = ((cExtends*)(this))->OnTIFFPixel
            (pixel, pixelByte, pixelBytes, 
             imageRow, imageCol, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample, 
             photometricInterpretation);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: On8BitPalette8BitTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/7/2010
     **********************************************************************
     */
    virtual eError On8BitPalette8BitTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        BYTE pixelColor = (pixelByte[0]);
        
        if ((pixelColor < m_paletteColors) && (m_paletteRed) 
             && (m_paletteGreen) && (m_paletteBlue))
        {
            RGBTRIPLE rgb = 
            {m_paletteBlue[pixelColor], 
             m_paletteGreen[pixelColor], 
             m_paletteRed[pixelColor]};
             
            cWinRGBTRIPLEPixel pixel(rgb);
            
            eError error = ((cExtends*)(this))->OnTIFFPixel
            (pixel, pixelByte, pixelBytes, 
             imageRow, imageCol, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample, 
             photometricInterpretation);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: On24BitRGBTIFFPixel
     *
     *   Author: $author$
     *     Date: 12/29/2009
     **********************************************************************
     */
    virtual eError On24BitRGBTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        RGBTRIPLE rgb = {pixelByte[2], pixelByte[1], pixelByte[0]};
        cWinRGBTRIPLEPixel pixel(rgb);
        eError error = ((cExtends*)(this))->OnTIFFPixel
        (pixel, pixelByte, pixelBytes, 
         imageRow, imageCol, 
         imageLength, imageWidth, 
         samplesPerPixel, bitsPerSample, 
         photometricInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTIFFPixel
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual eError OnTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        if ((m_onTIFFPixel))
            error = (this->*m_onTIFFPixel)
            (pixelByte, pixelBytes, 
             imageRow, imageCol, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample, 
             photometricInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: On8BitSampleTIFFRow
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual eError On8BitSampleTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        TSIZE pixelBytes = samplesPerPixel;
        BYTE* pixelByte;
        TSIZE imageCol;
        
        for (pixelByte = rowByte, imageCol = 0; 
             imageCol < imageWidth; 
             imageCol++, pixelByte += pixelBytes)
        {
            if (!(error = OnBeginTIFFPixel
                (pixelByte, pixelBytes, 
                 imageRow, imageCol, 
                 imageLength, imageWidth, 
                 samplesPerPixel, bitsPerSample, 
                 photometricInterpretation)))
            if (!(error = OnTIFFPixel
                (pixelByte, pixelBytes, 
                 imageRow, imageCol, 
                 imageLength, imageWidth, 
                 samplesPerPixel, bitsPerSample, 
                 photometricInterpretation)))
            if (!(error = OnEndTIFFPixel
                (pixelByte, pixelBytes, 
                 imageRow, imageCol, 
                 imageLength, imageWidth, 
                 samplesPerPixel, bitsPerSample, 
                 photometricInterpretation)))
                continue;
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTIFFRow
     *
     *   Author: $author$
     *     Date: 12/28/2009
     **********************************************************************
     */
    virtual eError OnTIFFRow
    (BYTE* rowByte, TSIZE rowBytes,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        if ((m_onTIFFRow))
            error = (this->*m_onTIFFRow)
            (rowByte, rowBytes, imageRow, 
             imageLength, imageWidth, 
             samplesPerPixel, bitsPerSample, 
             photometricInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTIFFStrip
     *
     *   Author: $author$
     *     Date: 12/27/2009
     **********************************************************************
     */
    virtual eError OnTIFFStrip
    (BYTE* stripByte, TSIZE stripBytes,
     TSIZE stripRows, TSIZE strip,
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        TSIZE rowBytes = (imageWidth*samplesPerPixel*bitsPerSample+7)/8;
        BYTE* rowByte;
        TSIZE stripRow;
        
        for (rowByte = stripByte, stripRow = 0; 
             stripRow < stripRows; 
             stripRow++, rowByte += rowBytes, imageRow++)
        {
            if (!(error = OnBeginTIFFRow
                (rowByte, rowBytes, imageRow, 
                 imageLength, imageWidth,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            if (!(error = OnTIFFRow
                (rowByte, rowBytes, imageRow, 
                 imageLength, imageWidth,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            if (!(error = OnEndTIFFRow
                (rowByte, rowBytes, imageRow, 
                 imageLength, imageWidth,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
                continue;
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTIFFImage
     *
     *   Author: $author$
     *     Date: 12/26/2009
     **********************************************************************
     */
    virtual eError OnTIFFImage
    (TSIZE imageLength, TSIZE imageWidth,
     TSIZE rowsPerStrip, TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        BYTE* stripByte;
        TLENGTH stripBytes;
        TLENGTH length;
        TSIZE row;
        
        switch(bitsPerSample)
        {
        case 8:
            m_onTIFFRow = &cDerives::On8BitSampleTIFFRow;
            switch(photometricInterpretation)
            {
            case e_TIFF_PHOTOMETRIC_RGB:
                m_onTIFFPixel = &cDerives::On24BitRGBTIFFPixel;
                break;

            case e_TIFF_PHOTOMETRIC_PALETTE:
                if (0 <(length = m_tiff->GetColorMapSpanned
                    (m_paletteBitsPerColor, m_paletteRed, 
                     m_paletteGreen, m_paletteBlue, bitsPerSample)))
                {
                    m_paletteColors = length;
                    
                    switch(m_paletteBitsPerColor)
                    {
                    case 8:
                        m_onTIFFPixel = &cDerives::On8BitPalette8BitTIFFPixel;
                        break;
                    case 16:
                        m_onTIFFPixel = &cDerives::On16BitPalette8BitTIFFPixel;
                        break;
                    }
                }
                break;    
            }
            break;
        }
        
        if (0 < (stripBytes = m_tiff->StripSize()))
        if (stripBytes < (length = m_stripBuffer.SetSize(stripBytes)))
        if ((stripByte = m_stripBuffer.GetWriteBuffer(length)))
        for (row = 0; row < imageLength; row += rowsPerStrip)
        {
            TSIZE stripRows = (row + rowsPerStrip > imageLength)
                              ?(imageLength - row):(rowsPerStrip);
            TSIZE strip = (0 <= (length = m_tiff->ComputeStrip(row,0)))
                          ?((TSIZE)(length)):(0);
                          
            if (0 < (length = m_tiff->ReadEncodedStrip
                (strip, stripByte, stripBytes)))
            if (!(error = OnBeginTIFFStrip
                (stripByte, stripBytes, stripRows, strip, 
                 row, imageLength, imageWidth,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            if (!(error = OnTIFFStrip
                (stripByte, stripBytes, stripRows, strip, 
                 row, imageLength, imageWidth,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
            if (!(error = OnEndTIFFStrip
                (stripByte, stripBytes, stripRows, strip, 
                 row, imageLength, imageWidth,
                 samplesPerPixel,bitsPerSample,
                 photometricInterpretation)))
                continue;
            break;
        }
        m_onTIFFRow = 0;
        return error;
    }
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADER_MEMBERS_ONLY) */

#endif /* !defined(_CWINTIFFREADER_HXX) || defined(CWINTIFFREADER_MEMBERS_ONLY) */
