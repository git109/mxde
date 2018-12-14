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
 *   File: cxalandocumentfactoryinterface.hxx
 *
 * Author: $author$
 *   Date: 12/11/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXALANDOCUMENTFACTORYINTERFACE_HXX
#define _CXALANDOCUMENTFACTORYINTERFACE_HXX

#include <XalanDOM/XalanDocument.hpp>

#include "cinterface.hxx"
#include "nsxalan.hxx"

/**
 **********************************************************************
 *  Class: cXalanDocumentFactoryInterface
 *
 * Author: $author$
 *   Date: 12/11/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cXalanDocumentFactoryInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetXalanDocument
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual nsXalan::XalanDocument *GetXalanDocument(eError &error)=0;
    /**
     **********************************************************************
     * Function: FreeXalanDocument
     *
     *   Author: $author$
     *     Date: 12/11/2003
     **********************************************************************
     */
    virtual eError FreeXalanDocument(nsXalan::XalanDocument &xalan_document)=0;
};

#endif /* ndef _CXALANDOCUMENTFACTORYINTERFACE_HXX */
