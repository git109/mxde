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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 8/27/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_READER_HPP
#define _XOS_NADIR_XOS_IO_READER_HPP

#include "xos/mt/locker.hpp"

namespace xos {
namespace io {

typedef base::implement_base reader_implement;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = void, typename TSized = char,
 typename TEnd = int, TEnd VEnd = 0,
 class TImplements = reader_implement>

class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) { return 0; }
    virtual ssize_t fill() { return 0; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t readf(const what_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        count = readfv(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t readfv(const what_t* format, va_list va) {
        ssize_t count = 0;
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef readert<> reader;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef readert<char, char, int, 0> char_reader;
typedef readert<wchar_t, wchar_t, int, 0> wchar_reader;
typedef readert<tchar_t, tchar_t, int, 0> tchar_reader;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef readert<byte_t, byte_t, int, 0> byte_reader;
typedef readert<word_t, word_t, int, 0> word_reader;

} // namespace io
} // namespace xos

#endif // _XOS_NADIR_XOS_IO_READER_HPP
