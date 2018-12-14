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

#include "cconnectioninterface.hxx"

/**
 **********************************************************************
 *  Class: cTcpConnectionT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cConnectionInterface,
 class TImplementIs=cConnectionImplement, 
 class TIs=cImplement>

class cTcpConnectionT
: virtual public TInterfaceIs,
  virtual public TImplementIs,
  public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Constructor: cTcpConnectionT
     *
     *      Author: $author$
     *        Date: 10/25/2004
     **********************************************************************
     */
    cTcpConnectionT() 
    {
    }
};

/**
 **********************************************************************
 *  Class: cTcpConnection
 *
 * Author: $author$
 *   Date: 10/25/2004
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
     *        Date: 10/25/2004
     **********************************************************************
     */
    cTcpConnection() 
    {
    }
};

#endif /* ndef _CTCPCONNECTION_HXX */
