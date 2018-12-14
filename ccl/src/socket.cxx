/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: socket.cxx
 *
 * Author: $author$
 *   Date: 10/25/2003
 *
 *    $Id$
 **********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#include "csocket.hxx"
#include "ccharbuffer.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cMySocket
 *
 * Author: $author$
 *   Date: 4/17/2004
 **********************************************************************
 */
class cMySocket
: public cSocket
{
public:
    typedef cSocket cIs;

    /**
     **********************************************************************
     * Constructor: cMySocket
     *
     *      Author: $author$
     *        Date: 4/17/2004
     **********************************************************************
     */
    cMySocket(SOCKET handle = INVALID_SOCKET)
    : cIs(handle) 
    {
    }
    /**
     **********************************************************************
     * Function: On_gethostbyname_Error
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError On_gethostbyname_Error
    (int err, const char *host) const
    {
        printf
        ("On_gethostbyname_Error(%d, \"%s\")\n", err, host);
        return cIs::On_gethostbyname_Error(err, host);
    }
    /**
     **********************************************************************
     * Function: On_bind_Error
     *
     *   Author: $author$
     *     Date: 4/17/2004
     **********************************************************************
     */
    virtual eError On_bind_Error
    (int err, SOCKET socket, 
     struct sockaddr *addr, socklen_t addrlen) const
    {
        printf
        ("On_bind_Error(%d, %x, %x, %d)\n",
         err, socket, addr, addrlen);

        return cIs::On_bind_Error
        (err, socket, addr, addrlen);
    }
};

/**
 **********************************************************************
 *  Class: cSocketMain
 *
 * Author: $author$
 *   Date: 10/25/2003
 **********************************************************************
 */
class cSocketMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_listen;
    bool m_send;
    bool m_receive;
    const char *m_host;
    int m_port;
    int m_message_length;
    const char *m_message;
    cCharBuffer m_message_buffer;
    cCharBuffer m_response_buffer;
    const char *m_capture_filename;
    cCharFile m_capture_file;
    cMySocket m_socket;

    /**
     **********************************************************************
     * Constructor: cSocketMain
     *
     *      Author: $author$
     *        Date: 10/25/2003
     **********************************************************************
     */
    cSocketMain() 
    : m_listen(false),
      m_send(false),
      m_receive(false),
      m_host("localhost"),
      m_port(777),
      m_message("GET / HTTP/1.1\n\n"),
      m_capture_filename(0)
    {
        m_message_length = strlen(m_message);
    }

    /**
     **********************************************************************
     * Function: OnAccept
     *
     *   Author: $author$
     *     Date: 3/9/2004
     **********************************************************************
     */
    virtual int OnAccept(cSocket &socket)
    {
        char *buffer;
        int size,length;

        if ((buffer = m_message_buffer.GetWriteBuffer(size, length)))
        {
            while (0 < (length = socket.Read(buffer, size-1)))
            {
                m_message_buffer.SetLength(length);

                printf("%s", buffer);

                if (m_capture_file.GetIsOpen())
                {
                    m_capture_file.Write(buffer, length);
                    m_capture_file.Flush();
                }
            }
        }

        return 0;
    }

    /**
     **********************************************************************
     * Function: OnConnect
     *
     *   Author: $author$
     *     Date: 6/6/2004
     **********************************************************************
     */
    virtual int OnConnect(int argc, char **argv)
    {
        eError error;

        printf
        ("Connecting to host \"%s\" port %d...\n",
         m_host, m_port);

        if ((error = m_socket.Connect(m_host, m_port)))
            printf
            ("Unable to connect to host \"%s\" port %d\n",
             m_host, m_port);
        else
        {
            printf
            ("Connected to host \"%s\" port %d\n",
             m_host, m_port);

            if (m_send)
            {
                printf
                ("Sending message \"%s\"[%d]...\n", 
                 m_message, m_message_length);

                m_socket.Write(m_message, m_message_length);
            }

            if (m_receive)
            {
                char *buffer;
                int size,length;

                if ((buffer = m_response_buffer.GetWriteBuffer(size, length)))
                {
                    while (0 < (length = m_socket.Read(buffer, size-1)))
                    {
                        m_response_buffer.SetLength(length);

                        printf("%s", buffer);

                        if (m_capture_file.GetIsOpen())
                        {
                            m_capture_file.Write(buffer, length);
                            m_capture_file.Flush();
                        }
                    }
                }
            }
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnListen
     *
     *   Author: $author$
     *     Date: 6/6/2004
     **********************************************************************
     */
    virtual int OnListen(int argc, char **argv)
    {
        eError error;

        printf
        ("Listening at host \"%s\" port %d...\n",
         m_host, m_port);

        if ((error = m_socket.Bind(m_host, m_port)))
            printf
            ("Unable to bind to host \"%s\" port %d\n",
             m_host, m_port);

        else if ((error = m_socket.Listen()))
                printf
                ("Unable to listen at host \"%s\" port %d\n",
                 m_host, m_port);
        else
        {
            cMySocket socket;

            do
            {
                if ((error = m_socket.Accept(socket)))
                    printf
                    ("Unable to accept connection at host \"%s\" port %d\n",
                     m_host, m_port);
                else
                {
                    printf
                    ("Accepted connection at host \"%s\" port %d\n"
                     " from host \"%s\" port %d...\n\n",
                     m_host, m_port, socket.GetHost(), socket.GetPort());

                    OnAccept(socket);

                    printf
                    ("\n\n...Closing connection at host \"%s\" port %d\n"
                     " from host \"%s\" port %d\n\n",
                     m_host, m_port, socket.GetHost(), socket.GetPort());
                    socket.Close();
                }
            }
            while (!error);
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 10/27/2003
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        eError error;

        if ((error = m_socket.Create()))
            printf("Unable to create socket\n");
        else
        {
            if (m_listen)
                OnListen(argc, argv);
            else OnConnect(argc, argv);

            m_socket.Close();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 10/25/2003
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        eError error;

        if (!strcmp(arg,"l"))
            m_listen = true;

        else if (!strcmp(arg,"c"))
                m_listen = false;

        else if (!strcmp(arg,"s"))
                m_send = true;

        else if (!strcmp(arg,"r"))
                m_receive = true;

        else if (argn < argc)
        {
            if (!strcmp(arg,"h"))
            {
                if (!strcmp("*", m_host = argv[++argn]))
                    m_host = "";
            }
            else if (!strcmp(arg,"p"))
                    m_port = atoi(argv[++argn]);

            else if (!strcmp(arg,"m"))
            {
                if ((m_message = argv[++argn]))
                if (0 < (m_message_length = m_message_buffer.Copy(m_message)))
                if (!(m_message = m_message_buffer.GetBuffer(m_message_length)))
                {
                    m_message = "";
                    m_message_length = 0;
                }
            }
            else if (!strcmp(arg,"f"))
            {
                if ((m_capture_filename = argv[++argn]))
                {
                    if ((error = m_capture_file.Open(m_capture_filename, "wb")))
                        printf("Unable to open file \"%s\"\n", m_capture_filename);
                }
            }
        }
        return argn;
    }
} g_socket_main;
