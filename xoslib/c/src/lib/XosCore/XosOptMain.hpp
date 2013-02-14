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
///   File: XosOptMain.hpp
///
/// Author: $author$
///   Date: 4/1/2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOSOPTMAIN_HPP
#define _XOSOPTMAIN_HPP

#include "XosMain.hpp"
#include "XosString.hpp"
#include <getopt.h>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

#define XOSOPTMAIN_OPTIONS_CHARS "d:h"

#define XOSOPTMAIN_OPTIONS_OPTIONS \
            {"debug-levels", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'd'}, \
            {"help", e_MAIN_OPT_ARGUMENT_NONE, 0, 'h'}, \

typedef int eMainOptArgument;
enum
{
    e_MAIN_OPT_ARGUMENT_NONE     = 0,
    e_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    e_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};
///////////////////////////////////////////////////////////////////////
/// Typedef: XosOptMainImplement
///
///  Author: $author$
///    Date: 4/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosMainImplement
XosOptMainImplement;
///////////////////////////////////////////////////////////////////////
/// Typedef: XosOptMainExtend
///
///  Author: $author$
///    Date: 4/1/2012
///////////////////////////////////////////////////////////////////////
typedef XosMain
XosOptMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosOptMain
///
/// Author: $author$
///   Date: 4/1/2012
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosOptMain
: virtual public XosOptMainImplement,
  public XosOptMainExtend
{
public:
    typedef XosOptMainImplement Implements;
    typedef XosOptMainExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosOptMain
    ///
    ///       Author: $author$
    ///         Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    XosOptMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Destructor: ~XosOptMain
    ///
    ///      Author: $author$
    ///        Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual ~XosOptMain()
    {
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Main
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Main
    (int argc, char**argv, char**env)
    {
        int err = 0;
        if (!(err = GetOptions(argc, argv, env)))
        if (!(GetDidMain()))
            err = Extends::Main(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Usage
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int Usage
    (int argc, char**argv, char**env)
    {
        int err = 0;
        const char* optstring = 0;
        const struct option* longopts = 0;

        OutFormatted("Usage: %s [options]\n", argv[0]);

        if ((optstring = Options(longopts)) && (longopts))
        {
            OutFormatted("Options:\n");

            while ((longopts->name))
            {
                const char* optarg =
                (e_MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                ((e_MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                const char* optusage = OptionUsage(optarg, longopts);
                const char* optargSeparator = (optarg[0])?(" "):("");
                const char* optusageSeparator = "  ";

                OutFormatted
                (" -%c --%s%s%s%s%s\n",
                 longopts->val, longopts->name,
                 optargSeparator, optarg, optusageSeparator, optusage);
                longopts++;
            }
        }        
        SetDidMain(true);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: GetOptions
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int GetOptions
    (int argc, char**argv, char**env)
    {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char optvaluename[2] = {0,0};
        const char* optname = optvaluename;
        const char* optstring;
        int optvalue;

        if ((optstring = Options(longopts)) && (longopts))
        while (0 <= (optvalue = getopt_long
               (argc, argv, optstring, longopts, &longindex)))
        {
            optvaluename[0] = optvalue;
            optname = (longindex)?(longopts[longindex].name):(optvaluename);

            XOS_DBT(("() optname = \"%s\" optarg = \"%s\"\n", optname, ((optarg)?(optarg):(""))));

            if ((err = OnOption
               (optvalue, optarg, optname, longindex, argc, argv, env)))
                break;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnDebugOption
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int OnDebugOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        char c;

        switch(optval)
        {
        case 'd':
            if ((optarg))
            if ((c = optarg[0]))
            if (!(optarg[1]))
            {
                err = 0;
                switch(c)
                {
                case '0':
                case 'n':
                    XOS_SET_DEBUG_LEVEL(XOS_DEBUG_LEVELS_NONE);
                    break;
 
                case '1':
                case 'e':
                    XOS_SET_DEBUG_LEVEL(XOS_DEBUG_LEVELS_ERROR);
                    break;
 
                case '2':
                case 'w':
                    XOS_SET_DEBUG_LEVEL(XOS_DEBUG_LEVELS_WARN);
                    break;
 
                case '3':
                case 'i':
                    XOS_SET_DEBUG_LEVEL(XOS_DEBUG_LEVELS_INFO);
                    break;
 
                case '4':
                case 'f':
                    XOS_SET_DEBUG_LEVEL(XOS_DEBUG_LEVELS_FUNC);
                    break;
 
                case '5':
                case 't':
                    XOS_SET_DEBUG_LEVEL(XOS_DEBUG_LEVELS_TRACE);
                    break;
 
                default:
                    if ((c >= '0') && (c <= '9'))
                        XOS_SET_DEBUG_LEVEL((c-'0'));
                    else
                    err = 1;
                }
            }
            break;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnUsageOption
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int OnUsageOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        err = Usage(argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OnOption
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        switch(optval)
        {
        case 'd':
            err = OnDebugOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case 'h':
            err = OnUsageOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
            
        default:
            err = 1;
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: OptionUsage
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt)
    {
        const char* chars = "";
        switch(longopt->val)
        {
        case 'd':
            optarg = "{(n)none|(e)error|(w)waring|(i)info|(f)function|(t)trace}";
            break;
        case 'h':
            chars = "Usage options";
            break;
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///  Function: Options
    ///
    ///    Author: $author$
    ///      Date: 4/1/2012
    ///////////////////////////////////////////////////////////////////////
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


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _XOSOPTMAIN_HPP 
        

