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
 *   File: cwinstring.hxx
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
#if !defined(_CWINSTRING_HXX) || defined(CWINSTRING_MEMBERS_ONLY)
#if !defined(_CWINSTRING_HXX) && !defined(CWINSTRING_MEMBERS_ONLY)
#define _CWINSTRING_HXX
#endif /* !defined(_CWINSTRING_HXX) && !defined(CWINSTRING_MEMBERS_ONLY) */

#if !defined(CWINSTRING_MEMBERS_ONLY)
#include "cwinstringinterface.hxx"
#include "cstringbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinStringExtend
 *
 *  Author: $author$
 *    Date: 8/1/2010
 **********************************************************************
 */
typedef cTCHARStringBase
cWinStringExtend;
/**
 **********************************************************************
 *  Class: cWinString
 *
 * Author: $author$
 *   Date: 8/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinString
: virtual public cWinStringImplement,
  public cWinStringExtend
{
public:
    typedef cWinStringImplement cImplements;
    typedef cWinStringExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinString
     *
     *       Author: $author$
     *         Date: 8/1/2010
     **********************************************************************
     */
    cWinString
    (const tChar* chars = 0,
     tLength length = vUndefinedLength)
    : cExtends(chars, length)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinString
     *
     *      Author: $author$
     *        Date: 8/1/2010
     **********************************************************************
     */
    virtual ~cWinString()
    {
    }
#else /* !defined(CWINSTRING_MEMBERS_ONLY) */
#endif /* !defined(CWINSTRING_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Assign
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength Assign
    (const CHAR* chars, 
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = AssignCHARS(chars, length);
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Assign
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength Assign
    (const WCHAR* chars, 
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = AssignWCHARS(chars, length);
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Append
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength Append
    (const CHAR* chars, 
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = AppendCHARS(chars, length);
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Append
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength Append
    (const WCHAR* chars, 
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = AppendWCHARS(chars, length);
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AssignCHARS
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength AssignCHARS
    (const CHAR* chars,
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;
        if (0 <= (count = clear()))
            count = AppendCHARS(chars, length);
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AssignWCHARS
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength AssignWCHARS
    (const WCHAR* chars,
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;
        if (0 <= (count = clear()))
            count = AppendWCHARS(chars, length);
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: AppendCHARS
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength AppendCHARS
    (const CHAR* chars,
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;
        tLength appended;
        tChar c;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                c = (tChar)(*chars++);
                if (0 > (appended = append(&c, 1)))
                    return appended;
            }
        }
        else
        for (; ((c = (tChar)(*chars++)) != vEndChar); count += appended)
        {
            if (0 > (appended = append(&c, 1)))
                return appended;
        }
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AppendWCHARS
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual tLength AppendWCHARS
    (const WCHAR* chars,
     tLength length=vUndefinedLength)
#if defined(CWINSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count = 0;
        tLength appended;
        tChar c;

        if (0 < length)
        {
            for (; 0 < length; --length, count += appended)
            {
                c = (tChar)(*chars++);
                if (0 > (appended = append(&c, 1)))
                    return appended;
            }
        }
        else
        for (; ((c = (tChar)(*chars++)) != vEndChar); count += appended)
        {
            if (0 > (appended = append(&c, 1)))
                return appended;
        }
#else /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINSTRING_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSTRING_MEMBERS_ONLY) */
#endif /* !defined(CWINSTRING_MEMBERS_ONLY) */

#endif /* !defined(_CWINSTRING_HXX) || defined(CWINSTRING_MEMBERS_ONLY) */
