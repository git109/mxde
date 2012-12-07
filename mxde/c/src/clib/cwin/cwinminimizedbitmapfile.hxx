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
 *   File: cwinminimizedbitmapfile.hxx
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
#if !defined(_CWINMINIMIZEDBITMAPFILE_HXX) || defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY)
#if !defined(_CWINMINIMIZEDBITMAPFILE_HXX) && !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY)
#define _CWINMINIMIZEDBITMAPFILE_HXX
#endif /* !defined(_CWINMINIMIZEDBITMAPFILE_HXX) && !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY) */

#if !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY)
#include "cwinbitmapfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinMinimizedBitmapFile
 *
 * Author: $author$
 *   Date: 7/22/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMinimizedBitmapFile
: public cWinBitmapFile
{
public:
    typedef cWinBitmapFile cExtends;
    typedef cWinMinimizedBitmapFile cDerives;

    cBYTEWriterInterface* m_minimizedWriter;
    bool m_minimizedRow, m_minimized, m_minimize;
    RGBQUAD m_rgbMin, m_rgbMax;
    TSIZE m_colMin, m_colMax, m_cols;
    TSIZE m_rowMin, m_rowMax, m_rows;
    TSIZE m_padded, m_bytes, m_bits;
    BYTE m_padding[3];

    /**
     **********************************************************************
     *  Constructor: cWinMinimizedBitmapFile
     *
     *       Author: $author$
     *         Date: 7/22/2009
     **********************************************************************
     */
    cWinMinimizedBitmapFile
    (cWinBitmapFileInterface* delegated=0)
    : cExtends(delegated),
      m_minimizedWriter(0),
      m_minimized(false),
      m_minimize(false)
    {
        m_padding[0] = 0;
        m_padding[1] = 0;
        m_padding[2] = 0;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMinimizedBitmapFile
     *
     *      Author: $author$
     *        Date: 7/22/2009
     **********************************************************************
     */
    virtual ~cWinMinimizedBitmapFile()
    {
    }
#else /* !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY) */
#endif /* !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY) */

#if !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: ReadMinimized
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH ReadMinimized
    (const RGBQUAD& rgbMin, const RGBQUAD& rgbMax, const char* fileName) 
    {
        TLENGTH count = -e_ERROR_FAILED;
        //TLENGTH length;

        m_bits = 0;
        m_cols = 0;
        m_rows = 0;
        m_bytes = 0;
        m_padded = 0;
        m_rgbMin = rgbMin;
        m_rgbMax = rgbMax;
        m_minimize = true;
        m_minimized = false;

        if (0 < (count = Read(fileName)))
        {
            if ((m_colMax >= m_colMin)
                && (m_rowMax >= m_rowMin))
            {
                m_rows = (m_rowMax-m_rowMin+1);
                m_cols = (m_colMax-m_colMin+1);

                m_bytes = ((m_bits*m_cols)+7)/8;
                m_padded = ((4 - (m_bytes & 3)) & 3);

                m_bih.biWidth = (m_cols);
                m_bih.biHeight = (m_rows);
                m_bih.biSizeImage = (m_rows*m_bytes);

                m_bfh.bfSize = (m_bfh.bfOffBits + (m_rows*(m_bytes+m_padded)));
            }

            m_minimize = false;
            m_minimized = true;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: WriteMinimized
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual TLENGTH WriteMinimized
    (const char* outFileName, const char* inFileName) 
    {
        TLENGTH count = -e_ERROR_FAILED;
        TLENGTH length;
        eError error;
        cBYTEFile outFile, inFile;

        if (m_minimized)
        if (!(error = inFile.Open(inFileName, "rb")))
        {
            if (!(error = outFile.Open(outFileName, "wb")))
            {
                if (0 < (count = m_rgbt.Write(m_bfh, m_bih, outFile)))
                {
                    m_minimizedWriter = &outFile;

                    if (0 > (length = Read(inFile)))
                        count = length;

                    m_minimizedWriter = 0;
                }
                outFile.Close();
            }
            inFile.Close();
        }
        return count;
    }

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
    {
        eError error = e_ERROR_NONE;

        if (m_minimize)
        {
            m_bits = bits;
            m_colMin = cols;
            m_colMax = 0;
            m_rowMin = rows;
            m_rowMax = 0;
        }
        return error;
    }
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
    {
        eError error = e_ERROR_NONE;
        TLENGTH count;

        if (m_minimize)
        {
            if ((rgb.rgbRed >= m_rgbMin.rgbRed)
                && (rgb.rgbRed <= m_rgbMax.rgbRed))

            if ((rgb.rgbGreen >= m_rgbMin.rgbGreen)
                && (rgb.rgbGreen <= m_rgbMax.rgbGreen))

            if ((rgb.rgbBlue >= m_rgbMin.rgbBlue)
                && (rgb.rgbBlue <= m_rgbMax.rgbBlue))
            {
                return error;
            }

            if (col < m_colMin) 
                m_colMin = col;

            if (col > m_colMax) 
                m_colMax = col;

            if (row < m_rowMin) 
                m_rowMin = row;

            if (row > m_rowMax) 
                m_rowMax = row;
        }
        else
        if (m_minimized)
        {
            if ((col >= m_colMin) && (col <= m_colMax)
                && (row >= m_rowMin) && (row <= m_rowMax))
            {
                m_minimizedRow = true;

                if (m_minimizedWriter)
                if (0 > (count = m_minimizedWriter->Write(&byte, bytes)))
                    error = -count;
            }
        }
        return error;
    }

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
    {
        eError error = e_ERROR_NONE;
        m_minimizedRow = false;
        return error;
    }
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
    {
        eError error = e_ERROR_NONE;
        TLENGTH count;

        if (m_minimizedRow)
        if (m_minimizedWriter)
        if (m_padded)
        if (0 > (count = m_minimizedWriter->Write(m_padding, m_padded)))
            error = -count;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY) */
#endif /* !defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY) */

#endif /* !defined(_CWINMINIMIZEDBITMAPFILE_HXX) || defined(CWINMINIMIZEDBITMAPFILE_MEMBERS_ONLY) */
