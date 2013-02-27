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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 12/23/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_OS_MAIN_OPT_HPP
#define _XOS_OS_MAIN_OPT_HPP

#include "xos/base/Base.hpp"
#include "xos/os/Logger.hpp"
#include <getopt.h>

#define XOS_MAIN_2STRING_(id) #id
#define XOS_MAIN_2STRING(id) XOS_MAIN_2STRING_(id)

#define XOS_MAIN_OPTIONS_CHARS "l:h"
#define XOS_MAIN_OPTIONS_OPTIONS \
            {"logging-level", XOS_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'l'},\
            {"help", XOS_MAIN_OPT_ARGUMENT_NONE, 0, 'h'},

enum {
    XOS_MAIN_OPT_ARGUMENT_NONE     = 0,
    XOS_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    XOS_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

namespace xos {

typedef int MainOptArgument;
enum {
    MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};

int OnLoggingLevel(const char* optarg);

int OnLoggingOption
(int optval, const char* optarg,
 const char* optname, int optind,
 int argc, char**argv, char**env);

} // namespace xos 

#endif // _XOS_OS_MAIN_OPT_HPP 
