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
///   Date: 10/30/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_APP_CONSOLE_LS_MAIN_HPP
#define _EV_APP_CONSOLE_LS_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "ev/app/console/ls/main_opt.hpp"
#include "ev/os/os/fs/directory/path.hpp"
#include "ev/os/os/fs/entry.hpp"
#include "ev/fs/path/directory/name.hpp"
#include "ev/fs/path/matchers.hpp"
#include "ev/fs/path/matcher.hpp"
#include "ev/fs/path/match/reader.hpp"
#include "ev/fs/path/match/read/events.hpp"
#include "ev/fs/path/separator.hpp"

#define EV_APP_CONSOLE_LS_BETWEEN " "

#define EV_APP_CONSOLE_LS_SKIP_PATTERNS \
    "*.o;*.obj;._*;" \
    ""

#define EV_APP_CONSOLE_LS_MATCH_PATTERNS \
    "*.h;*.c;*.m;*.hh;*.cc;*.mm;*.hpp;*.cpp;*.hxx;*.cxx;*.H;*.C;*.M;" \
    "*.pro;*.pri;Make*;" \
    ""

#define EV_APP_CONSOLE_LS_SKIP_DIRECTORY_PATTERNS \
    ".*;" \
    ""

#define EV_APP_CONSOLE_LS_MATCH_DIRECTORY_PATTERNS \
    "*;" \
    ""

namespace ev {
namespace app {
namespace console {
namespace ls {

typedef fs::path::matchers main_matchers;
typedef fs::path::match::read::events main_match_events;
typedef xos::base::getopt::main_implement main_implement;
typedef xos::base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_match_events,
  virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;
    typedef Extends::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : between_(EV_APP_CONSOLE_LS_BETWEEN),
      match_(EV_APP_CONSOLE_LS_MATCH_PATTERNS),
      skip_(EV_APP_CONSOLE_LS_SKIP_PATTERNS),
      match_directory_(EV_APP_CONSOLE_LS_MATCH_DIRECTORY_PATTERNS),
      skip_directory_(EV_APP_CONSOLE_LS_SKIP_DIRECTORY_PATTERNS),
      name_on_(true), source_on_(true), target_on_(true),
      match_case_on_(true), ln_on_(true) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char **env) {
        int err = 0;

        if ((optind < argc))
            source_.assign(argv[optind]);

        if ((optind+1 < argc))
            target_.assign(argv[optind+1]);

        if (0 < (source_.length())) {
            os::os::fs::directory::path path;
            if ((path.open(source_.c_str()))) {
                fs::directory::entry* e;
                fs::path::parts p;
                for (e = path.get_first_entry(); e; e = path.get_next_entry()) {
                    p.assign(e->path());
                    on_entry(*e, p, source_, target_);
                }
            }
        } else {
            err = usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int after_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        matchers_.read(match_.chars(), match_.length());
        skipers_.read(skip_.chars(), skip_.length());
        directory_matchers_.read(match_directory_.chars(), match_directory_.length());
        directory_skipers_.read(skip_directory_.chars(), skip_directory_.length());
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_directory_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if ((recursive_on_)) {
            const char *pchars, *dchars, *chars;
            size_t plength, dlength, length;

            if (!(e.is_circular())
                 && ((pchars = e.path(plength)) && (0 < plength))
                 && ((chars = e.name(length)) && (0 < length))) {
                fs::path::directory::name directory;
                os::os::fs::directory::path path;

                if ((dchars = e.directory(dlength)) && (0 < dlength))
                    directory.assign(dchars, dlength);

                directory.append(chars, length);

                if ((dchars = directory.chars(dlength)) && (0 < dlength)) {
                    if ((path.open(pchars, dchars))) {
                        fs::directory::entry* e;
                        fs::path::parts p;

                        for (e = path.get_first_entry(); e; e = path.get_next_entry()) {
                            p.assign(e->path());
                            on_entry(*e, p, source_, target_);
                        }
                    }
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_match_file_entry_target
    (const fs::directory::entry& e, const string_t& target) {
        os::os::fs::entry t;
        if ((t.exists_is_type(target.chars(), e.type()))) {
            if ((e.is_older_than_or_equal(t))) {
                return false;
            }
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_file_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        const char_t *chars;
        size_t length;

        if ((chars = target.chars(length)) && (0 < length)) {
            fs::path::directory::name name(chars, length);

            name.append(e.directory());
            name.append(e.name());

            if ((on_match_file_entry_target(e, name))) {
                out(before_.c_str());
                if ((source_on_)) {
                    if ((name_on_)) {
                        out(e.path());
                    } else {
                        out(e.directory());
                    }
                    out(between_.c_str());
                }
                if ((target_on_)) {
                    if ((name_on_)) {
                        out(name.chars());
                    } else {
                        fs::path::directory::name directory(chars, length);
                        directory.append(e.directory());
                        out(directory.chars());
                    }
                }
                out(after_.c_str());
                if ((ln_on_)) {
                    outln();
                }
            }
        } else {
            out(before_.c_str());
            if ((source_on_)) {
                if ((name_on_)) {
                    out(e.path());
                } else {
                    out(e.directory());
                }
            }
            out(after_.c_str());
            if ((ln_on_)) {
                outln();
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_actual_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if (fs::entry_type_directory == (fs::entry_type_directory & e.type())) {
            if (!(directory_skipers_.matches(p))) {
                if ((directory_matchers_.matches(p))) {
                    on_directory_entry(e, p, source, target);
                }
            }
        } else {
            if (fs::entry_type_file == (fs::entry_type_file & e.type())) {
                if (!(skipers_.matches(p))) {
                    if ((matchers_.matches(p))) {
                        on_file_entry(e, p, source, target);
                    }
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_symbolic_link_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if (fs::entry_type_directory == (fs::entry_type_directory & e.type())) {
            if (!(exclude_directory_links_on_)) {
                on_actual_entry(e, p, source, target);
            }
        } else {
            if (fs::entry_type_file == (fs::entry_type_file & e.type())) {
                if (!(exclude_file_links_on_)) {
                    on_actual_entry(e, p, source, target);
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_entry
    (const fs::directory::entry& e, fs::path::parts& p,
     const string_t& source, const string_t& target) {
        if (fs::entry_type_symbolic_link == (fs::entry_type_symbolic_link & e.type())) {
            on_symbolic_link_entry(e, p, source, target);
        } else {
            on_actual_entry(e, p, source, target);
        }
    }

#include "ev/app/console/ls/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main_matchers matchers_, skipers_;
    main_matchers directory_matchers_, directory_skipers_;
    string_t source_, target_;
    string_t before_directory_, after_directory_, between_directory_;
    string_t before_, after_, between_;
    string_t match_, skip_, match_file_, skip_file_;
    string_t match_directory_, skip_directory_, match_directory_file_, skip_directory_file_;

    bool_t name_on_, directory_on_, directory_only_on_;
    bool_t source_on_, target_on_, reverse_on_, recursive_on_, reflective_on_;
    bool_t match_case_on_, compare_files_on_;
    bool_t existing_files_on_, missing_files_on_, older_files_on_, all_files_on_;
    bool_t exclude_directory_links_on_, exclude_file_links_on_;
    bool_t ln_on_;
};

} // namespace ls 
} // namespace console 
} // namespace app 
} // namespace ev 

#endif // _EV_APP_CONSOLE_LS_MAIN_HPP 
