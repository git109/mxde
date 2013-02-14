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
///   File: XosHelloMain.hpp
///
/// Author: $author$
///   Date: 2/5/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSHELLOMAIN_HPP
#define _XOSHELLOMAIN_HPP

#include "XosOptMain.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
///  Class: XosHelloMain
///
/// Author: $author$
///   Date: 2/5/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosHelloMain
: public XosOptMain
{
public:
    typedef XosOptMain Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosHelloMain
    ///
    ///       Author: $author$
    ///         Date: 2/5/2013
    ///////////////////////////////////////////////////////////////////////
    XosHelloMain()
    : m_who(0)
    {
    }
    virtual ~XosHelloMain()
    {
    }
    virtual int Run(int argc, char** argv, char** env)
    {
        int err = 0;
        if ((optind < argc)) 
            m_who = argv[optind];
        printf("Hello %s\n", (m_who)?(m_who):(""));
        return err;
    }
protected:
    const char* m_who;
};


#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSHELLOMAIN_HPP 
        

