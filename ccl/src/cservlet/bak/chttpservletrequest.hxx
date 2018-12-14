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
 *   File: chttpservletrequest.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETREQUEST_HXX
#define _CHTTPSERVLETREQUEST_HXX

#include "curlencodedformdataparser.hxx"
#include "cbytestring.hxx"
#include "ccharstring.hxx"
#include "chttpservletheader.hxx"
#include "chttpservletinterface.hxx"
#include "chttpservletrequestinterface.hxx"
#include "chttprequestinterface.hxx"
#include "cconnectioninterface.hxx"
#include "cservletrequest.hxx"
#include "ccharreader.hxx"
#include "cinputstream.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cServletURLEncodedFormDataParser
 *
 * Author: $author$
 *   Date: 11/19/2004
 **********************************************************************
 */
class cServletURLEncodedFormDataParser
: public cURLEncodedFormDataParser
{
public:
    typedef cURLEncodedFormDataParser cIs;

    cHttpRequestInterface &m_request;

    /**
     **********************************************************************
     * Constructor: cServletURLEncodedFormDataParser
     *
     *      Author: $author$
     *        Date: 11/19/2004
     **********************************************************************
     */
    cServletURLEncodedFormDataParser
    (cHttpRequestInterface &request) 
    : m_request(request) 
    {
    }
    /**
     **********************************************************************
     * Function: OnFormField
     *
     *   Author: $author$
     *     Date: 11/19/2004
     **********************************************************************
     */
    virtual eError OnFormField
    (const char *name, int namelen=-1, 
     const char *value="", int valuelen=-1) 
    {
        eError result = e_ERROR_NONE;

        if (name && (namelen != 0))
            m_request.SetParameter
            (name, namelen, value, valuelen);

        return result;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletRequestT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template 
<class THttpRequestInterfaceIs=cHttpRequestInterface,
 class THttpServletRequestInterfaceIs=cHttpServletRequestInterface,
 class TIs=cServletRequest>

class cHttpServletRequestT
: virtual public THttpRequestInterfaceIs,
  virtual public THttpServletRequestInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cConnectionInterface &m_connection;

    cBYTEString m_header_bytes;

    int m_method;

    cCharString m_path_info;

    int m_content_length;
    cCharString m_content_type;
    bool m_is_chunked_content;

    int m_server_port;
    cCharString m_server_name;

    cHttpServletHeaderList m_header_list;

    cCharReaderInterface *m_reader;
    cCharReader m_null_reader;

    cInputStreamInterface *m_input;
    cInputStream m_null_input;

    cServletURLEncodedFormDataParser 
        m_urlencoded_form_data_parser;

    /**
     **********************************************************************
     * Constructor: cHttpServletRequestT
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cHttpServletRequestT
    (cConnectionInterface &connection,
     cCharReaderInterface *reader=0,
     cInputStreamInterface *input=0)
    : m_urlencoded_form_data_parser(*this),
      m_connection(connection),
      m_reader(reader),
      m_input(input),
      m_method(0),
      m_content_length(0),
      m_is_chunked_content(false),
      m_server_port(0)
    {
    }

    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual int SetContentType
    (const char *buf,  int len=-1)
    {
        int count = m_content_type.SetChars(buf, len);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual const char* GetContentType(int &length) const
    {
        const char* chars = m_content_type.GetChars(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual int SetContentLength(int length=-1)
    {
        m_content_length = length;
        return m_content_length;
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int GetContentLength() const
    {
        return m_content_length;
    }

    /**
     **********************************************************************
     * Function: SetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual bool SetIsChunkedContent(bool is=true) 
    {
        m_is_chunked_content = is;
        return m_is_chunked_content;
    }
    /**
     **********************************************************************
     * Function: IsChunkedContent
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual bool IsChunkedContent() const
    {
        return m_is_chunked_content;
    }

    /**
     **********************************************************************
     * Function: SetMethod
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetMethod(int method) 
    {
        m_method = method;
        return m_method;
    }
    /**
     **********************************************************************
     * Function: GetMethod
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int GetMethod() const
    {
        return m_method;
    }

    /**
     **********************************************************************
     * Function: SetPathInfo
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual int SetPathInfo
    (const char* buf,  int len=-1) 
    {
        int count = m_path_info.SetChars(buf, len);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetPathInfo
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual const char* GetPathInfo(int &length) const
    {
        const char* chars = m_path_info.GetChars(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetServerName
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int SetServerName
    (const char* chars, int length=-1) 
    {
        int count = m_server_name.SetChars(chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: SetServerPort
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual int SetServerPort(int port) 
    {
        m_server_port = port;
        return m_server_port;
    }

    /**
     **********************************************************************
     * Function: ClearHeaders
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError ClearHeaders() 
    {
        eError error = m_header_list.Clear();
        m_header_bytes.ClearBytes();
        m_method = 0;
        m_path_info.ClearChars();
        m_content_length = 0;
        m_content_type.ClearChars();
        m_is_chunked_content = false;
        m_server_port = 0;
        m_server_name.ClearChars();
        SetIsConsumed(false);
        cIs::Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: AddHeader
     *
     *   Author: $author$
     *     Date: 10/24/2004
     **********************************************************************
     */
    virtual eError AddHeader
    (const char *name,  int namelen=-1,
     const char *value=0, int valuelen=-1) 
    {
        eError error = e_ERROR_FAILED;
        cHttpServletHeader *header;

        if (!name)
            return e_ERROR_INVALID_PARAMETER;

        if ((header = new cHttpServletHeader
            (name, namelen, value, valuelen)))
        {
            error = e_ERROR_NONE;
            m_header_list.Add(header);
        }

        return error;
    }
    /**
     **********************************************************************
     * Function: GetHeader
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual const char* GetHeader
    (int &valuelen, const char *name, int namelen=-1) const
    {
        const char* value = 0;
        valuelen = 0;
        return value;
    }
    /**
     **********************************************************************
     * Function: GetHeaderByType
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual const char* GetHeaderByType
    (int &valuelen, int type) const
    {
        const char* value = 0;
        valuelen = 0;
        return value;
    }

    /**
     **********************************************************************
     * Function: SetHeaderChars
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual int SetHeaderChars
    (const char* chars, int length=-1) 
    {
        int count = m_header_bytes
        .SetBytes((const BYTE*)chars, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetHeaderChars
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual const char* GetHeaderChars(int &length) const
    {
        const char* chars = (const char*)
         m_header_bytes.GetBytes(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetHeaderBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int SetHeaderBytes
    (const BYTE* bytes, int length=-1) 
    {
        int count = m_header_bytes
        .SetBytes(bytes, length);
        return count;
    }
    /**
     **********************************************************************
     * Function: GetHeaderBytes
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual const BYTE* GetHeaderBytes(int &length) const
    {
        const BYTE* bytes = m_header_bytes.GetBytes(length);
        return bytes;
    }

    /**
     **********************************************************************
     * Function: SetReader
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cCharReaderInterface& SetReader
    (cCharReaderInterface *reader) 
    {
        if ((m_reader = reader))
            return *m_reader;
        return m_null_reader;
    }
    /**
     **********************************************************************
     * Function: GetReader
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cCharReaderInterface& GetReader() 
    {
        if (m_reader)
            return *m_reader;
        return m_null_reader;
    }

    /**
     **********************************************************************
     * Function: SetInputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cInputStreamInterface& SetInputStream
    (cInputStreamInterface *input) 
    {
        if ((m_input = input))
            return *m_input;
        return m_null_input;
    }
    /**
     **********************************************************************
     * Function: GetInputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cInputStreamInterface& GetInputStream() 
    {
        if (m_input)
            return *m_input;
        return m_null_input;
    }

    /**
     **********************************************************************
     * Function: GetParameter
     *
     *   Author: $author$
     *     Date: 11/18/2004
     **********************************************************************
     */
    virtual const char* GetParameter
    (int &length, const char *name, int namelen=-1)
    {
        eError error;
        const char *chars;
        int clength;
        char c;

        if (m_is_unconsumed)
        if ((chars = GetContentType(clength)))
        if (!strcmp("application/x-www-form-urlencoded", chars))
        {
            cCharReaderInterface &reader = GetReader();
            m_is_unconsumed = false;

            if (!(error = m_urlencoded_form_data_parser.Initialize()))
            {
                while ((clength = reader.Read(&c, sizeof(c))) >= sizeof(c))
                    m_urlencoded_form_data_parser.Putc(c);

                m_urlencoded_form_data_parser.Finalize();
            }
        }

        chars = cIs::GetParameter(length, name, namelen);
        return chars;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletRequest
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class cHttpServletRequest
: public cHttpServletRequestT<>
{
public:
    typedef cHttpServletRequestT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpServletRequest
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cHttpServletRequest
    (cConnectionInterface &connection,
     cCharReaderInterface *reader=0,
     cInputStreamInterface *input=0)
    : cIs(connection, reader, input) 
    {
    }
};

#endif /* ndef _CHTTPSERVLETREQUEST_HXX */
