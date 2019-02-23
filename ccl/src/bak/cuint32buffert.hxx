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
 *   File: cuint32buffert.hxx
 *
 * Author: $author$
 *   Date: 1/29/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CUINT32BUFFERT_HXX
#define _CUINT32BUFFERT_HXX

#include "cbuffert.hxx"
#include "cuint32stream.hxx"

/**
 **********************************************************************
 *  Class: cUint32BufferT
 *
 * Author: $author$
 *   Date: 1/29/2005
 **********************************************************************
 */
template
<int VDefaultSize, class TIs=cUint32Stream>
class cUint32BufferT
: public cBufferT<VDefaultSize, uint32, 0, TIs>
{
public:
    typedef cBufferT<VDefaultSize, uint32, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cUint32BufferT
     *
     *      Author: $author$
     *        Date: 1/29/2005
     **********************************************************************
     */
    cUint32BufferT
    (const uint32 *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
};

#endif /* _CUINT32BUFFERT_HXX */