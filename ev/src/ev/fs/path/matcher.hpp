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
///   File: matcher.hpp
///
/// Author: $author$
///   Date: 11/3/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_PATH_MATCHER_HPP
#define _EV_FS_PATH_MATCHER_HPP

#include "ev/fs/path/parts.hpp"
#include "ev/base/base.hpp"

namespace ev {
namespace fs {
namespace path {

typedef implement_base matcher_implements;
typedef base matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : pattern_(chars, length) {
    }
    virtual ~matchert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.chars()) && (length = parts.length())) {
            does = this->matches(chars, length, ignore_case);
        }
        return does;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool matches
    (const char_t* chars, size_t length, bool ignore_case=false) const {
        bool does = false;
        int unequal;
        if (0 < pattern_.length()) {
            if (ignore_case)
                unequal = pattern_.compare_case(chars, length);
            else unequal = pattern_.compare(chars, length);
            does = !unequal;
        }
        return does;
    }
    virtual bool matches_prefix
    (const char_t* chars, size_t length, bool ignore_case=false) const {
        bool does = false;
        int unequal;
        if (0 < pattern_.length()) {
            if (ignore_case)
                unequal = pattern_.compare_begin_case(chars, length);
            else unequal = pattern_.compare_begin(chars, length);
            does = !unequal;
        }
        return does;
    }
    virtual bool matches_suffix
    (const char_t* chars, size_t length, bool ignore_case=false) const {
        bool does = false;
        int unequal;
        if (0 < pattern_.length()) {
            if (ignore_case)
                unequal = pattern_.compare_end_case(chars, length);
            else unequal = pattern_.compare_end(chars, length);
            does = !unequal;
        }
        return does;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string_t pattern_;
};
typedef matchert<> matcher;

///////////////////////////////////////////////////////////////////////
/// name
///////////////////////////////////////////////////////////////////////
namespace file {
namespace name {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_name().chars())
            && (length = parts.file_name().length())) {
            does = this->matches(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;

namespace prefix {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_name().chars())
            && (length = parts.file_name().length())) {
            does = this->matches_prefix(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;
} // namespace prefix

namespace suffix {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_name().chars())
            && (length = parts.file_name().length())) {
            does = this->matches_suffix(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;
} // namespace suffix
} // namespace name

///////////////////////////////////////////////////////////////////////
/// base
///////////////////////////////////////////////////////////////////////
namespace base {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_base().chars())
            && (length = parts.file_base().length())) {
            does = this->matches(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;

namespace prefix {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_base().chars())
            && (length = parts.file_base().length())) {
            does = this->matches_prefix(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;
} // namespace prefix

namespace suffix {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_base().chars())
            && (length = parts.file_base().length())) {
            does = this->matches_suffix(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;
} // namespace suffix
} // namespace base

///////////////////////////////////////////////////////////////////////
/// extension
///////////////////////////////////////////////////////////////////////
namespace extension {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_extension().chars())
            && (length = parts.file_extension().length())) {
            does = this->matches(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;

namespace prefix {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_extension().chars())
            && (length = parts.file_extension().length())) {
            does = this->matches_prefix(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;
} // namespace prefix

namespace suffix {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(const char_t* chars, ssize_t length = -1)
    : Extends(chars, length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::matches;
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        bool does = false;
        const char_t* chars;
        size_t length;
        if ((chars = parts.file_extension().chars())
            && (length = parts.file_extension().length())) {
            does = this->matches_suffix(chars, length, ignore_case);
        }
        return does;
    }
};
typedef matchert<> matcher;
} // namespace suffix
} // namespace extension
} // namespace file

namespace any {
typedef path::matcher_implements matcher_implements;
typedef path::matcher matcher_extends;
///////////////////////////////////////////////////////////////////////
///  Class: matchert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TParts = parts,
 class TImplements = matcher_implements, class TExtends = matcher_extends>

class _EXPORT_CLASS matchert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TParts parts_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    matchert(): Extends(0, 0) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool matches(const parts_t& parts, bool ignore_case=false) const {
        return true;
    }
};
typedef matchert<> matcher;
} // namespace any

} // namespace path
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_PATH_MATCHER_HPP 
