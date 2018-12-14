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
 *   File: chtmldocumentparsertype.hxx
 *
 * Author: $author$
 *   Date: 11/13/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CHTMLDOCUMENTPARSERTYPE_HXX
#define _CHTMLDOCUMENTPARSERTYPE_HXX

#include "cdocumentparsertype.hxx"
#include "chtmltodocumentparser.hxx"
#include "cdocumentparser.hxx"

/**
 **********************************************************************
 *  Class: cHTMLStaticDocumentParserType
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cHTMLStaticDocumentParserType
: public cStaticDocumentParserType
{
public:
    typedef cStaticDocumentParserType cIs;

    static cHTMLStaticDocumentParserType m_instance;

    cHTMLToDocumentParser m_parser;
    cHTMLToDocumentParser* m_free_parser;

    /**
     **********************************************************************
     * Constructor: cHTMLStaticDocumentParserType
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cHTMLStaticDocumentParserType
    (const char *chars="html", int length=-1) 
    : cIs(chars, length),
      m_parser(m_ns_factory),
      m_free_parser(&m_parser) 
    {
    }
    /**
     **********************************************************************
     * Function: GetParser
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual cDocumentParserInterface* GetParser() 
    {
        cDocumentParserInterface* parser = 0;

        if ((parser = m_free_parser))
            m_free_parser = 0;

        return parser;
    }
    /**
     **********************************************************************
     * Function: FreeParser
     *
     *   Author: $author$
     *     Date: 11/13/2005
     **********************************************************************
     */
    virtual eError FreeParser(cDocumentParserInterface& parser) 
    {
        eError error = e_ERROR_FAILED;

        if (!m_free_parser && (&parser == &m_parser))
        {
            m_free_parser = &m_parser;
            error = e_ERROR_NONE;
        }
        return error;
    }
};

#endif /* _CHTMLDOCUMENTPARSERTYPE_HXX */
