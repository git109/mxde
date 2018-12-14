/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: cdocumentfactory.hxx
 *
 * Author: $author$
 *   Date: 1/2/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTFACTORY_HXX
#define _CDOCUMENTFACTORY_HXX

#include "cdocumenttype.hxx"
#include "cdocumentimplement.hxx"
#include "cdocumentinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cDocumentFactory
 *
 * Author: $author$
 *   Date: 9/2/2003
 **********************************************************************
 */
class cDocumentFactory
: virtual public cDocumentFactoryInterface,
  virtual public cDocumentFactoryImplement,
  public cErrorInstance
{
public:
    typedef cErrorInstance cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentFactory
     *
     *      Author: $author$
     *        Date: 9/2/2003
     **********************************************************************
     */
    cDocumentFactory() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cDocumentFactory
     *
     *     Author: $author$
     *       Date: 9/2/2003
     **********************************************************************
     */
    virtual ~cDocumentFactory()
    {
    }

    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 1/7/2004
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocument()
    {
        cDocumentTypeInterface *type;

        if ((type = cStaticDocumentType::GetDefault()))
            return type->CreateDocument();

        return 0;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByFileExtension
     *
     *   Author: $author$
     *     Date: 9/3/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByFileExtension
    (const char *file_extension, int file_extensionlen=-1)
    {
        cDocumentTypeInterface *type;

        if ((type = cStaticDocumentType::GetByFileExtension
            (file_extension, file_extensionlen)))
            return type->CreateDocument();

        return 0;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByContentType
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByContentType
    (const char *content_type, int content_typelen=-1)
    {
        cDocumentTypeInterface *type;

        if ((type = cStaticDocumentType::GetByContentType
            (content_type, content_typelen)))
            return type->CreateDocument();

        return 0;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByType
     *
     *   Author: $author$
     *     Date: 9/2/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocumentByType
    (const char *document_type, int document_typelen=-1)
    {
        cDocumentTypeInterface *type;

        if ((type = cStaticDocumentType::GetByDocumentType
            (document_type, document_typelen)))
            return type->CreateDocument();

        return 0;
    }
};

#endif /* ndef _CDOCUMENTFACTORY_HXX */
