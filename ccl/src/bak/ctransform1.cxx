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
 *   File: ctransform.cxx
 *
 * Author: $author$
 *   Date: 8/18/2003
 *
 *    $Id$
 **********************************************************************
 */

#include "ctransform.hxx"
#include "cdtparse.h"
#include "cdtparser.hxx"
#include "cdtlexer.hxx"
#include "cxmltodocumentparser.hxx"
#include "ccharbuffer.hxx"
#include "ccharfile.hxx"
#include "cdocument.hxx"

/*
 **********************************************************************
 *  Class: cTransform
 *
 * Author: $author$
 *   Date: 8/18/2003
 **********************************************************************
 */

/**
 **********************************************************************
 *    Function: cTransform::
 *
 *      Author: $author$
 *        Date: 8/18/2003
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 8/18/2003
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char *filename="test.xml";
    const char *extension;
    eError error;
    cCharFile in(filename);
    cCharFile out(stdout);
    cDocumentInterface *d;
    cDocumentFactory f;
    //cDTLexer l(out, in);
    //cDTParser p(d, out, in);

    if ((extension = strrchr(filename,'.')))
    if (*(++extension))
    if ((d = f.CreateDocumentByFileExtension(extension)))
    {
        if (!(error = d->ParseFromStream(in)))
            d->TransformToStream(out);
    }

    return 0;
}

