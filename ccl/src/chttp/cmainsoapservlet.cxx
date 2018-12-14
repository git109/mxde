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
 *   File: cmainsoapservlet.hxx
 *
 * Author: $author$
 *   Date: 12/31/2005
 *
 *    $Id$
 **********************************************************************
 */

#include "csoapservlet.hxx"
#include "csoapobjectcontainer.hxx"
#include "csoapobjectcontainerinterface.hxx"
#include "csoapobject.hxx"
#include "csoapobjectinterface.hxx"
#include "cverbosewriter.hxx"
#include "cdocumenttoxmlcharprinter.hxx"
#include "ccharwriterstream.hxx"
#include "chttpmainservlet.hxx"
#include "chttpservlet.hxx"
#include "cxmltodocumentparser.hxx"
#include "cdocumentprocessor.hxx"

/**
 **********************************************************************
 *  Class: cMainSOAPServlet
 *
 * Author: $author$
 *   Date: 12/31/2005
 **********************************************************************
 */
class cMainSOAPServlet
: public cHttpMainServlet
{
public:
    typedef cHttpMainServlet cIs;

    cSOAPObjectContainer m_object_container;
    cSOAPServlet m_servlet;

    /**
     **********************************************************************
     * Constructor: cMainSOAPServlet
     *
     *      Author: $author$
     *        Date: 12/31/2005
     **********************************************************************
     */
    cMainSOAPServlet
    (const char* name="soap") 
    : cIs(name),
      m_servlet(m_object_container)
    {
        eError error;

        m_old_http_servlet = GetHttpServlet();

        if ((error = SetHttpServlet(&m_servlet)))
            throw(error);
    }
    /**
     **********************************************************************
     *  Destructor: ~cMainSOAPServlet
     *
     *      Author: $author$
     *        Date: 1/1/2006
     **********************************************************************
     */
    virtual ~cMainSOAPServlet()
    {
        eError error;

        if ((error = SetHttpServlet(m_old_http_servlet)))
            throw(error);
    }
};

cMainSOAPServlet g_main_soap_servlet;
