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
 *   File: cwriter.hxx
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
#if defined(CWRITER_MEMBER_FUNCS_ONLY) 
#if defined(_CWRITER_HXX) 
#define _CWRITER_HXX_OLD 
#undef _CWRITER_HXX
#endif /* defined(_CWRITER_HXX) */
#endif /* defined(CWRITER_MEMBER_FUNCS_ONLY) */

#ifndef _CWRITER_HXX
#define _CWRITER_HXX

#if !defined(CWRITER_MEMBER_FUNCS_ONLY) 
#include "cstreambase.hxx"
#include "cwriterinterface.hxx"

class cWriter;

#undef CDB_CLASS
#define CDB_CLASS "cWriterT"
/**
 **********************************************************************
 *  Class: cWriterT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cWriter,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TWriterImplement=cWriterImplement,
 class TStreamBase=cStreamBase,
 class TImplements=TWriterImplement,
 class TExtends=TStreamBase>
 
class cWriterT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cWriterT cDerives;

#define CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstreaminterfacebase.hxx"
#undef CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY

    /**
     **********************************************************************
     * Constructor: cWriterT
     *
     *      Author: $author$
     *        Date: 2/27/2009
     **********************************************************************
     */
    cWriterT() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWriterT
     *
     *     Author: $author$
     *       Date: 2/27/2009
     **********************************************************************
     */
    virtual ~cWriterT()
    {
    }
#else /* !defined(CWRITER_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_ONLY) */

    /**
     **********************************************************************
     * Function: Think
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Think
    (const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Write
    (const tWhat* what,
     tLength length=vUndefinedLength) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Flush
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual tLength Flush() 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Thought
     *
     *   Author: $author$
     *     Date: 2/27/2009
     **********************************************************************
     */
    virtual const tWhat* Thought
    (tLength& length) const 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        const tWhat* what = 0;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
        length = 0;
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return what;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DelegateWriter
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tWriterInterface* DelegateWriter
    (tWriterInterface* delegated) 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tWriterInterface* delegated = 0;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WriterDelegate
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tWriterInterface* WriterDelegate() const 
#if defined(CWRITER_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */
    {
        tWriterInterface* delegated = 0;
#if !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CWRITER_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWRITER_MEMBER_FUNCS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWriterExtends
 *
 *  Author: $author$
 *    Date: 3/2/2009
 **********************************************************************
 */
typedef cWriterT<cWriter>
cWriterExtends;
/**
 **********************************************************************
 *  Class: cWriter
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
class cWriter
: public cWriterExtends
{
public:
    typedef cWriterExtends cExtends;
    typedef cWriter cDerives;
};

/*
 * TCHAR
 */
class cTCHARWriter;
/**
 **********************************************************************
 * Typedef: cTCHARWriterExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterT
<cTCHARWriter,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARWriterImplement, cTCHARStreamBase>
cTCHARWriterExtends;
/**
 **********************************************************************
 *  Class: cTCHARWriter
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARWriter
: public cTCHARWriterExtends
{
public:
    typedef cTCHARWriterExtends cExtends;
    typedef cTCHARWriter cDerives;
};

/*
 * WCHAR
 */
class cWCHARWriter;
/**
 **********************************************************************
 * Typedef: cWCHARWriterExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterT
<cWCHARWriter,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARWriterImplement, cWCHARStreamBase>
cWCHARWriterExtends;
/**
 **********************************************************************
 *  Class: cWCHARWriter
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARWriter
: public cWCHARWriterExtends
{
public:
    typedef cWCHARWriterExtends cExtends;
    typedef cWCHARWriter cDerives;
};
#else /* !defined(CWRITER_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CWRITER_MEMBER_FUNCS_ONLY) */
#endif /* _CWRITER_HXX */

#if defined(CWRITER_MEMBER_FUNCS_ONLY) 
#if defined(_CWRITER_HXX_OLD) 
#define _CWRITER_HXX 
#undef _CWRITER_HXX_OLD
#endif /* defined(_CWRITER_HXX_OLD) */
#endif /* defined(CWRITER_MEMBER_FUNCS_ONLY) */
