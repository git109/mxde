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
///   File: XosMain.hpp
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_XOSMAIN_HPP) || defined(XOSMAIN_MEMBERS_ONLY)
#if !defined(_XOSMAIN_HPP) && !defined(XOSMAIN_MEMBERS_ONLY)
#define _XOSMAIN_HPP
#endif // !defined(_XOSMAIN_HPP) && !defined(XOSMAIN_MEMBERS_ONLY) 

#if !defined(XOSMAIN_MEMBERS_ONLY)
#include "XosMainInterface.hpp"
#include "XosExportBase.hpp"
#include "XosDebug.hpp"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
/// Typedef: XosMainExtend
///
///  Author: $author$
///    Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
typedef XosExportBase
XosMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosMain
///
/// Author: $author$
///   Date: 11/25/2011
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS XosMain
: virtual public XosMainImplement,
  public XosMainExtend
{
public:
    typedef XosMainImplement Implements;
    typedef XosMainExtend Extends;

    XosMainInterface* m_theOldMain;
    bool m_didMain;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosMain
    ///
    ///       Author: $author$
    ///         Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    XosMain()
    : m_theOldMain(GetTheMain()),
      m_didMain(false)
    {
        SetTheMain(this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosMain
    ///
    ///      Author: $author$
    ///        Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosMain()
    {
        XosMainInterface* theMain;
        if (this == (theMain = GetTheMain()))
            SetTheMain(m_theOldMain);
    }
#else // !defined(XOSMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Run
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char** argv,
     char** env)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: BeforeRun
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int BeforeRun
    (int argc,
     char** argv,
     char** env)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: AfterRun
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int AfterRun
    (int argc,
     char** argv,
     char** env)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: Main
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc,
     char** argv,
     char** env)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
        int err2;
        if (!(err = BeforeRun(argc, argv, env)))
        {
            err = Run(argc, argv, env);

            if ((err2 = AfterRun(argc, argv, env)))
            if (!(err))
                err = err2;
        }
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: OutFormatted
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutFormatted
    (const char* format, ...)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, format);
        if ((format))
        count = OutFormattedV(format, va);
        va_end(va);
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OutFormattedV
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t OutFormattedV
    (const char* format, va_list va)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        ssize_t count = 0;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
        if ((format))
        count = vprintf(format, va);
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return count;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetDidMain
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidMain
    (bool isTrue=true)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
        m_didMain = isTrue;
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        isTrue = false;
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetDidMain
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetDidMain() const
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        bool isTrue = false;
#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
        isTrue = (m_didMain);
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return isTrue;
    }
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT)
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: TheMain
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    static int TheMain
    (int argc,
     char** argv,
     char** env);
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
#else // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(XOSMAIN_MEMBER_FUNCS_IMPLEMENT) 

#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: SetTheMain
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    static XosMainInterface* SetTheMain
    (XosMainInterface* toTheMain);
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
#if defined(XOSMAIN_MEMBER_FUNCS_INTERFACE)
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetTheMain
    ///
    ///    Author: $author$
    ///      Date: 11/25/2011
    ///////////////////////////////////////////////////////////////////////
    static XosMainInterface* GetTheMain();
#else // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 
#endif // defined(XOSMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(XOSMAIN_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(XOSMAIN_MEMBERS_ONLY) 
#endif // !defined(XOSMAIN_MEMBERS_ONLY) 

#endif // !defined(_XOSMAIN_HPP) || defined(XOSMAIN_MEMBERS_ONLY) 
        

