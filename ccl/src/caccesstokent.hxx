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
 *   File: caccesstokent.hxx
 *
 * Author: $author$
 *   Date: 11/10/2003
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CACCESSTOKENT_HXX
#define _CACCESSTOKENT_HXX

#if defined(WIN32)
#include <windows.h>
#define TOKEN HANDLE
#define INVALID_TOKEN INVALID_HANDLE_VALUE
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

#include "csystemidt.hxx"
#include "cthreadt.hxx"
#include "cprocesst.hxx"
#include "chandlet.hxx"
#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cAccessTokenT
 *
 * Author: $author$
 *   Date: 11/10/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cAccessTokenT
: public cOpenedHandleT<TOKEN, (int)INVALID_TOKEN, TIs>
{
public:
    typedef cOpenedHandleT<TOKEN, (int)INVALID_TOKEN, TIs> cIs;

    /**
     **********************************************************************
     * Constructor: cAccessTokenT
     *
     *      Author: $author$
     *        Date: 11/10/2003
     **********************************************************************
     */
    cAccessTokenT(TOKEN token=INVALID_TOKEN, bool opened=false) 
    : cIs(token, opened) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAccessTokenT
     *
     *     Author: $author$
     *       Date: 11/10/2003
     **********************************************************************
     */
    virtual ~cAccessTokenT()
    {
    }

    /**
     **********************************************************************
     * Function: OpenThread
     *
     *   Author: $author$
     *     Date: 11/10/2003
     **********************************************************************
     */
    virtual eError OpenThread(THREAD thread)
    {
#if defined(WIN32)
        TOKEN handle;
        BOOL as_process = FALSE;

        if (OpenThreadToken
            (thread, TOKEN_QUERY, as_process, &handle))
        {
            m_handle = handle;
            return e_ERROR_NONE;
        }
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: OpenProcess
     *
     *   Author: $author$
     *     Date: 11/10/2003
     **********************************************************************
     */
    virtual eError OpenProcess(PROCESS process)
    {
#if defined(WIN32)
        TOKEN handle;

        if (OpenProcessToken(process, TOKEN_QUERY, &handle))
        {
            m_handle = handle;
            return e_ERROR_NONE;
        }
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
};

/**
 **********************************************************************
 *  Class: cAccessTokenGroupsT
 *
 * Author: $author$
 *   Date: 11/12/2003
 **********************************************************************
 */
template <class TIs=cBase>
class cAccessTokenGroupsT
: public TIs
{
public:
    typedef TIs cIs;

#if defined(WIN32)
    int m_groups_size;
    int m_groups_length;
    int m_groups_index;
    TOKEN_GROUPS *m_groups;
    struct
    {
        TOKEN_GROUPS m_groups;
        SID_AND_ATTRIBUTES m_sid_and_attributes[256];
    } m_default_groups;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

    /**
     **********************************************************************
     * Constructor: cAccessTokenGroupsT
     *
     *      Author: $author$
     *        Date: 11/12/2003
     **********************************************************************
     */
    cAccessTokenGroupsT()
#if defined(WIN32)
    : m_groups(&m_default_groups.m_groups),
      m_groups_size(sizeof(m_default_groups)),
      m_groups_length(0),
      m_groups_index(-1)
#else /* defined(WIN32) */
#endif /* defined(WIN32) */
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAccessTokenGroupsT
     *
     *     Author: $author$
     *       Date: 11/12/2003
     **********************************************************************
     */
    virtual ~cAccessTokenGroupsT()
    {
        if (m_groups)
        if (m_groups != &m_default_groups.m_groups)
            delete m_groups;
    }

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 11/12/2003
     **********************************************************************
     */
    virtual eError Get(TOKEN handle)
    {
#if defined(WIN32)
        DWORD length;

        if (GetTokenInformation
            (handle, TokenGroups, 
             m_groups, m_groups_size, &length))
        {
            m_groups_length = (int)length;
            return e_ERROR_NONE;
        }
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }

    /**
     **********************************************************************
     * Function: GetFirstId
     *
     *   Author: $author$
     *     Date: 11/17/2003
     **********************************************************************
     */
    virtual eError GetFirstId(cSystemIdInterface &id)
    {
#if defined(WIN32)
        eError error;
        PSID handle;

        if (m_groups_length >= sizeof(TOKEN_GROUPS))
        if (m_groups->GroupCount > 0)
        if (INVALID_PSID != (handle = m_groups->Groups
            [m_groups_index = 0].Sid))
        if (!(error = id.Attach(handle)))
            return e_ERROR_NONE;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: GetNextId
     *
     *   Author: $author$
     *     Date: 11/17/2003
     **********************************************************************
     */
    virtual eError GetNextId(cSystemIdInterface &id)
    {
#if defined(WIN32)
        eError error;
        PSID handle;

        if (m_groups_length >= sizeof(TOKEN_GROUPS))
        if (m_groups_index >= 0)
        if (m_groups->GroupCount > (DWORD)m_groups_index)
        if (INVALID_PSID != (handle = m_groups->Groups
            [m_groups_index++].Sid))
        if (!(error = id.Attach(handle)))
            return e_ERROR_NONE;
#else /* defined(WIN32) */
#endif /* defined(WIN32) */

        return e_ERROR_FAILED;
    }
};

#endif /* ndef _CACCESSTOKENT_HXX */
