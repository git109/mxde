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
///   File: RestApp.cpp
///
/// Author: $author$
///   Date: 1/5/2014
///////////////////////////////////////////////////////////////////////
#include "RestApp.hpp"

namespace restapp {

typedef std::list<Processor*> Processors;
static Processors& processors() {
    static Processors processors;
    return processors;
}
///////////////////////////////////////////////////////////////////////
/// Class: Processor
///////////////////////////////////////////////////////////////////////
bool Processor::Add() {
    Processors& p = processors();
    p.push_back(this);
    return true;
}
bool Processor::Remove() {
    Processors& p = processors();
    Processors::iterator b = p.begin();
    Processors::iterator e = p.end();
    Processors::iterator i;
    for (i = b; i != e; ++i) {
        if ((*i) == this) {
            p.erase(i, i);
            break;
        }
    }
    return true;
}
Processor* Processor::Match(const String& path) {
    Processor* matched = 0;
    Processors& p = processors();
    Processors::iterator b = p.begin();
    Processors::iterator e = p.end();
    Processors::iterator i;
    for (i = b; i != e; ++i) {
        const String& pPath = (*i)->m_path;
        XOS_LOG_TRACE("matching \"" << pPath << "\" to \"" << path << "\"...");
        if (!(pPath.compare(path))) {
            XOS_LOG_TRACE("...matched \"" << pPath << "\" to \"" << path << "\"");
            matched = *i;
            break;
        }
    }
    return matched;
}

} // namespace restapp


namespace xos {
namespace http {
namespace server {

Processor& Processor::GetTheInstance() {
    static restapp::server::Processor the_processor;
    return the_processor;
}

} // namespace server
} // namespace http
} // namespace xos
