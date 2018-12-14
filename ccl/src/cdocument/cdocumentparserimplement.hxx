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
 *   File: cdocumentparserimplement.hxx
 *
 * Author: $author$
 *   Date: 11/8/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTPARSERIMPLEMENT_HXX
#define _CDOCUMENTPARSERIMPLEMENT_HXX

#include "cdocumentparserinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentParserImplement
 *
 * Author: $author$
 *   Date: 11/5/2005
 **********************************************************************
 */
class cDocumentParserImplement
: virtual public cDocumentParserInterface
{
public:
    /**
     **********************************************************************
     * Function: GetEvent
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentEventInterface& GetEvent() const 
    {
        return cDocumentEventInterface::GetNullEvent();
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
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetFactory() const 
    {
        return cDocumentFactoryInterface::GetNullFactory();
    }

    /**
     **********************************************************************
     * Function: ParseFile
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual eError ParseFile
    (const char* filename, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseLocation
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual eError ParseLocation
    (const char* uri, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseStream
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual eError ParseStream
    (cCharStreamInterface &stream, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseReader
     *
     *   Author: $author$
     *     Date: 11/5/2005
     **********************************************************************
     */
    virtual eError ParseReader
    (cCharReaderInterface &reader, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CDOCUMENTPARSERIMPLEMENT_HXX */
