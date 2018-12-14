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
 *   File: cbytebuffer.hxx
 *
 * Author: $author$
 *   Date: 11/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTEBUFFER_HXX
#define _CBYTEBUFFER_HXX

#include "cbytestreaminterface.hxx"
#include "cbytebuffert.hxx"

#define CBYTEBUFFER_DEFAULT_SIZE 256

/**
 **********************************************************************
 *  Class: cBYTEBuffer
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
class cBYTEBuffer
: virtual public cBYTEStreamInterface,
  public cBYTEBufferT<CBYTEBUFFER_DEFAULT_SIZE>
{
public:
    typedef cBYTEBufferT<CBYTEBUFFER_DEFAULT_SIZE> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEBuffer
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cBYTEBuffer
    (const BYTE *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
};

#endif /* ndef _CBYTEBUFFER_HXX */
