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
 *   File: cxtwidgetclassattached.hxx
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETCLASSATTACHED_HXX) || defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY)
#if !defined(_CXTWIDGETCLASSATTACHED_HXX) && !defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY)
#define _CXTWIDGETCLASSATTACHED_HXX
#endif /* !defined(_CXTWIDGETCLASSATTACHED_HXX) && !defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY)
#include "cxtbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXtWidgetClassAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXtWidgetClassAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXtWidgetClassAttachedInterface, 
 WidgetClass, UINT, NULL, cXtBaseInterface>
cXtWidgetClassAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXtWidgetClassAttachedInterface
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWidgetClassAttachedInterface
: virtual public cXtWidgetClassAttachedInterfaceImplements
{
public:
    typedef cXtWidgetClassAttachedInterfaceImplements cImplements;
    typedef cXtWidgetClassAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXtWidgetClassAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXtWidgetClassAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXtWidgetClassAttachedImplement, 
 cXtWidgetClassAttachedInterface, 
 WidgetClass, UINT, NULL>
cXtWidgetClassAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXtWidgetClassAttachedImplement
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWidgetClassAttachedImplement
: virtual public cXtWidgetClassAttachedImplementImplements
{
public:
    typedef cXtWidgetClassAttachedImplementImplements cImplements;
    typedef cXtWidgetClassAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXtWidgetClassAttached;
/**
 **********************************************************************
 * Typedef: cXtWidgetClassAttachedExtends
 *
 *  Author: $author$           
 *    Date: 5/1/2010
 **********************************************************************
 */
typedef cAttachedT
<cXtWidgetClassAttached, 
 cXtWidgetClassAttachedImplement, 
 cXtWidgetClassAttachedInterface,
 WidgetClass, UINT, NULL, cXtBase>
cXtWidgetClassAttachedExtends;
/**
 **********************************************************************
 *  Class: cXtWidgetClassAttached
 *
 * Author: $author$           
 *   Date: 5/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWidgetClassAttached
: public cXtWidgetClassAttachedExtends
{
public:
    typedef cXtWidgetClassAttachedExtends cExtends;
    typedef cXtWidgetClassAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXtWidgetClassAttached
     *
     *      Author: $author$           
     *        Date: 5/1/2010
     **********************************************************************
     */
    cXtWidgetClassAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETCLASSATTACHED_HXX) || defined(CXTWIDGETCLASSATTACHED_MEMBERS_ONLY) */
