///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
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
///   File: Stream.hpp
///
/// Author: $author$
///   Date: Aug 15, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_STREAM_HPP_
#define _XOS_STREAM_HPP_

#include "xos/base/Locked.hpp"

namespace xos {

template
<class TWhat=void, class TEnd=int, TEnd VEnd=0,
 class TImplement=LockedInterface, 
 typename TStatus=LockedInterface::Status,
 TStatus VSuccess=LockedInterface::Success>

class EXPORT_CLASS StreamBase: virtual public TImplement {
public:
    typedef TImplement Implements;
    typedef TWhat WhatT;
    typedef TEnd EndT;

    enum Whence {
        FromBegin,
        FromEnd,
        FromCurrent
    };

    virtual ssize_t Read(WhatT* what, size_t size) = 0;
    virtual ssize_t Write(const WhatT* what, ssize_t size = -1) = 0;

    virtual ssize_t Fill() = 0;
    virtual ssize_t Flush() = 0;

    virtual ssize_t Seek(size_t size, Whence whence = FromBegin) = 0;
    virtual ssize_t Tell() const = 0;

    virtual bool Lock(){ return true; }
    virtual bool Unlock(){ return true; }
    virtual TStatus TryLock(){ return VSuccess; }
    virtual TStatus TimedLock(mseconds_t waitMilliseconds){ return VSuccess; }

protected:
    static const EndT End = (EndT)(VEnd);
};

typedef StreamBase<void> Stream;
typedef StreamBase<char> CharStream;
typedef StreamBase<wchar_t> WCharStream;
typedef StreamBase<tchar_t> TCharStream;

} // namespace xos

#endif // _XOS_STREAM_HPP_ 
