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
///   File: XosMacWindowMain.mm
/// 
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
#include "XosMacWindowMain.hh"
#include "XosDebug.hpp"

#if defined(OBJC)  
///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacMainView
///
///       Author: $author$
///         Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacMainView
    - (void)drawRect:(NSRect)rect {
        [[NSColor DEFAULT_IXOSWINDOWMAIN_VIEW_BG_COLOR] set];
        NSRectFill([self bounds]);
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacMainWindow
///
///       Author: $author$
///         Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacMainWindow
    - (NSView*)CreateMainView:(int)argc argv:(char**)argv env:(char**)env {
        XosMacMainView* view = 0;
        if ((view = [[XosMacMainView alloc] init])) {
        }
        return view;
    }
    -(void)windowWillClose:(NSNotification*)notification {
        XOS_DBT(("() [[NSApplication sharedApplication] stop:self]...\n"));
        [[NSApplication sharedApplication] stop:self];
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: XosMacWindowMain
///
///       Author: $author$
///         Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@implementation XosMacWindowMain
    - (XosMacMainWindow*)CreateMainWindow:(int)argc argv:(char**)argv env:(char**)env {
        NSRect rect = NSMakeRect(DEFAULT_IXOSWINDOWMAIN_WINWOW_X,DEFAULT_IXOSWINDOWMAIN_WINWOW_Y, DEFAULT_IXOSWINDOWMAIN_WINWOW_WIDTH, DEFAULT_IXOSWINDOWMAIN_WINWOW_HEIGHT);
        NSUInteger style = NSTitledWindowMask| NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
        NSBackingStoreType backing = NSBackingStoreBuffered;
        XosMacMainWindow* window = 0;
        NSView* view = 0;

        if ((window = [[XosMacMainWindow alloc] initWithContentRect:rect styleMask:style backing:backing defer:NO])) {
            [window setTitle:@DEFAULT_IXOSWINDOWMAIN_WINWOW_TITLE];
            [window setDelegate:window];
            if ((view = [window CreateMainView:argc argv:argv env:env])) {
                [window setContentView:view];
            }
        }
        return window;
    }
    - (int)BeforeRun:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        if ((m_window = [self CreateMainWindow:argc argv:argv env:env])) {
            [m_window makeKeyAndOrderFront: nil];
        }
        return err;
    }
    - (int)AfterRun:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        return err;
    }
    - (int)Run:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        if ((m_pool = [[NSAutoreleasePool alloc] init])) {
            if ((m_app = [NSApplication sharedApplication])) {
                if (!(err = [self BeforeRun:argc argv:argv env:env])) {
                    XOS_DBT(("() [m_app run]...\n"));
                    [m_app run];
                    XOS_DBT(("() ...[m_app run]\n"));
                    err = [self AfterRun:argc argv:argv env:env];
                }
            }
            [m_pool release];
            m_pool = 0;
        }
        return err;
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
