///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Hello.hpp
///
/// Author: $author$
///   Date: Aug 18, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_HELLO_HPP_
#define _XOS_HELLO_HPP_

#include "xos/os/Main.hpp"
#include "xos/os/os/Mutex.hpp"
#include "xos/os/os/Semaphore.hpp"
#include "xos/os/os/Thread.hpp"
#include "xos/os/os/Process.hpp"
#include "xos/network/Sockets.hpp"
#include "xos/base/Locker.hpp"
#include <sstream>
#include <queue>

#define XOS_HELLO_2STRING_(value) #value
#define XOS_HELLO_2STRING(value) XOS_HELLO_2STRING_(value)

#define XOS_HELLO_DEFAULT_HELLO "Hello"
#define XOS_HELLO_DEFAULT_BYE "Bye"

#define XOS_HELLO_DEFAULT_PORTNO 7000
#define XOS_HELLO_DEFAULT_PORT "" XOS_HELLO_2STRING(XOS_HELLO_DEFAULT_PORTNO) ""
#define XOS_HELLO_DEFAULT_HOST "localhost"

#define XOS_HELLO_DEFAULT_THREADSNO 0
#define XOS_HELLO_DEFAULT_THREADS "" XOS_HELLO_2STRING(XOS_HELLO_DEFAULT_THREADSNO) ""

#define XOS_HELLO_DEFAULT_TRANSPORT "t"
#define XOS_HELLO_DEFAULT_FAMILY "4"

namespace xos {

typedef Main HelloExtend;

class Hello: public HelloExtend {
public:
    typedef HelloExtend Extends;
    typedef Hello Derives;
    typedef int (Derives::*Runner)(int argc, char** argv, char** env);
    typedef network::Endpoint* (Derives::*Endpoint)(const char* host, u_short port);

    class _EXPORT_CLASS TcpConnections {
    public:
        TcpConnections(network::Socket* s) {
            Queue(s);
        }
        TcpConnections(){}
        virtual ~TcpConnections() {
            Locker<Mutex> l(m_lock);
            while (0 < (m_queue.size())) {
                network::Socket* c = 0;
                if ((c = m_queue.front())) {
                    c->Shutdown();
                    network::Socket::Delete(c);
                }
                m_queue.pop();
            }
        }

        virtual void Queue(network::Socket* s) {
            Locker<Mutex> l(m_lock);
            m_queue.push(s);
            XOS_LOG_TRACE("queued socket...");
            m_signal.Continue();
        }
        virtual network::Socket* Dequeue() {
            network::Socket* s = 0;
            if ((m_signal.Wait())) {
                Locker<Mutex> l(m_lock);
                if (0 < (m_queue.size())) {
                    s = m_queue.front();
                    m_queue.pop();
                    XOS_LOG_TRACE("...dequeued socket");
                }
            }
            return s;
        }
    protected:
        os::Mutex m_lock;
        os::Semaphore m_signal;
        std::queue<network::Socket*> m_queue;
    };

    class _EXPORT_CLASS ServiceTcp: public Thread::Run {
    public:
        ServiceTcp
        (TcpConnections& connections)
        : m_connections(connections),
          m_recvdBye(false), 
          m_bye(XOS_HELLO_DEFAULT_BYE) {
        }
        bool RecvdBye() const { return m_recvdBye; }
        virtual void operator()() {
            network::Socket* c = 0;
            XOS_LOG_TRACE("dequeue socket...");
            if ((c = m_connections.Dequeue())) {
                ssize_t count = 0;
                XOS_LOG_TRACE("...dequeued socket");
                if (0 < (count = c->Recv(m_buf, sizeof(m_buf)-1, 0))) {
                    m_buf[count] = 0;
                    printf("--->\n%s\n<---\n", m_buf);
                    if (m_recvdBye = (m_buf == (strstr(m_buf, m_bye.c_str())))) {
                        XOS_LOG_INFO("...received \"" << m_bye << "\"");
                    }
                }
                c->Shutdown();
                network::Socket::Delete(c);
            }
        }
    protected:
        TcpConnections& m_connections;
        bool m_recvdBye;
        std::string m_bye;
        char m_buf[4096];
    };

