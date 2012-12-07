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
 *   Date: 3/16/2009
 **********************************************************************
 */
#if !defined(_CREADER_HXX) || defined(CREADER_MEMBERS_ONLY)
#if !defined(_CREADER_HXX) && !defined(CREADER_MEMBERS_ONLY)
#define _CREADER_HXX
#endif /* !defined(_CREADER_HXX) && !defined(CREADER_MEMBERS_ONLY) */

#if !defined(CREADER_MEMBERS_ONLY) 
#include "creaderinterface.hxx"
#include "csequence.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cReader;

#undef CDB_CLASS
#define CDB_CLASS "cReaderT"
/**
 **********************************************************************
 *  Class: cReaderT
 *
 * Author: $author$
 *   Date: 3/16/2009
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
     *        Date: 3/16/2009
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
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tReaderInterface* delegated;
        if ((delegated = ReaderDelegate()))
            count = delegated->Read(what, size);
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
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tReaderInterface* delegated;
        if ((delegated = ReaderDelegate()))
            count = delegated->Peek(what);
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
#if !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CREADER_MEMBER_FUNCS_IMPLEMENT) */
        tReaderInterface* delegated;
        if ((delegated = ReaderDelegate()))
            count = delegated->Get(what);
        else
        count = Read(&what, 1);
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Reread
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Reread
    (tLength length=vUndefinedLength) 
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
            count = delegated->Reread(length);
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
    virtual tLength Fill
    (tLength length=vUndefinedLength) 
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
            count = delegated->Fill(length);
        return count;
    }
#endif /* defined(CREADER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Empty
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Empty
    (tLength length=vUndefinedLength) 
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
            count = delegated->Empty(length);
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
        tReaderInterface* delegated;
        if ((delegated = ReaderDelegate()))
            what = delegated->See(length);
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
class c_INSTANCE_CLASS cReader;
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
typedef
class c_INSTANCE_CLASS cReader
: public cReaderExtends
{
public:
    typedef cReaderExtends cExtends;
    typedef cReader cDerives;
    /**
     **********************************************************************
     * Constructor: cReader
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cReader
    (tReaderInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
} cCHARReader;

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARReader;
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
class c_INSTANCE_CLASS cTCHARReader
: public cTCHARReaderExtends
{
public:
    typedef cTCHARReaderExtends cExtends;
    typedef cTCHARReader cDerives;
    /**
     **********************************************************************
     * Constructor: cTCHARReader
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cTCHARReader
    (tReaderInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARReader;
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
class c_INSTANCE_CLASS cWCHARReader
: public cWCHARReaderExtends
{
public:
    typedef cWCHARReaderExtends cExtends;
    typedef cWCHARReader cDerives;
    /**
     **********************************************************************
     * Constructor: cWCHARReader
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cWCHARReader
    (tReaderInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEReader;
/**
 **********************************************************************
 * Typedef: cBYTEReaderExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderT
<cBYTEReader, cBYTEReaderImplement, cBYTEReaderInterface, 
 cBYTESequence, BYTE>
cBYTEReaderExtends;
/**
 **********************************************************************
 *  Class: cBYTEReader
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEReader
: public cBYTEReaderExtends
{
public:
    typedef cBYTEReaderExtends cExtends;
    typedef cBYTEReader cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEReader
     *
     *      Author: $author$
     *        Date: 3/16/2009
     **********************************************************************
     */
    cBYTEReader
    (tReaderInterface* delegated=0) 
    : cExtends(delegated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREADER_MEMBERS_ONLY) */
#endif /* !defined(CREADER_MEMBERS_ONLY) */

#endif /* !defined(_CREADER_HXX) || defined(CREADER_MEMBERS_ONLY) */
