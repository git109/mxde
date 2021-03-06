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
 *   File: cinetsocketbytestream.hxx
 *
 * Author: $author$
 *   Date: 9/20/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINETSOCKETBYTESTREAM_HXX
#define _CINETSOCKETBYTESTREAM_HXX

#include "cinetsocket.hxx"

/**
 **********************************************************************
 *  Class: cInetSocketBYTEStream
 *
 * Author: $author$
 *   Date: 9/12/2005
 **********************************************************************
 */
class cInetSocketBYTEStream
: public cBYTEStream
{
public:
    typedef cBYTEStream cIs;

    cInetSocket& m_socket;

    /**
     **********************************************************************
     * Constructor: cInetSocketBYTEStream
     *
     *      Author: $author$
     *        Date: 9/12/2005
     **********************************************************************
     */
    cInetSocketBYTEStream(cInetSocket& socket) 
    : m_socket(socket)
    {
    }
    /**
     **********************************************************************
     * Function: Read
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Read
    (BYTE *buffer,  int size=-1) 
    {
        int result = m_socket.Receive(buffer, size);
        return result;
    }
    /**
     **********************************************************************
     * Function: Write
     *
     *   Author: $author$
     *     Date: 11/8/2004
     **********************************************************************
     */
    virtual int Write
    (const BYTE *buffer,  int size=-1) 
    {
        int result = m_socket.Send(buffer, size);
        return result;
    }
};

#endif /* _CINETSOCKETBYTESTREAM_HXX */