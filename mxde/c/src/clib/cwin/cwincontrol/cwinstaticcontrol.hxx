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
 *   File: cwinstaticcontrol.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINSTATICCONTROL_HXX) || defined(CWINSTATICCONTROL_MEMBERS_ONLY)
#if !defined(_CWINSTATICCONTROL_HXX) && !defined(CWINSTATICCONTROL_MEMBERS_ONLY)
#define _CWINSTATICCONTROL_HXX
#endif /* !defined(_CWINSTATICCONTROL_HXX) && !defined(CWINSTATICCONTROL_MEMBERS_ONLY) */

#if !defined(CWINSTATICCONTROL_MEMBERS_ONLY)
#include "cwinstaticcontrolwindowsuperclass.hxx"
#include "cwincontrol.hxx"

#define CWINSTATICCONTROL_WINDOW_CLASSNAME \
    CWINSTATICCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINSTATICCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE

#define CWINSTATICCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinStaticControlExtend
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinControl
cWinStaticControlExtend;
/**
 **********************************************************************
 *  Class: cWinStaticControl
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinStaticControl
: /*virtual public cWinStaticControlImplement,*/
  public cWinStaticControlExtend
{
public:
    /*typedef cWinStaticControlImplement cImplements;*/
    typedef cWinStaticControlExtend cExtends;
    
    /**
     **********************************************************************
     *  Constructor: cWinStaticControl
     *
     *       Author: $author$
     *         Date: 7/21/2010
     **********************************************************************
     */
    cWinStaticControl
    (LPCTSTR className=CWINSTATICCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINSTATICCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINSTATICCONTROL_DEFAULT_WINDOW_EXSTYLE,
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
     *  Destructor: ~cWinStaticControl
     *
     *      Author: $author$
     *        Date: 7/21/2010
     **********************************************************************
     */
    virtual ~cWinStaticControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINSTATICCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINSTATICCONTROL_MEMBERS_ONLY) */

#if !defined(CWINSTATICCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSTATICCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINSTATICCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINSTATICCONTROL_HXX) || defined(CWINSTATICCONTROL_MEMBERS_ONLY) */
