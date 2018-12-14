/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: comm.cxx
 *
 * Author: $author$
 *   Date: 11/12/2007
 *
 *    $Id$
 **********************************************************************
 */

#include "ccomm.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

/**
 **********************************************************************
 *  Class: cCommMain
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMain
: public cMain
{
public:
    typedef cMain cIs;

    bool m_usage;
    cComm m_comm;
    BYTE message[128];

    /**
     **********************************************************************
     * Constructor: cCommMain
     *
     *      Author: $author$
     *        Date: 11/12/2007
     **********************************************************************
     */
    cCommMain()
    : m_usage(false),
      m_comm()
    {
        m_comm.SetBaud(DEFAULT_COMM_BAUD);
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 11/12/2007
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        eError error;
        int result;

        if (m_usage)
            return OnUsage(argc, argv);

        memset(message, 'X', sizeof(message));

        if (!(error = m_comm.Open()))
        {
            result = m_comm.Write
            ((const char*)message, sizeof(message));
            m_comm.Close();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnRead
     *
     *   Author: $author$
     *     Date: 11/12/2007
     **********************************************************************
     */
    virtual int OnRead(int argc, const char **argv)
    {
        eError error;
        int result;

        if ((error = m_comm.Open()))
            DBE("() failed to open comm\n");
        else
        {
            if (0 < (result = m_comm.Read
                ((char*)message, sizeof(message)-1)))
            {
                message[sizeof(message)-1] = 0;
                printf("%s\n", message);
            }
            m_comm.Close();
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 11/12/2007
     **********************************************************************
     */
    virtual int OnUsage(int argc, char **argv)
    {
        int result=0;
        cMainArg *a;

        printf("usage: %s", argv[0]);

        if ((a = cMainArg::m_list.GetFirst()))
        do
        {
            a->OnUsage();
        }
        while ((a = a->GetNext()));

        printf("\n");
        return result;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 11/12/2007
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        cMainArg *a;

        if ((a = cMainArg::m_list.FindFirstByName(arg)))
            return a->OnMainArgSwitch
            (args, argn, arg, argc, argv);

        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 11/12/2007
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        if (!strcmp("?", arg))
            m_usage = true;
        return argn;
    }
} g_comm_main;

/**
 **********************************************************************
 *  Class: cCommMainArg
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cCommMain &m_main;

    /**
     **********************************************************************
     * Constructor: cCommMainArg
     *
     *      Author: $author$
     *        Date: 11/12/2007
     **********************************************************************
     */
    cCommMainArg(cCommMain &p_main, const char *name)
    : cIs(name),
      m_main(p_main)
    {
    }
};

/**
 **********************************************************************
 *  Class: cCommMainArgComm ("c")
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMainArgComm
: public cCommMainArg
{
public:
    typedef cCommMainArg cIs;

    cCommMainArgComm
    (cCommMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        m_main.OnRead(argc, argv);
        return argn;
    }
} g_comm_main_comm(g_comm_main, "c");

/**
 **********************************************************************
 *  Class: cCommMainArgBaud ("b")
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMainArgBaud
: public cCommMainArg
{
public:
    typedef cCommMainArg cIs;

    cCommMainArgBaud
    (cCommMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_comm_main_baud(g_comm_main, "b");

/**
 **********************************************************************
 *  Class: cCommMainArgParity ("p")
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMainArgParity
: public cCommMainArg
{
public:
    typedef cCommMainArg cIs;

    cCommMainArgParity
    (cCommMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_comm_main_parity(g_comm_main, "p");

/**
 **********************************************************************
 *  Class: cCommMainArgBits ("n")
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMainArgBits
: public cCommMainArg
{
public:
    typedef cCommMainArg cIs;

    cCommMainArgBits
    (cCommMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_comm_main_bits(g_comm_main, "n");

/**
 **********************************************************************
 *  Class: cCommMainArgStopBits ("s")
 *
 * Author: $author$
 *   Date: 11/12/2007
 **********************************************************************
 */
class cCommMainArgStopBits
: public cCommMainArg
{
public:
    typedef cCommMainArg cIs;

    cCommMainArgStopBits
    (cCommMain &p_main, const char *name)
    : cIs(p_main, name)
    {
    }
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
} g_comm_main_stopbits(g_comm_main, "s");
