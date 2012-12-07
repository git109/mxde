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
 *   File: cx509certreader.hxx
 *
 * Author: $author$
 *   Date: 4/2/2010
 **********************************************************************
 */
#if !defined(_CX509CERTREADER_HXX) || defined(CX509CERTREADER_MEMBERS_ONLY)
#if !defined(_CX509CERTREADER_HXX) && !defined(CX509CERTREADER_MEMBERS_ONLY)
#define _CX509CERTREADER_HXX
#endif /* !defined(_CX509CERTREADER_HXX) && !defined(CX509CERTREADER_MEMBERS_ONLY) */

#if !defined(CX509CERTREADER_MEMBERS_ONLY)
#include "cx509reader.hxx"
#include "cx509certinterface.hxx"
#include "cmd5.hxx"
#include "csha1.hxx"
#include "ccryptohash.hxx"
#include "ccryptohashinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cX509CertReaderExtend
 *
 *  Author: $author$
 *    Date: 4/2/2010
 **********************************************************************
 */
typedef cX509Reader
cX509CertReaderExtend;
/**
 **********************************************************************
 *  Class: cX509CertReader
 *
 * Author: $author$
 *   Date: 4/2/2010
 **********************************************************************
 */
class c_ASN1_CLASS cX509CertReader
: public cX509CertReaderExtend
{
public:
    typedef cX509CertReaderExtend cExtends;
    typedef cX509CertReader cDerives;

private:
    typedef TLENGTH (cDerives::*mRead)
    (cBYTEReaderInterface& reader);

    typedef TLENGTH (cDerives::*mOnReadHashed)
    (BYTE* byte, TSIZE bytes);

    cX509CertInterface& m_x509Cert;
    mRead m_read;
    mOnReadHashed m_onReadHashed;
    cBYTEBuffer m_hashedBuffer;

    cCryptoHashInterface* m_hash;
    cMD5 m_md5;
    cSHA1 m_sha1;

public:
    cBYTEBuffer m_hashBuffer;
    cBYTEBuffer m_rsaModulusBuffer;
    cBYTEBuffer m_rsaExponentBuffer;

    /**
     **********************************************************************
     *  Constructor: cX509CertReader
     *
     *       Author: $author$
     *         Date: 4/2/2010
     **********************************************************************
     */
    cX509CertReader
    (cX509CertInterface& x509Cert,
     cASN1ReaderEventsInterface* delegatedTo = 0)
    : cExtends(delegatedTo),
      m_x509Cert(x509Cert),
      m_read(0),
      m_onReadHashed(0),
      m_hash(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cX509CertReader
     *
     *      Author: $author$
     *        Date: 4/2/2010
     **********************************************************************
     */
    virtual ~cX509CertReader()
    {
    }
#else /* !defined(CX509CERTREADER_MEMBERS_ONLY) */
#endif /* !defined(CX509CERTREADER_MEMBERS_ONLY) */

#if !defined(CX509CERTREADER_MEMBERS_ONLY)
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
        {
            TLENGTH count2;

            if (0 > (count2 = m_hashedBuffer.Clear()))
                return count2;

            m_onReadHashed = &cDerives::OnReadHashedBuffered;
            m_read = &cDerives::ExtendsRead;
            m_hash = 0;
            count = cExtends::Read(reader);
            m_hash = 0;
            m_read = 0;
            m_onReadHashed = 0;
        }
        return count;
    }
    /**
     **********************************************************************
     *  Function: ExtendsRead
     *
     *    Author: $author$
     *      Date: 3/31/2010
     **********************************************************************
     */
    virtual TLENGTH ExtendsRead
    (cBYTEReaderInterface& reader)
    {
        TLENGTH count = cExtends::Read(reader);
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
        const BYTE* nByte;
        for (nByte = &byte; (bytes && (!*nByte)); --bytes)
            nByte++;
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
        TLENGTH count = On_Algorithm_ObjectID
        (m_md5, byte, bytes, asn1Block);
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
        TLENGTH count = On_Algorithm_ObjectID
        (m_sha1, byte, bytes, asn1Block);
        return count;
    }
    /**
     **********************************************************************
     * Function: On_Algorithm_ObjectID
     *
     *   Author: $author$
     *     Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH On_Algorithm_ObjectID
    (cCryptoHashInterface& hash,
     const BYTE& byte, TSIZE bytes,
     const cASN1Block& asn1Block) 
    {
        TLENGTH count = 0;
        TLENGTH count2;
        const BYTE* hashed;
        TLENGTH hashedLength;

        if (m_onReadHashed != &cDerives::OnReadHashedHashed)
        {
            m_hash = &hash;

            if ((hashed = m_hashedBuffer.Buffer(hashedLength)))
            if (0 < (hashedLength))
            if (0 > (count2 = m_hash->Initialize()))
                return count2;
            else
            if (0 > (count2 = m_hash->Hash(hashed, hashedLength)))
                return count2;
            else
            if (0 > (count2 = m_hashedBuffer.Clear()))
                return count2;

            m_onReadHashed = &cDerives::OnReadHashedHashed;
        }
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
        TLENGTH count2;
        TLENGTH hashBytesLength;
        TLENGTH hashBytesSize;
        BYTE* hashBytes;

        if (m_hash)
        if (0 > (hashBytesLength = m_hash->HashSize()))
            return hashBytesLength;
        else
        if (0 > (count2 = m_hashBuffer.SetLength(hashBytesLength)))
            return count2;
        else
        if ((hashBytes = m_hashBuffer.WriteBuffer(hashBytesSize, hashBytesLength)))
        if (0 > (count2 = m_hash->Finalize(hashBytes, hashBytesLength)))
            return count2;
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadHashed
     *
     *    Author: $author$
     *      Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadHashed
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        if (m_onReadHashed)
            count = (this->*m_onReadHashed)(byte, bytes);
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadHashedBuffered
     *
     *    Author: $author$
     *      Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadHashedBuffered
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = m_hashedBuffer.Append(byte, bytes);
        return count;
    }
    /**
     **********************************************************************
     *  Function: OnReadHashedHashed
     *
     *    Author: $author$
     *      Date: 4/2/2010
     **********************************************************************
     */
    virtual TLENGTH OnReadHashedHashed
    (BYTE* byte, TSIZE bytes)
    {
        TLENGTH count = 0;
        TLENGTH count2;
        if (m_hash && bytes)
        if (0 > (count2 = m_hash->Hash(byte, bytes)))
            return count2;
        return count;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CX509CERTREADER_MEMBERS_ONLY) */
#endif /* !defined(CX509CERTREADER_MEMBERS_ONLY) */

#endif /* !defined(_CX509CERTREADER_HXX) || defined(CX509CERTREADER_MEMBERS_ONLY) */
