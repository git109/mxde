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
#include "xos/mt/os/Thread.hpp"
#include <deque>
#include <sstream>

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

    class _EXPORT_CLASS Runner: public mt::Run {
    public:
        Runner(const String& name, size_t iterations = 1)
        : m_name(name), m_iterations(iterations) {}
        virtual void operator()() {
            for (size_t i = 0; i < m_iterations; ++i) {
                XOS_LOG_INFO("Hello from " << m_name << "[" << i << "]");
                usleep(200000);
            }
        }
        const String& Name() const { return m_name; }
    protected:
        String m_name;
        size_t m_iterations;
    };

    class _EXPORT_CLASS Thread {
    public:
        Thread(const String& name, size_t iterations = 1)
        : m_runner(name, iterations), m_thread(m_runner) {}
        virtual ~Thread() {}
        bool Destroy() { return m_thread.Destroy(); }
        const String& Name() const { return m_runner.Name(); }
    protected:
        Runner m_runner;
        mt::os::Thread m_thread;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main() {}
    virtual int Run(int argc, char **argv, char **env) {
        size_t n = 10;
        std::deque<Thread*> q;
        Thread* t;

        if ((optind < argc)) {
            std::stringstream ss(argv[optind]);
            size_t v;
            if (0 < (ss >> v))
                n = v;
        }

        for (size_t i = 0; i < n; ++i) {
            String name("Thread[");
            name.Append((unsigned)i);
            name.Append("]");
            XOS_LOG_DEBUG("creating \"" << name << "\"...");
            if ((t = new Thread(name, n))) {
                XOS_LOG_DEBUG("...created \"" << name << "\"");
                q.push_back(t);
            }
        }

        Runner m_runner("Main", n);
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
};

} // namespace hello 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_HELLO_MAIN_HPP 
