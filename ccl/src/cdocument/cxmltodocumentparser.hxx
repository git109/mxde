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
 *   File: cxmltodocumentparser.hxx
 *
 * Author: $author$
 *   Date: 10/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLTODOCUMENTPARSER_HXX
#define _CXMLTODOCUMENTPARSER_HXX

#include "cnamespacedocumentparser.hxx"
#include "cxmltodocumentparserevent.hxx"
#include "cxmlwriter.hxx"

/**
 **********************************************************************
 *  Class: cXMLToDocumentParser
 *
 * Author: $author$
 *   Date: 10/15/2005
 **********************************************************************
 */
class cXMLToDocumentParser
: public cNamespaceDocumentParser
{
public:
    typedef cNamespaceDocumentParser cIs;
    typedef cXMLToDocumentParser cAm;

    const cCCharBuffer &m_ns_attribute_prefix;
    cXMLToDocumentParserEvent m_parser_event;
    cXMLWriter m_parser_writer;
    cCharStreamToCharWriter m_char_stream_to_parser_writer;
    cCharReaderToCharWriter m_char_reader_to_parser_writer;
    bool m_is_dynamic;

    /**
     **********************************************************************
     * Constructor: cXMLToDocumentParser
     *
     *      Author: $author$
     *        Date: 10/15/2005
     **********************************************************************
     */
    cXMLToDocumentParser
    (cDocumentNamespaceFactoryInterface& ns_factory,
     const cCCharBuffer &ns_attribute_prefix,
     bool is_dynamic=false)
    : cIs(ns_factory, ns_attribute_prefix),
      m_ns_attribute_prefix(ns_attribute_prefix),
      m_parser_event(m_event, m_node_factory, m_document),
      m_parser_writer(m_parser_event),
      m_char_stream_to_parser_writer(m_parser_writer),
      m_char_reader_to_parser_writer(m_parser_writer),
      m_is_dynamic(is_dynamic)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXMLToDocumentParser
     *
     *      Author: $author$
     *        Date: 10/15/2005
     **********************************************************************
     */
    virtual ~cXMLToDocumentParser()
    {
    }

    /**
     **********************************************************************
     * Function: ParseStream
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseStream
    (cCharStreamInterface &stream, int length=-1) 
    {
        eError error = ParseStreamToWriter
        (m_char_stream_to_parser_writer, stream, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseStreamToWriter
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseStreamToWriter
    (cCharStreamToCharWriter &char_stream_to_char_writer,
     cCharStreamInterface &stream, int length=-1) 
    {
        eError error = ParseStreamToParserWriter
        (m_parser_writer, 
         m_char_stream_to_parser_writer, stream, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseReader
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseReader
    (cCharReaderInterface &reader, int length=-1) 
    {
        eError error = ParseReaderToWriter
        (m_char_reader_to_parser_writer, reader, length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseReaderToWriter
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError ParseReaderToWriter
    (cCharReaderToCharWriter &char_reader_to_char_writer,
     cCharReaderInterface &reader, int length=-1) 
    {
        eError error = ParseReaderToParserWriter
        (m_parser_writer, 
         m_char_reader_to_parser_writer, reader, length);
        return error;
    }

    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocument() 
    {
        cDocumentInterface* node = 0;
        cAm *parser;

        if ((parser = new cAm
            (m_ns_factory, m_ns_attribute_prefix, true)))
            node = &parser->GetDocument();

        return node;
    }
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual eError DestroyDocument(cDocumentInterface& node) 
    {
        cDocumentParserInterface& parser = node.GetParser();
        eError error = parser.DeleteInstance();
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 11/25/2005
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        eError error = e_ERROR_NOT_ALLOWED;

        if (m_is_dynamic)
        {
            delete this;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

#endif /* _CXMLTODOCUMENTPARSER_HXX */