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
///   File: creator.hpp
///
/// Author: $author$
///   Date: 9/19/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_CREATOR_HPP
#define _XOS_NADIR_XOS_BASE_CREATOR_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///  Enum: creator_exception
///////////////////////////////////////////////////////////////////////
enum creator_exception {
    failed_to_create,
    failed_to_destroy
};

typedef implement_base creator_implements;
///////////////////////////////////////////////////////////////////////
///  Class: creatort
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int,
 TUnattached VUnattached = 0,
 class TImplements = creator_implements>

class _EXPORT_CLASS creatort: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        if ((this->destroyed())) {
            return this->set_is_created();
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            this->set_is_created(false);
            return this->is_destroyed();
        }
        return false;
    }
    virtual bool destroyed() {
        if ((this->is_created())) {
            return this->destroy();
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_created(bool to = true) {
        return false;
    }
    virtual bool is_created() const {
        return false;
    }
    virtual bool is_destroyed() const {
        return false;
    }
};

typedef creatort<> creator;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_CREATOR_HPP 
