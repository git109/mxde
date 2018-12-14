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
 *   File: cdocumentimplement.hxx
 *
 * Author: $author$
 *   Date: 11/7/2005
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CDOCUMENTIMPLEMENT_HXX
#define _CDOCUMENTIMPLEMENT_HXX

#include "cdocumentinterface.hxx"
#include "cdocumentartifactimplement.hxx"

/**
 **********************************************************************
 *  Class: cDocumentImplement
 *
 * Author: $author$
 *   Date: 10/15/2005
 **********************************************************************
 */
class cDocumentImplement
: virtual public cDocumentInterface
{
public:
    /**
     **********************************************************************
     * Function: ParseFromStream
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual eError ParseFromStream
    (cCharStreamInterface &stream, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: ParseFromReader
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual eError ParseFromReader
    (cCharReaderInterface &reader, int length=-1) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
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
     * Function: GetNamespaceAttributePrefixCChars
     *
     *   Author: $author$
     *     Date: 11/29/2005
     **********************************************************************
     */
    virtual const cChar* 
    GetNamespaceAttributePrefixCChars(int &length) const 
    {
        const cChar* chars = 0;
        length = 0;
        return chars;
    }
};

#endif /* _CDOCUMENTIMPLEMENT_HXX */
