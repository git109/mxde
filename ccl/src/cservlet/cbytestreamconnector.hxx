/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cbytestreamconnector.hxx
 *
 * Author: $author$
 *   Date: 9/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMCONNECTOR_HXX
#define _CBYTESTREAMCONNECTOR_HXX

#include "cconnector.hxx"
#include "cbytestreamconnectionhandler.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamConnector
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamConnector
: virtual public cConnectorInterface,
  public cBYTEStreamConnectionHandler
{
public:
    typedef cBYTEStreamConnectionHandler cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEStreamConnector
     *
     *      Author: $author$
     *        Date: 9/11/2005
     **********************************************************************
     */
    cBYTEStreamConnector() 
    {
    }

    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError Listen(void) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError Connect(void) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Disconnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError Disconnect(void) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

#endif /* _CBYTESTREAMCONNECTOR_HXX */
