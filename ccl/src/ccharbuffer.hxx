/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: ccharbuffer.hxx
 *
 * Author: $author$
 *   Date: 7/7/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARBUFFER_HXX
#define _CCHARBUFFER_HXX

#include "ccharstream.hxx"
#include "ccharbuffert.hxx"

#define CCHARBUFFER_DEFAULT_SIZE 256

/**
 **********************************************************************
 *  Class: cCharBuffer
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
class cCharBuffer
: virtual public cCharStreamInterface,
  public cCharBufferT<CCHARBUFFER_DEFAULT_SIZE, cCharStream>
{
public:
    typedef cCharBufferT<CCHARBUFFER_DEFAULT_SIZE, cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharBuffer
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cCharBuffer(const char *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Function: CompareBuffer
     *
     *   Author: $author$
     *     Date: 8/2/2005
     **********************************************************************
     */
    int CompareBuffer(cCharBuffer &to) const
    {
        int unequal, length;
        const char *buffer;

        buffer = to.GetBuffer(length);
        unequal = Compare(buffer, length);
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cCharBufferSizedT
 *
 * Author: $author$
 *   Date: 4/22/2004
 **********************************************************************
 */
template <int VDefaultSize>
class cCharBufferSizedT
: virtual public cCharStreamInterface,
  public cCharBufferT<VDefaultSize, cCharStream>
{
public:
    typedef cCharBufferT<VDefaultSize, cCharStream> cIs;

    /**
     **********************************************************************
     * Constructor: cCharBufferSizedT
     *
     *      Author: $author$
     *        Date: 4/22/2004
     **********************************************************************
     */
    cCharBufferSizedT
    (const char *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
};

#endif
