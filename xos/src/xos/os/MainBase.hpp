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
///   File: MainBase.hpp
///
/// Author: $author$
///   Date: Jul 31, 2012
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MAINBASE_HPP_
#define _XOS_MAINBASE_HPP_

#include "xos/base/Base.hpp"
#include "xos/os/Logger.hpp"

namespace xos {

typedef InterfaceBase MainBaseImplement;
typedef ExportBase MainBaseExtend;

class _EXPORT_CLASS MainBase: virtual public MainBaseImplement, public MainBaseExtend {
public:
    typedef MainBaseImplement Implements;
    typedef MainBaseExtend Extends;

    MainBase* m_theOldMain;

    MainBase():m_theOldMain(GetTheMain()){ SetTheMain(this); }
    virtual ~MainBase(){ if (this == GetTheMain()) SetTheMain(m_theOldMain); }

    virtual int Run(int argc, char** argv, char** env){ return 0; }
    virtual int BeforeRun(int argc, char** argv, char** env){ return 0; }
    virtual int AfterRun(int argc, char** argv, char** env){ return 0; }

    virtual int Main(int argc, char** argv, char** env)
    {
        int err = 0;
        int err2;
        if (!(err = BeforeRun(argc, argv, env)))
        {
            err = Run(argc, argv, env);

            if ((err2 = AfterRun(argc, argv, env)))
            if (!(err))
                err = err2;
        }
        return err;
    }
    virtual int BeforeMain(int argc, char** argv, char** env){ return 0; }
    virtual int AfterMain(int argc, char** argv, char** env){ return 0; }
    virtual bool DidMain() const { return false; }

    static int TheMain(int argc, char** argv, char** env);
    static void SetTheMain(MainBase* toTheMain);
    static MainBase* GetTheMain();

    virtual ssize_t OutFormatted
    (const char* format, ...)
    {
        ssize_t count = 0;
        va_list va;
        va_start(va, format);
        if ((format))
        count = OutFormattedV(format, va);
        va_end(va);
        return count;
    }
    virtual ssize_t OutFormattedV
    (const char* format, va_list va)
    {
        ssize_t count = 0;
        if ((format))
        count = vprintf(format, va);
        return count;
    }
};

} // namespace xos

#endif // _XOS_MAINBASE_HPP_ 
