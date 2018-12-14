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
 *   File: ccharbuffert.hxx
 *
 * Author: $author$
 *   Date: 7/6/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCHARBUFFERT_HXX
#define _CCHARBUFFERT_HXX

#include "cbuffert.hxx"
#include "ccharstreamt.hxx"

/**
 **********************************************************************
 *  Class: cCharBufferT
 *
 * Author: $author$
 *   Date: 7/6/2003
 **********************************************************************
 */
template <int VDefaultSize, class TIs=cCharStreamT<cStream> >
class cCharBufferT
: public cBufferT<VDefaultSize, char, 0, TIs>
{
public:
    typedef cBufferT<VDefaultSize, char, 0, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cCharBufferT
     *
     *      Author: $author$
     *        Date: 7/6/2003
     **********************************************************************
     */
    cCharBufferT(const char *buffer=0, int size=-1, int length=-1) 
    : cIs(buffer, size, length) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cCharBufferT
     *
     *     Author: $author$
     *       Date: 7/6/2003
     **********************************************************************
     */
    virtual ~cCharBufferT()
    {
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 7/6/2003
     **********************************************************************
     */
};

#endif
