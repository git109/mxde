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
 *   File: cwineditcontrol.hxx
 *
 * Author: $author$
 *   Date: 7/20/2010
 **********************************************************************
 */
#if !defined(_CWINEDITCONTROL_HXX) || defined(CWINEDITCONTROL_MEMBERS_ONLY)
#if !defined(_CWINEDITCONTROL_HXX) && !defined(CWINEDITCONTROL_MEMBERS_ONLY)
#define _CWINEDITCONTROL_HXX
#endif /* !defined(_CWINEDITCONTROL_HXX) && !defined(CWINEDITCONTROL_MEMBERS_ONLY) */

#if !defined(CWINEDITCONTROL_MEMBERS_ONLY)
#include "cwineditcontrolwindowsuperclass.hxx"
#include "cwincontrol.hxx"
#include "cwinstring.hxx"

#define CWINEDITCONTROL_WINDOW_CLASSNAME \
    CWINEDITCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINEDITCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE | WS_EX_CLIENTEDGE

#define CWINEDITCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE | ES_AUTOHSCROLL

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinEditControlExtend
 *
 *  Author: $author$
 *    Date: 7/20/2010
 **********************************************************************
 */
typedef cWinControl
cWinEditControlExtend;
/**
 **********************************************************************
 *  Class: cWinEditControl
 *
 * Author: $author$
 *   Date: 7/20/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinEditControl
: /*virtual public cWinEditControlImplement,*/
  public cWinEditControlExtend
{
public:
    /*typedef cWinEditControlImplement cImplements;*/
    typedef cWinEditControlExtend cExtends;
    
    cWinString m_windowText;
    
    /**
     **********************************************************************
     *  Constructor: cWinEditControl
     *
     *       Author: $author$
     *         Date: 7/20/2010
     **********************************************************************
     */
    cWinEditControl
    (LPCTSTR className=CWINEDITCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINEDITCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINEDITCONTROL_DEFAULT_WINDOW_EXSTYLE,
     HINSTANCE hInstance=NULL,
     HWND attached=NULL,
     bool isCreated=false) 
    : cExtends
      (className, style, exStyle, 
       hInstance, attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEditControl
     *
     *      Author: $author$
     *        Date: 7/20/2010
     **********************************************************************
     */
    virtual ~cWinEditControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINEDITCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINEDITCONTROL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: SetText
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual eError SetText
    (const CHAR* chars,
      TLENGTH length=UNDEFINED_LENGTH)
#if defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        const TCHAR* tchars;
        
        if ((chars))
        if ((0 <= length))
        {
            if (0 > (length = m_windowText.Assign(chars, length)))
                return error = -length;
                
            if ((tchars = m_windowText.c_str()))
                error = cExtends::SetText(tchars);
        }
        else
        error = cExtends::SetText(chars);

#else /* !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: SetText
     *
     *    Author: $author$
     *      Date: 8/1/2010
     **********************************************************************
     */
    virtual eError SetText
    (const WCHAR* chars,
      TLENGTH length=UNDEFINED_LENGTH)
#if defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        const TCHAR* tchars;
        
        if ((chars))
        if ((0 <= length))
        {
            if (0 > (length = m_windowText.Assign(chars, length)))
                return error = -length;
                
            if ((tchars = m_windowText.c_str()))
                error = cExtends::SetText(tchars);
        }
        else
        error = cExtends::SetText(chars);

#else /* !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetText
     *
     *    Author: $author$
     *      Date: 7/29/2010
     **********************************************************************
     */
    virtual const TCHAR* GetText
    (TLENGTH& length)
#if defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE) */
    {
        const TCHAR* chars = 0;
#if !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT)
        TCHAR* buffer;
        TLENGTH bufferSize;
        HWND hWnd;
        
        length = -e_ERROR_NOT_ATTACHED;
        
        if ((hWnd = Attached()))
        if (0 <= (bufferSize = GetWindowTextLength(hWnd)))
        if (bufferSize <= (m_windowText.adjust_size(bufferSize+1)))
        if ((buffer = m_windowText.str()))
        if (bufferSize <= (GetWindowText(hWnd, buffer, bufferSize+1)))
        if ((chars = m_windowText.c_str()))
            length = bufferSize;
            
#else /* !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINEDITCONTROL_MEMBER_FUNCS_IMPLEMENT) */
        return chars;
    }
#endif /* defined(CWINEDITCONTROL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINEDITCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINEDITCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINEDITCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINEDITCONTROL_HXX) || defined(CWINEDITCONTROL_MEMBERS_ONLY) */
