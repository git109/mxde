/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cargmain.hxx
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
#ifndef _CARGMAIN_HXX
#define _CARGMAIN_HXX

#include "cmain.hxx"
#include "cmainarg.hxx"
#include "csplitter.hxx"

class cArgMain;

#undef CDB_CLASS
#define CDB_CLASS "cArgMainT"
/**
 **********************************************************************
 *  Class: cArgMainT
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
template
<class TDerives=cArgMain,
 class TMain=cMain,
 class TMainArg=cMainArg,
 class TMainArgList=cMainArgList,
 class TMainArgItem=cMainArgItem,
 class TSplitter=cSplitter,
 class TString=cString,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TExtends=TMain>
 
class cArgMainT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

    typedef TString tString;
    typedef TSplitter tSplitter;
    typedef TMainArg tMainArg;
    typedef TMainArgList tMainArgList;

    const tChar m_minus;
    const tChar m_equal;
    int m_unnamedArgs;
    bool m_didMainArg;
    tString m_argName;

    /**
     **********************************************************************
     * Constructor: cArgMainT
     *
     *      Author: $author$
     *        Date: 3/4/2009
     **********************************************************************
     */
    cArgMainT() 
    : m_minus('-'),
      m_equal('='),
      m_unnamedArgs(0),
      m_didMainArg(false)
    {
    }
    /**
     **********************************************************************
     * Function: Begin
     *
     *   Author: $author$
     *     Date: 3/11/2009
     **********************************************************************
     */
    virtual tInt Begin
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt err = 0;
        tInt args;
        if (0 > (args = MainArgs(argc, argv, env)))
            err = 1;
        return err;
    }
    /**
     **********************************************************************
     * Function: MainArgs
     *
     *   Author: $author$
     *     Date: 3/11/2009
     **********************************************************************
     */
    virtual tInt MainArgs
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        tInt argn, argon, args;
        const TChar *arg;

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
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 3/11/2009
     **********************************************************************
     */
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
    /**
     **********************************************************************
     * Function: MainArg0
     *
     *   Author: $author$
     *     Date: 3/11/2009
     **********************************************************************
     */
    virtual tInt MainArg0
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArgn
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual tInt MainArgn
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) 
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainArgSwitch
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
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
    /**
     **********************************************************************
     * Function: MainArgShort
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
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
    /**
     **********************************************************************
     * Function: MainArgLong
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
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

    /**
     **********************************************************************
     * Function: SetDidMainArg
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual bool SetDidMainArg
    (bool did=true) 
    {
        m_didMainArg = did;
        return m_didMainArg;
    }
    /**
     **********************************************************************
     * Function: GetDidMainArg
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual bool GetDidMainArg() const 
    {
        return m_didMainArg;
    }

    /**
     **********************************************************************
     * Function: GetList
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual tMainArgList& GetList() const
    {
        return tMainArg::m_list;
    }
};
#undef CDB_CLASS

class cArgMain;
/**
 **********************************************************************
 * Typedef: cArgMainExtends
 *
 *  Author: $author$
 *    Date: 3/4/2009
 **********************************************************************
 */
typedef cArgMainT
<cArgMain, 
 cMain,
 cMainArg,
 cMainArgList,
 cMainArgItem,
 cSplitter,
 cString,
 char, int>
cArgMainExtends;
/**
 **********************************************************************
 *  Class: cArgMain
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
class cArgMain
: public cArgMainExtends
{
public:
    typedef cArgMainExtends cExtends;
    typedef cArgMain cDerives;
};

/*
 * tmain
 */
class cArgTMain;
/**
 **********************************************************************
 * Typedef: cArgTMainExtends
 *
 *  Author: $author$
 *    Date: 3/4/2009
 **********************************************************************
 */
typedef cArgMainT
<cArgTMain,
 cTMain,
 cTMainArg,
 cTMainArgList,
 cTMainArgItem,
 cTSplitter,
 cTString,
 TCHAR, int>
cArgTMainExtends;
/**
 **********************************************************************
 *  Class: cArgTMain
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
class cArgTMain
: public cArgTMainExtends
{
public:
    typedef cArgTMainExtends cExtends;
    typedef cArgTMain cDerives;
};
#endif /* _CARGMAIN_HXX */
