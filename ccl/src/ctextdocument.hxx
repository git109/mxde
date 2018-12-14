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
 *   File: ctextdocument.hxx
 *
 * Author: $author$
 *   Date: 2/16/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTEXTDOCUMENT_HXX
#define _CTEXTDOCUMENT_HXX

#define CTEXTDOCUMENT_DOCUMENT_TYPE "text"
#define CTEXTDOCUMENT_CONTENT_TYPE "text/plain"
#define CTEXTDOCUMENT_FILE_EXTENSION "txt"

#include "cdocumenttype.hxx"
#include "cdocument.hxx"

/**
 **********************************************************************
 *  Class: cTextDocumentType
 *
 * Author: $author$
 *   Date: 2/16/2004
 **********************************************************************
 */
class cTextDocumentType
: public cDocumentType
{
public:
    typedef cDocumentType cIs;

    /**
     **********************************************************************
     * Constructor: cTextDocumentType
     *
     *      Author: $author$
     *        Date: 2/16/2004
     **********************************************************************
     */
    cTextDocumentType
    (const char *document_type = CTEXTDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CTEXTDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CTEXTDOCUMENT_FILE_EXTENSION,
     bool is_default=false)
    : cIs(document_type,content_type,file_extension,is_default) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual cDocumentInterface *CreateDocument();
};

/**
 **********************************************************************
 *  Class: cTextDocument
 *
 * Author: $author$
 *   Date: 2/16/2004
 **********************************************************************
 */
class cTextDocument
: virtual public cDocumentInterface,
  virtual public cDocumentImplement,
  virtual public cArtifact,
  public cTextDocumentType,
  public cElementSet
{
public:
    typedef cElementSet cIs;

    /**
     **********************************************************************
     * Constructor: cTextDocument
     *
     *      Author: $author$
     *        Date: 2/16/2004
     **********************************************************************
     */
    cTextDocument() 
    {
        SetParentDocument(this);
    }

    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 2/16/2004
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStream &stream, const char *filename=0, const char *uri=0);

    /**
     **********************************************************************
     * Function: GetIsTextContentType
     *
     *   Author: $author$
     *     Date: 2/6/2004
     **********************************************************************
     */
    virtual bool GetIsTextContentType() const
    {
        return true;
    }
};

#endif /* ndef _CTEXTDOCUMENT_HXX */
