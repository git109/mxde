/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$  
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
 *   File: cxtarglist.hxx
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
#if !defined(_CXTARGLIST_HXX) || defined(CXTARGLIST_MEMBERS_ONLY)
#if !defined(_CXTARGLIST_HXX) && !defined(CXTARGLIST_MEMBERS_ONLY)
#define _CXTARGLIST_HXX
#endif /* !defined(_CXTARGLIST_HXX) && !defined(CXTARGLIST_MEMBERS_ONLY) */

#if !defined(CXTARGLIST_MEMBERS_ONLY)
#include "cxtarglistinterface.hxx"
#include "cxtargitem.hxx"
#include "cxtarg.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtArgListExtend
 *
 *  Author: $author$           
 *    Date: 4/25/2010
 **********************************************************************
 */
typedef cXBase
cXtArgListExtend;
/**
 **********************************************************************
 *  Class: cXtArgList
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtArgList
: virtual public cXtArgListImplement,
  public cXtArgListExtend
{
public:
    typedef cXtArgListImplement cImplements;
    typedef cXtArgListExtend cExtends;

    cXtArgArray m_argArray;
    cXtArgItemList m_argList;

    /**
     **********************************************************************
     *  Constructor: cXtArgList
     *
     *       Author: $author$           
     *         Date: 4/25/2010
     **********************************************************************
     */
    cXtArgList
    (const XtChar* argName, XtArgVal argValue, ...)
    {
        va_list va;
        va_start(va, argValue);
        AppendV(argName, argValue, va);
        va_end(va);
    }
    /**
     **********************************************************************
     *  Constructor: cXtArgList
     *
     *       Author: $author$           
     *         Date: 4/25/2010
     **********************************************************************
     */
    cXtArgList()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtArgList
     *
     *      Author: $author$           
     *        Date: 4/25/2010
     **********************************************************************
     */
    virtual ~cXtArgList()
    {
        eError error;
        if ((error = m_argList.Clear()))
        {
            DBE(("() throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXTARGLIST_MEMBERS_ONLY) */
#endif /* !defined(CXTARGLIST_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Get
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH Get
    (const XtChar** argName, XtArgVal* argValue) const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = GetL(argName, argValue, 0);
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetL
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH GetL
    (const XtChar** argName, XtArgVal* argValue, ...) const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        va_list va;
        va_start(va, argValue);
        count = GetV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH GetV
    (const XtChar** argName, XtArgVal* argValue, va_list va) const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        TLENGTH argArrayLength;
        tXtArgArrayElement* argArrayElement;

        if ((argName) && (argValue))
        if (0 < (argArrayLength = m_argArray.Length()))
        if ((argArrayElement = m_argArray.Elements()))
        {
            do
            {
                *argName = argArrayElement[count].name;
                *argValue = argArrayElement[count].value;

                if (argArrayLength > (++count))
                if ((argName = va_arg(va, const XtChar**)))
                if ((argValue = va_arg(va, XtArgVal*)))
                    continue;

                break;
            }
            while ((argName) && (argValue) && (count < argArrayLength));
        }
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Set
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList Set
    (const XtChar* argName, XtArgVal argValue)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = SetL(argName, argValue, 0);
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetL
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList SetL
    (const XtChar* argName, XtArgVal argValue, ...)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, argValue);
        argList = SetV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList SetV
    (const XtChar* argName, XtArgVal argValue, va_list va)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = AssignV(argName, argValue, va);
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetGetV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList SetGetV
    (const XtChar* argName, XtArgVal* argValue, va_list va)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        int args;
        cXtArgItem* argItem;
        tXtArgArrayElement* argArrayElement;
        TLENGTH argArraySize;
        TLENGTH argArrayLength;

        DBT(("()in...\n"));

        if (0 > (argArrayLength = Clear()))
            return argList;

        if ((argName) && (argValue))
        if (0 <= (args = m_argArray.Length()))
        if (args < (argArraySize = m_argArray.Size()))
        if ((argArrayElement = m_argArray.Elements()))
        {
            do
            {
                DBT(("() new cXtArgItem(\"%s\", %p)\n", argName, argValue));

                if ((argItem = new cXtArgItem
                    (argArrayElement[args], argName, (XtArgVal)(argValue))))
                {
                    if (0 > (argArrayLength = m_argArray.SetLength(++args)))
                    {
                        delete argItem;
                        break;
                    }
                    else
                    m_argList.AddItem(*argItem);

                    if ((argName = va_arg(va, const XtChar*)))
                    if ((argValue = va_arg(va, XtArgVal*)))
                        continue;
                }
                break;
            }
            while ((argName) && (argValue) && (args < argArraySize));

            argList = m_argArray.Elements();
        }
        DBT(("()...out\n"));
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetSetV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH GetSetV
    (const XtChar* argName, XtArgVal* argValue, va_list va) const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = 0;
        TLENGTH argArrayLength;
        tXtArgArrayElement* argArrayElement;

        DBT(("()in...\n"));

        if ((argName) && (argValue))
        if (0 < (argArrayLength = m_argArray.Length()))
        if ((argArrayElement = m_argArray.Elements()))
        {
            do
            {
                argValue = (XtArgVal*)(argArrayElement[count].value);

                DBT(("() argName=\"%s\" argValue=%p\n", argName, argValue));

                if (argArrayLength > (++count))
                if ((argName = va_arg(va, const XtChar*)))
                if ((argValue = va_arg(va, XtArgVal*)))
                    continue;

                break;
            }
            while ((argName) && (argValue) && (count < argArrayLength));
        }
        DBT(("()...out\n"));
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Assign
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList Assign
    (const XtChar* argName, XtArgVal argValue)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = AssignL(argName, argValue, 0);
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AssignL
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList AssignL
    (const XtChar* argName, XtArgVal argValue, ...)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count;
        va_list va;

        if (0 > (count = Clear()))
            return argList;

        va_start(va, argValue);
        argList = AppendV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AssignV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList AssignV
    (const XtChar* argName, XtArgVal argValue, va_list va)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count;

        if (0 > (count = Clear()))
            return argList;

        argList = AppendV(argName, argValue, va);
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Append
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList Append
    (const XtChar* argName, XtArgVal argValue)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = AppendL(argName, argValue, 0);
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppendL
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList AppendL
    (const XtChar* argName, XtArgVal argValue, ...)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        va_list va;
        va_start(va, argValue);
        argList = AppendV(argName, argValue, va);
        va_end(va);
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppendV
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual ArgList AppendV
    (const XtChar* argName, XtArgVal argValue, va_list va)
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        int args;
        cXtArgItem* argItem;
        tXtArgArrayElement* argArrayElement;
        TLENGTH argArraySize;
        TLENGTH argArrayLength;

        if (0 <= (args = m_argArray.Length()))
        if (args < (argArraySize = m_argArray.Size()))
        if ((argArrayElement = m_argArray.Elements()))
        {
            do
            {
                if ((argItem = new cXtArgItem
                    (argArrayElement[args], argName, argValue)))
                {
                    if (0 > (argArrayLength = m_argArray.SetLength(++args)))
                    {
                        delete argItem;
                        break;
                    }
                    else
                    m_argList.AddItem(*argItem);

                    if ((argName = va_arg(va, const XtChar*)))
                    {
                        argValue = va_arg(va, XtArgVal);
                        continue;
                    }
                }
                break;
            }
            while ((argName) && (args < argArraySize));

            argList = m_argArray.Elements();
        }
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Clear
     *
     *    Author: $author$           
     *      Date: 4/30/2010
     **********************************************************************
     */
    virtual TLENGTH Clear()
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH count = m_argArray.Length();
        TLENGTH count2;
        eError error;

        if (0 > (count2 = m_argArray.SetLength(0)))
            return count2;

        if ((error = m_argList.Clear()))
            count = -error;

#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: List
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList List() const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH length = 0;
        ArgList argList = List(length);
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: List
     *
     *    Author: $author$           
     *      Date: 5/20/2010
     **********************************************************************
     */
    virtual ArgList List(TLENGTH& length) const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        ArgList argList = 0;
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        if (0 < (length = m_argArray.Length()))
        if (!(argList = m_argArray.Elements()))
            length = -e_ERROR_FAILED;
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Length
     *
     *    Author: $author$           
     *      Date: 4/27/2010
     **********************************************************************
     */
    virtual TLENGTH Length() const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH value = m_argArray.Length();
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH value = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return value;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: operator ArgList
     *
     *    Author: $author$           
     *      Date: 4/26/2010
     **********************************************************************
     */
    virtual operator ArgList() const
#if defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH length = 0;
        ArgList argList = List(length);
#if !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTARGLIST_MEMBER_FUNCS_IMPLEMENT) */
        return argList;
    }
#endif /* defined(CXTARGLIST_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTARGLIST_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTARGLIST_MEMBERS_ONLY) */
#endif /* !defined(CXTARGLIST_MEMBERS_ONLY) */

#endif /* !defined(_CXTARGLIST_HXX) || defined(CXTARGLIST_MEMBERS_ONLY) */
