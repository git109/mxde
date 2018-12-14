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
 *   File: cxmldocument.hxx
 *
 * Author: $author$
 *   Date: 9/5/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLDOCUMENT_HXX
#define _CXMLDOCUMENT_HXX

#define CXMLDOCUMENT_DOCUMENT_TYPE "xml"
#define CXMLDOCUMENT_CONTENT_TYPE "text/xml"
#define CXMLDOCUMENT_FILE_EXTENSION "xml"

#include "cdocumenttype.hxx"
#include "cdocument.hxx"

/**
 **********************************************************************
 *  Class: cXMLDocumentType
 *
 * Author: $author$
 *   Date: 9/3/2003
 **********************************************************************
 */
class cXMLDocumentType
: public cDocumentType
{
public:
    typedef cDocumentType cIs;

    /**
     **********************************************************************
     * Constructor: cXMLDocumentType
     *
     *      Author: $author$
     *        Date: 9/3/2003
     **********************************************************************
     */
    cXMLDocumentType
    (const char *document_type = CXMLDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CXMLDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CXMLDOCUMENT_FILE_EXTENSION,
     bool is_default=false)
    : cIs(document_type,content_type,file_extension,is_default) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 9/4/2003
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocument();
};

/**
 **********************************************************************
 *  Class: cXMLDocument
 *
 * Author: $author$
 *   Date: 9/5/2003
 **********************************************************************
 */
class cXMLDocument
: virtual public cDocumentInterface,
  virtual public cDocumentImplement,
  virtual public cArtifact,
  public cXMLDocumentType,
  public cElementSet
{
public:
    typedef cElementSet cIs;

    /**
     **********************************************************************
     * Constructor: cXMLDocument
     *
     *      Author: $author$
     *        Date: 9/5/2003
     **********************************************************************
     */
    cXMLDocument() 
    {
        SetParentDocument(this);
    }

    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 9/5/2003
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStream &stream, const char *filename=0, const char *uri=0);

    /**
     **********************************************************************
     * Function: GetNamespaceDesignator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual const char *GetNamespaceDesignator(int &length) const
    {
        static const char xmlns[]="xmlns";

        length = sizeof(xmlns)-1;
        return xmlns;
    }

    /**
     **********************************************************************
     * Function: GetNamespaceSeparator
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual const char *GetNamespaceSeparator(int &length) const
    {
        static const char colon[]=":";

        length = sizeof(colon)-1;
        return colon;
    }

    /**
     **********************************************************************
     * Function: GetIsXMLContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool GetIsXMLContentType() const
    {
        return true;
    }
};


#endif
