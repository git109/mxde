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
///   File: iXosHello.mm
///
/// Author: $author$
///   Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
#include "iXosHello.hh"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#define XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_FILE "frame.raw" 
#define XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_WIDTH 352
#define XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_HEIGHT 288
#define XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_DEPTH 4

NSRect MakeNormalizedRect(const NSSize& F, const NSSize& W) {
    NSRect N;
    if (W.height < W.width) {
        N.size = NSMakeSize(W.height/F.height * F.width, W.height);
    } else {
        N.size = NSMakeSize(W.width, W.width/F.width * F.height);
    }  
    N.origin = NSMakePoint((W.width - N.size.width) / 2.0f, (W.height - N.size.height) / 2.0f);
    N.origin.x /= W.width;      N.origin.y /= W.height;
    N.size.width /= W.width;    N.size.height /= W.height;
    return N;
}

///////////////////////////////////////////////////////////////////////
/// Implentation: iXosHelloMainView
///
///       Author: $author$
///         Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@implementation iXosHelloMainView
    - (id)init:(NSRect)rect {
        [super initWithFrame:rect pixelFormat:[NSOpenGLView defaultPixelFormat]];
        m_preparedOpenGL = false;
        m_image = 0;
        m_imageFile = XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_FILE;
        m_imageWidth = XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_WIDTH; 
        m_imageHeight = XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_HEIGHT; 
        m_imageDepth = XOS_GUI_COCOA_IXOSHELLO_DEFAULT_IMAGE_DEPTH; 
        m_imageSize = 0;
        return self;
    }
    - (void)prepareOpenGL {
        xos::gui::opengl::ContextImplemented openglContextImpl(self);

        if (!(m_image = [self ReadImageFile]))
            return;

        if ((openglRenderer.Init(openglContextImpl))) {
            openglRenderer.Prepare();
            return;
        }

        openglContext.Init(openglContextImpl);

        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, m_imageWidth, m_imageHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, m_image);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1, 0, 1);
        glDisable(GL_DEPTH_TEST);
        glDepthFunc(GL_ALWAYS);
        glDisable(GL_CULL_FACE);
        glViewport( 0, 0, m_imageWidth, m_imageHeight);

        m_preparedOpenGL = true;
        free(m_image);
        m_image = 0;
    }
    - (void)reshape {
        NSRect rect = [self bounds];
        if ((m_preparedOpenGL)) {
            glViewport( 0, 0, rect.size.width, rect.size.height);
        } else {
            openglRenderer.Reshape(rect.size.width, rect.size.height);
        }
        [super reshape];
    }
    - (void)drawRect:(NSRect)rect {
        if ((m_preparedOpenGL)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_TEXTURE_2D);

            glMatrixMode (GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0, 1, 1, 0);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glBindTexture(GL_TEXTURE_2D, m_texture);

            {
                NSSize F = NSMakeSize(m_imageWidth, m_imageHeight);
                NSSize W = [self bounds].size;
                NSRect N = MakeNormalizedRect(F, W);
                NSPoint p = N.origin;
                NSSize s = N.size;

	            glBegin(GL_QUADS);
	            glTexCoord2f(0.0f, 0.0f); glVertex2f(p.x, p.y);
	            glTexCoord2f(1.0f, 0.0f); glVertex2f(p.x + s.width, p.y);
	            glTexCoord2f(1.0f, 1.0f); glVertex2f(p.x + s.width, p.y + s.height);
	            glTexCoord2f(0.0f, 1.0f); glVertex2f(p.x, p.y + s.height);
	            glEnd();
            }
            glFlush();
            [[self openGLContext ] flushBuffer ];
        } else {
            if ((m_image)) {
                openglRenderer.Render
                (m_image, m_imageWidth, m_imageHeight,
                 m_image, m_imageWidth, m_imageHeight);
            } else {
                [[NSColor DEFAULT_IXOSHELLO_VIEW_BG_COLOR] set];
                NSRectFill([self bounds]);
            }
        }
    }
    - (void)SetImageFile:(const char*)chars {
        m_imageFile = chars;
    }
    - (void*)ReadImageFile {
        XOS_LOG_DEBUG(" read image file \"" << m_imageFile << "\"...");
        if ((m_image = malloc(m_imageSize=(m_imageWidth*m_imageHeight*m_imageDepth)))) {
            FILE* file = 0;
            size_t count = 0;
            if ((file = fopen(m_imageFile, "rb"))) {
                count = fread(m_image, m_imageSize, 1, file);
                fclose(file);
                if (1 > (count)) {
                    XOS_LOG_ERROR("failed on fread() of \"" << m_imageFile << "\"");
                    free(m_image);
                    m_image = 0;
                }
            } else {
                XOS_LOG_ERROR("failed on fopen(\"" << m_imageFile << "\",...)");
                free(m_image);
                m_image = 0;
            }
        }
        return m_image;
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: iXosHelloMainWindow
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation iXosHelloMainWindow
    - (NSView*)CreateMainView:(int)argc argv:(char**)argv env:(char**)env {
        iXosHelloMainView* view = 0;
        if ((view = [[iXosHelloMainView alloc] init:[self frame]])) {
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
/// Implentation: iXosHello
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation iXosHello
    - (iXosMainWindow*)CreateMainWindow:(int)argc argv:(char**)argv env:(char**)env {
        NSRect superRect = [[NSScreen mainScreen] visibleFrame];
        NSRect rect = NSMakeRect(superRect.origin.x, superRect.size.height, DEFAULT_IXOSWINDOWMAIN_WINWOW_WIDTH, DEFAULT_IXOSWINDOWMAIN_WINWOW_HEIGHT);
        NSUInteger style = NSTitledWindowMask| NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
        NSBackingStoreType backing = NSBackingStoreBuffered;
        iXosHelloMainWindow* window = 0;
        NSView* view = 0;

        if ((window = [[iXosHelloMainWindow alloc] initWithContentRect:rect styleMask:style backing:backing defer:NO])) {
            [window setTitle:@DEFAULT_IXOSWINDOWMAIN_WINWOW_TITLE];
            [window setDelegate:window];
            [window SetImageFile:m_imageFile];
            if ((view = [window CreateMainView:argc argv:argv env:env])) {
                [window setContentView:view];
            }
        }
        return window;
    }
    - (int)OnOption:(int)optval optarg:(const char*)optarg optname:(const char*)optname optind:(int)optind 
               argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        switch(optval) {
        case 'f':
            m_imageFile = optarg;
            break;
        default:
            err = [super OnOption:optval optarg:optarg optname:optname optind:optind
                   argc:argc argv:argv env:env];
        }
        return err;
    }
    - (const char*)OptionUsage:(const char*&)optarg longopt:(const struct option*)longopt {
        const char* chars = "";
        switch(longopt->val) {
        case 'f':
            optarg = "filename";
            chars = "Image filename";
            break;
        default:
            chars = [super OptionUsage:optarg longopt:longopt];
        }
        return chars;
    }
    - (const char*)Options:(const struct option*&)longopts {
        static const char* chars = "f:" XOS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            {"image-file", XOS_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'f'},\
            XOS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    - (id)init {
        [super init];
        m_imageFile = 0;
        return self;
    }
@end
///////////////////////////////////////////////////////////////////////
/// Implentation: iXosMain
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation iXosMain
+ (id<iXosMain>)Allocate {
    return [[iXosHello alloc] init];
}
@end
