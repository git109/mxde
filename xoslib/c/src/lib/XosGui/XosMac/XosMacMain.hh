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
///   File: XosMacMain.hh
/// 
/// Author: $author$
///   Date: 12/27/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACMAIN_HH
#define _XOSMACMAIN_HH

#include "XosPlatform_cocoa.hh"

#if defined(OBJC)  
///////////////////////////////////////////////////////////////////////
/// Protocol: XosMacMain
///
///   Author: $author$
///     Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@protocol XosMacMain
    - (int)Main:(int)argc argv:(char**)argv env:(char**)env;
    - (void)Release;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: XosMacMain
///
///    Author: $author$
///      Date: 12/20/2012
///////////////////////////////////////////////////////////////////////
@interface XosMacMain: NSObject {
    }
    + (id<XosMacMain>)Allocate;
@end
#else // defined(OBJC)  
#endif // defined(OBJC)  

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSMACMAIN_HH 
        

