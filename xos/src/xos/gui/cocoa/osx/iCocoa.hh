///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: iCocoa.hh
///
/// Author: $author$
///   Date: 2/2/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_COCOA_OSX_ICOCOA_HH
#define _XOS_GUI_COCOA_OSX_ICOCOA_HH

#include <Cocoa/Cocoa.h>

#define iMakeRect NSMakeRect
#define iMakeSize NSMakeSize
#define iMakeOrigin NSMakeOrigin
#define iApp NSApp

typedef NSArray iArray;
typedef NSRect iRect;
typedef NSSize iSize;
typedef NSPoint iPoint;
typedef NSString iString;
typedef NSObject iObject;
typedef NSView iView;
typedef NSWindow iWindow;
typedef NSApplication iApplication;
typedef NSAutoreleasePool iAutoreleasePool;
typedef NSProcessInfo iProcessInfo;
typedef NSUInteger iWindowStyleMask;
typedef NSBackingStoreType iBackingStoreType;
typedef NSNotification iNotification;
typedef NSOpenGLView iOpenGLView;
typedef NSOpenGLPixelFormat iOpenGLPixelFormat;
typedef NSOpenGLPixelFormatAttribute iOpenGLPixelFormatAttribute;
typedef NSOpenGLContext iOpenGLContext;

typedef NSMenu iMenu;
typedef NSMenuItem iMenuItem;
typedef NSTextField iTextField;
typedef NSButton iPushButton;
typedef NSPopUpButton iPopUpButton;
typedef NSProgressIndicator iProgressIndicator;
typedef NSCell iCell;

typedef NSMenuItem iMenuItem;

typedef NSPasteboard iPasteboard;
#define iFilenamesPboardType NSFilenamesPboardType
typedef NSDragOperation iDragOperation;
@protocol iDraggingInfo <NSDraggingInfo>
@end
enum {
    iDragOperationNone = NSDragOperationNone,
    iDragOperationCopy = NSDragOperationCopy,
    iDragOperationLink = NSDragOperationLink,
    iDragOperationGeneric = NSDragOperationGeneric,
    iDragOperationPrivate = NSDragOperationPrivate,
    iDragOperationAll_Obsolete = NSDragOperationAll_Obsolete,
    iDragOperationMove = NSDragOperationMove,
    iDragOperationDelete = NSDragOperationDelete,
    iDragOperationEvery = NSDragOperationEvery
};

enum {
    iProgressIndicatorBarStyle = NSProgressIndicatorBarStyle
};

#define iSwitchButton NSSwitchButton
#define iRoundedBezelStyle NSRoundedBezelStyle

enum {
    iMixedState = NSMixedState,
    iOffState   = NSOffState,
    iOnState    = NSOnState
};

enum {
    iTitledWindowMask = NSTitledWindowMask,
    iClosableWindowMask = NSClosableWindowMask,
    iMiniaturizableWindowMask = NSMiniaturizableWindowMask,
    iResizableWindowMask = NSResizableWindowMask
};

enum {
    iDefaultDesktopWindowMask
    = iTitledWindowMask | iClosableWindowMask
    | iMiniaturizableWindowMask | iResizableWindowMask
};

enum {
    iBackingStoreBuffered = NSBackingStoreBuffered
};

enum {
    iDefaultDesktopWindowBacking = iBackingStoreBuffered
};

#endif // _XOS_GUI_COCOA_OSX_ICOCOA_HH
