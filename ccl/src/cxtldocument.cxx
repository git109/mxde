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
 *   File: cxtldocument.cxx
 *
 * Author: $author$
 *   Date: 2/15/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cdtparse.h"
#include "cdxparser.hxx"
#include "cxtldocument.hxx"
#include "cxmltodocumentparser.hxx"

/*
 **********************************************************************
 *  Class: cXTLDocumentType
 *
 * Author: $author$
 *   Date: 2/15/2004
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cXTLDocumentType::CreateDocument
 *
 *      Author: $author$
 *        Date: 2/15/2004
 **********************************************************************
 */
cDocumentInterface *cXTLDocumentType::CreateDocument()
{
    cDocumentInterface *document;

    if (!(document=new cXTLDocument()))
        SetLastError(e_ERROR_NEW);

    return document;
}

/*
 **********************************************************************
 *  Class: cXTLDocument
 *
 * Author: $author$
 *   Date: 2/15/2004
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cXTLDocument::ParseFromStream
 *
 *      Author: $author$
 *        Date: 2/15/2004
 **********************************************************************
 */
eError cXTLDocument::ParseFromStream
(cCharStream &stream, const char *filename, const char *uri)
{
    eError error;

    if (!(error = cIs::ParseFromStream(stream, filename, uri)))
        error = PostParseElements(*this);

    return error;
}

/**
 **********************************************************************
 * Function: cXTLDocument::PostParseAttributeValue
 *
 *   Author: $author$
 *     Date: 2/15/2004
 **********************************************************************
 */
eError cXTLDocument::PostParseAttributeValue
(cElementSetInterface &element_set,
 const char *text, int textlen, 
 const char *expr, int exprlen)
{
    eError error=e_ERROR_NONE;

    if (0 < exprlen)
    {
        cCharBuffer in(expr, exprlen, exprlen);
        cCharBuffer out;
        cDXParser parser(*this, element_set, out, in);

        if ((error = parser.yyparse()))
            SetLastError(error=e_ERROR_FAILED,out.GetBuffer());
    }
    return error;
}
