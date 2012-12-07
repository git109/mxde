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
#if defined(CMAINARG_MEMBERS_ONLY) 
#if defined(_CMAINARG_HXX) 
#define _CMAINARG_HXX_OLD 
#undef _CMAINARG_HXX
#endif /* defined(_CMAINARG_HXX) */
#endif /* defined(CMAINARG_MEMBERS_ONLY) */

#ifndef _CMAINARG_HXX
#define _CMAINARG_HXX

#if !defined(CMAINARG_MEMBERS_ONLY)
#include "clist.hxx"
#include "cstring.hxx"
#include "cmainarginterface.hxx"

class cMainArgItem;
class cMainArg;

#undef CDB_CLASS
#define CDB_CLASS "cMainArgItemT"
/**
 **********************************************************************
 *  Class: cMainArgItemT
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
template
<class TDerives=cMainArgItem,
 class TMainArg=cMainArg,
 class TListItem=cListItemT<TDerives>,
 class TExtends=TListItem>
 
class cMainArgItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    TMainArg& m_mainArg;

    /**
     **********************************************************************
     * Constructor: cMainArgItemT
     *
     *      Author: $author$
     *        Date: 2/25/2009
     **********************************************************************
     */
    cMainArgItemT(TMainArg& mainArg)
    : m_mainArg(mainArg) 
    {
    }

    /**
     **********************************************************************
     * Function: GetMainArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual TMainArg& GetMainArg() const 
    {
        return m_mainArg;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cMainArgItemExtends
 *
 *  Author: $author$
 *    Date: 2/25/2009
 **********************************************************************
 */
typedef cMainArgItemT<cMainArgItem>
cMainArgItemExtends;
/**
 **********************************************************************
 *  Class: cMainArgItem
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
class cMainArgItem
: public cMainArgItemExtends
{
public:
    typedef cMainArgItemExtends cExtends;
    typedef cMainArgItem cDerives;
    /**
     **********************************************************************
     * Constructor: cMainArgItem
     *
     *      Author: $author$
     *        Date: 2/25/2009
     **********************************************************************
     */
    cMainArgItem
    (cMainArg& mainArg) 
    : cExtends(mainArg)
    {
    }
};

class cMainArgList;

#undef CDB_CLASS
#define CDB_CLASS "cMainArgListT"
/**
 **********************************************************************
 *  Class: cMainArgListT
 *
 * Author: $author$
 *   Date: 2/25/2009
 **********************************************************************
 */
template
<class TDerives=cMainArgList,
 class TMainArgItem=cMainArgItem,
 class TMainArg=cMainArg,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cBase,
 class TStaticList=cStaticListT<TDerives, TMainArgItem, TBase>,
 class TExtends=TStaticList>
 
class cMainArgListT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: FindFirstArgByShortName
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* FindFirstArgByShortName
    (const tChar* chars,
     tLength length=-1) 
    {
        const TMainArg* arg = 0;
        TMainArgItem* argItem;
        int diff;

        for (argItem=CTHIS GetFirstItem(); 
             argItem; argItem=argItem->GetNextItem())
        {
            const TMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareShortName(chars, length)))
                return arg = &mainArg;
        }
        return arg;
    }
    /**
     **********************************************************************
     * Function: FindFirstArgByName
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* FindFirstArgByName
    (const tChar* chars,
     tLength length=-1) 
    {
        TMainArg* arg = 0;
        TMainArgItem *argItem;
        int diff;

        for (argItem=CTHIS GetFirstItem(); 
             argItem; argItem=argItem->GetNextItem())
        {
            TMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareName(chars, length)))
                return arg = &mainArg;
        }
        return arg;
    }

    /**
     **********************************************************************
     * Function: GetFirstArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetFirstArg
    (const TMainArgItem*& argItem) 
    {
        const TMainArg* mainArg = 0;
        return mainArg;
    }
    /**
     **********************************************************************
     * Function: GetLastArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetLastArg
    (const TMainArgItem*& argItem) 
    {
        const TMainArg* mainArg = 0;
        return mainArg;
    }
    /**
     **********************************************************************
     * Function: GetNextArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetNextArg
    (const TMainArgItem*& argItem) 
    {
        const TMainArg* mainArg = 0;
        return mainArg;
    }
    /**
     **********************************************************************
     * Function: GetPrevArg
     *
     *   Author: $author$
     *     Date: 2/25/2009
     **********************************************************************
     */
    virtual const TMainArg* GetPrevArg
    (const TMainArgItem*& argItem) 
    {
        const TMainArg* mainArg = 0;
        return mainArg;
    }
};
#undef CDB_CLASS

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
 class TBase=cBase,
 class TImplements=TMainArgImplement,
 class TExtends=TBase>
 
class cMainArgT
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

    typedef TString tString;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    static TMainArgList m_list;
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    TMainArgItem m_item;

    tChar m_minus;
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
      m_minus('-')
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

/**
 **********************************************************************
 * Typedef: cMainArgListExtends
 *
 *  Author: $author$
 *    Date: 2/26/2009
 **********************************************************************
 */
typedef cMainArgListT
<cMainArgList, cMainArgItem, cMainArg, char, int>
cMainArgListExtends;
/**
 **********************************************************************
 *  Class: cMainArgList
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
class cMainArgList
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
class cMainArg
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
class cTMainArg;
class cTMainArgItem;
class cTMainArgList;
/**
 **********************************************************************
 * Typedef: cTMainArgItemExtends
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgItemT
<cTMainArgItem,cTMainArg>
cTMainArgItemExtends;
/**
 **********************************************************************
 *  Class: cTMainArgItem
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class cTMainArgItem
: public cTMainArgItemExtends
{
public:
    typedef cTMainArgItemExtends cExtends;
    typedef cTMainArgItem cDerives;
    /**
     **********************************************************************
     * Constructor: cTMainArgItem
     *
     *      Author: $author$
     *        Date: 3/5/2009
     **********************************************************************
     */
    cTMainArgItem
    (cTMainArg& mainArg) 
    : cExtends(mainArg)
    {
    }
};
/**
 **********************************************************************
 * Typedef: cTMainArgListExtends
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgListT
<cTMainArgList, cTMainArgItem, cTMainArg, TCHAR, int>
cTMainArgListExtends;
/**
 **********************************************************************
 *  Class: cTMainArgList
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class cTMainArgList
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
class cTMainArg
: public cTMainArgExtends
{
public:
    typedef cTMainArgExtends cExtends;
    typedef cTMainArg cDerives;
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
    }
};
#else /* !defined(CMAINARG_MEMBERS_ONLY) */
#endif /* !defined(CMAINARG_MEMBERS_ONLY) */
#endif /* _CMAINARG_HXX */

#if defined(CMAINARG_MEMBERS_ONLY) 
#if defined(_CMAINARG_HXX_OLD) 
#define _CMAINARG_HXX
#undef _CMAINARG_HXX_OLD
#endif /* defined(_CMAINARG_HXX_OLD) */
#endif /* defined(CMAINARG_MEMBERS_ONLY) */
