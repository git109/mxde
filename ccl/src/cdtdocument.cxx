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
 *   File: cdtdocument.cxx
 *
 * Author: $author$
 *   Date: 9/3/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "cdtparse.h"
#include "cdtparser.hxx"
#include "cdtdocument.hxx"
#include "cpath.hxx"

/*
 **********************************************************************
 *  Class: cDTDocumentType
 *
 * Author: $author$
 *   Date: 9/4/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cDTDocumentType::CreateDocument
 *
 *      Author: $author$
 *        Date: 9/4/2003
 **********************************************************************
 */
cDocumentInterface *cDTDocumentType::CreateDocument()
{
    cDocumentInterface *document;

    if (!(document=new cDTDocument()))
        SetLastError(e_ERROR_NEW);

    return document;
}

/*
 **********************************************************************
 *  Class: cDTDocument
 *
 * Author: $author$
 *   Date: 9/3/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cDTDocument::ParseFromStream
 *
 *      Author: $author$
 *        Date: 9/4/2003
 **********************************************************************
 */
eError cDTDocument::ParseFromStream
(cCharStream &stream, const char *filename, const char *uri)
{
    int length;
    eError error;
    cCharBuffer out;
    cDTParser parser(*this, *this, out, stream);

    if (filename)
    if (0 > (length = parser.SetFilename(filename)))
        return error = -length;

    if ((error = parser.yyparse()))
        SetLastError(error=e_ERROR_FAILED,out.GetBuffer());

    return error;
}

