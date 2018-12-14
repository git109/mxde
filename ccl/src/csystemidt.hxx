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
 *   File: csystemidt.hxx
 *
 * Author: $author$
 *   Date: 11/16/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CSYSTEMIDT_HXX
#define _CSYSTEMIDT_HXX

#if defined(WIN32)
#include <windows.h>
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "chandlet.hxx"
#include "csystemidinterface.hxx"
#include "cimplement.hxx"

/**
 **********************************************************************
 *  Class: cSystemIdT
 *
 * Author: $author$
 *   Date: 11/15/2003
 **********************************************************************
 */
template <class TIs=cSystemIdImplement>
class cSystemIdT
: virtual public cSystemIdInterface,
  public cCreatedHandleT<PSID, INVALID_PSID, TIs>
{
public:
    typedef cCreatedHandleT<PSID, INVALID_PSID, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cSystemIdT
     *
     *      Author: $author$
     *        Date: 11/15/2003
     **********************************************************************
     */
    cSystemIdT(PSID handle=INVALID_PSID, bool created=false) 
    : cIs(handle, created) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cSystemIdT
     *
     *     Author: $author$
     *       Date: 11/15/2003
     **********************************************************************
     */
    virtual ~cSystemIdT()
    {
        eError error;

        if (INVALID_PSID != m_handle)
        if (m_created)
        if ((error = Destroy()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: CreateAsAdmin
     *
     *   Author: $author$
     *     Date: 11/15/2003
     **********************************************************************
     */
    virtual eError CreateAsAdmin()
    {
        SID_IDENTIFIER_AUTHORITY auth = SECURITY_NT_AUTHORITY;
        PSID handle;

        if (m_created)
            return e_ERROR_ALREADY_CREATED;

        if (AllocateAndInitializeSid
            (&auth,2,SECURITY_BUILTIN_DOMAIN_RID,
             DOMAIN_ALIAS_RID_ADMINS,0,0,0,0,0,0,&handle))
        {
            m_created = true;
            m_handle = handle;
            return e_ERROR_NONE;
        }

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 11/15/2003
     **********************************************************************
     */
    virtual eError Destroy()
    {
        PSID handle;

        if (!m_created)
            return e_ERROR_NOT_CREATED;

        handle = m_handle;
        m_handle = INVALID_PSID;

#if defined(WIN32)
        FreeSid(handle);
#else // defined(WIN32)
#endif // defined(WIN32)

        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: Equal
     *
     *   Author: $author$
     *     Date: 11/17/2003
     **********************************************************************
     */
    virtual bool Equal(cSystemIdInterface &id)
    {
#if defined(WIN32)
        PSID handle;

        if (INVALID_PSID != m_handle)
        if (INVALID_PSID != (handle = id.GetHandle()))
        if (EqualSid(m_handle, handle))
            return true;
#else // defined(WIN32)
#endif // defined(WIN32)

        return false;
    }
};

#endif
