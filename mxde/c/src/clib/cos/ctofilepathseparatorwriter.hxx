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
    typedef cToFilePathSeparatorWriterT cDerive;
    
/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

    typedef TString tString;
    typedef TFilePathSeparatorEventsInterface tFilePathSeparatorEventsInterface;
    
    typedef tLength (cDerive::*MFinal)();
    typedef tLength (cDerive::*MPut)(tChar c);

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
        m_final = &cDerive::InitialFinal;
        m_put = &cDerive::InitialPut;
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

#if !defined(CTOFILEPATHSEPARATORWRITER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: InitialPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A*?
     **********************************************************************
     */
    tLength InitialPut
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
                m_put = &cDerive::NamePut;
            }
            else 
            {
                // '/'
                m_put = &cDerive::RootPut;
                m_final = &cDerive::RootFinal;
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'.'
                m_oldPut = m_put;
                m_put = &cDerive::ExtensionPut;
                m_final = &cDerive::ExtensionFinal;
            }
            else
            {
                // '.' 
                m_put = &cDerive::CurrentPut;
                m_final = &cDerive::CurrentFinal;
            }
            break;
        case ':':
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathFileVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerive::VolumePut;
            break;
        default:
            // A
            m_token.Append(&c, 1);
            m_final = &cDerive::NameFinal;
        }
