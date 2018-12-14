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
 *   File: cdocumentfactoryimplement.hxx
 *
 * Author: $author$
 *   Date: 11/1/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTFACTORYIMPLEMENT_HXX
#define _CDOCUMENTFACTORYIMPLEMENT_HXX

#include "cdocumentfactoryinterface.hxx"
#include "cdocumentartifactimplement.hxx"

/**
 **********************************************************************
 *  Class: cDocumentFactoryImplement
 *
 * Author: $author$
 *   Date: 10/12/2005
 **********************************************************************
 */
class cDocumentFactoryImplement
: virtual public cDocumentFactoryInterface
{
public:
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 11/8/2005
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateDocumentByType
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocumentByType
    (const char* uri, int length=-1) 
    {
        cDocumentInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: CreateDocument
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual cDocumentInterface* CreateDocument() 
    {
        cDocumentInterface* node = 0;
        return node;
    }
    /**
     **********************************************************************
     * Function: DestroyDocument
     *
     *   Author: $author$
     *     Date: 10/12/2005
     **********************************************************************
     */
    virtual eError DestroyDocument(cDocumentInterface& node) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetNodeFactory
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentNodeFactoryInterface& GetNodeFactory() const 
    {
        return cDocumentNodeFactoryInterface::GetNullNodeFactory();
    }
};

#endif /* _CDOCUMENTFACTORYIMPLEMENT_HXX */
