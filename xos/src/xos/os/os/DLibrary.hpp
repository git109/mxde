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
///   File: DLibrary.hpp
///
/// Author: $author$
///   Date: 10/24/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_OS_OS_DLIBRARY_HPP
#define _XOS_OS_OS_DLIBRARY_HPP

#include "xos/os/os/Os.hpp"

#if defined(WINDOWS) 
// Windows
typedef HMODULE DLIBRARY_T;
typedef DLIBRARY_T INVALID_DLIBRARY_T;
#define INVALID_DLIBRARY 0
#define DLIBRARY_FILE_EXTENSION_CHARS "dll"
#else // defined(WINDOWS) 
// Unix
#include <dlfcn.h>
typedef void* DLIBRARY_T;
typedef unsigned INVALID_DLIBRARY_T;
#define INVALID_DLIBRARY 0
#if defined(MACOSX)
// MacOSX
#define DLIBRARY_FILE_EXTENSION_CHARS "dylib"
#else // defined(MACOSX)
#define DLIBRARY_FILE_EXTENSION_CHARS "so"
#endif // defined(MACOSX)
#endif // defined(WINDOWS)

#define DLIBRARY_SYMBOL_(identifier) "" #identifier ""
#define DLIBRARY_SYMBOL(identifier) DLIBRARY_SYMBOL_(identifier)

#if defined(WINDOWS) 
// Windows
#include "xos/os/windows/DLibrary.hpp"
#elif defined(MACOSX) 
// MacOSX
#include "xos/os/macosx/DLibrary.hpp"
#else // defined(WINDOWS) 
// Unix
#include "xos/os/unix/DLibrary.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace os {

} // namespace os 
} // namespace xos 

#endif // _XOS_OS_OS_DLIBRARY_HPP 
