/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: chttp11header.hxx
 *
 * Author: $author$
 *   Date: 10/22/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP11HEADER_HXX
#define _CHTTP11HEADER_HXX

#include "ccharbufferoutputstream.hxx"
#include "ccharbufferinputstream.hxx"
#include "coutputstreaminterface.hxx"
#include "cinputstreaminterface.hxx"
#include "ccharstring.hxx"
#include "cnamedenumt.hxx"
#include "cvaluedenumt.hxx"
#include "clistt.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cHttpHeaderIntSerializer
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
class cHttpHeaderIntSerializer
{
public:
    int &m_value;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderIntSerializer
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpHeaderIntSerializer(int &value) 
    : m_value(value)
    {
    }
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output,
     const BYTE *endchars=0, int endchars_length=-1) const
    {
        int value, rvalue, digits, count, length=-e_ERROR_FAILED;
        BYTE c = 0;

        if (0 == m_value)
            length = output.Write(&c,1);

        else if (0 < (value = m_value))
        {
            for (digits=0, rvalue=0; value>0; value/=10, digits++)
                rvalue = rvalue * 10 + value % 10;

            for (count=0; count<digits; count++, rvalue/=10)
            {
                c = '0' + (rvalue % 10);

                if (0 > (length = output.Write(&c,1)))
                    return length;
            }
            length = count;
        }

        if (0 < length)
        if (endchars)
        {
            if (0 > (count = output.Write
                ((const BYTE*)endchars, endchars_length)))
                return count;

            length += count;
        }

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderVersionT
 *
 * Author: $author$
 *   Date: 10/22/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cHttpHeaderVersionT
: public TIs
{
public:
    typedef TIs cIs;

    int m_major,m_minor;

    cHttpHeaderIntSerializer 
        m_major_serializer,m_minor_serializer;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersionT
     *
     *      Author: $author$
     *        Date: 10/22/2004
     **********************************************************************
     */
    cHttpHeaderVersionT(int major=1, int minor=1) 
    : m_major(major),
      m_minor(minor),
      m_major_serializer(m_major),
      m_minor_serializer(m_minor)
    {
    }

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual void Set(int major, int minor) 
    {
        m_major = major;
        m_minor = minor;
    }

    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output,
     const BYTE *endchars=0, int endchars_length=-1) const
    {
        int length;
        const char *prefix = GetPrefix(length);
        char separator = GetSeparator();

        if (0 < (length = output.Write
            ((const BYTE*)prefix, length)))

        if (0 < (length = m_major_serializer
            .Serialize(output, (const BYTE*)&separator, 1)))
        {
            length = m_minor_serializer
            .Serialize(output, endchars, endchars_length);

            output.Flush();
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface& input, int endchar='\n') 
    {
        enum
        {
            e_STATE_PREFIX,
            e_STATE_MAJOR,
            e_STATE_MINOR
        } state = e_STATE_PREFIX;
        eError error = e_ERROR_FAILED;
        int major_value=-1, minor_value=-1;
        char separator = GetSeparator();
        int prefix_index,prefix_len,len;
        const char *prefix;
        char c;

        if (!(prefix = GetPrefix(prefix_len)))
            return error;

        prefix_index = 0;

        while (0 < (len = input.Read((BYTE*)&c, sizeof(c))))
        {
            if (0 < endchar)
            if (endchar == c)
                break;

            switch(state)
            {
            case e_STATE_PREFIX:
                if (c != prefix[prefix_index])
                {
                    if (0 < prefix_index)
                        return error;
                }
                else if (prefix_len <= ++prefix_index)
                        state = e_STATE_MAJOR;
                break;

            case e_STATE_MAJOR:
                if ((c >= '0') && (c <= '9'))
                {
                    if (major_value < 0)
                        major_value = 0;

                    major_value = major_value*10+(c-'0');
                }
                else if (separator == c)
                        state = e_STATE_MINOR;
                break;

            case e_STATE_MINOR:
                if ((c >= '0') && (c <= '9'))
                {
                    if (minor_value < 0)
                        minor_value = 0;

                    minor_value = minor_value*10+(c-'0');
                }
                break;
            }
        }

        if ((major_value >= 0) && (minor_value >= 0))
        {
            Set(major_value, minor_value);
            error = e_ERROR_NONE;
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: GetPrefix
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual const char* GetPrefix(int &len) const
    {
        static const char* prefix = "HTTP/";
        len = 5;
        return prefix;
    }
    /**
     **********************************************************************
     * Function: GetSeparator
     *
     *   Author: $author$
     *     Date: 10/23/2004
     **********************************************************************
     */
    virtual char GetSeparator() const
    {
        return '.';
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderVersion
 *
 * Author: $author$
 *   Date: 10/22/2004
 **********************************************************************
 */
class cHttpHeaderVersion
: public cHttpHeaderVersionT<>
{
public:
    typedef cHttpHeaderVersionT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderVersion
     *
     *      Author: $author$
     *        Date: 10/22/2004
     **********************************************************************
     */
    cHttpHeaderVersion(int major=1, int minor=1) 
    : cIs(major, minor) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldTypeT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template 
<class TAs, class TIs=cCharNamedEnumValueT<int, TAs> >

class cHttpHeaderFieldTypeT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/25/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_FIELD_CONNECTION,
        e_FIELD_CONTENT_TYPE,
        e_FIELD_CONTENT_LENGTH,
        e_FIELD_FROM,
        e_FIELD_HOST,
        e_FIELD_ACCEPT,
        e_FIELD_TRANSFER_ENCODING,
        e_FIELD_QUERY_STRING,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldTypeT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpHeaderFieldTypeT(int value=e_NONE)
    : cIs(value)
    {
    }

    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    static const char **GetNames()
    {
        static const char *name[e_NEXT]={
            "",
            "Connection",
            "Content-Type",
            "Content-Length",
            "From",
            "Host",
            "Accept",
            "Transfer-Encoding",
            "Query-String"
        };
        return name;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldType
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpHeaderFieldType
: public cHttpHeaderFieldTypeT<cHttpHeaderFieldType>
{
public:
    typedef cHttpHeaderFieldTypeT<cHttpHeaderFieldType> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldType
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpHeaderFieldType() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderConnectionFieldTypeT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template 
<class TAs, class TIs=cCharNamedEnumValueT<int, TAs> >

class cHttpHeaderConnectionFieldTypeT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/25/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_CONNECTION_KEEP_ALIVE,
        e_CONNECTION_CLOSE,
        e_CONNECTION_HOST,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    /**
     **********************************************************************
     * Constructor: cHttpHeaderConnectionFieldTypeT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpHeaderConnectionFieldTypeT(int value=e_NONE) 
    : cIs(value) 
    {
    }
    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    static const char** GetNames() 
    {
        static const char *names[e_NEXT]={
            "",
            "Keep-Alive",
            "close",
            "Host"
        };
        return names;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderConnectionFieldType
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpHeaderConnectionFieldType
: public cHttpHeaderConnectionFieldTypeT<cHttpHeaderConnectionFieldType>
{
public:
    typedef cHttpHeaderConnectionFieldTypeT<cHttpHeaderConnectionFieldType> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderConnectionFieldType
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpHeaderConnectionFieldType(int value=e_NONE) 
    : cIs(value) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderTransferEncodingFieldTypeT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template 
<class TAs, class TIs=cCharNamedEnumValueT<int, TAs> >

class cHttpHeaderTransferEncodingFieldTypeT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/25/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_TRANSFER_ENCODING_CHUNKED,

        e_NEXT,
        e_LAST=e_NEXT-1
    };

    /**
     **********************************************************************
     * Constructor: cHttpHeaderTransferEncodingFieldTypeT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpHeaderTransferEncodingFieldTypeT(int value=e_NONE) 
    : cIs(value) 
    {
    }
    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    static const char** GetNames() 
    {
        static const char *names[e_NEXT]={
            "",
            "chunked"
        };
        return names;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderTransferEncodingFieldType
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpHeaderTransferEncodingFieldType
: public cHttpHeaderTransferEncodingFieldTypeT
  <cHttpHeaderTransferEncodingFieldType>
{
public:
    typedef cHttpHeaderTransferEncodingFieldTypeT
    <cHttpHeaderTransferEncodingFieldType> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderTransferEncodingFieldType
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpHeaderTransferEncodingFieldType(int value=e_NONE) 
    : cIs(value) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldT
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
template <class TAs, class TIs=cDynamicListItemT<TAs> >
class cHttpHeaderFieldT
: public TIs
{
public:
    typedef TIs cIs;

    cCharString m_name, m_value;
    cHttpHeaderFieldType m_type;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderFieldT
     *
     *      Author: $author$
     *        Date: 10/28/2004
     **********************************************************************
     */
    cHttpHeaderFieldT
    (const char *name=0, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error;

        if ((error = Set(name, namelen, value, valuelen)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError Set
    (const char *name=0, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        if (name)
        {
            if (0 > (namelen = m_name.SetChars(name, namelen)))
                return error = -namelen;

            if ((name = m_name.GetChars(namelen)))
                m_type.SetValue(name);

            else m_type.SetValue
                 (cHttpHeaderFieldType::e_NONE);
        }

        if (value)
        if (0 > (valuelen = m_value.SetChars(value, valuelen)))
            error = -valuelen;

        return error;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetName(int &length) const
    {
        const char* chars = m_name.GetChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetValue(int &length) const
    {
        const char* chars = m_value.GetChars(length);
        return chars;
    }
    /**
     **********************************************************************
     * Function: GetValueType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetValueType() const
    {
        int type, value_type = 0;

        switch(type = m_type.GetValue())
        {
        case cHttpHeaderFieldType::e_FIELD_CONNECTION:
        case cHttpHeaderFieldType::e_FIELD_CONTENT_TYPE:
        case cHttpHeaderFieldType::e_FIELD_CONTENT_LENGTH:
        case cHttpHeaderFieldType::e_FIELD_FROM:
        case cHttpHeaderFieldType::e_FIELD_HOST:
        case cHttpHeaderFieldType::e_FIELD_ACCEPT:
        case cHttpHeaderFieldType::e_FIELD_TRANSFER_ENCODING:
        case cHttpHeaderFieldType::e_FIELD_QUERY_STRING:
            break;
        }
        return value_type;
    }
    /**
     **********************************************************************
     * Function: GetType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetType() const
    {
        int type = m_type.GetValue();
        return type;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderField
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cHttpHeaderField
: public cHttpHeaderFieldT<cHttpHeaderField>
{
public:
    typedef cHttpHeaderFieldT<cHttpHeaderField> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpHeaderField
     *
     *      Author: $author$
     *        Date: 10/28/2004
     **********************************************************************
     */
    cHttpHeaderField
    (const char *name=0, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    : cIs(name, namelen, value, valuelen) 
    {
    }
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output,
     const BYTE *endchars=0, int endchars_length=-1) const
    {
        int count,length,result = -e_ERROR_FAILED;
        const char *chars;

        if ((chars = m_name.GetChars(length)))
        if (0 < (count = (length = output.Write
            ((const BYTE*)chars, length))))
        if (0 < (length = output.Write((const BYTE*)": ")))
        {
            count += length;

            if ((chars = m_value.GetChars(length)))
            if (0 <= (length = output.Write
                ((const BYTE*)chars, length)))
            {
                count += length;

                if (endchars)
                {
                    if (0 < (length = output.Write
                        ((const BYTE*)endchars, endchars_length)))
                        result = count+length;
                }
                else result = count;
            }
        }

        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpHeaderFieldList
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cHttpHeaderFieldList
: public cDynamicListT
  <cHttpHeaderField, cHttpHeaderFieldList>
{
public:
    typedef cDynamicListT
    <cHttpHeaderField, cHttpHeaderFieldList> cIs;
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderMethodT
 *
 * Author: $author$
 *   Date: 10/22/2004
 **********************************************************************
 */
template 
<class TAs, class TIs=cCharNamedEnumValueT<int, TAs> >

class cHttpRequestHeaderMethodT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/22/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,
        e_METHOD_GET,
        e_METHOD_PUT,
        e_METHOD_POST,
        e_METHOD_DELETE,
        e_METHOD_TRACE,
        e_METHOD_OPTIONS,
        e_METHOD_HEAD,
        e_NEXT,
        e_LAST=e_NEXT-1
    };

    cCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethodT
     *
     *      Author: $author$
     *        Date: 10/22/2004
     **********************************************************************
     */
    cHttpRequestHeaderMethodT(int value=e_METHOD_GET) 
    : cIs(value) 
    {
    }

    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int SetName
    (const char* chars, int length=-1) 
    {
        this->SetValue(e_NONE);

        if (0 < (length = m_name.Copy(chars, length)))
        if ((chars = m_name.GetBuffer(length)))
            this->SetValue(chars);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetName(int &length) 
    {
        const char* chars = m_name.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/22/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface& input, int endchar=' ') 
    {
        eError error = e_ERROR_FAILED;
        int len;
        char c;
        const char *value;

        if (0 > (len = m_name.Clear()))
            return error;

        while (0 < (len = input.Read((BYTE*)&c, sizeof(c))))
        {
            if (0 < endchar)
            if (endchar == c)
                break;

            if (0 >= (len = m_name.Write(&c, sizeof(c))))
                break;
        }

        if ((value = m_name.GetBuffer(len)))
        if (0 < len)
        {
            this->SetValue(value);
            error = e_ERROR_NONE;
        }

        return error;
    }

    /**
     **********************************************************************
     * Function: GetNameOf
     *
     *   Author: $author$
     *     Date: 5/24/2014
     **********************************************************************
     */
    static const char* GetNameOf(int of) {
        const char** names;
        if ((e_FIRST <= of) && (e_LAST >= of) && (names = GetNames()))
            return names[of - e_FIRST];
        return "";
    }
    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 10/22/2004
     **********************************************************************
     */
    static const char **GetNames()
    {
        static const char *names[e_NEXT]=
        {
            "",
            "GET",
            "PUT",
            "POST",
            "DELETE",
            "TRACE",
            "OPTIONS",
            "HEAD",
        };

        return names;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderMethod
 *
 * Author: $author$
 *   Date: 10/22/2004
 **********************************************************************
 */
class cHttpRequestHeaderMethod
: public cHttpRequestHeaderMethodT<cHttpRequestHeaderMethod>
{
public:
    typedef cHttpRequestHeaderMethodT<cHttpRequestHeaderMethod> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderMethod
     *
     *      Author: $author$
     *        Date: 10/22/2004
     **********************************************************************
     */
    cHttpRequestHeaderMethod(int value=e_METHOD_GET) 
    : cIs(value) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderPathT
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cHttpRequestHeaderPathT
{
public:

    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderPathT
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttpRequestHeaderPathT
    (const char* chars=0,  int length=-1) 
    {
        if (chars)
        if (0 > (length = SetChars(chars, length)))
            throw(-length);
    }

    /**
     **********************************************************************
     * Function: SetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetChars
    (const char* chars=0,  int length=-1) 
    {
        int count = m_buffer.Copy(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual const char* GetChars(int &length) const
    {
        const char* chars = m_buffer.GetBuffer(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/22/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface& input, int endchar=' ') 
    {
        eError error = e_ERROR_FAILED;
        int len;
        char c;
        const char *value;

        if (0 > (len = m_buffer.Clear()))
            return error;

        while (0 < (len = input.Read((BYTE*)&c, sizeof(c))))
        {
            if (0 < endchar)
            if (endchar == c)
                break;

            if (0 >= (len = m_buffer.Write(&c, sizeof(c))))
                break;
        }

        if ((value = m_buffer.GetBuffer(len)))
        if (0 < len)
            error = e_ERROR_NONE;

        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderPath
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cHttpRequestHeaderPath
: public cHttpRequestHeaderPathT<>
{
public:
    typedef cHttpRequestHeaderPathT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderPath
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttpRequestHeaderPath
    (const char* chars=0,  int length=-1) 
    : cIs(chars, length) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeaderT
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cHttpRequestHeaderT
: public TIs
{
public:
    typedef TIs cIs;

    cHttpRequestHeaderMethod m_method;
    cHttpRequestHeaderPath m_path;
    cHttpHeaderVersion m_version;

    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeaderT
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttpRequestHeaderT() 
    {
    }
    /**
     **********************************************************************
     * Function: Deserialize
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError Deserialize
    (cInputStreamInterface &input, int endchar=-1) 
    {
        eError error = e_ERROR_FAILED;
        bool in_space = false;
        bool in_value = false;
        bool new_line = false;
        char c;
        int len, namelen, valuelen;
        const char *chars,*name,*value;
        cCharBuffer name_buffer;
        cCharBuffer value_buffer;
        cCharBufferInputStream buffer_input(m_buffer);

        if (0 > (len = m_buffer.Clear()))
            return error = -len;

        while (0 < (len = input.Read((BYTE*)&c, sizeof(c))))
        {
            if (0 > (len = m_buffer.Write(&c, sizeof(c))))
                return error = -len;

            if (0 < endchar)
            if (endchar == c)
                break;

            if ('\n' == c)
            {
                if (new_line)
                    break;
                new_line = true;
            }
            else if ('\r' != c)
                    new_line = false;
        }

        if (0 > (len = m_buffer.Seek(0)))
            return error = -len;

        if (!(error = m_method.Deserialize(buffer_input, ' ')))
        if (!(error = OnMethod(m_method)))
        if (!(error = m_path.Deserialize(buffer_input, ' ')))
        if (!(error = OnPath(m_path)))
        if (!(error = m_version.Deserialize(buffer_input, '\n')))
        if (!(error = OnVersion(m_version)))
        {
            while (0 < (len = buffer_input.Read
                   ((BYTE*)&c, sizeof(c))))
            {
                if (0 < endchar)
                if (endchar == c)
                    break;

                switch(c)
                {
                case ':':
                    if (in_value)
                    {
                        if (0 > (c = value_buffer.Putc(c)))
                            return e_ERROR_FAILED;
                    }
                    else if (0 > (len = value_buffer.Clear()))
                            return e_ERROR_FAILED;
                    else 
                    {
                        in_space=true;
                        in_value=true;
                    }
                    break;

                case ' ':
                    if (in_value)
                    {
                        if (in_space)
                            in_space=false;

                        else if (0 > (c = value_buffer.Putc(c)))
                                return e_ERROR_FAILED;
                    }
                    else if (0 > (c = name_buffer.Putc(c)))
                            return e_ERROR_FAILED;
                    break;

                case '\r':
                    break;

                case '\n':
                    if (in_value)
                    {
                        if (!(name = name_buffer.GetBuffer(namelen)))
                            return e_ERROR_FAILED;

                        if (!(value = value_buffer.GetBuffer(valuelen)))
                            return e_ERROR_FAILED;

                        if ((error = OnField
                            (name, namelen, value, valuelen)))
                            return error;
                    }
                    else if (1 > (len = name_buffer.GetLength()))
                    {
                        chars = GetChars(len);
                        error = OnEnd(chars, len);
                        return error;
                    }

                    if (0 > (len = name_buffer.Clear()))
                       return e_ERROR_FAILED;

                    in_space=false;
                    in_value=false;
                    break;

                default:
                    if (in_value)
                    {
                        if (in_space)
                            in_space=false;

                        if (0 > (c = value_buffer.Putc(c)))
                            return e_ERROR_FAILED;
                    }
                    else if (0 > (c = name_buffer.Putc(c)))
                            return e_ERROR_FAILED;
                }
            }
        }
        return error;
    }
    
    /**
     **********************************************************************
     * Function: OnMethod
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnMethod
    (cHttpRequestHeaderMethod &method) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnPath
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnPath
    (cHttpRequestHeaderPath &path) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnVersion
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnVersion
    (cHttpHeaderVersion &version) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnCloseConnectionField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnCloseConnectionField() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnKeepAliveConnectionField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnKeepAliveConnectionField() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnConnectionField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnConnectionField
    (const char *value=0, int valuelen=-1) 
    {
        cHttpHeaderConnectionFieldType field_type;
        int type = field_type.SetValueByNamed(value);
        eError error = e_ERROR_NONE;

        switch(type)
        {
        case cHttpHeaderConnectionFieldType
             ::e_CONNECTION_CLOSE:
            error = OnCloseConnectionField();
            break;

        case cHttpHeaderConnectionFieldType
             ::e_CONNECTION_KEEP_ALIVE:
            error = OnKeepAliveConnectionField();
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnContentTypeField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnContentTypeField
    (const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnContentLengthField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnContentLengthField
    (const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnChunkedTransferEncodingField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnChunkedTransferEncodingField()
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnTransferEncodingField
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnTransferEncodingField
    (const char *value=0, int valuelen=-1) 
    {
        cHttpHeaderTransferEncodingFieldType field_type;
        int type = field_type.SetValueByNamed(value);
        eError error = e_ERROR_NONE;

        switch(type)
        {
        case cHttpHeaderTransferEncodingFieldType
             ::e_TRANSFER_ENCODING_CHUNKED:
            error = OnChunkedTransferEncodingField();
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnFieldType
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError OnFieldType
    (int type, const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;

        switch(type)
        {
        case cHttpHeaderFieldType::e_FIELD_CONNECTION:
            error = OnConnectionField(value, valuelen);
            break;

        case cHttpHeaderFieldType::e_FIELD_CONTENT_TYPE:
            error = OnContentTypeField(value, valuelen);
            break;

        case cHttpHeaderFieldType::e_FIELD_CONTENT_LENGTH:
            error = OnContentLengthField(value, valuelen);
            break;

        case cHttpHeaderFieldType::e_FIELD_TRANSFER_ENCODING:
            error = OnTransferEncodingField(value, valuelen);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnField
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnField
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        cHttpHeaderFieldType field_type;
        int type = field_type.SetValueByNamed(name);
        eError error = OnFieldType(type, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnEnd
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError OnEnd(const char *chars, int length) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: GetChars
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual const char* GetChars(int &length) const
    {
        const char* chars = m_buffer.GetBuffer(length);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cHttpRequestHeader
 *
 * Author: $author$
 *   Date: 10/24/2004
 **********************************************************************
 */
class cHttpRequestHeader
: public cHttpRequestHeaderT<>
{
public:
    typedef cHttpRequestHeaderT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeader
     *
     *      Author: $author$
     *        Date: 10/24/2004
     **********************************************************************
     */
    cHttpRequestHeader() 
    {
    }
};

typedef int eHttpResponseHeaderStatus;

/**
 **********************************************************************
 *  Class: cHttpResponseHeaderStatusT
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
template 
<class TAs, class TIs=cIntValuedEnumValueT<int, TAs> >

class cHttpResponseHeaderStatusT
: public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 10/27/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST,
        e_NONE = e_FIRST,

        e_STATUS_OK,
        e_STATUS_BAD_REQUEST,
        e_STATUS_FILE_NOT_FOUND,
        e_STATUS_INTERNAL_SERVER_ERROR,
        e_STATUS_SERVICE_UNAVAILABLE,

        e_NEXT,
        e_LAST=e_NEXT-1,
        e_STATUS_ERROR = e_STATUS_INTERNAL_SERVER_ERROR
    };

    /**
     **********************************************************************
     * Constructor: cHttpResponseHeaderStatusT
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpResponseHeaderStatusT(int value=e_NONE)
    : cIs(value)
    {
    }
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output,
     const BYTE *endchars=0, int endchars_length=-1) const
    {
        const char **names,*name = 0;
        int count, length, valued = this->GetValued();
        cHttpHeaderIntSerializer serializer(valued);

        if ((names = GetNames()))
        if ((this->m_value >= e_NONE) && (this->m_value < e_NEXT))
        if ((name = names[this->m_value]))
        if (!name[0])
            name = 0;

        if (name)
        {
            if (0 < (length = serializer
                .Serialize(output, (const BYTE*)" ")))

            if (0 < (count = output.Write
                ((const BYTE*)name)))
            {
                count += length;

                if (endchars)
                {
                    if (0 < (length = output.Write
                        ((const BYTE*)endchars, 
                         endchars_length)))
                        length += count;
                }
                else length = count;
            }
        }
        else length = serializer.Serialize
             (output, endchars, endchars_length);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetValueNone
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    static int GetValueNone()
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetValues
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    static const int* GetValues()
    {
        static const int values[e_NEXT]=
        {
            0,
            200,
            400,
            404,
            500,
            503
        };
        return values;
    }
    /**
     **********************************************************************
     * Function: GetNames
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    static const char** GetNames() 
    {
        static const char* names[e_NEXT] = 
        {
            "",
            "OK",
            "Bad Request",
            "File Not Found",
            "Internal Server Error",
            "Service Unavailable"
        };
        return names;
    }
};

/**
 **********************************************************************
 *  Class: cHttpResponseHeaderStatus
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
class cHttpResponseHeaderStatus
: public cHttpResponseHeaderStatusT<cHttpResponseHeaderStatus>
{
public:
    typedef cHttpResponseHeaderStatusT<cHttpResponseHeaderStatus> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpResponseHeaderStatus
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpResponseHeaderStatus(int value=e_NONE)
    : cIs(value)
    {
    }
};

/**
 **********************************************************************
 *  Class: cHttpResponseHeaderT
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
template <class TIs=cBase>
class cHttpResponseHeaderT
: public TIs
{
public:
    typedef TIs cIs;

    cHttpHeaderVersion m_version;
    cHttpResponseHeaderStatus m_status;
    cHttpHeaderFieldList m_field_list;
    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cHttpResponseHeaderT
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpResponseHeaderT
    (int status=cHttpResponseHeaderStatus::e_STATUS_ERROR, 
     int version_major=1, int version_minor=1)
    : m_version(version_major, version_minor),
      m_status(status)
    {
    }
    /**
     **********************************************************************
     * Function: Serialize
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int Serialize
    (cOutputStreamInterface& output,
     const BYTE *endchars=0, int endchars_length=-1) const
    {
        int count, length;
        cHttpHeaderField *field;

        if (0 < (count = (length = m_version
            .Serialize(output, (const BYTE*)" "))))
        if (0 < (length = m_status
            .Serialize(output, (const BYTE*)"\r\n")))
        {
            count += length;

            for (field=m_field_list.GetFirst(); 
                 field; field=field->GetNext())
            {
                if (0 > (length = field->Serialize
                    (output, (const BYTE*)"\r\n")))
                    return length;

                count += length;
            }

            if (0 < (length = output.Write
                ((const BYTE*)"\r\n")))
                length += count;
        }
        return length;
    }

    /**
     **********************************************************************
     * Function: AddContentTypeField
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError AddContentTypeField
    (const char *value=0, int valuelen=-1) 
    {
        int type = cHttpHeaderFieldType::e_FIELD_CONTENT_TYPE;
        const char *name = cHttpHeaderFieldType::GetName(type);
        int namelen = -1;
        eError error = AddField(name, namelen, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddContentLengthField
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual eError AddContentLengthField(int length) 
    {
        eError error = e_ERROR_NONE;
        int type = cHttpHeaderFieldType::e_FIELD_CONTENT_LENGTH;
        const char *name = cHttpHeaderFieldType::GetName(type);
        int namelen = -1;
        const char *value = "";
        int valuelen = 0;
        cCharBufferOutputStream output(m_buffer);
        cHttpHeaderIntSerializer serializer(length);

        if (0 <= (valuelen = m_buffer.Clear()))
        if (0 < (valuelen = serializer.Serialize(output)))
        if ((value = m_buffer.GetBuffer(valuelen)))
            error = AddField
            (name, namelen, value, valuelen);

        return error;
    }
    /**
     **********************************************************************
     * Function: AddTransferEncodingChunkedField
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError AddTransferEncodingChunkedField() 
    {
        int type = cHttpHeaderFieldType::e_FIELD_TRANSFER_ENCODING;
        const char *name = cHttpHeaderFieldType::GetName(type);
        int namelen = -1;
        int value_type = cHttpHeaderTransferEncodingFieldType::e_TRANSFER_ENCODING_CHUNKED;
        const char *value = cHttpHeaderTransferEncodingFieldType::GetName(value_type);
        int valuelen = -1;
        eError error = AddField(name, namelen, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddConnectionKeepAliveField
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError AddConnectionKeepAliveField() 
    {
        int type = cHttpHeaderFieldType::e_FIELD_CONNECTION;
        const char *name = cHttpHeaderFieldType::GetName(type);
        int namelen = -1;
        int value_type = cHttpHeaderConnectionFieldType::e_CONNECTION_KEEP_ALIVE;
        const char *value = cHttpHeaderConnectionFieldType::GetName(value_type);
        int valuelen = -1;
        eError error = AddField(name, namelen, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddConnectionCloseField
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError AddConnectionCloseField() 
    {
        int type = cHttpHeaderFieldType::e_FIELD_CONNECTION;
        const char *name = cHttpHeaderFieldType::GetName(type);
        int namelen = -1;
        int value_type = cHttpHeaderConnectionFieldType::e_CONNECTION_CLOSE;
        const char *value = cHttpHeaderConnectionFieldType::GetName(value_type);
        int valuelen = -1;
        eError error = AddField(name, namelen, value, valuelen);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddField
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError AddField
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_NONE;
        cHttpHeaderField *field;

        if (!(field = new cHttpHeaderField
            (name, namelen, value, valuelen)))
            return e_ERROR_NEW;

        m_field_list.Add(field);
        return error;
    }
    /**
     **********************************************************************
     * Function: ClearFields
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eError ClearFields() 
    {
        eError error = m_field_list.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: SetStatus
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int SetStatus(int status) 
    {
        status = m_status.SetValue(status);
        return status;
    }
    /**
     **********************************************************************
     * Function: GetStatus
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual int GetStatus() const
    {
        int status = m_status.GetValue();
        return status;
    }
};

/**
 **********************************************************************
 *  Class: cHttpResponseHeader
 *
 * Author: $author$
 *   Date: 10/27/2004
 **********************************************************************
 */
class cHttpResponseHeader
: public cHttpResponseHeaderT<>
{
public:
    typedef cHttpResponseHeaderT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpResponseHeader
     *
     *      Author: $author$
     *        Date: 10/27/2004
     **********************************************************************
     */
    cHttpResponseHeader
    (int status=cHttpResponseHeaderStatus::e_STATUS_ERROR, 
     int version_major=1, int version_minor=1)
    : cIs(status, version_major, version_minor)
    {
    }
};

#endif /* ndef _CHTTP11HEADER_HXX */
