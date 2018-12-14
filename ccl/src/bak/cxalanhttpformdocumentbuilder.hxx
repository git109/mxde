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
 *   File: cxalanhttpformdocumentbuilder.hxx
 *
 * Author: $author$
 *   Date: 11/21/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANHTTPFORMDOCUMENTBUILDER_HXX
#define _CXALANHTTPFORMDOCUMENTBUILDER_HXX

#include "cxalandocumentfactory.hxx"
#include "chttpform.hxx"

/**
 **********************************************************************
 *  Class: cXalanHTTPFormDocumentBuilder
 *
 * Author: $author$
 *   Date: 11/21/2003
 **********************************************************************
 */
class cXalanHTTPFormDocumentBuilder
{
public:
    cXalanDocumentFactory &m_document_factory;

    /**
     **********************************************************************
     * Constructor: cXalanHTTPFormDocumentBuilder
     *
     *      Author: $author$
     *        Date: 11/21/2003
     **********************************************************************
     */
    cXalanHTTPFormDocumentBuilder
    (cXalanDocumentFactory &document_factory)
    : m_document_factory(document_factory)
    {
    }

    /**
     **********************************************************************
     * Function: BuildDocument
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual XalanDocument *BuildDocument(cHTTPForm &http_form)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 11/21/2003
     **********************************************************************
     */
    virtual eError DestroyDocument(XalanDocument &xalan_document)
    {
        return m_document_factory.
        FreeXalanDocument(xalan_document);
    }
};

#endif /* ndef _CXALANHTTPFORMDOCUMENTBUILDER_HXX */
