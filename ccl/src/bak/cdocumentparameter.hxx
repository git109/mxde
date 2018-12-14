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
 *   File: cdocumentparameter.hxx
 *
 * Author: $author$
 *   Date: 1/31/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CDOCUMENTPARAMETER_HXX
#define _CDOCUMENTPARAMETER_HXX

#include "ccharbufferparameter.hxx"
#include "cdocumentinterface.hxx"

/**
 **********************************************************************
 *  Class: cDocumentParameter
 *
 * Author: $author$
 *   Date: 1/31/2004
 **********************************************************************
 */
class cDocumentParameter
: public cCharBufferParameterT<cDocumentParameter>
{
public:
    typedef cCharBufferParameterT<cDocumentParameter> cIs;

    /**
     **********************************************************************
     * Constructor: cDocumentParameter
     *
     *      Author: $author$
     *        Date: 1/31/2004
     **********************************************************************
     */
    cDocumentParameter(const char *name, const char *&value) 
    : cIs(this, name, value) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cDocumentParameter
     *
     *      Author: $author$
     *        Date: 1/31/2004
     **********************************************************************
     */
    cDocumentParameter(const char *name) 
    : cIs(this, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnElement
     *
     *   Author: $author$
     *     Date: 1/31/2004
     **********************************************************************
     */
    virtual eError OnElement(cElementInterface &element)
    {
        eError error = e_ERROR_FAILED;
        int count;

        if (!(error = ClearValue()))
        if (0 <= (count = element->PutTextToStream(*this)))
            error = UpdateValue();

        return error;
    }
};

#endif /* ndef _CDOCUMENTPARAMETER_HXX */
