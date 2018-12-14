/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cinstanceinterface.hxx
 *
 * Author: $author$
 *   Date: 6/7/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CINSTANCEINTERFACE_HXX
#define _CINSTANCEINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cInstanceInterface
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cInstanceInterface
{
public:
    typedef cInstanceInterface cDerives;
    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cInstanceInterface* 
    NewInstance(eError& error) const = 0;
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteInstance
    (cInstanceInterface& instance) = 0;
};

/**
 **********************************************************************
 *  Class: cInstanceImplement
 *
 * Author: $author$
 *   Date: 6/7/2007
 **********************************************************************
 */
class cInstanceImplement
: virtual public cInstanceInterface
{
public:
    typedef cInstanceInterface cImplements;
    typedef cInstanceImplement cDerives;
    /**
     **********************************************************************
     * Function: NewInstance
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual cInstanceInterface* 
    NewInstance(eError& error) const
    {
        cInstanceInterface* instance = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return instance;
    }
    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 6/7/2007
     **********************************************************************
     */
    virtual eError DeleteInstance
    (cInstanceInterface& instance) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CINSTANCEINTERFACE_HXX */
