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
 *   File: ccreateinterface.hxx
 *
 * Author: $author$
 *   Date: 11/16/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCREATEINTERFACE_HXX
#define _CCREATEINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cCreateInterface
 *
 * Author: $author$
 *   Date: 11/16/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cCreateInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual eError Destroy() = 0;

    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsCreated(bool is_created=true) = 0;
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsCreated() const = 0;
};

/**
 **********************************************************************
 *  Class: cCreateImplement
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cCreateImplement
: virtual public cCreateInterface
{
public:
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsCreated(bool is_created=true)
    {
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsCreated() const
    {
        return false;
    }
};

#endif /* _CCREATEINTERFACE_HXX */
