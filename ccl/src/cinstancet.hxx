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
 *   File: cinstancet.hxx
 *
 * Author: $author$
 *   Date: 8/13/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CINSTANCET_HXX
#define _CINSTANCET_HXX

#include "cerror.h"

/**
 **********************************************************************
 *  Class: cInstanceTBase
 *
 * Author: $author$
 *   Date: 8/13/2003
 **********************************************************************
 */
class cInstanceTBase
{
};

/**
 **********************************************************************
 *  Class: cInstanceT
 *
 * Author: $author$
 *   Date: 8/13/2003
 **********************************************************************
 */
template <class TAs, class TIs=cInstanceTBase>
class cInstanceT
: public TIs
{
public:
    typedef TIs cIs;

    static TAs *m_instance;

    /**
     **********************************************************************
     * Constructor: cInstanceT
     *
     *      Author: $author$
     *        Date: 8/13/2003
     **********************************************************************
     */
    cInstanceT(TAs *instance) 
    {
        eError error;

        if (m_instance)
            throw (error = e_ERROR_ALREADY_INSTANTIATED);

        if (this != instance)
            throw (error = e_ERROR_INSTANTIATE);

        m_instance = instance;
    }
    /**
     **********************************************************************
     * Destructor: ~cInstanceT
     *
     *     Author: $author$
     *       Date: 8/13/2003
     **********************************************************************
     */
    virtual ~cInstanceT()
    {
        eError error;

        if (this != m_instance)
            throw (error = e_ERROR_NOT_INSTANTIATED);

        m_instance = 0;
    }
    /**
     **********************************************************************
     * Function: GetInstance
     *
     *   Author: $author$
     *     Date: 8/13/2003
     **********************************************************************
     */
    static inline TAs *GetInstance()
    {
        return m_instance;
    }
};


#endif
