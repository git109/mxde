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
 *   File: csocket.hxx
 *
 * Author: $author$
 *   Date: 3/11/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSOCKET_HXX
#define _CSOCKET_HXX

#include "csockett.hxx"
#include "ccharstream.hxx"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cSocket
 *
 * Author: $author$
 *   Date: 3/11/2004
 **********************************************************************
 */
class cSocket
: public cSocketT<cSocket, char, cCharStream>
{
public:
    typedef cSocketT<cSocket, char, cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cSocket
     *
     *      Author: $author$
     *        Date: 3/11/2004
     **********************************************************************
     */
    cSocket(SOCKET handle = INVALID_SOCKET)
    : cIs(handle) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cBYTESocket
 *
 * Author: $author$
 *   Date: 1/17/2005
 **********************************************************************
 */
class cBYTESocket
: public cSocketT<cBYTESocket, BYTE, cBYTEStream>
{
public:
    typedef cSocketT<cBYTESocket, BYTE, cBYTEStream> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTESocket
     *
     *      Author: $author$
     *        Date: 1/17/2005
     **********************************************************************
     */
    cBYTESocket(SOCKET handle = INVALID_SOCKET)
    : cIs(handle) 
    {
    }
};

#endif /* ndef _CSOCKET_HXX */
