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
 *   File: cbmpreader.hxx
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
#if !defined(_CBMPREADER_HXX) || defined(CBMPREADER_MEMBERS_ONLY)
#if !defined(_CBMPREADER_HXX) && !defined(CBMPREADER_MEMBERS_ONLY)
#define _CBMPREADER_HXX
#endif /* !defined(_CBMPREADER_HXX) && !defined(CBMPREADER_MEMBERS_ONLY) */

#if !defined(CBMPREADER_MEMBERS_ONLY)
#include "cbmpreaderinterface.hxx"
#include "cbmpreaderevents.hxx"
#include "crgbquadbuffer.hxx"
#include "cbuffer.hxx"
#include "cfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cBMPReaderExtend
 *
 *  Author: $author$
 *    Date: 1/19/2010
 **********************************************************************
 */
typedef cBMPReaderEvents
cBMPReaderExtend;
/**
 **********************************************************************
 *  Class: cBMPReader
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cBMPReader
: virtual public cBMPReaderImplement,
  public cBMPReaderExtend
{
public:
    typedef cBMPReaderImplement cImplements;
    typedef cBMPReaderExtend cExtends;
    typedef cBMPReader cDerives;
    
    typedef eError (cDerives::*MOnBMPCol)
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes);
     
    typedef eError (cDerives::*MOnBMPRow)
    (BYTE& rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes);
     
    BITMAPFILEHEADER m_bfh;
    BITMAPINFOHEADER m_bih;
    
    cRGBQUADBuffer m_rgb;
    RGBQUAD* m_rgbQuad;
    TSIZE m_rgbQuads;
    
    cBYTEBuffer m_row;
    BYTE* m_rowByte;
    TSIZE m_rowBytes;
    TSIZE m_rowPadded;

    TSIZE m_colBytes;
    BYTE m_colShift;
    BYTE m_colMask;
    MOnBMPCol m_onBMPCol;
    MOnBMPRow m_onBMPRow;
    
    cBYTEFile m_file;
    
    /**
     **********************************************************************
     *  Constructor: cBMPReader
     *
     *       Author: $author$
     *         Date: 1/19/2010
     **********************************************************************
     */
    cBMPReader
    (cBMPReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_rgbQuad(0),
      m_rgbQuads(0),
      m_rowByte(0),
      m_rowBytes(0),
      m_colBytes(0),
      m_colShift(0),
      m_colMask(0),
      m_onBMPCol(0),
      m_onBMPRow(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cBMPReader
     *
     *      Author: $author$
     *        Date: 1/19/2010
     **********************************************************************
     */
    virtual ~cBMPReader()
    {
    }
    
    /**
     **********************************************************************
     * Function: On8BitPaletteBMPCol
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError On8BitPaletteBMPCol
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        if ((m_rgbQuad) && (colByte < m_rgbQuads))
            error = OnBMPPixel
            (m_rgbQuad[colByte], colByte, colBytes, col, 
             row, plane, bits, cols, rows, planes);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnNBitPaletteBMPCol
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnNBitPaletteBMPCol
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        BYTE colValue = ((colByte >> m_colShift) & m_colMask);
        if ((m_rgbQuad) && (colValue < m_rgbQuads))
            error = OnBMPPixel
            (m_rgbQuad[colValue], colByte, colBytes, col, 
             row, plane, bits, cols, rows, planes);
        return error;
    }
    /**
     **********************************************************************
     * Function: On24BitRGBBMPCol
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError On24BitRGBBMPCol
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        RGBTRIPLE& pixel = (RGBTRIPLE&)(colByte);
        eError error = OnBMPPixel
        (pixel, colByte, colBytes, col, 
         row, plane, bits, cols, rows, planes);
        return error;
    }
    /**
     **********************************************************************
     * Function: On32BitRGBBMPCol
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError On32BitRGBBMPCol
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        RGBQUAD& pixel = (RGBQUAD&)(colByte);
        eError error = OnBMPPixel
        (pixel, colByte, colBytes, col, 
         row, plane, bits, cols, rows, planes);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBMPCol
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPCol
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        if ((m_onBMPCol))
            error = (this->*m_onBMPCol)
            (colByte, colBytes, col, row, plane, 
             bits, cols, rows, planes);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnNBitBMPRow
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual eError OnNBitBMPRow
    (BYTE& rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        BYTE* colByte;
        BYTE colShift;
        TSIZE col;
        
        for (colByte = &rowByte, col = 0; 
             col < cols; colByte++)
        {
            for (colShift = 0; colShift < 8; 
                 colShift += (BYTE)(bits), col++)
            {
                m_colShift = (8 - colShift - (BYTE)(bits));
                if ((error = OnBMPCol
                    (*colByte, m_colBytes, col, 
                     row, plane, bits, cols, rows, planes)))
                    return error;
            }
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBMPRow
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual eError OnBMPRow
    (BYTE& rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        BYTE* colByte;
        TSIZE col;
        
        if ((m_onBMPRow))
            error = (this->*m_onBMPRow)
            (rowByte, rowBytes, row, plane, 
             bits, cols, rows, planes);
        else
        for (colByte = &rowByte, col = 0; 
             col < cols; col++, colByte += m_colBytes)
        {
            if ((error = OnBMPCol
                (*colByte, m_colBytes, col, 
                 row, plane, bits, cols, rows, planes)))
                break;
        }
        return error;
    }
#else /* !defined(CBMPREADER_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName) 
#if defined(CBMPREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        TLENGTH length;
        const CHAR* chars;
        cString fileNameString;
        if (0 < (length = fileNameString.AssignW(fileName)))
        if ((chars = fileNameString.HasChars(length)))
            count = Read(chars);
#if !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBMPREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/20/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CBMPREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        if (!(error = m_file.Open
            (fileName, CPLATFORM_FILE_MODE_READ_BINARY)))
        {
            count = Read(m_file);
            m_file.Close(true);
        }
#else /* !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBMPREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader) 
#if defined(CBMPREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count2;
        TLENGTH length;
        TLENGTH size;
        TSIZE bytes;
        TSIZE plane;
        TSIZE row;
        eError error;
        
        m_onBMPRow = 0;
        m_onBMPCol = 0;
        m_rgbQuad = 0;
        m_rowByte = 0;
        m_rowPadded = (m_rowBytes = (m_colBytes = (m_rgbQuads = 0)));
        
        if (0 > (count2 = reader.Read
            ((BYTE*)(&m_bfh), sizeof(m_bfh))))
            return count2;
        
        count = count2;
        
        if (0 > (count2 = reader.Read
            ((BYTE*)(&m_bih), sizeof(m_bih))))
            return count2;
            
        count += count2;
        
        switch(m_bih.biCompression)
        {
        case BI_RGB:
            break;
        case BI_RLE8:
        case BI_RLE4:
        case BI_BITFIELDS:
        case BI_JPEG:
        case BI_PNG:
        default:
            return -e_ERROR_FAILED;
        }

        if (24 > (m_bih.biBitCount))
        if (256 < (m_rgbQuads = (1 << m_bih.biBitCount)))
            return -e_ERROR_FAILED;
            
        if (0 < (m_rgbQuads))
        {
            if (0 > (count2 = m_rgb.SetLength
                ((TLENGTH)(m_rgbQuads))))
                return count2;
                
            if (!(m_rgbQuad = m_rgb.WriteBuffer(size, length))
                || ((TLENGTH)(m_rgbQuads) != length))
                return -e_ERROR_FAILED;
                
            if (0 > (count2 = reader.Read
                ((BYTE*)(m_rgbQuad), m_rgbQuads*sizeof(RGBQUAD))))
                return count2;
                
            count += count2;
        
            if (256 > (m_rgbQuads))
            {
                m_colMask = (255 >> (8 - m_bih.biBitCount));
                m_onBMPRow = &cDerives::OnNBitBMPRow;
                m_onBMPCol = &cDerives::OnNBitPaletteBMPCol;
            }
            else
            if (256 == (m_rgbQuads))
                m_onBMPCol = &cDerives::On8BitPaletteBMPCol;
        }
        else
        if ((1 == m_bih.biPlanes))
        {
            if ((24 == m_bih.biBitCount))
                m_onBMPCol = &cDerives::On24BitRGBBMPCol;
            else
            if ((32 == m_bih.biBitCount))
                m_onBMPCol = &cDerives::On32BitRGBBMPCol;
        }
        
        if (count != (m_bfh.bfOffBits))
            return -e_ERROR_FAILED;
            
        m_colBytes = (m_bih.biBitCount+7)/8;
        m_rowBytes = ((m_bih.biBitCount*m_bih.biWidth)+7)/8;
        m_rowBytes += (m_rowPadded = ((4-(m_rowBytes & 3)) & 3));
        
        if (0 > (count2 = m_row.SetLength(m_rowBytes)))
            return count2;
            
        if (!(m_rowByte = m_row.WriteBuffer(size, length)))
            return length;
        
        if ((error = OnBeginBMPImage
            (m_bih.biBitCount, m_bih.biWidth, 
             m_bih.biHeight, m_bih.biPlanes)))
            return -error;
            
        for (row = 0, plane = 0, bytes = m_bih.biSizeImage; 
             bytes >= m_rowBytes; bytes -= m_rowBytes)
        {
            if (0 > (length = reader.Read(m_rowByte, m_rowBytes)))
                return length;
            else
            if (length != (TLENGTH)(m_rowBytes))
                return -e_ERROR_READ;
                
            if (!(error = OnBeginBMPRow
                (*m_rowByte, m_rowBytes, row, plane,
                 m_bih.biBitCount, m_bih.biWidth, 
                 m_bih.biHeight, m_bih.biPlanes)))
            if (!(error = OnBMPRow
                (*m_rowByte, m_rowBytes, row, plane,
                 m_bih.biBitCount, m_bih.biWidth, 
                 m_bih.biHeight, m_bih.biPlanes)))
            if (!(error = OnEndBMPRow
                (*m_rowByte, m_rowBytes, row, plane,
                 m_bih.biBitCount, m_bih.biWidth, 
                 m_bih.biHeight, m_bih.biPlanes)))
            {
                count += length;
                
                if ((TSIZE)(m_bih.biHeight) < (++row))
                {
                    row = 0;
                    plane++;
                }
                continue;
            }
            return -error;
        }
        
        if ((error = OnEndBMPImage
            (m_bih.biBitCount, m_bih.biWidth, 
             m_bih.biHeight, m_bih.biPlanes)))
            return -error;
            
#else /* !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CBMPREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBMPREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBMPREADER_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADER_MEMBERS_ONLY) */

#endif /* !defined(_CBMPREADER_HXX) || defined(CBMPREADER_MEMBERS_ONLY) */
