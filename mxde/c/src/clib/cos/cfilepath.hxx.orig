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
 *   File: cfilepath.hxx
 *
 * Author: $author$
 *   Date: 10/10/2009
 **********************************************************************
 */
#if !defined(_CFILEPATH_HXX) || defined(CFILEPATH_MEMBERS_ONLY)
#if !defined(_CFILEPATH_HXX) && !defined(CFILEPATH_MEMBERS_ONLY)
#define _CFILEPATH_HXX
#endif /* !defined(_CFILEPATH_HXX) && !defined(CFILEPATH_MEMBERS_ONLY) */

#if !defined(CFILEPATH_MEMBERS_ONLY)
#include "cfilepathseparatoreventsinterface.hxx"
#include "cfilepathinterface.hxx"
#include "ctofilepathseparatorwriter.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class cFilePath;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathT"
/**
 **********************************************************************
 *  Class: cFilePathT
 *
 * Author: $author$
 *   Date: 10/10/2009
 **********************************************************************
 */
template
<class TDerives=cFilePath,
 class TFilePathImplement=cFilePathImplement,
 class TFilePathSeparatorEventsImplement=cFilePathSeparatorEventsImplement,
 class TToFilePathSeparatorWriter=cToFilePathSeparatorWriter,
 class TStringInterface=cStringInterface,
 class TString=cString,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TFilePathSeparatorEventsImplements=TFilePathSeparatorEventsImplement,
 class TImplements=TFilePathImplement,
 class TExtends=TString>

class cFilePathT
: virtual public TFilePathSeparatorEventsImplements,
  virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cFilePath interface member definitions
 */
#define CFILEPATHINTERFACE_MEMBERS_ONLY
#include "cfilepathinterface.hxx"
#undef CFILEPATHINTERFACE_MEMBERS_ONLY

    typedef TString tString;
    typedef TToFilePathSeparatorWriter tToFilePathSeparatorWriter;
    
    tToFilePathSeparatorWriter m_toFilePathSeparatorWriter;
    tChar m_volumeSeparatorChar;
    tChar m_directorySeparatorChar;
    tChar m_extensionSeparatorChar;
    
    bool m_isRootDirectory;
    bool m_isAbsoluteDirectory;
    bool m_isRelativeDirectory;
    
    tString m_fileHost;
    tString m_fileVolume;
    tString m_fileDirectory;
    tString m_fileBase;
    tString m_fileExtension;
    tString m_fileName;
    tString m_filePath;
    
    /**
     **********************************************************************
     *  Constructor: cFilePathT
     *
     *       Author: $author$
     *         Date: 10/10/2009
     **********************************************************************
     */
    cFilePathT
    (const tChar* chars=0,
     tLength length=vUndefinedLength,
     bool onlyChars=false,
     eSeparate separate=e_SEPARATE_ALL)
    : m_toFilePathSeparatorWriter(*this),
      m_volumeSeparatorChar(CPLATFORM_VOLUME_SEPARATOR_CHAR),
      m_directorySeparatorChar(CPLATFORM_DIRECTORY_SEPARATOR_CHAR),
      m_extensionSeparatorChar(CPLATFORM_EXTENSION_SEPARATOR_CHAR),
      m_isRootDirectory(false),
      m_isAbsoluteDirectory(false),
      m_isRelativeDirectory(false)
    {
        eError error;
        if (chars)
        if (0 > (length = Assign
            (chars, length, onlyChars, separate)))
            throw (error = -length);
    }
