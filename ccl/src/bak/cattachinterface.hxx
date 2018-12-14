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
 *   File: cattachinterface.hxx
 *
 * Author: $author$
 *   Date: 11/16/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CATTACHINTERFACE_HXX
#define _CATTACHINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cAttachInterface
 *
 * Author: $author$
 *   Date: 11/16/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cAttachInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual eError Detach() = 0;

    /**
     **********************************************************************
     * Function: SetIsAttached
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsAttached(bool is_attached=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsAttached
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsAttached() const = 0;
};

#endif
