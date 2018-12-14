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
 *   File: casn1parser.hxx
 *
 * Author: $author$
 *   Date: 1/27/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CASN1PARSER_HXX
#define _CASN1PARSER_HXX

#include "platform.h"
#include "cbytestreamproxy.hxx"
#include "cbytestream.hxx"
#include "cbytebuffer.hxx"
#include "casn1typeof.hxx"
#include "casn1lengthof.hxx"
#include "casn1objectidentifier.hxx"

/**
 **********************************************************************
 *  Class: cASN1Parser
 *
 * Author: $author$
 *   Date: 1/27/2005
 **********************************************************************
 */
class cASN1Parser
{
public:
    unsigned m_depth;
    cASN1ObjectIdentifier m_object_identifier;

    /**
     **********************************************************************
     * Constructor: cASN1Parser
     *
     *      Author: $author$
     *        Date: 1/27/2005
     **********************************************************************
     */
    cASN1Parser() 
    : m_depth(0)
    {
    }
    /**
     **********************************************************************
     * Function: Parse
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    virtual int Parse(cBYTEStream &stream) 
    {
        int length = ParseInto(stream);
        return length;
    }
    /**
     **********************************************************************
     * Function: ParseInto
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    virtual int ParseInto(cBYTEStream &stream) 
    {
        int count, length = 0;
        eError error;
        cASN1Typeof typeof;
        cASN1Lengthof lengthof;

        m_depth++;

        while (0 < (count = typeof.Read(stream)))
        {
            length += count;

            if ((error = OnTypeof(typeof)))
                return -error;

            if (0 < (count = lengthof.Read(stream)))
            {
                length += count;

                if ((error = OnLengthof(lengthof)))
                    return -error;

                if ((error = OnParse(stream, typeof, lengthof)))
                    return -error;
            }
        }

        --m_depth;
        return length;
    }
    /**
     **********************************************************************
     * Function: OnTypeof
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnTypeof(cASN1Typeof &typeof) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnLengthof
     *
     *   Author: $author$
     *     Date: 1/30/2005
     **********************************************************************
     */
    virtual eError OnLengthof(cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnParse
     *
     *   Author: $author$
     *     Date: 1/27/2005
     **********************************************************************
     */
    virtual eError OnParse
    (cBYTEStream &stream, cASN1Typeof &typeof, cASN1Lengthof &lengthof) 
    {
        eError error = e_ERROR_NONE;
        unsigned formof = typeof.GetFormof();
        unsigned type = typeof.GetValue();
        unsigned length = lengthof.GetValue();
        const char *name = typeof.GetName();

        switch(formof)
        {
        case cASN1Formof::e_Primative:
            error = OnPrimative(stream, name, type, length);
            break;

        case cASN1Formof::e_Construct:
            error = OnConstruct(stream, name, type, length);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPrimative
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnPrimative
    (cBYTEStream &stream, const char *name,
     unsigned type, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        int count;
        BYTE *buffer;
        cBYTEBuffer primative;

        if (0 > (count = primative.SetLength(length)))
            return -count;

        if (0 > (count = primative.Seek(0)))
            return -count;

        if (!(buffer = primative.GetWriteBuffer()))
            return e_ERROR_FAILED;

        if (0 > (count = stream.Read(buffer, length)))
            return -count;

        if ((unsigned)count < length)
            return e_ERROR_ENDOF;

        switch(type)
        {
        case cASN1Typeof::e_UTCTime:
            return OnUTCTime(primative, length);

        case cASN1Typeof::e_ObjectID:
            return OnObjectID(primative, length);

        case cASN1Typeof::e_Integer:
            return OnInteger(primative, length);

        case cASN1Typeof::e_PrintableString:
            return OnPrintableString(primative, length);

        case cASN1Typeof::e_OctetString:
            return OnOctetString(primative, length);

        case cASN1Typeof::e_BitString:
            return OnBitString(primative, length);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnConstruct
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnConstruct
    (cBYTEStream &stream, const char *name,
     unsigned type, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        cBYTEStreamProxy proxy(stream, length);
        int count;

        if (0 > (count = ParseInto(proxy)))
            error = -count;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnUTCTime
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnUTCTime
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnObjectID
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnObjectID
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        int size;

        if (0 > (size = m_object_identifier.Read(stream)))
            error = -size;

        error = OnObjectIDValue(m_object_identifier);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnObjectIDValue
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnObjectIDValue
    (const cASN1ObjectIdentifier &id) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnInteger
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnInteger
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPrintableString
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnPrintableString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnOctetString
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnOctetString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitString
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnBitString
    (cBYTEStream &stream, unsigned length) 
    {
        eError error = e_ERROR_NONE;
        int minus_bits;

        if (0 > (minus_bits = stream.Getb()))
            return -minus_bits;

        error = OnBitStringValue(stream, length-1, minus_bits);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnBitStringValue
     *
     *   Author: $author$
     *     Date: 1/28/2005
     **********************************************************************
     */
    virtual eError OnBitStringValue
    (cBYTEStream &stream, unsigned length, unsigned minus_bits) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

#endif /* _CASN1PARSER_HXX */