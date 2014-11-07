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
///   File: base.hpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_BASE_BASE_HPP
#define _EV_BASE_BASE_HPP

#include "xos/base/string.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/io/logger.hpp"

#define EV_LOG_FATAL XOS_LOG_FATAL
#define EV_LOG_ERROR XOS_LOG_ERROR
#define EV_LOG_WARN XOS_LOG_WARN
#define EV_LOG_INFO XOS_LOG_INFO
#define EV_LOG_DEBUG XOS_LOG_DEBUG
#define EV_LOG_TRACE XOS_LOG_TRACE

#define EV_LOG_FATALF XOS_LOG_FATALF
#define EV_LOG_ERRORF XOS_LOG_ERRORF
#define EV_LOG_WARNF XOS_LOG_WARNF
#define EV_LOG_INFOF XOS_LOG_INFOF
#define EV_LOG_DEBUGF XOS_LOG_DEBUGF
#define EV_LOG_TRACEF XOS_LOG_TRACEF

namespace ev {

typedef xos::base::implement_base implement_base;
typedef xos::base::base base;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS bool_t {
public:
    bool_t(bool is_true = false): is_true_(is_true) {}
    bool_t(const bool_t& copy): is_true_(copy.is_true_) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    bool_t& operator = (bool is_true) { is_true_ = is_true; return *this; }
    operator bool() const { return is_true_; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_true_;
};

typedef xos::base::attacher_implements attacher_implements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = attacher_implements>

using attachert = typename xos::base::attachert
<TAttached, TUnattached, VUnattached, TImplements>;

typedef xos::base::attached_extends attached_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, attacher_implements>,
 class TExtends = attached_extends>

using attachedt = typename xos::base::attachedt
<TAttached, TUnattached, VUnattached, TImplements, TExtends>;

typedef xos::base::opener_implements opener_implements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template<class TImplements = opener_implements>

using openert = typename xos::base::openert<TImplements>;
typedef xos::base::opener opener;

typedef opener_implements opened_implements;
typedef xos::base::opened_extends opened_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, opened_implements>,
 class TExtends = attachedt
 <TAttached, TUnattached, VUnattached, TImplements, opened_extends> >

using openedt = typename xos::base::openedt
<TAttached, TUnattached, VUnattached, TImplements, TExtends>;
typedef xos::base::opened opened;

typedef xos::base::string_implement string_implements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string<TChar>, class TImplements = string_implements>

using stringt = typename xos::base::stringt
<TChar, TEnd, VEnd, TExtends, TImplements>;
typedef xos::base::string string_t;
typedef xos::base::tstring tstring_t;
typedef xos::base::wstring wstring_t;

} // namespace ev

#endif // _EV_BASE_BASE_HPP 
