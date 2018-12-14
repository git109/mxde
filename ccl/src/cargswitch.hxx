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
 *   File: cargswitch.hxx
 *
 * Author: $author$
 *   Date: 8/15/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CARGSWITCH_HXX
#define _CARGSWITCH_HXX

#include <string.h>

#include "clistt.hxx"

/**
 **********************************************************************
 *  Class: cArgSwitch
 *
 * Author: $author$
 *   Date: 8/15/2003
 **********************************************************************
 */
class cArgSwitch
: public cListItemT<cArgSwitch>
{
public:
    typedef cListItemT<cArgSwitch> cIs;

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 8/15/2003
     **********************************************************************
     */
    class cList
    : public cStaticListT<cArgSwitch, cList>
    {
    public:
        typedef cStaticListT<cArgSwitch, cList> cIs;
    };

    static cList m_list;

    /**
     **********************************************************************
     * Function: OnArgSwitch
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    static int OnArgSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        cArgSwitch *arg_switch;

        for (arg_switch = m_list.GetFirst(); arg_switch; arg_switch = arg_switch->GetNext())
        {
            if (!strcmp(arg, arg_switch->GetName()))
                return arg_switch->OnSwitch
                (args, argn, arg, argc, argv);
        }

        return -1;
    }

    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cArgSwitch
     *
     *      Author: $author$
     *        Date: 8/15/2003
     **********************************************************************
     */
    cArgSwitch(const char *name)
    : m_name(name) 
    {
        m_list.Add(this);
    }
    /**
     **********************************************************************
     * Destructor: ~cArgSwitch
     *
     *     Author: $author$
     *       Date: 8/15/2003
     **********************************************************************
     */
    virtual ~cArgSwitch()
    {
        m_list.Delete(this);
    }
    /**
     **********************************************************************
     * Function: OnSwitch
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    virtual int OnSwitch
    (int args, int argn, char *arg, int argc, char **argv)
    {
        return argn;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/15/2003
     **********************************************************************
     */
    inline const char *GetName() const
    {
        return m_name;
    }
};


#endif
