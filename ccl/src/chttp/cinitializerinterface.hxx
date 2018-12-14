/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cinitializerinterface.hxx
 *
 * Author: $author$
 *   Date: 2/15/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CINITIALIZERINTERFACE_HXX
#define _CINITIALIZERINTERFACE_HXX

#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cInitializerInterfaceT
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
template
<class TIs=cInterfaceBase>

class c_INTERFACE_CLASS cInitializerInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/15/2006
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/15/2006
     **********************************************************************
     */
    virtual eError Finalize() = 0;
};

/**
 **********************************************************************
 *  Class: cInitializerInterface
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cInitializerInterface
: virtual public cInitializerInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cInitializerImplementT
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
template
<class TIs=cInitializerInterface>

class cInitializerImplementT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 2/15/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 2/15/2006
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cInitializerImplement
 *
 * Author: $author$
 *   Date: 2/15/2006
 **********************************************************************
 */
class cInitializerImplement
: virtual public cInitializerImplementT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cInitializer
 *
 * Author: $author$
 *   Date: 2/18/2006
 **********************************************************************
 */
class cInitializer
: virtual public cInitializerImplement
{
public:
};

#endif /* _CINITIALIZERINTERFACE_HXX */
