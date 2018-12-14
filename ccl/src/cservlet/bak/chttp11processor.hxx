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
 *   File: chttp11processor.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP11PROCESSOR_HXX
#define _CHTTP11PROCESSOR_HXX

#include "cverboseinterface.hxx"
#include "chttpresponseoutputstream.hxx"
#include "chttprequestinputstream.hxx"
#include "chttprequestreader.hxx"
#include "chttpresponsewriter.hxx"
#include "chttp11header.hxx"
#include "chttp11requestdeserializer.hxx"
#include "chttp11responseserializer.hxx"
#include "chttpservletrequest.hxx"
#include "chttpservletresponse.hxx"
#include "chttpservletinterface.hxx"
#include "cprotocolprocessorinterface.hxx"
#include "cconnectioninterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cHttp11ProcessorT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template 
<class TInputStreamInterface=cInputStreamInterface, 
 class TOutputStreamInterface=cOutputStreamInterface, 
 class TInterfaceIs=cProtocolProcessorInterfaceT
 <TInputStreamInterface, TOutputStreamInterface, cInterface>,
 class TVerboseIs=cVerboseImplement,
 class TIs=cImplement>

class cHttp11ProcessorT
: virtual public TInterfaceIs,
  virtual public TVerboseIs,
  public TIs
{
public:
    typedef TVerboseIs cVerboseIs;
    typedef TIs cIs;

    const char *m_class;

    cConnectionInterface &m_connection;
    cHttpServletInterface &m_servlet;

    cHttpServletRequest m_request;
    cHttp11RequestDeserializer m_request_deserializer;

    cHttpServletResponse m_response;
    cHttp11ResponseSerializer m_response_serializer;

    /**
     **********************************************************************
     * Constructor: cHttp11ProcessorT
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cHttp11ProcessorT
    (cConnectionInterface &connection,
     cHttpServletInterface &servlet,
     cVerboseInterface *verbose=0,
     const char *p_class="cHttp11ProcessorT")
    : cVerboseIs(verbose),
      m_connection(connection),
      m_servlet(servlet),
      m_request(connection),
      m_request_deserializer(connection,m_request),
      m_response(connection),
      m_response_serializer(connection,m_response),
      m_class(p_class)
    {
    }
    /**
     **********************************************************************
     * Function: Process
     *
     *   Author: $author$
     *     Date: 10/21/2004
     **********************************************************************
     */
    virtual eError Process
    (TInputStreamInterface &input,
     TOutputStreamInterface &output)
    {
        eError error;
        int content_length;
        const char *content_type;

        cHttpRequestInputStream request_input
        (m_request, m_request_deserializer, input);

        cHttpResponseOutputStream response_output
        (m_response, m_response_serializer, output);

        cHttpResponseWriter response_writer
        (m_response, m_response_serializer, output);

        if (m_verbose)
            m_verbose->VerboseFormatted
            ("%s: Deserializing request...\n", 
             m_class);

        if (!(error = m_request_deserializer
            .Deserialize(input)))
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: ...Deserialized request\n", 
                 m_class);

            if (m_verbose)
            if ((content_type = m_request
                .GetContentType(content_length)))
            if (0 < content_length)
                m_verbose->VerboseFormatted
                ("%s: Content type = \"%s\"\n", 
                 m_class, content_type);

            if (m_request.IsChunkedContent())
            {
                cHttpRequestChunkedReader request_reader
                (m_request, m_request_deserializer, input);

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Content is chumked\n", m_class);

                error = Service(input, output);
            }
            else if (0 < (content_length = m_request.GetContentLength()))
            {
                cHttpRequestLengthReader request_reader
                (m_request, m_request_deserializer, 
                 input, content_length);

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Content length = %d\n", 
                     m_class, content_length);

                error = Service(input, output);
            }
            else if (HasContent())
            {
                cHttpRequestReader request_reader
                (m_request, m_request_deserializer, input);

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Content length indefinite\n", m_class);

                error = Service(input, output);
            }
            else error = Service(input, output);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: HasContent
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual bool HasContent() 
    {
        bool has = false;
        const char *content_type;
        int length;

        if ((content_type = m_request.GetContentType(length)))
        if (0 < length)
            has = true;

        return has;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/10/2004
     **********************************************************************
     */
    virtual eError Service
    (TInputStreamInterface &input,
     TOutputStreamInterface &output)
    {
        cCharWriterInterface &writer = m_response.GetWriter();
        eError error;
        int length;

        if (!(error = m_response.Clear()))
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: Calling servlet...\n", 
                 m_class);

            if (!(error = m_servlet.Service
                (m_request, m_response)))
            {
                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: ...Called servlet\n", 
                     m_class);

                if (!m_request.IsConsumed())
                {
                    cCharReaderInterface 
                        &reader = m_request.GetReader();

                    if (m_verbose)
                        m_verbose->VerboseFormatted
                        ("%s: Consuming remaining content...\n", 
                         m_class);

                    length = reader.Skip();

                    if (m_verbose)
                        m_verbose->VerboseFormatted
                        ("%s: ...Consumed remaining content[%d]\n", 
                         m_class, length);
                }

                writer.Flush();

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Serializing response...\n", 
                     m_class);

                if (0 > (length = m_response_serializer
                    .Serialize(output)))
                    error = -length;

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: ...Serialized response\n", 
                     m_class);

                if (m_response.IsChunkedContent())
                    output.Write
                    ((const BYTE*)"0\r\n\r\n");
            }
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttp11Processor
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class cHttp11Processor
: public cHttp11ProcessorT<>
{
public:
    typedef cHttp11ProcessorT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttp11Processor
     *
     *      Author: $author$
     *        Date: 10/21/2004
     **********************************************************************
     */
    cHttp11Processor
    (cConnectionInterface &connection,
     cHttpServletInterface &servlet,
     cVerboseInterface *verbose=0,
     const char *p_class="cHttp11Processor")
    : cIs(connection, servlet, verbose, p_class) 
    {
    }
};

#endif /* ndef _CHTTP11PROCESSOR_HXX */
