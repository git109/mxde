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
 *   File: chttpservlettcplistenerthread.hxx
 *
 * Author: $author$
 *   Date: 11/3/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CHTTPSERVLETTCPLISTENERTHREAD_HXX
#define _CHTTPSERVLETTCPLISTENERTHREAD_HXX

#include "cverboseinterface.hxx"
#include "cthreadedtcplistener.hxx"
#include "chttpservlet.hxx"
#include "chttp11processor.hxx"
#include "chttp11connectionhandler.hxx"

/**
 **********************************************************************
 *  Class: cHttpServletTcpListenerThread
 *
 * Author: $author$
 *   Date: 11/15/2004
 **********************************************************************
 */
class cHttpServletTcpListenerThread
: public cThread
{
public:
    typedef cThread cIs;

    const char *m_class;

    cVerboseInterface *m_verbose;
    cTcpListenerInterface &m_listener;
    cHttpServletInterface &m_servlet;
    cTcpConnection m_connection;
    cHttp11Processor m_connection_processor;
    cHttp11ConnectionHandler m_connection_handler;
    cInetSocket m_socket;
    int m_id;

    /**
     **********************************************************************
     * Constructor: cHttpServletTcpListenerThread
     *
     *      Author: $author$
     *        Date: 11/15/2004
     **********************************************************************
     */
    cHttpServletTcpListenerThread
    (cTcpListenerInterface &listener, 
     cHttpServletInterface &servlet,
     int id=-1, cVerboseInterface *verbose=0) 
    : m_verbose(verbose),
      m_listener(listener),
      m_servlet(servlet),
      m_connection_processor
      (m_connection, m_servlet, verbose),
      m_connection_handler
      (m_connection, m_connection_processor),
      m_id(id),
      m_class("cHttpServletTcpListenerThread") 
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual void OnRun() 
    {
        eError error, error2;

        do
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: Thread[%d] accepting connection...\n", m_class, m_id);

            if (!(error = m_listener.Accept(m_socket)))
            {
                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: ...Thread[%d] accepted connection\n", m_class, m_id);

                error = m_connection_handler
                .ProcessConnection(m_socket);

                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: Thread[%d] closing connection\n", m_class, m_id);

                if ((error2 = m_socket.Shutdown()))
                if (e_ERROR_NOT_ATTACHED != error2)
                if (!error)
                    error = error2;

                if ((error2 = m_socket.Close()))
                if (e_ERROR_NOT_ATTACHED != error2)
                if (!error)
                    error = error2;
            }
        }
        while(!error);
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletTcpListenerThreadFactory
 *
 * Author: $author$
 *   Date: 11/15/2004
 **********************************************************************
 */
class cHttpServletTcpListenerThreadFactory
: virtual public cTcpListenerThreadFactoryInterface,
  public cTcpListenerThreadFactoryImplement
{
public:
    typedef cTcpListenerThreadFactoryImplement cIs;

    cHttpServletInterface &m_servlet;

    /**
     **********************************************************************
     * Constructor: cHttpServletTcpListenerThreadFactory
     *
     *      Author: $author$
     *        Date: 11/15/2004
     **********************************************************************
     */
    cHttpServletTcpListenerThreadFactory
    (cHttpServletInterface &servlet,
     cVerboseInterface *verbose=0)
    : cIs(verbose),
      m_servlet(servlet)
    {
    }
    /**
     **********************************************************************
     * Function: CreateThread
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual cThread* CreateThread
    (cTcpListenerInterface &listener, int id=-1)
    {
        cThread *thread = 0;
        cHttpServletInterface *servlet;
        eError error;
        
        if ((servlet = m_servlet.CreateHttpServlet(error)))
        if (!(thread = new cHttpServletTcpListenerThread
            (listener, *servlet, id, m_verbose)))
            m_servlet.DestroyHttpServlet(*servlet);

        return thread;
    }
    /**
     **********************************************************************
     * Function: DestroyThread
     *
     *   Author: $author$
     *     Date: 11/15/2004
     **********************************************************************
     */
    virtual eError DestroyThread(cThread* thread)
    {
        eError error = e_ERROR_NONE;
        delete thread;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletTcpListenerThreadT
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
template <class THttpServlet=cHttpServlet>

class cHttpServletTcpListenerThreadT
: public cThread
{
public:
    typedef cThread cIs;

    const char *m_class;

    cVerboseInterface *m_verbose;
    cTcpListenerInterface &m_listener;
    THttpServlet m_servlet;
    cTcpConnection m_connection;
    cHttp11Processor m_connection_processor;
    cHttp11ConnectionHandler m_connection_handler;
    cInetSocket m_socket;
    int m_id;

    /**
     **********************************************************************
     * Constructor: cHttpServletTcpListenerThreadT
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cHttpServletTcpListenerThreadT
    (cTcpListenerInterface &listener, 
     int id=-1, cVerboseInterface *verbose=0) 
    : m_verbose(verbose),
      m_servlet(verbose),
      m_listener(listener),
      m_connection_processor
      (m_connection, m_servlet, verbose),
      m_connection_handler
      (m_connection, m_connection_processor),
      m_id(id),
      m_class("cHttpServletTcpListenerThreadT")
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual void OnRun() 
    {
        eError error, error2;

        do
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: Thread[%d] accepting connection...\n", m_class, m_id);

            if (!(error = m_listener.Accept(m_socket)))
            {
                if (m_verbose)
                    m_verbose->VerboseFormatted
                    ("%s: ...Thread[%d] accepted connection\n", m_class, m_id);

                error = m_connection_handler
                .ProcessConnection(m_socket);

                if ((error2 = m_socket.Shutdown()))
                if (e_ERROR_NOT_ATTACHED != error2)
                if (!error)
                    error = error2;

                if ((error2 = m_socket.Close()))
                if (e_ERROR_NOT_ATTACHED != error2)
                if (!error)
                    error = error2;
            }
        }
        while(!error);
    }
};

/**
 **********************************************************************
 *  Class: cHttpServletTcpListenerThreadFactoryT
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
template 
<class THttpServletTcpListenerThread
 =cHttpServletTcpListenerThreadT<> >

class cHttpServletTcpListenerThreadFactoryT
: virtual public cTcpListenerThreadFactoryInterface,
  public cTcpListenerThreadFactoryImplement
{
public:
    typedef cTcpListenerThreadFactoryImplement cIs;

    /**
     **********************************************************************
     * Constructor: cHttpServletTcpListenerThreadFactoryT
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cHttpServletTcpListenerThreadFactoryT
    (cVerboseInterface *verbose=0)
    : cIs(verbose)
    {
    }
    /**
     **********************************************************************
     * Function: CreateThread
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual cThread* CreateThread
    (cTcpListenerInterface &listener, int id=-1)
    {
        cThread *thread = new 
        THttpServletTcpListenerThread(listener, id, m_verbose);
        return thread;
    }
    /**
     **********************************************************************
     * Function: DestroyThread
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError DestroyThread(cThread* thread)
    {
        eError error = e_ERROR_NONE;
        delete thread;
        return error;
    }
};

#endif /* ndef _CHTTPSERVLETTCPLISTENERTHREAD_HXX */
