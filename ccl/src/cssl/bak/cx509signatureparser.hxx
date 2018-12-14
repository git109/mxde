/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cx509signatureparser.hxx
 *
 * Author: $author$
 *   Date: 2/6/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CX509SIGNATUREPARSER_HXX
#define _CX509SIGNATUREPARSER_HXX

#include "casn1parser.hxx"
#include "cx509hash.hxx"

/**
 **********************************************************************
 *  Class: cX509SignatureParser
 *
 * Author: $author$
 *   Date: 2/6/2005
 **********************************************************************
 */
class cX509SignatureParser
: public cASN1Parser
{
public:
    typedef cASN1Parser cIs;

    typedef eError (cX509SignatureParser::*mOnOctetString)
    (cBYTEStream &stream, unsigned length);

    cX509Hash *m_hash;
    mOnOctetString m_on_octet_string;

    /**
     **********************************************************************
     * Constructor: cX509SignatureParser
     *
     *      Author: $author$
     *        Date: 2/6/2005
     **********************************************************************
     */
    cX509SignatureParser(cX509Hash *hash=0) 
    : m_hash(hash),
      m_on_octet_string(DefaultOnOctetString)
    {
    }

    /**
     **********************************************************************
     * Function: OnMD5Hash
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnMD5Hash
    (cBYTEStream &stream, unsigned length) 
    {
        eError error;

        if (!(error = OnHash(stream, length)))
        if (m_hash)
            error = m_hash->SetMD5Verify();

        return error;
    }
    /**
     **********************************************************************
     * Function: OnSHA1Hash
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnSHA1Hash
    (cBYTEStream &stream, unsigned length) 
    {
        eError error;

        if (!(error = OnHash(stream, length)))
        if (m_hash)
            error = m_hash->SetSHA1Verify();

        return error;
    }
    /**
     **********************************************************************
     * Function: OnHash
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnHash
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (m_hash)
        if (0 < (count = m_hash->Read(stream, length)))
            error = e_ERROR_NONE;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnTypeof
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnTypeof(cASN1Typeof &typeof) 
    {
        eError error = e_ERROR_NONE;
        const char *name = typeof.GetName();

        printf("%s", name);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLengthof
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnLengthof(cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        unsigned length = lengthof.GetValue();

        printf("[%u]\n", length);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnObjectIDValue
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnObjectIDValue
    (const cASN1ObjectIdentifier &id) 
    {
        eError error = e_ERROR_NONE;
        const char *id_name = id.GetName();
        int id_type = id.GetType();

        printf("%s\n", id_name);

        switch(id_type)
        {
        case cASN1ObjectIdentifier::e_md5:
            m_on_octet_string = md5OnOctetString;
            break;
        case cASN1ObjectIdentifier::e_sha1:
            m_on_octet_string = sha1OnOctetString;
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOctetString
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    virtual eError OnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = (this->*m_on_octet_string)(stream, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: DefaultOnOctetString
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    eError DefaultOnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: md5OnOctetString
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    eError md5OnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = OnMD5Hash(stream, length);
        m_on_octet_string = DefaultOnOctetString;
        return error;
    }
    /**
     **********************************************************************
     * Function: sha1OnOctetString
     *
     *   Author: $author$
     *     Date: 2/6/2005
     **********************************************************************
     */
    eError sha1OnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = OnSHA1Hash(stream, length);
        m_on_octet_string = DefaultOnOctetString;
        return error;
    }
};

#endif /* _CX509SIGNATUREPARSER_HXX */