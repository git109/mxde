/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cxalandocumentfactory.hxx
 *
 * Author: $author$
 *   Date: 11/21/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANDOCUMENTFACTORY_HXX
#define _CXALANDOCUMENTFACTORY_HXX

#include <XMLSupport/XMLParserLiaison.hpp>

#include "cxalandocumentfactoryinterface.hxx"
#include "cxalanfactorydocument.hxx"
#include "cimplement.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanDocumentFactory
 *
 * Author: $author$
 *   Date: 11/21/2003
 **********************************************************************
 */
class cXalanDocumentFactory
: virtual public cXalanDocumentFactoryInterface,
  public cDynamicListT
  <cXalanFactoryDocument, cXalanDocumentFactory, cImplement>
{
public:
    typedef cDynamicListT
    <cXalanFactoryDocument, cXalanDocumentFactory, cImplement> cIs;

    nsXalan::XMLParserLiaison &m_xml_parser_liaison;

    /**
     **********************************************************************
     * Constructor: cXalanDocumentFactory
     *
     *      Author: $author$
     *        Date: 11/21/2003
     **********************************************************************
     */
    cXalanDocumentFactory(nsXalan::XMLParserLiaison &xml_parser_liaison)
    : m_xml_parser_liaison(xml_parser_liaison) 
    {
    }

    /**
     **********************************************************************
     * Function: GetXalanDocument
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual nsXalan::XalanDocument *GetXalanDocument(eError &error)
    {
        nsXalan::XalanDocument *xalan_document;

        if (!(xalan_document = m_xml_parser_liaison.createDOMFactory()))
            error = e_ERROR_FAILED;

        else if ((error = AddXalanDocument(*xalan_document)))
        {
            m_xml_parser_liaison.destroyDocument(xalan_document);
            xalan_document = 0;
        }
        else error = e_ERROR_NONE;

        return xalan_document;
    }
    /**
     **********************************************************************
     * Function: FreeXalanDocument
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual eError FreeXalanDocument(nsXalan::XalanDocument &xalan_document)
    {
        eError error;

        if ((error = RemoveXalanDocument(xalan_document)))
            return error;

        m_xml_parser_liaison.destroyDocument(&xalan_document);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: AddXalanDocument
     *
     *   Author: $author$
     *     Date: 1/12/2004
     **********************************************************************
     */
    virtual eError AddXalanDocument(nsXalan::XalanDocument &xalan_document)
    {
        cXalanFactoryDocument *xalan_factory_document;

        if (!(xalan_factory_document = new cXalanFactoryDocument(xalan_document)))
            return e_ERROR_NEW;

        Add(xalan_factory_document);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: RemoveXalanDocument
     *
     *   Author: $author$
     *     Date: 1/12/2004
     **********************************************************************
     */
    virtual eError RemoveXalanDocument(nsXalan::XalanDocument &xalan_document)
    {
        cXalanFactoryDocument *xalan_factory_document;

        if ((xalan_factory_document = GetFirst()))
        do
        {
            if (&xalan_factory_document->GetXalanDocument() == &xalan_document)
            {
                Delete(xalan_factory_document);
                delete xalan_factory_document;
                return e_ERROR_NONE;
            }
        }
        while((xalan_factory_document = xalan_factory_document->GetNext()));

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Free
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual eError Free(cXalanFactoryDocument *xalan_factory_document)
    {
        m_xml_parser_liaison.destroyDocument
        (&xalan_factory_document->GetXalanDocument());
        delete xalan_factory_document;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetXalanDocument
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    inline nsXalan::XalanDocument *GetXalanDocument()
    {
        eError error;
        return GetXalanDocument(error);
    }
};

#endif /* ndef _CXALANDOCUMENTFACTORY_HXX */
