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
 *   File: cpngreader.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGREADER_HXX) || defined(CPNGREADER_MEMBERS_ONLY)
#if !defined(_CPNGREADER_HXX) && !defined(CPNGREADER_MEMBERS_ONLY)
#define _CPNGREADER_HXX
#endif /* !defined(_CPNGREADER_HXX) && !defined(CPNGREADER_MEMBERS_ONLY) */

#if !defined(CPNGREADER_MEMBERS_ONLY)
#include "cpnginforeaderinterfacecreated.hxx"
#include "cpngreaderinterface.hxx"
#include "cpngreaderevents.hxx"
#include "cpnginterface.hxx"
#include "cimagepixel.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPNGReaderExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cPNGReaderEvents
cPNGReaderExtend;
/**
 **********************************************************************
 *  Class: cPNGReader
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cPNGReader
: virtual public cPNGReaderImplement,
  public cPNGReaderExtend
{
public:
    typedef cPNGReaderImplement cImplements;
    typedef cPNGReaderExtend cExtends;
    typedef cPNGReader cDerives;
    
    typedef eError (cDerives::*MOnPNGCol)
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType);
     
    cPngInfoReaderInterfaceCreated m_pngInfoReader;
    TSIZE m_colBytes;
    MOnPNGCol m_onPNGCol;
    png_int_32 m_bytesRead;
    
    /**
     **********************************************************************
     *  Constructor: cPNGReader
     *
     *       Author: $author$
     *         Date: 1/13/2010
     **********************************************************************
     */
    cPNGReader
    (cPNGReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_colBytes(0),
      m_onPNGCol(0),
      m_bytesRead(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cPNGReader
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cPNGReader()
    {
    }

    /**
     **********************************************************************
     * Function: On8BitPalette16BitPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError On8BitPalette16BitPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: On8BitPalette8BitPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError On8BitPalette8BitPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: On16BitRGBAPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError On16BitRGBAPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: On16BitRGBPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError On16BitRGBPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    
    /**
     **********************************************************************
     * Function: On8BitRGBAPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError On8BitRGBAPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        cImagePixel pixel(colByte[0], colByte[1], colByte[2], colByte[3]);
        error = OnPNGPixel
        (pixel, colByte, colBytes, col, row, 
         height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
        return error;
    }
    /**
     **********************************************************************
     * Function: On8BitRGBPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError On8BitRGBPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        cImagePixel pixel(colByte[0], colByte[1], colByte[2]);
        error = OnPNGPixel
        (pixel, colByte, colBytes, col, row, 
         height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        if ((m_onPNGCol))
            error = (this->*m_onPNGCol)
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType);
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnPNGRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        BYTE* colByte;
        TSIZE col;
        
        for (colByte = rowByte, col = 0; 
             col < width; col++, colByte += m_colBytes)
        {
            if ((error = OnPNGCol
                (colByte, m_colBytes, col, row, 
                 height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
                break;
        }
        return error;
    }
     
    /**
     **********************************************************************
     * Function: OnPNGImage
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
    {
        eError error = e_ERROR_NONE;
        cPngInfoReaderInterface* pngInfoReader;
        png_bytep* imageRow;
        png_int_32 imageRows;
        png_int_32 rowBytes;
        png_bytep rowByte;
        png_int_32 rowIndex;
        png_int_32 row;
        png_int_32 count;
        
        m_colBytes = ((bitDepth+7)/8)*colorChannels;
                
        switch(colorType)
        {
        case PNG_COLOR_TYPE_RGB:
            switch(bitDepth)
            {
            case 8:
                m_onPNGCol = &cDerives::On8BitRGBPNGCol;
                break;
            case 16:
                m_onPNGCol = &cDerives::On16BitRGBPNGCol;
                break;
            }
            break;
            
        case PNG_COLOR_TYPE_RGB_ALPHA:
            switch(bitDepth)
            {
            case 8:
                m_onPNGCol = &cDerives::On8BitRGBAPNGCol;
                break;
            case 16:
                m_onPNGCol = &cDerives::On16BitRGBAPNGCol;
                break;
            }
            break;
            
        case PNG_COLOR_TYPE_PALETTE:
            switch(bitDepth)
            {
            case 8:
                m_onPNGCol = &cDerives::On8BitPalette8BitPNGCol;
                break;
            case 16:
                m_onPNGCol = &cDerives::On8BitPalette16BitPNGCol;
                break;
            }
            break;
        }
        
        if ((pngInfoReader = m_pngInfoReader.Attached()))
        if ((imageRow = pngInfoReader->ImageRow(imageRows, rowBytes)))
        if ((0 < (imageRows)) && (0 < (rowBytes)))
        for (row = 0; row < (png_int_32)(height); row += imageRows)
        {
            if (0 > (count = pngInfoReader->ReadRows()))
                break;
            
            m_bytesRead += count;

            for (rowByte = imageRow[rowIndex = 0]; 
                 rowIndex < imageRows; rowByte = imageRow[++rowIndex])
            {
                if (!(error = OnBeginPNGRow
                    (rowByte, rowBytes, row+rowIndex,
                     height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType)))
                if (!(error = OnPNGRow
                    (rowByte, rowBytes, row+rowIndex,
                     height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType)))
                if (!(error = OnEndPNGRow
                    (rowByte, rowBytes, row+rowIndex,
                     height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType)))
                    continue;
                    
                return error;
            }
        }
        return error;
    }
#else /* !defined(CPNGREADER_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
#if defined(CPNGREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        const CHAR* chars;
        cString fileNameString;
        if (0 < (length = fileNameString.AssignW(fileName)))
        if ((chars = fileNameString.HasChars(length)))
            count = Read(chars);
#else /* !defined(CPNGREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CPNGREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CPNGREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CPNGREADER_MEMBER_FUNCS_IMPLEMENT) 
        cPngInfoReaderInterface* pngInfoReader;
        eError error;
        png_int_32 value;
        TSIZE height, width, bitDepth, colorChannels;
        UINT colorType, filterType, interlaceType, compressionType;
/*        
        if (!(pngInfoReader = m_pngInfoReader.Attached()))
        if ((error = m_pngInfoReader.Create()))
            return count;
        else
        if (!(pngInfoReader = m_pngInfoReader.Attached()))
            return count;
*/            
        m_bytesRead = 0;

        if (!(error = m_pngInfoReader.Create()))
        {
        if ((pngInfoReader = m_pngInfoReader.Attached()))
        
        if (!(error = pngInfoReader->Open(fileName)))
        {
            if (0 < (value = (m_bytesRead = pngInfoReader->ReadBegin(1))))
            if (0 <= (value = pngInfoReader->GetImageHeight()))
            if (0 <= (height = value))
            if (0 <= (value = pngInfoReader->GetImageWidth()))
            if (0 <= (width = value))
            if (0 <= (value = pngInfoReader->GetBitDepth()))
            if (0 <= (bitDepth = value))
            if (0 <= (value = pngInfoReader->GetColorChannels()))
            if (0 <= (colorChannels = value))
            if (0 <= (value = pngInfoReader->GetColorType()))
            if (0 <= (colorType = value))
            if (0 <= (value = pngInfoReader->GetFilterType()))
            if (0 <= (filterType = value))
            if (0 <= (value = pngInfoReader->GetInterlaceType()))
            if (0 <= (interlaceType = value))
            if (0 <= (value = pngInfoReader->GetCompressionType()))
            if (0 <= (compressionType = value))
            if (!(error = OnBeginPNGImage
                (height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
            if (!(error = OnPNGImage
                (height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
            if (0 <= (value = pngInfoReader->ReadEnd()))
            if (!(error = OnEndPNGImage
                (height, width, bitDepth, colorChannels,
                 colorType, filterType, interlaceType, compressionType)))
            {
            }
            pngInfoReader->Close();
        }
        
        m_pngInfoReader.Destroy();
        }
#else /* !defined(CPNGREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CPNGREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNGREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGREADER_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADER_MEMBERS_ONLY) */

#endif /* !defined(_CPNGREADER_HXX) || defined(CPNGREADER_MEMBERS_ONLY) */
