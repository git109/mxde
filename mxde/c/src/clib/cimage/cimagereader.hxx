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
 *   File: cimagereader.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CIMAGEREADER_HXX) || defined(CIMAGEREADER_MEMBERS_ONLY)
#if !defined(_CIMAGEREADER_HXX) && !defined(CIMAGEREADER_MEMBERS_ONLY)
#define _CIMAGEREADER_HXX
#endif /* !defined(_CIMAGEREADER_HXX) && !defined(CIMAGEREADER_MEMBERS_ONLY) */

#if !defined(CIMAGEREADER_MEMBERS_ONLY)
#include "cimagereaderinterface.hxx"
#include "cimagereaderevents.hxx"
#include "cfilepath.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cImageReaderExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cImageReaderEvents
cImageReaderExtend;
/**
 **********************************************************************
 *  Class: cImageReader
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cImageReader
: virtual public cImageReaderImplement,
  public cImageReaderExtend
{
public:
    typedef cImageReaderImplement cImplements;
    typedef cImageReaderExtend cExtends;
    
    /**
     **********************************************************************
     *  Constructor: cImageReader
     *
     *       Author: $author$
     *         Date: 1/13/2010
     **********************************************************************
     */
    cImageReader
    (cImageReaderEventsInterface* delegated=0)
    : cExtends(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cImageReader
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cImageReader()
    {
    }
#else /* !defined(CIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADER_MEMBERS_ONLY) */

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
#if defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Accept
     *
     *    Author: $author$
     *      Date: 11/9/2010
     **********************************************************************
     */
    virtual eError Accept
    (const WCHAR* fileName)
#if defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT)
        const WCHAR* fileExtension;
        cWFilePath filePath;
        TLENGTH length;
        
        if ((fileName))
        if (0 < (length = filePath.Assign(fileName)))
        if ((fileExtension = filePath.GetFileExtension(length, true)))
            error = AcceptExtension(fileExtension);
#else /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Accept
     *
     *    Author: $author$
     *      Date: 11/9/2010
     **********************************************************************
     */
    virtual eError Accept
    (const CHAR* fileName)
#if defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT)
        const CHAR* fileExtension;
        cFilePath filePath;
        TLENGTH length;
        
        if ((fileName))
        if (0 < (length = filePath.Assign(fileName)))
        if ((fileExtension = filePath.GetFileExtension(length, true)))
            error = AcceptExtension(fileExtension);
#else /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AcceptExtension
     *
     *    Author: $author$
     *      Date: 11/9/2010
     **********************************************************************
     */
    virtual eError AcceptExtension
    (const WCHAR* fileExtension)
#if defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AcceptExtension
     *
     *    Author: $author$
     *      Date: 11/9/2010
     **********************************************************************
     */
    virtual eError AcceptExtension
    (const CHAR* fileExtension)
#if defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT)
        cWCHARString wString;
        const WCHAR* wChars;
        if (0 < (wString.AssignCHARS(fileExtension)))
        if ((wChars = wString.HasChars()))
            error = AcceptExtension(wChars);
#else /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEREADER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CIMAGEREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEREADER_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEREADER_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADER_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEREADER_HXX) || defined(CIMAGEREADER_MEMBERS_ONLY) */
