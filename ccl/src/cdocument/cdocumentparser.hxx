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
 *   File: cdocumentparser.hxx
 *
 * Author: $author$
 *   Date: 11/4/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPARSER_HXX
#define _CDOCUMENTPARSER_HXX

#include "cdocumentparserinstance.hxx"
#include "cdocumentparserimplement.hxx"
#include "cdocumentparserinterface.hxx"
#include "cdocumentnodefactory.hxx"
#include "cdocumentfactory.hxx"
#include "cdocumentevent.hxx"
#include "cdocument.hxx"

/**
 **********************************************************************
 *  Class: cDocumentParser
 *
 * Author: $author$
 *   Date: 11/13/2005
 **********************************************************************
 */
class cDocumentParser
: public cDocumentParserInstance
{
public:
    typedef cDocumentParserInstance cIs;

    cDocumentNamespaceFactoryInterface& m_ns_factory;
    cDocumentEvent m_event;
    cDocumentNodeFactory m_node_factory;
    cDocument m_document;

    /**
     **********************************************************************
     * Constructor: cDocumentParser
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    cDocumentParser
    (cDocumentNamespaceFactoryInterface& ns_factory,
     const cCCharBuffer &ns_attribute_prefix) 
    : m_ns_factory(ns_factory),
      m_node_factory(m_event, *this, m_ns_factory),
      m_document
      (m_event, m_node_factory, 
       *this, *this, ns_attribute_prefix)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cDocumentParser
     *
     *      Author: $author$
     *        Date: 11/13/2005
     **********************************************************************
     */
    virtual ~cDocumentParser()
    {
    }
    /**
     **********************************************************************
     * Function: GetDocument
     *
     *   Author: $author$
     *     Date: 11/6/2005
     **********************************************************************
     */
    virtual cDocumentInterface& GetDocument() const
    {
        return (cDocumentInterface&)m_document;
    }
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetFactory() const
    {
        return (cDocumentFactoryInterface&)(*this);
    }
    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 11/21/2005
     **********************************************************************
     */
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const
    {
        return (cDocumentNodeFactoryInterface&)m_node_factory;
    }
};

#endif /* _CDOCUMENTPARSER_HXX */
