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
 *   File: cxmldocument.cxx
 *
 * Author: $author$
 *   Date: 9/5/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cxmldocument.hxx"
#include "cxmltodocumentparser.hxx"

/*
 **********************************************************************
 *  Class: cXMLDocumentType
 *
 * Author: $author$
 *   Date: 9/4/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cXMLDocumentType::CreateDocument
 *
 *      Author: $author$
 *        Date: 9/4/2003
 **********************************************************************
 */
cDocumentInterface *cXMLDocumentType::CreateDocument()
{
    cDocumentInterface *document;

    if (!(document=new cXMLDocument()))
        SetLastError(e_ERROR_NEW);

    return document;
}

/*
 **********************************************************************
 *  Class: cXMLDocument
 *
 * Author: $author$
 *   Date: 9/5/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cXMLDocument::ParseFromStream
 *
 *      Author: $author$
 *        Date: 9/5/2003
 **********************************************************************
 */
eError cXMLDocument::ParseFromStream
(cCharStream &stream, const char *filename, const char *uri)
{
    eError error;
    cXMLToDocumentParser parser(this);

    if ((error=parser.ParseFromStream(stream)))
        SetLastError(error=e_ERROR_FAILED);

    return error;
}
