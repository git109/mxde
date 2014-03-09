///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   File: File.hpp
///
/// Author: $author$
///   Date: 8/16/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_OS_FILE_HPP
#define _XOS_OS_FILE_HPP

#include "xos/base/Stream.hpp"
#include "xos/base/Opened.hpp"
#include "xos/base/Attached.hpp"
#include "xos/os/Logger.hpp"

#define XOS_FILE_MODE_READ "r"
#define XOS_FILE_MODE_WRITE "w"

#define XOS_FILE_MODE_BINARY "b"
#define XOS_FILE_MODE_APPEND "+"

#define XOS_FILE_MODE_READ_BINARY \
    XOS_FILE_MODE_READ \
    XOS_FILE_MODE_BINARY

#define XOS_FILE_MODE_WRITE_BINARY \
    XOS_FILE_MODE_WRITE \
    XOS_FILE_MODE_BINARY

namespace xos {

//
// void
//
typedef StreamBase FileImplement;
typedef ExportBase FileAttachedExtend;
typedef Attached
<FILE*, int, 0, FileAttachedExtend, FileImplement> FileAttached;
typedef Opened
<FILE*, int, 0, FileAttached, FileImplement> FileExtend;

///////////////////////////////////////////////////////////////////////
///  Class: FileBaseT
///////////////////////////////////////////////////////////////////////
template
<class TWhat=void, class TEnd=int, TEnd VEnd=0,
 class TExtend=FileExtend,
 class TImplement=FileImplement, 
 typename TWhence=FileImplement::Whence,
 TWhence VFromBegin=FileImplement::FromBegin,
 TWhence VFromEnd=FileImplement::FromEnd,
 typename TStatus=LockedInterface::Status,
 TStatus VSuccess=LockedInterface::Success>

class c_EXPORT_CLASS FileBaseT
: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TWhat WhatT;
    typedef TEnd EndT;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FileBaseT
    (FILE* detached=0, bool isOpen=false, 
     LockedInterface* locked=0, bool noLogging=false)
    : Extends(detached, isOpen), 
      m_locked(locked), 
      m_noLogging(noLogging) {
    }
    virtual ~FileBaseT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const char* fileName, const char* fileMode = "rb") {
        if (!(this->Closed()))
            return false;
        if ((fileName) && (fileMode)) {
            FILE* detached;
            if ((detached = fopen(fileName, fileMode))) {
                this->AttachOpened(detached);
                return true;
            } else {
                if (!(m_noLogging))
                {   XOS_LOG_ERROR("failed on fopen(\"" << fileName << "\", " << fileMode << "\")"); }
            }
        }
        return false;
    }
    virtual bool Close() {
        FILE* detached;
        if ((detached = this->Detach())) {
            int err;
            if (!(err = fclose(detached))) {
                return true;
            } else {
                if (!(m_noLogging))
                {   XOS_LOG_ERROR("failed on fclose()"); }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(WhatT* what, size_t size){
        ssize_t count = -Error::Failed;
        if ((this->m_attachedTo))
        if (0 >= (count = fread(what, sizeof(TWhat), size, this->m_attachedTo))){
            if (!(m_noLogging))
                XOS_LOG_TRACE("failed " << count << " on fread()");
            count = -Error::Failed;
        }
        return count;
    }
    virtual ssize_t Write(const WhatT* what, ssize_t size = -1){
        ssize_t count = -Error::Failed;
        if ((this->m_attachedTo)){
            if (0 > (size))
                size = Count(what);
            if (0 >= (count = fwrite(what, sizeof(TWhat), size, this->m_attachedTo))){
                if (!(m_noLogging))
                    XOS_LOG_ERROR("failed on fwrite()");
                count = -Error::Failed;
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Fill(){ return 0; }
    virtual ssize_t Flush(){
        ssize_t count = -Error::Failed;
        int err;
        if ((this->m_attachedTo))
        if ((err = fflush(this->m_attachedTo))){
            if (!(m_noLogging))
                XOS_LOG_ERROR("failed " << err << " on fflush()");
        } else {
            count = 0;
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Seek(size_t size, TWhence whence = VFromBegin){
        int origin = (VFromBegin != whence)?((VFromEnd != whence)?(SEEK_CUR):(SEEK_END)):(SEEK_SET);
        ssize_t count = -Error::Failed;
        int err;
        if ((this->m_attachedTo))
        if ((err = fseek(this->m_attachedTo, sizeof(TWhat)*size, origin))){
            if (!(m_noLogging))
                XOS_LOG_ERROR("failed " << err << " on fseek()");
        } else {
            count = size;
        }
        return count;
    }
    virtual ssize_t Tell() const{
        ssize_t count = -Error::Failed;
        if ((this->m_attachedTo))
        if (0 > (count = ftell(this->m_attachedTo))){
            if (!(m_noLogging))
                XOS_LOG_ERROR("failed on ftell()");
            count = -Error::Failed;
        } else {
            count /= sizeof(TWhat);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock(){ return m_locked.Lock(); }
    virtual bool Unlock(){ return m_locked.Unlock(); }
    virtual TStatus TryLock(){ return m_locked.TryLock(); }
    virtual TStatus TimedLock(mseconds_t waitMilliseconds){ 
        return m_locked.TimedLock(waitMilliseconds); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Count(const TWhat* what) const {
        const TEnd end = VEnd;
        size_t count = 0;
        if ((what))
        for (count = 0; ((*what) != end); ++what)
            ++count;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool noLogging() const {
        return m_noLogging;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    LockedAttached m_locked;
    bool m_noLogging;
};

typedef FileBaseT<void, int, 0, FileExtend, FileImplement> FileBase;

///////////////////////////////////////////////////////////////////////
///  Class: FileT
///////////////////////////////////////////////////////////////////////
template <class TExtend = FileBase, class TImplement = FileImplement>
class c_EXPORT_CLASS FileT: virtual public TImplement, public TExtend {
public:
    typedef TExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    FileT
    (FILE* detached=0, bool isOpen=false, 
     LockedInterface* locked=0, bool noLogging=false)
    : Extends(detached, isOpen, locked, noLogging) {
    }
    virtual ~FileT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormattedV(const char* format, va_list va) {
        ssize_t count = -Error::Failed;
        if ((this->m_attachedTo)){
            if (0 > (count = vfprintf(this->m_attachedTo, format, va))) {
                if (!(this->m_noLogging))
                    XOS_LOG_ERROR("failed on vfprintf()");
                count = -Error::Failed;
            }
        }
        return count;
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//
// char
//
typedef CharStreamBase CharFileImplement;
typedef ExportBase CharFileAttachedExtend;
typedef Attached
<FILE*, int, 0, CharFileAttachedExtend, CharFileImplement> CharFileAttached;
typedef Opened
<FILE*, int, 0, CharFileAttached, CharFileImplement> CharFileExtend;
//
// wchar_t
//
typedef WCharStreamBase WCharFileImplement;
typedef ExportBase WCharFileAttachedExtend;
typedef Attached
<FILE*, int, 0, WCharFileAttachedExtend, WCharFileImplement> WCharFileAttached;
typedef Opened
<FILE*, int, 0, WCharFileAttached, WCharFileImplement> WCharFileExtend;
//
// tchar_t
//
typedef TCharStreamBase TCharFileImplement;
typedef ExportBase TCharFileAttachedExtend;
typedef Attached
<FILE*, int, 0, TCharFileAttachedExtend, TCharFileImplement> TCharFileAttached;
typedef Opened
<FILE*, int, 0, TCharFileAttached, TCharFileImplement> TCharFileExtend;
//
// uint8_t
//
typedef ByteStreamBase ByteFileImplement;
typedef ExportBase ByteFileAttachedExtend;
typedef Attached
<FILE*, int, 0, ByteFileAttachedExtend, ByteFileImplement> ByteFileAttached;
typedef Opened
<FILE*, int, 0, ByteFileAttached, ByteFileImplement> ByteFileExtend;
//
// uint16_t
//
typedef WordStreamBase WordFileImplement;
typedef ExportBase WordFileAttachedExtend;
typedef Attached
<FILE*, int, 0, WordFileAttachedExtend, WordFileImplement> WordFileAttached;
typedef Opened
<FILE*, int, 0, WordFileAttached, WordFileImplement> WordFileExtend;
//
// uint32_t
//
typedef LongWordStreamBase LongWordFileImplement;
typedef ExportBase LongWordFileAttachedExtend;
typedef Attached
<FILE*, int, 0, LongWordFileAttachedExtend, LongWordFileImplement> LongWordFileAttached;
typedef Opened
<FILE*, int, 0, LongWordFileAttached, LongWordFileImplement> LongWordFileExtend;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef FileBaseT<char, int, 0, CharFileExtend, CharFileImplement> CharFileBase;
typedef FileBaseT<wchar_t, int, 0, WCharFileExtend, WCharFileImplement> WCharFileBase;
typedef FileBaseT<tchar_t, int, 0, TCharFileExtend, TCharFileImplement> TCharFileBase;

typedef FileBaseT<uint8_t, int, 0, ByteFileExtend, ByteFileImplement> ByteFileBase;
typedef FileBaseT<uint16_t, int, 0, WordFileExtend, WordFileImplement> WordFileBase;
typedef FileBaseT<uint32_t, int, 0, LongWordFileExtend, LongWordFileImplement> LongWordFileBase;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef FileT<FileBase> File;

typedef FileT<CharFileBase> CharFile;
typedef WCharFileBase WCharFile;
typedef TCharFileBase TCharFile;

typedef ByteFileBase ByteFile;
typedef WordFileBase WordFile;
typedef LongWordFileBase LongWordFile;

} // namespace xos 

#endif // _XOS_OS_FILE_HPP 
