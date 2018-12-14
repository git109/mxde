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
 *   File: inet.cxx
 *
 * Author: $author$
 *   Date: 10/13/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "chttpservlettcplistenerthread.hxx"
#include "cthreadedtcplistener.hxx"
#include "cmutex.hxx"
#include "chttprouterservlet.hxx"
#include "chttp11processor.hxx"
#include "chttp11connectionhandler.hxx"
#include "ctcplistener.hxx"
#include "ctcpendpoint.hxx"
#include "cinetendpoint.hxx"
#include "cinetsocket.hxx"
#include "cinetsocketinterface.hxx"
#include "copenedinterface.hxx"
#include "csocketattachedinterface.hxx"
#include "cinetsocketaddress.hxx"
#include "csocketaddress.hxx"
#include "cinetaddress.hxx"
#include "csockets.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Main: cINetMain
 *
 * Author: $author$
 *   Date: 10/13/2004
 **********************************************************************
 */
class cINetMain
: public cMain
{
public:
    typedef cMain cIs;

    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 10/13/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        int port=8080;
        const char *host="localhost";
        int status=cHttpResponseHeaderStatus::e_STATUS_FILE_NOT_FOUND;
        eError error;
        int length;
        BYTE buffer[1024];

        if (!(error = cSockets::Initialize()))
        {
            cInetAddress a(host);
            cTcpEndpoint e(a, port);
            cTcpConnection c;
            cHttpRouterServlet servlet;
            cHttp11Processor processor(c, servlet);
            cHttp11ConnectionHandler h(c, processor);
            cTcpListener l(e, h);
            cHttpServletTcpListenerThreadFactory f;
            cThreadedTcpListener tl(e, f, 1);

            e.SetListener(&tl);

            if (!(error = e.InitEndpoint()))
            {
                if (!(error = e.StartEndpoint()))
                {
                    e.FinishEndpoint();
                }
                e.FinalEndpoint();
            }

            return 0;

            cInetSocketAddress sa(a, port);
            cInetSocket s;

            if (!(error = s.Open()))
            {
                if (!(error = s.Connect(sa)))
                {
                    cOutputStreamInterface &o=s.GetOutputStream();
                    cInputStreamInterface &i=s.GetInputStream();

                    if (0 < (length = o.Write((BYTE*)"Get / HTTP/1.1\nAccept: */*\nHost: localhost:8080\n\n")))
                    while (0 < (length = i.Read(buffer, sizeof(buffer)-1)))
                    {
                        buffer[length] = 0;
                        printf("%s", buffer);
                    }
                }
                s.Close();
            }
            cSockets::Finalize();
        }
        return 0;
    }
} g_inet;

