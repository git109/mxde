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
 *   File: cwaitinterface.hxx
 *
 * Author: $author$
 *   Date: 10/9/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWAITINTERFACE_HXX
#define _CWAITINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cWaitInterfaceT
 *
 * Author: $author$
 *   Date: 10/9/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cWaitInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Wait
     *
     *   Author: $author$
     *     Date: 10/9/2004
     **********************************************************************
     */
    virtual eError Wait(int miliseconds=-1) = 0;
    /**
     **********************************************************************
     * Function: Notify
     *
     *   Author: $author$
     *     Date: 10/9/2004
     **********************************************************************
     */
    virtual eError Notify() = 0;
    /**
     **********************************************************************
     * Function: NotifyAll
     *
     *   Author: $author$
     *     Date: 10/9/2004
     **********************************************************************
     */
    virtual eError NotifyAll() = 0;
};

/**
 **********************************************************************
 *  Class: cWaitImplementT
 *
 * Author: $author$
 *   Date: 10/9/2004
 **********************************************************************
 */
template <class TIs=cImplement>
class cWaitImplementT
: virtual public cWaitInterfaceT?<cInterface>,
  public TIs
{
public:
    typedef TIs cIs;

    /**
     **********************************************************************
     * Function: Wait
     *
     *   Author: $author$
     *     Date: 10/9/2004
     **********************************************************************
     */
    virtual eError Wait(int miliseconds=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Notify
     *
     *   Author: $author$
     *     Date: 10/9/2004
     **********************************************************************
     */
    virtual eError Notify() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: NotifyAll
     *
     *   Author: $author$
     *     Date: 10/9/2004
     **********************************************************************
     */
    virtual eError NotifyAll() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* ndef _CWAITINTERFACE_HXX */
