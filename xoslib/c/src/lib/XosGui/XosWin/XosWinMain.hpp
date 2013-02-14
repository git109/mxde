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
///   File: XosWinMain.hpp
///
/// Author: $author$
///   Date: 12/8/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSWINMAIN_HPP) || defined(XOSWINMAIN_MEMBERS_ONLY)
#if !defined(_XOSWINMAIN_HPP) && !defined(XOSWINMAIN_MEMBERS_ONLY)
#define _XOSWINMAIN_HPP
#endif // !defined(_XOSWINMAIN_HPP) && !defined(XOSWINMAIN_MEMBERS_ONLY) 

#if !defined(XOSWINMAIN_MEMBERS_ONLY)
#include "XosWinInterfaceBase.hpp"
#include "XosWinBase.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinMainImplement
///
///  Author: $author$
///    Date: 12/8/2011
///////////////////////////////////////////////////////////////////////
typedef XosInterfaceBase
XosWinMainImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosWinMainExtend
///
///  Author: $author$
///    Date: 12/8/2011
///////////////////////////////////////////////////////////////////////
typedef XosWinBase
XosWinMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosWinMain
///
/// Author: $author$
///   Date: 12/8/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosWinMain
: virtual public XosWinMainImplement,
  public XosWinMainExtend
{
public:
    typedef XosWinMainImplement Implements;
    typedef XosWinMainExtend Extends;

	static XosWinMain* m_theMain;
	XosWinMain* m_theOldMain;

	///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosWinMain
    ///
    ///       Author: $author$
    ///         Date: 12/8/2011
    ///////////////////////////////////////////////////////////////////////
	XosWinMain()
	: m_theOldMain(GetTheMain())
    {
		SetTheMain(this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosWinMain
    ///
    ///      Author: $author$
    ///        Date: 12/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosWinMain()
    {
		XosWinMain* theMain;
		if ((theMain = GetTheMain()) == (this))
			SetTheMain(m_theOldMain);
    }
#else // !defined(XOSWINMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSWINMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnWinMain
    ///
    ///    Author: $author$
    ///      Date: 12/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnWinMain
    (HINSTANCE hInstance,
     HINSTANCE hPrevInstance,
     LPSTR cmdLine,
     int cmdShow)
#if defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TheWinMain
    ///
    ///    Author: $author$
    ///      Date: 12/8/2011
    ///////////////////////////////////////////////////////////////////////
    static int TheWinMain
    (HINSTANCE hInstance,
     HINSTANCE hPrevInstance,
     LPSTR cmdLine,
     int cmdShow)
#if defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
		XosWinMain* theMain;
		if ((theMain = GetTheMain()))
			err = theMain->OnWinMain
			(hInstance, hPrevInstance, cmdLine, cmdShow);
        return err;
    }
#endif // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetTheMain
    ///
    ///    Author: $author$
    ///      Date: 12/8/2011
    ///////////////////////////////////////////////////////////////////////
    virtual XosWinMain* SetTheMain
    (XosWinMain* theMain)
#if defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        m_theMain = theMain;
        return m_theMain;
    }
#endif // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 
#if !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetTheMain
    ///
    ///    Author: $author$
    ///      Date: 12/8/2011
    ///////////////////////////////////////////////////////////////////////
    static XosWinMain* GetTheMain()
#if defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE)
    ;
#else // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        return m_theMain;
    }
#endif // defined(XOSWINMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSWINMAIN_MEMBER_FUNCS_IMPLEMENT) 

#if !defined(XOSWINMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSWINMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSWINMAIN_MEMBERS_ONLY) 

#endif // !defined(_XOSWINMAIN_HPP) || defined(XOSWINMAIN_MEMBERS_ONLY) 
