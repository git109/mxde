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
 *   File: cwincheckboxcontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
#if !defined(_CWINCHECKBOXCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINCHECKBOXCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINCHECKBOXCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINCHECKBOXCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#define CWINCHECKBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_BUTTON

#define CWINCHECKBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINCHECKBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinCheckBoxControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinCheckBoxControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/21/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinCheckBoxControlWindowSuperClass>
cWinCheckBoxControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinCheckBoxControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinCheckBoxControlWindowSuperClass
: /*virtual public cWinCheckBoxControlWindowSuperClassImplement,*/
  public cWinCheckBoxControlWindowSuperClassExtend
{
public:
    /*typedef cWinCheckBoxControlWindowSuperClassImplement cImplements;*/
    typedef cWinCheckBoxControlWindowSuperClassExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinCheckBoxControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/21/2010
     **********************************************************************
     */
    cWinCheckBoxControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINCHECKBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINCHECKBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinCheckBoxControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/21/2010
     **********************************************************************
     */
    virtual ~cWinCheckBoxControlWindowSuperClass()
    {
    }
#else /* !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINCHECKBOXCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINCHECKBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
