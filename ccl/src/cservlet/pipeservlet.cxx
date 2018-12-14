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
 *   File: pipeservlet.cxx
 *
 * Author: $author$
 *   Date: 11/5/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cpipehttpservlet.hxx"
#include "chttpmainservlet.hxx"

/**
 **********************************************************************
 *  Class: cPipeServlet
 *
 * Author: $author$
 *   Date: 11/5/2004
 **********************************************************************
 */
class cPipeServlet
: public cHttpMainServlet
{
public:
    typedef cHttpMainServlet cIs;

    cPipeHttpServlet m_pipe_servlet;

    /**
     **********************************************************************
     * Constructor: cPipeServlet
     *
     *      Author: $author$
     *        Date: 11/5/2004
     **********************************************************************
     */
    cPipeServlet(const char *name="pipe")
    : cIs(name),
      m_pipe_servlet(name, "servlet")
    {
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/5/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = m_pipe_servlet.Service(request, response);
        return error;
    }
} g_pipe_servlet;
