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
 *   File: cxtwidgetclassinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/24/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETCLASSINTERFACE_HXX) || defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTWIDGETCLASSINTERFACE_HXX) && !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY)
#define _CXTWIDGETCLASSINTERFACE_HXX
#endif /* !defined(_CXTWIDGETCLASSINTERFACE_HXX) && !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY)
#include "cxtwidgetclassattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWidgetClassInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/24/2010
 **********************************************************************
 */
typedef cXtWidgetClassAttachedInterface
cXtWidgetClassInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtWidgetClassInterface
 *
 * Author: $author$           
 *   Date: 6/24/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWidgetClassInterface
: virtual public cXtWidgetClassInterfaceImplement
{
public:
    typedef cXtWidgetClassInterfaceImplement cImplements;
#else /* !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXTWIDGETCLASSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtWidgetClassImplement
 *
 * Author: $author$           
 *   Date: 6/24/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWidgetClassImplement
: virtual public cXtWidgetClassInterface
{
public:
    typedef cXtWidgetClassInterface cImplements;
#else /* !defined(CXTWIDGETCLASSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCLASSIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXTWIDGETCLASSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETCLASSINTERFACE_HXX) || defined(CXTWIDGETCLASSINTERFACE_MEMBERS_ONLY) */
