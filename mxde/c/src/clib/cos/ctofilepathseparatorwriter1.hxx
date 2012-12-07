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
 *   File: ctofilepathseparatorwriter.hxx
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
#if !defined(_CTOFILEPATHSEPARATORWRITER_HXX) || defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY)
#if !defined(_CTOFILEPATHSEPARATORWRITER_HXX) && !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY)
#define _CTOFILEPATHSEPARATORWRITER_HXX
#endif /* !defined(_CTOFILEPATHSEPARATORWRITER_HXX) && !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY) */

#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY)
#include "cfilepathseparatoreventsinterface.hxx"
#include "cstring.hxx"
#include "cwriter.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class cToFilePathSeparatorWriter;

#undef CDB_CLASS
#define CDB_CLASS "cToFilePathSeparatorWriterT"
/**
 **********************************************************************
 *  Class: cToFilePathSeparatorWriterT
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
template
<class TDerives=cToFilePathSeparatorWriter,
 class TFilePathSeparatorEventsInterface=cFilePathSeparatorEventsInterface,
 class TString=cString,
 class TWriter=cWriter,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TExtends=TWriter>

class cToFilePathSeparatorWriterT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cToFilePathSeparatorWriterT cDerives;
    
/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

    typedef TString tString;
    typedef TFilePathSeparatorEventsInterface tFilePathSeparatorEventsInterface;
    
    typedef tLength (cDerives::*MFinal)();
    typedef tLength (cDerives::*MPut)(tChar c);

    tFilePathSeparatorEventsInterface& m_events;
    
    MFinal m_final;
    MPut m_put;
    MPut m_oldPut;

    tChar m_dot;
    tString m_token;
    tString m_token2;

    /**
     **********************************************************************
     *  Constructor: cToFilePathSeparatorWriterT
     *
     *       Author: $author$
     *         Date: 10/14/2009
     **********************************************************************
     */
    cToFilePathSeparatorWriterT
    (tFilePathSeparatorEventsInterface& events)
    : m_events(events),
      m_final(0),
      m_put(0),
      m_oldPut(0),
      m_dot('.')
    {
    }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 10/14/2009
     **********************************************************************
     */
    virtual tLength Initialize() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        m_final = &cDerives::InitFinal;
        m_put = &cDerives::InitPut;
        m_token.Clear();
        m_token2.Clear();
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 10/14/2009
     **********************************************************************
     */
    virtual tLength Finalize() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        if (m_final)
            count = (this->*m_final)();
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */

    /*
     * Put
     */

    /**
     **********************************************************************
     * Function: InitPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A*?
     **********************************************************************
     */
    virtual tLength InitPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'/'
                m_events.OnPathFileDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // '/'
                m_put = &cDerives::RootPut;
                m_final = &cDerives::RootFinal;
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'.'
                m_oldPut = m_put;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        case ':':
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathFileVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::VolumePut;
            break;
        default:
            // A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NamePut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * .+?
     **********************************************************************
     */
    virtual tLength NamePut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // .+A+'/'
                m_events.OnPathFileDirectory(chars, length);
                m_token.Clear();
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // .+A+'.'
                m_oldPut = m_put;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // .+'.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        default:
            // .+A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootNamePut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'.+?
     **********************************************************************
     */
    virtual tLength RootNamePut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'/'
                m_events.OnPathFileRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/'.+'.' 
                m_put = &cDerives::RootCurrentPut;
                m_final = &cDerives::RootCurrentFinal;
            }
            break;
        default:
            // '/'.+A
            m_token.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ExtensionPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A+'.'?
     **********************************************************************
     */
    virtual tLength ExtensionPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // A+'.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // A+'.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.HasChars(length)))
            {
                m_events.OnPathFileDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // A+'.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // A+'.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            break;
        default:
            // A+'.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::ExtensionFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootExtensionPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'A+'.'?
     **********************************************************************
     */
    virtual tLength RootExtensionPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '/'A+'.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/'A+'.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.HasChars(length)))
            {
                m_events.OnPathFileRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // '/'A+'.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/'A+'.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            break;
        default:
            // '/'A+'.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootExtensionFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CurrentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '.'?
     **********************************************************************
     */
    virtual tLength CurrentPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathFileDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '.''/'
                m_events.OnPathFileCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.''.' 
                m_put = &cDerives::ParentPut;
                m_final = &cDerives::ParentFinal;
            }
            break;
        default:
            // '.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::CurrentFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootCurrentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''.'?
     **********************************************************************
     */
    virtual tLength RootCurrentPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '/''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathFileRootDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '/''.''/'
                m_events.OnPathFileRootCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '/''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.''.' 
                m_put = &cDerives::RootParentPut;
                m_final = &cDerives::RootParentFinal;
            }
            break;
        default:
            // '/''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ParentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '.''.'?
     **********************************************************************
     */
    virtual tLength ParentPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '.''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathFileDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '.''.''/'
                m_events.OnPathFileParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerives::NamePut;
                m_final = &cDerives::NameFinal;
            }
            break;
        default:
            // '.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootParentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''.''.'?
     **********************************************************************
     */
    virtual tLength RootParentPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '/''.''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathFileRootDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '/''.''.''/'
                m_events.OnPathFileRootParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '/''.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerives::RootNamePut;
                m_final = &cDerives::RootNameFinal;
            }
            break;
        default:
            // '/''.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'?
     **********************************************************************
     */
    virtual tLength RootPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '/'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'/'
                m_events.OnPathFileRootDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // '/''/'
                m_put = &cDerives::HostPut;
                m_final = &cDerives::HostFinal;
            }
            break;
        case '.':
            // '/'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.' 
                m_put = &cDerives::RootCurrentPut;
                m_final = &cDerives::RootCurrentFinal;
            }
            break;
        case ':':
            // '/'A*':'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathFileVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::VolumePut;
            break;
        default:
            // '/'A
            m_token.Append(&c, 1);
            m_final = &cDerives::RootFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: VolumePut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A+':'?
     **********************************************************************
     */
    virtual tLength VolumePut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // A+':'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'/'
                m_events.OnPathFileDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // A+':''/'
                m_put = &cDerives::RootPut;
                m_final = &cDerives::RootFinal;
            }
            break;
        case '.':
            // A+':'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // A+':''.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        default:
            // A+':'A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: HostPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''/'?
     **********************************************************************
     */
    virtual tLength HostPut
    (tChar c) 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        switch((char)c)
        {
        case '/':
        case '\\':
            // '/''/'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // '/''/'A+'/'
                m_events.OnPathFileHost(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        default:
            // '/''/'A
            m_token.Append(&c, 1);
            m_final = &cDerives::HostFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */

    /*
     * Final
     */

    /**
     **********************************************************************
     * Function: InitFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     **********************************************************************
     */
    virtual tLength InitFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: NameFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A*
     **********************************************************************
     */
    virtual tLength NameFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // A+
            m_events.OnPathFileBase(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootNameFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'A*
     **********************************************************************
     */
    virtual tLength RootNameFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/'A+
            m_events.OnPathFileRootBase(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ExtensionFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A+'.'A*
     **********************************************************************
     */
    virtual tLength ExtensionFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // A+'.'
            m_events.OnPathFileBase(chars, length);
            m_token.Clear();
        }
        if ((chars = m_token2.HasChars(length)))
        {
            // A'.'A+
            m_events.OnPathFileExtension(chars, length);
            m_token2.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootExtensionFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'A+'.'A*
     **********************************************************************
     */
    virtual tLength RootExtensionFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/'A+'.'
            m_events.OnPathFileRootBase(chars, length);
            m_token.Clear();
        }
        if ((chars = m_token2.HasChars(length)))
        {
            // '/'A'.'A+
            m_events.OnPathFileExtension(chars, length);
            m_token2.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CurrentFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '.'
     **********************************************************************
     */
    virtual tLength CurrentFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '.'
            m_events.OnPathFileCurrentDirectory(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootCurrentFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''.'
     **********************************************************************
     */
    virtual tLength RootCurrentFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''.'
            m_events.OnPathFileRootCurrentDirectory(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ParentFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '.''.'
     **********************************************************************
     */
    virtual tLength ParentFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '.''.'
            m_events.OnPathFileParentDirectory(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootParentFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''.''.'
     **********************************************************************
     */
    virtual tLength RootParentFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''.''.'
            m_events.OnPathFileRootParentDirectory(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: RootFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'
     **********************************************************************
     */
    virtual tLength RootFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        chars = m_token.HasChars(length);
        m_events.OnPathFileRootDirectory(chars, length);
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: HostFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''/'A*
     **********************************************************************
     */
    virtual tLength HostFinal() 
#if defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) 
        tLength length;
        const tChar* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''/'A+
            m_events.OnPathFileHost(chars, length);
            m_token.Clear();
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 10/14/2009
     **********************************************************************
     */
    virtual tLength Put
    (const tWhat& what) 
    {
        tLength count = 0;
        if (m_put)
            count = (this->*m_put)(what);
        return count;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 10/14/2009
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* what,
     tLength length=vUndefinedLength) 
    {
        tLength count = 0;
        tLength count2;
        tWhat whatAt;
        if (what)
        if (0 > length)
        {
            while ((whatAt = (*what++)) != vEndWhat)
            {
                if (0 > (count2 = Put(whatAt)))
                    return count2;
                count += count2;
            }
        }
        else
        {
            for (whatAt = (*what++); 0 < length; --length, whatAt = (*what++))
            {
                if (0 > (count2 = Put(whatAt)))
                    return count2;
                count += count2;
            }
        }
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cToFilePathSeparatorWriterExtends
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cToFilePathSeparatorWriterT<>
cToFilePathSeparatorWriterExtends;
/**
 **********************************************************************
 *  Class: cToFilePathSeparatorWriter
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class cToFilePathSeparatorWriter
: public cToFilePathSeparatorWriterExtends
{
public:
    typedef cToFilePathSeparatorWriterExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cToFilePathSeparatorWriter
     *
     *       Author: $author$
     *         Date: 10/14/2009
     **********************************************************************
     */
    cToFilePathSeparatorWriter
    (tFilePathSeparatorEventsInterface& events)
    : cExtends(events)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY) */

#endif /* !defined(_CTOFILEPATHSEPARATORWRITER_HXX) || defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY) */
