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
 *   File: creader.hxx
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
#if defined(CREADER_MEMBERS_ONLY) 
#if defined(_CREADER_HXX) 
#define _CREADER_HXX_OLD 
#undef _CREADER_HXX
#endif /* defined(_CREADER_HXX) */
#endif /* defined(CREADER_MEMBERS_ONLY) */

#ifndef _CREADER_HXX
#define _CREADER_HXX

#if !defined(CREADER_MEMBERS_ONLY)
#include "csequence.hxx"
#include "creaderinterface.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cReaderT"
/**
 **********************************************************************
 *  Class: cReaderT
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
template
<class TDerives=cReader,
 class TReaderImplement=cReaderImplement,
 class TReaderInterface=cReaderInterface,
 class TSequence=cSequence,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TReaderImplement,
 class TExtends=TSequence>
 
class cReaderT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TReaderInterface tReaderInterface;

/* include cReader interface member definitions
 */
#define CREADERINTERFACE_MEMBERS_ONLY
#include "creaderinterface.hxx"
#undef CREADERINTERFACE_MEMBERS_ONLY

    tReaderInterface* m_delegated;

    /**
     **********************************************************************
     * Constructor: cReaderT
     *
     *      Author: $author$
     *        Date: 2/26/2009
     **********************************************************************
     */
    cReaderT
    (tReaderInterface* delegated=0) 
    : m_delegated(delegated)
    {
    }
#else /* !defined(CREADER_MEMBERS_ONLY) */
#endif /* !defined(CREADER_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Look
     *
     *   Author: $author$
     *     Date: 2/26/2009
     **********************************************************************
     */
    virtual tLength Look
    (tWhat* what,
     tSize size) 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tReaderInterface* delegated;
        if ((delegated = ReaderDelegate()))
            count = delegated->Look(what, size);
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 2/26/2009
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size) 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Peek
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Peek
    (tWhat& what) 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Get
    (tWhat& what) 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Fill() 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: See
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual const tWhat* See
    (tLength& length) const 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* what = 0;
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        length = 0;
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return what;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DelegateReader
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tReaderInterface* DelegateReader
    (tReaderInterface* delegateTo) 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        tReaderInterface* delegated = (m_delegated = delegateTo);
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tReaderInterface* delegated = 0;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReaderDelegate
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tReaderInterface* ReaderDelegate() const 
#if defined(CREADER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        tReaderInterface* delegated = m_delegated;
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tReaderInterface* delegated = 0;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CREADER_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/*
 * CHAR
 */
class cReader;
/**
 **********************************************************************
 * Typedef: cReaderExtends
 *
 *  Author: $author$
 *    Date: 3/2/2009
 **********************************************************************
 */
typedef cReaderT
<cReader, cReaderImplement, cReaderInterface, 
 cSequence, CHAR>
cReaderExtends;
/**
 **********************************************************************
 *  Class: cReader
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
class cReader
: public cReaderExtends
{
public:
    typedef cReaderExtends cExtends;
    typedef cReader cDerives;
};

/*
 * TCHAR
 */
class cTCHARReader;
/**
 **********************************************************************
 * Typedef: cTCHARReaderExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderT
<cTCHARReader, cTCHARReaderImplement, cTCHARReaderInterface, 
 cTCHARSequence, TCHAR>
cTCHARReaderExtends;
/**
 **********************************************************************
 *  Class: cTCHARReader
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARReader
: public cTCHARReaderExtends
{
public:
    typedef cTCHARReaderExtends cExtends;
    typedef cTCHARReader cDerives;
};

/*
 * WCHAR
 */
class cWCHARReader;
/**
 **********************************************************************
 * Typedef: cWCHARReaderExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderT
<cWCHARReader, cWCHARReaderImplement, cWCHARReaderInterface, 
 cWCHARSequence, WCHAR>
cWCHARReaderExtends;
/**
 **********************************************************************
 *  Class: cWCHARReader
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARReader
: public cWCHARReaderExtends
{
public:
    typedef cWCHARReaderExtends cExtends;
    typedef cWCHARReader cDerives;
};
#else /* !defined(CREADER_MEMBERS_ONLY) */
#endif /* !defined(CREADER_MEMBERS_ONLY) */

#endif /* _CREADER_HXX */

#if defined(CREADER_MEMBERS_ONLY) 
#if defined(_CREADER_HXX_OLD) 
#define _CREADER_HXX
#undef _CREADER_HXX_OLD
#endif /* defined(_CREADER_HXX_OLD) */
#endif /* defined(CREADER_MEMBERS_ONLY) */
