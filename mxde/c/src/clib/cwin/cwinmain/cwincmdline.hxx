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
 *   File: cwincmdline.hxx
 *
 * Author: $author$
 *   Date: 1/11/2010
 **********************************************************************
 */
#if !defined(_CWINCMDLINE_HXX) || defined(CWINCMDLINE_MEMBERS_ONLY)
#if !defined(_CWINCMDLINE_HXX) && !defined(CWINCMDLINE_MEMBERS_ONLY)
#define _CWINCMDLINE_HXX
#endif /* !defined(_CWINCMDLINE_HXX) && !defined(CWINCMDLINE_MEMBERS_ONLY) */

#if !defined(CWINCMDLINE_MEMBERS_ONLY)
#include "cwincmdlineparserinterface.hxx"
#include "cwincmdlineparser.hxx"
#include "cwincmdlinelist.hxx"
#include "cstring.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCmdLineExtends
 *
 *  Author: $author$
 *    Date: 1/11/2010
 **********************************************************************
 */
typedef cTCHARString
cWinCmdLineExtends;
/**
 **********************************************************************
 *  Class: cWinCmdLine
 *
 * Author: $author$
 *   Date: 1/11/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinCmdLine
: virtual public cWinCmdLineParserImplement,
  public cWinCmdLineExtends
{
public:
    typedef cWinCmdLineExtends cExtends;
    
    cWinCmdLineParser m_parser;
    cWinCmdLineList m_list;
    
    /**
     **********************************************************************
     *  Constructor: cWinCmdLine
     *
     *       Author: $author$
     *         Date: 1/11/2010
     **********************************************************************
     */
    cWinCmdLine
    (const WCHAR* chars, 
     TLENGTH length=UNDEFINED_LENGTH)
    : m_parser
      ((cWinCmdLineParserInterface&)(*this),
       (cTCHARString&)(*this))
    {
        eError error;
        if (chars)
        if (0 > (length = AssignWChars(chars, length)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     *  Constructor: cWinCmdLine
     *
     *       Author: $author$
     *         Date: 1/11/2010
     **********************************************************************
     */
    cWinCmdLine
    (const CHAR* chars=0, 
     TLENGTH length=UNDEFINED_LENGTH)
    : m_parser
      ((cWinCmdLineParserInterface&)(*this),
       (cTCHARString&)(*this))
    {
        eError error;
        if (chars)
        if (0 > (length = AssignCHARS(chars, length)))
            throw(error = -length);
    }
#else /* !defined(CWINCMDLINE_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: FirstArg
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual const TCHAR* FirstArg
    (TLENGTH& length) const
#if defined(CWINCMDLINE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINCMDLINE_MEMBER_FUNCS_INTERFACE) */
    {
        const TCHAR* chars = 0;
#if !defined(CWINCMDLINE_MEMBER_FUNCS_IMPLEMENT)
        cWinCmdLineItem* cmdArg;
        length = 0;
        if ((cmdArg = m_list.GetFirstItem()))
            chars = cmdArg->HasChars(length);
#else /* !defined(CWINCMDLINE_MEMBER_FUNCS_IMPLEMENT) */
        length = 0;
#endif /* !defined(CWINCMDLINE_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINCMDLINE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NextArg
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual const TCHAR* NextArg
    (TLENGTH& length, const TCHAR* prevArg) const
#if defined(CWINCMDLINE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINCMDLINE_MEMBER_FUNCS_INTERFACE) */
    {
        const TCHAR* chars = 0;
#if !defined(CWINCMDLINE_MEMBER_FUNCS_IMPLEMENT) 
        cWinCmdLineItem* cmdArg;
        const TCHAR* argChars;
        TLENGTH argLength;
        length = 0;
        if ((cmdArg = m_list.GetFirstItem()))
        do
        {
            if ((argChars = cmdArg->HasChars(argLength)))
            if (prevArg == argChars)
            {
                if ((cmdArg = cmdArg->GetNextItem()))
                    chars = cmdArg->HasChars(length);
                break;
            }
        }
        while ((cmdArg = cmdArg->GetNextItem()));
#else /* !defined(CWINCMDLINE_MEMBER_FUNCS_IMPLEMENT) */
        length = 0;
#endif /* !defined(CWINCMDLINE_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINCMDLINE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINCMDLINE_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: OnCmdArg
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
    virtual eError OnCmdArg
    (const TCHAR* chars,
     TLENGTH length=UNDEFINED_LENGTH)
    {
        eError error = e_ERROR_NONE;
        cWinCmdLineItem* cmdArg;
        if ((cmdArg = new cWinCmdLineItem(chars, length)))
            m_list.AddItem(*cmdArg);
        return error;
    }
    /**
     **********************************************************************
     * Function: AssignWChars
     *
     *   Author: $author$
     *     Date: 10/6/2010
     **********************************************************************
     */
    virtual tLength AssignWChars
    (const WCHAR* wChars,
     tLength length=vUndefinedLength) 
    {
        tLength count = 0;
        eError error;
        m_list.ClearItems();
        if (0 < (count = cExtends::AssignWChars(wChars, length)))
        if ((error = m_parser.Parse()))
            count = -error;
        return count;
    }
    /**
     **********************************************************************
     * Function: AssignCHARS
     *
     *   Author: $author$
     *     Date: 10/6/2010
     **********************************************************************
     */
    virtual tLength AssignCHARS
    (const CHAR* chars,
     tLength length=vUndefinedLength) 
    {
        tLength count = 0;
        eError error;
        m_list.ClearItems();
        if (0 < (count = cExtends::AssignCHARS(chars, length)))
        if ((error = m_parser.Parse()))
            count = -error;
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCMDLINE_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINE_MEMBERS_ONLY) */

#endif /* !defined(_CWINCMDLINE_HXX) || defined(CWINCMDLINE_MEMBERS_ONLY) */
