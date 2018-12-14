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
 *   File: cmainarg.hxx
 *
 * Author: $author$
 *   Date: 6/17/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMAINARG_HXX
#define _CMAINARG_HXX

#include <stdio.h>
#include <string.h>
#include "clistt.hxx"

class cMainArgList;

/**
 **********************************************************************
 *  Class: cMainArg
 *
 * Author: $author$
 *   Date: 6/17/2004
 **********************************************************************
 */
class cMainArg
: public cListItemT<cMainArg>
{
public:
    typedef cListItemT<cMainArg> cIs;

    static cMainArgList m_list;

    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cMainArg
     *
     *      Author: $author$
     *        Date: 6/17/2004
     **********************************************************************
     */
    cMainArg(const char *name);
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
     *     Date: 6/17/2004
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
     *     Date: 6/17/2004
     **********************************************************************
     */
    virtual int OnMainArgValue
    (int args, int argn, const char *arg, int argc, const char **argv)
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: OnUsage
     *
     *   Author: $author$
     *     Date: 11/1/2004
     **********************************************************************
     */
    virtual void OnUsage()
    {
        printf(" -%s", m_name);
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 6/17/2004
     **********************************************************************
     */
    const char *GetName() const
    {
        return m_name;
    }
};

/**
 **********************************************************************
 *  Class: cMainArgList
 *
 * Author: $author$
 *   Date: 6/17/2004
 **********************************************************************
 */
class cMainArgList
: public cStaticListT<cMainArg, cMainArgList>
{
public:
    typedef cStaticListT<cMainArg, cMainArgList> cIs;

    /**
     **********************************************************************
     * Function: FindFirstByName
     *
     *   Author: $author$
     *     Date: 6/17/2004
     **********************************************************************
     */
    virtual cMainArg *FindFirstByName(const char *name) const
    {
        cMainArg *arg;

        for (arg=GetFirst(); arg; arg=arg->GetNext())
            if (!strcmp(name, arg->GetName()))
                break;

        return arg;
    }
};

#endif /* ndef _CMAINARG_HXX */
