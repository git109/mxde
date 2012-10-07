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
///   File: Main.hpp
///
/// Author: $author$
///   Date: Jul 29, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MAIN_HPP_
#define _XOS_MAIN_HPP_

#include "xos/os/MainBase.hpp"
#include "xos/os/StreamLogger.hpp"
#include <getopt.h>

#define XOS_MAIN_OPTIONS_CHARS "l:h"
#define XOS_MAIN_OPTIONS_OPTIONS \
            {"logging-level", MAIN_OPT_ARGUMENT_REQUIRED, 0, 'l'},\
            {"help", MAIN_OPT_ARGUMENT_NONE, 0, 'h'},

namespace xos {

typedef int MainOptArgument;
enum
{
    MAIN_OPT_ARGUMENT_NONE     = 0,
    MAIN_OPT_ARGUMENT_REQUIRED = 1,
    MAIN_OPT_ARGUMENT_OPTIONAL = 2
};

typedef MainBaseImplement MainImplement;
typedef MainBase MainExtend;

class _EXPORT_CLASS Main: virtual public MainImplement, public MainExtend {
public:
    typedef MainImplement Implements;
    typedef MainExtend Extends;

    class EXPORT_CLASS Logger: public StreamLogger {
    public:
        typedef StreamLogger Extends;
        Logger
        (Stream* attachedTo = 0,
         Level::Enable levelEnabled = XOS_STREAMLOGGER_LEVELS_ENABLED)
        : Extends(attachedTo, levelEnabled),
          m_oldDefault(GetDefault()){
              SetDefault(this);
        }
        virtual ~Logger(){
            if ((GetDefault() == this))
                SetDefault(m_oldDefault);
        }
    protected:
        xos::Logger* m_oldDefault;
    };

    bool m_didUsage;

    Main():m_didUsage(false){}
    virtual ~Main(){}

    virtual int BeforeMain
    (int argc, char**argv, char**env)
    {
        int err = GetOptions(argc, argv, env);
        return err;
    }
    virtual int AfterMain
    (int argc, char**argv, char**env)
    {
        int err = 0;
        return err;
    }
    virtual bool DidMain() const
    {   return DidUsage(); }

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
                (MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                ((MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
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
        SetDidUsage(true);
        return err;
    }
    virtual bool SetDidUsage(bool isTrue=true)
    {   return m_didUsage = isTrue; }
    virtual bool DidUsage() const
    {   return m_didUsage; }
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

            if ((err = OnOption
               (optvalue, optarg, optname, longindex, argc, argv, env)))
                break;
        }
        return err;
    }
    virtual int OnLoggingOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        char c;

        switch(optval)
        {
        case 'l':
            if ((optarg))
            if ((c = optarg[0]))
            if (!(optarg[1]))
            {
                err = 0;
                switch(c)
                {
                case 'a':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ALL);
                    break;
 
                case '0':
                case 'n':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_NONE);
                    break;
 
                case '1':
                case 'f':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_FATAL);
                    break;
 
                case '2':
                case 'e':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ERROR);
                    break;
 
                case '3':
                case 'w':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_WARN);
                    break;
 
                case '4':
                case 'i':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_INFO);
                    break;
 
                case '5':
                case 'd':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_DEBUG);
                    break;
 
                case '6':
                case 't':
                    XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_TRACE);
                    break;
 
                default:
                    err = 1;
                }
            }
            break;
        }
        return err;
    }
    virtual int OnUsageOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env)
    {
        int err = 0;
        err = Usage(argc, argv, env);
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
        case 'l':
            err = OnLoggingOption
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
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt)
    {
        const char* chars = "";
        switch(longopt->val)
        {
        case 'l':
            optarg = "{(a)all|(n)none|(f)fatal|(e)error|(w)waring|(i)info|(t)trace|(d)debug}";
            break;
        case 'h':
            chars = "Usage options";
            break;
        }
        return chars;
    }
    virtual const char* Options
    (const struct option*& longopts)
    {
        int err = 0;
        static const char* chars = XOS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
};

} // namespace xos

#endif // _XOS_MAIN_HPP_ 
