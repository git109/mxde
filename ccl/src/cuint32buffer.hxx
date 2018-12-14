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
 *   File: cuint32buffer.hxx
 *
 * Author: $author$
 *   Date: 1/29/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CUINT32BUFFER_HXX
#define _CUINT32BUFFER_HXX

#include "cuint32streaminterface.hxx"
#include "cuint32buffert.hxx"

#define CUINT32BUFFER_DEFAULT_SIZE 64

/**
 **********************************************************************
 *  Class: cUint32Buffer
 *
 * Author: $author$
 *   Date: 1/29/2005
 **********************************************************************
 */
class cUint32Buffer
: virtual public cUint32StreamInterface,
  public cUint32BufferT<CUINT32BUFFER_DEFAULT_SIZE>
{
public:
    typedef cUint32BufferT<CUINT32BUFFER_DEFAULT_SIZE> cIs;

    /**
     **********************************************************************
     * Constructor: cUint32Buffer
     *
     *      Author: $author$
     *        Date: 1/29/2005
     **********************************************************************
     */
    cUint32Buffer
    (const uint32 *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
};

#endif /* _CUINT32BUFFER_HXX */