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
 *   File: cnamespacedocumentparser.hxx
 *
 * Author: $author$
 *   Date: 11/12/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CNAMESPACEDOCUMENTPARSER_HXX
#define _CNAMESPACEDOCUMENTPARSER_HXX

#include "cdocumentparserinstance.hxx"
#include "cdocumentparserimplement.hxx"
#include "cdocumentparserinterface.hxx"
#include "cdocumentnodefactory.hxx"
#include "cnamespacedocumentevent.hxx"
#include "cdocument.hxx"

/**
 **********************************************************************
 *  Class: cNamespaceDocumentParser
 *
 * Author: $author$
 *   Date: 11/12/2005
 **********************************************************************
 */
class cNamespaceDocumentParser
: public cDocumentParserInstance
{
public:
    typedef cDocumentParserInstance cIs;

    cDocumentNamespaceFactoryInterface& m_ns_factory;
    cNamespaceDocumentEvent m_event;
    cDocumentNodeFactory m_node_factory;
    cDocument m_document;

    /**
     **********************************************************************
     * Constructor: cNamespaceDocumentParser
     *
     *      Author: $author$
     *        Date: 11/12/2005
     **********************************************************************
     */
    cNamespaceDocumentParser
    (cDocumentNamespaceFactoryInterface& ns_factory,
     const cCCharBuffer &ns_attribute_prefix) 
    : m_ns_factory(ns_factory),
      m_event(ns_attribute_prefix),
      m_node_factory(m_event, *this, ns_factory),
      m_document
      (m_event, m_node_factory, 
       *this, *this, ns_attribute_prefix)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cNamespaceDocumentParser
     *
     *      Author: $author$
     *        Date: 11/12/2005
     **********************************************************************
     */
    virtual ~cNamespaceDocumentParser()
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

#endif /* _CNAMESPACEDOCUMENTPARSER_HXX */
