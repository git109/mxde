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
///   File: Xos2cMain.hpp
///
/// Author: $author$
///   Date: 2/1/2013
///////////////////////////////////////////////////////////////////////
#ifndef _XOS2CMAIN_HPP
#define _XOS2CMAIN_HPP

#include "XosOptMain.hpp"
#include "XosIBufferFile.hpp"

#if defined(_NAMESPACE)
namespace _NAMESPACE {
#endif // defined(_NAMESPACE) 

typedef XosOptMain Xos2cMainExtend;
///////////////////////////////////////////////////////////////////////
///  Class: Xos2cMain
///
/// Author: $author$
///   Date: 2/1/2013
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Xos2cMain
: public Xos2cMainExtend
{
public:
    typedef Xos2cMainExtend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///  Constructor: Xos2cMain
    ///
    ///       Author: $author$
    ///         Date: 2/1/2013
    ///////////////////////////////////////////////////////////////////////
    Xos2cMain()
    {
    }
    virtual ~Xos2cMain()
    {
    }
    virtual int Run
    (int argc,
     char** argv,
     char** env)
    {
        int err = 0;
        XosByteIBufferFile file;
        const char* fileName;
        XosError error;

        if (1 < argc)
        if ((fileName = argv[1]))
        if (!(error = file.Open(fileName, "rb")))
        {
            const char* before = "";
            const char* after = "";
            size_t count = 0;
            size_t size = 0;
            uint8_t byte[1];

            printf("uint8_t Data[] = {\n");
            for (size=0; (0 < file.Read(byte, 1)); size++)
            {
                printf("%s0x%2.2x%s", before, byte[0], after);
                if (++count >= 32)
                {
                    before = ",\n";
                    count = 0;
                }
                else
                before = ",";
            }
            printf("\n};\n");
            printf("size_t Size=%u;\n", size);
            file.Close();
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

#endif // _XOS2CMAIN_HPP 
