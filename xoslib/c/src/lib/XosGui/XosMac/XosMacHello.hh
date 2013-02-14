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
///   File: XosMacHello.hh
/// 
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACHELLO_HH
#define _XOSMACHELLO_HH

#include "XosMacWindowMain.hh"
#include "XosNSOpenGLViewTexture2DImageRenderer.hh"

#define XOSMACHELLO_DEFAULT_WINDOW_TITLE "Hello"
#define XOSMACHELLO_DEFAULT_VIEW_BG_COLOR redColor

#define XOSMACHELLO_DEFAULT_IMAGE_FILENAME "image.raw"
#define XOSMACHELLO_DEFAULT_IMAGE_WIDTH 352
#define XOSMACHELLO_DEFAULT_IMAGE_HEIGHT 288
#define XOSMACHELLO_DEFAULT_IMAGE_DEPTH 4

#if defined(OBJC)  
///////////////////////////////////////////////////////////////////////
/// Interface: XosMacHelloMainView
///
///    Author: $author$
///      Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacHelloMainView: NSOpenGLView {
    void* m_image;
    const char* m_imageFile;
    unsigned m_imageWidth, m_imageHeight, m_imageDepth, m_imageSize;
    XosNSOpenGLViewTexture2DImageRenderer openglRenderer;
    }
    - (id)init:(NSRect)rect;
    - (void)prepareOpenGL;
    - (void)reshape;
    - (void)drawRect:(NSRect)rect;
    - (void)SetImageFile:(const char*)chars;
    - (void*)LoadImageFile:(const char*)chars;
    - (void)FreeImage;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: XosMacHelloMainWindow
///
///    Author: $author$
///      Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacHelloMainWindow: XosMacMainWindow {
    const char* m_imageFile;
    }
    - (NSView*)CreateMainView:(int)argc argv:(char**)argv env:(char**)env;
    - (void)SetImageFile:(const char*)chars;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: XosMacHello
///
///    Author: $author$
///      Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacHello: XosMacWindowMain {
    const char* m_imageFile;
    }
    - (XosMacMainWindow*)CreateMainWindow:(int)argc argv:(char**)argv env:(char**)env;
@end
#else // defined(OBJC)  
#endif // defined(OBJC)  

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMACHELLO_HH 
        

