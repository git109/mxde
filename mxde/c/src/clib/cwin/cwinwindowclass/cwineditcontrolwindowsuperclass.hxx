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
 *   File: cwineditcontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/19/2010
 **********************************************************************
 */
#if !defined(_CWINEDITCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINEDITCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINEDITCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINEDITCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#define CWINEDITCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_EDIT

#define CWINEDITCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINEDITCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinEditControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinEditControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/19/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinEditControlWindowSuperClass>
cWinEditControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinEditControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/19/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinEditControlWindowSuperClass
: public cWinEditControlWindowSuperClassExtend
{
public:
    typedef cWinEditControlWindowSuperClassExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinEditControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/19/2010
     **********************************************************************
     */
    cWinEditControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINEDITCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINEDITCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinEditControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/19/2010
     **********************************************************************
     */
    virtual ~cWinEditControlWindowSuperClass()
    {
    }
#else /* !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINEDITCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINEDITCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
