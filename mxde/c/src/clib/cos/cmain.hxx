/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cmain.hxx
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
#if !defined(_CMAIN_HXX) || defined(CMAIN_MEMBERS_ONLY)
#if !defined(_CMAIN_HXX) && !defined(CMAIN_MEMBERS_ONLY)
#define _CMAIN_HXX
#endif /* !defined(_CMAIN_HXX) && !defined(CMAIN_MEMBERS_ONLY) */

#if !defined(CMAIN_MEMBERS_ONLY)
#include "cbase.hxx"
#include "cdebug.hxx"
#include "cfile.hxx"
#include "cmaininterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cMain;

#undef CDB_CLASS
#define CDB_CLASS "cMainT"
/**
 **********************************************************************
 *  Class: cMainT
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
template
<class TDerives=cMain,
 class TMainImplement=cMainImplement,
 class TMainInterface=cMainInterface,
 class TFile=cFile,
 class TFileInterface=cFileInterface,
 class TStreamInterface=cStreamInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cBase,
 class TImplements=TMainImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cMainT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

    typedef TFile tFile;
    typedef TFileInterface tFileInterface;
    typedef TStreamInterface tStreamInterface;

    TMainInterface* m_oldMainInterface;

    tFile m_stdIn;
    tFile m_stdOut;
    tFile m_stdErr;

    tStreamInterface* m_in;
    tStreamInterface* m_out;
    tStreamInterface* m_err;

    tInt m_argc;
    tChar** m_argv;
    tChar** m_env;

    bool m_didMain;

    /**
     **********************************************************************
     * Constructor: cMainT
     *
     *      Author: $author$
     *        Date: 2/23/2009
     **********************************************************************
     */
    cMainT()
    : m_in(&m_stdIn),
      m_out(&m_stdOut),
      m_err(&m_stdErr),
      m_argc(0),
      m_argv(0),
      m_env(0),
      m_didMain(false)
    {
        m_oldMainInterface = TMainInterface::m_theMainInterface;
        TMainInterface::m_theMainInterface = (TMainInterface*)(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cMainT
     *
     *     Author: $author$
     *       Date: 2/23/2009
     **********************************************************************
     */
    virtual ~cMainT()
    {
        if (TMainInterface::m_theMainInterface == (TMainInterface*)(this))
            TMainInterface::m_theMainInterface = m_oldMainInterface;
    }
#else /* !defined(CMAIN_MEMBERS_ONLY) */
#endif /* !defined(CMAIN_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 3/11/2009
     **********************************************************************
     */
    virtual tInt Main
    (tInt argc,
     tChar** argv,
     tChar** env) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        const tChar** c_argv = (const tChar**)argv;
        const tChar** c_env = (const tChar**)env;

#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tInt oldArgc = m_argc;
        tChar** oldArgv = m_argv;
        tChar** oldEnv = m_env;

        m_argc = argc;
        m_argv = argv;
        m_env = env;
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */

        tInt err = Main(argc, c_argv, c_env);

#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        m_env = oldEnv;
        m_argv = oldArgv;
        m_argc = oldArgc;
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return err;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Main
     *
     *   Author: $author$
     *     Date: 2/23/2009
     **********************************************************************
     */
    virtual tInt Main
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tInt err2, err = 0;

#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        m_stdIn.Attach(stdin);
        m_stdOut.Attach(stdout);
        m_stdErr.Attach(stderr);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */

        if (!(err = Begin(argc, argv, env)))
        {
            bool didMain;

            if (!(didMain = GetDidMain()))
                err = Run(argc, argv, env);

            if ((err2 = End(argc, argv, env)) && (!err))
                err = err2;
        }
        return err;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Begin
     *
     *   Author: $author$
     *     Date: 2/23/2009
     **********************************************************************
     */
    virtual tInt Begin
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tInt err = 0;
        return err;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: End
     *
     *   Author: $author$
     *     Date: 2/23/2009
     **********************************************************************
     */
    virtual tInt End
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tInt err = 0;
        return err;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 2/23/2009
     **********************************************************************
     */
    virtual tInt Run
    (tInt argc,
     const tChar** argv,
     const tChar** env) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tInt err = 0;
        return err;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetDidMain
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual bool SetDidMain
    (bool did=true) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        bool didMain = (m_didMain = did);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        bool didMain = false;
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return didMain;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetDidMain
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual bool GetDidMain() const 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        bool didMain = m_didMain;
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        bool didMain = false;
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return didMain;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OutFormatted
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual tLength OutFormatted
    (const tChar* format,...) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tStreamInterface* stream;
        va_list va;
        va_start(va, format);
        if ((stream = m_out))
        count = stream->VWriteFormatted(format, va);
        va_end(va);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ErrFormatted
     *
     *   Author: $author$
     *     Date: 3/20/2009
     **********************************************************************
     */
    virtual tLength ErrFormatted
    (const tChar* format,...) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tStreamInterface* stream;
        va_list va;
        va_start(va, format);
        if ((stream = m_err))
        count = stream->VWriteFormatted(format, va);
        va_end(va);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: VOutFormatted
     *
     *   Author: $author$
     *     Date: 9/16/2011
     **********************************************************************
     */
    virtual tLength VOutFormatted
    (const tChar* format, va_list va) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tStreamInterface* stream;
        if ((stream = m_out))
        count = stream->VWriteFormatted(format, va);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: VErrFormatted
     *
     *   Author: $author$
     *     Date: 9/26/2011
     **********************************************************************
     */
    virtual tLength VErrFormatted
    (const tChar* format, va_list va) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tStreamInterface* stream;
        if ((stream = m_err))
        count = stream->VWriteFormatted(format, va);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Out
     *
     *   Author: $author$
     *     Date: 3/27/2009
     **********************************************************************
     */
    virtual tLength Out
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tStreamInterface* stream;
        if ((stream = m_out))
        count = stream->Write(chars, length);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Err
     *
     *   Author: $author$
     *     Date: 3/27/2009
     **********************************************************************
     */
    virtual tLength Err
    (const tChar* chars,
     tLength length=vUndefinedLength) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE) 
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        tLength count = 0;
        tStreamInterface* stream;
        if ((stream = m_err))
        count = stream->Write(chars, length);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        tLength count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetStdErr
     *
     *    Author: $author$
     *      Date: 3/12/2010
     **********************************************************************
     */
    virtual tFileInterface* GetStdErr() const
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tFileInterface* file = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT)
        file = (tFileInterface*)(&m_stdErr);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return file;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetStdOut
     *
     *    Author: $author$
     *      Date: 3/12/2010
     **********************************************************************
     */
    virtual tFileInterface* GetStdOut() const
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tFileInterface* file = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT)
        file = (tFileInterface*)(&m_stdOut);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return file;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetStdIn
     *
     *    Author: $author$
     *      Date: 3/12/2010
     **********************************************************************
     */
    virtual tFileInterface* GetStdIn() const
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tFileInterface* file = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT)
        file = (tFileInterface*)(&m_stdIn);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return file;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetErr
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual tStreamInterface* SetErr
    (tStreamInterface* toStream) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tStreamInterface* stream = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        stream = (tStreamInterface*)(m_err);
        m_err = toStream;
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return stream;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetErr
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual tStreamInterface* GetErr() const 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tStreamInterface* stream = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        stream = (tStreamInterface*)(m_err);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return stream;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetOut
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual tStreamInterface* SetOut
    (tStreamInterface* toStream) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tStreamInterface* stream = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        stream = (tStreamInterface*)(m_out);
        m_out = toStream;
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return stream;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetOut
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual tStreamInterface* GetOut() const 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tStreamInterface* stream = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        stream = (tStreamInterface*)(m_out);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return stream;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetIn
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual tStreamInterface* SetIn
    (tStreamInterface* toStream) 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tStreamInterface* stream = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        stream = (tStreamInterface*)(m_in);
        m_in = toStream;
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return stream;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GetIn
     *
     *   Author: $author$
     *     Date: 3/11/2010
     **********************************************************************
     */
    virtual tStreamInterface* GetIn() const 
