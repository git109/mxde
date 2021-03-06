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
 *   File: cwincomboboxcontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
#if !defined(_CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#define CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_COMBOBOX

#define CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinComboBoxControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinComboBoxControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/22/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinComboBoxControlWindowSuperClass>
cWinComboBoxControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinComboBoxControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinComboBoxControlWindowSuperClass
: /*virtual public cWinComboBoxControlWindowSuperClassImplement,*/
  public cWinComboBoxControlWindowSuperClassExtend
{
public:
    /*typedef cWinComboBoxControlWindowSuperClassImplement cImplements;*/
    typedef cWinComboBoxControlWindowSuperClassExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cWinComboBoxControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/22/2010
     **********************************************************************
     */
    cWinComboBoxControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinComboBoxControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/22/2010
     **********************************************************************
     */
    virtual ~cWinComboBoxControlWindowSuperClass()
    {
    }
#else /* !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINCOMBOBOXCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
