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
///   File: Writer.hpp
///
/// Author: $author$
///   Date: 4/17/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_WRITER_HPP
#define _XOS_IO_WRITER_HPP

#include "xos/io/Sequence.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0, class TImplement = Sequence>

class _EXPORT_CLASS WriterT: virtual public TImplement {
public:
    typedef TImplement Implements;
    typedef TWhat WhatT;
    typedef TSized SizedT;
    typedef TEnd EndT;
    enum { End = VEnd };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write(const WhatT* what, ssize_t size = -1) { return 0; }
    virtual ssize_t Flush() { return 0; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteL(const WhatT* what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = WriteV(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t WriteV(const WhatT* what, va_list va) {
        ssize_t count = 0;
        ssize_t length = 0;
        for (count = 0; what; count += length) {
            if (0 > (length = Write(what)))
                return count;
            what = va_arg(va, const SizedT*);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t WriteFormatted(const WhatT* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = WriteFormattedV(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t WriteFormattedV(const WhatT* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Writex(const void* bytes, ssize_t length=-1, char a = 'a', char between = 0) {
        ssize_t count = WriteX(bytes, length, a, between);
        return count;
    }
    virtual ssize_t WriteX(const void* bytes, ssize_t length=-1, char A = 'A', char between = 0) {
        ssize_t count = 0;
        const uint8_t* byte;
        if ((byte = (const uint8_t*)(bytes))) {
            SizedT t = (SizedT)(between);
            ssize_t written;
            uint8_t b;
            SizedT x[2];
            if (0 <= length) {
                for (; 0 < length; --length) {
                    if ((byte != bytes) && (between)) {
                        if (0 > (written = Write((const WhatT*)(&t), 1)))
                            return written;
                        count += written;
                    }
                    b = (*byte++);
                    x[0] = this->DToX(b >> 4, A);
                    x[1] = this->DToX(b & 15, A);
                    if (0 > (written = Write((const WhatT*)(x), 2)))
                        return written;
                    count += written;
                }
            } else {
                for (; (b = (*byte)); ++byte) {
                    if ((byte != bytes) && (between)) {
                        if (0 > (written = Write((const WhatT*)(&t), 1)))
                            return written;
                        count += written;
                    }
                    x[0] = this->DToX(b >> 4, A);
                    x[1] = this->DToX(b & 15, A);
                    if (0 > (written = Write((const WhatT*)(x), 2)))
                        return written;
                    count += written;
                }
            }
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WriterT<> Writer;

} // namespace io 
} // namespace xos 

#endif // _XOS_IO_WRITER_HPP 
