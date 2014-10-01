///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 4/16/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_HELLO_MAIN_HPP
#define _XOS_MT_HELLO_MAIN_HPP

#include "xos/os/Main.hpp"
#include "xos/mt/Run.hpp"
#include "xos/mt/os/Process.hpp"
#include "xos/mt/os/Thread.hpp"

#include <deque>
#include <sstream>

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_MT_HELLO_MAIN_THREADS_OPT "threads"
#define XOS_MT_HELLO_MAIN_THREADS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_THREADS_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_THREADS_OPTARG "{1..n}"
#define XOS_MT_HELLO_MAIN_THREADS_OPTUSE "Number of threads"
#define XOS_MT_HELLO_MAIN_THREADS_OPTVAL_S "t:"
#define XOS_MT_HELLO_MAIN_THREADS_OPTVAL_C 't'
#define XOS_MT_HELLO_MAIN_THREADS_OPTION \
   {XOS_MT_HELLO_MAIN_THREADS_OPT, \
    XOS_MT_HELLO_MAIN_THREADS_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_THREADS_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_THREADS_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_PROCESSES_OPT "processes"
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTARG "{1..n}"
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTUSE "Number of processes"
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTVAL_S "p:"
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTVAL_C 'p'
#define XOS_MT_HELLO_MAIN_PROCESSES_OPTION \
   {XOS_MT_HELLO_MAIN_PROCESSES_OPT, \
    XOS_MT_HELLO_MAIN_PROCESSES_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_PROCESSES_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_PROCESSES_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPT "executable"
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTARG "<path>"
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTUSE "Process executable path"
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTVAL_S "x:"
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTVAL_C 'x'
#define XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTION \
   {XOS_MT_HELLO_MAIN_EXECCUTABLE_OPT, \
    XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_ARGS_OPT "pass-args"
#define XOS_MT_HELLO_MAIN_ARGS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_ARGS_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_ARGS_OPTARG ""
#define XOS_MT_HELLO_MAIN_ARGS_OPTUSE ""
#define XOS_MT_HELLO_MAIN_ARGS_OPTVAL_S "a:"
#define XOS_MT_HELLO_MAIN_ARGS_OPTVAL_C 'a'
#define XOS_MT_HELLO_MAIN_ARGS_OPTION \
   {XOS_MT_HELLO_MAIN_ARGS_OPT, \
    XOS_MT_HELLO_MAIN_ARGS_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_ARGS_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_ARGS_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_ENV_OPT "pass-env"
#define XOS_MT_HELLO_MAIN_ENV_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_ENV_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_ENV_OPTARG ""
#define XOS_MT_HELLO_MAIN_ENV_OPTUSE ""
#define XOS_MT_HELLO_MAIN_ENV_OPTVAL_S "n:"
#define XOS_MT_HELLO_MAIN_ENV_OPTVAL_C 'n'
#define XOS_MT_HELLO_MAIN_ENV_OPTION \
   {XOS_MT_HELLO_MAIN_ENV_OPT, \
    XOS_MT_HELLO_MAIN_ENV_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_ENV_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_ENV_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_STDIN_OPT "pass-stdin"
#define XOS_MT_HELLO_MAIN_STDIN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_STDIN_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_STDIN_OPTARG ""
#define XOS_MT_HELLO_MAIN_STDIN_OPTUSE ""
#define XOS_MT_HELLO_MAIN_STDIN_OPTVAL_S "i:"
#define XOS_MT_HELLO_MAIN_STDIN_OPTVAL_C 'i'
#define XOS_MT_HELLO_MAIN_STDIN_OPTION \
   {XOS_MT_HELLO_MAIN_STDIN_OPT, \
    XOS_MT_HELLO_MAIN_STDIN_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_STDIN_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_STDIN_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_STDOUT_OPT "pass-stdout"
#define XOS_MT_HELLO_MAIN_STDOUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_STDOUT_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_STDOUT_OPTARG ""
#define XOS_MT_HELLO_MAIN_STDOUT_OPTUSE ""
#define XOS_MT_HELLO_MAIN_STDOUT_OPTVAL_S "o:"
#define XOS_MT_HELLO_MAIN_STDOUT_OPTVAL_C 'o'
#define XOS_MT_HELLO_MAIN_STDOUT_OPTION \
   {XOS_MT_HELLO_MAIN_STDOUT_OPT, \
    XOS_MT_HELLO_MAIN_STDOUT_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_STDOUT_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_STDOUT_OPTVAL_C}, \

#define XOS_MT_HELLO_MAIN_STDERR_OPT "pass-stderr"
#define XOS_MT_HELLO_MAIN_STDERR_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_MT_HELLO_MAIN_STDERR_OPTARG_RESULT 0
#define XOS_MT_HELLO_MAIN_STDERR_OPTARG ""
#define XOS_MT_HELLO_MAIN_STDERR_OPTUSE ""
#define XOS_MT_HELLO_MAIN_STDERR_OPTVAL_S "e:"
#define XOS_MT_HELLO_MAIN_STDERR_OPTVAL_C 'e'
#define XOS_MT_HELLO_MAIN_STDERR_OPTION \
   {XOS_MT_HELLO_MAIN_STDERR_OPT, \
    XOS_MT_HELLO_MAIN_STDERR_OPTARG_REQUIRED, \
    XOS_MT_HELLO_MAIN_STDERR_OPTARG_RESULT, \
    XOS_MT_HELLO_MAIN_STDERR_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_MT_HELLO_MAIN_OPTIONS_CHARS \
   XOS_MT_HELLO_MAIN_THREADS_OPTVAL_S \
   XOS_MT_HELLO_MAIN_PROCESSES_OPTVAL_S \
   XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTVAL_S \
   XOS_MT_HELLO_MAIN_ARGS_OPTVAL_S \
   XOS_MT_HELLO_MAIN_ENV_OPTVAL_S \
   XOS_MT_HELLO_MAIN_STDIN_OPTVAL_S \
   XOS_MT_HELLO_MAIN_STDOUT_OPTVAL_S \
   XOS_MT_HELLO_MAIN_STDERR_OPTVAL_S \
   XOS_MAIN_OPTIONS_CHARS

#define XOS_MT_HELLO_MAIN_OPTIONS_OPTIONS \
   XOS_MT_HELLO_MAIN_THREADS_OPTION \
   XOS_MT_HELLO_MAIN_PROCESSES_OPTION \
   XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTION \
   XOS_MT_HELLO_MAIN_ARGS_OPTION \
   XOS_MT_HELLO_MAIN_ENV_OPTION \
   XOS_MT_HELLO_MAIN_STDIN_OPTION \
   XOS_MT_HELLO_MAIN_STDOUT_OPTION \
   XOS_MT_HELLO_MAIN_STDERR_OPTION \
   XOS_MAIN_OPTIONS_OPTIONS

namespace xos {
namespace mt {
namespace hello {

typedef xos::MainImplement MainImplement;
typedef xos::Main MainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplement, public MainExtend {
public:
    typedef MainImplement Implements;
    typedef MainExtend Extends;
    typedef Main Derives;

    typedef int (Derives::*Runner)(int argc, char **argv, char **env);
    typedef mt::os::Process Process;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Thread {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        class _EXPORT_CLASS Runner: public mt::Run {
        public:
            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            Runner(int argc, char **argv, char **env, const String& name, size_t iterations = 1)
            : m_argc(argc), m_argv(argv), m_env(env),
              m_name(name), m_iterations(iterations) {}

            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            virtual void operator()() {
                const char* hello = "Hello";
                const char* who = (optind < m_argc)?(m_argv[optind]):(0);
                for (size_t i = 0; i < m_iterations; ++i) {
                    XOS_LOG_INFO(m_name << "[" << i << "]" << hello << ((who)?(" "):("")) << ((who)?(who):("")));
                    usleep(200000);
                }
            }
            const String& Name() const { return m_name; }

            ///////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////
        protected:
            int m_argc;
            char** m_argv;
            char** m_env;
            String m_name;
            size_t m_iterations;
        };

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Thread(int argc, char **argv, char **env, const String& name, size_t iterations = 1)
        : m_runner(argc, argv, env, name, iterations), m_thread(m_runner) {}
        virtual ~Thread() {}

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        bool Destroy() { return m_thread.Destroy(); }
        const String& Name() const { return m_runner.Name(); }

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        Runner m_runner;
        mt::os::Thread m_thread;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_runner(0), m_processes(0), m_threads(0) {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char **argv, char **env) {
        int err = 0;
        if ((m_runner)) {
            err = (this->*m_runner)(argc, argv, env);
        } else {
            String hello("Hello");
            const char* who = (optind < argc)?(argv[optind]):(0);
            OutLLn(hello.Chars(), (who)?(" "):(""), (who)?(who):(""), 0);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int ProcessesRun(int argc, char **argv, char **env) {
        const char* exe = (0 < argc)?(argv[0]):("XosMtHello");
        char* arg0 = (0 < argc)?(argv[0]):(0);
        char* arg1 = (optind < argc)?(argv[optind]):(0);
        char* args[] = {arg0, arg1, 0};
        char** envs = env;
        int* fdup = 0;
        int** pdup = 0;
        bool isDetached = false;
        size_t n = m_processes;
        int err = 0;

        if ((exe) && (args)) {
            if (2 > (n)) {
                try {
                    Process p(exe, args, envs, fdup, pdup, isDetached);
                } catch(const Creator::Exception& e) {
                    const char* eName = (Creator::FailedToCreate!=e)?("FailedToDestroy"):("FailedToCreate");
                    XOS_LOG_ERROR("...caught Creator::" << eName);
                }
            } else {
                std::deque<Process*> q;
                Process* p;

                for (size_t i = 0; i < n; ++i) {
                    try {
                        XOS_LOG_DEBUG("new Process(\"" << exe << "\",...)...");
                        if ((p = new Process(exe, args, envs, fdup, pdup, isDetached))) {
                            XOS_LOG_DEBUG("...new Process(\"" << exe << "\",...)");
                            q.push_back(p);
                        }
                    } catch(const Creator::Exception& e) {
                        const char* eName = (Creator::FailedToCreate!=e)?("FailedToDestroy"):("FailedToCreate");
                        XOS_LOG_ERROR("...caught Creator::" << eName);
                        break;
                    }
                }

                for (std::deque<Process*>::iterator i = q.end(); i != q.begin(); --i) {
                    if ((p = *(i-1))) {
                        try {
                            pid_t pid = p->AttachedTo();
                            XOS_LOG_DEBUG("deleteing process " << pid << "...");
                            delete p;
                            XOS_LOG_DEBUG("...deleted process " << pid << "");
                        } catch(const Creator::Exception& e) {
                            const char* eName = (Creator::FailedToCreate!=e)?("FailedToDestroy"):("FailedToCreate");
                            XOS_LOG_ERROR("...caught Creator::" << eName);
                        }
                    }
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int ThreadsRun(int argc, char **argv, char **env) {
        size_t n = m_threads;
        std::deque<Thread*> q;
        Thread* t;

        for (size_t i = 0; i < n; ++i) {
            String name("Thread[");
            name.Append((unsigned)i);
            name.Append("]");
            XOS_LOG_DEBUG("creating \"" << name << "\"...");
            if ((t = new Thread(argc, argv, env, name, n))) {
                XOS_LOG_DEBUG("...created \"" << name << "\"");
                q.push_back(t);
            }
        }

        Thread::Runner m_runner(argc, argv, env, "Main", n);
        m_runner();

        for (std::deque<Thread*>::iterator i = q.end(); i != q.begin(); --i) {
            if ((t = *(i-1))) {
                String name(t->Name());
                XOS_LOG_DEBUG("destroying \"" << name << "\"...");
                if ((t->Destroy())) {
                    XOS_LOG_DEBUG("...destroyed \"" << name << "\"");
                }
                XOS_LOG_DEBUG("deleteing \"" << name << "\"...");
                delete t;
                XOS_LOG_DEBUG("...deleted \"" << name << "\"");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnThreadsOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        String a(optarg);
        int n;
        if (0 < (a >> n)) {
            m_threads = n;
            m_runner = &Derives::ThreadsRun;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnProcessesOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        String a(optarg);
        int n;
        if (0 < (a >> n)) {
            m_processes = n;
            if (0 < (m_threads)) {
                m_runner = &Derives::ThreadsRun;
            } else {
                m_runner = &Derives::ProcessesRun;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnExeccutableOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnArgsOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnEnvOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnStdinOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnstdoutOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnStderrOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case XOS_MT_HELLO_MAIN_THREADS_OPTVAL_C:
            err = OnThreadsOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_PROCESSES_OPTVAL_C:
            err = OnProcessesOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTVAL_C:
            err = OnExeccutableOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_ARGS_OPTVAL_C:
            err = OnArgsOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_ENV_OPTVAL_C:
            err = OnEnvOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_STDIN_OPTVAL_C:
            err = OnStdinOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_STDOUT_OPTVAL_C:
            err = OnstdoutOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_MT_HELLO_MAIN_STDERR_OPTVAL_C:
            err = OnStderrOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case XOS_MT_HELLO_MAIN_THREADS_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_THREADS_OPTARG;
            chars = XOS_MT_HELLO_MAIN_THREADS_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_PROCESSES_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_PROCESSES_OPTARG;
            chars = XOS_MT_HELLO_MAIN_PROCESSES_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTARG;
            chars = XOS_MT_HELLO_MAIN_EXECCUTABLE_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_ARGS_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_ARGS_OPTARG;
            chars = XOS_MT_HELLO_MAIN_ARGS_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_ENV_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_ENV_OPTARG;
            chars = XOS_MT_HELLO_MAIN_ENV_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_STDIN_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_STDIN_OPTARG;
            chars = XOS_MT_HELLO_MAIN_STDIN_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_STDOUT_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_STDOUT_OPTARG;
            chars = XOS_MT_HELLO_MAIN_STDOUT_OPTUSE;
            break;
        case XOS_MT_HELLO_MAIN_STDERR_OPTVAL_C:
            optarg = XOS_MT_HELLO_MAIN_STDERR_OPTARG;
            chars = XOS_MT_HELLO_MAIN_STDERR_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = XOS_MT_HELLO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_MT_HELLO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Runner m_runner;
    size_t m_processes;
    size_t m_threads;
};

} // namespace hello 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_HELLO_MAIN_HPP 
