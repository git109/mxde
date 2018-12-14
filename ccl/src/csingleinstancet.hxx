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
 *   File: csingleinstancet.hxx
 *
 * Author: $author$
 *   Date: 10/26/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSINGLEINSTANCET_HXX
#define _CSINGLEINSTANCET_HXX

#include "cerror.h"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cSingleInstanceT
 *
 * Author: $author$
 *   Date: 10/26/2003
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cSingleInstanceT
: public TIs
{
public:
    typedef TIs cIs;

    static TAs *m_instance;

    /**
     **********************************************************************
     * Constructor: cSingleInstanceT
     *
     *      Author: $author$
     *        Date: 10/26/2003
     **********************************************************************
     */
    cSingleInstanceT(TAs *instance) 
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
     * Destructor: ~cSingleInstanceT
     *
     *     Author: $author$
     *       Date: 10/26/2003
     **********************************************************************
     */
    virtual ~cSingleInstanceT()
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
     *     Date: 10/26/2003
     **********************************************************************
     */
    static inline TAs *GetInstance()
    {
        return m_instance;
    }
    /**
     **********************************************************************
     * Function: FreeInstance
     *
     *   Author: $author$
     *     Date: 10/26/2003
     **********************************************************************
     */
    inline eError FreeInstance()
    {
        return e_ERROR_NONE;
    }
};

#endif /* ndef _CSINGLEINSTANCET_HXX */
