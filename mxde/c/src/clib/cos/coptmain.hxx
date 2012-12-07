/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: coptmain.hxx
 *
 * Author: $author$
 *   Date: 2/21/2011
 **********************************************************************
 */
#if !defined(_COPTMAIN_HXX) || defined(COPTMAIN_MEMBERS_ONLY)
#if !defined(_COPTMAIN_HXX) && !defined(COPTMAIN_MEMBERS_ONLY)
#define _COPTMAIN_HXX
#endif /* !defined(_COPTMAIN_HXX) && !defined(COPTMAIN_MEMBERS_ONLY) */

#if !defined(COPTMAIN_MEMBERS_ONLY)
#include "coptmaininterface.hxx"
#include "cmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *    Enum: eMainOptArgument
 *
 *  Author: $author$
 *    Date: 2/21/2011
 **********************************************************************
 */
typedef int eMainOptArgument;
enum
{
    e_MAIN_OPT_ARGUMENT_NONE     = 0,
    e_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    e_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};
/**
 **********************************************************************
 * Typedef: cOptMainExtend
 *
 *  Author: $author$
 *    Date: 2/21/2011
 **********************************************************************
 */
typedef cMain
cOptMainExtend;
/**
 **********************************************************************
 *  Class: cOptMain
 *
 * Author: $author$
 *   Date: 2/21/2011
 **********************************************************************
 */
class c_INSTANCE_CLASS cOptMain
: virtual public cOptMainImplement,
  public cOptMainExtend
{
public:
    typedef cOptMainImplement cImplements;
    typedef cOptMainExtend cExtends;
    
    /**
     **********************************************************************
     *  Constructor: cOptMain
     *
     *       Author: $author$
     *         Date: 2/21/2011
     **********************************************************************
     */
    cOptMain()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cOptMain
     *
     *      Author: $author$
     *        Date: 2/21/2011
     **********************************************************************
     */
    virtual ~cOptMain()
    {
    }
#else /* !defined(COPTMAIN_MEMBERS_ONLY) */
#endif /* !defined(COPTMAIN_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Usage
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual int Usage
    (int argc, char**argv, char**env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
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
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetOptions
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual int GetOptions
    (int argc, char** argv, char** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
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

            DBT(("() optname = \"%s\" optarg = \"%s\"", optname, ((optarg)?(optarg):(""))));

            if ((err = OnOption
               (optvalue, optarg, optname, longindex, argc, argv, env)))
                break;
        }
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnDebugOption
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual int OnDebugOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char** argv, char** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
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
                    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_NONE);
                    break;
 
                case '1':
                case 'e':
                    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_ERROR);
                    break;
 
                case '2':
                case 'w':
                    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_WARN);
                    break;
 
                case '3':
                case 'i':
                    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_INFO);
                    break;
 
                case '4':
                case 'f':
                    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_FUNC);
                    break;
 
                case '5':
                case 't':
                    SET_DEBUG_LEVELS(e_DEBUG_LEVELS_TRACE);
                    break;
 
                default:
                    if ((c >= '0') && (c <= '9'))
                        SET_DEBUG_LEVELS((c-'0'));
                    else
                    err = 1;
                }
            }
            break;
        }
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnUsageOption
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual int OnUsageOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char** argv, char** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        err = Usage(argc, argv, env);
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OnOption
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char** argv, char** env)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        int err = 0;
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
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
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: OptionUsage
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual const char* OptionUsage
    (const char*& optarg, const struct option* longopt)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        const char* chars = "";
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        switch(longopt->val)
        {
        case 'd':
            optarg = "{(e)error|(w)waring|(i)info|(f)function|(t)trace}";
            break;
        case 'h':
            chars = "Usage options";
            break;
        }
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Options
     *
     *    Author: $author$
     *      Date: 2/21/2011
     **********************************************************************
     */
    virtual const char* Options
    (const struct option*& longopts)
#if defined(COPTMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT)
        static const char* chars = "d:h";
        static struct option optstruct[]= {
            {"debug-levels", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'd'},
            {"help", e_MAIN_OPT_ARGUMENT_NONE, 0, 'h'},
            {0, 0, 0, 0}};
        longopts = optstruct;
#else /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        static const char* chars = "";
#endif /* !defined(COPTMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(COPTMAIN_MEMBER_FUNCS_INTERFACE) */

#if !defined(COPTMAIN_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(COPTMAIN_MEMBERS_ONLY) */
#endif /* !defined(COPTMAIN_MEMBERS_ONLY) */

#endif /* !defined(_COPTMAIN_HXX) || defined(COPTMAIN_MEMBERS_ONLY) */
