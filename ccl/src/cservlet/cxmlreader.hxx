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
 *   File: cxmlreader.hxx
 *
 * Author: $author$
 *   Date: 10/3/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CXMLREADER_HXX
#define _CXMLREADER_HXX

#include "ccontenthandler.hxx"
#include "cdtdhandler.hxx"
#include "centityresolver.hxx"
#include "ccharstring.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cXMLReaderInterfaceT
 *
 * Author: $author$
 *   Date: 10/3/2004
 **********************************************************************
 */
template <class TIs=cInterface>
class c_INTERFACE_CLASS cXMLReaderInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: SetContentHandler
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cContentHandlerInterface* SetContentHandler
    (cContentHandlerInterface* contenthandler) = 0;
    /**
     **********************************************************************
     * Function: GetContentHandler
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cContentHandlerInterface* GetContentHandler() = 0;
    /**
     **********************************************************************
     * Function: SetDTDHandler
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cDTDHandlerInterface* SetDTDHandler
    (cDTDHandlerInterface* dtdhandler) = 0;
    /**
     **********************************************************************
     * Function: GetDTDHandler
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cDTDHandlerInterface* GetDTDHandler() = 0;
    /**
     **********************************************************************
     * Function: SetEntityResolver
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cEntityResolverInterface* SetEntityResolver
    (cEntityResolverInterface* entityresolver) = 0;
    /**
     **********************************************************************
     * Function: GetEntityResolver
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cEntityResolverInterface* GetEntityResolver() = 0;
    /**
     **********************************************************************
     * Function: SetErrorHandler
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cErrorHandlerInterface* SetErrorHandler
    (cErrorHandlerInterface* errorhandler) = 0;
    /**
     **********************************************************************
     * Function: GetErrorHandler
     *
     *   Author: $author$
     *     Date: 10/3/2004
     **********************************************************************
     */
    virtual cErrorHandlerInterface* GetErrorHandler() = 0;
};

#endif /* ndef _CXMLREADER_HXX */
