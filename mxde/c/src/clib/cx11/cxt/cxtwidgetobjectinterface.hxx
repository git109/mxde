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
 *   File: cxtwidgetobjectinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETOBJECTINTERFACE_HXX) || defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTWIDGETOBJECTINTERFACE_HXX) && !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY)
#define _CXTWIDGETOBJECTINTERFACE_HXX
#endif /* !defined(_CXTWIDGETOBJECTINTERFACE_HXX) && !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY)
#include "cxobjectinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWidgetObjectInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/22/2010
 **********************************************************************
 */
typedef cXObjectInterface
cXtWidgetObjectInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtWidgetObjectInterface
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWidgetObjectInterface
: virtual public cXtWidgetObjectInterfaceImplement
{
public:
    typedef cXtWidgetObjectInterfaceImplement cImplements;
#else /* !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXTWIDGETOBJECTIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtWidgetObjectImplement
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWidgetObjectImplement
: virtual public cXtWidgetObjectInterface
{
public:
    typedef cXtWidgetObjectInterface cImplements;
#else /* !defined(CXTWIDGETOBJECTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETOBJECTIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTWIDGETOBJECTIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXTWIDGETOBJECTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETOBJECTIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETOBJECTINTERFACE_HXX) || defined(CXTWIDGETOBJECTINTERFACE_MEMBERS_ONLY) */
