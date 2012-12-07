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
 *   File: cx509reader.hxx
 *
 * Author: $author$
 *   Date: 3/28/2010
 **********************************************************************
 */
#if !defined(_CX509READER_HXX) || defined(CX509READER_MEMBERS_ONLY)
#if !defined(_CX509READER_HXX) && !defined(CX509READER_MEMBERS_ONLY)
#define _CX509READER_HXX
#endif /* !defined(_CX509READER_HXX) && !defined(CX509READER_MEMBERS_ONLY) */

#if !defined(CX509READER_MEMBERS_ONLY)
#include "cx509readerinterface.hxx"
#include "casn1reader.hxx"
#include "casn1objectid.hxx"
#include "ceventreader.hxx"
#include "creaderevent.hxx"
#include "cbuffer.hxx"
#include "ctypes.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cX509ReaderExtend
 *
 *  Author: $author$
 *    Date: 3/28/2010
 **********************************************************************
 */
typedef cASN1Reader
cX509ReaderExtend;
/**
 **********************************************************************
 *  Class: cX509Reader
 *
 * Author: $author$
 *   Date: 3/28/2010
 **********************************************************************
 */
class c_ASN1_CLASS cX509Reader
: virtual public cX509ReaderImplement,
  virtual public cBYTEReaderEventImplement,
  public cX509ReaderExtend
{
public:
    typedef cX509ReaderImplement cImplements;
    typedef cX509ReaderExtend cExtends;
    typedef cX509Reader cDerives;

private:
    typedef TLENGTH (cDerives::*mRead)
    (cBYTEReaderInterface& reader);

    typedef TLENGTH (cDerives::*mOnRead)
    (BYTE* byte, TSIZE bytes);

    typedef TLENGTH (cDerives::*mOnASN1Primative)
    (const BYTE& byte, TSIZE bytes, 
     const cASN1Block& asn1Block);

    TSIZE m_size;
    mRead m_read;
    mOnRead m_onRead;
    mOnASN1Primative m_onASN1OctetString;
    mOnASN1Primative m_onASN1BitString;
    mOnASN1Primative m_onASN1Integer;

    cBYTEBuffer m_readBuffer;

public:
    /**
     **********************************************************************
     *  Constructor: cX509Reader
     *
     *       Author: $author$
     *         Date: 3/28/2010
     **********************************************************************
     */
    cX509Reader
    (cASN1ReaderEventsInterface* delegatedTo = 0)
    : cExtends(delegatedTo),
      m_size(0),
      m_read(&cDerives::ReadLevel0),
      m_onRead(&cDerives::OnReadHashed),
      m_onASN1OctetString(0),
      m_onASN1BitString(0),
      m_onASN1Integer(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cX509Reader
     *
     *      Author: $author$
     *        Date: 3/28/2010
     **********************************************************************
     */
    virtual ~cX509Reader()
    {
    }
#else /* !defined(CX509READER_MEMBERS_ONLY) */
#endif /* !defined(CX509READER_MEMBERS_ONLY) */

#if !defined(CX509READER_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: Read
     *
     *    Author: $author$
     *      Date: 3/31/2010
     **********************************************************************
     */
    virtual TLENGTH Read
    (cBYTEReaderInterface& reader)
    {
        TLENGTH count = 0;

        if (m_read)
            count = (this->*m_read)(reader);
        else
        count = cExtends::Read(reader);
        return count;
    }
    /**
     **********************************************************************
     *  Function: ReadLevel0
     *
     *    Author: $author$
     *      Date: 3/31/2010
     **********************************************************************
     */
    virtual TLENGTH ReadLevel0
    (cBYTEReaderInterface& reader)
    {
        cBYTEEventReader eventReader(*this, reader);
        TLENGTH count = 0;
        TLENGTH count2;
        cASN1Block asn1Block;

        DBI(("()...\n"));

        m_size = 0;
        m_read = &cDerives::ReadLevel1;
        m_onRead = &cDerives::OnReadHashed;

        if (0 < (count2 = asn1Block.Read(eventReader)))
        {
            count += count2;

            m_size = asn1Block.Length();

            if (0 < (count2 = OnASN1Block(eventReader, asn1Block)))
                count += count2;
        }

        m_read = &cDerives::ReadLevel0;
        return count;
    }
    /**
     **********************************************************************
     *  Function: ReadLevel1
     *
     *    Author: $author$
     *      Date: 3/31/2010
     **********************************************************************
     */
    virtual TLENGTH ReadLevel1
    (cBYTEReaderInterface& reader)
    {
        TLENGTH count = 0;
        TLENGTH count2;
        TSIZE size;
        cASN1Block asn1Block;

        DBI(("()...\n"));

        size = 0;
        m_read = &cDerives::ReadLevel2;

        do
        {
            m_readBuffer.Clear();
            m_onRead = &cDerives::OnReadBuffered;

            if (0 < (count2 = asn1Block.Read(reader)))
            {
                count += count2;

                if (m_size <= (size += asn1Block.Size()))
                {
                    if (0 > (count2 = OnEndHashedASN1Block(reader, asn1Block)))
                        return count2;

                    m_onRead = &cDerives::OnReadEnd;
                }
                else
                m_onRead = &cDerives::OnReadBufferedHashed;

                if (0 < (count2 = OnASN1Block(reader, asn1Block)))
                    count += count2;
            }
        }
        while (count2 > 0);

        m_read = &cDerives::ReadLevel1;
        return count;
    }
    /**
     **********************************************************************
     *  Function: ReadLevel2
     *
     *    Author: $author$
     *      Date: 3/31/2010
     **********************************************************************
     */
    virtual TLENGTH ReadLevel2
    (cBYTEReaderInterface& reader)
    {
        TLENGTH count = 0;

        DBI(("()...\n"));

        count = cExtends::Read(reader);
        return count;
    }
    /**
     **********************************************************************
     * Function: OnEndHashedASN1Block
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH OnEndHashedASN1Block
    (cBYTEReaderInterface& reader,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        return count;
    }

    /**
     **********************************************************************
     * Function: OnASN1ObjectID
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1ObjectID
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        DBI(("()...\n"));

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1ObjectID(byte, bytes, asn1Block)))
            return count;

        {
            cBYTEBuffer oidData;
            cASN1ObjectID oidFind;
            const cASN1ObjectID* oid;
            const UINT32* oidValue;
            TLENGTH oidValueLength;
            eASN1ObjectID oidType;
            TLENGTH count2;

            if (0 < (oidData.Append(&byte, bytes)))
            if (0 < (oidFind.Read(oidData)))
            if ((oidValue = oidFind.Value(oidValueLength)))
            if ((oid = cASN1ObjectID::Find(oidValue)))
            {
                const CHAR* oidNameChars;
                if ((oidNameChars = oid->Name()))
                DBI(("() =\"%s\"\n", oidNameChars));

                switch((oidType = oid->Type()))
                {
                case e_ASN1_OBJECTID_authorityKeyIdentifier:
                    m_onASN1OctetString = &cDerives::On_authorityKeyIdentifier_ASN1OctetString;
                    break;

                case e_ASN1_OBJECTID_rsaEncryption:
                    if (0 > (count2 = On_rsaEncryption_ObjectID(byte, bytes, asn1Block)))
                        count = count2;
                    else
                    m_onASN1BitString = &cDerives::On_rsaEncryption_ASN1BitString;
                    break;

                case e_ASN1_OBJECTID_md5WithRSA:
                case e_ASN1_OBJECTID_md5WithRSAEncryption:
                    if (0 > (count2 = On_md5WithRSA_ObjectID(byte, bytes, asn1Block)))
                        count = count2;
                    else
                    m_onASN1BitString = &cDerives::On_md5WithRSAEncryption_ASN1BitString;
                    break;

                case e_ASN1_OBJECTID_sha1WithRSA:
                case e_ASN1_OBJECTID_sha1WithRSAEncryption:
                    if (0 > (count2 = On_sha1WithRSA_ObjectID(byte, bytes, asn1Block)))
                        count = count2;
                    else
                    m_onASN1BitString = &cDerives::On_sha1WithRSAEncryption_ASN1BitString;
                    break;
                }
            }
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: On_md5WithRSA_ObjectID
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH On_md5WithRSA_ObjectID
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: On_sha1WithRSA_ObjectID
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH On_sha1WithRSA_ObjectID
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: On_rsaEncryption_ObjectID
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH On_rsaEncryption_ObjectID
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        return count;
    }

    /**
     **********************************************************************
     * Function: OnASN1Integer
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1Integer
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        DBI(("()...\n"));

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1Integer(byte, bytes, asn1Block)))
            return count;

        if (m_onASN1Integer)
            count = (this->*m_onASN1Integer)(byte, bytes, asn1Block);
        return count;
    }
    /**
     **********************************************************************
     * Function: On_rsaModulus_ASN1Integer
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH On_rsaModulus_ASN1Integer
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        TLENGTH count2;
        DBI(("()...\n"));
        if (0 > (count2 = On_rsaModulus_Integer(byte, bytes, asn1Block)))
            return count2;
        m_onASN1Integer = &cDerives::On_rsaExponent_ASN1Integer;
        return count;
    }
    /**
     **********************************************************************
     * Function: On_rsaExponent_ASN1Integer
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH On_rsaExponent_ASN1Integer
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        TLENGTH count2;
        DBI(("()...\n"));
        if (0 > (count2 = On_rsaExponent_Integer(byte, bytes, asn1Block)))
            return count2;
        m_onASN1Integer = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: On_rsaModulus_Integer
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH On_rsaModulus_Integer
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     * Function: On_rsaExponent_Integer
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH On_rsaExponent_Integer
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        return count;
    }

    /**
     **********************************************************************
     * Function: OnASN1OctetString
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1OctetString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        DBI(("()...\n"));

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1OctetString(byte, bytes, asn1Block)))
            return count;

        if (m_onASN1OctetString)
            count = (this->*m_onASN1OctetString)(byte, bytes, asn1Block);
        return count;
    }
    /**
     **********************************************************************
     * Function: On_authorityKeyIdentifier_ASN1OctetString
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH On_authorityKeyIdentifier_ASN1OctetString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        m_onASN1OctetString = 0;
        DBI(("()...\n"));
        return count;
    }

    /**
     **********************************************************************
     * Function: OnASN1BitString
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH OnASN1BitString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        cASN1ReaderEventsInterface* delegatedTo = 0;

        DBI(("()...\n"));

        if ((delegatedTo = DelegatedTo((cASN1ReaderEventsInterface&)(*this))))
        if (0 != (count = delegatedTo->OnASN1BitString(byte, bytes, asn1Block)))
            return count;

        if (m_onASN1BitString)
            count = (this->*m_onASN1BitString)(byte, bytes, asn1Block);
        return count;
    }
    /**
     **********************************************************************
     * Function: On_rsaEncryption_ASN1BitString
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH On_rsaEncryption_ASN1BitString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        TLENGTH rsaDataXCharsSize;
        CHAR* rsaDataXChars;
        cBuffer rsaDataX;
        cBYTEBuffer rsaData;
        DBI(("()...\n"));

        m_onASN1BitString = 0;

        if (bytes+bytes <= (rsaDataX.SetLength(bytes+bytes)))
        if ((rsaDataXChars = rsaDataX.WriteBuffer(rsaDataXCharsSize)))
            cCHARS::ToX(rsaDataXChars, &byte, bytes);

        /* The initial octet shall encode, as an unsigned binary integer with bit 1 
         * as the least significant bit, the number of unused bits in the final 
         * subsequent octet. The number shall be in the range zero to seven.
         */
        if (0 < (rsaData.Append(&byte+1, bytes-1)))
        {
            m_onASN1Integer = &cDerives::On_rsaModulus_ASN1Integer;
            Read(rsaData);
            m_onASN1Integer = 0;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: On_md5WithRSAEncryption_ASN1BitString
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH On_md5WithRSAEncryption_ASN1BitString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        m_onASN1BitString = 0;
        DBI(("()...\n"));
        return count;
    }
    /**
     **********************************************************************
     * Function: On_sha1WithRSAEncryption_ASN1BitString
     *
     *   Author: $author$
     *     Date: 3/28/2010
     **********************************************************************
     */
    virtual TLENGTH On_sha1WithRSAEncryption_ASN1BitString
    (const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        DBI(("()...\n"));
        m_onASN1BitString = 0;
        return count;
    }

    /**
     **********************************************************************
     *  Function: OnRead
     *
     *    Author: $author$
     *      Date: 4/1/2010
     **********************************************************************
     */
    virtual TLENGTH OnRead
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        if (m_onRead)
            count = (this->*m_onRead)(byte, bytes);
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadBuffered
     *
     *    Author: $author$
     *      Date: 4/1/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadBuffered
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        TLENGTH count2;

        DBI(("(%p, %u)...\n", byte, bytes));

        if (0 > (count2 = m_readBuffer.Append(byte, bytes)))
            return count2;
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadBufferedHashed
     *
     *    Author: $author$
     *      Date: 4/1/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadBufferedHashed
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        TLENGTH count2;
        BYTE* buffered;
        TLENGTH length;
        TLENGTH size;

        DBI(("(%p, %u)...\n", byte, bytes));

        if ((buffered = m_readBuffer.WriteBuffer(size, length)))
        if (0 < (length))
        if (0 > (count2 = OnReadHashed(buffered, length)))
            return count2;
        else
        if (0 > (count2 = m_readBuffer.Clear()))
            return count2;

        count = OnReadHashed(byte, bytes);
        m_onRead = &cDerives::OnReadHashed;
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadHashed
     *
     *    Author: $author$
     *      Date: 4/1/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadHashed
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadEnd
     *
     *    Author: $author$
     *      Date: 4/1/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadEnd
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        DBI(("(%p, %u)...\n", byte, bytes));
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CX509READER_MEMBERS_ONLY) */
#endif /* !defined(CX509READER_MEMBERS_ONLY) */

#endif /* !defined(_CX509READER_HXX) || defined(CX509READER_MEMBERS_ONLY) */
