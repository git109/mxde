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
 *   File: cthreadedtcplistener.hxx
 *
 * Author: $author$
 *   Date: 11/3/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CTHREADEDTCPLISTENER_HXX
#define _CTHREADEDTCPLISTENER_HXX

#include "cverboseinterface.hxx"
#include "ctcplistenerinterface.hxx"
#include "ctcpendpoint.hxx"
#include "cinetsocket.hxx"
#include "cmutex.hxx"
#include "cthread.hxx"

/**
 **********************************************************************
 *  Class: cTcpListenerThreadFactoryInterfaceT
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
template <class TIs=cVerboseInterface>
class cTcpListenerThreadFactoryInterfaceT
: virtual public TIs
{
public:
    /**
     **********************************************************************
     * Function: CreateThread
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual cThread* CreateThread
    (cTcpListenerInterface &listener, int id=-1) = 0;
    /**
     **********************************************************************
     * Function: DestroyThread
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError DestroyThread(cThread* thread) = 0;
};

/**
 **********************************************************************
 *  Class: cTcpListenerThreadFactoryInterface
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cTcpListenerThreadFactoryInterface
: virtual public cTcpListenerThreadFactoryInterfaceT<>
{
public:
};

/**
 **********************************************************************
 *  Class: cTcpListenerThreadFactoryImplement
 *
 * Author: $author$
 *   Date: 11/14/2004
 **********************************************************************
 */
class cTcpListenerThreadFactoryImplement
: virtual public cTcpListenerThreadFactoryInterface,
  public cVerboseImplement
{
public:
    typedef cVerboseImplement cIs;

    /**
     **********************************************************************
     * Constructor: cTcpListenerThreadFactoryImplement
     *
     *      Author: $author$
     *        Date: 11/14/2004
     **********************************************************************
     */
    cTcpListenerThreadFactoryImplement
    (cVerboseInterface *verbose=0) 
    : cIs(verbose) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cThreadedTcpListenerT
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
template  
<class TInterfaceIs=cTcpListenerInterface,
 class TIs=cTcpListenerImplement>

class cThreadedTcpListenerT
: virtual public TInterfaceIs,
  public TIs
{
public:
    typedef TIs cIs;

    const char *m_class;

    cTcpEndpoint &m_tcp_endpoint;
    cTcpListenerThreadFactoryInterface &m_thread_factory;
    int m_threads;
    cThread **m_thread;

    cMutex m_accept_mutex;

    /**
     **********************************************************************
     * Constructor: cThreadedTcpListenerT
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cThreadedTcpListenerT
    (cTcpEndpoint &tcp_endpoint, 
     cTcpListenerThreadFactoryInterface &thread_factory, 
     int threads=1, cVerboseInterface *verbose=0) 
    : cIs(verbose),
      m_tcp_endpoint(tcp_endpoint),
      m_thread_factory(thread_factory),
      m_threads(threads),
      m_thread(0),
      m_class("cThreadedTcpListenerT")
    {
    }
    /**
     **********************************************************************
     * Function: Start
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError Start() 
    {
        eError error = e_ERROR_FAILED;
        int thread;

        if (m_thread)
            return e_ERROR_ALREADY_STARTED;

        if (!(error = m_accept_mutex.Create(true)))
        {
            if (m_verbose)
                m_verbose->VerboseFormatted
                ("%s: creating %d threads...\n", m_class, m_threads);

            if ((m_thread = new cThread*[m_threads]))
            {
                for (thread=0; thread<m_threads; thread++)
                {
                    if (m_verbose)
                        m_verbose->VerboseFormatted
                        ("%s: creating thread[%d]...\n", m_class, thread);

                    if (!(m_thread[thread] = m_thread_factory
                        .CreateThread(*this, thread)))
                    {
                        while (thread>0)
                            m_thread_factory.DestroyThread(m_thread[--thread]);
                        break;
                    }
                    if (m_verbose)
                        m_verbose->VerboseFormatted
                        ("%s: ...created thread[%d]\n", m_class, thread);
                }

                if (thread >= m_threads)
                {
                    for (thread=0; thread<m_threads; thread++)
                    {
                        if (m_verbose)
                            m_verbose->VerboseFormatted
                            ("%s: starting thread[%d]...\n", m_class, thread);

                        if ((error = m_thread[thread]->Start()))
                        {
                            while (thread>0)
                            {
                                m_thread[--thread]->Finish();
                                m_thread_factory.DestroyThread(m_thread[thread]);
                            }
                            break;
                        }
                        if (m_verbose)
                            m_verbose->VerboseFormatted
                            ("%s: ...started thread[%d]\n", m_class, thread);
                    }
                    if (thread >= m_threads)
                    {
                        m_accept_mutex.Release();
                        return e_ERROR_NONE;
                    }
                }
                delete m_thread;
                m_thread = 0;
            }
            m_accept_mutex.Close();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Finish
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError Finish() 
    {
        eError error = e_ERROR_FAILED;

        if (!m_thread)
            return e_ERROR_NOT_STARTED;
                    
        for (int threads=m_threads; threads>0; --threads)
        {
            m_thread[threads-1]->Finish();
            m_thread_factory.DestroyThread(m_thread[threads-1]);
        }

        delete m_thread;
        m_thread = 0;
        m_accept_mutex.Close();
        return error;
    }
    /**
     **********************************************************************
     * Function: Accept
     *
     *   Author: $author$
     *     Date: 11/3/2004
     **********************************************************************
     */
    virtual eError Accept
    (cInetSocketInterface &socket) 
    {
        eError error;

        if (m_verbose)
            m_verbose->VerboseFormatted
            ("%s: Accepting connection...\n", m_class);
        
        if (!(error = m_accept_mutex.Acquire()))
        {
            error = m_tcp_endpoint.Accept(socket);
            m_accept_mutex.Release();
        }
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cThreadedTcpListener
 *
 * Author: $author$
 *   Date: 11/3/2004
 **********************************************************************
 */
class cThreadedTcpListener
: public cThreadedTcpListenerT<>
{
public:
    typedef cThreadedTcpListenerT<> cIs;

    /**
     **********************************************************************
     * Constructor: cThreadedTcpListener
     *
     *      Author: $author$
     *        Date: 11/3/2004
     **********************************************************************
     */
    cThreadedTcpListener
    (cTcpEndpoint &tcp_endpoint, 
     cTcpListenerThreadFactoryInterface &thread_factory, 
     int threads=1, cVerboseInterface *verbose=0) 
    : cIs(tcp_endpoint, thread_factory, threads, verbose) 
    {
    }
};

#endif /* ndef _CTHREADEDTCPLISTENER_HXX */