#else /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CTOFILEPATHSEPARATORWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: InitialFinal
     *
     *   Author: $author$
     *     Date: 10/14/2009
     **********************************************************************
     */
    tLength InitialFinal() 
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
     * Function: NamePut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * .+?
     **********************************************************************
     */
    tLength NamePut
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
                m_put = &cDerive::ExtensionPut;
                m_final = &cDerive::ExtensionFinal;
            }
            else
            {
                // .+'.' 
                m_put = &cDerive::CurrentPut;
                m_final = &cDerive::CurrentFinal;
            }
            break;
        default:
            // .+A
            m_token.Append(&c, 1);
            m_final = &cDerive::NameFinal;
        }
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
    tLength NameFinal() 
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
     * Function: RootNamePut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'.+?
     **********************************************************************
     */
    tLength RootNamePut
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
            m_put = &cDerive::NamePut;
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'.'
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::RootExtensionPut;
                m_final = &cDerive::RootExtensionFinal;
            }
            else
            {
                // '/'.+'.' 
                m_put = &cDerive::RootCurrentPut;
                m_final = &cDerive::RootCurrentFinal;
            }
            break;
        default:
            // '/'.+A
            m_token.Append(&c, 1);
            m_final = &cDerive::RootNameFinal;
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
    tLength RootNameFinal() 
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
     * Function: ExtensionPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A+'.'?
     **********************************************************************
     */
    tLength ExtensionPut
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
            m_final = &cDerive::ExtensionFinal;
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
    tLength ExtensionFinal() 
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
     * Function: RootExtensionPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'A+'.'?
     **********************************************************************
     */
    tLength RootExtensionPut
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
            m_final = &cDerive::RootExtensionFinal;
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
    tLength RootExtensionFinal() 
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
     * Function: CurrentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '.'?
     **********************************************************************
     */
    tLength CurrentPut
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
            m_put = &cDerive::NamePut;
            break;
        case '.':
            // '.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::ExtensionPut;
                m_final = &cDerive::ExtensionFinal;
            }
            else
            {
                // '.''.' 
                m_put = &cDerive::ParentPut;
                m_final = &cDerive::ParentFinal;
            }
            break;
        default:
            // '.'A
            m_token2.Append(&c, 1);
            m_final = &cDerive::CurrentFinal;
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
    tLength CurrentFinal() 
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
     * Function: RootCurrentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''.'?
     **********************************************************************
     */
    tLength RootCurrentPut
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
            m_put = &cDerive::NamePut;
            break;
        case '.':
            // '/''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::RootExtensionPut;
                m_final = &cDerive::RootExtensionFinal;
            }
            else
            {
                // '/''.''.' 
                m_put = &cDerive::RootParentPut;
                m_final = &cDerive::RootParentFinal;
            }
            break;
        default:
            // '/''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerive::RootNameFinal;
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
    tLength RootCurrentFinal() 
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
     * Function: ParentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '.''.'?
     **********************************************************************
     */
    tLength ParentPut
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
            m_put = &cDerive::NamePut;
            break;
        case '.':
            // '.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::ExtensionPut;
                m_final = &cDerive::ExtensionFinal;
            }
            else
            {
                // '.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerive::NamePut;
                m_final = &cDerive::NameFinal;
            }
            break;
        default:
            // '.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerive::NameFinal;
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
    tLength ParentFinal() 
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
     * Function: RootParentPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/''.''.'?
     **********************************************************************
     */
    tLength RootParentPut
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
            m_put = &cDerive::NamePut;
            break;
        case '.':
            // '/''.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::RootExtensionPut;
                m_final = &cDerive::RootExtensionFinal;
            }
            else
            {
                // '/''.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerive::RootNamePut;
                m_final = &cDerive::RootNameFinal;
            }
            break;
        default:
            // '/''.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerive::RootNameFinal;
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
    tLength RootParentFinal() 
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
     * Function: RootPut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * '/'?
     **********************************************************************
     */
    tLength RootPut
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
                m_put = &cDerive::NamePut;
            }
            else 
            {
                // '/''/'
                m_put = &cDerive::HostPut;
                m_final = &cDerive::HostFinal;
            }
            break;
        case '.':
            // '/'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'.'
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::RootExtensionPut;
                m_final = &cDerive::RootExtensionFinal;
            }
            else
            {
                // '/''.' 
                m_put = &cDerive::RootCurrentPut;
                m_final = &cDerive::RootCurrentFinal;
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
            m_put = &cDerive::VolumePut;
            break;
        default:
            // '/'A
            m_token.Append(&c, 1);
            m_final = &cDerive::RootFinal;
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
    tLength RootFinal() 
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
     * Function: VolumePut
     *
     *   Author: $author$
     *     Date: 10/14/2009
     *
     * A+':'?
     **********************************************************************
     */
    tLength VolumePut
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
                m_put = &cDerive::NamePut;
            }
            else 
            {
                // A+':''/'
                m_put = &cDerive::RootPut;
                m_final = &cDerive::RootFinal;
            }
            break;
        case '.':
            // A+':'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'.'
                m_oldPut = &cDerive::NamePut;
                m_put = &cDerive::ExtensionPut;
                m_final = &cDerive::ExtensionFinal;
            }
            else
            {
                // A+':''.' 
                m_put = &cDerive::CurrentPut;
                m_final = &cDerive::CurrentFinal;
            }
            break;
        default:
            // A+':'A
            m_token.Append(&c, 1);
            m_final = &cDerive::NameFinal;
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
    tLength HostPut
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
            m_put = &cDerive::NamePut;
            break;
        default:
            // '/''/'A
            m_token.Append(&c, 1);
            m_final = &cDerive::HostFinal;
        }
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
    tLength HostFinal() 
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
        tLength count = PutN(what, length);
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

/*
 * WCHAR
 */
 
class cWToFilePathSeparatorWriter;
/**
 **********************************************************************
 * Typedef: cWToFilePathSeparatorWriterExtends
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cToFilePathSeparatorWriterT
<cWToFilePathSeparatorWriter, 
 cWFilePathSeparatorEventsInterface,
 cWString, cWCHARWriter, WCHAR>
cWToFilePathSeparatorWriterExtends;
/**
 **********************************************************************
 *  Class: cWToFilePathSeparatorWriter
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class cWToFilePathSeparatorWriter
: public cWToFilePathSeparatorWriterExtends
{
public:
    typedef cWToFilePathSeparatorWriterExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cWToFilePathSeparatorWriter
     *
     *       Author: $author$
     *         Date: 10/14/2009
     **********************************************************************
     */
    cWToFilePathSeparatorWriter
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
