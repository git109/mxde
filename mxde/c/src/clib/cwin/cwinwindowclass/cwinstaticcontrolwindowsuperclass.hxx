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
 *   File: cwinstaticcontrolwindowsuperclass.hxx
 *
 * Author: $author$
 *   Date: 7/20/2010
 **********************************************************************
 */
#if !defined(_CWINSTATICCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#if !defined(_CWINSTATICCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#define _CWINSTATICCONTROLWINDOWSUPERCLASS_HXX
#endif /* !defined(_CWINSTATICCONTROLWINDOWSUPERCLASS_HXX) && !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
#include "cwinwindowsuperclassextend.hxx"
#include "cwincontrol.hxx"

#define CWINSTATICCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME WC_STATIC

#define CWINSTATICCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME \
    CWINWINDOWSUPERCLASS_WINDOW_CLASSNAME_PREFIX \
    CWINSTATICCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cWinStaticControlWindowSuperClass;
/**
 **********************************************************************
 * Typedef: cWinStaticControlWindowSuperClassExtend
 *
 *  Author: $author$
 *    Date: 7/20/2010
 **********************************************************************
 */
typedef cWinWindowSuperClassExtendT
<cWinStaticControlWindowSuperClass>
cWinStaticControlWindowSuperClassExtend;
/**
 **********************************************************************
 *  Class: cWinStaticControlWindowSuperClass
 *
 * Author: $author$
 *   Date: 7/20/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinStaticControlWindowSuperClass
: public cWinStaticControlWindowSuperClassExtend
{
public:
    typedef cWinStaticControlWindowSuperClassExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinStaticControlWindowSuperClass
     *
     *       Author: $author$
     *         Date: 7/20/2010
     **********************************************************************
     */
    cWinStaticControlWindowSuperClass
    (LPCTSTR windowSubclassNameChars = CWINSTATICCONTROLWINDOWSUPERCLASS_WINDOW_SUBCLASSNAME,
     LPCTSTR windowClassNameChars = CWINSTATICCONTROLWINDOWSUPERCLASS_WINDOW_CLASSNAME) 
    : cExtends
      (windowSubclassNameChars, 
       windowClassNameChars)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinStaticControlWindowSuperClass
     *
     *      Author: $author$
     *        Date: 7/20/2010
     **********************************************************************
     */
    virtual ~cWinStaticControlWindowSuperClass()
    {
    }
#else /* !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#if !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
#endif /* !defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */

#endif /* !defined(_CWINSTATICCONTROLWINDOWSUPERCLASS_HXX) || defined(CWINSTATICCONTROLWINDOWSUPERCLASS_MEMBERS_ONLY) */
