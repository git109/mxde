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
 *   File: cwinrgbquadtable.hxx
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
#if !defined(_CWINRGBQUADTABLE_HXX) || defined(CWINRGBQUADTABLE_MEMBERS_ONLY)
#if !defined(_CWINRGBQUADTABLE_HXX) && !defined(CWINRGBQUADTABLE_MEMBERS_ONLY)
#define _CWINRGBQUADTABLE_HXX
#endif /* !defined(_CWINRGBQUADTABLE_HXX) && !defined(CWINRGBQUADTABLE_MEMBERS_ONLY) */

#if !defined(CWINRGBQUADTABLE_MEMBERS_ONLY)
#include "cwinbitmapinfoheader.hxx"
#include "cwinbitmapfileheader.hxx"
#include "cfile.hxx"

#define CWINRGBQUADTABLE_DEFAULT_SIZE 256

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRGBQUADTable
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRGBQUADTable
{
public:
    RGBQUAD m_defaultTable[CWINRGBQUADTABLE_DEFAULT_SIZE];
    RGBQUAD* m_table;
    TSIZE m_size,m_length;

    /**
     **********************************************************************
     *  Constructor: cWinRGBQUADTable
     *
     *       Author: $author$
     *         Date: 7/21/2009
     **********************************************************************
     */
    cWinRGBQUADTable()
    : m_table(m_defaultTable),
      m_size(CWINRGBQUADTABLE_DEFAULT_SIZE),
      m_length(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRGBQUADTable
     *
     *      Author: $author$
     *        Date: 7/21/2009
     **********************************************************************
     */
    virtual ~cWinRGBQUADTable()
    {
    }
#else /* !defined(CWINRGBQUADTABLE_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cWinBITMAPFILEHEADER& bfh,
     cWinBITMAPINFOHEADER& bih,
     const char* fileName) 
#if defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        TLENGTH count2;
        cBYTEFile file;
        if (!(error = file.Open(fileName, "rb")))
        {
            if (0 < (count = bfh.Read(file)))
            if (0 < (count2 = bih.Read(file)))
            {
                count += count2;
                if (0 < (bih.biClrUsed))
                if (0 < (count2 = Read(file, bih.biClrUsed)))
                    count += count2;
                else count = count2;
            }
            else count = count2;
            file.Close();
        }
#else /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (cWinBITMAPFILEHEADER& bfh,
     cWinBITMAPINFOHEADER& bih,
     const char* fileName) 
#if defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/22/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cWinBITMAPFILEHEADER& bfh,
     cWinBITMAPINFOHEADER& bih,
     cBYTEReaderInterface& reader) 
#if defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count2;

        if (0 < (count = bfh.Read(reader)))
        if (0 < (count2 = bih.Read(reader)))
        {
            count += count2;
            if (0 < (bih.biClrUsed))
            if (0 < (count2 = Read(reader, bih.biClrUsed)))
                count += count2;
            else count = count2;
        }
#else /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/23/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (cWinBITMAPFILEHEADER& bfh,
     cWinBITMAPINFOHEADER& bih,
     cBYTEWriterInterface& writer) 
#if defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count2;

        if (0 < (count = bfh.Write(writer)))
        if (0 < (count2 = bih.Write(writer)))
        {
            count += count2;
            if (0 < (bih.biClrUsed))
            if (0 < (count2 = Write(writer, bih.biClrUsed)))
                count += count2;
            else count = count2;
        }
#else /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader,
     TSIZE size) 
#if defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        if (size <= m_size)
        if (0 < (length = (TLENGTH)(size*sizeof(RGBQUAD))))
        if (length <= (count = reader.Read((BYTE*)(m_table), length)))
            m_length = size;
#else /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (cBYTEWriterInterface& writer,
     TSIZE size) 
#if defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH length;
        if (size <= m_length)
        if (0 < (length = (TLENGTH)(size*sizeof(RGBQUAD))))
            count = writer.Write((BYTE*)(m_table), length);
#else /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINRGBQUADTABLE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINRGBQUADTABLE_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: RGBQUAD
     *
     *   Author: $author$
     *     Date: 7/25/2009
     **********************************************************************
     */
    virtual operator RGBQUAD*() const 
    {
        return m_table;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRGBQUADTABLE_MEMBERS_ONLY) */
#endif /* !defined(CWINRGBQUADTABLE_MEMBERS_ONLY) */

#endif /* !defined(_CWINRGBQUADTABLE_HXX) || defined(CWINRGBQUADTABLE_MEMBERS_ONLY) */
