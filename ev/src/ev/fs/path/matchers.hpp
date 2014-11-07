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
///   File: matchers.hpp
///
/// Author: $author$
///   Date: 11/3/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_PATH_MATCHERS_HPP
#define _EV_FS_PATH_MATCHERS_HPP

#include "ev/fs/path/match/reader.hpp"
#include "ev/fs/path/match/read/events.hpp"
#include "ev/fs/path/matcher.hpp"
#include "ev/base/base.hpp"

#include <deque>

namespace ev {
namespace fs {
namespace path {

typedef match::reader matchers_reader;
typedef matcher matchers_matcher;
typedef std::deque<matchers_matcher*> matchers_matchers_extend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TMatcher = matchers_matcher,
 class TExtends = matchers_matchers_extend>

class _EXPORT_CLASS matchers_matcherst: public TExtends {
public:
    typedef TExtends Extends;
    typedef TMatcher matcher_t;
    typedef typename matchers_matcherst<TMatcher, TExtends>::iterator iterator;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ~matchers_matcherst() {
        clear();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual matchers_matcherst& clear() {
        iterator end = this->end();
        matcher_t* matcher;
        for (iterator i = this->begin(); i != end; ++i) {
            if ((matcher = *i)) {
                delete matcher;
            }
        }
        Extends::clear();
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef matchers_matcherst<> matchers_matchers;

typedef match::read::events matchers_implements;
typedef base matchers_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matcherst
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,class TMatcher = matchers_matcher,
 class TMatchers = matchers_matchers, class TReader = matchers_reader,
 class TImplements = matchers_implements, class TExtends = matchers_extends>

class _EXPORT_CLASS matcherst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TMatchers matchers_t;
    typedef TMatcher matcher_t;
    typedef TReader reader_t;
    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    typedef typename TMatchers::const_iterator const_iterator;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matcherst() {}
    virtual ~matcherst() {
        matchers_.clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        const_iterator end = matchers_.end();
        matcher_t* matcher;
        for (const_iterator i = matchers_.begin(); i != end; ++i) {
            if ((matcher = *i)) {
                if ((matcher->matches(parts, ignore_case))) {
                    return true;
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool read(const char_t* chars, size_t length) {
        matchers_.clear();
        return this->read_more(chars, length);
    }
    virtual bool read(const char_t* chars) {
        matchers_.clear();
        return this->read_more(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool read_more(const char_t* chars, size_t length) {
        reader_t reader(*this);
        return reader.read(chars, length);
    }
    virtual bool read_more(const char_t* chars) {
        reader_t reader(*this);
        return reader.read(chars);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_any() {
        EV_LOG_DEBUG("match file any");
        matcher_t* m;
        if ((m = new any::matcher())) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_with_extension() {
    }
    virtual void on_match_file_without_extension() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_name(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file name \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::name::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_name_prefix(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file name prefix \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::name::prefix::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_name_suffix(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file name suffix \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::name::suffix::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_base(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file base \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::base::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_base_prefix(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file base prefix\"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::base::prefix::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_base_suffix(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file base suffix \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::base::suffix::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_extension(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file extension \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::extension::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_extension_prefix(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file extension prefix\"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::extension::prefix::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }
    virtual void on_match_file_extension_suffix(const char_t* chars, size_t length) {
        EV_LOG_DEBUG("match file extension suffix \"" << chars << "\"");
        matcher_t* m;
        if ((m = new file::extension::suffix::matcher(chars, length))) {
            matchers_.push_back(m);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    matchers_t matchers_;
};
typedef matcherst<> matchers;

} // namespace path 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_PATH_MATCHERS_HPP 
