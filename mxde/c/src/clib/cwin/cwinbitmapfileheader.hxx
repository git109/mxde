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
 *   File: cwinbitmapfileheader.hxx
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPFILEHEADER_HXX) || defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY)
#if !defined(_CWINBITMAPFILEHEADER_HXX) && !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY)
#define _CWINBITMAPFILEHEADER_HXX
#endif /* !defined(_CWINBITMAPFILEHEADER_HXX) && !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY) */

#if !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY)
#include "cwinbase.hxx"
#include "cfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinBITMAPFILEHEADER
 *
 * Author: $author$
 *   Date: 7/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBITMAPFILEHEADER
: public BITMAPFILEHEADER
{
public:
    typedef BITMAPFILEHEADER cExtends;
#else /* !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Read
    (const char* fileName) 
#if defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) 
        eError error;
        cBYTEFile file;
        if (!(error = file.Open(fileName, "rb")))
        {
            count = Read(file);
            file.Close();
        }
#else /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 7/21/2009
     **********************************************************************
     */
    virtual TLENGTH Write
    (const char* fileName) 
#if defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) 
        cExtends& extends = (cExtends&)(*this);
        count = reader.Read((BYTE*)(&extends), sizeof(cExtends));
#else /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE */
    {
        TLENGTH count = -e_ERROR_FAILED;
#if !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) 
        cExtends& extends = (cExtends&)(*this);
        count = writer.Write((BYTE*)(&extends), sizeof(cExtends));
#else /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINBITMAPFILEHEADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPFILEHEADER_HXX) || defined(CWINBITMAPFILEHEADER_MEMBERS_ONLY) */
