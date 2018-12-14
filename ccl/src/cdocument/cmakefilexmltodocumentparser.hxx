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
 *   File: cmakefilexmltodocumentparser.hxx
 *
 * Author: $author$
 *   Date: 11/10/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CMAKEFILEXMLTODOCUMENTPARSER_HXX
#define _CMAKEFILEXMLTODOCUMENTPARSER_HXX

#include "cxmltodocumentparser.hxx"
#include "cmakefilecommentstocharwriter.hxx"

/**
 **********************************************************************
 *  Class: cMakefileXMLToDocumentParser
 *
 * Author: $author$
 *   Date: 11/10/2005
 **********************************************************************
 */
class cMakefileXMLToDocumentParser
: public cXMLToDocumentParser
{
public:
    typedef cXMLToDocumentParser cIs;

    cMakefileCommentsToCharWriter m_makefile_parser_writer;

    /**
     **********************************************************************
     * Constructor: cMakefileXMLToDocumentParser
     *
     *      Author: $author$
     *        Date: 11/10/2005
     **********************************************************************
     */
    cMakefileXMLToDocumentParser
    (cDocumentNamespaceFactoryInterface& ns_factory,
     bool is_dynamic=false) 
    : cIs(ns_factory, is_dynamic),
      m_makefile_parser_writer(m_parser_writer)
    {
    }
    /**
     **********************************************************************
     * Function: ParseStream
     *
     *   Author: $author$
     *     Date: 11/10/2005
     **********************************************************************
     */
    virtual eError ParseStream
    (cCharStreamInterface &stream, int length=-1) 
    {
        eError error = ParseStreamToWriter
        (m_makefile_parser_writer, stream, length);
        return error;
    }
};

#endif /* _CMAKEFILEXMLTODOCUMENTPARSER_HXX */
