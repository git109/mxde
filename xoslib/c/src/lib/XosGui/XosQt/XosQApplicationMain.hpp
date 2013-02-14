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
///   File: XosQApplicationMain.hpp
///
/// Author: $author$
///   Date: 2/3/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOSQAPPLICATIONMAIN_HPP
#define _XOSQAPPLICATIONMAIN_HPP

#include <QtGui>
#include "XosOptMain.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosOptMain XosQApplicationMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: XosQApplicationMain
///
/// Author: $author$
///   Date: 2/3/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS XosQApplicationMain
: public XosQApplicationMainExtend
{
public:
    typedef XosQApplicationMainExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: XosQApplicationMain
    ///
    ///       Author: $author$
    ///         Date: 2/3/2013
    ///////////////////////////////////////////////////////////////////////
    XosQApplicationMain()
    {
    }
    virtual ~XosQApplicationMain()
    {
    }

    virtual int Exec
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        int err = qApplication.exec();
        return err;
    }
    virtual int BeforeExec
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        int err = 0;
        return err;
    }
    virtual int AfterExec
    (QApplication& qApplication,
     int argc, char** argv, char** env)
    {
        int err = 0;
        return err;
    }

    virtual int Run
    (int argc, char** argv, char** env)
    {
        int err = 0;
        QApplication qApplication(argc, argv, env);
        if (!(err = BeforeExec(qApplication, argc, argv, env)))
        {
            int err2;
            err = Exec(qApplication, argc, argv, env);
            if ((err2 = AfterExec(qApplication, argc, argv, env)) && (!err))
                err = err2;
        }
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

#endif // _XOSQAPPLICATIONMAIN_HPP 
        

