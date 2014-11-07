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
///   File: events.hpp
///
/// Author: $author$
///   Date: 11/3/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_FS_PATH_MATCH_READ_EVENTS_HPP
#define _EV_FS_PATH_MATCH_READ_EVENTS_HPP

#include "ev/base/base.hpp"

namespace ev {
namespace fs {
namespace path {
namespace match {
namespace read {

typedef implement_base events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: eventst
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,  typename TEnd = TChar, TEnd VEnd = 0,
 class TImplements = events_implements>

class _EXPORT_CLASS eventst: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef TEnd end_t;
    enum { end = VEnd };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_any() {
    }
    virtual void on_match_file_with_extension() {
    }
    virtual void on_match_file_without_extension() {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_name(const char_t* chars, size_t length) {
    }
    virtual void on_match_file_name_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_file_name_suffix(const char_t* chars, size_t length) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_base(const char_t* chars, size_t length) {
    }
    virtual void on_match_file_base_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_file_base_suffix(const char_t* chars, size_t length) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_file_extension(const char_t* chars, size_t length) {
    }
    virtual void on_match_file_extension_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_file_extension_suffix(const char_t* chars, size_t length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_directory_any() {
    }
    virtual void on_match_directory_with_extension() {
    }
    virtual void on_match_directory_without_extension() {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_directory_name(const char_t* chars, size_t length) {
    }
    virtual void on_match_directory_name_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_directory_name_suffix(const char_t* chars, size_t length) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_directory_base(const char_t* chars, size_t length) {
    }
    virtual void on_match_directory_base_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_directory_base_suffix(const char_t* chars, size_t length) {
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_directory_extension(const char_t* chars, size_t length) {
    }
    virtual void on_match_directory_extension_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_directory_extension_suffix(const char_t* chars, size_t length) {
    }


    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_match_path_any() {
    }
    virtual void on_match_path_name(const char_t* chars, size_t length) {
    }
    virtual void on_match_path_prefix(const char_t* chars, size_t length) {
    }
    virtual void on_match_path_suffix(const char_t* chars, size_t length) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef eventst<> events;

} // namespace read 
} // namespace match 
} // namespace path 
} // namespace fs 
} // namespace ev 

#endif // _EV_FS_PATH_MATCH_READ_EVENTS_HPP 
