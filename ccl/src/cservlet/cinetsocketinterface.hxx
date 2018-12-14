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
 *   File: cinetsocketinterface.hxx
 *
 * Author: $author$
 *   Date: 10/16/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETSOCKETINTERFACE_HXX
#define _CINETSOCKETINTERFACE_HXX

#include "cinetsocketaddressinterface.hxx"
#include "copenedinterface.hxx"
#include "csocketattachedinterface.hxx"
#include "coutputstreaminterface.hxx"
#include "cinputstreaminterface.hxx"

/**
 **********************************************************************
 *  Class: cInetSocketInterfaceT
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
template 
<class TAs,
 class TAttachedIs=cSOCKETAttachedInterface,
 class TOpenedIs=cOpenedInterface, 
 class TIs=cInterface>

class c_INTERFACE_CLASS cInetSocketInterfaceT
: virtual public TAttachedIs,
  virtual public TOpenedIs,
  virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Open
    (int type=SOCK_STREAM, int protocol=IPPROTO_TCP) = 0;

    /**
     **********************************************************************
     * Function: AttachOpen
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual SOCKET AttachOpen
    (SOCKET attached, bool opened=true) = 0;

    /**
     **********************************************************************
     * Function: Bind
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Bind
    (cInetSocketAddressInterface &address) = 0;
    /**
     **********************************************************************
     * Function: Connect
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Connect
    (cInetSocketAddressInterface &address) = 0;

    /**
     **********************************************************************
     * Function: Listen
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual eError Listen
    (int backlog=DEFAULT_SOCKET_BACKLOG) = 0;
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual eError Accept(TAs &socket) = 0;

    /**
     **********************************************************************
     * Function: UpdateAcceptContext
     *
     *   Author: $author$
     *     Date: 11/16/2004
     **********************************************************************
     */
    virtual eError UpdateAcceptContext(TAs &socket) = 0;

    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int Send(const BYTE *buf, int len=-1) = 0;
    /**
     **********************************************************************
     * Function: Receive
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int Receive(BYTE *buf, int len=-1) = 0;

    /**
     **********************************************************************
     * Function: GetOutputStream
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual cOutputStreamInterface &GetOutputStream() = 0;
    /**
     **********************************************************************
     * Function: GetInputStream
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual cInputStreamInterface &GetInputStream() = 0;
};

/**
 **********************************************************************
 *  Class: cInetSocketInterface
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cInetSocketInterface
: virtual public cInetSocketInterfaceT<cInetSocketInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cInetSocketImplementT
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
template 
<class TAttachedImplementIs=cSOCKETAttachedImplement, 
 class TOpenedImplementIs=cOpenedImplement, 
 class TAttachedIs=cSOCKETAttachedInterface, 
 class TOpenedIs=cOpenedInterface, 
 class TIs=cInetSocketInterface>

class cInetSocketImplementT
: virtual public TIs,
  virtual public TAttachedImplementIs,
  virtual public TOpenedImplementIs
{
public:
    /**
     **********************************************************************
     * Constructor: cInetSocketImplementT
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cInetSocketImplementT
    (SOCKET attached=INVALID_SOCKET, bool opened=false)
    : TAttachedImplementIs(attached),
      TOpenedImplementIs(opened)
    {
    }

    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 10/16/2004
     **********************************************************************
     */
    virtual eError Open
    (int type=SOCK_STREAM, int protocol=IPPROTO_TCP) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: AttachOpen
     *
     *   Author: $author$
     *     Date: 10/17/2004
     **********************************************************************
     */
    virtual SOCKET AttachOpen(SOCKET attached, bool opened=true) 
    {
        SOCKET old_attached = this->Attach(attached);
        this->SetIsOpen(opened);
        return old_attached;
    }

    /**
     **********************************************************************
     * Function: Send
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int Send(const BYTE *buf, int len=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    /**
     **********************************************************************
     * Function: Receive
     *
     *   Author: $author$
     *     Date: 10/18/2004
     **********************************************************************
     */
    virtual int Receive(BYTE *buf, int len=-1) 
    {
        int count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
};

/**
 **********************************************************************
 *  Class: cInetSocketImplement
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class cInetSocketImplement
: virtual public cInetSocketImplementT<>
{
public:
    typedef cInetSocketImplementT<> cIs;

    /**
     **********************************************************************
     * Constructor: cInetSocketImplement
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cInetSocketImplement
    (SOCKET attached=INVALID_SOCKET, bool opened=false) 
    : cIs(attached, opened) 
    {
    }
};

#endif /* ndef _CINETSOCKETINTERFACE_HXX */
