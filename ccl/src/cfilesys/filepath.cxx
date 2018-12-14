/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: filepath.cxx
 *
 * Author: $author$
 *   Date: 12/25/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "cfilepathparser.hxx"
#include "cfilepathparserevent.hxx"
#include "cfilepathwriter.hxx"
#include "cfilepatht.hxx"
#include "cprintf.hxx"

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 12/25/2005
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char* path = "xx:../pp/dd/.ff.x";
    char c;
    eError error;
    cFilePath cpath;
    cFilePathParserEvent cevent(cpath);
    cFilePathWriter cwriter(cevent);
    cFilePathParser parser(cevent);
    cPrintf cprintf(stdout);
    int length;

    cwriter.SetPrintf(&cprintf);

    if (0 < (length = cpath.SetPathc(path)))
    {
            cCCharToCharBuffer dir(cpath.m_directory);
            printf("ok\n");
    }

    if (!(error = cwriter.Initialize()))
    {
        while ((c = *path++))
            cwriter.Putc(c);

        cwriter.Finalize();
        {
            cCCharToCharBuffer dev(cpath.m_device);
            cCCharToCharBuffer dir(cpath.m_directory);
            cCCharToCharBuffer f(cpath.m_file);
            cCCharToCharBuffer x(cpath.m_extension);

            printf("ok\n");
        }
    }
    return 0;
}
