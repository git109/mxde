////////////////////////////////////////////////////////////////////////
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
///   File: Processors.cpp
///
/// Author: $author$
///   Date: 1/9/2014
////////////////////////////////////////////////////////////////////////
#include "examples/clock/server/implement/Processors.hpp"

namespace restapp {
namespace examples {
namespace clock {
namespace server {
namespace implement {

static RestartServiceProcessor the_RestartServiceProcessor;
static StopServiceProcessor the_StopServiceProcessor;
static StartProcessor the_StartProcessor;
static StopProcessor the_StopProcessor;
static TickProcessor the_TickProcessor;
static SetTickSecondsProcessor the_SetTickSecondsProcessor;
static GetTickSecondsProcessor the_GetTickSecondsProcessor;
static AddTickEventListenerProcessor the_AddTickEventListenerProcessor;
static RemoveTickEventListenerProcessor the_RemoveTickEventListenerProcessor;


static RestartServiceProcessor the_RestartServiceProcessor2("/examples/Clock/RestartService");
static StopServiceProcessor the_StopServiceProcessor2("/examples/Clock/StopService");
static StartProcessor the_StartProcessor2("/examples/Clock/Start");
static StopProcessor the_StopProcessor2("/examples/Clock/Stop");
static TickProcessor the_TickProcessor2("/examples/Clock/OnTickEvent");
static SetTickSecondsProcessor the_SetTickSecondsProcessor2("/examples/Clock/SetTickSeconds");
static GetTickSecondsProcessor the_GetTickSecondsProcessor2("/examples/Clock/GetTickSeconds");
static AddTickEventListenerProcessor the_AddTickEventListenerProcessor2("/examples/Clock/AddEventListener");
static RemoveTickEventListenerProcessor the_RemoveTickEventListenerProcessor2("/examples/Clock/RemoveEventListener");

} // namespace implement
} // namespace server
} // namespace clock
} // namespace examples
} // namespace restapp
