///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2013 $organization$
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
///   File: Processor_instance.cpp
///
/// Author: $author$
///   Date: 12/1/2013
///////////////////////////////////////////////////////////////////////
#include "xos/inet/http/server/Processor.hpp"
#include "xos/inet/http/server/Daemon.hpp"

namespace xos {
namespace http {
namespace server {
namespace hello {

typedef server::Processor ProcessorExtend;
class Processor: public ProcessorExtend {
public:
    typedef ProcessorExtend Extends;
    virtual bool Process(Response& response, const Request& request) {
        String contentType("text/html");
        http::Form::Field formField;
        XOS_LOG_TRACE("in...");
        if ((request.form().GetField(formField, "content_type"))) {
            const String& fieldValue(formField.GetValue());
            if (0 < (fieldValue.Length())) {
                XOS_LOG_TRACE("content_type = \"" << fieldValue << "\"");
                contentType.Assign(fieldValue);
            }
        }
        response.headers().SetContentType(contentType);
        response.message().Assign("<b>Hello</b>");
        if ((request.form().GetField(formField, "who"))) {
            const String& fieldValue(formField.GetValue());
            if (0 < (fieldValue.Length())) {
                XOS_LOG_TRACE("who = \"" << fieldValue << "\"");
                response.message().Append(" <b>");
                response.message().Append(fieldValue);
                response.message().Append("</b>");
            }
        }
        if ((request.form().GetField(formField, "action"))) {
            const String& fieldValue(formField.GetValue());
            xos::Daemon& daemon = xos::Daemon::GetTheInstance();
            if (0 < (fieldValue.Length())) {
                XOS_LOG_TRACE("action = \"" << fieldValue << "\"");
                if (!(fieldValue.Compare("restart"))) {
                    daemon.Restart();
                } else
                if (!(fieldValue.Compare("stop"))) {
                    daemon.Stop();
                }
            }
        }
        XOS_LOG_TRACE("...out");
        return true;
    }
};

} // namespace hello

Processor& Processor::GetTheInstance() {
    static hello::Processor the_processor;
    return the_processor;
}

} // namespace server 
} // namespace http 
} // namespace xos 
