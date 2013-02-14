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
///   File: XosToBGRALibPngReader.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSTOBGRALIBPNGREADER_HPP
#define _XOSTOBGRALIBPNGREADER_HPP

#include "XosToBGRALibPngReaderPeer.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosToBGRALibPngReader
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosToBGRALibPngReader
{
protected:
    XosToBGRALibPngReaderPeer m_peer;

public:
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///
    /// Read PNG image from data buffer, and return BGRA(8) image buffer
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t* Read
    (size_t& width, size_t& height,
     const uint8_t* dataBuffer, size_t dataBufferSize)
    {
        uint8_t* image = m_peer.Read(width, height, dataBuffer, dataBufferSize);
        return image;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Read
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///
    /// Read PNG image from a file, and return BGRA(8) image buffer
    ///////////////////////////////////////////////////////////////////////
    virtual uint8_t* Read
    (size_t& width, size_t& height,
     const char* fileName)
    {
        uint8_t* image = m_peer.Read(width, height, fileName);
        return image;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSTOBGRALIBPNGREADER_HPP 
