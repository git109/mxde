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
 *   File: cwinwindowclass.hxx
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
#ifndef _CWINWINDOWCLASS_HXX
#define _CWINWINDOWCLASS_HXX

#include "cwinwindowmessagetarget.hxx"
#include "cwinwndclass.hxx"
#include "cwinatom.hxx"
#include "cstring.hxx"

/**
 **********************************************************************
 *  Class: cWinWindowClassInterface
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinWindowClassInterface
: virtual public cWinAtomInterface
{
public:
    typedef cWinAtomInterface cImplements;
    typedef cWinWindowClassInterface cDerives;
};

/**
 **********************************************************************
 *  Class: cWinWindowClassImplement
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindowClassImplement
: virtual public cWinWindowClassInterface
{
public:
    typedef cWinWindowClassInterface cImplements;
    typedef cWinWindowClassImplement cDerives;
};

#define CWINWINDOWCLASS_CLASSNAME_CHARS "cWinWindowClass"

/**
 **********************************************************************
 *  Class: cWinWindowClass
 *
 * Author: $author$
 *   Date: 5/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinWindowClass
: virtual public cWinWindowClassImplement,
  public cWinAtom
{
public:
    typedef cWinWindowClassImplement cImplements;
    typedef cWinAtom cExtends;
    typedef cWinWindowClass cDerives;

    LPCTSTR m_windowClassNameChars;
    WNDPROC m_wndProc;
    HBRUSH m_hBackgroundBrush;
    int m_windowExtra;
    int m_windowExtraOffset;
    int m_classExtra;
    int m_classExtraOffset;
    UINT m_style;

    bool m_isRegistered;
    cWinWNDCLASS m_wndClass;

    cTString m_windowClassName;

    /**
     **********************************************************************
     * Constructor: cWinWindowClass
     *
     *      Author: $author$
     *        Date: 5/8/2009
     **********************************************************************
     */
    cWinWindowClass
    (LPCTSTR windowClassNameChars=_T
     (CWINWINDOWCLASS_CLASSNAME_CHARS),
     WNDPROC wndProc=cWinWindowMessageTarget::WindowProc,
     int windowExtra=(int)(sizeof(cWinInterfaceBase*)),
     int windowExtraOffset=0,
     int classExtra=0,
     int classExtraOffset=0,
     UINT style=0,
     ATOM attached=NULL,
     bool isRegistered=false,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_windowClassNameChars(windowClassNameChars),
      m_wndProc(wndProc),
      m_hBackgroundBrush(NULL),
      m_windowExtra(windowExtra),
      m_windowExtraOffset(windowExtraOffset),
      m_classExtra(classExtra),
      m_classExtraOffset(classExtraOffset),
      m_style(style),
      m_isRegistered(isRegistered)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinWindowClass
     *
     *     Author: $author$
     *       Date: 5/8/2009
     **********************************************************************
     */
    virtual ~cWinWindowClass()
    {
        eError error;
        if ((error = Unregistered()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Register
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Register
    (HINSTANCE instance, LPCTSTR classname=NULL, WNDPROC wndproc=NULL,
     LPCTSTR menuname=NULL, HICON icon=NULL, HICON iconsm=NULL,
     HCURSOR cursor=NULL, HBRUSH background=NULL, UINT style=0,
     int wndextra=-1, int clsextra=-1,
     bool onlyUnregistered=false) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        ATOM detached, attached;

        if (!classname)
        if (!(classname = WindowClassName()))
            return error;

        if (!wndproc)
        if (!(wndproc = WindowProc()))
            return error;

        if (!background)
            background = Background();

        if (0 > wndextra)
            wndextra = WindowExtra();

        if (0 > clsextra)
            clsextra = ClassExtra();

        if (!style)
            style = Style();

        if ((error = Unregistered(onlyUnregistered)))
            return error;

        m_wndClass.Set
        (instance, classname, wndproc, menuname, icon, iconsm,
         cursor, background, style, wndextra, clsextra);

        if ((detached = m_wndClass.Register()))
        {
            if (detached == (attached = Attach(detached)))
            if (SetIsRegistered())
                return error = e_ERROR_NONE;

            m_wndClass.Unregister();
        }
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Unregister
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Unregister
    (bool onlyRegistered=false) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        ATOM detached;
        bool isRegistered;

        if ((isRegistered = IsRegistered()))
            SetIsRegistered(false);
        else
        if (onlyRegistered)
            return e_ERROR_NOT_CREATED;

        if (!(detached = Detach()))
        if (onlyRegistered)
            return e_ERROR_NOT_ATTACHED;

        error = m_wndClass.Unregister();
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Unregistered
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual eError Unregistered
    (bool onlyUnregistered=false) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NONE;
        bool isRegistered;

        if (!(isRegistered = IsRegistered()))
            error = Detached(onlyUnregistered);
        else
        if (onlyUnregistered)
            error = e_ERROR_ALREADY_CREATED;
        else
        error = Unregister(isRegistered);
        return error;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIsRegistered
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual int SetIsRegistered
    (bool is=true) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
        int isRegistered = false;
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        isRegistered = (m_isRegistered = is);
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return isRegistered;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: IsRegistered
     *
     *   Author: $author$
     *     Date: 5/8/2009
     **********************************************************************
     */
    virtual bool IsRegistered() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
        bool isRegistered = false;
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        isRegistered = m_isRegistered;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return isRegistered;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowClassName
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual TLENGTH SetWindowClassName
    (LPCTSTR chars,
     TLENGTH length=-1) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH count = 0;
        if (0 > (count = m_windowClassName.Assign(chars, length)))
            return count;
        if ((chars = m_windowClassName.HasChars(length)))
            m_windowClassNameChars = chars;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowClassName
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual LPCTSTR WindowClassName() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        LPCTSTR chars = m_windowClassNameChars;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        LPCTSTR chars =0;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowProc
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual WNDPROC SetWindowProc
    (WNDPROC wndProc) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        m_wndProc = wndProc;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        wndProc = DefWindowProc;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return wndProc;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowProc
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual WNDPROC WindowProc() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        WNDPROC wndProc = m_wndProc;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        WNDPROC wndProc = DefWindowProc;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return wndProc;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowExtra
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int SetWindowExtra
    (int bytes) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = (m_windowExtra = bytes);
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowExtra
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int WindowExtra() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = m_windowExtra;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWindowExtraOffset
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int SetWindowExtraOffset
    (int bytes) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
        int count = 0;
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: WindowExtraOffset
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int WindowExtraOffset() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = m_windowExtraOffset;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = 0;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetClassExtra
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int SetClassExtra
    (int bytes) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = (m_classExtra = bytes);
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ClassExtra
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int ClassExtra() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = m_classExtra;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetClassExtraOffset
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int SetClassExtraOffset
    (int bytes) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
        int count = 0;
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: ClassExtraOffset
     *
     *   Author: $author$
     *     Date: 5/9/2009
     **********************************************************************
     */
    virtual int ClassExtraOffset() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        int count = m_classExtraOffset;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        int count = 0;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetBackground
     *
     *   Author: $author$
     *     Date: 5/22/2009
     **********************************************************************
     */
    virtual HBRUSH SetBackground(HBRUSH hBrush) 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        m_hBackgroundBrush = hBrush;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        hBrush = NULL;
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return hBrush;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Background
     *
     *   Author: $author$
     *     Date: 5/22/2009
     **********************************************************************
     */
    virtual HBRUSH Background() const 
#if defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE */
    {
        HBRUSH hBrush = NULL;
#if !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) 
        hBrush = m_hBackgroundBrush;
#else /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINWINDOWCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return hBrush;
    }
#endif /* defined(CWINWINDOWCLASS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetStyle
     *
     *   Author: $author$
     *     Date: 12/12/2009
     **********************************************************************
     */
    virtual UINT SetStyle
    (UINT toStyle) 
#if defined(CWINCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINCLASS_MEMBER_FUNCS_INTERFACE) */
    {
        UINT style = 0;
#if !defined(CWINCLASS_MEMBER_FUNCS_IMPLEMENT) 
        style = (m_style = toStyle);
#else /* !defined(CWINCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCLASS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Style
     *
     *   Author: $author$
     *     Date: 12/12/2009
     **********************************************************************
     */
    virtual UINT Style() const 
#if defined(CWINCLASS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINCLASS_MEMBER_FUNCS_INTERFACE) */
    {
        UINT style = 0;
#if !defined(CWINCLASS_MEMBER_FUNCS_IMPLEMENT) 
        style = (m_style);
#else /* !defined(CWINCLASS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCLASS_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCLASS_MEMBER_FUNCS_INTERFACE) */
};
#endif /* _CWINWINDOWCLASS_HXX */
