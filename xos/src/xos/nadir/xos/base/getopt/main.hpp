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
///   Date: 9/13/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_GETOPT_MAIN_HPP
#define _XOS_NADIR_XOS_BASE_GETOPT_MAIN_HPP

#include "xos/base/main.hpp"
#include "xos/base/getopt/main_opt.hpp"

namespace xos {
namespace base {
namespace getopt {

typedef xos::base::main_implement main_implements;
typedef xos::base::main main_extends;
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
    maint(): did_usage_(false) {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int before_main(int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = before_get_options(argc, argv, env))) {
            int err2 = 0;

            err = get_options(argc, argv, env);

            if ((err2 = after_get_options(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;

        set_did_usage();
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_did_usage(bool to = true) {
        this->set_did_main(did_usage_ = to);
        return did_usage_;
    }
    virtual bool did_usage() const {
        return did_usage_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool did_usage_;
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

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        const char_t** args = 0;
        const char_t* argstring = arguments(args);
        const struct option* longopts = 0;
        const char_t* optstring = options(longopts);

        outf
        ("Usage: %s%s%s%s\n", argv[0],
         (optstring)?(" [options]"):(""),
         (argstring)?(" "):(""), (argstring)?(argstring):(""));

        if ((optstring) && (longopts)) {
            outf("\nOptions:\n");

            while ((longopts->name)) {
                const char_t* optarg =
                (OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                ((OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                const char_t* optusage = option_usage(optarg, longopts);
                const char_t* optargSeparator = (optarg[0])?(" "):("");
                const char_t* optusageSeparator = "  ";

                outf
                (" -%c --%s%s%s%s%s\n",
                 longopts->val, longopts->name,
                 optargSeparator, optarg, optusageSeparator, optusage);
                longopts++;
            }
        }

        if ((argstring) && (args)) {
            outf("\nArguments:\n");

            while ((arg = (*args))) {
                outf(" %s\n", arg);
                args++;
            }
        }

        set_did_usage();
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char_t optvaluename[2] = {0,0};
        const char_t* optname = optvaluename;
        const char_t* optstring;
        int optvalue;

        if ((optstring = options(longopts)) && (longopts)) {
            while (0 <= (optvalue = getopt_long(argc, argv, optstring, longopts, &longindex))) {
                optvaluename[0] = optvalue;
                optname = (longindex)?(longopts[longindex].name):(optvaluename);

                if ((err = on_option (optvalue, optarg, optname, longindex, argc, argv, env)))
                    break;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = xos::base::getopt::on_logging_option
        (optval, optarg, optname, optind, argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_usage_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_invalid_option_arg
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 1;
        errf("invalid argument \"%s\" for option \"%s\"\n", optarg, optname);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_MAIN_LOGGING_OPTVAL_C:
            err = on_logging_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_MAIN_HELP_OPTVAL_C:
            err = on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_MAIN_LOGGING_OPTVAL_C:
            optarg = XOS_MAIN_LOGGING_OPTARG;
            break;

        case XOS_MAIN_HELP_OPTVAL_C:
            chars = XOS_MAIN_HELP_OPTUSE;
            break;

        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        static const char* chars = XOS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int missing_argument(const char_t* arg) {
        int err = 1;
        errf("missing argument \"%s\"\n", arg);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char* arguments(const char**& args) {
        args = 0;
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace getopt 
} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_GETOPT_MAIN_HPP 
