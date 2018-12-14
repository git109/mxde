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
 *   File: eolrepl.c
 *
 * Author: $author$
 *   Date: 12/23/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 12/23/2005
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    const char *pattern = "";
    const char *filename;
    FILE* file;
    int c;

    if (2 < argc)
    if ((filename = argv[1]))
    if ((pattern = argv[2]))
    if ((file = fopen(filename, "r")))
    {
        while (0 < (c = getc(file)))
        {
            if ('\n' == c)
                fputs(pattern, stdout);
            putc(c, stdout);
        }

        fclose(file);
    }
    return 0;
}
