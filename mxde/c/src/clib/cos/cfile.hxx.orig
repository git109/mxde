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
 *   File: cfile.hxx
 *
 * Author: $author$
 *   Date: 3/14/2009
 **********************************************************************
 */
#if !defined(_CFILE_HXX) || defined(CFILE_MEMBERS_ONLY)
#if !defined(_CFILE_HXX) && !defined(CFILE_MEMBERS_ONLY)
#define _CFILE_HXX
#endif /* !defined(_CFILE_HXX) && !defined(CFILE_MEMBERS_ONLY) */

#if !defined(CFILE_MEMBERS_ONLY)
#include "cstore.hxx"
#include "cstring.hxx"
#include "cfileinterface.hxx"
#include "cplatform_fcntl.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cFile;

#undef CDB_CLASS
#define CDB_CLASS "cFileT"
/**
 **********************************************************************
 *  Class: cFileT
 *
 * Author: $author$
 *   Date: 3/14/2009
 **********************************************************************
 */
template
<class TDerives=cFile,
 class TFileInterface=cFileInterface,
 class TStore=cStore,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TUnattached=INT,
 TUnattached VUnattached=0,
 class TAttachedTo=FILE*,
 class TAttachedInterface=cFILEAttachedInterface,
 class TImplements=TFileInterface,
 class TExtends=TStore>
 
class c_INSTANCE_CLASS cFileT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CFILEINTERFACE_MEMBERS_ONLY
#include "cfileinterface.hxx"
#undef CFILEINTERFACE_MEMBERS_ONLY

    tAttachedTo m_attached;

    /**
     **********************************************************************
     * Constructor: cFileT
     *
     *      Author: $author$
     *        Date: 3/14/2009
     **********************************************************************
     */
    cFileT
    (tAttachedTo attached=((tAttachedTo)(vUnattached))) 
    : m_attached(attached)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cFileT
     *
     *     Author: $author$
     *       Date: 3/14/2009
     **********************************************************************
     */
    virtual ~cFileT()
    {
    }
#else /* !defined(CFILE_MEMBERS_ONLY) */
#endif /* !defined(CFILE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Open
     *
     *    Author: $author$
     *      Date: 3/11/2010
     **********************************************************************
     */
    virtual eError Open
    (const WCHAR* fileName,
     const char* mode="r",
     bool onlyClosed=false)
#if defined(CFILE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILE_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        TLENGTH length;
        const CHAR* nFileNameChars;
        cString nFileName;
        
        if (fileName)
        if (0 < (length = nFileName.AssignWChars(fileName)))
        if ((nFileNameChars = nFileName.HasChars(length)))
            error = Open(nFileNameChars,  mode, onlyClosed);

#else /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/28/2009
     **********************************************************************
     */
    virtual eError Open
    (const char* filename,
     const char* mode="r",
     bool onlyClosed=false) 
#if defined(CFILE_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        tAttachedTo attached;
        if (!mode)
            mode = "r";
        if (filename)
        if ((attached = fopen(filename, mode)))
        {
            Attach(attached);
            error = e_ERROR_NONE;
        }
#else /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/28/2009
     **********************************************************************
     */
    virtual eError Close
    (bool onlyOpened=false) 
#if defined(CFILE_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        tAttachedTo attached;
        int err;
        if ((attached = Detach()))
        if (!(err = fclose(attached)))
            error = e_ERROR_NONE;
#else /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Seek
     *
     *   Author: $author$
     *     Date: 3/14/2009
     **********************************************************************
     */
    virtual tLength Seek
    (tLength count,
     tWhence whence=vWhenceCurrent) 
#if defined(CFILE_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength tell = 0;
#if !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        return tell;
    }
#endif /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Tell
     *
     *   Author: $author$
     *     Date: 3/14/2009
     **********************************************************************
     */
    virtual tLength Tell() const 
#if defined(CFILE_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength tell = 0;
#if !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        return tell;
    }
#endif /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBinaryMode
     *
     *   Author: $author$
     *     Date: 8/18/2009
     **********************************************************************
     */
    virtual int SetBinaryMode
    (bool toOn=true) 
