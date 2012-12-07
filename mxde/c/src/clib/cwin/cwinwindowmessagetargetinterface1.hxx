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
 *   File: cwinwindowmessagetargetinterface.hxx
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
#if !defined(_CWINWINDOWMESSAGETARGETINTERFACE_HXX) || defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINWINDOWMESSAGETARGETINTERFACE_HXX) && !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY)
#define _CWINWINDOWMESSAGETARGETINTERFACE_HXX
#endif /* !defined(_CWINWINDOWMESSAGETARGETINTERFACE_HXX) && !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY)
#include "cwininterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowMessageTargetInterface
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinWindowMessageTargetInterface
: virtual public cWinInterfaceBase
{
public:
    typedef cWinInterfaceBase cImplements;
    typedef cWinWindowMessageTargetInterface cDerives;
#else /* !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnWindowMessage
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    virtual LRESULT OnWindowMessage
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
#if !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        LRESULT lResult;
        
        switch(msg)
        {
#include "cwinwindowmessagetargetinterface_cases.hxx"

        default:
            lResult = OnWindowMessageDefault(hWnd,msg,wParam,lParam);
        }
        return lResult;
    }
#endif /* !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT) */

#include "cwinwindowmessagetargetinterface_members.hxx"

    /**
     **********************************************************************
     * Function: OnWindowMessageDefault
     *
     *   Author: $author$
     *     Date: 5/7/2009
     **********************************************************************
     */
    virtual LRESULT OnWindowMessageDefault
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
#if !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT)
    = 0;
#else /* CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT */
    {
        LRESULT lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }
#endif /* !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) 
};

/**
 **********************************************************************
 *  Class: cWinWindowMessageTargetImplement
 *
 * Author: $author$
 *   Date: 5/7/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindowMessageTargetImplement
: virtual public cWinWindowMessageTargetInterface
{
public:
    typedef cWinWindowMessageTargetInterface cImplements;
    typedef cWinWindowMessageTargetImplement cDerives;

/* include cWinWindowMessageTargetInterface member functions implement
 */
#define CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY
#define CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT
#include "cwinwindowmessagetargetinterface.hxx"
#undef CWINWINDOWMESSAGETARGETINTERFACE_MEMBER_FUNCS_IMPLEMENT
#undef CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY
};
#else /* !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINWINDOWMESSAGETARGETINTERFACE_HXX) || defined(CWINWINDOWMESSAGETARGETINTERFACE_MEMBERS_ONLY) */
