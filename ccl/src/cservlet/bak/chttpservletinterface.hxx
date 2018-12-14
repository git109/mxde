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
 *   File: chttpservletinterface.hxx
 *
 * Author: $author$
 *   Date: 10/21/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETINTERFACE_HXX
#define _CHTTPSERVLETINTERFACE_HXX

#include "cservletinterface.hxx"
#include "chttpservletrequestinterface.hxx"
#include "chttpservletresponseinterface.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletInterfaceT
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
template <class TAs, class TIs=cServletInterface>
class c_INTERFACE_CLASS cHttpServletInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: CreateHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual TAs* CreateHttpServlet(eError &error) = 0;
    /**
     **********************************************************************
     * Function: DestroyHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError DestroyHttpServlet(TAs& servlet) = 0;
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
    /**
     **********************************************************************
     * Function: DoGet
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoGet
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
    /**
     **********************************************************************
     * Function: DoPut
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoPut
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
    /**
     **********************************************************************
     * Function: DoPost
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoPost
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
    /**
     **********************************************************************
     * Function: DoDelete
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoDelete
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
    /**
     **********************************************************************
     * Function: DoHead
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoHead
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
    /**
     **********************************************************************
     * Function: DoTrace
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoTrace
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) = 0;
};

/**
 **********************************************************************
 *  Class: cHttpServletInterface
 *
 * Author: $author$
 *   Date: 10/21/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cHttpServletInterface
: virtual public cHttpServletInterfaceT<cHttpServletInterface>
{
public:
};

/**
 **********************************************************************
 *  Class: cHttpServletImplementT
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
template 
<class TInterfaceIs=cHttpServletInterface,
 class TIs=cServletImplement>

class cHttpServletImplementT
: virtual public TInterfaceIs,
  virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: CreateHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual TInterfaceIs* CreateHttpServlet(eError &error) 
    {
        TInterfaceIs* servlet = 0;
        error = e_ERROR_NOT_IMPLEMENTED;
        return servlet;
    }
    /**
     **********************************************************************
     * Function: DestroyHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError DestroyHttpServlet(TInterfaceIs& servlet) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int method = request.GetMethod();

        switch(method)
        {
        case cHttpRequestHeaderMethod::e_METHOD_GET:
            error = DoGet(request, response);
            break;

        case cHttpRequestHeaderMethod::e_METHOD_POST:
            error = DoPost(request, response);
            break;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: DoGet
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoGet
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DoPut
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoPut
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DoPost
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoPost
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DoDelete
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoDelete
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DoHead
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoHead
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
    /**
     **********************************************************************
     * Function: DoTrace
     *
     *   Author: $author$
     *     Date: 10/25/2004
     **********************************************************************
     */
    virtual eError DoTrace
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletImplement
 *
 * Author: $author$
 *   Date: 10/25/2004
 **********************************************************************
 */
class cHttpServletImplement
: virtual public cHttpServletImplementT<>
{
public:
};

#endif /* ndef _CHTTPSERVLETINTERFACE_HXX */
