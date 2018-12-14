/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: chttprequestheader.hxx
 *
 * Author: $author$
 *   Date: 2/5/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPREQUESTHEADER_HXX
#define _CHTTPREQUESTHEADER_HXX

#include "chttprequestheadermethod.hxx"
#include "chttprequestheaderpath.hxx"
#include "chttpheaderversion.hxx"
#include "chttpheaderfield.hxx"

/**
 **********************************************************************
 *  Class: cHttpRequestHeader
 *
 * Author: $author$
 *   Date: 2/5/2006
 **********************************************************************
 */
class cHttpRequestHeader
{
public:
    cHttpRequestHeaderMethod m_method;
    cHttpRequestHeaderPath m_path;
    cHttpHeaderVersion m_version;
    cHttpHeaderFieldList m_field_list;

    /**
     **********************************************************************
     * Constructor: cHttpRequestHeader
     *
     *      Author: $author$
     *        Date: 2/5/2006
     **********************************************************************
     */
    cHttpRequestHeader
    (cHttpHeaderFieldListEvent& event) 
    : m_field_list(event)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cHttpRequestHeader
     *
     *      Author: $author$
     *        Date: 2/14/2006
     **********************************************************************
     */
    virtual ~cHttpRequestHeader()
    {
        eError error;

        if ((error = m_field_list.Clear()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/1/2006
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;

        if (!(error = m_method.Initialize()))
        if (!(error = m_path.Initialize()))
        if (!(error = m_version.Initialize()))
        if (!(error = m_field_list.Clear()))
        {
        }
        return error;
    }
};

#endif /* _CHTTPREQUESTHEADER_HXX */


