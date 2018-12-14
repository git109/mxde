/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$
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
 *   File: cdocumentfactoryinterface.hxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTFACTORYINTERFACE_HXX
#define _CDOCUMENTFACTORYINTERFACE_HXX

#include "cdocumentartifactinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentFactoryInterface
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentFactoryInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetNullFactory
     *
     *   Author: $author$
     *     Date: 11/23/2005
     **********************************************************************
     */
    static cDocumentFactoryInterface& GetNullFactory();

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError Finalize() = 0;
    /**
     **********************************************************************
     * Function: CreateDocumentByType
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocumentByType
    (const char* uri, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocument() = 0;
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual eError DestroyDocument(cDocumentInterface& node) = 0;

    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const = 0;
};

#endif /* _CDOCUMENTFACTORYINTERFACE_HXX */
