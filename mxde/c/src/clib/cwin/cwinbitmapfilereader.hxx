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
 *   File: cwinbitmapfilereader.hxx
 *
 * Author: $author$
 *   Date: 12/17/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEREADER_HXX) || defined(CWINBITMAPFILEREADER_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEREADER_HXX) && !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY)
#define _CWINBITMAPFILEREADER_HXX
#endif /* !defined(_CWINBITMAPFILEREADER_HXX) && !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY)
#include "cwinbitmapfilereaderinterface.hxx"
#include "cwinbitmapfilereaderevents.hxx"
#include "cwinbitmapfileheader.hxx"
#include "cwinbitmapinfoheader.hxx"
#include "cwinrgbquadtable.hxx"
#include "cfile.hxx"
#include "cbuffer.hxx"
#include "ctchartostring.hxx"

#define CWINBITMAPFILEREADER_FILE_READ_MODE "rb"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapFileReaderExtend
 *
 *  Author: $author$
 *    Date: 12/17/2009
 **********************************************************************
 */
typedef cWinBitmapFileReaderEvents
cWinBitmapFileReaderExtend;
/**
 **********************************************************************
 *  Class: cWinBitmapFileReader
 *
 * Author: $author$
 *   Date: 12/17/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapFileReader
: virtual public cWinBitmapFileReaderImplement,
  public cWinBitmapFileReaderExtend
{
public:
    typedef cWinBitmapFileReaderImplement cImplements;
    typedef cWinBitmapFileReaderExtend cExtends;
    
    cWinBITMAPFILEHEADER m_bfh;
    cWinBITMAPINFOHEADER m_bih;
    cWinRGBQUADTable m_rgbt;
    cBYTEBuffer m_row;

    cTCHARToString m_t2FileName;
    cBYTEFile m_file;
        
    /**
     **********************************************************************
     *  Constructor: cWinBitmapFileReader
     *
     *       Author: $author$
     *         Date: 12/17/2009
     **********************************************************************
     */
    cWinBitmapFileReader
    (cWinBitmapFileReaderEventsInterface* delegated=0)
    : cExtends(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinBitmapFileReader
     *
     *      Author: $author$
     *        Date: 12/17/2009
     **********************************************************************
     */
    virtual ~cWinBitmapFileReader()
    {
    }
#else /* !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY) */

#if defined(TCHAR_NOT_CHAR) 
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (const TCHAR* fileName) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        const char* fileNameChars;
        if (0 < (length = m_t2FileName.AssignT(fileName)))
        if ((fileNameChars = m_t2FileName.HasChars(length)))
            count = Read(fileNameChars);
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
#endif /* defined(TCHAR_NOT_CHAR) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (const char* fileName) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        if (!(error = m_file.Open
            (fileName, CWINBITMAPFILEREADER_FILE_READ_MODE)))
        {
            count = Read(m_file);
            m_file.Close();
        }
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */

#if defined(TCHAR_NOT_CHAR) 
    /**
     **********************************************************************
     * Function: ReadHeader
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH ReadHeader
    (const TCHAR* fileName) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        const char* fileNameChars;
        if (0 < (length = m_t2FileName.AssignT(fileName)))
        if ((fileNameChars = m_t2FileName.HasChars(length)))
            count = ReadHeader(fileNameChars);
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
#endif /* defined(TCHAR_NOT_CHAR) */
    /**
     **********************************************************************
     * Function: ReadHeader
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH ReadHeader
    (const char* fileName) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        if (!(error = m_file.Open
            (fileName, CWINBITMAPFILEREADER_FILE_READ_MODE)))
        {
            count = ReadHeader(m_file);
            m_file.Close();
        }
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        TLENGTH count2;

        SetIs32BitColorBitmap(false);

        if (0 < (count = m_rgbt.Read(m_bfh, m_bih, reader)))
        if (!(error = OnBeginBitmap
            (m_bih.biBitCount, m_bih.biWidth, 
             m_bih.biHeight, m_bih.biPlanes)))
        {
            TSIZE pixelSize = (m_bih.biBitCount+7)/8;

            if (256 == (m_rgbt.m_length))
                SetIs256ColorBitmap();
            else
            if (!(m_rgbt.m_length))
            {
                if ((1 == m_bih.biPlanes))
                if ((24 == m_bih.biBitCount))
                    SetIs24BitColorBitmap();
                else
                if ((32 == m_bih.biBitCount))
                    SetIs32BitColorBitmap();
            }

            if (0 < (count2 = ReadPixels
                (reader, m_bih.biSizeImage, pixelSize,
                 m_bih.biWidth, m_bih.biHeight)))
            {
                count += count2;
                
                OnEndBitmap
                (m_bih.biBitCount, m_bih.biWidth, 
                 m_bih.biHeight, m_bih.biPlanes);
            }
            else count = count2;
        }
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadHeader
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH ReadHeader
    (cBYTEReaderInterface& reader) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count2;
        if (0 < (count = m_bfh.Read(reader)))
        if (0 < (count2 = m_bih.Read(reader)))
            count += count2;
        else count = count2;
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadPixels
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual TLENGTH ReadPixels
    (cBYTEReaderInterface& reader,
     TSIZE size, TSIZE pixelSize, TSIZE width, TSIZE height) 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
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

            if ((error = OnBitmapRow(*byte, bytes, width, row)))
                return length = -error;
        }
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: BitmapWidth
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual LONG BitmapWidth() const 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        LONG width = m_bih.biWidth;
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        LONG width = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return width;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BitmapHeight
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual LONG BitmapHeight() const 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        LONG height = m_bih.biHeight;
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        LONG height = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return height;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BitmapBits
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual SHORT BitmapBits() const 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        SHORT bits = m_bih.biBitCount;
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        SHORT bits = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return bits;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BitmapPlanes
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual SHORT BitmapPlanes() const 
#if defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) 
        SHORT planes = m_bih.biPlanes;
#else /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        SHORT planes = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return planes;
    }
#endif /* defined(CWINBITMAPFILEREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEREADER_HXX) || defined(CWINBITMAPFILEREADER_MEMBERS_ONLY) */
