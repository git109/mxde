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
 *   File: cxalanfactorydocument.hxx
 *
 * Author: $author$
 *   Date: 11/21/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANFACTORYDOCUMENT_HXX
#define _CXALANFACTORYDOCUMENT_HXX

#include <XalanDOM/XalanDocument.hpp>

#include "clistt.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanFactoryDocument
 *
 * Author: $author$
 *   Date: 11/21/2003
 **********************************************************************
 */
class cXalanFactoryDocument
: public cDynamicListItemT<cXalanFactoryDocument>
{
public:
    typedef cDynamicListItemT<cXalanFactoryDocument> cIs;

    nsXalan::XalanDocument &m_xalan_document;

    /**
     **********************************************************************
     * Constructor: cXalanFactoryDocument
     *
     *      Author: $author$
     *        Date: 11/21/2003
     **********************************************************************
     */
    cXalanFactoryDocument(nsXalan::XalanDocument &xalan_document)
    : m_xalan_document(xalan_document) 
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
    nsXalan::XalanDocument &GetXalanDocument() const
    {
        return m_xalan_document;
    }
};

#endif /* ndef _CXALANFACTORYDOCUMENT_HXX */
