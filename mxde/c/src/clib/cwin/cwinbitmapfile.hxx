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
 *   File: cwinbitmapfile.hxx
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILE_HXX) || defined(CWINBITMAPFILE_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILE_HXX) && !defined(CWINBITMAPFILE_MEMBERS_ONLY)
#define _CWINBITMAPFILE_HXX
#endif /* !defined(_CWINBITMAPFILE_HXX) && !defined(CWINBITMAPFILE_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILE_MEMBERS_ONLY)
#include "cwinbitmapfileinterface.hxx"
#include "cwinbitmapfileheader.hxx"
#include "cwinbitmapinfoheader.hxx"
#include "cwinrgbquadtable.hxx"
#include "cwinbase.hxx"
#include "cfile.hxx"
#include "cbuffer.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinBitmapFile
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapFile
: virtual public cWinBitmapFileImplement,
  public cWinBase
{
public:
    typedef cWinBitmapFileImplement cImplements;
    typedef cWinBase cExtends;
    typedef cWinBitmapFile cDerives;

    typedef eError (cDerives::*MOnCol)
    (BYTE& rowByte, TSIZE rowBytes, TSIZE rowCol, TSIZE row);

    cWinBitmapFileInterface* m_delegated;

    cWinBITMAPFILEHEADER m_bfh;
    cWinBITMAPINFOHEADER m_bih;
    cWinRGBQUADTable m_rgbt;

    cBYTEBuffer m_row;

    MOnCol m_onCol;

    /**
     **********************************************************************
     *  Constructor: cWinBitmapFile
     *
     *       Author: $author$
     *         Date: 7/22/2009
     **********************************************************************
     */
    cWinBitmapFile
    (cWinBitmapFileInterface* delegated=0)
    : m_delegated(delegated),
      m_onCol(0)
    {
    }
#else /* !defined(CWINBITMAPFILE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnImage
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual eError OnImage
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        cWinBitmapFileInterface* delegated = 0;
        if ((delegated = Delegated()))
            error = delegated->OnImage
            (bits,cols,rows,planes);
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnPixel
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual eError OnPixel
    (RGBQUAD& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        cWinBitmapFileInterface* delegated = 0;
        if ((delegated = Delegated()))
            error = delegated->OnPixel
            (rgb,byte,bytes,col,row);
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginRow
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual eError OnBeginRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        cWinBitmapFileInterface* delegated = 0;
        if ((delegated = Delegated()))
            error = delegated->OnBeginRow
            (rowByte,rowBytes,rowCols,row);
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndRow
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual eError OnEndRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        cWinBitmapFileInterface* delegated = 0;
        if ((delegated = Delegated()))
            error = delegated->OnEndRow
            (rowByte,rowBytes,rowCols,row);
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Delegated
     *
     *    Author: $author$
     *      Date: 12/3/2009
     **********************************************************************
     */
    virtual cWinBitmapFileInterface* Delegated() const
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    {
        cWinBitmapFileInterface* delegated = 0;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT)
        delegated = m_delegated;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPFILE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnRow
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual eError OnRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        TSIZE rowCol;

        if (!(error = OnBeginRow(rowByte, rowBytes, rowCols, row)))
        {
            for (rowCol = 0; rowCol < rowCols; rowCol++)
            {
                if ((error = OnCol(rowByte, rowBytes, rowCol, row)))
                    return error;
            }

            error = OnEndRow(rowByte, rowBytes, rowCols, row);
        }
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnCol
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual eError OnCol
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        if (m_onCol)
            error = (this->*m_onCol)
            (rowByte, rowBytes, rowCol, row);
        else
        error = e_ERROR_NOT_SUPPORTED;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: On256ColorCol
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    eError On256ColorCol
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCol,
     TSIZE row) 
    {
        eError error = e_ERROR_NONE;

        if (rowCol < rowBytes)
        {
            BYTE& pixelByte = *((&rowByte)+rowCol);
            RGBQUAD& pixelRGB = m_rgbt.m_table[pixelByte];

            if (m_rgbt.m_length > (pixelByte))
                error = OnPixel
                (pixelRGB, pixelByte, sizeof(BYTE), rowCol, row);
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: On24BitColorCol
     *
     *   Author: $author$
     *     Date: 7/28/2009
     **********************************************************************
     */
    eError On24BitColorCol
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCol,
     TSIZE row) 
    {
        eError error = e_ERROR_NONE;

        if (rowCol < rowBytes)
        {
            RGBQUAD& pixelRGB = *((RGBQUAD*)(((RGBTRIPLE*)(&rowByte))+rowCol));
            BYTE& pixelByte = *((BYTE*)(&pixelRGB));

            error = OnPixel
            (pixelRGB, pixelByte, sizeof(RGBTRIPLE), rowCol, row);
        }
        return error;
    }

    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/11/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (const WCHAR* fileName)
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = -e_ERROR_FAILED;
        eError error;
        cBYTEFile file;
        if (!(error = file.Open(fileName, CFILE_MODE_READ_BINARY)))
        {
            count = Read(file);
            file.Close();
        }
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (const CHAR* fileName) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = -e_ERROR_FAILED;
        eError error;
        cBYTEFile file;
        if (!(error = file.Open(fileName, CFILE_MODE_READ_BINARY)))
        {
            count = Read(file);
            file.Close();
        }
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (const char* fileName) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: ReadHeader
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual TLENGTH ReadHeader
    (const WCHAR* fileName) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        cBYTEFile file;

        m_onCol = 0;
        if (!(error = file.Open(fileName, CFILE_MODE_READ_BINARY)))
        {
            count = ReadHeader(file);
            file.Close();
        }
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadHeader
     *
     *   Author: $author$
     *     Date: 12/2/2009
     **********************************************************************
     */
    virtual TLENGTH ReadHeader
    (const char* fileName) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        cBYTEFile file;

        m_onCol = 0;
        if (!(error = file.Open(fileName, CFILE_MODE_READ_BINARY)))
        {
            count = ReadHeader(file);
            file.Close();
        }
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadHeader
     *
     *   Author: $author$
     *     Date: 12/2/2009
     **********************************************************************
     */
    virtual TLENGTH ReadHeader
    (cBYTEReaderInterface& reader) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count2;

        if (0 < (count = m_bfh.Read(reader)))
        if (0 < (count2 = m_bih.Read(reader)))
            count += count2;
        else count = count2;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        TLENGTH count2;

        m_onCol = 0;

        if (0 < (count = m_rgbt.Read(m_bfh, m_bih, reader)))
        if (!(error = OnImage
            (m_bih.biBitCount, m_bih.biWidth, 
             m_bih.biHeight, m_bih.biPlanes)))
        {
            TSIZE pixelSize = (m_bih.biBitCount+7)/8;

            if (256 == (m_rgbt.m_length))
                m_onCol = &cDerives::On256ColorCol;
            else
            if (!(m_rgbt.m_length))
            {
                if ((1 == m_bih.biPlanes) 
                    && (24 == m_bih.biBitCount))
                    m_onCol = &cDerives::On24BitColorCol;
            }

            if (0 < (count2 = Read
                (reader, m_bih.biSizeImage, pixelSize,
                 m_bih.biWidth, m_bih.biHeight)))
                count += count2;
            else count = count2;
        }
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader,
     TSIZE size, TSIZE pixelSize, TSIZE width, TSIZE height) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        TSIZE pixelsWidth = (pixelSize*width);
        TSIZE padded = ((4-(pixelsWidth & 3)) & 3);
        TSIZE bytes = pixelsWidth+padded;
        BYTE* byte;
        TSIZE row;
        TLENGTH length;
        eError error;

        if (0 < (length = m_row.SetSize(bytes)))
        if ((byte = m_row.WriteBuffer(length)))
        for (row = 0, count = 0; (TSIZE)(count) < size; count += length, row++)
        {
            if (0 > (length = reader.Read(byte, bytes)))
                return length;

            if ((error = OnRow(*byte, bytes, width, row)))
                return length = -error;
        }

#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (cBYTEWriterInterface& writer,
     TSIZE size, TSIZE pixelSize, TSIZE width, TSIZE height) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWidth
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual LONG SetWidth
    (LONG toWidth) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        LONG width = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return width;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Width
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual LONG Width() const 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        LONG width = m_bih.biWidth;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        LONG width = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return width;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetHeight
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual LONG SetHeight
    (LONG toHeight) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        LONG height = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return height;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Height
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual LONG Height() const 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        LONG height = m_bih.biHeight;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        LONG height = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return height;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBits
     *
     *   Author: $author$
     *     Date: 7/27/2009
     **********************************************************************
     */
    virtual SHORT SetBits
    (WORD toBits) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        SHORT bits = (m_bih.biBitCount = toBits);
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        SHORT bits = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return bits;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Bits
     *
     *   Author: $author$
     *     Date: 7/27/2009
     **********************************************************************
     */
    virtual SHORT Bits() const 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        SHORT bits = m_bih.biBitCount;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        SHORT bits = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return bits;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetPlanes
     *
     *   Author: $author$
     *     Date: 7/27/2009
     **********************************************************************
     */
    virtual SHORT SetPlanes
    (WORD toPlanes) 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        SHORT planes = (m_bih.biPlanes = toPlanes);
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        SHORT planes = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return planes;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Planes
     *
     *   Author: $author$
     *     Date: 7/27/2009
     **********************************************************************
     */
    virtual SHORT Planes() const 
#if defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        SHORT planes = m_bih.biPlanes;
#else /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        SHORT planes = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return planes;
    }
#endif /* defined(CWINBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILE_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILE_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILE_HXX) || defined(CWINBITMAPFILE_MEMBERS_ONLY) */
