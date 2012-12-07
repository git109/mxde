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
 *   File: cmainarg.hxx
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
#if !defined(_CMAINARG_HXX) || defined(CMAINARG_MEMBERS_ONLY)
#if !defined(_CMAINARG_HXX) && !defined(CMAINARG_MEMBERS_ONLY)
#define _CMAINARG_HXX
#endif /* !defined(_CMAINARG_HXX) && !defined(CMAINARG_MEMBERS_ONLY) */

#if !defined(CMAINARG_MEMBERS_ONLY)
/* cMainArg definition
 */
#include "cmaininterface.hxx"
#include "cmainarginterface.hxx"
#include "cmainarglist.hxx"
#include "cstring.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#undef CDB_CLASS
#define CDB_CLASS "cMainArgT"
/**
 **********************************************************************
 *  Class: cMainArgT
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
template
<class TDerives=cMainArg,
 class TMainArgImplement=cMainArgImplement,
 class TMainArgList=cMainArgList,
 class TMainArgItem=cMainArgItem,
 class TString=cString,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cExportBase,
 class TImplements=TMainArgImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cMainArgT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

    typedef cTypesT<tChar> tChars;
    typedef TString tString;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    static TMainArgList m_list;
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    TMainArgItem m_item;

    tChar m_minus;
    tChar m_nullChar;
	tString m_shortName;
	tString m_name;
	tString m_description;
	tString m_parameters;

    /**
     **********************************************************************
     * Constructor: cMainArgT
     *
     *      Author: $author$
     *        Date: 3/4/2009
     **********************************************************************
     */
    cMainArgT
    (const tChar* shortName,
     const tChar* name,
     const tChar* description=0,
     const tChar* parameters=0) 
    : m_item((TDerives&)(*this)), 
      m_minus('-'),
      m_nullChar(0)
    {
        eError error;
        tLength length;

        if (shortName)
        if (0 > (length = SetShortName(shortName)))
            throw (error = -length);

        if (name)
        if (0 > (length = SetName(name)))
            throw (error = -length);

        if (description)
        if (0 > (length = SetDescription(description)))
            throw (error = -length);

        if (parameters)
        if (0 > (length = SetParameters(parameters)))
            throw (error = -length);

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
        m_list.AddItem(m_item);
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     * Destructor: ~cMainArgT
     *
     *     Author: $author$
     *       Date: 3/4/2009
     **********************************************************************
     */
    virtual ~cMainArgT()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
        m_list.DeleteItem(m_item);
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
#else /* !defined(CMAINARG_MEMBERS_ONLY) */
#endif /* !defined(CMAINARG_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: MainArgs
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual tInt MainArgs
    (tInt argc,
     const tChar** argv,
     const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
        tInt argn = 0;
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
        tInt argon, args;
        const TChar *arg;

        for (args = argon = argn = 0; argn < argc; argon = ++argn)
        {
            if (!(arg = argv[argn]))
                return -e_ERROR_NULL_PARAMETER;

            if ((argn = MainArgDispatch
                (args, argn, arg, argc, argv, env)) < argon)
            {
                if (argn >= 0)
                    return -e_ERROR_INVALID_RETURN;

                return argn;
            }
            ++args;
        }
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: MainArgDispatch
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual tInt MainArgDispatch
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
        if (1 > argn)
            return argn = MainArg0
            (args, argn, arg, argc, argv, env);

        if (m_minus != arg[0])
            return argn = MainArgn
            (args, argn, arg, argc, argv, env);

        argn = MainArgSwitch
        (args, argn, arg+1, argc, argv, env);
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: MainArg0
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual tInt MainArg0
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
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
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
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
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
        if (m_minus != arg[0])
            return argn = MainArgShort
            (args, argn, arg, argc, argv, env);

        argn = MainArgLong
        (args, argn, arg+1, argc, argv, env);
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
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
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
        int unequal;
        tLength argNameLength;
        tChar argNameChar;
        const tChar* argNameChars;
        tString argName;

        if (0 < (argNameLength = argName.Assign(arg, 1)))
        if ((argNameChars = argName.HasChars(argNameLength)))
        {
            if (!(argNameChar = *(++arg)))
                arg = 0;
            if (!(unequal = CompareShortName(argNameChars)))
                argn = MainArgArg(args, argn, arg, argc, argv, env);
        }
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
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
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
        int unequal;
        tLength argNameLength;
        const tChar* argNameChars;
        tString argName;

        if (0 < (argNameLength = argName.Assign(arg)))
        if ((argNameChars = argName.HasChars(argNameLength)))
        {
            arg = 0;
            if (!(unequal = CompareName(argNameChars)))
                argn = MainArgArg(args, argn, arg, argc, argv, env);
        }
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: MainArgArg
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual tInt MainArgArg
    (tInt args, tInt argn, const tChar *arg, 
     tInt argc, const tChar** argv, const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
        argn = MainArg(args, argn, arg, argc, argv, env);
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tInt MainArg
    (tInt args,
     tInt argn,
     const tChar* arg,
     tInt argc,
     const tChar** argv,
     const tChar** env) const
#if defined(CMAINARG_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAINARG_MEMBER_FUNCS_IMPLEMENT) */
        return argn;
    }
#endif /* defined(CMAINARG_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMAINARG_MEMBERS_ONLY) 
    /**
     **********************************************************************
     * Function: MainArgParam
     *
     *   Author: $author$
     *     Date: 3/12/2009
     **********************************************************************
     */
    virtual const tChar* MainArgParam
    (tInt &argn, const tChar*& arg, 
     tInt argc, const tChar** argv) const
    {
        const tChar* argParam = arg;
        if (!argParam && (argn+1 < argc))
            argParam = argv[++argn];
        arg = 0;
        return argParam;
    }

    /**
     **********************************************************************
     * Function: SetShortName
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tLength SetShortName
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = m_shortName.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetShortName
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tChar* GetShortName
    (tLength& length) const 
    {
        const tChar* chars = m_shortName.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: CompareShortName
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual int CompareShortName
    (const tChar* toChars,
     tLength length=vUndefinedLength) const 
    {
        int unequal = m_shortName.Compare(toChars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tLength SetName
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = m_name.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tChar* GetName
    (tLength& length) const 
    {
        const tChar* chars = m_name.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: Name
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tChar* Name() const 
    {
        tLength length;
        const tChar* chars;
        if (!(chars = m_name.HasChars(length)))
            chars = &m_nullChar;
        return chars;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual int CompareName
    (const tChar* toChars,
     tLength length=vUndefinedLength) const 
    {
        int unequal = m_name.Compare(toChars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetDescription
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tLength SetDescription
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = m_description.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tChar* GetDescription
    (tLength& length) const 
    {
        const tChar* chars = m_description.HasChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: SetParameters
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual tLength SetParameters
    (const tChar* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = m_parameters.Assign(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetParameters
     *
     *   Author: $author$
     *     Date: 3/4/2009
     **********************************************************************
     */
    virtual const tChar* GetParameters
    (tLength& length) const 
    {
        const tChar* chars = m_parameters.HasChars(length);
        return chars;
    }
};
#undef CDB_CLASS

/*
 * main
 */
/**
 **********************************************************************
 * Typedef: cMainArgListExtends
 *
 *  Author: $author$
 *    Date: 2/26/2009
 **********************************************************************
 */
typedef cMainArgListT
<cMainArgList, cMainArgListListExtends,
 cMainArgItem, cMainArg, char, int>
cMainArgListExtends;
/**
 **********************************************************************
 *  Class: cMainArgList
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cMainArgList
: public cMainArgListExtends
{
public:
    typedef cMainArgListExtends cExtends;
    typedef cMainArgList cDerives;
};
/**
 **********************************************************************
 * Typedef: cMainArgExtends
 *
 *  Author: $author$
 *    Date: 3/4/2009
 **********************************************************************
 */
typedef cMainArgT
<cMainArg, cMainArgImplement, 
 cMainArgList, cMainArgItem, cString, char, int>
cMainArgExtends;
/**
 **********************************************************************
 *  Class: cMainArg
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cMainArg
: public cMainArgExtends
{
public:
    typedef cMainArgExtends cExtends;
    typedef cMainArg cDerives;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
    static cMainArgList m_list;
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */

    /**
     **********************************************************************
     * Constructor: cMainArg
     *
     *      Author: $author$
     *        Date: 3/4/2009
     **********************************************************************
     */
    cMainArg
    (const tChar* shortName,
     const tChar* name,
     const tChar* description=0,
     const tChar* parameters=0) 
    : cExtends(shortName,name,description,parameters)
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.AddItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     * Destructor: ~cMainArg
     *
     *     Author: $author$
     *       Date: 3/4/2009
     **********************************************************************
     */
    virtual ~cMainArg()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.DeleteItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
};

