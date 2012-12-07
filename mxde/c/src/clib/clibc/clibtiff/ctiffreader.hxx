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
 *   File: ctiffreader.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CTIFFREADER_HXX) || defined(CTIFFREADER_MEMBERS_ONLY)
#if !defined(_CTIFFREADER_HXX) && !defined(CTIFFREADER_MEMBERS_ONLY)
#define _CTIFFREADER_HXX
#endif /* !defined(_CTIFFREADER_HXX) && !defined(CTIFFREADER_MEMBERS_ONLY) */

#if !defined(CTIFFREADER_MEMBERS_ONLY)
#include "ctiffinterfacecreated.hxx"
#include "ctiffreaderinterface.hxx"
#include "ctiffreaderevents.hxx"
#include "cimagepixel.hxx"
#include "cstring.hxx"
#include "cbuffer.hxx"

#define CTIFFREADER_8BIT_MAX 255
#define CTIFFREADER_16BIT_MAX 32767

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cTIFFReaderExtend
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cTIFFReaderEvents
cTIFFReaderExtend;
/**
 **********************************************************************
 *  Class: cTIFFReader
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTIFFReader
: virtual public cTIFFReaderImplement,
  public cTIFFReaderExtend
{
public:
    typedef cTIFFReaderImplement cImplements;
    typedef cTIFFReaderExtend cExtends;
    typedef cTIFFReader cDerives;
    
    typedef eError (cDerives::*MOnTIFFPixel)
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation);
     
    cTIFFInterfaceCreated m_tiff;
    
    UINT16* m_paletteRed;
    UINT16* m_paletteGreen;
    UINT16* m_paletteBlue;
    TSIZE m_paletteColors;
    TSIZE m_paletteBitsPerColor;
    TSIZE m_bytesPerStrip;
    TSIZE m_bytesPerRow;
    TSIZE m_bytesPerPixel;
    MOnTIFFPixel m_onTIFFPixel;
    cBYTEBuffer m_stripBuffer;
    
    /**
     **********************************************************************
     *  Constructor: cTIFFReader
     *
     *       Author: $author$
     *         Date: 12/30/2009
     **********************************************************************
     */
    cTIFFReader
    (cTIFFReaderEventsInterface* delegated=0,
     cTIFFInterface* attached=0,
     bool isCreated=false)
    : cExtends(delegated),
      m_tiff(attached, isCreated),
      m_paletteRed(0),
      m_paletteGreen(0),
      m_paletteBlue(0),
      m_paletteColors(0),
      m_paletteBitsPerColor(0),
      m_bytesPerStrip(0),
      m_bytesPerRow(0),
      m_bytesPerPixel(0),
      m_onTIFFPixel(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cTIFFReader
     *
     *      Author: $author$
     *        Date: 12/30/2009
     **********************************************************************
     */
    virtual ~cTIFFReader()
    {
        eError error;
        if ((error = m_tiff.Destroy()))
            throw (error);
    }
#else /* !defined(CTIFFREADER_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
#if defined(CTIFFREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFFREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = 0;
        TLENGTH length;
        const CHAR* chars;
        cString fileNameString;
        if (0 < (length = fileNameString.AssignW(fileName)))
        if ((chars = fileNameString.HasChars(length)))
            count = Read(chars);
#else /* !defined(CTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFFREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CTIFFREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTIFFREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CTIFFREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = 0;
        eError error;
        TLENGTH imageLength;
        TLENGTH imageWidth;
        TLENGTH rowsPerStrip;
        TLENGTH samplesPerPixel;
        TLENGTH bitsPerSample;
        TLENGTH photometricInterpretation;
        cTIFFInterface* tiff;
        
        if (!(tiff = m_tiff.CreatedAttached(error)))
            return count = -error;
            
        if (!(error = tiff->Open(fileName)))
        {
            if (0 < (imageLength = tiff->ImageLength()))
            if (0 < (imageWidth = tiff->ImageWidth()))
            if (0 < (rowsPerStrip = tiff->RowsPerStrip()))
            if (0 < (samplesPerPixel = tiff->SamplesPerPixel()))
            if (0 < (bitsPerSample = tiff->BitsPerSample()))
            if (0 < (photometricInterpretation = tiff->PhotometricInterpretation()))
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
            tiff->Close();
        }
#else /* !defined(CTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CTIFFREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTIFFREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTIFFREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On16BitPalette16BitTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/9/2010
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
     *     Date: 1/9/2010
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
     *     Date: 1/9/2010
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
            cImagePixel pixel
            ((m_paletteRed[pixelColor]*CTIFFREADER_8BIT_MAX)/CTIFFREADER_16BIT_MAX, 
             (m_paletteGreen[pixelColor]*CTIFFREADER_8BIT_MAX)/CTIFFREADER_16BIT_MAX, 
             (m_paletteBlue[pixelColor]*CTIFFREADER_8BIT_MAX)/CTIFFREADER_16BIT_MAX);
             
            error = ((cExtends*)(this))->OnTIFFPixel
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
     *     Date: 1/9/2010
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
            cImagePixel pixel
            ((m_paletteRed[pixelColor]), 
             (m_paletteGreen[pixelColor]), 
             (m_paletteBlue[pixelColor]));
             
            error = ((cExtends*)(this))->OnTIFFPixel
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
     * Function: On32BitRGBTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual eError On32BitRGBTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        cImagePixel pixel
        (pixelByte[0], pixelByte[1], pixelByte[2], pixelByte[3]);
        
        error = ((cExtends*)(this))->OnTIFFPixel
        (pixel, pixelByte, pixelBytes, 
         imageRow, imageCol, 
         imageLength, imageWidth, 
         samplesPerPixel, bitsPerSample, 
         photometricInterpretation);
        return error;
    }
    /**
     **********************************************************************
     * Function: On24BitRGBTIFFPixel
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual eError On24BitRGBTIFFPixel
    (BYTE* pixelByte, TSIZE pixelBytes,
     TSIZE imageRow, TSIZE imageCol,
     TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        cImagePixel pixel
        (pixelByte[0], pixelByte[1], pixelByte[2]);
        
        error = ((cExtends*)(this))->OnTIFFPixel
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
     *     Date: 1/9/2010
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
     * Function: OnTIFFRow
     *
     *   Author: $author$
     *     Date: 1/9/2010
     **********************************************************************
     */
    virtual eError OnTIFFRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE imageRow, TSIZE imageLength, TSIZE imageWidth,
     TSIZE samplesPerPixel, TSIZE bitsPerSample,
     eTIFFPhotometricInterpretation photometricInterpretation) 
    {
        eError error = e_ERROR_NONE;
        TSIZE pixelBytes = m_bytesPerPixel;
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
     * Function: OnTIFFStrip
     *
     *   Author: $author$
     *     Date: 1/9/2010
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
        TSIZE rowBytes = m_bytesPerRow;
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
     *     Date: 1/9/2010
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
        cTIFFInterface* tiff;
        
        if (!(tiff = m_tiff.Attached()))
            return error = e_ERROR_NOT_ATTACHED;
            
        switch(bitsPerSample)
        {
        case 8:
            m_bytesPerStrip = rowsPerStrip
            *(m_bytesPerRow = (imageWidth
            *(m_bytesPerPixel = samplesPerPixel)));
            
            switch(photometricInterpretation)
            {
            case e_TIFF_PHOTOMETRIC_RGB:
                m_onTIFFPixel = &cDerives::On24BitRGBTIFFPixel;
                break;

            case e_TIFF_PHOTOMETRIC_PALETTE:
                if (0 <(length = tiff->GetColorMapSpanned
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
            
        default:
            m_bytesPerPixel = (samplesPerPixel*bitsPerSample+7)/8;
            m_bytesPerRow = (imageWidth*samplesPerPixel*bitsPerSample+7)/8;
            m_bytesPerStrip = m_bytesPerRow*rowsPerStrip;
        }
        
        if (0 < (stripBytes = tiff->StripSize()))
        if (stripBytes < (length = m_stripBuffer.SetSize(stripBytes)))
        if ((stripByte = m_stripBuffer.GetWriteBuffer(length)))
        for (row = 0; row < imageLength; row += rowsPerStrip)
        {
            TSIZE stripRows = (row + rowsPerStrip > imageLength)
                              ?(imageLength - row):(rowsPerStrip);
            TSIZE strip = (0 <= (length = tiff->ComputeStrip(row,0)))
                          ?((TSIZE)(length)):(0);
                          
            if (0 < (length = tiff->ReadEncodedStrip
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
        m_onTIFFPixel = 0;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFREADER_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADER_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFREADER_HXX) || defined(CTIFFREADER_MEMBERS_ONLY) */
