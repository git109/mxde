///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosDLibrary.hpp
///
/// Author: $author$
///   Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSDLIBRARY_HPP
#define _XOSDLIBRARY_HPP

#include "XosPlatform_dlibrary.hpp"
#include "XosOpenedAttached.hpp"
#include "XosInterfaceBase.hpp"
#include "XosInstanceBase.hpp"
#include "XosString.hpp"
#include "XosDebug.hpp"

#if defined(WINDOWS) 
// Windows 
#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosDLibraryAttachedInterface
///
///  Author: $author$
///    Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedInterfaceT
<DLIBRARY, int, INVALID_DLIBRARY, XosInterfaceBase>
XosDLibraryAttachedInterface;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosDLibraryAttached
///
///  Author: $author$
///    Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosAttachedT
<DLIBRARY, int, INVALID_DLIBRARY, XosDLibraryAttachedInterface, XosExportBase>
XosDLibraryAttached;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosDLibraryImplement
///
///  Author: $author$
///    Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosOpenedAttachedInterfaceT
<DLIBRARY, int, INVALID_DLIBRARY, XosDLibraryAttachedInterface>
XosDLibraryImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosDLibraryExtend
///
///  Author: $author$
///    Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosOpenedAttachedT
<DLIBRARY, int, INVALID_DLIBRARY, XosDLibraryImplement, XosDLibraryAttached>
XosDLibraryExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosDLibrary
///
/// Author: $author$
///   Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosDLibrary
: virtual public XosDLibraryImplement,
  public XosDLibraryExtend
{
public:
    typedef XosDLibraryImplement Implements;
    typedef XosDLibraryExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosDLibrary
    ///
    ///       Author: $author$
    ///         Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    XosDLibrary
    (DLIBRARY detached=INVALID_DLIBRARY, bool isOpen=false)
    : Extends(detached, isOpen)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosDLibrary
    ///
    ///      Author: $author$
    ///        Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosDLibrary()
    {
        XosError error;
        if ((error = Closed()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (const std::string& fileName, bool resolve=true, bool global=false)
    {
        XosError error = Open(fileName.c_str(), resolve, global);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (const char* fileName, bool resolve=true, bool global=false)
    {
        XosError error = XOS_ERROR_FAILED;

        if (!fileName || !fileName[0])
            return XOS_ERROR_NULL_PARAMETER;

#if defined(WINDOWS) 
// Windows 
        char c;
        size_t length;
        TCHAR tChar;
        const char* chars;
        const TCHAR* tChars;
        XosTString tFilename;

        for (chars = fileName; (c = *chars); chars++)
        {
            if ('/' == c)
                tChar = (TCHAR)('\\');
            else tChar = (TCHAR)(c);

            tFilename.append(&tChar, 1);
        }

        if (0 < (length = tFilename.length()))
        if ((tChars = tFilename.c_str()))
        if (INVALID_DLIBRARY != (m_attached = LoadLibrary(tChars)))
            error = XOS_ERROR_NONE;
        else 
        XOS_DBE(("() LoadLibrary(\"%s\") error %lu", fileName, GetLastError()));
#else // defined(WINDOWS) 
// Unix 
        int flag = (resolve?RTLD_NOW:RTLD_LAZY)
                   |(global?RTLD_GLOBAL:0);

        if (INVALID_DLIBRARY != (m_attached = dlopen(filename, flag)))
            error = XOS_ERROR_NONE;
        else 
        XOS_DBE(("() dlopen(\"%s\") error \"%s\"\n", fileName, dlerror()));
#endif // defined(WINDOWS) 

        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close()
    {
        XosError error = XOS_ERROR_FAILED;

        if (INVALID_DLIBRARY == m_attached)
            return XOS_ERROR_NOT_ATTACHED;

#if defined(WINDOWS) 
// Windows 
        if (!FreeLibrary(m_attached))
            XOS_DBE(("() FreeLibrary() failed\n"));
#else // defined(WINDOWS) 
// Unix 
        int err;
        if ((err = dlclose(m_attached)))
            XOS_DBE(("() dlclose() failed\n"));
#endif // defined(WINDOWS) 

        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetAddress
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void* GetAddress(const char* symbol) const
    {
        void* address = 0;

        if (!symbol || !symbol[0] || (INVALID_DLIBRARY == m_attached))
            return 0;

#if defined(WINDOWS) 
// Windows 
        address = GetProcAddress(m_attached, symbol);
#else // defined(WINDOWS) 
// Unix 
        address = dlsym(m_attached, symbol);
#endif // defined(WINDOWS) 

        return address;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSDLIBRARY_HPP 
