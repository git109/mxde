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
///   File: Mutex.hpp
///
/// Author: $author$
///   Date: 4/15/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_MACOSX_MUTEX_HPP
#define _XOS_MT_MACOSX_MUTEX_HPP

#include "xos/mt/unix/Mutex.hpp"

namespace xos {
namespace mt {
namespace macosx {

///////////////////////////////////////////////////////////////////////
///  Class: MutexT
///////////////////////////////////////////////////////////////////////
template
<class TAttached = unix::MutextAttachedT,
 class TExtend = unix::Mutex,
 class TImplement = unix::MutexImplement>

class _EXPORT_CLASS MutexT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MutexT(TAttached attachedTo, bool isCreated): Extends(attachedTo, isCreated) {
    }
    MutexT(TAttached attachedTo): Extends(attachedTo) {
    }
    MutexT(bool initallyLocked): Extends(initallyLocked) {
    }
    MutexT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MutexT<> Mutex;

} // namespace macosx
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_MACOSX_MUTEX_HPP 
