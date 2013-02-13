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
 *   File: cxtwidgetcreated.hxx
 *
 * Author: $author$           
 *   Date: 6/22/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETCREATED_HXX) || defined(CXTWIDGETCREATED_MEMBERS_ONLY)
#if !defined(_CXTWIDGETCREATED_HXX) && !defined(CXTWIDGETCREATED_MEMBERS_ONLY)
#define _CXTWIDGETCREATED_HXX
#endif /* !defined(_CXTWIDGETCREATED_HXX) && !defined(CXTWIDGETCREATED_MEMBERS_ONLY) */

#if !defined(CXTWIDGETCREATED_MEMBERS_ONLY)
#include "cxtwidgetattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXtWidgetCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXtWidgetCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXtWidgetCreatedInterface, cXtWidgetAttachedInterface>
cXtWidgetCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXtWidgetCreatedInterface
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWidgetCreatedInterface
: virtual public cXtWidgetCreatedInterfaceImplements
{
public:
    typedef cXtWidgetCreatedInterfaceImplements cImplements;
    typedef cXtWidgetCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXtWidgetCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXtWidgetCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXtWidgetCreatedImplement, cXtWidgetCreatedInterface>
cXtWidgetCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXtWidgetCreatedImplement
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXtWidgetCreatedImplement
: virtual public cXtWidgetCreatedImplementImplements
{
public:
    typedef cXtWidgetCreatedImplementImplements cImplements;
    typedef cXtWidgetCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXtWidgetCreated;
/**
 **********************************************************************
 * Typedef: cXtWidgetCreatedExtends
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cCreatedT
<cXtWidgetCreated, 
 cXtWidgetCreatedImplement, 
 cXtWidgetAttached>
cXtWidgetCreatedExtends;
/**
 **********************************************************************
 *  Class: cXtWidgetCreated
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXtWidgetCreated
: public cXtWidgetCreatedExtends
{
public:
    typedef cXtWidgetCreatedExtends cExtends;
    typedef cXtWidgetCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXtWidgetCreated
     *
     *      Author: $author$           
     *        Date: 4/26/2010
     **********************************************************************
     */
    cXtWidgetCreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXtWidgetCreated
     *
     *     Author: $author$           
     *       Date: 4/26/2010
     **********************************************************************
     */
    virtual ~cXtWidgetCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTWIDGETCREATED_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETCREATED_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETCREATED_HXX) || defined(CXTWIDGETCREATED_MEMBERS_ONLY) */