    Hello()
    : m_runner(0),
      m_waitIsTrue(false),
      m_processIsNative(false),
      m_threadsNo(XOS_HELLO_DEFAULT_THREADSNO),
      m_threads(XOS_HELLO_DEFAULT_THREADS),
      m_transport(XOS_HELLO_DEFAULT_TRANSPORT),
      m_family(XOS_HELLO_DEFAULT_FAMILY),
      m_hello(XOS_HELLO_DEFAULT_HELLO),
      m_bye(XOS_HELLO_DEFAULT_BYE),
      m_host(XOS_HELLO_DEFAULT_HOST), 
      m_port(XOS_HELLO_DEFAULT_PORT),
      m_portNo(XOS_HELLO_DEFAULT_PORTNO) {}

    virtual int Run(int argc, char** argv, char** env) { 
        printf("%s %s\n", m_hello.c_str(), (optind<argc)?(argv[optind]):(""));
        if ((m_runner)) {
            (this->*m_runner)(argc, argv, env);
        }
        return 0; 
    }
    virtual int BeforeRun(int argc, char** argv, char** env) { 
        network::Sockets::Startup();
        return 0; 
    }
    virtual int AfterRun(int argc, char** argv, char** env) { 
        network::Sockets::Cleanup();
        return 0; 
    }

    //
    // Start
    //
    virtual int RunStart(int argc, char** argv, char** env) { 
        char* argV[] = {
            argv[0],
            "-o",
            (char*)(m_host.c_str()),
            "-p",
            (char*)(m_port.c_str()),
            "-t",
            (char*)(m_threads.c_str()),
            "-s",
            (char*)(m_transport.c_str()),
            "-a",
            (char*)(m_family.c_str()),
            argv[optind],
            0};
            if ((m_processIsNative)) {
                os::Process p(argv[0], argV);
                if (!(m_waitIsTrue)) {
                    p.Separate(); }
            } else {
                os::crt::Process p(argv[0], argV);
                if (!(m_waitIsTrue)) {
                    p.Separate(); }
            }
        return 0; 
    }

    //
    // TCP
    //
    virtual int RunTcpClient(int argc, char** argv, char** env) { 
        network::Endpoint* ep = ClientEndpoint(m_host.c_str(), m_portNo);
        network::Socket* s = 0;
        if (s = (network::Socket::New(ep->GetFamily(), network::ip::tcp::Transport::Type, network::ip::tcp::Transport::Protocol))) {
            if ((s->Connect(ep->SocketAddress(), ep->SocketAddressLen()))) {
                std::string message(m_hello + " ");
                message.append((optind<argc)?(argv[optind]):(""));
                message.append("\n");
                XOS_LOG_INFO("Sending \"" << message << "\"...");
                if (0 < (s->Send((const void*)(message.c_str()), message.length(), 0))) {
                    XOS_LOG_INFO("...Sent \"" << message << "\"...");
                }
            }
            network::Socket::Delete(s);
        }
        delete ep;
        return 0; 
    }
    virtual int RunTcpServer(int argc, char** argv, char** env) { 
        network::Endpoint* ep = ServerEndpoint(m_host.c_str(), m_portNo);
        network::Socket* s = 0;
        if (s = (network::Socket::New(ep->GetFamily(), network::ip::tcp::Transport::Type, network::ip::tcp::Transport::Protocol))) {
            if ((s->Bind(ep->SocketAddress(), ep->SocketAddressLen()))) {
                if ((s->Listen())) {
                    network::Socket* c = 0;
                    while ((c = s->Accept(ep->SocketAddress(), &ep->SocketAddressLen()))) {
                        TcpConnections cn(c);
                        ServiceTcp service(cn);
                        if ((m_threadsNo)) {
                            os::Thread t(service);
                        } else {
                            service();
                        }
                        if ((service.RecvdBye())) {
                            break;
                        }
                    }
                }
            }
            network::Socket::Delete(s);
        }
        delete ep;
        return 0; 
    }

