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
 *   File: cwindibitmapfile.hxx
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
#if !defined(_CWINDIBITMAPFILE_HXX) || defined(CWINDIBITMAPFILE_MEMBERS_ONLY)
#if !defined(_CWINDIBITMAPFILE_HXX) && !defined(CWINDIBITMAPFILE_MEMBERS_ONLY)
#define _CWINDIBITMAPFILE_HXX
#endif /* !defined(_CWINDIBITMAPFILE_HXX) && !defined(CWINDIBITMAPFILE_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAPFILE_MEMBERS_ONLY)
#include "cwinbitmapfile.hxx"
#include "cwinbitmapinfo.hxx"
#include "cwindibitmap.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDIBitmapFileExtends
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cWinBitmapFile
cWinDIBitmapFileExtends;
/**
 **********************************************************************
 *  Class: cWinDIBitmapFile
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDIBitmapFile
: public cWinDIBitmapFileExtends
{
public:
    typedef cWinDIBitmapFileExtends cExtends;

    cWinDIBitmap* m_diBitmap;
    cWinBitmapInfo* m_bitmapInfo;
    HDC m_hDC;

    /**
     **********************************************************************
     *  Constructor: cWinDIBitmapFile
     *
     *       Author: $author$
     *         Date: 7/24/2009
     **********************************************************************
     */
    cWinDIBitmapFile
    (cWinDIBitmap* diBitmap=0,
     cWinBitmapInfo* bitmapInfo=0,
     HDC hDC=NULL)
    : m_diBitmap(diBitmap),
      m_bitmapInfo(bitmapInfo),
      m_hDC(hDC)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDIBitmapFile
     *
     *      Author: $author$
     *        Date: 7/24/2009
     **********************************************************************
     */
    virtual ~cWinDIBitmapFile()
    {
    }
    /**
     **********************************************************************
     * Function: OnImage
     *
     *   Author: $author$
     *     Date: 7/25/2009
     **********************************************************************
     */
    virtual eError OnImage
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
    {
        eError error = e_ERROR_NONE;
        eError error2;
        BITMAPINFO* bmi;

        if (m_bitmapInfo)
        if ((error2 = m_bitmapInfo->Allocate
            (m_bih, (m_bih.biClrUsed)?(m_rgbt):((RGBQUAD*)0))))
            error = error2;
        else
        {
            error = e_ERROR_NOT_ATTACHED;

            if ((bmi = m_bitmapInfo->Attached()))
            if (m_diBitmap && m_hDC)
                error = m_diBitmap->Create(*bmi, m_hDC);

            if ((error2 = m_bitmapInfo->Free()))
            if (!error)
                error = error2;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBeginRow
     *
     *   Author: $author$
     *     Date: 7/25/2009
     **********************************************************************
     */
    virtual eError OnBeginRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
    {
        eError error = e_ERROR_NONE;
        BYTE* byte;
        TSIZE size;
        TLENGTH length;

        if (m_diBitmap)
        if (!(byte = m_diBitmap->Row(length, row)))
            error = e_ERROR_FAILED;
        else
        {
            if (rowBytes < (size = (TSIZE)(length)))
                size = rowBytes;
            memcpy(byte, &rowByte, size);
        }
        return error;
    }
#else /* !defined(CWINDIBITMAPFILE_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPFILE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: ReadDIBitmap
     *
     *   Author: $author$
     *     Date: 12/2/2009
     **********************************************************************
     */
    virtual TLENGTH ReadDIBitmap
    (cWinDIBitmap& diBitmap, 
     cWinBitmapInfo& bitmapInfo,
     HDC hDC,
     const WCHAR* fileName) 
#if defined(CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        const char* fileNameChars;
        cString w2FileName;
        if (fileName)
        if (0 < (length = w2FileName.AssignW(fileName)))
        if ((fileNameChars = w2FileName.HasChars(length)))
            count = ReadDIBitmap
            (diBitmap, bitmapInfo, hDC, fileNameChars);
#else /* !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReadDIBitmap
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    virtual TLENGTH ReadDIBitmap
    (cWinDIBitmap& diBitmap, 
     cWinBitmapInfo& bitmapInfo,
     HDC hDC,
     const CHAR* fileName) 
#if defined(CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
        cWinDIBitmap* old_diBitmap = m_diBitmap;
        cWinBitmapInfo* old_bitmapInfo = m_bitmapInfo;
        HDC old_hDC = m_hDC;

         m_diBitmap = &diBitmap;
         m_bitmapInfo = &bitmapInfo;
         m_hDC = hDC;

         count = Read(fileName);

         m_hDC = old_hDC;
         m_bitmapInfo = old_bitmapInfo;
         m_diBitmap = old_diBitmap;
#else /* !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriteDIBitmap
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    virtual TLENGTH WriteDIBitmap
    (const CHAR* fileName) 
#if defined(CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDIBITMAPFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINDIBITMAPFILE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINDIBITMAPFILE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDIBITMAPFILE_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAPFILE_MEMBERS_ONLY) */

#endif /* !defined(_CWINDIBITMAPFILE_HXX) || defined(CWINDIBITMAPFILE_MEMBERS_ONLY) */
