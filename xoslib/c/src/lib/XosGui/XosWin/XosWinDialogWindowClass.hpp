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
///   File: XosWinDialogWindowClass.hpp
///
/// Author: $author$
///   Date: 1/29/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSWINDIALOGWINDOWCLASS_HPP
#define _XOSWINDIALOGWINDOWCLASS_HPP

#include "XosWinWindowClass.hpp"

#define XOSWINDIALOGWINDOWCLASS_CLASSNAME_CHARS "XosWinDialogWindowClass"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinDialogWindowClassExtend
///
///  Author: $author$
///    Date: 1/29/2012
///////////////////////////////////////////////////////////////////////
typedef XosWinWindowClass
XosWinDialogWindowClassExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinDialogWindowClass
///
/// Author: $author$
///   Date: 1/29/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosWinDialogWindowClass
: public XosWinDialogWindowClassExtend
{
public:
    typedef XosWinDialogWindowClassExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinDialogWindowClass
    ///
    ///       Author: $author$
    ///         Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    XosWinDialogWindowClass
    (LPCTSTR windowClassNameChars=_T(XOSWINDIALOGWINDOWCLASS_CLASSNAME_CHARS),
     WNDPROC wndProc=DefDlgProc,
     int windowExtra=WindowExtra(),
     int windowExtraOffset=WindowExtraOffset()) 
    : Extends
      (windowClassNameChars, wndProc, 
       windowExtra, windowExtraOffset)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinDialogWindowClass
    ///
    ///      Author: $author$
    ///        Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinDialogWindowClass()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: WindowExtra
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    static int WindowExtra()
    {
        int count = WindowExtraOffset()+(int)(sizeof(XosWinInterfaceBase*));
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: WindowExtraOffset
    ///
    ///    Author: $author$
    ///      Date: 1/29/2012
    ///////////////////////////////////////////////////////////////////////
    static int WindowExtraOffset()
    {
        int count = DLGWINDOWEXTRA;
        return count;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSWINDIALOGWINDOWCLASS_HPP 
        

