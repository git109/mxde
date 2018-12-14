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
 *   File: cxmldocumentfactory.hxx
 *
 * Author: $author$
 *   Date: 11/24/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CXMLDOCUMENTFACTORY_HXX
#define _CXMLDOCUMENTFACTORY_HXX

#include "cdocumentfactory.hxx"

/**
 **********************************************************************
 *  Class: cXMLDocumentFactory
 *
 * Author: $author$
 *   Date: 11/24/2005
 **********************************************************************
 */
class cXMLDocumentFactory
: public cDocumentFactory
{
public:
    typedef cDocumentFactory cIs;

    /**
     **********************************************************************
     * Constructor: cXMLDocumentFactory
     *
     *      Author: $author$
     *        Date: 11/24/2005
     **********************************************************************
     */
    cXMLDocumentFactory() 
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXMLDocumentFactory
     *
     *      Author: $author$
     *        Date: 11/24/2005
     **********************************************************************
     */
    virtual ~cXMLDocumentFactory()
    {
    }
};

#endif /* _CXMLDOCUMENTFACTORY_HXX */
