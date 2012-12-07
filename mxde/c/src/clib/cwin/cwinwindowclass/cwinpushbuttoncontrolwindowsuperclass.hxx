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
 *   File: cwinpushbuttoncontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
#if !defined(_CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#define CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_BUTTON

#define CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinPushButtonControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinPushButtonControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/28/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinPushButtonControlWindowSuperClass>
cWinPushButtonControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinPushButtonControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/28/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinPushButtonControlWindowSuperClass
: //virtual public cWinPushButtonControlWindowSuperClassImplement,
  public cWinPushButtonControlWindowSuperClassExtend
{
public:
    //typedef cWinPushButtonControlWindowSuperClassImplement cImplements;
    typedef cWinPushButtonControlWindowSuperClassExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinPushButtonControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/28/2010
     **********************************************************************
     */
    cWinPushButtonControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinPushButtonControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/28/2010
     **********************************************************************
     */
    virtual ~cWinPushButtonControlWindowSuperClass()
    {
    }
#else /* !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINPUSHBUTTONCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
