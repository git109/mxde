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
 *   File: casn1readerevents.hxx
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
#if !defined(_CASN1READEREVENTS_HXX) || defined(CASN1READEREVENTS_MEMBERS_ONLY)
#if !defined(_CASN1READEREVENTS_HXX) && !defined(CASN1READEREVENTS_MEMBERS_ONLY)
#define _CASN1READEREVENTS_HXX
#endif /* !defined(_CASN1READEREVENTS_HXX) && !defined(CASN1READEREVENTS_MEMBERS_ONLY) */

#if !defined(CASN1READEREVENTS_MEMBERS_ONLY)
#include "casn1readereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cASN1ReaderEventsExtends
 *
 *  Author: $author$
 *    Date: 3/21/2010
 **********************************************************************
 */
typedef cASN1Base
cASN1ReaderEventsExtends;
/**
 **********************************************************************
 *  Class: cASN1ReaderEvents
 *
 * Author: $author$
 *   Date: 3/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cASN1ReaderEvents
: virtual public cASN1ReaderEventsImplement,
  public cASN1ReaderEventsExtends
{
public:
    typedef cASN1ReaderEventsImplement cImplements;
    typedef cASN1ReaderEventsExtends cExtends;

    cASN1ReaderEventsInterface* m_delegatedTo;

    /**
     **********************************************************************
     *  Constructor: cASN1ReaderEvents
     *
     *       Author: $author$
     *         Date: 3/22/2010
     **********************************************************************
     */
    cASN1ReaderEvents
    (cASN1ReaderEventsInterface* delegatedTo = 0)
    : m_delegatedTo(delegatedTo)
    {
    }
#else /* !defined(CASN1READEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CASN1READEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: OnASN1Block
     *
     *    Author: $author$
     *      Date: 3/21/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Block
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Block(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1PrimativeBlock
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1PrimativeBlock
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1PrimativeBlock(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructBlock
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructBlock
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructBlock(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1UndefinedBlock
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1UndefinedBlock
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1UndefinedBlock(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: OnASN1Primative
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Primative
    (const BYTE& byte, TSIZE bytes, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Primative(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1Construct
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Construct
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Construct(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1ConstructBegin
     *
     *   Author: $author$
     *     Date: 3/23/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructBegin
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructBegin(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1ConstructEnd
     *
     *   Author: $author$
     *     Date: 3/23/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructEnd
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructEnd(reader, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnASN1Any
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Any
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Any(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Boolean
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Boolean
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Boolean(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Integer
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Integer
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Integer(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1BitString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1BitString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1BitString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1OctetString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1OctetString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1OctetString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Null
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Null
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Null(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1ObjectID
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ObjectID
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ObjectID(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Object
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Object
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Object(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1External
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1External
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1External(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Real
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Real
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Real(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Enum
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Enum
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Enum(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Sequence
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Sequence
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Sequence(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1Set
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Set
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Set(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1NumericString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1NumericString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1NumericString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1PrintableString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1PrintableString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1PrintableString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1TeletexString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1TeletexString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1TeletexString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1VideotexString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1VideotexString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1VideotexString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1IA5String
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1IA5String
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1IA5String(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1UTCTime
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1UTCTime
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1UTCTime(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1GeneralizedTime
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1GeneralizedTime
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1GeneralizedTime(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1GraphicString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1GraphicString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1GraphicString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1VisibleString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1VisibleString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1VisibleString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnASN1GeneralString
     *
     *   Author: $author$
     *     Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1GeneralString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
     =0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1GeneralString(byte, bytes, asn1Block)))
            return count;

#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: OnASN1ConstructAny
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructAny
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructAny(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructBoolean
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructBoolean
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructBoolean(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructInteger
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructInteger
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructInteger(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructBitString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructBitString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructBitString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructOctetString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructOctetString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructOctetString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructNull
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructNull
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructNull(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructObjectID
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructObjectID
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructObjectID(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructObject
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructObject
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructObject(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructExternal
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructExternal
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructExternal(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructReal
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructReal
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructReal(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructEnum
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructEnum
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructEnum(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructSequence
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructSequence
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructSequence(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructSet
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructSet
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructSet(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructNumericString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructNumericString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructNumericString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructPrintableString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructPrintableString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructPrintableString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructTeletexString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructTeletexString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructTeletexString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructVideotexString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructVideotexString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructVideotexString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructIA5String
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructIA5String
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructIA5String(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructUTCTime
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructUTCTime
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructUTCTime(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructGeneralizedTime
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructGeneralizedTime
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructGeneralizedTime(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructGraphicString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructGraphicString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructGraphicString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructVisibleString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructVisibleString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructVisibleString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnASN1ConstructGeneralString
     *
     *    Author: $author$
     *      Date: 3/30/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ConstructGeneralString
    (cBYTEReaderInterface& reader, 
     const cASN1Block& asn1Block)
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ConstructGeneralString(reader, asn1Block)))
            return count;

         count = OnASN1Construct(reader, asn1Block);
		
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: DelegatedTo
     *
     *    Author: $author$
     *      Date: 3/22/2010
     **********************************************************************
     */
    virtual cASN1ReaderEventsInterface* DelegatedTo
    (const cASN1ReaderEventsInterface& delegated) const
#if defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        cASN1ReaderEventsInterface* delegatedTo = 0;
#if !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        delegatedTo = ((cASN1ReaderEventsInterface*)(m_delegatedTo));
#else /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CASN1READEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegatedTo;
    }
#endif /* defined(CASN1READEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CASN1READEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CASN1READEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CASN1READEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CASN1READEREVENTS_HXX) || defined(CASN1READEREVENTS_MEMBERS_ONLY) */
