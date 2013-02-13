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
 *   File: cxtwidgetinterface.hxx
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETINTERFACE_HXX) || defined(CXTWIDGETINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTWIDGETINTERFACE_HXX) && !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY)
#define _CXTWIDGETINTERFACE_HXX
#endif /* !defined(_CXTWIDGETINTERFACE_HXX) && !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY)
#include "cxtwidgetattached.hxx"
#include "cxtarglistinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWidgetInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cXtWidgetCreatedInterface
cXtWidgetInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtWidgetInterface
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWidgetInterface
: virtual public cXtWidgetInterfaceImplement
{
public:
    typedef cXtWidgetInterfaceImplement cImplements;
#else /* !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY) */

    typedef INT tInt;
    typedef TSIZE tSize;

#if !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY)
/* include cXtWidget member functions interface
 */
#define CXTWIDGET_MEMBERS_ONLY
#define CXTWIDGET_MEMBER_FUNCS_INTERFACE
#include "cxtwidget.hxx"
#undef CXTWIDGET_MEMBER_FUNCS_INTERFACE
#undef CXTWIDGET_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXtWidgetImplement
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWidgetImplement
: virtual public cXtWidgetInterface
{
public:
    typedef cXtWidgetInterface cImplements;

/* include cXtWidget member functions implement
 */
#define CXTWIDGET_MEMBERS_ONLY
#define CXTWIDGET_MEMBER_FUNCS_IMPLEMENT
#include "cxtwidget.hxx"
#undef CXTWIDGET_MEMBER_FUNCS_IMPLEMENT
#undef CXTWIDGET_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETINTERFACE_HXX) || defined(CXTWIDGETINTERFACE_MEMBERS_ONLY) */
