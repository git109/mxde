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
 *   File: ssl.cxx
 *
 * Author: $author$
 *   Date: 6/13/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cssl.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cSSLMain
 *
 * Author: $author$
 *   Date: 6/13/2004
 **********************************************************************
 */
class cSSLMain
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     * Constructor: cSSLMain
     *
     *      Author: $author$
     *        Date: 6/13/2004
     **********************************************************************
     */
    cSSLMain() 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cSSLMain
     *
     *     Author: $author$
     *       Date: 6/13/2004
     **********************************************************************
     */
    virtual ~cSSLMain()
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 6/13/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        cSSLVersion version;

        version.Put(m_out);
        return 0;
    }
} g_ssl_main;
