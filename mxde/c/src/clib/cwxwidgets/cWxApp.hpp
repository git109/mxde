///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2010 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cWxApp.hpp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
#if !defined(_CWXAPP_HPP) || defined(CWXAPP_MEMBERS_ONLY)
#if !defined(_CWXAPP_HPP) && !defined(CWXAPP_MEMBERS_ONLY)
#define _CWXAPP_HPP
#endif // !defined(_CWXAPP_HPP) && !defined(CWXAPP_MEMBERS_ONLY) 

#if !defined(CWXAPP_MEMBERS_ONLY)
#include "cWxMainArg.hpp"
#include "wx/app.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cWxAppImplement
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
//typedef wxAppImplement
//cWxAppImplement;
///////////////////////////////////////////////////////////////////////
// Typedef: cWxAppExtend
//
//  Author: $author$
//    Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
typedef wxApp
cWxAppExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cWxApp
//
// Author: $author$
//   Date: 8/28/2010
///////////////////////////////////////////////////////////////////////
class cWxApp
: //virtual public cWxAppImplement,
  public cWxAppExtend
{
public:
    //typedef cWxAppImplement cImplements;
    typedef cWxAppExtend cExtends;

    typedef cWxMainArgList tMainArgList;
    typedef cWxMainArgItem tMainArgItem;
    typedef cWxMainArg tMainArg;
    typedef cWxCharString tString;
    typedef wxChar tChar;
    typedef int tInt;
    typedef TLENGTH tLength;

    const tChar m_minus;
    const tChar m_equal;
    int m_unnamedArgs;
    bool m_didMainArg;
    tString m_argName;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cWxApp
    //
    //       Author: $author$
    //         Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    cWxApp()
    : m_minus('-'),
      m_equal('='),
      m_unnamedArgs(0),
      m_didMainArg(false)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cWxApp
    //
    //      Author: $author$
    //        Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual ~cWxApp()
    {
    }
#else // !defined(CWXAPP_MEMBERS_ONLY) 
#endif // !defined(CWXAPP_MEMBERS_ONLY) 

#if !defined(CWXAPP_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 7/6/2013
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArgs
    (tInt argc,
     tChar** argv,
     tChar** env) 
    {
        tInt args = MainArgs
        (argc, (const tChar**)(argv), (const tChar**)(env));
        return args;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArgs
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt argn, argon, args;
        const tChar *arg;

        for (args = argon = argn = 0; argn < argc; argon = ++argn)
        {
            if (!(arg = argv[argn]))
                return -e_ERROR_NULL_PARAMETER;

            if ((argn = MainArg
                (args, argn, arg, argc, argv, env)) < argon)
            {
                if (argn >= 0)
                    return -e_ERROR_INVALID_RETURN;

                return argn;
            }
            ++args;
        }
        return args;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArg
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        if (1 > argn)
            return argn = MainArg0
            (args, argn, arg, argc, argv, env);

        if (m_minus != arg[0])
            return argn = MainArgn
            (args, argn, arg, argc, argv, env);

        argn = MainArgSwitch
        (args, argn, arg+1, argc, argv, env);
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArg0
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArgn
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArgSwitch
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        if (m_minus != arg[0])
            return argn = MainArgShort
            (args, argn, arg, argc, argv, env);

        argn = MainArgLong
        (args, argn, arg+1, argc, argv, env);
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArgShort
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        tInt argon = argn;
        const tMainArg* mainArg;
        const tChar* argNameChars;
        tChar argNameChar;
        tLength argNameLength;

        if (0 < (argNameLength = m_argName.Assign(arg, 1)))
        if ((argNameChars = m_argName.HasChars(argNameLength)))
        {
            tMainArgList& list = GetList();
            if (!(argNameChar = *(++arg)))
                arg = 0;
            if ((mainArg = list.FindFirstArgByShortName(argNameChars)))
            if (argon <= (argn = mainArg->MainArg(args, argn, arg, argc, argv, env)))
                SetDidMainArg();
        }
        return argn;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tInt MainArgLong
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        tInt argon = argn;
        const tMainArg* mainArg;
        const tChar* argNameChars;
        tLength argNameLength;

        if (0 < (argNameLength = m_argName.Assign(arg)))
        if ((argNameChars = m_argName.HasChars(argNameLength)))
        {
            tMainArgList& list = GetList();
            arg = 0;
            if ((mainArg = list.FindFirstArgByName(argNameChars)))
            if (argon <= (argn = mainArg->MainArg(args, argn, arg, argc, argv, env)))
                SetDidMainArg();
        }
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDidMainArg
    (bool did=true) 
    {
        m_didMainArg = did;
        return m_didMainArg;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetDidMainArg() const 
    {
        return m_didMainArg;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: 
    //
    //   Author: $author$
    //     Date: 8/28/2010
    ///////////////////////////////////////////////////////////////////////
    virtual tMainArgList& GetList() const
    {
        return tMainArg::m_list;
    }
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CWXAPP_MEMBERS_ONLY) 
#endif // !defined(CWXAPP_MEMBERS_ONLY) 

#endif // !defined(_CWXAPP_HPP) || defined(CWXAPP_MEMBERS_ONLY) 
