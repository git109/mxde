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
///   File: file.hpp
///
/// Author: $author$
///   Date: 11/9/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_IO_READ_FILE_HPP
#define _XOS_NADIR_XOS_IO_READ_FILE_HPP

#include "xos/io/file/reader.hpp"
#include "xos/io/file/opened.hpp"

namespace xos {
namespace io {
namespace read {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS file_implemnents
: virtual public io::file::reader,
  virtual public io::file::opened_implemnents {
};
typedef file::opened file_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = file_implemnents, class TExtends = file_extends>

class _EXPORT_CLASS filet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filet(FILE* attached = 0, bool is_open = false)
    : Extends(attached, is_open) {
    }
    virtual ~filet() {
        if (!(this->closed())) {
            base::opener::exception e = base::opener::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef filet<> file;

} // namespace read 
} // namespace io 
} // namespace xos 

#endif // _XOS_NADIR_XOS_IO_READ_FILE_HPP 
