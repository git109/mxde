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
///   File: XosLibPngMain.hpp
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSLIBPNGMAIN_HPP) || defined(XOSLIBPNGMAIN_MEMBERS_ONLY)
#if !defined(_XOSLIBPNGMAIN_HPP) && !defined(XOSLIBPNGMAIN_MEMBERS_ONLY)
#define _XOSLIBPNGMAIN_HPP
#endif // !defined(_XOSLIBPNGMAIN_HPP) && !defined(XOSLIBPNGMAIN_MEMBERS_ONLY) 

#if !defined(XOSLIBPNGMAIN_MEMBERS_ONLY)
#include "XosMain.hpp"
#include "XosToBGRALibPngReader.hpp"
#include "XosLibPngReader.hpp"
#include "XosLibPngImage.hpp"
#include <string>

#define XOSLIBPNGMAIN_FILENAME "XosLibPngImage.png"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosLibPngMainExtend
///
///  Author: $author$
///    Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosMain
XosLibPngMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosLibPngMain
///
/// Author: $author$
///   Date: 5/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosLibPngMain
: public XosLibPngMainExtend
{
public:
    typedef XosLibPngMainExtend Extends;

    std::string m_fileName;
    XosToBGRALibPngReader m_pngReader;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosLibPngMain
    ///
    ///       Author: $author$
    ///         Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosLibPngMain()
    : m_fileName(XOSLIBPNGMAIN_FILENAME)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosLibPngMain
    ///
    ///      Author: $author$
    ///        Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosLibPngMain()
    {
    }
#else // !defined(XOSLIBPNGMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Run
    ///
    ///    Author: $author$
    ///      Date: 5/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(XOSLIBPNGMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSLIBPNGMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(XOSLIBPNGMAIN_MEMBER_FUNCS_IMPLEMENT)
        const char* fileName;
        const uint8_t* imageData;
        size_t imageSize;
        size_t width;
        size_t height;

        if ((fileName = m_fileName.c_str()))
            m_pngReader.Read(width, height, fileName);

        if ((imageData = XosLibPngImage::m_imageData)
            && (imageSize = XosLibPngImage::m_imageSize))
            m_pngReader.Read(width, height, imageData, imageSize);

#else // !defined(XOSLIBPNGMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSLIBPNGMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(XOSLIBPNGMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSLIBPNGMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSLIBPNGMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSLIBPNGMAIN_MEMBERS_ONLY) 

#endif // !defined(_XOSLIBPNGMAIN_HPP) || defined(XOSLIBPNGMAIN_MEMBERS_ONLY) 
