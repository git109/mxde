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
 *   File: ccharfilereader.cxx
 *
 * Author: $author$
 *   Date: 9/29/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "ccharfilereader.hxx"

/*
 **********************************************************************
 *  Class: cCharFileReader
 *
 * Author: $author$
 *   Date: 9/29/2004
 **********************************************************************
 */
/**
 **********************************************************************
 *    Function: cCharFileReader::
 *
 *      Author: $author$
 *        Date: 9/29/2004
 **********************************************************************
 */

#if !defined(CCHARFILEREADER_MAIN)
/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 9/29/2004
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char *filename="c:/source/xml/XMLSchema.xsd";
    FILE *f;
    cCharFileReader r;
    char c[1];

    if ((f = fopen(filename, "r")))
    {
        r.Attach(f);
        r.Read(c, 1);
        r.Detach();
        fclose(f);
    }
    return 0;
}
#endif /* defined(CCHARFILEREADER_MAIN) */
