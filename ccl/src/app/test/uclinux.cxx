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
 *   File: uclinux.cxx
 *
 * Author: $author$
 *   Date: 12/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>

/**
 **********************************************************************
 *  Class: cUcLinuxInterface
 *
 * Author: $author$
 *   Date: 12/24/2005
 **********************************************************************
 */
class cUcLinuxInterface
{
public:
    /**
     **********************************************************************
     * Function: Hi
     *
     *   Author: $author$
     *     Date: 12/24/2005
     **********************************************************************
     */
    virtual void Hi() = 0;
};

/**
 **********************************************************************
 *  Class: cUcLinux
 *
 * Author: $author$
 *   Date: 12/24/2005
 **********************************************************************
 */
class cUcLinux
: virtual public cUcLinuxInterface
{
public:
    enum eError
    {
        e_ERROR_NONE   = 0,
        e_ERRPR_FAILED = 1
    };
    /**
     **********************************************************************
     * Constructor: cUcLinux
     *
     *      Author: $author$
     *        Date: 12/24/2005
     **********************************************************************
     */
    cUcLinux() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cUcLinux
     *
     *      Author: $author$
     *        Date: 12/24/2005
     **********************************************************************
     */
    virtual ~cUcLinux()
    {
    }
    /**
     **********************************************************************
     * Function: Hi
     *
     *   Author: $author$
     *     Date: 12/24/2005
     **********************************************************************
     */
    virtual void Hi() 
    {
        try 
        {
            printf("Hi\n");
        }
        catch(eError error)
        {
            throw(error);
        }
    }
};

/**
 **********************************************************************
 * Function: main
 *
 *   Author: $author$
 *     Date: 12/24/2005
 **********************************************************************
 */
int main(int argc,const char **argv)
{
    cUcLinux uClinux;

    uClinux.Hi();
    return 0;
}
