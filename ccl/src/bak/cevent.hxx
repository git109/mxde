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
 *   File: cevent.hxx
 *
 * Author: $author$
 *   Date: 10/8/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CEVENT_HXX
#define _CEVENT_HXX

#include "ceventt.hxx"

/**
 **********************************************************************
 *  Class: cEvent
 *
 * Author: $author$
 *   Date: 10/8/2004
 **********************************************************************
 */
class cEvent
: public cEventT<cBase>
{
public:
    typedef cEventT<cBase> cIs;

    /**
     **********************************************************************
     * Constructor: cEvent
     *
     *      Author: $author$
     *        Date: 10/8/2004
     **********************************************************************
     */
    cEvent(EVENT handle=INVALID_EVENT, bool opened=false) 
    : cIs(handle, opened) 
    {
    }
};

#endif /* ndef _CEVENT_HXX */
