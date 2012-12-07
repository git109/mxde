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
 *   File: cwindc.hxx
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
#if !defined(_CWINDC_HXX) || defined(CWINDCATTACHED_MEMBERS_ONLY)
#if !defined(_CWINDC_HXX) && !defined(CWINDCATTACHED_MEMBERS_ONLY)
#define _CWINDC_HXX
#endif /* !defined(_CWINDC_HXX) && !defined(CWINDCATTACHED_MEMBERS_ONLY) */

#include "cwininterfacebase.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "cacquired.hxx"
#include "ccreated.hxx"

class c_INTERFACE_CLASS cWinDCAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinDCAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinDCAttachedInterface, 
 HDC, UINT, NULL, cWinInterfaceBase>
cWinDCAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinDCAttachedInterface
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinDCAttachedInterface
: virtual public cWinDCAttachedInterfaceImplements
{
public:
    typedef cWinDCAttachedInterfaceImplements cImplements;
    typedef cWinDCAttachedInterface cDerives;
};
class c_EXPORT_CLASS cWinDCAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinDCAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinDCAttachedImplement, 
 cWinDCAttachedInterface, 
 HDC, UINT, NULL>
cWinDCAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinDCAttachedImplement
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDCAttachedImplement
: virtual public cWinDCAttachedImplementImplements
{
public:
    typedef cWinDCAttachedImplementImplements cImplements;
    typedef cWinDCAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinDCAttached;
/**
 **********************************************************************
 * Typedef: cWinDCAttachedExtends
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinDCAttached, 
 cWinDCAttachedImplement, 
 cWinDCAttachedInterface,
 HDC, UINT, NULL, cWinBase>
cWinDCAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinDCAttached
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDCAttached
: public cWinDCAttachedExtends
{
public:
    typedef cWinDCAttachedExtends cExtends;
    typedef cWinDCAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinDCAttached
     *
     *      Author: $author$
     *        Date: 5/25/2009
     **********************************************************************
     */
    cWinDCAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cWinDCAcquiredInterface;
/**
 **********************************************************************
 * Typedef: cWinDCAcquiredInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/26/2009
 **********************************************************************
 */
typedef cAcquiredInterfaceT
<cWinDCAcquiredInterface, cWinDCAttachedInterface>
cWinDCAcquiredInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinDCAcquiredInterface
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinDCAcquiredInterface
: virtual public cWinDCAcquiredInterfaceImplements
{
public:
    typedef cWinDCAcquiredInterfaceImplements cImplements;
    typedef cWinDCAcquiredInterface cDerives;
};
class c_EXPORT_CLASS cWinDCAcquiredImplement;
/**
 **********************************************************************
 * Typedef: cWinDCAcquiredImplementImplements
 *
 *  Author: $author$
 *    Date: 5/26/2009
 **********************************************************************
 */
typedef cAcquiredImplementT
<cWinDCAcquiredImplement, cWinDCAcquiredInterface>
cWinDCAcquiredImplementImplements;
/**
 **********************************************************************
 *  Class: cWinDCAcquiredImplement
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDCAcquiredImplement
: virtual public cWinDCAcquiredImplementImplements
{
public:
    typedef cWinDCAcquiredImplementImplements cImplements;
    typedef cWinDCAcquiredImplement cDerives;
};
class c_EXPORT_CLASS cWinDCAcquired;
/**
 **********************************************************************
 * Typedef: cWinDCAcquiredExtends
 *
 *  Author: $author$
 *    Date: 5/26/2009
 **********************************************************************
 */
typedef cAcquiredT
<cWinDCAcquired, 
 cWinDCAcquiredImplement, 
 cWinDCAttached>
cWinDCAcquiredExtends;
/**
 **********************************************************************
 *  Class: cWinDCAcquired
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDCAcquired
: public cWinDCAcquiredExtends
{
public:
    typedef cWinDCAcquiredExtends cExtends;
    typedef cWinDCAcquired cDerives;

    HWND m_hWndAcquired;

    /**
     **********************************************************************
     * Constructor: cWinDCAcquired
     *
     *      Author: $author$
     *        Date: 5/26/2009
     **********************************************************************
     */
    cWinDCAcquired
    (HWND hWnd=NULL,
     bool isAcquired=false) 
    : cExtends(isAcquired),
      m_hWndAcquired(hWnd)
    {
    }
};

class c_INTERFACE_CLASS cWinDCInterface;
/**
 **********************************************************************
 * Typedef: cWinDCInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinDCInterface, cWinDCAcquiredInterface>
cWinDCInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinDCInterface
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinDCInterface
: virtual public cWinDCInterfaceImplements
{
public:
    typedef cWinDCInterfaceImplements cImplements;
    typedef cWinDCInterface cDerives;
};
class c_EXPORT_CLASS cWinDCImplement;
/**
 **********************************************************************
 * Typedef: cWinDCImplementImplements
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinDCImplement, cWinDCInterface>
cWinDCImplementImplements;
/**
 **********************************************************************
 *  Class: cWinDCImplement
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDCImplement
: virtual public cWinDCImplementImplements
{
public:
    typedef cWinDCImplementImplements cImplements;
    typedef cWinDCImplement cDerives;
};
class c_EXPORT_CLASS cWinDC;
/**
 **********************************************************************
 * Typedef: cWinDCExtends
 *
 *  Author: $author$
 *    Date: 5/25/2009
 **********************************************************************
 */
