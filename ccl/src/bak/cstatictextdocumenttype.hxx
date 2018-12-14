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
 *   File: cstatictextdocumenttype.hxx
 *
 * Author: $author$
 *   Date: 2/16/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTATICTEXTDOCUMENTTYPE_HXX
#define _CSTATICTEXTDOCUMENTTYPE_HXX

#include "ctextdocument.hxx"

/**
 **********************************************************************
 *  Class: cStaticTextDocumentType
 *
 * Author: $author$
 *   Date: 2/16/2004
 **********************************************************************
 */
class cStaticTextDocumentType
: public cTextDocumentType,
  public cErrorInstance,
  public cStaticDocumentType
{
public:
    typedef cTextDocumentType cDocumentTypeIs;
    typedef cStaticDocumentType cStaticDocumentTypeIs;

    static cStaticTextDocumentType m_instance;

    /**
     **********************************************************************
     * Constructor: cStaticTextDocumentType
     *
     *      Author: $author$
     *        Date: 2/16/2004
     **********************************************************************
     */
    cStaticTextDocumentType
    (bool is_default = false,
     const char *document_type = CTEXTDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CTEXTDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CTEXTDOCUMENT_FILE_EXTENSION)
    : cDocumentTypeIs(document_type,content_type,file_extension,is_default),
      cStaticDocumentTypeIs((cDocumentType&)*this) 
    {
    }
};

#endif /* ndef _CSTATICTEXTDOCUMENTTYPE_HXX */
