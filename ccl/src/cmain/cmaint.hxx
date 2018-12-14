/**
 **********************************************************************
 * Copyright (c) 1988-2003 $organization$.
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
 *   File: cmaint.hxx
 *
 * Author: $author$
 *   Date: 8/15/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMAINT_HXX
#define _CMAINT_HXX

#include <string.h>

#include "ccharfile.hxx"
#include "cmultipleinstancet.hxx"

/**
 **********************************************************************
 *  Class: cMainT
 *
 * Author: $author$
 *   Date: 8/15/2003
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cMainT
: public cMultipleInstanceT<TAs, TIs>
{
public:
    typedef cMultipleInstanceT<TAs, TIs> cInstanceIs, cIs;

    cCharFile m_in, m_out, m_err;

    /**
     **********************************************************************
     * Constructor: cMainT
     *
     *      Author: $author$
     *        Date: 8/15/2003
     **********************************************************************
     */
    cMainT(TAs *instance) 
    : cIs(instance)
    {
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnRun(int argc, char **argv)
    {
        return OnRun(argc, (const char **)argv);
    }
    /**
     **********************************************************************
     * Function: OnRun
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnRun(int argc, const char **argv)
    {
        return 0;
    }
    /**
     **********************************************************************
     * Function: OnMain
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMain(int argc, char **argv)
    {
        int count;
        eError error;

        if ((error = m_in.Attach(stdin)))
            return 1;

        if ((error = m_out.Attach(stdout)))
            return 1;

        if ((error = m_err.Attach(stderr)))
            return 1;

        if ((count = OnMainArgs(argc, argv)) < 0)
            return 1;

        return OnRun(argc, argv);
    }
    /**
     **********************************************************************
     * Function: OnMainArgs
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgs(int argc, char **argv)
    {
        char *arg;
        int argn, argon, args=0;

        for (argon = argn = 0; argn < argc; argon = ++argn)
        {
            if (!(arg = argv[argn]))
                return -e_ERROR_NULL_PARAMETER;

            if ((argn = OnMainArg
                (args, argn, arg, argc, argv)) < argon)
            {
                if (argn >= 0)
                    return -e_ERROR_INVALID_RETURN;

                return argn;
            }

            ++args;
        }

        return args;
    }
    /**
     **********************************************************************
     * Function: OnMainArg
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArg
    (int args, int argn, char *arg, int argc, char **argv)
    {
        const char *equal;

        switch(arg[0])
        {
        case '-':
            return OnMainArgSwitch
            (args, argn, arg+1, argc, argv);
        }

        if ((equal = strchr(arg, '=')))
            return OnMainArgAssign
            (args, argn, arg, equal, argc, argv);

        return OnMainArgValue(args, argn, arg, argc, argv);
    }
    /**
     **********************************************************************
     * Function: OnMainArgAssign
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgAssign
    (int args, int argn, char *arg, 
     const char *equal, int argc, char **argv)
    {
        return OnMainArgAssign
        (args, argn, (const char *)arg,
         equal, argc, (const char **)argv);
    }
    /**
     **********************************************************************
     * Function: OnMainArgAssign
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgAssign
    (int args, int argn, const char *arg, 
     const char *equal, int argc, const char **argv)
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        return OnMainArgSwitch
        (args, argn, (const char *)arg, argc, (const char **)argv);
    }
    /**
     **********************************************************************
     * Function: OnMainArgSwitch
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgSwitch
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, char *arg, int argc, char **argv)
    {
        return OnMainArgValue
        (args, argn, (const char *)arg, argc, (const char **)argv);
    }
    /**
     **********************************************************************
     * Function: OnMainArgValue
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
};

#endif
