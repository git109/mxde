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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 8/26/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_WRITER_HPP
#define _XOS_NADIR_XOS_IO_WRITER_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace io {

typedef base::implement_base writer_implement;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TImplements = writer_implement>

class _EXPORT_CLASS writert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) { return 0; }
    virtual ssize_t flush() { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writel(const what_t* what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = writev(what, va);
        va_end(va);
        return count;
    }
    virtual ssize_t writev(const what_t* what, va_list va) {
        ssize_t count = 0;
        ssize_t length = 0;
        for (count = 0; what; count += length) {
            if (0 > (length = write(what)))
                return count;
            what = va_arg(va, const sized_t*);
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writef(const what_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = writefv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t writefv(const what_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef writert<> writer;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef writert<char, char, int, 0> char_writer;
typedef writert<wchar_t, wchar_t, int, 0> wchar_writer;
typedef writert<tchar_t, tchar_t, int, 0> tchar_writer;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef writert<byte_t, byte_t, int, 0> byte_writer;
typedef writert<word_t, word_t, int, 0> word_writer;

} // namespace io
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_WRITER_HPP 
