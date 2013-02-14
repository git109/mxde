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
///   File: XosLibPngInfoReader.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGINFOREADER_HPP) || defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGINFOREADER_HPP) && !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY)
#define _XOSLIBPNGINFOREADER_HPP
#endif // !defined(_XOSLIBPNGINFOREADER_HPP) && !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY)
#include "XosLibPngInfoReaderInterface.hpp"
#include "XosLibPngReadStruct.hpp"
#include "XosLibPngInfo.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoReaderImplement
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngInfoReaderInterface
XosLibPngInfoReaderImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngInfoReaderExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngInfo
XosLibPngInfoReaderExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngInfoReader
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngInfoReader
: virtual public XosLibPngInfoReaderImplement,
  public XosLibPngInfoReaderExtend
{
public:
    typedef XosLibPngInfoReaderImplement Implements;
    typedef XosLibPngInfoReaderExtend Extends;

    XosLibPngReadStruct& m_pngReadStruct;
    
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngInfoReader
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngInfoReader
    (XosLibPngReadStruct& pngReadStruct,
     png_infop attached=0,
     bool isCreated=false)
    : Extends(pngReadStruct, attached, isCreated),
      m_pngReadStruct(pngReadStruct)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngInfoReader
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngInfoReader()
    {
    }
#else // !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = m_pngReadStruct.Create()))
        if ((error = Extends::Create()))
            m_pngReadStruct.Destroy();
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy()
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        XosError error2;
        error = Extends::Destroy();
        if ((error2 = m_pngReadStruct.Destroy()))
        if (!error)
            error = error2;
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachBuffer
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const uint8_t* AttachBuffer
    (const uint8_t* toBuffer, size_t size, ssize_t length=-1)
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        const uint8_t* buffer = 0;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        buffer = m_pngReadStruct.AttachBuffer(toBuffer, size, length);
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return buffer;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DetachBuffer
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const uint8_t* DetachBuffer()
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        const uint8_t* buffer = 0;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        buffer = m_pngReadStruct.DetachBuffer();
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return buffer;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open(const char* fileName)
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        error = m_pngReadStruct.Open(fileName);
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close()
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        error = m_pngReadStruct.Close();
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: ToXosLibPngInfoReader
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosLibPngInfoReader* ToXosLibPngInfoReader()
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosLibPngInfoReader* pngInfoReader = 0;
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
        pngInfoReader = this;
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
        return pngInfoReader;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: CreateInstance
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    static XosLibPngInfoReaderInterface* CreateInstance
    (XosError& error)
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosLibPngInfoReaderInterface* pngInfoReader = 0;
        XosLibPngReadStruct* pngReadStruct = 0;
        
        error = XOS_ERROR_NEW;
        
        if ((pngReadStruct = new XosLibPngReadStruct()))
        {
            if ((pngInfoReader = new XosLibPngInfoReader(*pngReadStruct)))
            {
                error = XOS_ERROR_NONE;
                return pngInfoReader;
            }
            delete pngReadStruct;
        }
        return pngInfoReader;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DestroyInstance
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    static XosError DestroyInstance
    (XosLibPngInfoReaderInterface* instance)
#if defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
    {
        XosError error = XOS_ERROR_FAILED;
        XosLibPngInfoReader* pngInfoReader = 0;
        XosLibPngReadStruct* pngReadStruct = 0;
        if ((pngInfoReader = instance->ToXosLibPngInfoReader()))
        {
            pngReadStruct = &pngInfoReader->m_pngReadStruct;
            delete pngInfoReader;
            delete pngReadStruct;
            error = XOS_ERROR_NONE;
        }
        return error;
    }
#endif // defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGINFOREADER_HPP) || defined(XOSLIBPNGINFOREADER_MEMBERS_ONLY) 
        

