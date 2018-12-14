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
 *   File: chtmldocument.cxx
 *
 * Author: $author$
 *   Date: 1/14/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "chtmldocument.hxx"
#include "chtmltodocumentparser.hxx"

/*
 **********************************************************************
 *  Class: cHTMLDocumentType
 *
 * Author: $author$
 *   Date: 1/14/2004
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cHTMLDocumentType::
 *
 *      Author: $author$
 *        Date: 1/14/2004
 **********************************************************************
 */
cDocumentInterface *cHTMLDocumentType::CreateDocument()
{
    cDocumentInterface *document;

    if (!(document=new cHTMLDocument()))
        SetLastError(e_ERROR_NEW);

    return document;
}

/*
 **********************************************************************
 *  Class: cHTMLDocument
 *
 * Author: $author$
 *   Date: 1/14/2004
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cHTMLDocument::ParseFromStream
 *
 *      Author: $author$
 *        Date: 1/14/2004
 **********************************************************************
 */
eError cHTMLDocument::ParseFromStream
(cCharStream &stream, const char *filename, const char *uri)
{
    eError error;
    cHTMLToDocumentParser parser(this);

    if ((error=parser.ParseFromStream(stream)))
        SetLastError(error=e_ERROR_FAILED);

    return error;
}

