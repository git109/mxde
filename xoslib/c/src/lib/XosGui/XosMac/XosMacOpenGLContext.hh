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
///   File: XosMacOpenGLContext.hh
///
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACOPENGLCONTEXT_HH
#define _XOSMACOPENGLCONTEXT_HH

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"
#include "XosPlatform_cocoa.hh"
#include "XosPlatform_opengl.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosMacOpenGLContextImplement
///
///  Author: $author$
///    Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosMacOpenGLContextImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosMacOpenGLContextExtend
///
///  Author: $author$
///    Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosMacOpenGLContextExtend;

///////////////////////////////////////////////////////////////////////
///  Class: XosMacOpenGLContext
///
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosMacOpenGLContext
: virtual public XosMacOpenGLContextImplement,
  public XosMacOpenGLContextExtend
{
public:
    typedef XosMacOpenGLContextImplement Implements;
    typedef XosMacOpenGLContextExtend Extends;

    XosMacOpenGLContext() {}
    virtual ~XosMacOpenGLContext() {}

    virtual bool Init(NSOpenGLView* view) {
        bool isSuccess = false;
        NSOpenGLPixelFormatAttribute* pixelFormatAttributes;
        NSOpenGLPixelFormat* pixelFormat;
        if ((m_view = view)) {
            if ((pixelFormatAttributes = GetPixelFormatAttributes())) {
                if ((m_pixelFormat = GetPixelFormat())) {
                    if ((pixelFormat = AcquirePixelFormat(pixelFormatAttributes))) {
                        isSuccess = !(pixelFormat != SetPixelFormat(pixelFormat));
                        ReleasePixelFormat(pixelFormat);
                        return isSuccess;
                    }
                    m_pixelFormat = 0;
                }
            }
            m_view = 0;
        }
        return isSuccess;
    }
    virtual bool Finish() {
        bool isSuccess = false;
        if ((m_pixelFormat)) {
            isSuccess = !(m_pixelFormat != SetPixelFormat(m_pixelFormat));
            m_pixelFormat = 0;
        }
        m_view = 0;
        return isSuccess;
    }

    NSOpenGLPixelFormat* AcquirePixelFormat(NSOpenGLPixelFormatAttribute* attributes) const;
    bool ReleasePixelFormat(NSOpenGLPixelFormat* pixelFormat) const;

    NSOpenGLPixelFormat* SetPixelFormat(NSOpenGLPixelFormat* toPixelFormat);
    NSOpenGLPixelFormat* GetPixelFormat() const;

    NSOpenGLContext* GetContext() const;
    NSOpenGLPixelFormatAttribute* GetPixelFormatAttributes() const;

protected:
    NSOpenGLView* m_view;
    NSOpenGLPixelFormat* m_pixelFormat;
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMACOPENGLCONTEXT_HH 
        

