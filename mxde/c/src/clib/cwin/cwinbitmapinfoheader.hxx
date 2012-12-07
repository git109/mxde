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
 *   File: cwinbitmapinfoheader.hxx
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPINFOHEADER_HXX) || defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY)
#if !defined(_CWINBITMAPINFOHEADER_HXX) && !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY)
#define _CWINBITMAPINFOHEADER_HXX
#endif /* !defined(_CWINBITMAPINFOHEADER_HXX) && !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY) */

#if !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY)
#include "cwinbitmapfileheader.hxx"
#include "cfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinBITMAPINFOHEADER
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBITMAPINFOHEADER
: public BITMAPINFOHEADER
{
public:
    typedef BITMAPINFOHEADER cExtends;
#else /* !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY) */

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
     const char* fileName) 
#if defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        TLENGTH count2;
        cBYTEFile file;
        if (!(error = file.Open(fileName, "rb")))
        {
            if (0 < (count = bfh.Read(file)))
            if (0 < (count2 = Read(file)))
                count += count2;
            else count = count2;
            file.Close();
        }
#else /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE) */
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
     const char* fileName) 
#if defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader) 
#if defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) 
        cExtends& extends = (cExtends&)(*this);
        count = reader.Read((BYTE*)(&extends), sizeof(cExtends));
#else /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (cBYTEWriterInterface& writer) 
#if defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) 
        cExtends& extends = (cExtends&)(*this);
        count = writer.Write((BYTE*)(&extends), sizeof(cExtends));
#else /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPINFOHEADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPINFOHEADER_HXX) || defined(CWINBITMAPINFOHEADER_MEMBERS_ONLY) */
