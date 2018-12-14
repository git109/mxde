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
 *   File: chttp11connectionhandler.hxx
 *
 * Author: $author$
 *   Date: 10/19/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTP11CONNECTIONHANDLER_HXX
#define _CHTTP11CONNECTIONHANDLER_HXX

#include "ctcpconnectionhandlerinterface.hxx"
#include "ctcpconnection.hxx"
#include "chttpservletinterface.hxx"
#include "chttp11processor.hxx"

/**
 **********************************************************************
 *  Class: cHttp11ConnectionHandlerT
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cTcpConnectionHandlerInterface,
 class TIs=cImplement>

class cHttp11ConnectionHandlerT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cTcpConnection &m_connection;
    cHttp11Processor &m_processor;

    /**
     **********************************************************************
     * Constructor: cHttp11ConnectionHandlerT
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cHttp11ConnectionHandlerT
    (cTcpConnection &connection, cHttp11Processor &processor) 
    : m_connection(connection),
      m_processor(processor)
    {
    }
    /**
     **********************************************************************
     * Function: ProcessConnection
     *
     *   Author: $author$
     *     Date: 10/19/2004
     **********************************************************************
     */
    virtual eError ProcessConnection
    (cInetSocketInterface &socket) 
    {
        eError error = e_ERROR_FAILED;
        cInputStreamInterface &input = socket.GetInputStream();
        cOutputStreamInterface &output = socket.GetOutputStream();

        error = m_processor.Process(input, output);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttp11ConnectionHandler
 *
 * Author: $author$
 *   Date: 10/19/2004
 **********************************************************************
 */
class cHttp11ConnectionHandler
: public cHttp11ConnectionHandlerT<>
{
public:
    typedef cHttp11ConnectionHandlerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cHttp11ConnectionHandler
     *
     *      Author: $author$
     *        Date: 10/19/2004
     **********************************************************************
     */
    cHttp11ConnectionHandler
    (cTcpConnection &connection, cHttp11Processor &processor)
    : cIs(connection, processor)
    {
    }
};

#endif /* ndef _CHTTP11CONNECTIONHANDLER_HXX */
