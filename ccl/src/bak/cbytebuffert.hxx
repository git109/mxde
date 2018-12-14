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
 *   File: cbytebuffert.hxx
 *
 * Author: $author$
 *   Date: 11/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CBYTEBUFFERT_HXX
#define _CBYTEBUFFERT_HXX

#include "cbuffert.hxx"
#include "cbytestream.hxx"

/**
 **********************************************************************
 *  Class: cBYTEBufferT
 *
 * Author: $author$
 *   Date: 11/8/2004
 **********************************************************************
 */
template <int VDefaultSize, class TIs=cBYTEStream>
class cBYTEBufferT
: public cBufferT<VDefaultSize, BYTE, 0, TIs>
{
public:
    typedef cBufferT<VDefaultSize, BYTE, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cBYTEBufferT
     *
     *      Author: $author$
     *        Date: 11/8/2004
     **********************************************************************
     */
    cBYTEBufferT
    (const BYTE *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
};

#endif /* ndef _CBYTEBUFFERT_HXX */
