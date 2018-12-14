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
 *   File: chttpservletresponse.hxx
 *
 * Author: $author$
 *   Date: 10/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETRESPONSE_HXX
#define _CHTTPSERVLETRESPONSE_HXX

#include "coutputstream.hxx"
#include "cservletresponse.hxx"
#include "chttpservletheader.hxx"
#include "chttpservletinterface.hxx"
#include "chttpservletresponseinterface.hxx"
#include "chttpresponseinterface.hxx"
#include "cconnectioninterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletResponseT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template 
<class THttpResponseInterfaceIs=cHttpResponseInterface,
 class THttpServletResponseInterfaceIs=cHttpServletResponseInterface,
 class TIs=cServletResponse>

class cHttpServletResponseT
: virtual public THttpResponseInterfaceIs,
  virtual public THttpServletResponseInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cConnectionInterface &m_connection;

    eHttpResponseHeaderStatus m_status;

    bool m_is_chunked_content;

    int m_content_length;
    cCharString m_content_type;

    cCharWriterInterface *m_writer;
    cCharWriter m_null_writer;

    cOutputStreamInterface *m_output;
    cOutputStream m_null_output;

    /**
     **********************************************************************
     * Constructor: cHttpServletResponseT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpServletResponseT
    (cConnectionInterface &connection,
     cCharWriterInterface *writer=0,
     cOutputStreamInterface *output=0,
     eHttpResponseHeaderStatus status
     =cHttpResponseHeaderStatus::e_STATUS_ERROR)
    : m_connection(connection),
      m_writer(writer),
      m_output(output),
      m_status(status),
      m_content_length(0),
      m_is_chunked_content(false)
    {
    }

    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual eError Clear()
    {
        eError error = e_ERROR_NONE;

        m_status = cHttpResponseHeaderStatus::e_STATUS_ERROR;
        m_content_length = 0;
        m_is_chunked_content = false;
        m_is_committed = false;
        m_content_type.ClearChars();
        return error;
    }
    /**
     **********************************************************************
     * Function: SetStatusOK
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eHttpResponseHeaderStatus SetStatusOK() 
    {
        m_status = cHttpResponseHeaderStatus::e_STATUS_OK;
        return m_status;
    }
    /**
     **********************************************************************
     * Function: GetStatusOK
     *
     *   Author: $author$
     *     Date: 10/28/2004
     **********************************************************************
     */
    virtual eHttpResponseHeaderStatus GetStatusOK() const
    {
        eHttpResponseHeaderStatus status = cHttpResponseHeaderStatus::e_STATUS_OK;
        return status;
    }

    /**
     **********************************************************************
     * Function: SetStatus
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual eHttpResponseHeaderStatus 
    SetStatus(eHttpResponseHeaderStatus status) 
    {
        m_status = status;
        return m_status;
    }
    /**
     **********************************************************************
     * Function: GetStatus
     *
     *   Author: $author$
     *     Date: 10/27/2004
     **********************************************************************
     */
    virtual eHttpResponseHeaderStatus GetStatus() const
    {
        return m_status;
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
     *     Date: 11/14/2004
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
     *     Date: 11/14/2004
     **********************************************************************
     */
    virtual bool IsChunkedContent() const
    {
        return m_is_chunked_content;
    }

    /**
     **********************************************************************
     * Function: SetWriter
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual cCharWriterInterface& SetWriter
    (cCharWriterInterface* writer)
    {
        if (m_writer = writer)
            return *m_writer;
        return m_null_writer;
    }
    /**
     **********************************************************************
     * Function: GetWriter
     *
     *   Author: $author$
     *     Date: 10/26/2004
     **********************************************************************
     */
    virtual cCharWriterInterface& GetWriter()
    {
        if (m_writer)
            return *m_writer;
        return m_null_writer;
    }

    /**
     **********************************************************************
     * Function: SetOutputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cOutputStreamInterface& SetOutputStream
    (cOutputStreamInterface *output) 
    {
        if ((m_output = output))
            return *m_output;
        return m_null_output;
    }
    /**
     **********************************************************************
     * Function: GetOutputStream
     *
     *   Author: $author$
     *     Date: 11/6/2004
     **********************************************************************
     */
    virtual cOutputStreamInterface& GetOutputStream() 
    {
        if (m_output)
            return *m_output;
        return m_null_output;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletResponse
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpServletResponse
: public cHttpServletResponseT<>
{
public:
    typedef cHttpServletResponseT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttpServletResponse
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cHttpServletResponse
    (cConnectionInterface &connection,
     cCharWriterInterface *writer=0,
     cOutputStreamInterface *output=0,
     eHttpResponseHeaderStatus status
     =cHttpResponseHeaderStatus::e_STATUS_ERROR)
    : cIs(connection, writer, output, status) 
    {
    }
};

#endif /* ndef _CHTTPSERVLETRESPONSE_HXX */
