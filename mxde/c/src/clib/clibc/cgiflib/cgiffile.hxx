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
 *   File: cgiffile.hxx
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
#if !defined(_CGIFFILE_HXX) || defined(CGIFFILE_MEMBERS_ONLY)
#if !defined(_CGIFFILE_HXX) && !defined(CGIFFILE_MEMBERS_ONLY)
#define _CGIFFILE_HXX
#endif /* !defined(_CGIFFILE_HXX) && !defined(CGIFFILE_MEMBERS_ONLY) */

#if !defined(CGIFFILE_MEMBERS_ONLY)
#include "cgiffileinterface.hxx"
#include "cstring.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cGifFileExtend
 *
 *  Author: $author$
 *    Date: 11/4/2010
 **********************************************************************
 */
typedef cGifFileTypeOpened
cGifFileExtend;
/**
 **********************************************************************
 *  Class: cGifFile
 *
 * Author: $author$
 *   Date: 11/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifFile
: virtual public cGifFileImplement,
  public cGifFileExtend
{
public:
    typedef cGifFileImplement cImplements;
    typedef cGifFileExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cGifFile
     *
     *       Author: $author$
     *         Date: 11/4/2010
     **********************************************************************
     */
    cGifFile
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(attached, isOpen)
    {
        eError error;
        DBE_THROW_ERROR(error, error = Closed());
    }
    /**
     **********************************************************************
     *  Destructor: ~cGifFile
     *
     *      Author: $author$
     *        Date: 11/4/2010
     **********************************************************************
     */
    virtual ~cGifFile()
    {
    }
#else /* !defined(CGIFFILE_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Open
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual eError Open
    (const CHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH,
     bool onlyClosed=false)
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        OpenAttached(error, chars, length, onlyClosed);
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OpenAttached
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual GifFileType* OpenAttached
    (eError& error,
     const CHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH,
     bool onlyClosed=false)
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        GifFileType* detached = 0;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = Closed(onlyClosed)))
        if ((detached = OpenDetached(error, chars, length)))
        if (detached == (AttachOpened(detached)))
            error = e_ERROR_NONE;
        else
        {
            error = e_ERROR_FAILED;
            CloseDetached(detached);
            detached = 0;
        }
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OpenDetached
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual GifFileType* OpenDetached
    (eError& error,
     const CHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH) const
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        GifFileType* detached = 0;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        cString fileName;
        
        error = e_ERROR_FAILED;
        
        if (0 < (fileName.Append(chars, length)))
        if ((chars = fileName.HasChars(length)))
        if ((detached = DGifOpenFileName(chars)))
            error = e_ERROR_NONE;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Close
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpen=false)
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        GifFileType* detached;
        if ((detached = Detach()))
            error = CloseDetached(detached);
        else 
        if (onlyOpen)
            error = e_ERROR_NOT_ATTACHED;
        else
        error = e_ERROR_NONE;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CloseDetached
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual eError CloseDetached
    (GifFileType* detached) const
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        if (detached)
        if (GIF_OK == (DGifCloseFile(detached)))
            error = e_ERROR_NONE;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetImageDesc
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual GifImageDesc* GetImageDesc()
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        GifImageDesc* desc = 0;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        GifFileType* attached;
        if ((attached = Attached()))
        if (GIF_OK == (DGifGetImageDesc(attached)))
            desc = &attached->Image;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return desc;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetLine
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual TLENGTH GetLine
    (GifPixelType* line, int lineSize)
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        GifFileType* attached;
        if (line && (0 <= lineSize))
        if ((attached = Attached()))
        if (GIF_OK == (DGifGetLine(attached, line, lineSize)))
            count =(TLENGTH)(lineSize);
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetExtension
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual GifByteType* GetExtension
    (int& extCode)
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        GifByteType* extBytes = 0;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        GifFileType* attached;
        if ((attached = Attached()))
        if (GIF_OK != (DGifGetExtension(attached, &extCode, &extBytes)))
            extBytes = 0;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return extBytes;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetExtensionNext
     *
     *    Author: $author$
     *      Date: 11/5/2010
     **********************************************************************
     */
    virtual GifByteType* GetExtensionNext()
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        GifByteType* extBytes = 0;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        GifFileType* attached;
        if ((attached = Attached()))
        if (GIF_OK != (DGifGetExtensionNext(attached, &extBytes)))
            extBytes = 0;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return extBytes;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetRecordType
     *
     *    Author: $author$
     *      Date: 11/4/2010
     **********************************************************************
     */
    virtual GifRecordType GetRecordType()
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        GifRecordType type = UNDEFINED_RECORD_TYPE;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        GifFileType* attached;
        if ((attached = Attached()))
        if (GIF_OK != (DGifGetRecordType(attached, &type)))
            type = UNDEFINED_RECORD_TYPE;
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return type;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: operator cGifFile*
     *
     *    Author: $author$
     *      Date: 11/14/2010
     **********************************************************************
     */
    virtual operator cGifFile*() const
#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */
    {
        cGifFile* gif = 0;
#if !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT)
        gif = (cGifFile*)(this);
#else /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILE_MEMBER_FUNCS_IMPLEMENT) */
        return gif;
    }
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

#if defined(CGIFFILE_MEMBER_FUNCS_INTERFACE)
    /**
     **********************************************************************
     * Function: CreateInstance
     *
     *   Author: $author$
     *     Date: 11/14/2010
     **********************************************************************
     */
    static cGifFileInterface* CreateInstance
    (eError& error) ;
    /**
     **********************************************************************
     * Function: DestroyInstance
     *
     *   Author: $author$
     *     Date: 11/14/2010
     **********************************************************************
     */
    static eError DestroyInstance
    (cGifFileInterface& gif) ;
#endif /* defined(CGIFFILE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CGIFFILE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILE_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILE_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILE_HXX) || defined(CGIFFILE_MEMBERS_ONLY) */
