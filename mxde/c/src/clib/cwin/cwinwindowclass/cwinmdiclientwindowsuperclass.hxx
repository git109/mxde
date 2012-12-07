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
 *   File: cwinmdiclientwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
#if !defined(_CWINMDICLIENTWINDOWSUPERCLASS_HXX) || defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINMDICLIENTWINDOWSUPERCLASS_HXX) && !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINMDICLIENTWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINMDICLIENTWINDOWSUPERCLASS_HXX) && !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"

#define CWINMDICLIENTWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME "MDIClient"
#define CWINMDICLIENTWINDOWSUPERCLASS_WINDOW_CLASSNAME "cWinMDIClient"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Struct: sWinCLIENTCREATESTRUCT
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
struct sWinCLIENTCREATESTRUCT
{
    CLIENTCREATESTRUCT ccs;
    cWinWindowMessageTargetInterface* target;
};

class c_EXPORT_CLASS cWinMDIClientWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinMDIClientWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 1/1/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinMDIClientWindowSuperClass>
cWinMDIClientWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinMDIClientWindowSuperClass
 *
 * Author: $author$
 *   Date: 1/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinMDIClientWindowSuperClass
: public cWinMDIClientWindowSuperClassExtend
{
public:
    typedef cWinMDIClientWindowSuperClassExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinMDIClientWindowSuperClass
     *
     *       Author: $author$
     *         Date: 1/1/2010
     **********************************************************************
     */
    cWinMDIClientWindowSuperClass
    (LPCTSTR windowSubclassNameChars=_T(CWINMDICLIENTWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME),
     LPCTSTR windowClassNameChars=_T(CWINMDICLIENTWINDOWSUPERCLASS_WINDOW_CLASSNAME)) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars,
       DerivedWindowClassProc)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinMDIClientWindowSuperClass
     *
     *      Author: $author$
     *        Date: 1/1/2010
     **********************************************************************
     */
    virtual ~cWinMDIClientWindowSuperClass()
    {
    }
#else /* !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: DerivedWindowClassProc
     *
     *   Author: $author$
     *     Date: 1/1/2010
     **********************************************************************
     */
    static LRESULT CALLBACK DerivedWindowClassProc
    (HWND hWnd,
     UINT msg,
     WPARAM wParam,
     LPARAM lParam) 
    {
        LRESULT lResult = 0;
        cWinWindowMessageTargetInterface* target=0;
        tWinWindowSuperClass* windowClassInstance;
        WNDPROC windowSubclassProc;
        sWinCLIENTCREATESTRUCT* ccs;
        CREATESTRUCT* cs;
        
        switch(msg)
        {
        case WM_CREATE:
            if ((cs = ((CREATESTRUCT*)(lParam))))
            if ((ccs = ((sWinCLIENTCREATESTRUCT*)(cs->lpCreateParams))))
                target = ccs->target;
            lResult = SetWindowClassProc
            (hWnd, msg, wParam, lParam, target);
            return lResult;
        }
        
        if ((windowClassInstance = DerivedWindowClassInstance()))
        if ((windowSubclassProc = windowClassInstance->WindowSubclassProc()))
            return lResult = CallWindowProc
            (windowSubclassProc, hWnd, msg, wParam, lParam);
            
        lResult = DefWindowProc(hWnd, msg, wParam, lParam);
        return lResult;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINMDICLIENTWINDOWSUPERCLASS_HXX) || defined(CWINMDICLIENTWINDOWSUPERCLASS_MEMBERS_ONLY) */
