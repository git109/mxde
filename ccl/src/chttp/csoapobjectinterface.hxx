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
 *   File: csoapobjectinterface.hxx
 *
 * Author: $author$
 *   Date: 1/4/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSOAPOBJECTINTERFACE_HXX
#define _CSOAPOBJECTINTERFACE_HXX

#include "cdocumentprocessor.hxx"

/**
 **********************************************************************
 *  Class: cSOAPObjectInterface
 *
 * Author: $author$
 *   Date: 1/3/2006
 **********************************************************************
 */
class c_INTERFACE_CLASS cSOAPObjectInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: CallMethodByName
     *
     *   Author: $author$
     *     Date: 1/3/2006
     **********************************************************************
     */
    virtual eError CallMethodByName
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& parameter,
     cDocumentProcessorInterface& processor) = 0;
};

/**
 **********************************************************************
 *  Class: cSOAPObjectImplement
 *
 * Author: $author$
 *   Date: 1/3/2006
 **********************************************************************
 */
class cSOAPObjectImplement
: virtual public cSOAPObjectInterface
{
public:
    /**
     **********************************************************************
     * Function: CallMethodByName
     *
     *   Author: $author$
     *     Date: 1/3/2006
     **********************************************************************
     */
    virtual eError CallMethodByName
    (cDocumentNodeListInterface& result,
     cDocumentNodeListInterface& parameter,
     cDocumentProcessorInterface& processor) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

#endif /* _CSOAPOBJECTINTERFACE_HXX */
