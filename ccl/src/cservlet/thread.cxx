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
 *   File: thread.cxx
 *
 * Author: $author$
 *   Date: 10/10/2004
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include "cthreadt.hxx"

/**
 **********************************************************************
 *  Class: cT
 *
 * Author: $author$
 *   Date: 10/10/2004
 **********************************************************************
 */
class cT
: public cThreadT<cT>
{
public:
    typedef cThreadT<cT> cIs;

    /**
     **********************************************************************
     * Constructor: cT
     *
     *      Author: $author$
     *        Date: 10/10/2004
     **********************************************************************
     */
    cT() 
    : cIs(this) 
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 10/10/2004
     **********************************************************************
     */
    virtual int OnRun() 
    {
        int result = 0;

        for (int i=0; i<100; i++)
        {
            printf("iteration=%d\n", i);
            Sleep(250);
        }
        return result;
    }
};

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 10/10/2004
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    eError error;
    cT t;

    if (!(error = t.Start()))
    {
        Sleep(250);

        while ((error = t.Wait(50)))
        {
            printf("waiting...\n");
        }

        t.Close();
    }
    return 0;
}
