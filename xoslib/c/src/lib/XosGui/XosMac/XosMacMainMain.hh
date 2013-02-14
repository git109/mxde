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
///   File: XosMacMainMain.hh
///
/// Author: $author$
///   Date: 2/6/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSMACMAINMAIN_HH
#define _XOSMACMAINMAIN_HH

#include "XosMacMain.hh"
#include "XosOptMain.hpp"
#include "XosDebug.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosOptMain XosMacMainMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosMacMainMain
///
/// Author: $author$
///   Date: 2/6/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosMacMainMain
: public XosMacMainMainExtend
{
public:
    typedef XosMacMainMainExtend Extends;

    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosMacMainMain
    ///
    ///       Author: $author$
    ///         Date: 2/6/2013
    ///////////////////////////////////////////////////////////////////////
    XosMacMainMain()
    {
    }
    virtual ~XosMacMainMain()
    {
    }

    virtual int Run
    (int argc, char** argv, char** env)
    {
        int err = 1;
#if defined(OBJC)  
        id<XosMacMain> main = 0;
        if ((main = [XosMacMain Allocate])) {
    	    err = [main Main:argc argv:argv env:env];
    	    [main Release];
        } else {
            XOS_DBE(("failed on [iXosMain Allocate]"));
        }
#else // defined(OBJC)  
        XOS_DBE(("not built with Objective-C++ compiler"));
#endif // defined(OBJC)  
        return err;
    }

    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        switch(optval)
        {
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt)
    {
        const char* chars = "";
        switch(longopt->val)
        {
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    virtual const char* Options
    (const struct option*& longopts)
    {
        int err = 0;
        static const char* chars = XOSOPTMAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOSOPTMAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
};

#if defined(_NAMESPACE)
}
#endif // defined(_NAMESPACE) 

#endif // _XOSMACMAINMAIN_HH 
