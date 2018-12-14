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
 *   File: routerservlet.cxx
 *
 * Author: $author$
 *   Date: 11/11/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpservletroute.hxx"
#include "chttprouterservlet.hxx"
#include "cpipehttpservlet.hxx"
#include "chttpmainservlet.hxx"

/**
 **********************************************************************
 *  Class: cRouterServlet
 *
 * Author: $author$
 *   Date: 11/11/2004
 **********************************************************************
 */
class cRouterServlet
: public cHttpMainServlet
{
public:
    typedef cHttpMainServlet cIs;

    cHttpRouterServlet m_servlet;

    /**
     **********************************************************************
     * Constructor: cRouterServlet
     *
     *      Author: $author$
     *        Date: 11/11/2004
     **********************************************************************
     */
    cRouterServlet(const char *name="router")
    : cIs(name)
    {
    }
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual eError Init() 
    {
        eError error = e_ERROR_NONE;
        cHttpServletRouteItem *item;

        if (!(error = m_servlet.Init()))
        if ((item = cHttpServletRoute::m_list.GetFirst()))
        do
        {
            if ((error = item->m_servlet.Init()))
            {
                while ((item = item->GetPrevious()))
                {
                    item->m_servlet.Final();
                    m_servlet.DeleteServlet(item->m_servlet);
                }
                break;
            }
            m_servlet.InsertServlet(item->m_servlet);
        }
        while ((item = item->GetNext()));
        return error;
    }
    /**
     **********************************************************************
     * Function: Final
     *
     *   Author: $author$
     *     Date: 11/12/2004
     **********************************************************************
     */
    virtual eError Final() 
    {
        eError error2,error = e_ERROR_NONE;
        cHttpServletRouteItem *item;

        if ((item = cHttpServletRoute::m_list.GetLast()))
        do
        {
            if ((error2 = item->m_servlet.Final()))
            if (!error)
                error = error2;

            m_servlet.DeleteServlet(item->m_servlet);
        }
        while ((item = item->GetPrevious()));

        if ((error2 = m_servlet.Final()))
        if (!error)
            error = error2;

        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/11/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = m_servlet.Service(request, response);
        return error;
    }
} g_router_servlet;

cHttpServletRouteItem *cHttpServletRouteList::m_first = 0;
cHttpServletRouteItem *cHttpServletRouteList::m_last = 0;
cHttpServletRouteList cHttpServletRoute::m_list;

/**
 **********************************************************************
 *  Class: cPipeServletRoute
 *
 * Author: $author$
 *   Date: 11/13/2004
 **********************************************************************
 */
class cPipeServletRoute
: public cHttpServletRoute
{
public:
    typedef cHttpServletRoute cIs;

    cPipeHttpServlet m_servlet;

    /**
     **********************************************************************
     * Constructor: cPipeServletRoute
     *
     *      Author: $author$
     *        Date: 11/13/2004
     **********************************************************************
     */
    cPipeServletRoute
    (const char *name, const char *command) 
    : cIs(name),
      m_servlet(name, command)
    {
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/13/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = m_servlet.Service(request, response);
        return error;
    }
};

cPipeServletRoute g_t_servlet("t", "tservlet");
cPipeServletRoute g_dt_servlet("dt", "dtservlet");
cPipeServletRoute g_xalan_servlet("xalan", "xalanservlet");
