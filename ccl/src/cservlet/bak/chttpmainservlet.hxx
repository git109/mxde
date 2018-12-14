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
 *   File: chttpmainservlet.hxx
 *
 * Author: $author$
 *   Date: 11/5/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPMAINSERVLET_HXX
#define _CHTTPMAINSERVLET_HXX

#include "chttpservlet.hxx"

/**
 **********************************************************************
 *  Class: cHttpMainServlet
 *
 * Author: $author$
 *   Date: 11/4/2004
 **********************************************************************
 */
class cHttpMainServlet
: public cHttpServlet
{
public:
    typedef cHttpServlet cIs;

    static cHttpServletInterface *m_instance;
    cHttpServletInterface *m_old_instance;

    /**
     **********************************************************************
     * Constructor: cHttpMainServlet
     *
     *      Author: $author$
     *        Date: 11/4/2004
     **********************************************************************
     */
    cHttpMainServlet
    (const char *name, int namelen=-1, 
     bool is_main_instance=false) 
    : cIs(name, namelen),
      m_old_instance(0)
    {
        if (!is_main_instance)
        {
            m_old_instance = m_instance;
            m_instance = this;
        }
    }
    /**
     **********************************************************************
     * Destructor: ~cHttpMainServlet
     *
     *     Author: $author$
     *       Date: 11/8/2004
     **********************************************************************
     */
    virtual ~cHttpMainServlet()
    {
        if (this == m_instance)
            m_instance = m_old_instance;
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

        if (m_instance && (m_instance != this))
            error = m_instance->Init();
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
        eError error = e_ERROR_NONE;

        if (m_instance && (m_instance != this))
            error = m_instance->Final();
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateHttpServlet
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual cHttpServletInterface* 
    CreateHttpServlet(eError &error) 
    {
        cHttpServletInterface* servlet = 0;
        error = e_ERROR_NOT_IMPLEMENTED;

        if (m_instance && (m_instance != this))
            servlet = m_instance->CreateHttpServlet(error);
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
    virtual eError DestroyHttpServlet
    (cHttpServletInterface& servlet) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;

        if (m_instance && (m_instance != this))
            error = m_instance->DestroyHttpServlet(servlet);
        return error;
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual eError Service
    (cHttpServletRequestInterface &request,
     cHttpServletResponseInterface &response) 
    {
        eError error = e_ERROR_NONE;
        cCharWriterInterface &writer = response.GetWriter();

        if (m_instance && (m_instance != this))
            error = m_instance->Service(request, response);

        else
        {
            response.SetStatusOK();
            response.SetContentType("text/plain");
            writer.Write("Servlet instance missing\n");
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: SetServletName
     *
     *   Author: $author$
     *     Date: 12/10/2004
     **********************************************************************
     */
    virtual int SetServletName(const char* chars, int length=-1)
    {
        if (m_instance && (m_instance != this))
            length = m_instance->SetServletName(chars, length);
        else length = cIs::SetServletName(chars, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetServletName
     *
     *   Author: $author$
     *     Date: 11/4/2004
     **********************************************************************
     */
    virtual const char* GetServletName(int &length) const
    {
        const cHttpServletInterface* instance = m_instance;
        const char* chars;
        
        if (instance && (instance != this))
            chars = instance->GetServletName(length);
        else chars = cIs::GetServletName(length);
        return chars;
    }

    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 12/11/2004
     **********************************************************************
     */
    static cHttpServletInterface* GetInstance() 
    {
        return m_instance;
    }
};

#endif /* ndef _CHTTPMAINSERVLET_HXX */
