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
 *   File: ceventreader.hxx
 *
 * Author: $author$
 *   Date: 4/1/2010
 **********************************************************************
 */
#if !defined(_CEVENTREADER_HXX) || defined(CEVENTREADER_MEMBERS_ONLY)
#if !defined(_CEVENTREADER_HXX) && !defined(CEVENTREADER_MEMBERS_ONLY)
#define _CEVENTREADER_HXX
#endif /* !defined(_CEVENTREADER_HXX) && !defined(CEVENTREADER_MEMBERS_ONLY) */

#if !defined(CEVENTREADER_MEMBERS_ONLY)
#include "creadereventinterface.hxx"
#include "creader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cEventReader;

#undef CDB_CLASS
#define CDB_CLASS "cEventReaderT"
/**
 **********************************************************************
 *  Class: cEventReaderT
 *
 * Author: $author$
 *   Date: 4/1/2010
 **********************************************************************
 */
template
<class TDerives=cEventReader,
 class TReaderEventInterface=cReaderEventInterface,
 class TReader=cReader,
 class TReaderInterface=cReaderInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TExtends=TReader>

class c_INSTANCE_CLASS cEventReaderT
: public TExtends
{
public:
    typedef TExtends cExtends;

/* include cReader interface member definitions
 */
#define CREADERINTERFACE_MEMBERS_ONLY
#include "creaderinterface.hxx"
#undef CREADERINTERFACE_MEMBERS_ONLY

    typedef TReaderInterface tReaderInterface;
    typedef TReaderEventInterface tReaderEventInterface;

    tReaderEventInterface& m_readerEvent;

    /**
     **********************************************************************
     *  Constructor: cEventReaderT
     *
     *       Author: $author$
     *         Date: 4/1/2010
     **********************************************************************
     */
    cEventReaderT
    (tReaderEventInterface& readerEvent,
     tReaderInterface* delegated=0) 
    : m_readerEvent(readerEvent)
    {
        if (delegated)
            DelegateReader(delegated);
    }
    /**
     **********************************************************************
     *  Constructor: cEventReaderT
     *
     *       Author: $author$
     *         Date: 4/1/2010
     **********************************************************************
     */
    cEventReaderT
    (tReaderEventInterface& readerEvent,
     tReaderInterface& delegated) 
    : m_readerEvent(readerEvent)
    {
        DelegateReader(&delegated);
    }
    /**
     **********************************************************************
     *  Destructor: ~cEventReaderT
     *
     *      Author: $author$
     *        Date: 4/1/2010
     **********************************************************************
     */
    virtual ~cEventReaderT()
    {
    }
#else /* !defined(CEVENTREADER_MEMBERS_ONLY) */
#endif /* !defined(CEVENTREADER_MEMBERS_ONLY) */

#if !defined(CEVENTREADER_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 4/1/2010
     **********************************************************************
     */
    virtual tLength Read
    (tWhat* what,
     tSize size)
    {
        tLength count = 0;
        tLength count2;
        tReaderInterface* delegated;

        if ((delegated = CTHIS ReaderDelegate()))
        if (0 < (count = delegated->Read(what, size)))
        if (0 > (count2 = m_readerEvent.OnRead(what, (tSize)(count))))
            count = count2;
        return count;
    }
    /**
     **********************************************************************
     * Function: DelegateReader
     *
     *   Author: $author$
     *     Date: 4/1/2010
     **********************************************************************
     */
    virtual tReaderInterface* DelegateReader
    (tReaderInterface* delegateTo)
    {
        if ((CTHIS m_delegated = delegateTo))
        while ((delegateTo = CTHIS m_delegated->ReaderDelegate()))
            (CTHIS m_delegated = delegateTo);

        return CTHIS m_delegated;
    }
};
#undef CDB_CLASS

class c_INSTANCE_CLASS cBYTEEventReader;
/**
 **********************************************************************
 * Typedef: cBYTEEventReaderExtend
 *
 *  Author: $author$
 *    Date: 4/1/2010
 **********************************************************************
 */
typedef cEventReaderT
<cBYTEEventReader,
 cBYTEReaderEventInterface,
 cBYTEReader, cBYTEReaderInterface, BYTE>
cBYTEEventReaderExtend;
/**
 **********************************************************************
 *  Class: cBYTEEventReader
 *
 * Author: $author$
 *   Date: 4/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTEEventReader
: public cBYTEEventReaderExtend
{
public:
    typedef cBYTEEventReaderExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cBYTEEventReader
     *
     *       Author: $author$
     *         Date: 4/1/2010
     **********************************************************************
     */
    cBYTEEventReader
    (tReaderEventInterface& readerEvent,
     tReaderInterface* delegated=0) 
    : cExtends(readerEvent, delegated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cBYTEEventReader
     *
     *       Author: $author$
     *         Date: 4/1/2010
     **********************************************************************
     */
    cBYTEEventReader
    (tReaderEventInterface& readerEvent,
     tReaderInterface& delegated) 
    : cExtends(readerEvent, delegated)
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CEVENTREADER_MEMBERS_ONLY) */
#endif /* !defined(CEVENTREADER_MEMBERS_ONLY) */

#endif /* !defined(_CEVENTREADER_HXX) || defined(CEVENTREADER_MEMBERS_ONLY) */