/*
 * tmain
 */
class c_INSTANCE_CLASS cTMainArgList;
/**
 **********************************************************************
 * Typedef: cTMainArgListListExtends
 *
 *  Author: $author$
 *    Date: 8/23/2009
 **********************************************************************
 */
typedef cStaticExportListT
<cTMainArgList, cTMainArgItem>
cTMainArgListListExtends;
/**
 **********************************************************************
 * Typedef: cTMainArgListExtends
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgListT
<cTMainArgList, cTMainArgListListExtends, 
 cTMainArgItem, cTMainArg, TCHAR, int>
cTMainArgListExtends;
/**
 **********************************************************************
 *  Class: cTMainArgList
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTMainArgList
: public cTMainArgListExtends
{
public:
    typedef cTMainArgListExtends cExtends;
    typedef cTMainArgList cDerives;
};
/**
 **********************************************************************
 * Typedef: cTMainArgExtends
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgT
<cTMainArg, cTMainArgImplement,
 cTMainArgList, cTMainArgItem, cTString, TCHAR, int>
cTMainArgExtends;
/**
 **********************************************************************
 *  Class: cTMainArg
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTMainArg
: public cTMainArgExtends
{
public:
    typedef cTMainArgExtends cExtends;
    typedef cTMainArg cDerives;
    
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
    static cTMainArgList m_list;
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */

    /**
     **********************************************************************
     * Constructor: cTMainArg
     *
     *      Author: $author$
     *        Date: 3/5/2009
     **********************************************************************
     */
    cTMainArg
    (const tChar* shortName,
     const tChar* name,
     const tChar* description=0,
     const tChar* parameters=0) 
    : cExtends(shortName, name, description, parameters)
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.AddItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     * Destructor: ~cTMainArg
     *
     *     Author: $author$
     *       Date: 3/4/2009
     **********************************************************************
     */
    virtual ~cTMainArg()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.DeleteItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMAINARG_MEMBERS_ONLY) */
#endif /* !defined(CMAINARG_MEMBERS_ONLY) */

#endif /* !defined(_CMAINARG_HXX) || defined(CMAINARG_MEMBERS_ONLY) */
