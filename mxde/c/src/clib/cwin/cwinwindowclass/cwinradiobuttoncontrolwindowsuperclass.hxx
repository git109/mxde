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
 *   File: cwinradiobuttoncontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#define CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_BUTTON

#define CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinRadioButtonControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinRadioButtonControlWindowSuperClassImplement
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 *
typedef cWinWindowSuperClassExtendTImplement
cWinRadioButtonControlWindowSuperClassImplement;*/
/**
 **********************************************************************
 * Typedef: cWinRadioButtonControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinRadioButtonControlWindowSuperClass>
cWinRadioButtonControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinRadioButtonControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRadioButtonControlWindowSuperClass
: /*virtual public cWinRadioButtonControlWindowSuperClassImplement,*/
  public cWinRadioButtonControlWindowSuperClassExtend
{
public:
    /*typedef cWinRadioButtonControlWindowSuperClassImplement cImplements;*/
    typedef cWinRadioButtonControlWindowSuperClassExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinRadioButtonControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/21/2010
     **********************************************************************
     */
    cWinRadioButtonControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRadioButtonControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/21/2010
     **********************************************************************
     */
    virtual ~cWinRadioButtonControlWindowSuperClass()
    {
    }
#else /* !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINRADIOBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
