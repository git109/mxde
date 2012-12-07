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
 *   File: cwinradiobuttoncontrol.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINRADIOBUTTONCONTROL_HXX) || defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY)
#if !defined(_CWINRADIOBUTTONCONTROL_HXX) && !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY)
#define _CWINRADIOBUTTONCONTROL_HXX
#endif /* !defined(_CWINRADIOBUTTONCONTROL_HXX) && !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY) */

#if !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY)
#include "cwinradiobuttoncontrolwindowsuperclass.hxx"
#include "cwincontrol.hxx"

#define CWINRADIOBUTTONCONTROL_WINDOW_CLASSNAME \
    CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME

#define CWINRADIOBUTTONCONTROL_DEFAULT_WINDOW_EXSTYLE \
    CWINCONTROL_DEFAULT_WINDOW_EXSTYLE | WS_EX_CLIENTEDGE

#define CWINRADIOBUTTONCONTROL_DEFAULT_WINDOW_STYLE \
    CWINCONTROL_DEFAULT_WINDOW_STYLE | WS_BORDER | BS_AUTORADIOBUTTON

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinRadioButtonControlImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 *
typedef cWinControlImplement
cWinRadioButtonControlImplement;*/
/**
 **********************************************************************
 * Typedef: cWinRadioButtonControlExtend
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinControl
cWinRadioButtonControlExtend;
/**
 **********************************************************************
 *  Class: cWinRadioButtonControl
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRadioButtonControl
: /*virtual public cWinRadioButtonControlImplement,*/
  public cWinRadioButtonControlExtend
{
public:
    /*typedef cWinRadioButtonControlImplement cImplements;*/
    typedef cWinRadioButtonControlExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinRadioButtonControl
     *
     *       Author: $author$
     *         Date: 7/21/2010
     **********************************************************************
     */
    cWinRadioButtonControl
    (LPCTSTR className=CWINRADIOBUTTONCONTROL_WINDOW_CLASSNAME,
     DWORD style=CWINRADIOBUTTONCONTROL_DEFAULT_WINDOW_STYLE,
     DWORD exStyle=CWINRADIOBUTTONCONTROL_DEFAULT_WINDOW_EXSTYLE,
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
     *  Destructor: ~cWinRadioButtonControl
     *
     *      Author: $author$
     *        Date: 7/21/2010
     **********************************************************************
     */
    virtual ~cWinRadioButtonControl()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#else /* !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY) */

#if !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY) */
#endif /* !defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY) */

#endif /* !defined(_CWINRADIOBUTTONCONTROL_HXX) || defined(CWINRADIOBUTTONCONTROL_MEMBERS_ONLY) */
