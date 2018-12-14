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
 *   File: ctcpconnection.hxx
 *
 * Author: $author$
 *   Date: 10/25/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTCPCONNECTION_HXX
#define _CTCPCONNECTION_HXX

#include "ctcpconnectioninterface.hxx"

/**
 **********************************************************************
 *  Class: cTcpConnectionT
 *
 * Author: $author$
 *   Date: 8/21/2005
 **********************************************************************
 */
template 
<class TIs=cConnection,
 class TInterfaceIs=cTcpConnectionInterface>

class cTcpConnectionT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    cInetSocketInterface &m_socket;

    /**
     **********************************************************************
     * Constructor: cTcpConnectionT
     *
     *      Author: $author$
     *        Date: 8/21/2005
     **********************************************************************
     */
    cTcpConnectionT
    (cInetSocketInterface &socket, bool keep_alive_on=false) 
    : cIs(keep_alive_on),
      m_socket(socket)
    {
    }
    /**
     **********************************************************************
     * Function: GetSocket
     *
     *   Author: $author$
     *     Date: 8/21/2005
     **********************************************************************
     */
    virtual cInetSocketInterface& GetSocket() const
    {
        return m_socket;
    }
};

/**
 **********************************************************************
 *  Class: cTcpConnection
 *
 * Author: $author$
 *   Date: 8/21/2005
 **********************************************************************
 */
class cTcpConnection
: public cTcpConnectionT<>
{
public:
    typedef cTcpConnectionT<> cIs;

    /**
     **********************************************************************
     * Constructor: cTcpConnection
     *
     *      Author: $author$
     *        Date: 8/21/2005
     **********************************************************************
     */
    cTcpConnection
    (cInetSocketInterface &socket, bool keep_alive_on=false) 
    : cIs(socket, keep_alive_on) 
    {
    }
};

#endif /* ndef _CTCPCONNECTION_HXX */
