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
///   File: main.cpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#include "xos/base/main.hpp"
#include "xos/io/main/logger.hpp"
#include "xos/mt/main/mutex.hpp"

namespace xos {
namespace base {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TChar, typename TEnd, TEnd VEnd,
 class TImplements, class TExtends>
int maint<TChar, TEnd, VEnd, TImplements, TExtends>::the_main
(int argc, char_t** argv, char_t** env) {
    int err = 1;
    maint* main;

    if ((main = get_the_main())) {
        mt::main::mutext<maint> mutex(*main);
        io::main::loggert<TChar, TEnd, VEnd, maint> logger(*main);

        // initialize logger
        //
        XOS_LOGGER_INIT();

        // set logging level to XOS_DEFAULT_LOGGING_LEVELS_ID
        //
        //XOS_SET_LOGGING_LEVELS_TO_DEFAULT_LOGGING_LEVELS_ID();

        err = (*main)(argc, argv, env);

        // finalize logger
        //
        XOS_LOGGER_FINI();
    }
    return err;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<typename TChar, typename TEnd, TEnd VEnd,
 class TImplements, class TExtends>
maint<TChar, TEnd, VEnd, TImplements, TExtends>*&
maint<TChar, TEnd, VEnd, TImplements, TExtends>::get_the_main() {
    static maint<TChar, TEnd, VEnd, TImplements, TExtends>* the_main = 0;
    return the_main;
}

} // namespace base 
} // namespace xos 
