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
///   File: XosWinLibPngMain.hpp
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINLIBPNGMAIN_HPP) || defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY)
#if !defined(_XOSWINLIBPNGMAIN_HPP) && !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY)
#define _XOSWINLIBPNGMAIN_HPP
#endif // !defined(_XOSWINLIBPNGMAIN_HPP) && !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY) 

#if !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY)
#include "XosDebug.hpp"
#include "WinMainWindowMain.hpp"
#include "XosWinLibPngMainWindow.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinLibPngMainExtend
///
///  Author: $author$
///    Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
typedef WinMainWindowMain
XosWinLibPngMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinLibPngMain
///
/// Author: $author$
///   Date: 11/26/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinLibPngMain
: public XosWinLibPngMainExtend
{
public:
    typedef XosWinLibPngMainExtend Extends;

    XosWinLibPngMainWindow m_mainWindow;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinLibPngMain
    ///
    ///       Author: $author$
    ///         Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    XosWinLibPngMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinLibPngMain
    ///
    ///      Author: $author$
    ///        Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinLibPngMain()
    {
    }
#else // !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY) 

#if !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: GetTheMainWindow
    //
    //    Author: $author$
    //      Date: 11/26/2011
    ///////////////////////////////////////////////////////////////////////
    virtual WinMainWindow& GetTheMainWindow() const
    {
        return (WinMainWindow&)(m_mainWindow);
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY) 

#endif // !defined(_XOSWINLIBPNGMAIN_HPP) || defined(XOSWINLIBPNGMAIN_MEMBERS_ONLY) 
        

