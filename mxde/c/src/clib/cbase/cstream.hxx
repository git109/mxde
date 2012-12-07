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
 *   File: cstream.hxx
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
#if !defined(_CSTREAM_HXX) || defined(CSTREAM_MEMBERS_ONLY)
#if !defined(_CSTREAM_HXX) && !defined(CSTREAM_MEMBERS_ONLY)
#define _CSTREAM_HXX
#endif /* !defined(_CSTREAM_HXX) && !defined(CSTREAM_MEMBERS_ONLY) */

#if !defined(CSTREAM_MEMBERS_ONLY) 
#include "csequence.hxx"
#include "cstreaminterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cStream;

#undef CDB_CLASS
#define CDB_CLASS "cStreamT"
/**
 **********************************************************************
 *  Class: cStreamT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cStream,
 class TStreamImplement=cStreamImplement,
 class TStreamInterface=cStreamInterface,
 class TReaderInterface=cReaderInterface,
 class TWriterInterface=cWriterInterface,
 class TSequence=cSequence,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TStreamImplement,
 class TExtends=TSequence>
 
class c_INSTANCE_CLASS cStreamT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    typedef TReaderInterface tReaderInterface;
    typedef TWriterInterface tWriterInterface;
    typedef TStreamInterface tStreamInterface;

/* include cStream interface member definitions
 */
#define CSTREAMINTERFACE_MEMBERS_ONLY
#include "cstreaminterface.hxx"
#undef CSTREAMINTERFACE_MEMBERS_ONLY

    tStreamInterface* m_delegated;
    tReaderInterface* m_readerDelegated;
    tWriterInterface* m_writerDelegated;

    /**
     **********************************************************************
     * Constructor: cStreamT
     *
     *      Author: $author$
     *        Date: 3/17/2009
     **********************************************************************
     */
    cStreamT
    (tStreamInterface* delegated=0)
    : m_delegated(delegated),
      m_readerDelegated(delegated),
      m_writerDelegated(delegated)
    {
        if (delegated)
        {
            CTHIS DelegateReader(delegated);
            CTHIS DelegateWriter(delegated);
        }
    }
#else /* !defined(CSTREAM_MEMBERS_ONLY) */
#endif /* !defined(CSTREAM_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Reset
     *
     *   Author: $author$
     *     Date: 9/14/2009
     **********************************************************************
     */
    virtual tLength Reset
    (tLength length=vUndefinedLength) 
#if defined(CSTREAM_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CSTREAM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
#else /* !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) */
        tLength count2;
        tStreamInterface* delegated;
        if ((delegated = StreamDelegate()))
            count = delegated->Reset(length);
        else
        if (0 > (count = CTHIS Reread(length)))
            return count;
        else
        if (0 > (count2 = CTHIS Rewrite(length)))
            return count2;
        else
        count += count2;
        return count;
    }
#endif /* defined(CSTREAM_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: DelegateStream
     *
     *   Author: $author$
     *     Date: 3/17/2009
     **********************************************************************
     */
    virtual tStreamInterface* DelegateStream
    (tStreamInterface* delegateTo) 
#if defined(CSTREAM_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTREAM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        tStreamInterface* delegated = (m_delegated = delegateTo);
#else /* !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) */
        tStreamInterface* delegated = 0;
#endif /* !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) */
        CTHIS DelegateReader(delegateTo);
        CTHIS DelegateWriter(delegateTo);
        return delegated;
    }
#endif /* defined(CSTREAM_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: StreamDelegate
     *
     *   Author: $author$
     *     Date: 3/17/2009
     **********************************************************************
     */
    virtual tStreamInterface* StreamDelegate() const 
#if defined(CSTREAM_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTREAM_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) 
        tStreamInterface* delegated = m_delegated;
#else /* !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) */
        tStreamInterface* delegated = 0;
