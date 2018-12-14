/**
 **********************************************************************
 * Copyright (c) 1988-2005 $organization$.
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
 *   File: cmultipleinstancet.hxx
 *
 * Author: $author$
 *   Date: 9/15/2005
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CMULTIPLEINSTANCET_HXX
#define _CMULTIPLEINSTANCET_HXX

#include "cerror.h"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cMultipleInstanceT
 *
 * Author: $author$
 *   Date: 10/26/2003
 **********************************************************************
 */
template <class TAs, class TIs=cBase>
class cMultipleInstanceT
: public TIs
{
public:
    typedef TIs cIs;

    static TAs *m_instance;
    TAs *m_old_instance;

    /**
     **********************************************************************
     * Constructor: cMultipleInstanceT
     *
     *      Author: $author$
     *        Date: 10/26/2003
     **********************************************************************
     */
    cMultipleInstanceT(TAs *instance) 
    {
        eError error;

        if (this == m_instance)
            throw (error = e_ERROR_ALREADY_INSTANTIATED);

        if (this != instance)
            throw (error = e_ERROR_INSTANTIATE);

        m_old_instance = m_instance;
        m_instance = instance;
    }
    /**
     **********************************************************************
     * Destructor: ~cMultipleInstanceT
     *
     *     Author: $author$
     *       Date: 10/26/2003
     **********************************************************************
     */
    virtual ~cMultipleInstanceT()
    {
        eError error;

        if (this != m_instance)
            throw (error = e_ERROR_NOT_INSTANTIATED);

        m_instance = m_old_instance;
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

#endif /* _CMULTIPLEINSTANCET_HXX */
