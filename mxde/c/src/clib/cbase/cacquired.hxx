/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cacquired.hxx
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
#if !defined(_CACQUIRED_HXX) || defined(CACQUIRED_MEMBERS_ONLY)
#if !defined(_CACQUIRED_HXX) && !defined(CACQUIRED_MEMBERS_ONLY)
#define _CACQUIRED_HXX
#endif /* !defined(_CACQUIRED_HXX) && !defined(CACQUIRED_MEMBERS_ONLY) */

#if !defined(CACQUIRED_MEMBERS_ONLY)
#include "cacquiredinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cAcquired definition
 */
class c_INSTANCE_CLASS cAcquired;

#undef CDB_CLASS
#define CDB_CLASS "cAcquiredT"
/**
 **********************************************************************
 *  Class: cAcquiredT
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
template
<class TDerives=cAcquired,
 class TAcquiredImplement=cAcquiredImplement,
 class TBase=cBase,
 class TImplements=TAcquiredImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cAcquiredT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cAcquiredT cDerives;

/* include cAcquired interface member definitions
 */
#define CACQUIREDINTERFACE_MEMBERS_ONLY
#include "cacquiredinterface.hxx"
#undef CACQUIREDINTERFACE_MEMBERS_ONLY

    bool m_isAcquired;

    /**
     **********************************************************************
     * Constructor: cAcquiredT
     *
     *      Author: $author$
     *        Date: 5/26/2009
     **********************************************************************
     */
    cAcquiredT
    (bool isAcquired=false) 
    : m_isAcquired(isAcquired)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAcquiredT
     *
     *     Author: $author$
     *       Date: 5/26/2009
     **********************************************************************
     */
    virtual ~cAcquiredT()
    {
        eError error;
        if ((error = Released()))
            throw(error);
    }
#else /* !defined(CACQUIRED_MEMBERS_ONLY) */
#endif /* !defined(CACQUIRED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Released
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError Released
    (bool onlyReleased=false) 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        bool isAcquired;

        if ((isAcquired = IsAcquired()))
        if (onlyReleased)
            return e_ERROR_ALREADY_ACQUIRED;
        else
        if ((error = Release(isAcquired)))
            return error;
        return error;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError Acquire
    (bool onlyReleased=false) 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        bool isAcquired;
        int is;

        if ((isAcquired = IsAcquired()))
        if (onlyReleased)
            return e_ERROR_ALREADY_ACQUIRED;
        else
        if ((error = Release(isAcquired)))
            return error;

        if (!(error = AcquireReleased()))
        if (0 > (is = SetIsAcquired()))
            error = -is;
#else /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Release
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError Release
    (bool onlyAcquired=false) 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        bool isAcquired;
        int is;
        if ((isAcquired = IsAcquired()))
        {
            if (!(error = ReleaseAcquired()))
            if (0 > (is = SetIsAcquired(false)))
                error = -is;
        }
        else
        if (onlyAcquired)
            return e_ERROR_NOT_ACQUIRED;

#else /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: AcquireReleased
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError AcquireReleased() 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReleaseAcquired
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError ReleaseAcquired() 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIsAcquired
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual int SetIsAcquired
    (bool is=true) 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        int isAcquired = (m_isAcquired = is);
#else /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        int isAcquired = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return isAcquired;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: IsAcquired
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual bool IsAcquired() const 
#if defined(CACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        bool isAcquired = m_isAcquired;
#else /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        bool isAcquired = false;
#endif /* !defined(CACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return isAcquired;
    }
#endif /* defined(CACQUIRED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CACQUIRED_MEMBERS_ONLY) 
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CACQUIRED_MEMBERS_ONLY) */
#endif /* !defined(CACQUIRED_MEMBERS_ONLY) */

#endif /* !defined(_CACQUIRED_HXX) || defined(CACQUIRED_MEMBERS_ONLY) */
