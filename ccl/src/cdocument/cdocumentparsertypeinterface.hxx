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
 *   File: cdocumentparsertypeinterface.hxx
 *
 * Author: $author$
 *   Date: 11/25/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPARSERTYPEINTERFACE_HXX
#define _CDOCUMENTPARSERTYPEINTERFACE_HXX

#include "cdocumentparserinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentParserTypeInterface
 *
 * Author: $author$
 *   Date: 11/5/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentParserTypeInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: GetParser
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual cDocumentParserInterface* GetParser() = 0;
    /**
     **********************************************************************
     * Function: FreeParser
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual eError FreeParser(cDocumentParserInterface& parser) = 0;
};

/**
 **********************************************************************
 *  Class: cDocumentParserTypeImplement
 *
 * Author: $author$
 *   Date: 11/5/2005
 **********************************************************************
 */
class cDocumentParserTypeImplement
: virtual public cDocumentParserTypeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetParser
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual cDocumentParserInterface* GetParser() 
    {
        cDocumentParserInterface* parser = 0;
        return parser;
    }
    /**
     **********************************************************************
     * Function: FreeParser
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual eError FreeParser(cDocumentParserInterface& parser) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CDOCUMENTPARSERTYPEINTERFACE_HXX */
