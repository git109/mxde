/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: chttprequest.hxx
 *
 * Author: $author$
 *   Date: 2/24/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTTPREQUEST_HXX
#define _CHTTPREQUEST_HXX

#include "chttprequestinterface.hxx"
#include "chttprequestheader.hxx"
#include "ccharbufferinputstream.hxx"
#include "ccharstring.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequest
 *
 * Author: $author$
 *   Date: 2/24/2006
 **********************************************************************
 */
class cHttpRequest
: virtual public cInitializerImplement,
  virtual public cHttpRequestImplement,
  public cHttpHeaderFieldListEvent
{
public:
    typedef cHttpHeaderFieldListEvent cIs;

    cHttpRequestHeader m_header;

    cCharString m_content_type;
    int m_content_length;
    bool m_is_chunked_content;
    bool m_content_is_consumed;

    int m_server_port;
    cCharString m_server_name;

    cInputStream m_null_content_input;
    cInputStreamInterface* m_content_input;

    /**
     **********************************************************************
     * Constructor: cHttpRequest
     *
     *      Author: $author$
     *        Date: 2/24/2006
     **********************************************************************
     */
    cHttpRequest() 
    : m_header(*this),
      m_content_length(-1),
      m_is_chunked_content(false),
      m_content_is_consumed(false),
      m_server_port(-1),
      m_content_input(0)
    {
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/1/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        if (!(error = m_header.Initialize()))
        {
            m_server_name.SetChars("");
            m_content_type.SetChars("");
            m_server_port = -1;
            m_content_length = -1;
            m_content_input = 0;
            m_is_chunked_content = false;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddContentTypeField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddContentTypeField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        int value_length;
        const char* value;

        if ((value = field.GetValue(value_length)))
        if (0 < value_length)
        if (0 > (value_length = SetContentType(value, value_length)))
            error = -value_length;

        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddContentLengthField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddContentLengthField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        int content_length, value_length;
        const char* value;

        if ((value = field.GetValue(value_length)))
        if (0 < value_length)
        {
            cCharBuffer buffer(value, value_length, value_length);
            cCharBufferInputStream input(buffer);
            cHttpHeaderIntDeserializer deserializer(content_length);

            if (0 < (value_length = deserializer.
                Deserialize(input, value_length)))
            if (0 > (content_length = SetContentLength(content_length)))
                error = -content_length;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddChunkedTransferEncodingField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddChunkedTransferEncodingField
    (cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        int result;

        if (0 > (result = SetIsChunkedContent()))
            error = -result;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddHostField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddHostField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAddQueryStringField
     *
     *   Author: $author$
     *     Date: 2/14/2006
     **********************************************************************
     */
    virtual eError OnAddQueryStringField(cHttpHeaderField& field) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetContentType
     *
     *   Author: $author$
     *     Date: 2/24/2006
     **********************************************************************
     */
    virtual int SetContentType
    (const char* chars, int length=-1) 
    {
        int result = m_content_type.SetChars(chars, length);
        return result;
    }
    /**
     **********************************************************************
     * Function: GetContentType
     *
     *   Author: $author$
     *     Date: 2/24/2006
     **********************************************************************
     */
    virtual const char* GetContentType
    (int& length) const 
    {
        const char* chars = m_content_type.GetChars(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: SetContentLength
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetContentLength(int length) 
    {
        int result = m_content_length = length;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetContentLength
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int GetContentLength() const 
    {
        int result = m_content_length;
        return result;
    }

    /**
     **********************************************************************
     * Function: SetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual int SetIsChunkedContent(bool is=true) 
    {
        int result = m_is_chunked_content = is;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetIsChunkedContent
     *
     *   Author: $author$
     *     Date: 2/25/2006
     **********************************************************************
     */
    virtual bool GetIsChunkedContent() const 
    {
        bool is = m_is_chunked_content;
        return is;
    }

    /**
     **********************************************************************
     * Function: SetContentIsConsumed
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual int SetContentIsConsumed(bool is=true) 
    {
        int result = m_content_is_consumed = is;
        return result;
    }
    /**
     **********************************************************************
     * Function: GetContentIsConsumed
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual bool GetContentIsConsumed() const 
    {
        bool is = m_content_is_consumed;
        return is;
    }

    /**
     **********************************************************************
     * Function: SetContentInputStream
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual cInputStreamInterface* SetContentInputStream
    (cInputStreamInterface* input) 
    {
        cInputStreamInterface* old_content_input = m_content_input;
        m_content_input = input;
        return old_content_input;
    }
    /**
     **********************************************************************
     * Function: GetContentInputStream
     *
     *   Author: $author$
     *     Date: 2/27/2006
     **********************************************************************
     */
    virtual cInputStreamInterface& GetContentInputStream() const 
    {
        if (m_content_input)
            return *m_content_input;

        return (cInputStreamInterface&)m_null_content_input;
    }
};

#endif /* _CHTTPREQUEST_HXX */


