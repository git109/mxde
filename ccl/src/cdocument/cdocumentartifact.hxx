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
 *   File: cdocumentartifact.hxx
 *
 * Author: $author$
 *   Date: 11/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTARTIFACT_HXX
#define _CDOCUMENTARTIFACT_HXX

#include "cdocumentartifactimplement.hxx"
#include "cdocumentartifactinterface.hxx"
#include "cisdynamicinstance.hxx"

/**
 **********************************************************************
 *  Class: cDocumentArtifact
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentArtifact
: virtual public cDocumentArtifactImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    cDocumentElementInterface *m_parent_element;
    cDocumentInterface *m_parent_document;

    /**
     **********************************************************************
     * Constructor: cDocumentArtifact
     *
     *      Author: $author$
     *        Date: 10/16/2005
     **********************************************************************
     */
    cDocumentArtifact
    (cDocumentElementInterface *parent_element=0,
     cDocumentInterface *parent_document=0) 
    : m_parent_document(parent_document),
      m_parent_element(parent_element)
    {
    }

    /**
     **********************************************************************
     * Function: SetParentDocument
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual eError SetParentDocument(cDocumentInterface *document)
    {
        m_parent_document = document;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetParentDocument
     *
     *   Author: $author$
     *     Date: 10/8/2005
     **********************************************************************
     */
    virtual cDocumentInterface *GetParentDocument() const
    {
        return m_parent_document;
    }

    /**
     **********************************************************************
     * Function: SetParentElement
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual eError SetParentElement
    (cDocumentElementInterface *element)
    {
        m_parent_element = element;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetParentElement
     *
     *   Author: $author$
     *     Date: 10/16/2005
     **********************************************************************
     */
    virtual cDocumentElementInterface *GetParentElement() const
    {
        return m_parent_element;
    }
};

/**
 **********************************************************************
 *  Class: cIsDynamicDocumentArtifact
 *
 * Author: $author$
 *   Date: 10/20/2005
 **********************************************************************
 */
class cIsDynamicDocumentArtifact
: public cIsDynamicInstanceT<cDocumentArtifact>
{
public:
    typedef cIsDynamicInstanceT<cDocumentArtifact> cIs;

    /**
     **********************************************************************
     * Constructor: cIsDynamicDocumentArtifact
     *
     *      Author: $author$
     *        Date: 10/20/2005
     **********************************************************************
     */
    cIsDynamicDocumentArtifact() 
    {
    }
};

#endif /* _CDOCUMENTARTIFACT_HXX */
