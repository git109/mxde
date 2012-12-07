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
 *   File: cwinlistboxcontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
#if !defined(_CWINLISTBOXCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINLISTBOXCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINLISTBOXCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINLISTBOXCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#define CWINLISTBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_LISTBOX

#define CWINLISTBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINLISTBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

class c_INSTANCE_CLASS cWinListBoxControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinListBoxControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinListBoxControlWindowSuperClass>
cWinListBoxControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinListBoxControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinListBoxControlWindowSuperClass
: /*virtual public cWinListBoxControlWindowSuperClassImplement,*/
  public cWinListBoxControlWindowSuperClassExtend
{
public:
    /*typedef cWinListBoxControlWindowSuperClassImplement cImplements;*/
    typedef cWinListBoxControlWindowSuperClassExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinListBoxControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/22/2010
     **********************************************************************
     */
    cWinListBoxControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINLISTBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINLISTBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinListBoxControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/22/2010
     **********************************************************************
     */
    virtual ~cWinListBoxControlWindowSuperClass()
    {
    }
#else /* !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINLISTBOXCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINLISTBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
