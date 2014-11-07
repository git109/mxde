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
///   File: opener.hpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_OPENER_HPP
#define _XOS_NADIR_XOS_BASE_OPENER_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace base {

typedef implement_base opener_implements;
///////////////////////////////////////////////////////////////////////
///  Class: openert
///////////////////////////////////////////////////////////////////////
template <class TImplements = opener_implements>

class _EXPORT_CLASS openert: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum exception {
        failed_to_open,
        failed_to_close
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open() {
        return false;
    }
    virtual bool close() {
        return false;
    }
    virtual bool closed() {
        if ((this->is_open()))
            return this->close();
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool sei_is_open(bool is_true = true) {
        return false;
    }
    virtual bool is_open() const {
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef openert<> opener;

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_OPENER_HPP 
