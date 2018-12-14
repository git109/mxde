/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: ctcpendpoint.hxx
 *
 * Author: $author$
 *   Date: 3/30/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CTCPENDPOINT_HXX
#define _CTCPENDPOINT_HXX

#include "cinetsocketendpoint.hxx"

/**
 **********************************************************************
 *  Class: cTcpEndpoint
 *
 * Author: $author$
 *   Date: 3/30/2006
 **********************************************************************
 */
class cTcpEndpoint
: public cInetSocketEndpoint
{
public:
    typedef cInetSocketEndpoint cIs;
    /**
     **********************************************************************
     * Constructor: cTcpEndpoint
     *
     *      Author: $author$
     *        Date: 3/30/2006
     **********************************************************************
     */
    cTcpEndpoint() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cTcpEndpoint
     *
     *      Author: $author$
     *        Date: 3/30/2006
     **********************************************************************
     */
    virtual ~cTcpEndpoint()
    {
    }
};

#endif /* _CTCPENDPOINT_HXX */


