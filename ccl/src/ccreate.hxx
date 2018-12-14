/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: ccreate.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CCREATE_HXX
#define _CCREATE_HXX

#include "ccreateinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cCreate
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cCreate
: virtual public cCreateImplement,
  public cInstance
{
public:
    typedef cInstance cIs;

    bool m_is_created;

    /**
     **********************************************************************
     * Constructor: cCreate
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cCreate(bool is_created=false) 
    : m_is_created(is_created)
    {
    }

    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error = e_ERROR_NONE;

        m_is_created = false;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 4/3/2004
     **********************************************************************
     */
    virtual bool SetIsCreated(bool is_created=true)
    {
        m_is_created = is_created;
        return m_is_created;
    }
    /**
     **********************************************************************
     * Function: GetIsCreated
     *
     *   Author: $author$
     *     Date: 11/16/2003
     **********************************************************************
     */
    virtual bool GetIsCreated() const
    {
        return m_is_created;
    }
};

#endif /* _CCREATE_HXX */


