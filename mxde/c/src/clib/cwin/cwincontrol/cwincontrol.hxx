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
 *   File: cwincontrol.hxx
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
#if !defined(_CWINCONTROL_HXX) || defined(CWINCONTROL_MEMBERS_ONLY)
#if !defined(_CWINCONTROL_HXX) && !defined(CWINCONTROL_MEMBERS_ONLY)
#define _CWINCONTROL_HXX
#endif /* !defined(_CWINCONTROL_HXX) && !defined(CWINCONTROL_MEMBERS_ONLY) */

#if !defined(CWINCONTROL_MEMBERS_ONLY)
#include "cwincontrolinterface.hxx"
#include "cwinwindow.hxx"

#define CWINCONTROL_DEFAULT_WINDOW_CLASSNAME NULL

#define CWINCONTROL_DEFAULT_WINDOW_EXSTYLE 0

#define CWINCONTROL_DEFAULT_WINDOW_STYLE \
    WS_CHILD | WS_VISIBLE

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinControlExtend
 *
 *  Author: $author$
 *    Date: 3/24/2010
 **********************************************************************
 */
typedef cWinWindow
cWinControlExtend;
/**
 **********************************************************************
 *  Class: cWinControl
 *
 * Author: $author$
 *   Date: 3/24/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinControl
: virtual public cWinControlImplement,
  public cWinControlExtend
{
public:
    typedef cWinControlImplement cImplements;
    typedef cWinControlExtend cExtends;
    
    TLENGTH m_attachedClassNameLength;
    const TCHAR* m_attachedClassNameChars;
    cTCHARString m_attachedClassName;
    
    DWORD m_style;
    DWORD m_exStyle;
    
    /**
     **********************************************************************
     *  Constructor: cWinControl
     *
     *       Author: $author$
     *         Date: 7/20/2010
     **********************************************************************
     */
    cWinControl
    (LPCTSTR className,
     DWORD style=CWINCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINCONTROL_DEFAULT_WINDOW_EXSTYLE,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated),
      m_attachedClassNameLength(0),
      m_attachedClassNameChars(0),
      m_style(style),
      m_exStyle(exStyle)
    {
        if (className)
            AttachClassName(className);
    }
    /**
     **********************************************************************
     *  Constructor: cWinControl
     *
     *       Author: $author$
     *         Date: 3/24/2010
     **********************************************************************
     */
    cWinControl
    (HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends(hInstance, attached, isCreated),
      m_attachedClassNameLength(0),
      m_attachedClassNameChars(0),
      m_style(CWINCONTROL_DEFAULT_WINDOW_STYLE),
      m_exStyle(CWINCONTROL_DEFAULT_WINDOW_EXSTYLE)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinControl
     *
     *      Author: $author$
     *        Date: 3/24/2010
     **********************************************************************
     */
    virtual ~cWinControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINCONTROL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName = 0, 
     LPVOID lParam = 0, bool isCreated = false, bool onlyDestroyed = false)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateAttached
        (error, hInstance, hParentWnd, id, 
         x,y, width,height, windowName, lParam, 
         isCreated, onlyDestroyed);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Create
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual eError Create
    (HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName, 
     DWORD style, DWORD exStyle, LPCTSTR className, 
     LPVOID lParam = 0, bool isCreated = false, 
     bool onlyDestroyed = false)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        CreateAttached
        (error, hInstance, hParentWnd, id, x,y, width,height,
         windowName, style, exStyle, className, lParam,
         isCreated, onlyDestroyed);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual HWND CreateAttached
    (eError& error, 
     HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName = 0, 
     LPVOID lParam = 0, bool isCreated = false, bool onlyDestroyed = false)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        HWND detached = NULL;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        DWORD style = m_style;
        DWORD exStyle = m_exStyle;
        LPCTSTR className;
        
        error = e_ERROR_FAILED;
        
        if ((className = ClassNameAttached()))
            detached = CreateAttached
            (error, hInstance, hParentWnd, id, x,y, width,height,
             windowName, style, exStyle, className, lParam,
             isCreated, onlyDestroyed);
             
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateAttached
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual HWND CreateAttached
    (eError& error, 
     HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName, 
     DWORD style, DWORD exStyle, LPCTSTR className, 
     LPVOID lParam = 0, bool isCreated = false, 
     bool onlyDestroyed = false)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        HWND detached = NULL;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        
        if (!(error = Destroyed(onlyDestroyed)))
        if ((detached = CreateDetached
            (error, hInstance, hParentWnd, id, x,y, width,height,
             windowName, style, exStyle, className, lParam)))
        {
            if (detached == (AttachCreated(detached, isCreated)))
            {
                AttachInstance(hInstance);
                return detached;
            }
            DestroyDetached(detached);
        }
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateDetached
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual HWND CreateDetached
    (eError& error, 
     HINSTANCE hInstance, HWND hParentWnd, int id,
     int x, int y, int width, int height, LPCTSTR windowName, 
     DWORD style, DWORD exStyle, LPCTSTR className, LPVOID lParam) const
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        HWND detached = NULL;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)

        error = e_ERROR_FAILED;
        
        if (!className)
        if (!(className = ClassNameAttached()))
            return detached;
            
        detached = cWinWindow::CreateDetached
        (error, exStyle, className, windowName, style, 
         x,y, width,height, hParentWnd, (HMENU)(id),
         hInstance, lParam);
         
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD SetStyle(DWORD toStyle)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_style = toStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AddStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD AddStyle(DWORD toStyle)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_style |= toStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: RemoveStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD RemoveStyle(DWORD toStyle)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_style &= ~toStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Style
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD Style() const
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_style);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: SetExStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD SetExStyle(DWORD toStyle)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_exStyle = toStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AddExStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD AddExStyle(DWORD toStyle)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_exStyle |= toStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: RemoveExStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD RemoveExStyle(DWORD toStyle)
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_exStyle &= ~toStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: ExStyle
     *
     *    Author: $author$
     *      Date: 7/20/2010
     **********************************************************************
     */
    virtual DWORD ExStyle() const
#if defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        DWORD style = 0;
#if !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT)
        style = (m_exStyle);
#else /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return style;
    }
#endif /* defined(CWINCONTROL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINCONTROL_MEMBERS_ONLY)
#include "cwinclassnameattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINCONTROL_HXX) || defined(CWINCONTROL_MEMBERS_ONLY) */
