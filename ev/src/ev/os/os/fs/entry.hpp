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
///   Date: 11/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _EV_OS_OS_FS_ENTRY_HPP
#define _EV_OS_OS_FS_ENTRY_HPP

#include "ev/os/os.hpp"

#if defined(WINDOWS)
#include "ev/os/windows/fs/entry.hpp"
#elif defined(MACOSX)
#include "ev/os/macosx/fs/entry.hpp"
#else // defined(WINDOWS)
#include "ev/os/unix/fs/entry.hpp"
#endif // defined(WINDOWS)

namespace ev {
namespace os {

} // namespace os 
} // namespace ev 

#endif // _EV_OS_OS_FS_ENTRY_HPP 
