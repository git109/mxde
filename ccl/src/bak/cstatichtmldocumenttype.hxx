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
 *   File: cstatichtmldocumenttype.hxx
 *
 * Author: $author$
 *   Date: 1/14/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTATICHTMLDOCUMENTTYPE_HXX
#define _CSTATICHTMLDOCUMENTTYPE_HXX

#include "chtmldocument.hxx"

/**
 **********************************************************************
 *  Class: cStaticHTMLDocumentType
 *
 * Author: $author$
 *   Date: 1/14/2004
 **********************************************************************
 */
class cStaticHTMLDocumentType
: public cHTMLDocumentType,
  public cErrorInstance,
  public cStaticDocumentType
{
public:
    typedef cHTMLDocumentType cDocumentTypeIs;
    typedef cStaticDocumentType cStaticDocumentTypeIs;

    static cStaticHTMLDocumentType m_instance;

    /**
     **********************************************************************
     * Constructor: cStaticHTMLDocumentType
     *
     *      Author: $author$
     *        Date: 1/14/2004
     **********************************************************************
     */
    cStaticHTMLDocumentType
    (bool is_default = false,
     const char *document_type = CHTMLDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CHTMLDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CHTMLDOCUMENT_FILE_EXTENSION)
    : cDocumentTypeIs(document_type,content_type,file_extension,is_default),
      cStaticDocumentTypeIs((cDocumentType&)*this) 
    {
    }
};

#endif /* ndef _CSTATICHTMLDOCUMENTTYPE_HXX */
