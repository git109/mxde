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
///   File: path.hpp
///
/// Author: $author$
///   Date: 10/31/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_OS_UNIX_FS_DIRECTORY_PATH_HPP
#define _EV_OS_UNIX_FS_DIRECTORY_PATH_HPP

#include "ev/fs/directory/path.hpp"
#include "ev/os/unix/fs/directory/entry.hpp"

namespace ev {
namespace os {
namespace unix {
namespace fs {
namespace directory {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS attacher_implements
: virtual public ev::fs::directory::path,
  virtual public entry_implements {
};
typedef ev::fs::directory::entry path_entry;
typedef DIR* path_attached_t;
typedef attachert<path_attached_t, int, 0, attacher_implements> path_attacher;
typedef attachedt<path_attached_t, int, 0, path_attacher, entry> path_attached;
typedef openedt<path_attached_t, int, 0, path_attacher, path_attached> path_opened;
typedef path_attacher path_implements;
typedef path_opened path_extends;
///////////////////////////////////////////////////////////////////////
///  Class: patht
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TString = string_t, class TEntry = path_entry,
 class TImplements = path_implements, class TExtends = path_extends>

class _EXPORT_CLASS patht
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef path_attached_t attached_t;
    typedef TEntry entry_t;
    typedef TString string_t;
    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    patht() {
    }
    virtual ~patht() {
        if (!(this->closed())) {
            opener::exception e = opener::failed_to_close;
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char_t* name, const char_t* directory) {
        if ((name) && (directory)) {
            if ((open(name))) {
                this->set_directory(directory);
                return true;
            }
        }
        return false;
    }
    virtual bool open(const char_t* name) {
        if ((name)) {
            if ((this->closed())) {
                attached_t d = 0;
                if ((d = opendir(name))) {
                    this->set_path(name);
                    this->attach_opened(d);
                    return true;
                } else {
                    EV_LOG_ERROR("failed " << errno << " on opendir(\"" << name << "\")");
                }
            }
        }
        return false;
    }
    virtual bool close() {
        attached_t d = 0;
        if ((d = this->detach())) {
            int err = 0;
            if (!(err = closedir(d))) {
                return true;
            } else {
                EV_LOG_ERROR("failed " << err << " on closedir()");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual entry_t* get_first_entry() {
        return this->get_next_entry();
    }
    virtual entry_t* get_next_entry() {
        attached_t d = 0;
        if ((d = this->attached_to())) {
            const struct dirent* dirent = 0;
            if ((dirent = readdir(d))) {
                entry_.assign(this->path(), this->directory(), dirent);
                return &entry_;
            } else {
                EV_LOG_DEBUG("failed on readdir()");
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    entry entry_;
};
typedef patht<> path;

} // namespace directory 
} // namespace fs 
} // namespace unix 
} // namespace os 
} // namespace ev 

#endif // _EV_OS_UNIX_FS_DIRECTORY_PATH_HPP 
