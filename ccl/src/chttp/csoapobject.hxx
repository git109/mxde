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
 *   File: csoapobject.hxx
 *
 * Author: $author$
 *   Date: 1/4/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CSOAPOBJECT_HXX
#define _CSOAPOBJECT_HXX

#include "csoapobjectinterface.hxx"

/**
 **********************************************************************
 *  Class: cSOAPObject
 *
 * Author: $author$
 *   Date: 1/3/2006
 **********************************************************************
 */
class cSOAPObject
: virtual public cSOAPObjectImplement,
  public cInstance
{
public:
    typedef cInstance cIs;
    /**
     **********************************************************************
     * Constructor: cSOAPObject
     *
     *      Author: $author$
     *        Date: 1/3/2006
     **********************************************************************
     */
    cSOAPObject() 
    {
    }
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
        cCCharBuffer text("Value");
        cDocumentTextInterface* node;

        node = result.AddText(error, text);
        return error;
    }
};

#endif /* _CSOAPOBJECT_HXX */
