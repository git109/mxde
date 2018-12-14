/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: csoapobjectcontainerinterface.hxx
 *
 * Author: $author$
 *   Date: 1/4/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSOAPOBJECTCONTAINERINTERFACE_HXX
#define _CSOAPOBJECTCONTAINERINTERFACE_HXX

#include "csoapobjectinterface.hxx"

/**
 **********************************************************************
 *  Class: cSOAPObjectContainerInterface
 *
 * Author: $author$
 *   Date: 1/3/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cSOAPObjectContainerInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetObjectByName
     *
     *   Author: $author$
     *     Date: 1/3/2006
     **********************************************************************
     */
    virtual cSOAPObjectInterface* GetObjectByName
    (const cCCharBuffer& name) const = 0;
};

/**
 **********************************************************************
 *  Class: cSOAPObjectContainerImplement
 *
 * Author: $author$
 *   Date: 1/3/2006
 **********************************************************************
 */
class cSOAPObjectContainerImplement
: virtual public cSOAPObjectContainerInterface
{
public:
    /**
     **********************************************************************
     * Function: GetObjectByName
     *
     *   Author: $author$
     *     Date: 1/3/2006
     **********************************************************************
     */
    virtual cSOAPObjectInterface* GetObjectByName
    (const cCCharBuffer& name) const 
    {
        cSOAPObjectInterface* object = 0;
        return object;
    }
};

#endif /* _CSOAPOBJECTCONTAINERINTERFACE_HXX */
