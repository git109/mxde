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
///   File: XosLibPngReadStruct.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSLIBPNGREADSTRUCT_HPP
#define _XOSLIBPNGREADSTRUCT_HPP

#include "XosLibPngStruct.hpp"
#include "XosLibPngInfo.hpp"
#include "XosIStreamInterface.hpp"
#include "XosIBufferFile.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngReadStructExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosLibPngStruct
XosLibPngReadStructExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngReadStruct
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class XosLibPngReadStruct
: public XosLibPngReadStructExtend
{
public:
    typedef XosLibPngReadStructExtend Extends;

    XosByteIBufferFile m_buffer;
    XosByteIStreamInterface& m_in;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngReadStruct
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngReadStruct
    (XosByteIStreamInterface& in,
     png_structp attached=NULL,
     bool isCreated=false) 
    : Extends(attached, isCreated),
      m_in(in)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngReadStruct
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngReadStruct
    (png_structp attached=NULL,
     bool isCreated=false) 
    : Extends(attached, isCreated),
      m_in(m_buffer)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngReadStruct
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngReadStruct()
    {
        XosError error;
        if ((m_attached))
        if ((m_isCreated))
        if ((error = Destroy()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Create
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Create()
    {
        XosError error = XOS_ERROR_FAILED;
        tAttachedTo detached;

        if ((error = Destroyed()))
            return error;

        if ((NULL != (detached = png_create_read_struct
            (PNG_LIBPNG_VER_STRING, ((png_voidp)this), ErrorFn, WarnFn))))
        {
            png_set_read_fn(detached, ((png_voidp)this), ReadFn);
            m_attached = detached;
            m_isCreated = true;
            error = XOS_ERROR_NONE;
        }
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Destroy
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Destroy()
    {
        XosError error = XOS_ERROR_FAILED;
        tAttachedTo detached;

        m_isCreated = false;

        if ((detached = Detach()))
        {
            png_destroy_read_struct
            (&detached, png_infopp_NULL, png_infopp_NULL);
            error = XOS_ERROR_NONE;
        }
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (XosLibPngInfo& pngInfo,
     const char* fileName)
    {
        ssize_t count = 0;
        XosError error;

        if (!(m_attached))
            error = XOS_ERROR_NOT_ATTACHED;
        else
        if ((error = m_buffer.Open(fileName)))
        {
            XOS_DBE(("() failed to open \"%s\"\n", fileName));
            count = -error;
        }
        else
        {
            count = pngInfo.Read();
            if ((error = m_buffer.Close()))
                XOS_DBE(("() failed to close \"%s\"\n", fileName));
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read
    (XosLibPngInfo& pngInfo,
     const uint8_t* buffer,
     size_t size, ssize_t length=-1)
    {
        ssize_t count = 0;
        if (!(m_attached))
            count = -XOS_ERROR_NOT_ATTACHED;
        else
        if ((m_buffer.Attach(buffer, size, length)))
        {
            count = pngInfo.Read();
            m_buffer.Detach();
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AttachBuffer
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const uint8_t* AttachBuffer
    (const uint8_t* buffer, 
     size_t size, ssize_t length=-1)
    {
        m_buffer.Attach(buffer, size, length);
        return buffer;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: DetachBuffer
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const uint8_t* DetachBuffer()
    {
        const uint8_t* buffer = m_buffer.Detach();
        return buffer;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Open
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Open
    (const char* fileName)
    {
        XosError error = XOS_ERROR_FAILED;
        if ((m_attached))
        if ((error = m_buffer.Open(fileName, "rb")))
            XOS_DBE(("() failed to open file \"%s\"\n", fileName));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Close
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError Close()
    {
        XosError error = XOS_ERROR_FAILED;
        if ((m_attached))
        if ((error = m_buffer.Close()))
            XOS_DBE(("() failed to close file\n"));
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnReadFn
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual void OnReadFn
    (png_structp structp,
     png_bytep bytep,
     png_size_t size)
    {
        size_t length;
        XOS_DBT(("() in...\n"));
        if (0 > (length = m_in.Read(bytep, (size_t)(size))))
        {
            XOS_DBE(("() failed to read %d bytes\n", size));
            m_bytesRead = length;
        }
        else
        m_bytesRead += length;
        XOS_DBT(("() ...out\n"));
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: ReadFn
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    static void ReadFn
    (png_structp structp,
     png_bytep bytep,
     png_size_t size)
    {
        png_voidp error_ptr;
        XosLibPngReadStruct* pngReadStruct;
        XOS_DBT(("() in...\n"));
        if ((pngReadStruct = (XosLibPngReadStruct*)
            (error_ptr = png_get_io_ptr(structp))))
            pngReadStruct->OnReadFn(structp, bytep, size);
        XOS_DBT(("() ...out\n"));
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSLIBPNGREADSTRUCT_HPP 
        

