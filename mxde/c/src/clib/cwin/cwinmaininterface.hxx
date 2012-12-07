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
 *   File: cwinmaininterface.hxx
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
#if !defined(_CWINMAININTERFACE_HXX) || defined(CWINMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CWINMAININTERFACE_HXX) && !defined(CWINMAININTERFACE_MEMBERS_ONLY)
#define _CWINMAININTERFACE_HXX
#endif /* !defined(_CWINMAININTERFACE_HXX) && !defined(CWINMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CWINMAININTERFACE_MEMBERS_ONLY)
#include "cwininterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cWinMainInterface
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinMainInterface
: virtual public cWinInterfaceBase
{
public:
    typedef cWinInterfaceBase cImplements;
    typedef cWinMainInterface cDerives;

    static cWinMainInterface* m_theWinMainInterface;
    /**
     **********************************************************************
     * Function: GetWinMainInterface
     *
     *   Author: $author$
     *     Date: 5/5/2009
     **********************************************************************
     */
    static cWinMainInterface* GetWinMainInterface();
    /**
     **********************************************************************
     * Function: SetWinMainInterface
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    static cWinMainInterface* SetWinMainInterface
    (cWinMainInterface* theWinMainInterface);
#else /* !defined(CWINMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINMAININTERFACE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: WinMain
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual INT WinMain
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
#if !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        INT result = 0;
        return result;
    }
#endif /* !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT) */
    /**
     **********************************************************************
     * Function: ProcessMessages
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual INT ProcessMessages
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
#if !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        INT result = 0;
        return result;
    }
#endif /* !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT) */
    /**
     **********************************************************************
     * Function: BeforeProcessMessages
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual INT BeforeProcessMessages
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
#if !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        INT result = 0;
        return result;
    }
#endif /* !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT) */
    /**
     **********************************************************************
     * Function: AfterProcessMessages
     *
     *   Author: $author$
     *     Date: 5/4/2009
     **********************************************************************
     */
    virtual INT AfterProcessMessages
    (HINSTANCE instance,
     HINSTANCE previnst,
     LPCMDLINE cmdline,
     INT cmdshow) 
#if !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        INT result = 0;
        return result;
    }
#endif /* !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT) */

    /**
     **********************************************************************
     * Function: GetHINSTANCE
     *
     *   Author: $author$
     *     Date: 5/6/2009
     **********************************************************************
     */
    virtual HINSTANCE GetHINSTANCE() const 
#if !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        HINSTANCE hInstance = NULL;
        return hInstance;
    }
#endif /* !defined(CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CWINMAININTERFACE_MEMBERS_ONLY) 
};

/**
 **********************************************************************
 *  Class: cWinMainImplement
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMainImplement
: virtual public cWinMainInterface
{
public:
    typedef cWinMainInterface cImplements;
    typedef cWinMainImplement cDerives;

/* include cWinMainInterface member functions implement
 */
#define CWINMAININTERFACE_MEMBERS_ONLY
#define CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT
#include "cwinmaininterface.hxx"
#undef CWINMAININTERFACE_MEMBER_FUNCS_IMPLEMENT
#undef CWINMAININTERFACE_MEMBERS_ONLY
};
#else /* !defined(CWINMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINMAININTERFACE_HXX) || defined(CWINMAININTERFACE_MEMBERS_ONLY) */
