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
///   File: opened.hpp
///
/// Author: $author$
///   Date: 11/1/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_OPENED_HPP
#define _XOS_NADIR_XOS_BASE_OPENED_HPP

#include "xos/base/opener.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"

namespace xos {
namespace base {

typedef opener opened_implements;
typedef base opened_extends;
///////////////////////////////////////////////////////////////////////
///  Class: openedt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached = void*,
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, opened_implements>,
 class TExtends = attachedt
 <TAttached, TUnattached, VUnattached, TImplements, opened_extends> >

class _EXPORT_CLASS openedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    openedt
    (attached_t attached = (attached_t)(unattached), bool is_open = false)
    : Extends(attached), is_open_(is_open) {
    }
    virtual ~openedt() {
        if (!(this->closed())) {
            opener::exception e = opener::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open() {
        if ((this->closed()))
            return this->set_is_open();
        return false;
    }
    virtual bool close() {
        if ((this->is_open())) {
            this->set_is_open(false);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_open(bool is_true = true) {
        is_open_ = is_true;
        return is_open_;
    }
    virtual bool is_open() const {
        return is_open_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach_opened
    (attached_t detached, bool is_open = true) {
        this->set_is_open(is_open);
        return Extends::attach(detached);
    }
    virtual attached_t detach_opened(bool& is_open) {
        is_open = this->is_open();
        return this->detach();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t attach(attached_t detached) {
        this->set_is_open(false);
        return Extends::attach(detached);
    }
    virtual attached_t detach() {
        this->set_is_open(false);
        return Extends::detach();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_open_;
};
typedef openedt<> opened;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_OPENED_HPP 
