/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cwinhdccreated.hxx
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
#if !defined(_CWINHDCCREATED_HXX) || defined(CWINHDCCREATED_MEMBERS_ONLY)
#if !defined(_CWINHDCCREATED_HXX) && !defined(CWINHDCCREATED_MEMBERS_ONLY)
#define _CWINHDCCREATED_HXX
#endif /* !defined(_CWINHDCCREATED_HXX) && !defined(CWINHDCCREATED_MEMBERS_ONLY) */

#if !defined(CWINHDCCREATED_MEMBERS_ONLY)
#include "cwinhdccreatedinterface.hxx"
#include "cwinhdcacquired.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinHDCCreated;
/**
 **********************************************************************
 * Typedef: cWinHDCCreatedExtend
 *
 *  Author: $author$
 *    Date: 8/4/2010
 **********************************************************************
 */
typedef cCreatedT
<cWinHDCCreated, 
 cWinHDCCreatedImplement, 
 cWinHDCAcquired>
cWinHDCCreatedExtend;
/**
 **********************************************************************
 *  Class: cWinHDCCreated
 *
 * Author: $author$
 *   Date: 8/4/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinHDCCreated
: virtual public cWinHDCCreatedImplement,
  public cWinHDCCreatedExtend
{
public:
    typedef cWinHDCCreatedImplement cImplements;
    typedef cWinHDCCreatedExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinHDCCreated
     *
     *       Author: $author$
     *         Date: 8/4/2010
     **********************************************************************
     */
    cWinHDCCreated
    (HDC attached,
     HWND hWndAttached,
     bool isAcquired=false)
    {
        m_attached = attached;
        m_hWndAttached = hWndAttached;
        m_isAcquired = isAcquired;
    }
    /**
     **********************************************************************
     *  Constructor: cWinHDCCreated
     *
     *       Author: $author$
     *         Date: 8/4/2010
     **********************************************************************
     */
    cWinHDCCreated
    (HDC attached=NULL,
     bool isCreated=false)
    : cExtends(isCreated)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinHDCCreated
     *
     *      Author: $author$
     *        Date: 8/4/2010
     **********************************************************************
     */
    virtual ~cWinHDCCreated()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINHDCCREATED_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCCREATED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: CreateCompatible
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual eError CreateCompatible
    (HDC hDC,
     bool onlyDestroyed=false)
#if defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateCompatibleAttached(error, hDC, onlyDestroyed);
#else /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreateCompatibleAttached
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual HDC CreateCompatibleAttached
    (eError& error, HDC hDC,
     bool onlyDestroyed=false)
#if defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    {
        HDC attached = NULL;
#if !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT)
        HDC detached;
        
        if (!(error = Destroyed(onlyDestroyed)))
        if ((detached = CreateCompatibleDetached(error, hDC)))
        if (detached == (AttachCreated(detached)))
            attached = detached;
        else
        {
            DeleteDetached(detached);
            error = e_ERROR_FAILED;
        }
#else /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Destroy
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false)
#if defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NONE;
        HDC detached;
        
        if ((detached = Detach()))
            error = DeleteDetached(detached);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;
            
#else /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: CreateCompatibleDetached
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual HDC CreateCompatibleDetached
    (eError& error, HDC hDC) const
#if defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    {
        HDC detached = NULL;
#if !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_FAILED;
        if (hDC)
        if ((detached = CreateCompatibleDC(hDC)))
            error = e_ERROR_NONE;
#else /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: DeleteDetached
     *
     *    Author: $author$
     *      Date: 8/4/2010
     **********************************************************************
     */
    virtual eError DeleteDetached
    (HDC detached) const
#if defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        if (detached)
        if (DeleteDC(detached))
            error = e_ERROR_NONE;
#else /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINHDCCREATED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINHDCCREATED_MEMBERS_ONLY)
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHDCCREATED_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCCREATED_MEMBERS_ONLY) */

#endif /* !defined(_CWINHDCCREATED_HXX) || defined(CWINHDCCREATED_MEMBERS_ONLY) */
