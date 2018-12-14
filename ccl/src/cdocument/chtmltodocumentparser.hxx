/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: chtmltodocumentparser.hxx
 *
 * Author: $author$
 *   Date: 11/13/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTMLTODOCUMENTPARSER_HXX
#define _CHTMLTODOCUMENTPARSER_HXX

#include "cdocumentparser.hxx"
#include "chtmltodocumentparserevent.hxx"
#include "chtmlwriter.hxx"

/**
 **********************************************************************
 *  Class: cHTMLToDocumentParser
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cHTMLToDocumentParser
: public cDocumentParser
{
public:
    typedef cDocumentParser cIs;

    cHTMLToDocumentParserEvent m_parser_event;
    cHTMLWriter m_parser_writer;
    cCharStreamToCharWriter m_char_stream_to_parser_writer;

    /**
     **********************************************************************
     * Constructor: cHTMLToDocumentParser
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cHTMLToDocumentParser
    (cDocumentNamespaceFactoryInterface& ns_factory)
    : cIs(ns_factory),
      m_parser_event(m_event, m_node_factory, m_document),
      m_parser_writer(m_parser_event),
      m_char_stream_to_parser_writer(m_parser_writer)
    {
    }
    /**
     **********************************************************************
     * Function: ParseStream
     *
     *   Author: $author$
     *     Date: 11/13/2005
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
     *     Date: 11/13/2005
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
};

#endif /* _CHTMLTODOCUMENTPARSER_HXX */