    //
    // UDP
    //
    virtual int RunUdpClient(int argc, char** argv, char** env) { 
        network::Endpoint* ep = ClientEndpoint(m_host.c_str(), m_portNo);
        network::Socket* s = 0;
        if (s = (network::Socket::New(ep->GetFamily(), network::ip::udp::Transport::Type, network::ip::udp::Transport::Protocol))) {
             std::string message(m_hello + " ");
             message.append((optind<argc)?(argv[optind]):(""));
             message.append("\n");
             XOS_LOG_INFO("Sending \"" << message << "\"...");
             if (0 < (s->SendTo((const void*)(message.c_str()), message.length(), 0, ep->SocketAddress(), ep->SocketAddressLen()))) {
                 XOS_LOG_INFO("...Sent \"" << message << "\"...");
             }
            network::Socket::Delete(s);
        }
        delete ep;
        return 0; 
    }
    virtual int RunUdpServer(int argc, char** argv, char** env) { 
        network::Endpoint* ep = ServerEndpoint(m_host.c_str(), m_portNo);
        network::Socket* s = 0;
        if (s = (network::Socket::New(ep->GetFamily(), network::ip::udp::Transport::Type, network::ip::udp::Transport::Protocol))) {
            if ((s->Bind(ep->SocketAddress(), ep->SocketAddressLen()))) {
                ssize_t count = 0;
                while (0 < (count = s->RecvFrom(m_buf, sizeof(m_buf)-1, 0, ep->SocketAddress(), &ep->SocketAddressLen()))) {
                    m_buf[count] = 0;
                    printf("--->\n%s\n<---\n", m_buf);
                    if (m_buf == (strstr(m_buf, m_bye.c_str()))) {
                        break;
                    }
                }
            }
            network::Socket::Delete(s);
        }
        delete ep;
        return 0; 
    }

    virtual network::Endpoint* ClientEndpoint(const char* host, u_short port) {
        network::Endpoint* ep = 0;
        if ((m_clientEndpoint))
            ep = (this->*m_clientEndpoint)(host, port);
        else ep = ClientIpv4Endpoint(host, port);
        return ep;
    }
    virtual network::Endpoint* ServerEndpoint(const char* host, u_short port) {
        network::Endpoint* ep = 0;
        if ((m_serverEndpoint))
            ep = (this->*m_serverEndpoint)(host, port);
        else ep = ServerIpv4Endpoint(host, port);
        return ep;
    }

    virtual network::Endpoint* LocalEndpoint(const char* host, u_short port) {
        std::stringstream ss;
        ss << host;
        ss << port;
        network::Endpoint* ep = new network::local::Endpoint(ss.str().c_str());
        return ep;
    }

    virtual network::Endpoint* ClientIpv4Endpoint(const char* host, u_short port) {
        network::Endpoint* ep = new network::ip::v4::Endpoint(host, port);
        return ep;
    }
    virtual network::Endpoint* ServerIpv4Endpoint(const char* host, u_short port) {
        network::Endpoint* ep = new network::ip::v4::Endpoint(port);
        return ep;
    }