#else /* !defined(CFILEPATH_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATH_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: NewFilePath
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual const tChar* NewFilePath
    (tLength& length,
     tStringInterface& path,
     const TChar* newFilePathChars,
     tLength newFilePathLength=vUndefinedLength,
     bool onlyHasChars=true) const
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength length2;
        const tChar* chars2;
        
        length = 0;
        
        if (0 > (length2 = path.Clear()))
            length = length2;
        else
        if (0 > (length2 = path.Append(newFilePathChars, newFilePathLength)))
            length = length2;
        else
        if (0 > (length2 = path.Append(&m_directorySeparatorChar, 1)))
            length = length2;
        else
        if ((chars2 = m_fileName.HasChars(length2)))
        {
            if (0 > (length2 = path.Append(chars2, length2)))
                length = length2;
        }
        
        if (0 <= length)
            chars = path.Chars(length, onlyHasChars);
            
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NewFileName
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual const tChar* NewFileName
    (tLength& length,
     tStringInterface& path,
     const TChar* newFileNameChars,
     tLength newFileNameLength=vUndefinedLength,
     bool onlyHasChars=true) const
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength length2;
        const tChar* chars2;
        
        length = 0;
        
        if (0 > (length2 = path.Clear()))
            length = length2;
        else
        if ((chars2 = m_filePath.HasChars(length2)))
        {
            if (0 > (length2 = path.Append(chars2, length2)))
                length = length2;
            else
            if (0 > (length2 = path.Append(&m_directorySeparatorChar, 1)))
                length = length2;
        }
        if (0 <= length)
        if (0 > (length2 = path.Append(newFileNameChars, newFileNameLength)))
            length = length2;
            
        if (0 <= length)
            chars = path.Chars(length, onlyHasChars);
            
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NewFileBase
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual const tChar* NewFileBase
    (tLength& length,
     tStringInterface& path,
     const TChar* newFileBaseChars,
     tLength newFileBaseLength=vUndefinedLength,
     bool onlyHasChars=true) const
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength length2;
        const tChar* chars2;
        
        length = 0;
        
        if (0 > (length2 = path.Clear()))
            length = length2;
        else
        if ((chars2 = m_filePath.HasChars(length2)))
        {
            if (0 > (length2 = path.Append(chars2, length2)))
                length = length2;
            else
            if (0 > (length2 = path.Append(&m_directorySeparatorChar, 1)))
                length = length2;
        }
        
        if (0 <= length)
        if (0 > (length2 = path.Append(newFileBaseChars, newFileBaseLength)))
            length = length2;
        else
        if (0 < (length2 = m_fileExtension.Length()))
        {
            if (0 > (length2 = path.Append(&m_extensionSeparatorChar, 1)))
                length = length2;
            else
            if ((chars2 = m_fileExtension.HasChars(length2)))
            {
                if (0 > (length2 = path.Append(chars2, length2)))
                    length = length2;
            }
        }
        
        if (0 <= length)
            chars = path.Chars(length, onlyHasChars);
            
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NewFileExtension
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual const tChar* NewFileExtension
    (tLength& length,
     tStringInterface& path,
     const TChar* newFileExtensionChars,
     tLength newFileExtensionLength=vUndefinedLength,
     bool onlyHasChars=true) const
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar* chars = 0;
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength length2;
        const TChar* chars2;
        
        length = 0;
        
        if (0 > (length2 = path.Clear()))
            length = length2;
        else
        if ((chars2 = m_filePath.HasChars(length2)))
        {
            if (0 > (length2 = path.Append(chars2, length2)))
                length = length2;
            else
            if (0 > (length2 = path.Append(&m_directorySeparatorChar, 1)))
                length = length2;
        }
        
        if (0 <= length)
        if ((chars2 = m_fileBase.HasChars(length2)))
        {
            if (0 > (length2 = path.Append(chars2, length2)))
                length = length2;
            else
            if (0 > (length2 = path.Append(&m_extensionSeparatorChar, 1)))
                length = length2;
        }
        
        if (0 <= length)
        if (0 > (length2 = path.Append(newFileExtensionChars, newFileExtensionLength)))
            length = length2;
            
        if (0 <= length)
            chars = path.Chars(length, onlyHasChars);
            
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Assign
     *
     *   Author: $author$
     *     Date: 10/12/2009
     **********************************************************************
     */
    virtual tLength Assign
    (const tChar* chars,
     tLength length=vUndefinedLength,
     bool onlyChars=false, 
     eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        if (0 < (count = AssignChars(chars, length)))
        if (!onlyChars)
        if (0 > (length = Separate(separate)))
            count = length;
        else
        if (0 > (length = CombineFileName(separate)))
            count = length;
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Append
     *
     *   Author: $author$
     *     Date: 10/12/2009
     **********************************************************************
     */
    virtual tLength Append
    (const tChar* chars,
     tLength length=vUndefinedLength,
     bool onlyChars=true, 
     eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        if (0 < (count = AppendChars(chars, length)))
        if (!onlyChars)
        if (0 > (length = Separate(separate)))
            count = length;
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Separate
     *
     *   Author: $author$
     *     Date: 10/12/2009
     **********************************************************************
     */
    virtual tLength Separate
    (eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tLength length;
        const tChar* chars;
        
        if ((chars = CTHIS HasChars(length)))
        if (0 <= (count = m_toFilePathSeparatorWriter.Initialize()))
        {
            count = m_toFilePathSeparatorWriter.Write(chars, length);
            
            if (0 > (length = m_toFilePathSeparatorWriter.Finalize()))
                count = length;
            else count += length;
        }
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Combine
     *
     *   Author: $author$
     *     Date: 10/12/2009
     **********************************************************************
     */
    virtual tLength Combine
    (eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tLength length;
        const tChar* chars;
        bool hasHost;
        bool hasVolume;
        bool hasDirectory;
        bool hasFileBase;
        bool hasFileExtension;

        if (0 > (length = CTHIS ClearChars()))
            return length;

        if ((hasHost = (0 != (chars = m_fileHost.HasChars(length)))))
        {
            if (0 > (count = CTHIS AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = CTHIS AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = CTHIS AppendChars(chars, length)))
                return count;
        }

        if ((hasVolume = (0 != (chars = m_fileVolume.HasChars(length)))))
        {
            if (hasHost)
            if (0 > (count = CTHIS AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = CTHIS AppendChars(chars, length)))
                return count;
            if (0 > (count = CTHIS AppendChars(&m_volumeSeparatorChar, 1)))
                return count;
        }

        if ((hasDirectory = (0 != (chars = m_fileDirectory.HasChars(length)))))
        {
            if ((hasHost && !hasVolume) || m_isRootDirectory)
            if (0 > (count = CTHIS AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = CTHIS AppendChars(chars, length)))
                return count;
        }

        if ((hasFileBase = (0 != (chars = m_fileBase.HasChars(length)))))
        {
            if (hasDirectory || m_isRootDirectory || (hasHost && !hasVolume))
            if (0 > (count = CTHIS AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = CTHIS AppendChars(chars, length)))
                return count;

            if ((hasFileExtension = (0 != (chars = m_fileExtension.HasChars(length)))))
            {
                if (0 > (count = CTHIS AppendChars(&m_extensionSeparatorChar, 1)))
                    return count;
                if (0 > (count = CTHIS AppendChars(chars, length)))
                    return count;
            }
        }
        else if (m_isRootDirectory)
        {
            if (0 > (count = CTHIS AppendChars(&m_directorySeparatorChar, 1)))
                return count;
        }
        count = CTHIS Length();
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CombineFileName
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength CombineFileName
    (eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tLength length;
        const tChar* chars;
        bool hasFileBase;
        bool hasFileExtension;

        if (0 > (length = m_fileName.ClearChars()))
            return length;

        if ((hasFileBase = (0 != (chars = m_fileBase.HasChars(length)))))
        {
            if (0 > (count = m_fileName.AppendChars(chars, length)))
                return count;

            if ((hasFileExtension = (0 != (chars = m_fileExtension.HasChars(length)))))
            {
                if (0 > (count = m_fileName.AppendChars(&m_extensionSeparatorChar, 1)))
                    return count;
                if (0 > (count = m_fileName.AppendChars(chars, length)))
                    return count;
            }
        }
        count = m_fileName.Length();
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CombineFilePath
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength CombineFilePath
    (eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tLength length;
        const tChar* chars;
        bool hasHost;
        bool hasVolume;
        bool hasDirectory;

        if (0 > (length = m_filePath.ClearChars()))
            return length;

        if ((hasHost = (0 != (chars = m_fileHost.HasChars(length)))))
        {
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(chars, length)))
                return count;
        }

        if ((hasVolume = (0 != (chars = m_fileVolume.HasChars(length)))))
        {
            if (hasHost)
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(chars, length)))
                return count;
            if (0 > (count = m_filePath.AppendChars(&m_volumeSeparatorChar, 1)))
                return count;
        }

        if ((hasDirectory = (0 != (chars = m_fileDirectory.HasChars(length)))))
        {
            if ((hasHost && !hasVolume) || m_isRootDirectory)
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
            if (0 > (count = m_filePath.AppendChars(chars, length)))
                return count;
        }
        else if (m_isRootDirectory)
        {
            if (0 > (count = m_filePath.AppendChars(&m_directorySeparatorChar, 1)))
                return count;
        }
        count = m_filePath.Length();
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength Clear
    (bool onlyChars=false,
     eSeparate separate=e_SEPARATE_ALL) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tLength count2;
        
        if (0 > (count = CTHIS ClearChars()))
            return count;
            
        if (0 > (count2 = m_fileHost.Clear()))
            return count2;
            
        if (0 > (count2 = m_fileVolume.Clear()))
            return count2;
            
        if (0 > (count2 = m_fileDirectory.Clear()))
            return count2;
            
        if (0 > (count2 = m_fileBase.Clear()))
            return count2;
            
        if (0 > (count2 = m_fileExtension.Clear()))
            return count2;
            
        if (0 > (count2 = m_fileName.Clear()))
            return count2;
            
        if (0 > (count2 = m_filePath.Clear()))
            return count2;
            
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength Clear
    (bool onlyChars) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = Clear(onlyChars, e_SEPARATE_ALL);
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength Clear() 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = Clear(false, e_SEPARATE_ALL);
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFileHost
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFileHost
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileHost.Append(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFileHost
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFileHost
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileHost.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileHost
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFileHost
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_fileHost.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFileVolume
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFileVolume
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileVolume.Append(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFileVolume
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFileVolume
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileVolume.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileVolume
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFileVolume
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_fileVolume.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFileDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFileDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        const tChar* chars2;
        tLength length2;
        
        if ((chars2 = m_fileDirectory.HasChars(length2)))
        if (m_directorySeparatorChar != (chars2[length2-1]))
        if (0 > (count = m_fileDirectory.Append(&m_directorySeparatorChar, 1)))
            return count;
        
        if (0 <= (length = m_fileDirectory.Append(chars,length)))
            count += length;
        else count = length;
        
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFileDirectory
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFileDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileDirectory.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileDirectory
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFileDirectory
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_fileDirectory.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFileBase
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFileBase
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileBase.Append(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFileBase
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFileBase
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileBase.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileBase
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFileBase
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_fileBase.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFileExtension
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFileExtension
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileExtension.Append(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFileExtension
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFileExtension
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileExtension.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileExtension
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFileExtension
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_fileExtension.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFileName
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFileName
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileName.Append(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFileName
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFileName
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_fileName.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFileName
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFileName
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_fileName.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AppendToFilePath
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength AppendToFilePath
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_filePath.Append(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetFilePath
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual tLength SetFilePath
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = m_filePath.Assign(chars,length);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetFilePath
     *
     *   Author: $author$
     *     Date: 10/10/2009
     **********************************************************************
     */
    virtual const tChar* GetFilePath
    (tLength& length,
     bool onlyHasChars=false) const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        const tChar* chars = m_filePath.Chars(length,onlyHasChars);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        const tChar* chars = 0;
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIsRootDirectory
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual int SetIsRootDirectory
    (bool isTrue=true) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        int is = (m_isRootDirectory = isTrue);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        int is = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetIsRootDirectory
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual bool GetIsRootDirectory() const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        bool is = m_isRootDirectory;
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        bool is = false;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetIsAbsoluteDirectory
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual int SetIsAbsoluteDirectory
    (bool isTrue=true) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        int is = (m_isAbsoluteDirectory = isTrue);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        int is = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetIsAbsoluteDirectory
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual bool GetIsAbsoluteDirectory() const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        bool is = m_isAbsoluteDirectory;
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        bool is = false;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual int SetIsRelativeDirectory
    (bool isTrue=true) 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        int is = (m_isRelativeDirectory = isTrue);
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        int is = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetIsRelativeDirectory
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual bool GetIsRelativeDirectory() const 
#if defined(CFILEPATH_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) 
        bool is = m_isRelativeDirectory;
#else /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        bool is = false;
#endif /* !defined(CFILEPATH_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CFILEPATH_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILEPATH_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnPathFileHost
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileHost
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = SetFileHost(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileVolume
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileVolume
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = SetFileVolume(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = AppendToFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileRootDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = AppendToFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileCurrentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileCurrentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = AppendToFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileRootCurrentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootCurrentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = AppendToFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileParentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileParentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = AppendToFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileRootParentDirectory
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootParentDirectory
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = AppendToFileDirectory(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileBase
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileBase
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = SetFileBase(chars,length);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileRootBase
     *
     *   Author: $author$
     *     Date: 10/15/2009
     **********************************************************************
     */
    virtual tLength OnPathFileRootBase
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = SetFileBase(chars,length);
        SetIsAbsoluteDirectory();
        return count;
    }
    /**
     **********************************************************************
     * Function: OnPathFileExtension
     *
     *   Author: $author$
     *     Date: 10/13/2009
     **********************************************************************
     */
    virtual tLength OnPathFileExtension
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = SetFileExtension(chars,length);
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cFilePathExtends
 *
 *  Author: $author$
 *    Date: 10/12/2009
 **********************************************************************
 */
typedef cFilePathT<>
cFilePathExtends;
/**
 **********************************************************************
 *  Class: cFilePath
 *
 * Author: $author$
 *   Date: 10/12/2009
 **********************************************************************
 */
class cFilePath
: public cFilePathExtends
{
public:
    typedef cFilePathExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cFilePath
     *
     *       Author: $author$
     *         Date: 10/12/2009
     **********************************************************************
     */
    cFilePath
    (const tChar* chars=0,
     tLength length=vUndefinedLength,
     bool onlyChars=false)
    : cExtends(chars, length, onlyChars)
    {
    }
};

/*
 * WCHAR
 */
 
class cWFilePath;
/**
 **********************************************************************
 * Typedef: cWFilePathExtends
 *
 *  Author: $author$
 *    Date: 10/12/2009
 **********************************************************************
 */
typedef cFilePathT
<cWFilePath,
 cWFilePathImplement,
 cWFilePathSeparatorEventsImplement,
 cWToFilePathSeparatorWriter,
 cWCHARStringInterface,
 cWCHARString,
 WCHAR>
cWFilePathExtends;
/**
 **********************************************************************
 *  Class: cWFilePath
 *
 * Author: $author$
 *   Date: 10/12/2009
 **********************************************************************
 */
class cWFilePath
: public cWFilePathExtends
{
public:
    typedef cWFilePathExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cWFilePath
     *
     *       Author: $author$
     *         Date: 10/12/2009
     **********************************************************************
     */
    cWFilePath
    (const tChar* chars=0,
     tLength length=vUndefinedLength,
     bool onlyChars=false)
    : cExtends(chars, length, onlyChars)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILEPATH_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATH_MEMBERS_ONLY) */

#endif /* !defined(_CFILEPATH_HXX) || defined(CFILEPATH_MEMBERS_ONLY) */
