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
///   File: XosMacHello.mm
/// 
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
#include "XosMacHello.hh"
#include "XosOptMain.hpp"

#if defined(OBJC)  
///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacHelloMainView
///
///       Author: $author$
///         Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacHelloMainView
    - (id)init:(NSRect)rect {
        [super initWithFrame:rect pixelFormat:[NSOpenGLView defaultPixelFormat]];
        m_image = 0;
        m_imageSize=0;
        m_imageFile = XOSMACHELLO_DEFAULT_IMAGE_FILENAME;
        m_imageWidth = XOSMACHELLO_DEFAULT_IMAGE_WIDTH; 
        m_imageHeight = XOSMACHELLO_DEFAULT_IMAGE_HEIGHT; 
        m_imageDepth = XOSMACHELLO_DEFAULT_IMAGE_DEPTH; 
        return self;
    }
    - (void)prepareOpenGL {
        if (!([self LoadImageFile:m_imageFile])) {
            return;
        }
        if ((openglRenderer.init(self))) {
            openglRenderer.prepareOpenGL();
        } else {
            XOS_DBE(("failed on openglRenderer.init()\n"));
            [self FreeImage];
        }
        [super prepareOpenGL];
    }
    - (void)reshape {
        NSRect rect = [self bounds];
        if ((m_image)) {
            openglRenderer.reshape(rect.size.width, rect.size.height);
        }
        [super reshape];
    }
    - (void)drawRect:(NSRect)rect {
        if ((m_image)) {
            openglRenderer.render
            (m_image, m_imageWidth, m_imageHeight,
             m_image, m_imageWidth, m_imageHeight);
        } else {
            [[NSColor XOSMACHELLO_DEFAULT_VIEW_BG_COLOR] set];
            NSRectFill([self bounds]);
        }
    }
    - (void)SetImageFile:(const char*)chars {
        m_imageFile = chars;
    }
    - (void*)LoadImageFile:(const char*)chars {
        if ((chars) && (chars != m_imageFile))
            m_imageFile = chars;

        if ((m_imageFile)) {
            m_imageSize = (m_imageWidth*m_imageHeight*m_imageDepth);
            if ((m_image = malloc(m_imageSize))) {
                FILE* file = 0;
                size_t count = 0;
                if ((file = fopen(m_imageFile, "rb"))) {
                    count = fread(m_image, m_imageSize, 1, file);
                    fclose(file);
                    if (1 > (count)) {
                        XOS_DBE(("failed on fread() of \"%s\"\n", m_imageFile));
                        free(m_image);
                        m_image = 0;
                        m_imageSize = 0;
                    }
                } else {
                    XOS_DBE(("failed on fopen(\"%s\",...)\n", m_imageFile));
                    free(m_image);
                    m_image = 0;
                    m_imageSize = 0;
                }
            } else {
                XOS_DBE(("failed on malloc(%d)\n", m_imageSize));
                m_imageSize = 0;
            }
        }
        return m_image;
    }
    - (void)FreeImage {
        if ((m_image)) {
            free(m_image);
            m_image = 0;
            m_imageSize = 0;
        }
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacHelloMainWindow
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacHelloMainWindow
    - (NSView*)CreateMainView:(int)argc argv:(char**)argv env:(char**)env {
        XosMacHelloMainView* view = 0;
        if ((view = [[XosMacHelloMainView alloc] init:[self frame]])) {
            if ((m_imageFile)) {
                [view SetImageFile:m_imageFile];
            }
        }
        return view;
    }
    - (void)SetImageFile:(const char*)chars {
        m_imageFile = chars;
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacHello
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacHello
    - (XosMacMainWindow*)CreateMainWindow:(int)argc argv:(char**)argv env:(char**)env {
        NSRect superRect = [[NSScreen mainScreen] visibleFrame];
        NSRect rect = NSMakeRect(superRect.origin.x, superRect.size.height, DEFAULT_IXOSWINDOWMAIN_WINWOW_WIDTH, DEFAULT_IXOSWINDOWMAIN_WINWOW_HEIGHT);
        NSUInteger style = NSTitledWindowMask| NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
        NSBackingStoreType backing = NSBackingStoreBuffered;
        XosMacHelloMainWindow* window = 0;
        NSView* view = 0;

        if ((optind < argc))
            m_imageFile = argv[optind];

        if ((window = [[XosMacHelloMainWindow alloc] initWithContentRect:rect styleMask:style backing:backing defer:NO])) {
            [window setTitle:@XOSMACHELLO_DEFAULT_WINDOW_TITLE];
            [window setDelegate:window];
            [window SetImageFile:m_imageFile];
            if ((view = [window CreateMainView:argc argv:argv env:env])) {
                [window setContentView:view];
            }
        }
        return window;
    }
    - (id)init {
        [super init];
        m_imageFile = 0;
        return self;
    }
@end
///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacMain
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacMain
+ (id<XosMacMain>)Allocate {
    return [[XosMacHello alloc] init];
}
@end
#else // defined(OBJC)  
#endif // defined(OBJC)  

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 
