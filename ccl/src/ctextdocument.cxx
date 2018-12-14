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
 *   File: ctextdocument.cxx
 *
 * Author: $author$
 *   Date: 2/16/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "ctextdocument.hxx"

/*
 **********************************************************************
 *  Class: cTextDocumentType
 *
 * Author: $author$
 *   Date: 2/16/2004
 **********************************************************************
 */
/**
 **********************************************************************
 *    Function: cTextDocumentType::CreateDocument
 *
 *      Author: $author$
 *        Date: 2/16/2004
 **********************************************************************
 */
cDocumentInterface *cTextDocumentType::CreateDocument()
{
    cDocumentInterface *document;

    if (!(document=new cTextDocument()))
        SetLastError(e_ERROR_NEW);

    return document;
}

/*
 **********************************************************************
 *  Class: cTextDocument
 *
 * Author: $author$
 *   Date: 2/16/2004
 **********************************************************************
 */
/**
 **********************************************************************
 *    Function: cTextDocument::
 *
 *      Author: $author$
 *        Date: 2/16/2004
 **********************************************************************
 */
eError cTextDocument::ParseFromStream
(cCharStream &stream, const char *filename, const char *uri)
{
    eError error=e_ERROR_NONE;
    cElementInterface *element;
    cCharStream *text;
    int textlen;

    if ((element = AddTextElement()))
    if ((text = element->GetTextStream(textlen)))
        text->WriteStream(stream);

    return error;
}


