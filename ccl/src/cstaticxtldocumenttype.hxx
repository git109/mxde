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
 *   File: cstaticxtldocumenttype.hxx
 *
 * Author: $author$
 *   Date: 2/15/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSTATICXTLDOCUMENTTYPE_HXX
#define _CSTATICXTLDOCUMENTTYPE_HXX

#include "cxtldocument.hxx"

/**
 **********************************************************************
 *  Class: cStaticXTLDocumentType
 *
 * Author: $author$
 *   Date: 2/15/2004
 **********************************************************************
 */
class cStaticXTLDocumentType
: public cXTLDocumentType,
  public cErrorInstance,
  public cStaticDocumentType
{
public:
    typedef cXTLDocumentType cDocumentTypeIs;
    typedef cStaticDocumentType cStaticDocumentTypeIs;

    static cStaticXTLDocumentType m_instance;

    /**
     **********************************************************************
     * Constructor: cStaticXTLDocumentType
     *
     *      Author: $author$
     *        Date: 2/15/2004
     **********************************************************************
     */
    cStaticXTLDocumentType
    (bool is_default = false,
     const char *document_type = CXTLDOCUMENT_DOCUMENT_TYPE, 
     const char *content_type = CXMLDOCUMENT_CONTENT_TYPE,
     const char *file_extension = CXTLDOCUMENT_FILE_EXTENSION)
    : cDocumentTypeIs(document_type,content_type,file_extension,is_default),
      cStaticDocumentTypeIs((cDocumentType&)*this) 
    {
    }
};

#endif /* ndef _CSTATICXTLDOCUMENTTYPE_HXX */
