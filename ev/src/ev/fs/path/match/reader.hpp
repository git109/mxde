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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 11/3/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_PATH_MATCH_READER_HPP
#define _EV_FS_PATH_MATCH_READER_HPP

#include "ev/fs/path/match/read/events.hpp"
#include "ev/base/base.hpp"

namespace ev {
namespace fs {
namespace path {
namespace match {

typedef read::events reader_events;
typedef implement_base reader_implements;
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TEvents = reader_events,
 class TImplements = reader_implements, class TExtends = reader_extends>

class _EXPORT_CLASS readert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef readert Derives;

    typedef TEvents events_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(events_t& events)
    : dot_((char_t)'.'), dot_token_("."), events_(events),
      final_(0), old_final_(0), put_(0), old_put_(0) {}
    virtual ~readert() {}

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            if ((initialize())) {
                for (; length; --length, ++chars) {
                    if (!(put(*chars))) {
                        return false;
                    }
                }
                return finalize();
            }
        }
        return false;
    }
    virtual bool read(const char_t* chars) {
        if ((chars)) {
            if ((initialize())) {
                for (char_t c = *chars++; c != 0; c = *chars++) {
                    if (!(put(c))) {
                        return false;
                    }
                }
                return finalize();
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool initialize() {
        bool is_true = true;
        final_ = &Derives::on_final;
        old_final_ = &Derives::on_final;
        put_ = &Derives::on_put;
        old_put_ = &Derives::on_put;
        token_.clear();
        return is_true;
    }
    virtual bool finalize() {
        bool is_true = final();
        final_ = 0;
        old_final_ = 0;
        put_ = 0;
        old_put_ = 0;
        token_.clear();
        return is_true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool put(char_t c) {
        if ((put_))
            return (this->*put_)(c);
        return false;
    }
protected:
    virtual bool final() {
        if ((final_))
            return (this->*final_)();
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_final() {
        const char_t* chars;
        size_t length;
        return true;
    }
    // '*'
    virtual bool on_wild_final() {
        const char_t* chars;
        size_t length;
        events_.on_match_file_any();
        return true;
    }
    // '*'A+
    virtual bool on_wild_name_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_name_suffix(chars, length);
        return true;
    }
    // A+
    virtual bool on_name_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_name(chars, length);
        return true;
    }
    // A+'*'
    virtual bool on_name_wild_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_name_prefix(chars, length);
        return true;
    }
    // A+'*'.
    virtual bool on_name_wild_base_final() {
        const char_t* chars;
        size_t length;
        EV_LOG_WARN("unsupported pattern \"A+'*'\"");
        return false;
    }
    // A+'*'.'*'
    virtual bool on_name_wild_base_wild_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_base_prefix(chars, length);
        return false;
    }
    // A+'.'
    virtual bool on_base_final() {
        const char_t* chars;
        size_t length;
        token_.append(&dot_, 1);
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_name(chars, length);
        return true;
    }
    // A+'.''*'
    virtual bool on_base_wild_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_base(chars, length);
        return true;
    }
    // '*'A+'.'
    virtual bool on_wild_base_final() {
        const char_t* chars;
        size_t length;
        token_.append(&dot_, 1);
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_name_suffix(chars, length);
        return true;
    }
    // '*'A+'.''*'
    virtual bool on_wild_base_wild_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_base_suffix(chars, length);
        return true;
    }
    // '*''.'A+
    virtual bool on_ext_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length)) {
            events_.on_match_file_extension(chars, length);
        } else {
            if ((chars = dot_token_.chars(length)) && (0 < length))
                events_.on_match_file_name_suffix(chars, length);
        }
        return true;
    }
    // '*''.'A+'*'
    virtual bool on_ext_wild_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_extension_prefix(chars, length);
        return true;
    }
    // '*''.''*'A+
    virtual bool on_wild_ext_final() {
        const char_t* chars;
        size_t length;
        if ((chars = token_.chars(length)) && (0 < length))
            events_.on_match_file_extension_suffix(chars, length);
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool on_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '#':
            // '#'
            old_put_ = put_;
            put_ = &Derives::on_comment_eol_put;
            break;

        case '*':
            // '*'
            put_ = &Derives::on_wild_put;
            final_ = &Derives::on_wild_final;
            break;

        case ' ':
        case '\t':
        case '\r':
        case '\n':
        case ';':
            break;

        case '.':
            // '.'
        default:
            // A
            token_.append(&c, 1);
            put_ = &Derives::on_name_put;
            final_ = &Derives::on_name_final;
            break;
        }
        return true;
    }
    // '#'
    virtual bool on_comment_eol_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '\n':
            // '#'?';'
            token_.clear();
            put_ = old_put_;
            old_put_ = &Derives::on_put;
            break;
        default:
            break;
        }
        return true;
    }
    virtual bool on_next_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case ';':
            // '*'';'
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;
        default:
            break;
        }
        return true;
    }
    // A+
    virtual bool on_name_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // A+'*'
            //EV_LOG_WARN("unsupported pattern \"A'*'\"");
            put_ = &Derives::on_name_wild_put;
            final_ = &Derives::on_name_wild_final;
            break;

        case '.':
            // A+'.'
            put_ = &Derives::on_base_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // A+';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_name(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // A+A
            token_.append(&c, 1);
            break;
        }
        return true;
    }
    // A+'*'
    virtual bool on_name_wild_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // A+'*''*'
            EV_LOG_WARN("unsupported pattern \"A+'*''*'\"");
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case '.':
            // A+'*''.'
            //EV_LOG_WARN("unsupported pattern \"A+'*''.'\"");
            put_ = &Derives::on_name_wild_base_put;
            final_ = &Derives::on_name_wild_base_final;
            break;

        case ';':
            // A+'*'';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_name_prefix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // A+'*'A
            EV_LOG_WARN("unsupported pattern \"A+'*'A\"");
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // A+'*''.'
    virtual bool on_name_wild_base_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // A+'*''.''*'
            //EV_LOG_WARNF("unsupported pattern \"A+'*''.''%c'\"", c);
            put_ = &Derives::on_name_wild_base_wild_put;
            final_ = &Derives::on_name_wild_base_wild_final;
            break;

        case '.':
            // A+'*''.''.'
            EV_LOG_WARNF("unsupported pattern \"A+'*''.''%c'\"", c);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // A+'*''.'';'
            EV_LOG_WARN("unsupported pattern \"A+'*''.'\"");
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        default:
            // A+'*''.'A
            EV_LOG_WARNF("unsupported pattern \"A+'*''.''%c'\"", c);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // A+'*''.''*'
    virtual bool on_name_wild_base_wild_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        default:
            // A+'*''.'A
        case '*':
            // A+'*''.''*''*'
        case '.':
            // A+'*''.''*''.'
            EV_LOG_WARNF("unsupported pattern \"A+'*''.''*''%c'\"", c);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // A+'*''.''*'';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_base_prefix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // A+'.'
    virtual bool on_base_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // A'.''*'
            put_ = &Derives::on_base_wild_put;
            final_ = &Derives::on_base_final;
            break;

        case '.':
            // A'.''.'
            EV_LOG_WARNF("unsupported pattern \"A'.''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // A'.'';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_name(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // A'.'A
            EV_LOG_WARNF("unsupported pattern \"A'.''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // A+'.''*'
    virtual bool on_base_wild_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // A+'.''*''*'
            EV_LOG_WARNF("unsupported pattern \"A'.''*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case '.':
            // A+'.''*''.'
            EV_LOG_WARNF("unsupported pattern \"A'.''*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // A+'.''*'';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_base(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // A+'.''*'A
            EV_LOG_WARNF("unsupported pattern \"A'.''*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // '*'
    virtual bool on_wild_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*''*'
            EV_LOG_WARNF("unsupported pattern \"'*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case '.':
            // '*''.'
            put_ = &Derives::on_ext_put;
            final_ = &Derives::on_ext_final;
            break;

        case ';':
            // '*'';'
            events_.on_match_file_any();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // '*'A
            //EV_LOG_WARNF("unsupported pattern \"'*''%c'\"", cc);
            token_.append(&c, 1);
            put_ = &Derives::on_wild_name_put;
            final_ = &Derives::on_wild_name_final;
            break;
        }
        return true;
    }
    // '*'A+
    virtual bool on_wild_name_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*'A+'*'
            EV_LOG_WARNF("unsupported pattern \"'*'A+'%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case '.':
            // '*'A+'.'
            //EV_LOG_WARNF("unsupported pattern \"'*'A+'%c'\"", cc);
            put_ = &Derives::on_wild_base_put;
            final_ = &Derives::on_wild_base_final;
            break;

        case ';':
            // '*'A+';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_name_suffix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // '*'A+A
            //EV_LOG_WARNF("unsupported pattern \"'*'A+'%c'\"", cc);
            token_.append(&c, 1);
            put_ = &Derives::on_wild_name_put;
            final_ = &Derives::on_wild_name_final;
            break;
        }
        return true;
    }
    // '*'A+'.'
    virtual bool on_wild_base_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*'A+'.''*'
            //EV_LOG_WARNF("unsupported pattern \"'*'A+'.''%c'\"", cc);
            put_ = &Derives::on_wild_base_wild_put;
            final_ = &Derives::on_wild_base_wild_final;
            break;

        case '.':
            // '*'A+'.''.'
            EV_LOG_WARNF("unsupported pattern \"'*'A+'.''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // '*'A+'.'';'
            token_.append(&dot_, 1);
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_name_suffix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // '*'A+'.'A
            EV_LOG_WARNF("unsupported pattern \"'*'A+'.''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // '*'A+'.''*'
    virtual bool on_wild_base_wild_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*'A+'.''*''*'
        case '.':
            // '*'A+'.''*''.'
        default:
            // '*'A+'.''*'A
            EV_LOG_WARNF("unsupported pattern \"'*'A+'.''*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // '*'A+'.''*'';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_base_suffix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // '*''.'
    virtual bool on_ext_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*''.''*'
            put_ = &Derives::on_wild_ext_put;
            final_ = &Derives::on_wild_ext_final;
            break;

        case '.':
            // '*''.''.'
        case ';':
            // '*''.'';'
            EV_LOG_WARNF("unsupported pattern \"'*''.''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        default:
            // '*''.'A
            token_.append(&c, 1);
            put_ = &Derives::on_ext_name_put;
            final_ = &Derives::on_ext_final;
            break;
        }
        return true;
    }
    // '*''.'A+
    virtual bool on_ext_name_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*''.'A+'*'
            put_ = &Derives::on_ext_wild_put;
            final_ = &Derives::on_ext_wild_final;
            break;

        case '.':
            // '*''.'A+'.'
            EV_LOG_WARN("unsupported pattern \"'*''.'A*'.'\"");
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // '*''.'A+';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_extension(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // '*''.'A+A
            token_.append(&c, 1);
            break;
        }
        return true;
    }
    // '*''.'A+'*'
    virtual bool on_ext_wild_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*''.'A+'*''*'
        case '.':
            // '*''.'A+'*''.'
        default:
            // '*''.'A+'*'A
            EV_LOG_WARNF("unsupported pattern \"'*''.'A+'*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // '*''.'A+'*'';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_extension_prefix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;
        }
        return true;
    }
    // '*''.''*'A+
    virtual bool on_wild_ext_put(char_t c) {
        const char cc = (char)(c);
        const char_t* chars;
        size_t length;
        switch (cc) {
        case '*':
            // '*''.''*'A+'*'
        case '.':
            // '*''.''*'A+'.'
            EV_LOG_WARNF("unsupported pattern \"'*''.'A+'*''%c'\"", cc);
            put_ = &Derives::on_next_put;
            final_ = &Derives::on_final;
            break;

        case ';':
            // '*''.''*'A+';'
            if ((chars = token_.chars(length)) && (0 < length))
                events_.on_match_file_extension_suffix(chars, length);
            token_.clear();
            put_ = &Derives::on_put;
            final_ = &Derives::on_final;
            break;

        default:
            // '*''.''*'A+A
            token_.append(&c ,1);
            break;
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef bool (Derives::*final_t)();
    typedef bool (Derives::*put_t)(char_t c);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char_t dot_;
    const string_t dot_token_;
    events_t& events_;
    string_t token_;
    final_t final_;
    final_t old_final_;
    put_t put_;
    put_t old_put_;
};
typedef readert<> reader;

} // namespace match 
} // namespace path 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_PATH_MATCH_READER_HPP 