    virtual network::Endpoint* ClientIpv6Endpoint(const char* host, u_short port) {
        network::Endpoint* ep = new network::ip::v6::Endpoint(host, port);
        return ep;
    }
    virtual network::Endpoint* ServerIpv6Endpoint(const char* host, u_short port) {
        network::Endpoint* ep = new network::ip::v6::Endpoint(port);
        return ep;
    }

    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        switch(optval)
        {
        case 'c':
            if ('u' != (tolower(optarg[0]))) {
                m_transport.assign("t");
                m_runner = &Derives::RunTcpClient;
            } else {
                m_transport.assign("u");
                m_runner = &Derives::RunUdpClient;
            }
            break;
        case 's':
            if ('u' != (tolower(optarg[0]))) {
                m_transport.assign("t");
                m_runner = &Derives::RunTcpServer;
            } else {
                m_transport.assign("u");
                m_runner = &Derives::RunUdpServer;
            }
            break;
        case 'r':
            if ('u' != (tolower(optarg[0]))) {
                m_transport.assign("t");
                m_runner = &Derives::RunStart;
            } else {
                m_transport.assign("u");
                m_runner = &Derives::RunStart;
            }
            break;
        case 'w':
            m_waitIsTrue = true;
            break;
        case 'n':
            m_processIsNative = true;
            break;
        case 'm':
            m_hello.assign(optarg);
            break;
        case 'o':
            m_host.assign(optarg);
            break;
        case 't':
            {
                std::stringstream ss(optarg);
                ss >> m_threadsNo;
                m_threads.assign(optarg);
            }
            break;
        case 'p':
            {
                std::stringstream ss(optarg);
                ss >> m_portNo;
                m_port.assign(optarg);
            }
            break;
        case 'a':
            switch(tolower(optarg[0])) {
            case '4':
                m_family.assign("4");
                m_clientEndpoint = &Derives::ClientIpv4Endpoint;
                m_serverEndpoint = &Derives::ServerIpv4Endpoint;
                break;
            case '6':
                m_family.assign("6");
                m_clientEndpoint = &Derives::ClientIpv6Endpoint;
                m_serverEndpoint = &Derives::ServerIpv6Endpoint;
                break;
            case 'l':
                m_family.assign("l");
                m_clientEndpoint = &Derives::LocalEndpoint;
                m_serverEndpoint = &Derives::LocalEndpoint;
                break;
            }
            break;
        default:
            err = Extends::OnOption(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt)
    {
        const char* chars = "";
        switch(longopt->val)
        {
        case 'm':
            optarg = "message";
            chars = "Hello Message";
            break;
        case 'c':
        case 'r':
        case 's':
            optarg = "{(t)Tcp | (u)Udp}";
            chars = ('s'!=(longopt->val))?(('r'!=(longopt->val))?("Client"):("Start")):("Server");
            break;
        case 'w':
            chars = "Wait Process";
            break;
        case 'n':
            chars = "Native Process";
            break;
        case 't':
            optarg = "number";
            chars = "Threads";
            break;
        case 'o':
            optarg = "name";
            chars = "Host Name";
            break;
        case 'p':
            optarg = "number";
            chars = "Port Number";
            break;
        case 'a':
            optarg = "{(4)ipv4 | (6)ipv6 | (l)local}";
            chars = "Address Family";
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    virtual const char* Options
    (const struct option*& longopts)
    {
        int err = 0;
        static const char* chars = "m:c:s:r:wnt:o:p:a:" XOS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            {"message", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'm'},
            {"client", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'c'},
            {"server", MAIN_OPT_ARGUMENT_REQUIRED, 0, 's'},
            {"start", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'r'},
            {"wait", MAIN_OPT_ARGUMENT_NONE, 0, 'w'},
            {"native", MAIN_OPT_ARGUMENT_NONE, 0, 'n'},
            {"threads", MAIN_OPT_ARGUMENT_REQUIRED, 0, 't'},
            {"host", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'o'},
            {"port", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'p'},
            {"address-family", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'a'},
            XOS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

protected:
    Runner m_runner;
    Endpoint m_clientEndpoint;
    Endpoint m_serverEndpoint;
    bool m_waitIsTrue;
    bool m_processIsNative;
    unsigned m_threadsNo;
    std::string m_threads;
    std::string m_transport;
    std::string m_family;
    std::string m_hello;
    std::string m_bye;
    std::string m_host;
    std::string m_port;
    u_short m_portNo;
    char m_buf[4096];
};

} // namespace xos

#endif // _XOS_HELLO_HPP_ 
