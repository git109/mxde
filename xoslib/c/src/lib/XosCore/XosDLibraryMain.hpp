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
///   File: XosDLibraryMain.hpp
///
/// Author: $author$
///   Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSDLIBRARYMAIN_HPP
#define _XOSDLIBRARYMAIN_HPP

#include "XosInterfaceBase.hpp"
#include "XosExportBase.hpp"

#if defined(WINDOWS) 
// Windows 
#else // defined(WINDOWS) 
// Unix 
#endif // defined(WINDOWS) 

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosDLibraryMainImplement
///
///  Author: $author$
///    Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosDLibraryMainImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosDLibraryMainExtend
///
///  Author: $author$
///    Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosDLibraryMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosDLibraryMain
///
/// Author: $author$
///   Date: 12/9/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosDLibraryMain
: virtual public XosDLibraryMainImplement,
  public XosDLibraryMainExtend
{
public:
    typedef XosDLibraryMainImplement Implements;
    typedef XosDLibraryMainExtend Extends;

    XosDLibraryMain* m_oldDLibraryMain;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosDLibraryMain
    ///
    ///       Author: $author$
    ///         Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    XosDLibraryMain()
    : m_oldDLibraryMain(GetDLibraryMain())
    {
        GetDLibraryMain() = (this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosDLibraryMain
    ///
    ///      Author: $author$
    ///        Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosDLibraryMain()
    {
        if ((this) == GetDLibraryMain())
            GetDLibraryMain() = m_oldDLibraryMain;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Init
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init()
    {
        bool isTrue = true;
        return isTrue;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Finish
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool Finish()
    {
        bool isTrue = true;
        return isTrue;
    }

    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDLibraryMain
    ///
    ///    Author: $author$
    ///      Date: 12/9/2012
    ///////////////////////////////////////////////////////////////////////
    static XosDLibraryMain*& GetDLibraryMain();
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSDLIBRARYMAIN_HPP 
        

