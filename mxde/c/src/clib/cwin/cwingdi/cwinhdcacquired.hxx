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
 *   File: cwinhdcacquired.hxx
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
#if !defined(_CWINHDCACQUIRED_HXX) || defined(CWINHDCACQUIRED_MEMBERS_ONLY)
#if !defined(_CWINHDCACQUIRED_HXX) && !defined(CWINHDCACQUIRED_MEMBERS_ONLY)
#define _CWINHDCACQUIRED_HXX
#endif /* !defined(_CWINHDCACQUIRED_HXX) && !defined(CWINHDCACQUIRED_MEMBERS_ONLY) */

#if !defined(CWINHDCACQUIRED_MEMBERS_ONLY)
#include "cwinhdcacquiredinterface.hxx"
#include "cwinhdcattached.hxx"
#include "cacquired.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinHDCAcquired;
/**
 **********************************************************************
 * Typedef: cWinHDCAcquiredExtend
 *
 *  Author: $author$
 *    Date: 8/3/2010
 **********************************************************************
 */
typedef cAcquiredT
<cWinHDCAcquired, 
 cWinHDCAcquiredImplement, 
 cWinHDCAttached>
cWinHDCAcquiredExtend;
/**
 **********************************************************************
 *  Class: cWinHDCAcquired
 *
 * Author: $author$
 *   Date: 8/3/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinHDCAcquired
: virtual public cWinHDCAcquiredImplement,
  public cWinHDCAcquiredExtend
{
public:
    typedef cWinHDCAcquiredImplement cImplements;
    typedef cWinHDCAcquiredExtend cExtends;

    HWND m_hWndAttached;
        
    /**
     **********************************************************************
     *  Constructor: cWinHDCAcquired
     *
     *       Author: $author$
     *         Date: 8/3/2010
     **********************************************************************
     */
    cWinHDCAcquired
    (HDC attached=NULL,
     HWND hWndAttached=NULL,
     bool isAcquired=false)
    : cExtends(isAcquired),
      m_hWndAttached(hWndAttached)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinHDCAcquired
     *
     *      Author: $author$
     *        Date: 8/3/2010
     **********************************************************************
     */
    virtual ~cWinHDCAcquired()
    {
        eError error;
        DBE_THROW_ERROR(error, Released());
    }
#else /* !defined(CWINHDCACQUIRED_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCACQUIRED_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError Get
    (HWND hWnd, bool onlyReleased=false) 
#if defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        GetAttached(error, hWnd, onlyReleased);
#else /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: GetAttached
     *
     *    Author: $author$
     *      Date: 8/3/2010
     **********************************************************************
     */
    virtual HDC GetAttached
    (eError& error, HWND hWnd, 
     bool onlyReleased=false)
#if defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE) */
    {
        HDC attached = NULL;
#if !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT)
        HDC detached;
        
        if (!(error = Released(onlyReleased)))
        if ((detached = GetDetached(error, hWnd)))
        if (detached == (AttachAcquired(detached)))
        {
            attached = detached;
            m_hWndAttached = hWnd;
        }
        else
        {
            error = e_ERROR_FAILED;
            ReleaseDetached(hWnd, detached);
        }
#else /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return attached;
    }
#endif /* defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
        HWND hWndDetached;
        HDC detached;
        
        if ((detached = Detach()))
        {
            if ((hWndDetached = m_hWndAttached))
                error = ReleaseDetached
                (hWndDetached, detached);
            else
            error = e_ERROR_NOT_ATTACHED;
        }
        else
        if ((onlyAcquired))
            error = e_ERROR_NOT_ATTACHED;
            
        m_hWndAttached = NULL;
        
#else /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: GetDetached
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual HDC GetDetached
    (eError& error, HWND hWnd) const 
#if defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
        HDC detached = NULL;
        error = e_ERROR_FAILED;
#if !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        if (hWnd)
        if ((detached = GetDC(hWnd)))
            error = e_ERROR_NONE;
#else /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ReleaseDetached
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError ReleaseDetached
    (HWND hWnd, HDC detached) const 
#if defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) 
        int ok;
        if (detached)
        if ((ok = ReleaseDC(hWnd, detached)))
            error = e_ERROR_NONE;
#else /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINHDCACQUIRED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINHDCACQUIRED_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINHDCACQUIRED_MEMBERS_ONLY)
#include "cacquiredattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHDCACQUIRED_MEMBERS_ONLY) */
#endif /* !defined(CWINHDCACQUIRED_MEMBERS_ONLY) */

#endif /* !defined(_CWINHDCACQUIRED_HXX) || defined(CWINHDCACQUIRED_MEMBERS_ONLY) */