#if defined(CFILE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) 
#if defined(WINDOWS) 
/* Windows
 */
        int isOn = toOn;
        tAttachedTo attached;
        int result;

        if (!(attached = Attached()))
            isOn = -e_ERROR_NOT_ATTACHED;
        else
        if (0 > (result = _setmode
            (_fileno(attached), toOn?_O_BINARY:_O_TEXT)))
            isOn = -e_ERROR_FAILED;
            
#else /* defined(WINDOWS) */
/* Unix
 */
        int isOn = true;
#endif /* defined(WINDOWS) */
#else /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        int isOn = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CFILE_MEMBER_FUNCS_IMPLEMENT) */
        return isOn;
    }
#endif /* defined(CFILE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILE_MEMBERS_ONLY) 
/* include cAttached member functions
 */
#define CATTACHED_MEMBERS_ONLY
#include "cattached.hxx"
#undef CATTACHED_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/27/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size) 
    {
        tLength count = -e_ERROR_FAILED;
        tAttachedTo attached;
        size_t read;

        if (what)
        if ((attached = Attached()))
        if (0 <= (read = fread
            (what, sizeof(tWhat), size, attached)))
            count = (tLength)(read);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 3/27/2009
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* what,
     tLength length=vUndefinedLength) 
    {
        tLength count = -e_ERROR_FAILED;
        tAttachedTo attached;
        size_t written;

        if (!what)
            return 0;

        if (0 > length)
        if (0 > (length = LengthOf(what)))
            return count;

        if ((attached = Attached()))
        if (0 <= (written = fwrite
            (what, sizeof(tWhat), length, attached)))
            count = (tLength)(written);
        return count;
    }
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INSTANCE_CLASS cFile;
/**
 **********************************************************************
 * Typedef: cFileExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileT
<cFile, cFileInterface,
 cStore, CHAR>
cFileExtends;
/**
 **********************************************************************
 *  Class: cFile
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cFile
: public cFileExtends
{
public:
    typedef cFileExtends cExtends;
    typedef cFile cDerives;

    /**
     **********************************************************************
     * Function: WriteFormatted
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual tLength WriteFormatted
    (const tWhat* format,...) 
    {
        tLength count;
        va_list va;

        va_start(va, format);
        count = VWriteFormatted(format, va);
        va_end(va);
        return count;
    }
    /**
     **********************************************************************
     * Function: VWriteFormatted
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual tLength VWriteFormatted
    (const tWhat* format, va_list va) 
    {
        tLength count = e_ERROR_FAILED;
        tAttachedTo attached;
        int written;

        if ((attached = Attached()))
        if (0 <= (written = vfprintf(attached, format, va)))
            count = written;
        return count;
    }
};

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARFile;
/**
 **********************************************************************
 * Typedef: cTCHARFileExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileT
<cTCHARFile, cTCHARFileInterface,
 cTCHARStore, TCHAR>
cTCHARFileExtends;
/**
 **********************************************************************
 *  Class: cTCHARFile
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARFile
: public cTCHARFileExtends
{
public:
    typedef cTCHARFileExtends cExtends;
    typedef cTCHARFile cDerives;
};

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARFile;
/**
 **********************************************************************
 * Typedef: cWCHARFileExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileT
<cWCHARFile, cWCHARFileInterface,
 cWCHARStore, WCHAR>
cWCHARFileExtends;
/**
 **********************************************************************
 *  Class: cWCHARFile
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARFile
: public cWCHARFileExtends
{
public:
    typedef cWCHARFileExtends cExtends;
    typedef cWCHARFile cDerives;
};

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEFile;
/**
 **********************************************************************
 * Typedef: cBYTEFileExtends
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cFileT
<cBYTEFile, cBYTEFileInterface,
 cBYTEStore, BYTE>
cBYTEFileExtends;
/**
 **********************************************************************
 *  Class: cBYTEFile
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEFile
: public cBYTEFileExtends
{
public:
    typedef cBYTEFileExtends cExtends;
    typedef cBYTEFile cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILE_MEMBERS_ONLY) */
#endif /* !defined(CFILE_MEMBERS_ONLY) */

#endif /* !defined(_CFILE_HXX) || defined(CFILE_MEMBERS_ONLY) */
