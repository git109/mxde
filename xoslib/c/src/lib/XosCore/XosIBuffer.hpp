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
///   File: XosIBuffer.hpp
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
#ifndef _XOSIBUFFER_HPP
#define _XOSIBUFFER_HPP

#include "XosIStreamInterface.hpp"
#include "XosExportBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosIBufferT
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
template
<class TImplement,
 class TWhat,
 class TExtend=XosExportBase,
 class TSize=size_t,
 class TLength=ssize_t>

class c_EXPORT_CLASS XosIBufferT
: virtual public TImplement,
  public TExtend
{
public:
    typedef TImplement Implements;
    typedef TExtend Extends;

    typedef ssize_t tLength;
    typedef size_t tSize;
    typedef uint8_t tWhat;

    const tWhat* m_readBuffer;
    tSize m_bufferSize;
    tLength m_bufferLength;
    tLength m_bufferTell;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosIBufferT
    ///
    ///       Author: $author$
    ///         Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    XosIBufferT
    (const tWhat* buffer=0,
     tSize size=0,
     tLength length=-1)
    : m_readBuffer(buffer), 
      m_bufferSize(size), 
      m_bufferLength(length), 
      m_bufferTell(0)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tLength Read
    (tWhat* buffer, tSize size)
    {
        tLength count = 0;

        if (size < 1)
            return 0;

        if (!buffer)
            return -XOS_ERROR_NULL_PARAMETER;

        if (!m_readBuffer)
            return -XOS_ERROR_NOT_ATTACHED;

        if (m_bufferTell >= m_bufferLength)
            return 0;

        if (m_bufferTell + (count = (tLength)(size)) >= m_bufferLength)
            size = (tSize)(count = (m_bufferLength - m_bufferTell));

        CopyBuffer(buffer, m_readBuffer+m_bufferTell, size);
        m_bufferTell += count;

        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Attach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const tWhat* Attach
    (const tWhat* buffer,
     tSize size,
     tLength length=-1)
    {
        m_readBuffer = buffer;
        m_bufferSize = size;
        m_bufferLength = length;
        m_bufferTell = 0;
        return m_readBuffer;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Detach
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const tWhat* Detach()
    {
        const tWhat* buffer = m_readBuffer;
        m_readBuffer = 0;
        m_bufferSize = 0;
        m_bufferLength = 0;
        m_bufferTell = 0;
        return buffer;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: CopyBuffer
    ///
    ///    Author: $author$
    ///      Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    virtual tLength CopyBuffer
    (tWhat* to, const tWhat* from, tSize size) const
    {
		tLength length;
        for (length = 0; size > 0; --size, length++)
            (*to++) = (*from++);
        return length;
    }
};

///////////////////////////////////////////////////////////////////////
/// Typedef: XosByteIBufferExtend
///
///  Author: $author$
///    Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
typedef XosIBufferT
<XosByteIStreamInterface, uint8_t>
XosByteIBufferExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosByteIBuffer
///
/// Author: $author$
///   Date: 11/23/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosByteIBuffer
: public XosByteIBufferExtend
{
public:
    typedef XosByteIBufferExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosByteIBuffer
    ///
    ///       Author: $author$
    ///         Date: 11/23/2011
    ///////////////////////////////////////////////////////////////////////
    XosByteIBuffer
    (const uint8_t* bytes=0,
     size_t size=0,
     ssize_t length=-1)
    : Extends(bytes, size, length)
    {
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSIBUFFER_HPP 
        

