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
 *   File: cbytestreamconnectionhandler.hxx
 *
 * Author: $author$
 *   Date: 9/11/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTESTREAMCONNECTIONHANDLER_HXX
#define _CBYTESTREAMCONNECTIONHANDLER_HXX

#include "cbytestreamconnectionhandlerinterface.hxx"

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandlerImplementT
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
template
<class TInterfaceIs=cBYTEStreamConnectionHandlerInterface>

class cBYTEStreamConnectionHandlerImplementT
: virtual private TInterfaceIs
{
public:
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 8/21/2005
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cBYTEStreamConnectionInterface &connection)
    {
        cBYTEStreamInterface &stream = connection.GetStream();
        eError error = ProcessConnectionStream(stream);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessConnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessConnect
    (cBYTEStreamConnectionInterface &connection)
    {
        cBYTEStreamInterface &stream = connection.GetStream();
        eError error = ProcessConnectStream(stream);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessDisconnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnect
    (cBYTEStreamConnectionInterface &connection)
    {
        cBYTEStreamInterface &stream = connection.GetStream();
        eError error = ProcessDisconnectStream(stream);
        return error;
    }

    /**
     **********************************************************************
     * Function: ProcessConnectionStream
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError ProcessConnectionStream
    (cBYTEStreamInterface &stream)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessConnectStream
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessConnectStream
    (cBYTEStreamInterface &stream)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessDisconnectStream
     *
     *   Author: $author$
     *     Date: 8/22/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnectStream
    (cBYTEStreamInterface &stream)
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandlerImplement
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamConnectionHandlerImplement
: virtual public cBYTEStreamConnectionHandlerImplementT<>
{
public:
    typedef cBYTEStreamConnectionHandlerImplementT<> cIs;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandlerT
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
template
<class TIs=cInstance>
class cBYTEStreamConnectionHandlerT
: virtual public cBYTEStreamConnectionHandlerImplement,
  public TIs
{
public:
    typedef TIs cIs;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandler
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamConnectionHandler
: public cBYTEStreamConnectionHandlerT<>
{
public:
    typedef cBYTEStreamConnectionHandlerT<> cIs;
};

/**
 **********************************************************************
 *  Class: cBYTEStreamConnectionHandlerProxy
 *
 * Author: $author$
 *   Date: 9/11/2005
 **********************************************************************
 */
class cBYTEStreamConnectionHandlerProxy
: public cBYTEStreamConnectionHandler
{
public:
    typedef cBYTEStreamConnectionHandler cIs;

    cBYTEStreamConnectionHandlerInterface& m_connection_handler;

    /**
     **********************************************************************
     * Constructor: cBYTEStreamConnectionHandlerProxy
     *
     *      Author: $author$
     *        Date: 9/11/2005
     **********************************************************************
     */
    cBYTEStreamConnectionHandlerProxy
    (cBYTEStreamConnectionHandlerInterface& connection_handler) 
    : m_connection_handler(connection_handler)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cBYTEStreamConnectionInterface &connection) 
    {
        eError error = m_connection_handler
        .ProcessConnection(connection);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessConnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessConnect
    (cBYTEStreamConnectionInterface &connection) 
    {
        eError error = m_connection_handler
        .ProcessConnect(connection);
        return error;
    }
    /**
     **********************************************************************
     * Function: ProcessDisconnect
     *
     *   Author: $author$
     *     Date: 9/11/2005
     **********************************************************************
     */
    virtual eError ProcessDisconnect
    (cBYTEStreamConnectionInterface &connection) 
    {
        eError error = m_connection_handler
        .ProcessDisconnect(connection);
        return error;
    }
};

#endif /* _CBYTESTREAMCONNECTIONHANDLER_HXX */
