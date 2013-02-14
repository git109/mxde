///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2011 $organization$
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
///   File: XosLibPngStruct.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGSTRUCT_HPP) || defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGSTRUCT_HPP) && !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY)
#define _XOSLIBPNGSTRUCT_HPP
#endif // !defined(_XOSLIBPNGSTRUCT_HPP) && !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY)
#include "XosLibPngStructInterface.hpp"
#include "XosLibPngStructAttached.hpp"
#include "XosLibPngBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngStructImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngStructInterface
XosLibPngStructImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngStructExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngStructAttached
XosLibPngStructExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngStruct
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class XosLibPngStruct
: virtual public XosLibPngStructImplement,
  public XosLibPngStructExtend
{
public:
    typedef XosLibPngStructImplement Implements;
    typedef XosLibPngStructExtend Extends;

    png_int_32 m_bytesRead, m_bytesWritten;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngStruct
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngStruct
    (png_structp attached=NULL,
     bool isCreated=false) 
    : Extends(attached,isCreated),
      m_bytesRead(0), 
      m_bytesWritten(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngStruct
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngStruct()
    {
        XosError error;
        if ((m_attached))
        if ((m_isCreated))
        if ((error = Destroy()))
            throw(error);
    }
#else // !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnError
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnError
    (png_structp structp,
     png_const_charp charp)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        XOS_DBT(("() in...\n"));
        XOS_DBT(("() ...out\n"));
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnWarn
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnWarn
    (png_structp structp,
     png_const_charp charp)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        XOS_DBT(("() in...\n"));
        XOS_DBT(("() ...out\n"));
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ErrorFn
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    static void ErrorFn
    (png_structp structp,
     png_const_charp charp)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
        png_voidp error_ptr;
        XosLibPngStruct* pngStruct;
        XOS_DBT(("() in...\n"));
        if ((pngStruct = (XosLibPngStruct*)
            (error_ptr = png_get_error_ptr(structp))))
            pngStruct->OnError(structp, charp);
        XOS_DBT(("() ...out\n"));
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: WarnFn
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    static void WarnFn
    (png_structp structp,
     png_const_charp charp)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
        png_voidp error_ptr;
        XosLibPngStruct* pngStruct;
        XOS_DBT(("() in...\n"));
        if ((pngStruct = (XosLibPngStruct*)
            (error_ptr = png_get_error_ptr(structp))))
            pngStruct->OnWarn(structp, charp);
        XOS_DBT(("() ...out\n"));
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetBytesRead
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 SetBytesRead
    (png_int_32 toBytes)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 bytes = 0;
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        bytes = m_bytesRead;
        m_bytesRead = toBytes;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
        return bytes;
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetBytesRead
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 GetBytesRead() const
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        return m_bytesRead;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetBytesWritten
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 SetBytesWritten
    (png_int_32 toBytes)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
        png_int_32 bytes = 0;
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        bytes = m_bytesWritten;
        m_bytesWritten = toBytes;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
        return bytes;
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetBytesWritten
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_int_32 GetBytesWritten() const
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        return m_bytesWritten;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        XosError error = XOS_ERROR_NOT_ALLOWED;
        return error;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy()
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        XosError error = XOS_ERROR_NOT_ALLOWED;
        return error;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroyed
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroyed()
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        XosError error = XOS_ERROR_NONE;
        if ((m_attached) && (m_isCreated))
            error = Destroy();
        return error;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_structp Attach
    (png_structp attachedTo,
     bool isCreated=false)
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        m_attached = attachedTo;
        m_isCreated = isCreated;
        return m_attached;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual png_structp Detach()
#if defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        png_structp attached = m_attached;
        m_attached = NULL;
        m_isCreated = false;
        return attached;
#else // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT) 
    }
#endif // defined(XOSLIBPNGSTRUCT_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGSTRUCT_HPP) || defined(XOSLIBPNGSTRUCT_MEMBERS_ONLY) 
