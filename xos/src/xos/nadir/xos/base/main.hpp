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

#include "xos/base/base.hpp"

namespace xos {
namespace base {

typedef implement_base main_implement;
typedef base main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TChar = char,
 class TImplements = main_implement,
 class TExtends = main_extend>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): the_main_(get_the_main()) {
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

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
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
        if (!(err = before_run(argc, argv, env))) {
            int err2;
            err = run(argc, argv, env);
            if ((err2 = after_run(argc, argv, env))) {
                if (!(err))
                    err = err2;
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
        if (!(err = before_main(argc, argv, env))) {
            int err2;
            err = main(argc, argv, env);
            if ((err2 = after_main(argc, argv, env))) {
                if (!(err))
                    err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static maint*& get_the_main();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    maint* the_main_;
};
typedef maint<char> main;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_MAIN_HPP 
