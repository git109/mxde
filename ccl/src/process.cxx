/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
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
 *   File: process.cxx
 *
 * Author: $author$
 *   Date: 10/28/2004
 *
 *    $Id$
 **********************************************************************
 */

#include "cpipe.hxx"
#include "cpipeprocess.hxx"
#include "cprocess.hxx"
#include "cmainarg.hxx"
#include "cmain.hxx"

class cProcessMain;

/**
 **********************************************************************
 *  Class: cProcessMainArg
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArg
: public cMainArg
{
public:
    typedef cMainArg cIs;

    cProcessMain &m_main;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArg
    (cProcessMain &p_main, const char *name)
    : cIs(name), 
      m_main(p_main) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cProcessMain
 *
 * Author: $author$
 *   Date: 10/28/2004
 **********************************************************************
 */
class cProcessMain
: public cMain
{
public:
    typedef cMain cIs;

    const char *m_command;
    const char *m_write;
    bool m_read;
    bool m_child;
    bool m_verbose;
    char m_end;

    char m_buffer[4096];

    /**
     **********************************************************************
     * Constructor: cProcessMain
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMain(const char *command="cmd /C dir") 
    : m_command(command),
      m_write(0),
      m_read(false),
      m_child(false),
      m_verbose(false),
      m_end('\n')
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 10/13/2004
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        int c, length, result = 0;
        FILE *in = stdin;
        FILE *out = stdout;
        eError error;
        cPipeProcess p;

        if (m_child)
        {
            if (m_verbose)
                fprintf(out, "Child:\n");

            if (m_read)
            while (0 < (c = getc(in)))
            {
                putc(c, out);

                if (m_end == c)
                    break;
            }
            if (m_write)
                fprintf(out, "%s\n", m_write);
        }
        else 
        {
            if (m_verbose)
                fprintf(out, "Parent:\n");

            if (!(error = p.Create(m_command)))
            {
                if (m_write)
                {
                    if (m_verbose)
                        fprintf(out, "Parent: \"%s\"\n", m_write);

                    p.Write(m_write, strlen(m_write));
                    p.Write("\n", 1);
                }

                if (m_read)
                while (0 < (length = p.Read(m_buffer, sizeof(m_buffer))))
                {
                    fwrite(m_buffer, 1, length, out);

                    //if (length < sizeof(m_buffer))
                      //  break;
                }

                p.Finish();
            }
        }

        return result;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
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
} g_process_main;

/**
 **********************************************************************
 *  Class: cProcessMainArgRead
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArgRead
: public cProcessMainArg
{
public:
    typedef cProcessMainArg cIs;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArgRead(const char *name="r") 
    : cIs(g_process_main, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char **argv) 
    {
        m_main.m_read = true;
        return argn;
    }
} g_process_arg_read;

/**
 **********************************************************************
 *  Class: cProcessMainArgWrite
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArgWrite
: public cProcessMainArg
{
public:
    typedef cProcessMainArg cIs;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArgWrite(const char *name="w") 
    : cIs(g_process_main, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char **argv) 
    {
        if (argn < argc)
            m_main.m_write = argv[++argn];
        return argn;
    }
} g_process_arg_write;

/**
 **********************************************************************
 *  Class: cProcessMainArgExecute
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArgExecute
: public cProcessMainArg
{
public:
    typedef cProcessMainArg cIs;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArgExecute(const char *name="e") 
    : cIs(g_process_main, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char **argv) 
    {
        if (argn < argc)
            m_main.m_command = argv[++argn];
        return argn;
    }
} g_process_arg_execute;

/**
 **********************************************************************
 *  Class: cProcessMainArgParent
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArgParent
: public cProcessMainArg
{
public:
    typedef cProcessMainArg cIs;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArgParent(const char *name="p") 
    : cIs(g_process_main, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char **argv) 
    {
        m_main.m_child = false;
        return argn;
    }
} g_process_arg_parent;

/**
 **********************************************************************
 *  Class: cProcessMainArgChild
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArgChild
: public cProcessMainArg
{
public:
    typedef cProcessMainArg cIs;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArgChild(const char *name="c") 
    : cIs(g_process_main, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char **argv) 
    {
        m_main.m_child = true;
        return argn;
    }
} g_process_arg_child;

/**
 **********************************************************************
 *  Class: cProcessMainArgVerbose
 *
 * Author: $author$
 *   Date: 10/31/2004
 **********************************************************************
 */
class cProcessMainArgVerbose
: public cProcessMainArg
{
public:
    typedef cProcessMainArg cIs;

    /**
     **********************************************************************
     * Constructor: cProcessMainArg
     *
     *      Author: $author$
     *        Date: 10/31/2004
     **********************************************************************
     */
    cProcessMainArgVerbose(const char *name="v") 
    : cIs(g_process_main, name) 
    {
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 10/31/2004
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, 
     int argc, const char **argv) 
    {
        m_main.m_verbose = true;
        return argn;
    }
} g_process_arg_verbose;