#if defined(CMAIN_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        tStreamInterface* stream = 0;
#if !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) 
        stream = (tStreamInterface*)(m_in);
#else /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return stream;
    }
#endif /* defined(CMAIN_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMAIN_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/*
 * main
 */
class c_INSTANCE_CLASS cMain;
/**
 **********************************************************************
 * Typedef: cMainExtends
 *
 *  Author: $author$
 *    Date: 2/23/2009
 **********************************************************************
 */
typedef cMainT
<cMain,
 cMainImplement,
 cMainInterface,
 cFile, cFileInterface, cStreamInterface,
 char, int>
cMainExtends;
/**
 **********************************************************************
 *  Class: cMain
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cMain
: public cMainExtends
{
public:
    typedef cMainExtends cImplements;
    typedef cMain cDerives;
};

/*
 * tmain
 */
class c_INSTANCE_CLASS cTMain;
/**
 **********************************************************************
 * Typedef: cTMainExtends
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainT
<cTMain,
 cTMainImplement,
 cTMainInterface,
 cTCHARFile, cTCHARFileInterface, cTCHARStreamInterface,
 TCHAR, int>
cTMainExtends;
/**
 **********************************************************************
 *  Class: cTMain
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTMain
: public cTMainExtends
{
public:
    typedef cTMainExtends cExtends;
    typedef cTMain cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMAIN_MEMBERS_ONLY) */
#endif /* !defined(CMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CMAIN_HXX) || defined(CMAIN_MEMBERS_ONLY) */
