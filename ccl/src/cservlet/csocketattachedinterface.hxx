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
 *   File: csocketattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 10/16/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSOCKETATTACHEDINTERFACE_HXX
#define _CSOCKETATTACHEDINTERFACE_HXX

#include "platformsocket.h"
#include "cattachedinterfacet.hxx"

/**
 **********************************************************************
 *  Class: cSOCKETAttachedInterface
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cSOCKETAttachedInterface
: virtual public cAttachedInterfaceT
  <SOCKET, INVALID_SOCKET, cInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cSOCKETAttachedImplement
 *
 * Author: $author$
 *   Date: 10/16/2004
 **********************************************************************
 */
class cSOCKETAttachedImplement
: public cAttachedImplementT
  <SOCKET, INVALID_SOCKET, cSOCKETAttachedInterface>
{
public:
    typedef cAttachedImplementT
    <SOCKET, INVALID_SOCKET, cSOCKETAttachedInterface> cIs;

    /**
     **********************************************************************
     * Constructor: cSOCKETAttachedImplement
     *
     *      Author: $author$
     *        Date: 10/16/2004
     **********************************************************************
     */
    cSOCKETAttachedImplement(SOCKET attached=INVALID_SOCKET) 
    : cIs(attached) 
    {
    }
};

#endif /* ndef _CSOCKETATTACHEDINTERFACE_HXX */
