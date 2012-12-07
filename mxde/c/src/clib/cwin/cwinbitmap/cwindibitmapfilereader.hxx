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
 *   File: cwindibitmapfilereader.hxx
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
#if !defined(_CWINDIBITMAPFILEREADER_HXX) || defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY)
#if !defined(_CWINDIBITMAPFILEREADER_HXX) && !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY)
#define _CWINDIBITMAPFILEREADER_HXX
#endif /* !defined(_CWINDIBITMAPFILEREADER_HXX) && !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY)
#include "cwinbitmapfilereader.hxx"
#include "cwinbitmapinfo.hxx"
#include "cwindibitmap.hxx"
#include "cwindc.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDIBitmapFileReaderExtend
 *
 *  Author: $author$
 *    Date: 12/18/2009
 **********************************************************************
 */
typedef cWinBitmapFileReader
cWinDIBitmapFileReaderExtend;
/**
 **********************************************************************
 *  Class: cWinDIBitmapFileReader
 *
 * Author: $author$
 *   Date: 12/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDIBitmapFileReader
: public cWinDIBitmapFileReaderExtend
{
public:
    typedef cWinDIBitmapFileReaderExtend cExtends;
    
    cWinDC& m_dc;
    cWinDIBitmap& m_diBitmap;
    cWinBitmapInfo& m_bitmapInfo;
    
    /**
     **********************************************************************
     *  Constructor: cWinDIBitmapFileReader
     *
     *       Author: $author$
     *         Date: 12/18/2009
     **********************************************************************
     */
    cWinDIBitmapFileReader
    (cWinDC& dc,
     cWinDIBitmap& diBitmap,
     cWinBitmapInfo& bitmapInfo,
     cWinBitmapFileReaderEventsInterface* delegated=0)
    : cExtends(delegated),
      m_dc(dc),
      m_diBitmap(diBitmap),
      m_bitmapInfo(bitmapInfo)
    {
    }
    /**
     **********************************************************************
     * Function: OnBeginBitmapRow
     *
     *   Author: $author$
     *     Date: 12/18/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        BYTE* byte;
        TSIZE size;
        TLENGTH length;
        
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnBeginBitmapRow
            (rowByte,rowBytes,rowCols,row)))
            return error2;
            
        if (!(byte = m_diBitmap.Row(length, row)))
            error = e_ERROR_FAILED;
        else
        {
            if (rowBytes < (size = (TSIZE)(length)))
                size = rowBytes;
            cBYTES::Copy(byte, &rowByte, size);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginBitmap
     *
     *   Author: $author$
     *     Date: 12/18/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        BITMAPINFO* bmi;
        HDC hDC;
        
        if ((m_delegated))
        if (0 <= (error2 = m_delegated->OnBeginBitmap
            (bits,cols,rows,planes)))
            return error2;
            
        if ((error2 = m_bitmapInfo.Allocate
            (m_bih, (m_bih.biClrUsed)?(m_rgbt):((RGBQUAD*)0))))
            error = error2;
        else
        {
            error = e_ERROR_NOT_ATTACHED;

            if ((bmi = m_bitmapInfo.Attached()))
            if ((hDC = m_dc.Attached()))
                error = m_diBitmap.Create(*bmi, hDC);

            if ((error2 = m_bitmapInfo.Free()))
            if (!error)
                error = error2;
        }
        return error;
    }
#else /* !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CWINDIBITMAPFILEREADER_HXX) || defined(CWINDIBITMAPFILEREADER_MEMBERS_ONLY) */
