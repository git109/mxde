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
 *   File: gdtest.cxx
 *
 * Author: $author$
 *   Date: 2/19/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <gd.h>
#include "cmain.hxx"

/**
 **********************************************************************
 *  Main: cGDTest
 *
 * Author: $author$
 *   Date: 2/19/2004
 **********************************************************************
 */
class cGDTest
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     * Constructor: cGDTest
     *
     *      Author: $author$
     *        Date: 2/19/2004
     **********************************************************************
     */
    cGDTest() 
    : cMain() 
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 2/19/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        int black,white;
        gdImagePtr im;
        FILE *file;

        im = gdImageCreate(64, 64);
        black = gdImageColorAllocate(im, 0, 0, 0);
        white = gdImageColorAllocate(im, 255, 255, 255);
        gdImageLine(im, 0, 0, 63, 63, white);

        return 0;

        if ((file = fopen("gdtest.png", "wb")))
        {
            //gdImagePngEx(im, file, -1);
            fclose(file);
        }
        return 0;
    }
} g_gdtest;
