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
///   File: FILEStream.hpp
///
/// Author: $author$
///   Date: Aug 25, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_FILESTREAM_HPP_
#define _XOS_FILESTREAM_HPP_

#include "xos/base/Stream.hpp"
#include "xos/os/Logger.hpp"

namespace xos {

typedef Stream FILEStreamImplement;
typedef Attached<FILE*, int> FILEStreamExtend;

class EXPORT_CLASS FILEStream: virtual public FILEStreamImplement, public FILEStreamExtend {
public:
    typedef FILEStreamImplement Implements;
    typedef FILEStreamExtend Extends;

    FILEStream(FILE* detached=0, LockedInterface* locked=0)
    : Extends(detached),m_locked(locked){}
    virtual ~FILEStream(){}

    virtual ssize_t Read(WhatT* what, size_t size){
        ssize_t count = -Error::Failed;
        if ((m_attachedTo))
        if (0 >= (count = fread(what, 1, size, m_attachedTo))){
            XOS_LOG_ERROR("failed on fread()");
            count = -Error::Failed;
        }
        return count;
    }
    virtual ssize_t Write(const WhatT* what, ssize_t size = -1){
        ssize_t count = -Error::Failed;
        if ((m_attachedTo)){
            if (0 > (size))
                size = strlen((const char*)(what));
            if (0 >= (count = fwrite(what, 1, size, m_attachedTo))){
                XOS_LOG_ERROR("failed on fwrite()");
                count = -Error::Failed;
            }
        }
        return count;
    }

    virtual ssize_t Fill(){ return 0; }
    virtual ssize_t Flush(){
        ssize_t count = -Error::Failed;
        int err;
        if ((m_attachedTo))
        if ((err = fflush(m_attachedTo))){
            XOS_LOG_ERROR("failed " << err << " on fflush()");
            count = -Error::Failed;
        }
        return count;
    }

    virtual ssize_t Seek(size_t size, Whence whence = FromBegin){
        int origin = (FromBegin != whence)?((FromEnd != whence)?(SEEK_CUR):(SEEK_END)):(SEEK_SET);
        ssize_t count = -Error::Failed;
        int err;
        if ((m_attachedTo))
        if ((err = fseek(m_attachedTo, size, origin))){
            XOS_LOG_ERROR("failed " << err << " on fseek()");
            count = -Error::Failed;
        }
        return count;
    }
    virtual ssize_t Tell() const{
        ssize_t count = -Error::Failed;
        if ((m_attachedTo))
        if (0 > (count = ftell(m_attachedTo))){
            XOS_LOG_ERROR("failed on ftell()");
            count = -Error::Failed;
        }
        return count;
    }

    virtual bool Lock(){ return m_locked.Lock(); }
    virtual bool Unlock(){ return m_locked.Unlock(); }
    virtual Status TryLock(){ return m_locked.TryLock(); }
    virtual Status TimedLock(mseconds_t waitMilliseconds){ 
        return m_locked.TimedLock(waitMilliseconds); }
protected:
    LockedAttached m_locked;
};

} // namespace xos

#endif // _XOS_FILESTREAM_HPP_ 
