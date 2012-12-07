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
 *   File: cwincmdlineparser.hxx
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
#if !defined(_CWINCMDLINEPARSER_HXX) || defined(CWINCMDLINEPARSER_MEMBERS_ONLY)
#if !defined(_CWINCMDLINEPARSER_HXX) && !defined(CWINCMDLINEPARSER_MEMBERS_ONLY)
#define _CWINCMDLINEPARSER_HXX
#endif /* !defined(_CWINCMDLINEPARSER_HXX) && !defined(CWINCMDLINEPARSER_MEMBERS_ONLY) */

#if !defined(CWINCMDLINEPARSER_MEMBERS_ONLY)
#include "cwincmdlineparserinterface.hxx"
#include "cwinbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCmdLineParserExtend
 *
 *  Author: $author$
 *    Date: 10/6/2010
 **********************************************************************
 */
typedef cWinBase
cWinCmdLineParserExtend;
/**
 **********************************************************************
 *  Class: cWinCmdLineParser
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCmdLineParser
: public cWinCmdLineParserExtend
{
public:
    typedef cWinCmdLineParserExtend cExtends;
    typedef cWinCmdLineParser cDerives;
    typedef eError (cDerives::*mOnChar)(TCHAR c);
    typedef eError (cDerives::*mOnEnd)();
    
    cWinCmdLineParserInterface& m_parser;
    cTCHARString& m_cmdLine;
    cTCHARString m_cmdArg;
    mOnChar m_onChar;
    mOnEnd m_onEnd;
    
    /**
     **********************************************************************
     *  Constructor: cWinCmdLineParser
     *
     *       Author: $author$
     *         Date: 10/6/2010
     **********************************************************************
     */
    cWinCmdLineParser
    (cWinCmdLineParserInterface& parser,
     cTCHARString& cmdLine)
    : m_parser(parser),
      m_cmdLine(cmdLine),
      m_onChar(0),
      m_onEnd(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCmdLineParser
     *
     *      Author: $author$
     *        Date: 10/6/2010
     **********************************************************************
     */
    virtual ~cWinCmdLineParser()
    {
    }
#else /* !defined(CWINCMDLINEPARSER_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEPARSER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Parse
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
    virtual TLENGTH Parse()
#if defined(CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT)
        TLENGTH length;
        const TCHAR* chars;
        
        if ((chars = m_cmdLine.HasChars(length)))
        {
            m_onEnd = &cDerives::OnCmdArg;
            m_onChar = 0;
            
            do
            {
                OnChar(*chars);
                chars++;
                --length;
            }
            while (0 < length);
            OnEnd();
        }
#else /* !defined(CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT)
        error = m_parser.OnCmdArg(chars, length);
#else /* !defined(CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINCMDLINEPARSER_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: OnCmdArg
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
    eError OnCmdArg()
    {
        eError error = e_ERROR_NONE;
        const TCHAR* chars;
        TLENGTH length;
        
        if ((chars = m_cmdArg.HasChars(length)))
        {
            error = OnCmdArg(chars, length);
            m_cmdArg.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnEnd
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
     eError OnEnd()
     {
        eError error = e_ERROR_NONE;
        if (m_onEnd)
            return (this->*m_onEnd)();
        return error;
    }
    /**
     **********************************************************************
     *  Function: OnChar
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
     eError OnChar(TCHAR c)
     {
        eError error = e_ERROR_NONE;
        
        if (m_onChar)
            return (this->*m_onChar)(c);
        
        switch(c)
        {
        case _T(' '):
        case _T('\t'):
            error = OnCmdArg();
            m_onEnd = 0;
            m_onChar = &cDerives::OnChar_Sp;
            break;
            
        case _T('"'):
            error = OnCmdArg();
            m_onEnd = &cDerives::OnCmdArg;
            m_onChar = &cDerives::OnChar_Qt;
            break;            
        
        default:
            m_cmdArg.Append(&c, 1);
        }
        return error;
     }
    /**
     **********************************************************************
     *  Function: OnChar
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
     eError OnChar_Sp(TCHAR c)
     {
        eError error = e_ERROR_NONE;
        switch(c)
        {
        case _T(' '):
        case _T('\t'):
            break;
            
        case _T('"'):
            m_onEnd = &cDerives::OnCmdArg;
            m_onChar = &cDerives::OnChar_Qt;
            break;
            
        default:
            m_cmdArg.Append(&c, 1);
            m_onEnd = &cDerives::OnCmdArg;
            m_onChar = 0;
            break;
        }
        return error;
     }
    /**
     **********************************************************************
     *  Function: OnChar
     *
     *    Author: $author$
     *      Date: 10/6/2010
     **********************************************************************
     */
     eError OnChar_Qt(TCHAR c)
     {
        eError error = e_ERROR_NONE;
        switch(c)
        {
        case _T('"'):
            error = OnCmdArg();
            m_onEnd = 0;
            m_onChar = 0;
            break;

        default:
            m_cmdArg.Append(&c, 1);
        }
        return error;
     }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCMDLINEPARSER_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEPARSER_MEMBERS_ONLY) */

#endif /* !defined(_CWINCMDLINEPARSER_HXX) || defined(CWINCMDLINEPARSER_MEMBERS_ONLY) */
