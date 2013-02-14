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
///   File: XosMacWindowMain.hh
/// 
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACWINDOWMAIN_HH
#define _XOSMACWINDOWMAIN_HH

#include "XosMacBaseMain.hh"

#define DEFAULT_IXOSWINDOWMAIN_WINWOW_TITLE "XosMacWindowMain"
#define DEFAULT_IXOSWINDOWMAIN_WINWOW_X 0
#define DEFAULT_IXOSWINDOWMAIN_WINWOW_Y 2048
#define DEFAULT_IXOSWINDOWMAIN_WINWOW_WIDTH 256
#define DEFAULT_IXOSWINDOWMAIN_WINWOW_HEIGHT 256

#define DEFAULT_IXOSWINDOWMAIN_VIEW_BG_COLOR whiteColor

#if defined(OBJC)  
///////////////////////////////////////////////////////////////////////
/// Interface: XosMacMainView
///
///    Author: $author$
///      Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacMainView: NSView {
    }
    - (void)drawRect:(NSRect)rect;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: XosMacMainWindow
///
///    Author: $author$
///      Date: 12/21/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacMainWindow: NSWindow <NSWindowDelegate> {
    }
    - (NSView*)CreateMainView:(int)argc argv:(char**)argv env:(char**)env;
    -(void)windowWillClose:(NSNotification*)notification;
@end

///////////////////////////////////////////////////////////////////////
/// Protocol: XosMacWindowMain
///
///   Author: $author$
///     Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@protocol XosMacWindowMain <XosMacMain>
    - (XosMacMainWindow*)CreateMainWindow:(int)argc argv:(char**)argv env:(char**)env;
    - (int)BeforeRun:(int)argc argv:(char**)argv env:(char**)env;
    - (int)AfterRun:(int)argc argv:(char**)argv env:(char**)env;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: XosMacWindowMain
///
///    Author: $author$
///      Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacWindowMain: XosMacBaseMain <XosMacWindowMain> {
    NSAutoreleasePool *m_pool;
    NSApplication *m_app;
    XosMacMainWindow *m_window;
    }
    - (XosMacMainWindow*)CreateMainWindow:(int)argc argv:(char**)argv env:(char**)env;
    - (int)BeforeRun:(int)argc argv:(char**)argv env:(char**)env;
    - (int)AfterRun:(int)argc argv:(char**)argv env:(char**)env;
    - (int)Run:(int)argc argv:(char**)argv env:(char**)env;
@end
#else // defined(OBJC)  
#endif // defined(OBJC)  

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMACWINDOWMAIN_HH 
        

