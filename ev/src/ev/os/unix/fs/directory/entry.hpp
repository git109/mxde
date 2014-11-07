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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 11/1/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_OS_UNIX_FS_DIRECTORY_ENTRY_HPP
#define _EV_OS_UNIX_FS_DIRECTORY_ENTRY_HPP

#include "ev/fs/directory/entry.hpp"
#include "ev/os/unix/fs/entry.hpp"

#include <dirent.h>

namespace ev {
namespace os {
namespace unix {
namespace fs {
namespace directory {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS dirent_t {
public:
    dirent_t(const struct dirent* dirent = 0): dirent_(dirent) {}
    virtual ~dirent_t() {}
    ///////////////////////////////////////////////////////////////////////
    virtual dirent_t& operator = (const struct dirent* dirent) {
        dirent_ = dirent;
        return *this;
    }
    virtual const struct dirent& operator -> () const { return *dirent_; }
    virtual const struct dirent& operator * () const { return *dirent_; }
    virtual const struct dirent* operator & () const { return dirent_; }
    virtual operator const struct dirent*() const { return dirent_; }
    ///////////////////////////////////////////////////////////////////////
protected:
    const struct dirent* dirent_;
};

typedef ev::fs::directory::entry_implements entry_implements;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS entry_extends
: virtual public ev::os::unix::fs::entry, public ev::fs::directory::entry {
};
///////////////////////////////////////////////////////////////////////
///  Class: entryt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = entry_implements, class TExtends = entry_extends>

class _EXPORT_CLASS entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    entryt() {
    }
    virtual ~entryt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entryt& assign
    (const char_t* path, const char_t* directory, const struct dirent* dirent) {
        if ((path) && (directory) && (dirent)) {
            this->set_path(path);
            this->set_directory(directory);
            this->set_dirent(dirent);
            this->set_found(*dirent);
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::entry_type set_found(const struct dirent& dirent) {
        set_found_type(dirent);
        this->set_name(dirent.d_name, dirent.d_namlen);
        return this->get_found();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ev::fs::entry_type set_found_type(const struct dirent& dirent) {
        this->set_type(ev::fs::entry_type_none);
        switch (dirent.d_type) {
        case DT_REG:
            this->set_type(ev::fs::entry_type_file);
            break;
        case DT_DIR:
            this->set_type(ev::fs::entry_type_directory);
            break;
        case DT_LNK:
            this->set_type(ev::fs::entry_type_symbolic_link);
            break;
        case DT_BLK:
            this->set_type(ev::fs::entry_type_block_device);
            break;
        case DT_CHR:
            this->set_type(ev::fs::entry_type_char_device);
            break;
        case DT_FIFO:
            this->set_type(ev::fs::entry_type_pipe);
            break;
        case DT_SOCK:
            this->set_type(ev::fs::entry_type_socket);
            break;
        }
        return this->type();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const struct dirent* set_dirent(const struct dirent* dirent) {
        dirent_ = dirent;
        return (const struct dirent*)(dirent_);
    }
    virtual const struct dirent* dirent() const {
        return dirent_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    dirent_t dirent_;
};
typedef entryt<> entry;

} // namespace directory 
} // namespace fs 
} // namespace unix 
} // namespace os 
} // namespace ev 

#endif // _EV_OS_UNIX_FS_DIRECTORY_ENTRY_HPP 
