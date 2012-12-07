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
 *   File: ctchartostring.hxx
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
#if !defined(_CTCHARTOSTRING_HXX) || defined(CTCHARTOSTRING_MEMBERS_ONLY)
#if !defined(_CTCHARTOSTRING_HXX) && !defined(CTCHARTOSTRING_MEMBERS_ONLY)
#define _CTCHARTOSTRING_HXX
#endif /* !defined(_CTCHARTOSTRING_HXX) && !defined(CTCHARTOSTRING_MEMBERS_ONLY) */

#if !defined(CTCHARTOSTRING_MEMBERS_ONLY)
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cTCHARToString
 *
 * Author: $author$
 *   Date: 12/2/2009
 **********************************************************************
 */
class cTCHARToString
: public cString
{
public:
    typedef cString cExtends;
    /**
     **********************************************************************
     *  Constructor: cTCHARToString
     *
     *       Author: $author$
     *         Date: 12/2/2009
     **********************************************************************
     */
    cTCHARToString
    (const tChar* chars=0,
     tLength length=vUndefinedLength,
     bool onlyChars=false)
    : cExtends(chars,length)
    {
    }
#else /* !defined(CTCHARTOSTRING_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOSTRING_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: AssignT
     *
     *    Author: $author$
     *      Date: 12/2/2009
     **********************************************************************
     */
    virtual tLength AssignT
    (const TCHAR* chars, tLength length=vUndefinedLength)
#if defined(CTCHARTOSTRING_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CTCHARTOSTRING_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTCHARTOSTRING_MEMBER_FUNCS_IMPLEMENT)
        tLength count2;
        TCHAR tc;
        tChar c;
        
        if (0 > (count2 = Clear()))
            return count2;
            
        if (chars)
        if (0 > length)
        {
            for (tc = *(chars++); (tc != 0); tc=*(chars++), count++)
            {
                c = (tChar)(tc);
                if (0 > (count2 = Append(&c, 1)))
                    return count2;
            }
        }
        else
        if (0 < length)
        {
            for (tc = *(chars++); 0 < length; --length, tc=*(chars++), count++)
            {
                c = (tChar)(tc);
                if (0 > (count2 = Append(&c, 1)))
                    return count2;
            }
        }
#else /* !defined(CTCHARTOSTRING_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTCHARTOSTRING_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTCHARTOSTRING_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTCHARTOSTRING_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTCHARTOSTRING_MEMBERS_ONLY) */
#endif /* !defined(CTCHARTOSTRING_MEMBERS_ONLY) */

#endif /* !defined(_CTCHARTOSTRING_HXX) || defined(CTCHARTOSTRING_MEMBERS_ONLY) */