typedef cCreatedT
<cWinDC, 
 cWinDCImplement, 
 cWinDCAcquired>
cWinDCExtends;
/**
 **********************************************************************
 *  Class: cWinDC
 *
 * Author: $author$
 *   Date: 5/25/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDC
: public cWinDCExtends
{
public:
    typedef cWinDCExtends cExtends;
    typedef cWinDC cDerives;

    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 5/27/2009
     **********************************************************************
     */
    cWinDC
    (HWND hWnd) 
    {
        eError error;
        if (hWnd)
        if ((error = Get(hWnd, true)))
            throw(error);
    }
    /**
     **********************************************************************
     * Constructor: cWinDC
     *
     *      Author: $author$
     *        Date: 5/25/2009
     **********************************************************************
     */
    cWinDC
    (HDC detached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        HDC attached;
        eError error;
        if (detached)
        if (detached != (attached = Attach(detached)))
            throw(error = e_ERROR_NOT_ATTACHED);
    }
    /**
     **********************************************************************
     * Destructor: ~cWinDC
     *
     *     Author: $author$
     *       Date: 5/25/2009
     **********************************************************************
     */
    virtual ~cWinDC()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
        if ((error = Released()))
            throw(error);
        if ((error = Detached()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: CreateCompatible
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError CreateCompatible
    (HDC hDC,
     bool onlyDestroyed=false) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        HDC detached, attached;
        bool isAcquired, isCreated;
        int is;

        if ((isAcquired = IsAcquired()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_ACQUIRED;
        else
        if ((error = Release(isAcquired)))
            return error;

        if ((isCreated = IsCreated()))
        if (onlyDestroyed)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(isCreated)))
            return error;

        if ((detached = CreateCompatibleDetached(error, hDC)))
        {
            if (detached == (attached = Attach(detached)))
            {
                if (0 < (is = SetIsCreated()))
                    return e_ERROR_NONE;
                else
                if (0 > is)
                    error = -is;
                else
                error = e_ERROR_FAILED;

                Detach();
            }
            DeleteDetached(detached);
        }
#else /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyed=false) 
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ALLOWED;
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CCREATED_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CCREATED_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        HDC detached;
        bool isCreated;
        int is;

        if ((isCreated = IsCreated()))
        {
            if (0 > (is = SetIsCreated(false)))
                error = -is;
            else
            if ((detached = Detach()))
                error = DeleteDetached(detached);
            else
            error = e_ERROR_NOT_ATTACHED;
        }
        else
        if (onlyCreated)
            error = e_ERROR_NOT_CREATED;

#else /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CCREATED_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CCREATED_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        HDC detached, attached;
        bool isAcquired, isCreated;
        int is;

        if ((isCreated = IsCreated()))
        if (onlyReleased)
            return e_ERROR_ALREADY_CREATED;
        else
        if ((error = Destroy(isCreated)))
            return error;

        if ((isAcquired = IsAcquired()))
        if (onlyReleased)
            return e_ERROR_ALREADY_ACQUIRED;
        else
        if ((error = Release(isAcquired)))
            return error;

        if ((detached = GetDetached(error, hWnd)))
        {
            if (detached != (attached = Attach(detached)))
                error = e_ERROR_ATTACH;
            else
            {
                if (0 <= (is = SetIsAcquired()))
                    return e_ERROR_NONE;
                error = -is;
                Detach();
            }
            ReleaseDetached(hWnd, detached);
        }
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Acquire
     *
     *   Author: $author$
     *     Date: 5/27/2009
     **********************************************************************
     */
    virtual eError Acquire
    (bool onlyed=false) 
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ALLOWED;
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        HDC detached;
        HWND hWnd;
        bool isAcquired;

        if ((isAcquired = IsAcquired()))
        {
            SetIsAcquired(false);
            if ((hWnd = m_hWndAcquired))
            {
                m_hWndAcquired = NULL;
                if ((detached = Detach()))
                    error = ReleaseDetached(hWnd, detached);
                else
                error = e_ERROR_NOT_ATTACHED;
            }
        }
        else
        if (onlyAcquired)
            error = e_ERROR_NOT_ACQUIRED;
        else
        error = e_ERROR_NONE;

#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CreateCompatibleDetached
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual HDC CreateCompatibleDetached
    (eError& error,
     HDC hDC) const 
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
        HDC detached = NULL;
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_FAILED;
        if (hDC)
        if ((detached = CreateCompatibleDC(hDC)))
            error = e_ERROR_NONE;
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DeleteDetached
     *
     *   Author: $author$
     *     Date: 5/26/2009
     **********************************************************************
     */
    virtual eError DeleteDetached
    (HDC detached) const 
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        if (detached)
        if (DeleteDC(detached))
            error = e_ERROR_NONE;
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */

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
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
        HDC detached = NULL;
        error = e_ERROR_FAILED;
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
        if (hWnd)
        if ((detached = GetDC(hWnd)))
            error = e_ERROR_NONE;
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CWINDC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDC_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) 
        int ok;
        if (detached)
        if ((ok = ReleaseDC(hWnd, detached)))
            error = e_ERROR_NONE;
#else /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINDC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDC_MEMBER_FUNCS_INTERFACE) */
};
#endif /* !defined(_CWINDC_HXX) || defined(CWINDCATTACHED_MEMBERS_ONLY) */
