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
 *   File: chttp.hxx
 *
 * Author: $author$
 *   Date: 3/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP_HXX
#define _CHTTP_HXX

#include <stdio.h>
#include <stdlib.h>

#include "clistt.hxx"
#include "cvaluedenumt.hxx"
#include "cnamedenumt.hxx"
#include "ccharbuffer.hxx"
#include "cerror.hxx"

/**
 **********************************************************************
 *  Class: cHTTPChunkedContent
 *
 * Author: $author$
 *   Date: 3/14/2004
 **********************************************************************
 */
class cHTTPChunkedContent
: public cCharStreamStream
{
public:
    typedef cCharStreamStream cIs;

    int m_chunk_size,m_chunk_remain;

    /**
     **********************************************************************
     * Constructor: cHTTPChunkedContent
     *
     *      Author: $author$
     *        Date: 3/14/2004
     **********************************************************************
     */
    cHTTPChunkedContent(cCharStream &stream) 
    : cIs(stream),
      m_chunk_size(-1),
      m_chunk_remain(-1)
    {
    }

    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int Read(char *buffer, int size)
    {
        int count,length=0;

        if (0 > m_chunk_remain)
        {
            if (0 > (count = ReadChunkBegin()))
                return count;
        }
        else if (0 == m_chunk_remain)
        {
            if (0 > (count = ReadChunkEnd()))
                return count;

            if (0 > (count = ReadChunkBegin()))
                return count;
        }

        length = ReadChunkRemain(buffer, size);
        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkRemain
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int ReadChunkRemain(char *buffer, int size)
    {
        int count,remain,length=0;

        do
        {
            if ((remain = (size > m_chunk_remain)))
            {
                remain = size-m_chunk_remain;
                size = m_chunk_remain;
            }

            if (0 > (count = m_stream.Read(buffer, size)))
                return count;

            m_chunk_remain -= count;
            length += count;
            buffer += count;

            if (remain)
            {
                if (0 > (count = ReadChunkBegin()))
                    return count;

                size = remain;
            }
        }
        while (remain);

        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkBegin
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int ReadChunkBegin()
    {
        int c,length=0;

        m_chunk_size=0;
        m_chunk_remain=-1;

        do
        {
            if (0 > (c = m_stream.Getc()))
                return c;

            if (('0' <= c) && ('9' >= c))
                m_chunk_size = (m_chunk_size<<4)+(c-'0');

            else if (('A' <= c) && ('F' >= c))
                    m_chunk_size = (m_chunk_size<<4)+(c-'A')+10;

            else if (('a' <= c) && ('f' >= c))
                    m_chunk_size = (m_chunk_size<<4)+(c-'a')+10;

            else if ('\n' == c)
            {
                m_chunk_remain = m_chunk_size;
                break;
            }

            else continue;

            length++;
        }
        while (0 <= c);

        return length;
    }
    /**
     **********************************************************************
     * Function: ReadChunkEnd
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual int ReadChunkEnd()
    {
        int c,length=0;

        do
        {
            if (0 > (c = m_stream.Getc()))
                return c;

            if ('0' == c)
                length++;

            else if ('\n' == c)
            {
                if (0 < length)
                    break;
            }
        }
        while (0 <= c);

        return length;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPVersion
 *
 * Author: $author$
 *   Date: 3/8/2004
 **********************************************************************
 */
class cHTTPVersion
{
public:
    int m_major,m_minor;
    cCharBuffer m_buffer;

    /**
     **********************************************************************
     * Constructor: cHTTPVersion
     *
     *      Author: $author$
     *        Date: 3/8/2004
     **********************************************************************
     */
    cHTTPVersion(int major=1,int minor=1)
    : m_major(major),
      m_minor(minor) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cHTTPVersion
     *
     *      Author: $author$
     *        Date: 3/8/2004
     **********************************************************************
     */
    cHTTPVersion(cHTTPVersion &version)
    : m_major(version.m_major),
      m_minor(version.m_minor) 
    {
    }

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual int Put(cCharStream &stream) const
    {
        int count,length;

        if (0 < (count = (length=stream.Write("HTTP/"))))
        if (0 < (length=stream.WriteInt(m_major)))
        {
            count+=length;
            if (0 < (length=stream.Write(".")))
            {
                count+=length;
                if (0 < (length=stream.WriteInt(m_minor)))
                    length+=count;
            }
        }
        return length;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual int Get
    (cCharStream &stream, char endc=' ', int skipc=-1)
    {
        int length;

        length = m_buffer.CopyStreamEndc(stream, endc, skipc);

        return length;
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    const char *GetBuffer(int &length) const
    {
        return m_buffer.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetDefault
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    static cHTTPVersion &GetDefault()
    {
        static cHTTPVersion default_version;

        return default_version;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPHeader
 *
 * Author: $author$
 *   Date: 3/8/2004
 **********************************************************************
 */
class cHTTPHeader
{
public:
    /**
     **********************************************************************
     *  Class: cField
     *
     * Author: $author$
     *   Date: 3/8/2004
     **********************************************************************
     */
    class cField
    : public cDynamicListItemT<cField>
    {
    public:
        typedef cDynamicListItemT<cField> cIs;

        /**
         **********************************************************************
         *  Class: cType
         *
         * Author: $author$
         *   Date: 3/8/2004
         **********************************************************************
         */
        class cType
        : public cCharNamedEnumT<int, cType>
        {
        public:
            /**
             **********************************************************************
             *   Enum: 
             *
             * Author: $author$
             *   Date: 3/8/2004
             **********************************************************************
             */
            enum
            {
                e_NONE,
                e_CONNECTION,
                e_CONTENT_TYPE,
                e_CONTENT_LENGTH,
                e_FROM,
                e_HOST,
                e_ACCEPT,
                e_TRANSFER_ENCODING,
                e_QUERY_STRING,
                e_NEXT,
                e_FIRST = e_NONE,
                e_LAST = e_NEXT-1,
            };

            /**
             **********************************************************************
             *  Class: cConnection
             *
             * Author: $author$
             *   Date: 3/12/2004
             **********************************************************************
             */
            class cConnection
            : public cCharNamedEnumT<int, cConnection>
            {
            public:
                /**
                 **********************************************************************
                 *   Enum: 
                 *
                 * Author: $author$
                 *   Date: 3/12/2004
                 **********************************************************************
                 */
                enum
                {
                    e_FIRST,
                    e_NONE = e_FIRST,
                    e_KEEP_ALIVE,
                    e_CLOSE,
                    e_HOST,
                    e_NEXT,
                    e_LAST = e_NEXT-1
                };

                /**
                 **********************************************************************
                 * Function: GetNames
                 *
                 *   Author: $author$
                 *     Date: 3/12/2004
                 **********************************************************************
                 */
                static const char **GetNames()
                {
                    static const char *names[e_NEXT]={
                        "",
                        "Keep-Alive",
                        "close",
                        "Host"
                    };
                    return names;
                }
                /**
                 **********************************************************************
                 * Function: GetName
                 *
                 *   Author: $author$
                 *     Date: 6/16/2004
                 **********************************************************************
                 */
                static const char *GetName(int type)
                {
                    const char **names,*name=0;

                    if ((names = GetNames()))
                    if ((type >= e_FIRST) && (type <= e_LAST))
                        name = names[type-e_FIRST];

                    return name;
                }
            };

            /**
             **********************************************************************
             *  Class: cTransferEncoding
             *
             * Author: $author$
             *   Date: 3/13/2004
             **********************************************************************
             */
            class cTransferEncoding
            : public cCharNamedEnumValueT<int, cTransferEncoding>
            {
            public:
                typedef cCharNamedEnumValueT<int, cTransferEncoding> cIs;

                /**
                 **********************************************************************
                 *   Enum: 
                 *
                 * Author: $author$
                 *   Date: 3/13/2004
                 **********************************************************************
                 */
                enum
                {
                    e_FIRST,
                    e_NONE = e_FIRST,
                    e_CHUNKED,
                    e_NEXT,
                    e_LAST = e_NEXT-1
                };

                /**
                 **********************************************************************
                 * Constructor: cTransferEncoding
                 *
                 *      Author: $author$
                 *        Date: 3/14/2004
                 **********************************************************************
                 */
                cTransferEncoding(int value=e_NONE)
                : cIs(value) 
                {
                }
                /**
                 **********************************************************************
                 * Function: GetNames
                 *
                 *   Author: $author$
                 *     Date: 3/13/2004
                 **********************************************************************
                 */
                static const char **GetNames()
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
             * Function: GetNames
             *
             *   Author: $author$
             *     Date: 3/8/2004
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

        int m_type;
        cCharBuffer m_name;
        cCharBuffer m_value;

        /**
         **********************************************************************
         * Constructor: cField
         *
         *      Author: $author$
         *        Date: 3/8/2004
         **********************************************************************
         */
        cField(int type=cType::e_NONE, const char *value=0)
        : m_type(type) 
        {
            const char *name;
            int length;
            eError error;

            if (cType::e_NONE != type)
            if ((name = cType::GetName(type)))
            if (0 > (length = m_name.Write(name)))
                throw(error=-length);

            if (value)
            if (0 > (length=m_value.Write(value)))
                throw(error=-length);
        }
        /**
         **********************************************************************
         * Constructor: cField
         *
         *      Author: $author$
         *        Date: 3/8/2004
         **********************************************************************
         */
        cField(const char *name, const char *value=0)
        : m_type(cType::e_NONE) 
        {
            int length;
            eError error;

            if (0 > (length=m_name.Write(name)))
                throw(error=-length);

            if (value)
            if (0 > (length=m_value.Write(value)))
                throw(error=-length);
        }
        /**
         **********************************************************************
         * Constructor: cField
         *
         *      Author: $author$
         *        Date: 3/8/2004
         **********************************************************************
         */
        cField(int type, const char *name, const char *value)
        : m_type(type) 
        {
            int length;
            eError error;

            if (0 > (length=m_name.Write(name)))
                throw(error=-length);

            if (value)
            if (0 > (length=m_value.Write(value)))
                throw(error=-length);
        }
        /**
         **********************************************************************
         * Constructor: cField
         *
         *      Author: $author$
         *        Date: 3/12/2004
         **********************************************************************
         */
        cField(int type, int value_type)
        : m_type(type) 
        {
            const char *name;
            int length;
            eError error;

            if (cType::e_NONE != type)
            if ((name = cType::GetName(type)))
            if (0 > (length = m_name.Write(name)))
                throw(error=-length);

            if (0 > (value_type = SetValueType(value_type)))
                throw(error=-value_type);
        }
        /**
         **********************************************************************
         * Constructor: cField
         *
         *      Author: $author$
         *        Date: 3/8/2004
         **********************************************************************
         */
        cField(cField &field)
        : m_type(field.m_type),
          m_name(field.m_name),
          m_value(field.m_value)
        {
        }
        /**
         **********************************************************************
         * Function: SetName
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual int SetName(const char *buff, int length=-1)
        {
            return m_name.Copy(buff, length);
        }
        /**
         **********************************************************************
         * Function: GetName
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual const char *GetName(int &length) const
        {
            return m_name.GetBuffer(length);
        }
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual int SetValue(const char *buff, int length=-1)
        {
            return m_value.Copy(buff, length);
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual const char *GetValue(int &length) const
        {
            return m_value.GetBuffer(length);
        }
        /**
         **********************************************************************
         * Function: SetType
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual int SetType(int type)
        {
            const char *name;
            int length;

            if (cType::e_NONE != type)
            if ((name = cType::GetName(type)))
            if (0 > (length = m_name.Copy(name)))
                return length;

            return m_type = type;
        }
        /**
         **********************************************************************
         * Function: GetType
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual int GetType() const
        {
            return m_type;
        }
        /**
         **********************************************************************
         * Function: SetValueType
         *
         *   Author: $author$
         *     Date: 3/12/2004
         **********************************************************************
         */
        virtual int SetValueType(int type)
        {
            const char *value;
            int length;

            switch(m_type)
            {
            case cType::e_CONNECTION:
                value = cType::cConnection::GetName(type);
                break;

            case cType::e_TRANSFER_ENCODING:
                value = cType::cTransferEncoding::GetName(type);
                break;

            default:
                return -e_ERROR_INVALID_PARAMETER;
            }

            if (value)
            if (0 > (length = m_value.Copy(value)))
                return length;

            return type;
        }
        /**
         **********************************************************************
         * Function: Put
         *
         *   Author: $author$
         *     Date: 3/8/2004
         **********************************************************************
         */
        virtual int Put(cCharStream &stream) const
        {
            int length=-e_ERROR_FAILED;
            const char *name,*value;

            if ((name = m_name.GetBuffer()))
            if ((value = m_value.GetBuffer()))
                length = stream.WriteL(name, ": ", value, "\r\n", 0);

            return length;
        }

        /**
         **********************************************************************
         * Operator: const char *
         *
         *   Author: $author$
         *     Date: 6/10/2004
         **********************************************************************
         */
        inline operator const char *() const
        {
            int length;
            return GetValue(length);
        }
    };

    /**
     **********************************************************************
     *  Class: cStaticField
     *
     * Author: $author$
     *   Date: 3/8/2004
     **********************************************************************
     */
    class cStaticField
    : public cField
    {
    public:
        typedef cField cIs;

        /**
         **********************************************************************
         * Constructor: cStaticField
         *
         *      Author: $author$
         *        Date: 3/8/2004
         **********************************************************************
         */
        cStaticField(int type=cType::e_NONE, const char *value=0)
        : cIs(type, value)
        {
            m_is_static=true;
        }
        /**
         **********************************************************************
         * Constructor: cStaticField
         *
         *      Author: $author$
         *        Date: 3/8/2004
         **********************************************************************
         */
        cStaticField(const char *name, const char *value=0)
        : cIs(name, value) 
        {
            m_is_static=true;
        }
    };

    /**
     **********************************************************************
     *  Class: cFieldList
     *
     * Author: $author$
     *   Date: 3/9/2004
     **********************************************************************
     */
    class cFieldList
    : public cDynamicListT<cField,cFieldList>
    {
    public:
        typedef cDynamicListT<cField,cFieldList> cIs;

        /**
         **********************************************************************
         * Constructor: cFieldList
         *
         *      Author: $author$
         *        Date: 3/9/2004
         **********************************************************************
         */
        cFieldList() 
        {
        }
        /**
         **********************************************************************
         * Constructor: cFieldList
         *
         *      Author: $author$
         *        Date: 3/9/2004
         **********************************************************************
         */
        cFieldList(cField *field,...) 
        {
            va_list arg;

            va_start(arg,field);

            while(field)
            {
                Add(field);
                field=va_arg(arg,cField*);
            }

            va_end(arg);
        }
    };

    cFieldList m_field_list;
    cCharBuffer m_buffer;
    cCharBuffer m_content_type;
    int m_content_length;
    cField::cType::cTransferEncoding m_transfer_encoding;

    /**
     **********************************************************************
     * Constructor: cHTTPHeader
     *
     *      Author: $author$
     *        Date: 3/8/2004
     **********************************************************************
     */
    cHTTPHeader()
    : m_content_length(-1)
    {
    }
    /**
     **********************************************************************
     * Constructor: cHTTPHeader
     *
     *      Author: $author$
     *        Date: 3/8/2004
     **********************************************************************
     */
    cHTTPHeader(cHTTPHeader &header) 
    : m_content_length(-1)
    {
        eError error;
        cField *field;
        cField *new_field;

        for (field=header.m_field_list.GetFirst(); field; field=field->GetNext())
        {
            if (!(new_field=new cField(*field)))
                throw (error=e_ERROR_FAILED);

            m_field_list.Add(new_field);
        }
    }
    /**
     **********************************************************************
     * Constructor: cHTTPHeader
     *
     *      Author: $author$
     *        Date: 3/8/2004
     **********************************************************************
     */
    cHTTPHeader(cField *field,...) 
    : m_content_length(-1)
    {
        va_list arg;

        va_start(arg,field);

        while(field)
        {
            m_field_list.Add(field);
            field=va_arg(arg,cField*);
        }

        va_end(arg);
    }
    /**
     **********************************************************************
     * Constructor: cHTTPHeader
     *
     *      Author: $author$
     *        Date: 3/8/2004
     **********************************************************************
     */
    cHTTPHeader(cFieldList &field_list) 
    : m_content_length(-1)
    {
        eError error;
        cField *field;
        cField *new_field;

        for (field=field_list.GetFirst(); field; field=field->GetNext())
        {
            if (!(new_field=new cField(*field)))
                throw (error=e_ERROR_FAILED);

            m_field_list.Add(new_field);
        }
    }

    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual int Put(cCharStream &stream) const
    {
        int count,length=0;
        cField *field;

        for (field=m_field_list.GetFirst(); field; field=field->GetNext())
        {
            if (0 > (count=field->Put(stream)))
                return -count;

            length += count;
        }

        if (0 > (count=stream.Write("\r\n")))
            return -count;

        return length+count;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual int Get(cCharStream &stream)
    {
        int c,count,length=0;
        bool newline;
        eError error;

        m_content_length = -1;
        m_content_type.Clear();

        if ((error = m_field_list.Clear()))
            return -error;

        if (0 > (count=m_buffer.Clear()))
            return -count;

        if (0 <= (c=stream.Getc()))
        {
            newline=false;
            do
            {
                length++;

                if (c=='\n')
                {
                    if (newline)
                    {
                        if (0 > (count=m_buffer.Seek(0)))
                            return count;

                        if (0 > (count=AddFields(m_buffer)))
                            return count;

                        return length;
                    }
                    newline=true;
                }
                else if (c=='\r')
                {
                    c=stream.Getc();
                    continue;
                }
                else if (newline)
                        newline=false;

                if (0 <= (c=m_buffer.Putc(c)))
                    c=stream.Getc();
            }
            while(0 <= c);
        }

        return length;
    }
    /**
     **********************************************************************
     * Function: AddFields
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual int AddFields(cCharStream &stream)
    {
        int c,count,length=0;
        bool in_space;
        bool in_value;
        eError error;
        cCharBuffer name;
        cCharBuffer value;

        in_space=false; 
        in_value=false;

        while (0 <= (c=stream.Getc()))
        {
            switch(c)
            {
            case ':':
                if (in_value)
                {
                    if (0 > (c=value.Putc(c)))
                        return c;
                }
                else if (0 > (count=value.Clear()))
                        return count;
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

                    else if (0 > (c=value.Putc(c)))
                            return c;
                }
                else if (0 > (c=name.Putc(c)))
                        return c;
                break;

            case '\n':
                if (in_value)
                {
                    if ((error=AddField
                        (name.GetBuffer(), 
                         value.GetBuffer())))
                        return -error;

                    length++;
                }

                if (0 > (count=name.Clear()))
                   return count;

                in_space=false;
                in_value=false;
                break;

            default:
                if (in_value)
                {
                    if (in_space)
                        in_space=false;

                    if (0 > (c=value.Putc(c)))
                        return c;
                }
                else if (0 > (c=name.Putc(c)))
                        return c;
            }
        }

        return length;
    }
    /**
     **********************************************************************
     * Function: OnAddField
     *
     *   Author: $author$
     *     Date: 3/14/2004
     **********************************************************************
     */
    virtual eError OnAddField
    (int type, const char *name, const char *value)
    {
        eError error=e_ERROR_NONE;

        switch(type)
        {
        case cField::cType::e_CONTENT_LENGTH:
            m_content_length=atoi(value);
            break;

        case cField::cType::e_CONTENT_TYPE:
            m_content_type.Copy(value);
            break;

        case cField::cType::e_TRANSFER_ENCODING:
            m_transfer_encoding.SetValue(value);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: AddField
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual eError AddField
    (const char *name, const char *value)
    {
        eError error=e_ERROR_NONE;
        int type;
        cField *field;

        type=cField::cType::GetType(name);

        if ((field = new cField(type, name, value)))
            m_field_list.Add(field);

        error = OnAddField(type, name, value);
        return error;
    }
    /**
     **********************************************************************
     * Function: AddField
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    virtual void AddField(cField &field)
    {
        m_field_list.Add(&field);
    }
    /**
     **********************************************************************
     * Function: DeleteField
     *
     *   Author: $author$
     *     Date: 3/12/2004
     **********************************************************************
     */
    virtual void DeleteField(cField &field)
    {
        m_field_list.Delete(&field);
    }
    /**
     **********************************************************************
     * Function: GetFirstFieldByName
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cField *GetFirstFieldByName(const char *name) const
    {
        cField *field;
        const char *field_name;
        int field_name_length;

        if ((field = m_field_list.GetFirst()))
        do
        {
            if ((field_name = field->GetName(field_name_length)))
            if (0 == strcmp(field_name, name))
                break;
        }
        while ((field = field->GetNext()));

        return field;
    }
    /**
     **********************************************************************
     * Function: GetFirstField
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cField *GetFirstField() const
    {
        return m_field_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastField
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cField *GetLastField() const
    {
        return m_field_list.GetLast();
    }
    /**
     **********************************************************************
     * Function: GetBuffer
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    const char *GetBuffer(int &length) const
    {
        return m_buffer.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    const char *GetContentType(int &length) const
    {
        return m_content_type.GetBuffer(length);
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 6/9/2004
     **********************************************************************
     */
    inline int GetContentLength() const
    {
        return m_content_length;
    }
    /**
     **********************************************************************
     * Function: GetDefault
     *
     *   Author: $author$
     *     Date: 3/8/2004
     **********************************************************************
     */
    static cHTTPHeader &GetDefault()
    {
        static cHTTPHeader default_header;

        return default_header;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPRequest
 *
 * Author: $author$
 *   Date: 3/9/2004
 **********************************************************************
 */
class cHTTPRequest
{
public:
    /**
     **********************************************************************
     *  Class: cMethod
     *
     * Author: $author$
     *   Date: 3/9/2004
     **********************************************************************
     */
    class cMethod
    : public cCharNamedEnumT<int, cMethod>
    {
    public:
        /**
         **********************************************************************
         *   Enum: 
         *
         * Author: $author$
         *   Date: 3/9/2004
         **********************************************************************
         */
        enum
        {
            e_NONE,
            e_GET,
            e_PUT,
            e_POST,
            e_DELETE,
            e_TRACE,
            e_OPTIONS,
            e_HEAD,
            e_NEXT,
            e_FIRST = e_NONE,
            e_LAST = e_NEXT-1
        };

        int m_type;
        cCharBuffer m_buffer;

        /**
         **********************************************************************
         * Constructor: cMethod
         *
         *      Author: $author$
         *        Date: 3/9/2004
         **********************************************************************
         */
        cMethod(int type=e_GET)
        : m_type(type) 
        {
        }
        /**
         **********************************************************************
         * Constructor: cMethod
         *
         *      Author: $author$
         *        Date: 3/9/2004
         **********************************************************************
         */
        cMethod(cMethod &method)
        : m_type(method.m_type) 
        {
        }

        /**
         **********************************************************************
         * Function: Put
         *
         *   Author: $author$
         *     Date: 3/9/2004
         **********************************************************************
         */
        virtual int Put(cCharStream &stream) const
        {
            int length=0;

            length = stream.Write(GetName(m_type));
            return length;
        }
        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 3/9/2004
         **********************************************************************
         */
        virtual int Get
        (cCharStream &stream, char endc=' ', int skipc=-1)
        {
            int type,length=0;
            const char *name,**names;

            if (0 > (length = m_buffer.
                CopyStreamEndc(stream, endc, skipc)))
                return length;

            m_type = e_NONE;

            if ((names = GetNames()))
            if ((name = m_buffer.GetBuffer()))
            for (type=e_NONE+1; type<e_LAST; type++)
            {
                if (0 == strcmp(name, names[type]))
                {
                    m_type = type;
                    break;
                }
            }

            return length;
        }
        /**
         **********************************************************************
         * Function: SetType
         *
         *   Author: $author$
         *     Date: 3/9/2004
         **********************************************************************
         */
        virtual int SetType(int type)
        {
            if ((type<e_FIRST) && (type>=e_NEXT))
                return -e_ERROR_FAILED;

            m_type=type;
            return m_type;
        }
        /**
         **********************************************************************
         * Function: GetType
         *
         *   Author: $author$
         *     Date: 3/9/2004
         **********************************************************************
         */
        virtual int GetType() const
        {
            return m_type;
        }
        /**
         **********************************************************************
         * Function: GetBuffer
         *
         *   Author: $author$
         *     Date: 6/15/2004
         **********************************************************************
         */
        const char *GetBuffer(int &length) const
        {
            return m_buffer.GetBuffer(length);
        }
        /**
         **********************************************************************
         * Function: GetNames
         *
         *   Author: $author$
         *     Date: 3/9/2004
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
        /**
         **********************************************************************
         * Function: GetDefault
         *
         *   Author: $author$
         *     Date: 3/9/2004
         **********************************************************************
         */
        static cMethod &GetDefault()
        {
            static cMethod default_method;

            return default_method;
        }
    };

    /**
     **********************************************************************
     *  Class: cURI
     *
     * Author: $author$
     *   Date: 3/10/2004
     **********************************************************************
     */
    class cURI
    {
    public:
        cCharBuffer m_value;

        /**
         **********************************************************************
         * Constructor: cURI
         *
         *      Author: $author$
         *        Date: 3/10/2004
         **********************************************************************
         */
        cURI(const char *value=0, int length=-1) 
        {
            eError error;

            if (value)
            if (0 > (length = m_value.Write(value, length)))
                throw(error = -length);
        }
        /**
         **********************************************************************
         * Constructor: cURI
         *
         *      Author: $author$
         *        Date: 3/10/2004
         **********************************************************************
         */
        cURI(cURI &uri)
        : m_value(uri.m_value) 
        {
        }
        /**
         **********************************************************************
         * Function: SetValue
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual int SetValue(const char *value, int length)
        {
            return m_value.Copy(value, length);
        }
        /**
         **********************************************************************
         * Function: GetValue
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual const char *GetValue(int &length) const
        {
            return m_value.GetBuffer(length);
        }
        /**
         **********************************************************************
         * Function: Put
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual int Put(cCharStream &stream) const
        {
            int length;
            const char *value;

            if ((value = m_value.GetBuffer(length)))
            if (0 <= (length = stream.Write(value, length)))
                return length;

            return -e_ERROR_FAILED;
        }
        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 6/14/2004
         **********************************************************************
         */
        virtual int Get
        (cCharStream &stream, char endc=' ', int skipc=-1)
        {
            int length;

            length = m_value.CopyStreamEndc(stream, endc, skipc);
            return length;
        }
        /**
         **********************************************************************
         * Function: GetDefault
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        static cURI &GetDefault()
        {
            static cURI default_uri;

            return default_uri;
        }
    };

    /**
     **********************************************************************
     *  Class: cLine
     *
     * Author: $author$
     *   Date: 3/10/2004
     **********************************************************************
     */
    class cLine
    {
    public:
        cMethod m_method;
        cURI m_uri;
        cHTTPVersion m_version;
        cCharBuffer m_buffer;

        /**
         **********************************************************************
         * Constructor: cLine
         *
         *      Author: $author$
         *        Date: 3/10/2004
         **********************************************************************
         */
        cLine
        (cMethod &method=cMethod::GetDefault(),
         cURI &uri=cURI::GetDefault(),
         cHTTPVersion &version=cHTTPVersion::GetDefault())
        : m_method(method),
          m_uri(uri),
          m_version(version) 
        {
        }
        /**
         **********************************************************************
         * Constructor: cLine
         *
         *      Author: $author$
         *        Date: 3/10/2004
         **********************************************************************
         */
        cLine
        (const char *uri, int uri_length=-1,
         cMethod &method=cMethod::GetDefault(),
         cHTTPVersion &version=cHTTPVersion::GetDefault())
        : m_method(method),
          m_uri(uri, uri_length),
          m_version(version) 
        {
        }
        /**
         **********************************************************************
         * Constructor: cLine
         *
         *      Author: $author$
         *        Date: 3/10/2004
         **********************************************************************
         */
        cLine(cLine &line)
        : m_method(line.m_method),
          m_uri(line.m_uri),
          m_version(line.m_version) 
        {
        }
        /**
         **********************************************************************
         * Function: SetMethod
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual int SetMethod(int type)
        {
            type = m_method.SetType(type);
            return type;
        }
        /**
         **********************************************************************
         * Function: GetMethod
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual int GetMethod() const
        {
            int type = m_method.GetType();
            return type;
        }
        /**
         **********************************************************************
         * Function: SetURI
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual int SetURI(const char *value, int length)
        {
            return m_uri.SetValue(value, length);
        }
        /**
         **********************************************************************
         * Function: GetURI
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual const char *GetURI(int &length) const
        {
            return m_uri.GetValue(length);
        }
        /**
         **********************************************************************
         * Function: Put
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        virtual int Put(cCharStream &stream) const
        {
            int count,length=0;

            if (0 > (count=m_method.Put(stream)))
                return count;

            length += count;

            if (0 > (count=stream.Putc(' ')))
                return count;

            length++;

            if (0 > (count=m_uri.Put(stream)))
                return count;

            length += count;

            if (0 > (count=stream.Putc(' ')))
                return count;

            length++;

            if (0 > (count=m_version.Put(stream)))
                return count;

            length += count;

            if (0 > (count=stream.Write("\r\n")))
                return count;

            length += count;

            return length;
        }
        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 6/13/2004
         **********************************************************************
         */
        virtual int Get
        (cCharStream &stream, char endc='\n', int skipc='\r')
        {
            int count,length;

            if (0 > (length = m_buffer.CopyStreamEndc(stream, endc, skipc)))
                return length;

            const char *buffer=m_buffer.GetBuffer(count);

            if (0 > (count = m_buffer.Seek(0)))
                return count;

            if (0 > (count = m_method.Get(m_buffer)))
                return count;

            const char *method=m_method.GetBuffer(count);
            
            if (0 > (count = m_uri.Get(m_buffer)))
                return count;

            const char *uri=m_uri.GetValue(count);

            if (0 > (count = m_version.Get(m_buffer, -1)))
                return count;

            const char *version=m_version.GetBuffer(count);

            return length;
        }
        /**
         **********************************************************************
         * Function: GetBuffer
         *
         *   Author: $author$
         *     Date: 6/16/2004
         **********************************************************************
         */
        const char *GetBuffer(int &length) const
        {
            return m_buffer.GetBuffer(length);
        }
        /**
         **********************************************************************
         * Function: GetDefault
         *
         *   Author: $author$
         *     Date: 3/10/2004
         **********************************************************************
         */
        static cLine &GetDefault()
        {
            static cLine default_line;

            return default_line;
        }
    };

    cLine m_line;
    cHTTPHeader m_header;
    cCharBuffer m_buffer;
    cCharStream *m_content;
    int m_content_length;

    /**
     **********************************************************************
     * Constructor: cHTTPRequest
     *
     *      Author: $author$
     *        Date: 3/9/2004
     **********************************************************************
     */
    cHTTPRequest
    (cLine &line=cLine::GetDefault(),
     cHTTPHeader &header=cHTTPHeader::GetDefault(),
     cCharStream *content=0,int content_length=-1)
    : m_line(line),
      m_header(header),
      m_content(0),
      m_content_length(0) 
    {
        eError error;

        if ((m_content=content))
        if (0 > (m_content_length=content_length))
        if (0 > (content_length=content->GetLength()))
            throw(error=-content_length);
    }
    /**
     **********************************************************************
     * Constructor: cHTTPRequest
     *
     *      Author: $author$
     *        Date: 3/9/2004
     **********************************************************************
     */
    cHTTPRequest
    (const char *uri, int uri_length=-1,
     cMethod &method=cMethod::GetDefault(),
     cHTTPVersion &version=cHTTPVersion::GetDefault(),
     cHTTPHeader &header=cHTTPHeader::GetDefault(),
     cCharStream *content=0,int content_length=-1)
    : m_line(uri,uri_length,method,version),
      m_header(header),
      m_content(0),
      m_content_length(0) 
    {
        eError error;

        if ((m_content=content))
        if (0 > (m_content_length=content_length))
        if (0 > (content_length=content->GetLength()))
            throw(error=-content_length);
    }
    /**
     **********************************************************************
     * Function: SetURI
     *
     *   Author: $author$
     *     Date: 3/10/2004
     **********************************************************************
     */
    virtual int SetURI(const char *value, int length=-1)
    {
        return m_line.SetURI(value, length);
    }
    /**
     **********************************************************************
     * Function: GetURI
     *
     *   Author: $author$
     *     Date: 3/10/2004
     **********************************************************************
     */
    virtual const char *GetURI(int &length) const
    {
        return m_line.GetURI(length);
    }
    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int Send(cCharStream &stream)
    {
        int count,length=0;

        if (0 > (count=m_line.Put(stream)))
            return count;

        length+=count;

        if (0 > (count=m_header.Put(stream)))
            return count;

        length+=count;

        if (m_content)
        if (0 > (count=stream.WriteStream
            (*m_content,m_content_length)))
            return count;

        length+=count;

        return length;
    }
    /**
     **********************************************************************
     * Function: Receive
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    virtual int Receive(cCharStream &stream)
    {
        int count,length;

        if (0 > (length = m_line.Get(stream)))
            return length;

        const char *line=m_line.GetBuffer(count);

        if (0 > (count = m_header.Get(stream)))
            return count;

        const char *header=m_header.GetBuffer(count);

        length += count;

        return length;
    }
    /**
     **********************************************************************
     * Function: AddField
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    void AddField(cHTTPHeader::cField &field)
    {
        m_header.AddField(field);
    }
    /**
     **********************************************************************
     * Function: DeleteField
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    void DeleteField(cHTTPHeader::cField &field)
    {
        m_header.DeleteField(field);
    }
    /**
     **********************************************************************
     * Function: GetLine
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cLine &GetLine()
    {
        return m_line;
    }
    /**
     **********************************************************************
     * Function: GetHeader
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cHTTPHeader &GetHeader()
    {
        return m_header;
    }
};

/**
 **********************************************************************
 *  Class: cHTTPResponse
 *
 * Author: $author$
 *   Date: 3/13/2004
 **********************************************************************
 */
class cHTTPResponse
: public cError
{
public:
    typedef cError cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 3/14/2004
     **********************************************************************
     */
    enum
    {
        e_FIRST_ERROR=::e_NEXT_ERROR,
        e_ERROR_RECEIVED_HTTP_ERROR=e_FIRST_ERROR,
        e_ERROR_RECEIVED_HTTP_ERROR_CONTENT,
        e_NEXT_ERROR=e_FIRST_ERROR,
        e_LAST_ERROR=e_NEXT_ERROR-1
    };

    /**
     **********************************************************************
     *  Class: cStatus
     *
     * Author: $author$
     *   Date: 3/14/2004
     **********************************************************************
     */
    class cStatus
    : public cIntValuedEnumT<int, cStatus>
    {
    public:
        typedef cIntValuedEnumT<int, cStatus> cIs;

        /**
         **********************************************************************
         *   Enum: 
         *
         * Author: $author$
         *   Date: 3/14/2004
         **********************************************************************
         */
        enum
        {
            e_FIRST,
            e_NONE = e_FIRST,
            e_OK,
            e_ERROR,
            e_NEXT,
            e_LAST=e_NEXT-1
        };

        int m_type,m_code;
        cCharBuffer m_buffer;

        /**
         **********************************************************************
         * Constructor: cStatus
         *
         *      Author: $author$
         *        Date: 3/14/2004
         **********************************************************************
         */
        cStatus(int type=e_NONE, int code=0)
        : m_type(type),
          m_code(code)
        {
        }

        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 3/14/2004
         **********************************************************************
         */
        virtual int Get
        (cCharStream &stream, char endc='\n', int skipc='\r')
        {
            int c,count,length=0;
            const char *buffer;

            m_code = 0;
            m_type = e_NONE;

            if (0 > (count = m_buffer.Clear()))
                return count;

            if (0 > (count = m_buffer.
                CopyStreamEndc(stream, endc, skipc)))
                return count;

            if (!(buffer = m_buffer.GetBuffer(length)))
                return -e_ERROR_FAILED;

            for (count=0; count<length; count++)
            {
                c = buffer[count];

                if (('0' <= c) && ('9' >= c))
                    m_code = m_code*10 + (c - '0');

                else if (' ' == c)
                {
                    m_type = GetType(m_code);
                    break;
                }
            }
            return length;
        }
        /**
         **********************************************************************
         * Function: Put
         *
         *   Author: $author$
         *     Date: 3/14/2004
         **********************************************************************
         */
        virtual int Put(cCharStream &stream)
        {
            int c,code,rcode,count,length=-e_ERROR_FAILED;

            if (0 == m_code)
            {
                if (0 >= (length = stream.Putc('0')))
                    length = 1;
            }
            else if (0 < (code = m_code))
            {
                for (length=0,rcode=0; code>0; code/=10, length++)
                    rcode = rcode * 10 + code % 10;

                for (count=0; count<length; count++, rcode/=10)
                {
                    c = '0' + (rcode % 10);

                    if (0 > (c = stream.Putc(c)))
                        return c;
                }
            }
            return length;
        }
        /**
         **********************************************************************
         * Function: GetValueNone
         *
         *   Author: $author$
         *     Date: 6/18/2004
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
         *     Date: 3/14/2004
         **********************************************************************
         */
        static int *GetValues()
        {
            static int values[e_NEXT]=
            {
                0,
                200,
                400
            };
            return values;
        }
    };

    /**
     **********************************************************************
     *  Class: cLine
     *
     * Author: $author$
     *   Date: 3/14/2004
     **********************************************************************
     */
    class cLine
    {
    public:
        cHTTPVersion m_version;
        cStatus m_status;
        cCharBuffer m_buffer;

        /**
         **********************************************************************
         * Constructor: cLine
         *
         *      Author: $author$
         *        Date: 3/14/2004
         **********************************************************************
         */
        cLine() 
        {
        }
        /**
         **********************************************************************
         * Function: Get
         *
         *   Author: $author$
         *     Date: 3/14/2004
         **********************************************************************
         */
        virtual int Get(cCharStream &stream)
        {
            int c,count,length=0;

            if (0 > (count = m_buffer.Clear()))
                return count;

            while (0 <= (c = stream.Getc()))
            {
                if ('\n' == c)
                {
                    if (0 > (count = m_buffer.Seek(0)))
                        return count;

                    if (0 > (count = m_version.Get(m_buffer, ' ')))
                        return count;

                    if (0 > (count = m_status.Get(m_buffer, -1, -1)))
                        return count;

                    break;
                }

                if ('\r' == c)
                    continue;

                if (0 > (c = m_buffer.Putc(c)))
                    return c;

                length++;
            }
            return length;
        }
        /**
         **********************************************************************
         * Function: Put
         *
         *   Author: $author$
         *     Date: 6/18/2004
         **********************************************************************
         */
        virtual int Put(cCharStream &stream)
        {
            int c,count,length=0;

            if (0 < (length = m_version.Put(stream)))

            if (0 > (c = stream.Putc(' ')))
                length = c;
            else
            {
                ++length;

                if (0 > (count = m_status.Put(stream)))
                    length = count;

                else 
                {
                    length += count;

                    if (0 > (count = stream.Write("\r\n")))
                        length = count;

                    else length += count;
                }
            }

            return length;
        }
    };

    cLine m_line;
    cHTTPHeader m_header;

    /**
     **********************************************************************
     * Constructor: cHTTPResponse
     *
     *      Author: $author$
     *        Date: 3/13/2004
     **********************************************************************
     */
    cHTTPResponse() 
    {
    }
    /**
     **********************************************************************
     * Function: Receive
     *
     *   Author: $author$
     *     Date: 3/13/2004
     **********************************************************************
     */
    virtual cCharStream *Receive
    (cCharStream &stream, cHTTPChunkedContent &chunked_content)
    {
        int type,count,length=0;
        cCharStream *content=0;

        if (0 <= (count = m_line.Get(stream)))
        {
            length += count;

            if (0 <= (count = m_header.Get(stream)))
            {
                length += count;

                if (cHTTPHeader::cField::cType::cTransferEncoding::e_CHUNKED
                    == (type = m_header.m_transfer_encoding.GetValue()))
                    content = &chunked_content;

                else content = &stream;
            }
        }
        return content;
    }
    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    virtual int Send(cCharStream &stream)
    {
        int count,length=0;

        if (0 < (length = (count = m_line.Put(stream))))
        if (0 < (length = m_header.Put(stream)))
            length += count;

        return length;
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 6/18/2004
     **********************************************************************
     */
    int GetContentLength() const
    {
        return m_header.GetContentLength();
    }
    /**
     **********************************************************************
     * Function: GetLine
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cLine &GetLine()
    {
        return m_line;
    }
    /**
     **********************************************************************
     * Function: GetHeader
     *
     *   Author: $author$
     *     Date: 6/16/2004
     **********************************************************************
     */
    cHTTPHeader &GetHeader()
    {
        return m_header;
    }
};

#endif /* ndef _CHTTP_HXX */
