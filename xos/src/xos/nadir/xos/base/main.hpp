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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_MAIN_HPP
#define _XOS_NADIR_XOS_BASE_MAIN_HPP

#include "xos/mt/locker.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace xos {
namespace base {

typedef mt::locker main_locker;
typedef main_locker main_implements;
typedef attachert<main_locker*, int, 0, main_implements> main_attacher;
typedef attachedt<main_locker*, int, 0, main_attacher, base> main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = main_implements,
 class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): the_main_(get_the_main()), did_main_(false), did_run_(false) {
        get_the_main() = this;
    }
    virtual ~maint() {
        if (this == (get_the_main())) {
            get_the_main() = the_main_;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int the_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        maint* main;

        if ((main = get_the_main())) {
            err = (*main)(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool unlock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->lock();
        }
        return true;
    }
    virtual bool lock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->unlock();
        }
        return true;
    }
    virtual mt::wait_status try_lock() {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->try_lock();
        }
        return mt::wait_success;
    }
    virtual mt::wait_status timed_lock(mseconds_t milliseconds) {
        main_locker* locker;
        if ((locker = this->attached_to())) {
            return locker->timed_lock(milliseconds);
        }
        return mt::wait_success;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        set_did_run();
        return 0;
    }
    virtual int before_run(int argc, char_t** argv, char_t** env) {
        return 0;
    }
    virtual int after_run(int argc, char_t** argv, char_t** env) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int main(int argc, char_t** argv, char_t** env) {
        int err = 0;

        set_did_main();
        if (!(did_run())) {
            if (!(err = before_run(argc, argv, env))) {
                int err2;

                if (!(did_run())) {
                    err = run(argc, argv, env);
                }
                if ((err2 = after_run(argc, argv, env))) {
                    if (!(err))
                        err = err2;
                }
            }
        }
        return err;
    }
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        return 0;
    }
    virtual int after_main(int argc, char_t** argv, char_t** env) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int operator()(int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(did_main())) {
            if (!(err = before_main(argc, argv, env))) {
                int err2;

                if (!(did_main())) {
                    err = main(argc, argv, env);
                }
                if ((err2 = after_main(argc, argv, env))) {
                    if (!(err))
                        err = err2;
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = outfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t outfv(const char_t* format, va_list va) {
        ssize_t count = outfv(std_out(), format, va);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t errf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = errfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errfv(const char_t* format, va_list va) {
        ssize_t count = outfv(std_err(), format, va);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t inf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = infv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t infv(const char_t* format, va_list va) {
        ssize_t count = infv(std_in(), format, va);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, out);
        if ((out))
        count = outlv(out, va);
        va_end(va);
        return count;
    }
    virtual ssize_t outlv(const char_t* out, va_list va) {
        ssize_t count = outlv(std_out(), out, va);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t errl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, out);
        if ((out))
        count = errlv(out, va);
        va_end(va);
        return count;
    }
    virtual ssize_t errlv(const char_t* out, va_list va) {
        ssize_t count = outlv(std_err(), out, va);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outfv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t infv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outlv(FILE* f, const char_t* out, va_list va) {
        ssize_t count = 0;
        ssize_t amount = 0;
        for (count = 0; out; count += amount) {
            if (0 > (amount = this->out(f, out)))
                return amount;
            out = va_arg(va, const char_t*);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outln(FILE* f) {
        const char_t ln = ((char_t)'\n');
        ssize_t count = out(f, &ln, 1);
        return count;
    }
    virtual ssize_t out(FILE* f, const char_t* out, ssize_t length = -1) {
        ssize_t count = 0;
        if ((out) && (f)) {
            ssize_t amount;
            if (0 <= (length)) {
                if (0 < (amount = fwrite(out, sizeof(char_t), length, f)))
                    count += amount;
            } else {
                for (; *out; ++out) {
                    if (0 < (amount = fwrite(out, sizeof(char_t), 1, f)))
                        count += amount;
                }
            }
        }
        return count;
    }
    virtual ssize_t out_flush(FILE* f) {
        ssize_t count = 0;
        if ((f)) {
            fflush(f);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t inln(FILE* f, char_t* in, size_t size) {
        ssize_t count = 0;
        if ((in) && (f) && (0 < (size))) {
            const char_t ln = ((char_t)'\n');
            char_t c;
            ssize_t amount;
            while (0 < (size)) {
                if (0 > (amount = this->in(f, &c, 1))) {
                    count = amount;
                } else {
                    --size;
                    if (ln != c) {
                        *in = c;
                        ++in;
                        continue;
                    }
                }
                break;
            }
        }
        return count;
    }
    virtual ssize_t in(FILE* f, char_t* in, size_t size) {
        ssize_t count = 0;
        if ((in) && (f) && (0 < (size))) {
            ssize_t amount;
            if (0 < (amount = fread(in, sizeof(char_t), size, f))) {
                count += amount;
            }
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_run(bool to = true) {
        return did_run_ = to;
    }
    virtual bool did_run() const {
        return did_run_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_main(bool to = true) {
        return did_main_ = to;
    }
    virtual bool did_main() const {
        return did_main_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* std_out() const {
        return stdout;
    }
    virtual FILE* std_err() const {
        return stderr;
    }
    virtual FILE* std_in() const {
        return stdin;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static maint*& get_the_main();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    maint* the_main_;
    bool did_main_;
    bool did_run_;
};

typedef main_implements main_implement;
typedef maint<char, int, 0, main_implements, main_extends> main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outfv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        if ((f) && (format)) {
            count = vfprintf(f, format, va);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t infv(FILE* f, const char_t* format, va_list va) {
        ssize_t count = 0;
        if ((f) && (format)) {
            count = vfscanf(f, format, va);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace base
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_MAIN_HPP 
