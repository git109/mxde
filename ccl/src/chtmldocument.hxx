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
 *   File: chtmldocument.hxx
 *
 * Author: $author$
 *   Date: 1/11/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTMLDOCUMENT_HXX
#define _CHTMLDOCUMENT_HXX

#define CHTMLDOCUMENT_DOCUMENT_TYPE "html"
#define CHTMLDOCUMENT_CONTENT_TYPE "text/html"
#define CHTMLDOCUMENT_FILE_EXTENSION "html"

#include "cdocumenttype.hxx"
#include "cdocument.hxx"

/**
 **********************************************************************
 *  Class: cHTMLDocumentType
 *
 * Author: $author$
 *   Date: 1/14/2004
 **********************************************************************
 */
class cHTMLDocumentType
: public cDocumentType
{
public:
    typedef cDocumentType cIs;

    /**
     **********************************************************************
     * Constructor: cHTMLDocumentType
     *
     *      Author: $author$
     *        Date: 1/14/2004
     **********************************************************************
     */
    cHTMLDocumentType
    (const char *document_type = CHTMLDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CHTMLDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CHTMLDOCUMENT_FILE_EXTENSION,
     bool is_default=false)
    : cIs(document_type,content_type,file_extension,is_default) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 1/14/2004
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocument();
};

/**
 **********************************************************************
 *  Class: cHTMLDocument
 *
 * Author: $author$
 *   Date: 1/11/2004
 **********************************************************************
 */
class cHTMLDocument
: virtual public cDocumentInterface,
  virtual public cDocumentImplement,
  virtual public cArtifact,
  public cHTMLDocumentType,
  public cElementSet
{
public:
    typedef cElementSet cIs;

    /**
     **********************************************************************
     * Constructor: cHTMLDocument
     *
     *      Author: $author$
     *        Date: 1/11/2004
     **********************************************************************
     */
    cHTMLDocument()
    {
    }

    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 1/11/2004
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStream &stream, const char *filename, const char *uri);
};

#endif /* ndef _CHTMLDOCUMENT_HXX */
