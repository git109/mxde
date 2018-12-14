/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cdocumentinterface.hxx
 *
 * Author: $author$
 *   Date: 10/9/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTINTERFACE_HXX
#define _CDOCUMENTINTERFACE_HXX

#include "cdocumentartifactinterface.hxx"
#include "ccharstreaminterface.hxx"
#include "ccharreaderinterface.hxx"
#include "cdocumentparserinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentInterface
 *
 * Author: $author$
 *   Date: 10/15/2005
 **********************************************************************
 */
class c_INTERFACE_CLASS cDocumentInterface
: virtual public cDocumentNodeListInterface
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
    (cCharStreamInterface &stream, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: ParseFromReader
     *
     *   Author: $author$
     *     Date: 11/7/2005
     **********************************************************************
     */
    virtual eError ParseFromReader
    (cCharReaderInterface &reader, int length=-1) = 0;
    /**
     **********************************************************************
     * Function: AsDocument
     *
     *   Author: $author$
     *     Date: 10/15/2005
     **********************************************************************
     */
    virtual cDocument& AsDocument() = 0;
    /**
     **********************************************************************
     * Function: GetFactory
     *
     *   Author: $author$
     *     Date: 11/24/2005
     **********************************************************************
     */
    virtual cDocumentFactoryInterface& GetFactory() const = 0;
    /**
     **********************************************************************
     * Function: GetParser
     *
     *   Author: $author$
     *     Date: 11/26/2005
     **********************************************************************
     */
    virtual cDocumentParserInterface& GetParser() const = 0;
    /**
     **********************************************************************
     * Function: GetNamespaceAttributePrefixCChars
     *
     *   Author: $author$
     *     Date: 11/29/2005
     **********************************************************************
     */
    virtual const cChar* 
    GetNamespaceAttributePrefixCChars(int &length) const = 0;
};

#endif /* _CDOCUMENTINTERFACE_HXX */