#endif /* !defined(CSTREAM_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CSTREAM_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSTREAM_MEMBERS_ONLY) 
    /**
     **********************************************************************
     * Function: DelegateReader
     *
     *   Author: $author$
     *     Date: 3/28/2009
     **********************************************************************
     */
    virtual tReaderInterface* DelegateReader
    (tReaderInterface* delegateTo) 
    {
        tReaderInterface* delegated = (m_readerDelegated = delegateTo);
        return delegated;
    }
    /**
     **********************************************************************
     * Function: ReaderDelegate
     *
     *   Author: $author$
     *     Date: 3/28/2009
     **********************************************************************
     */
    virtual tReaderInterface* ReaderDelegate() const 
    {
        tReaderInterface* delegated = CTHIS m_readerDelegated;
        return delegated;
    }
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INSTANCE_CLASS cStream;
/**
 **********************************************************************
 * Typedef: cStreamExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamT
<cStream, cStreamImplement, cStreamInterface,
 cReaderInterface, cWriterInterface, cSequence, CHAR>
cStreamExtends;
/**
 **********************************************************************
 *  Class: cStream
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cStream
: public cStreamExtends
{
public:
    typedef cStreamExtends cExtends;
    typedef cStream cDerives;
    /**
     **********************************************************************
     * Constructor: cStream
     *
     *      Author: $author$
     *        Date: 3/17/2009
     **********************************************************************
     */
    cStream
    (tStreamInterface* delegated=0)
    : cExtends(delegated)
    {
    }
};

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARStream;
/**
 **********************************************************************
 * Typedef: cTCHARStreamExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamT
<cTCHARStream, cTCHARStreamImplement, cTCHARStreamInterface,
 cTCHARReaderInterface, cTCHARWriterInterface, cTCHARSequence, TCHAR>
cTCHARStreamExtends;
/**
 **********************************************************************
 *  Class: cTCHARStream
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARStream
: public cTCHARStreamExtends
{
public:
    typedef cTCHARStreamExtends cExtends;
    typedef cTCHARStream cDerives;
    /**
     **********************************************************************
     * Constructor: cTCHARStream
     *
     *      Author: $author$
     *        Date: 3/17/2009
     **********************************************************************
     */
    cTCHARStream
    (tStreamInterface* delegated=0)
    : cExtends(delegated)
    {
    }
};

/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARStream;
/**
 **********************************************************************
 * Typedef: cWCHARStreamExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamT
<cWCHARStream, cWCHARStreamImplement, cWCHARStreamInterface,
 cWCHARReaderInterface, cWCHARWriterInterface, cWCHARSequence, WCHAR>
cWCHARStreamExtends;
/**
 **********************************************************************
 *  Class: cWCHARStream
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARStream
: public cWCHARStreamExtends
{
public:
    typedef cWCHARStreamExtends cExtends;
    typedef cWCHARStream cDerives;
    /**
     **********************************************************************
     * Constructor: cWCHARStream
     *
     *      Author: $author$
     *        Date: 3/17/2009
     **********************************************************************
     */
    cWCHARStream
    (tStreamInterface* delegated=0)
    : cExtends(delegated)
    {
    }
};

/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTEStream;
/**
 **********************************************************************
 * Typedef: cBYTEStreamExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamT
<cBYTEStream, cBYTEStreamImplement, cBYTEStreamInterface,
 cBYTEReaderInterface, cBYTEWriterInterface, cBYTESequence, BYTE>
cBYTEStreamExtends;
/**
 **********************************************************************
 *  Class: cBYTEStream
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEStream
: public cBYTEStreamExtends
{
public:
    typedef cBYTEStreamExtends cExtends;
    typedef cBYTEStream cDerives;
    /**
     **********************************************************************
     * Constructor: cBYTEStream
     *
     *      Author: $author$
     *        Date: 3/17/2009
     **********************************************************************
     */
    cBYTEStream
    (tStreamInterface* delegated=0)
    : cExtends(delegated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTREAM_MEMBERS_ONLY) */
#endif /* !defined(CSTREAM_MEMBERS_ONLY) */

#endif /* !defined(_CSTREAM_HXX) || defined(CSTREAM_MEMBERS_ONLY) */
