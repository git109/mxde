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
 *   File: cxtwidgetattached.hxx
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
#if !defined(_CXTWIDGETATTACHED_HXX) || defined(CXTWIDGETATTACHED_MEMBERS_ONLY)
#if !defined(_CXTWIDGETATTACHED_HXX) && !defined(CXTWIDGETATTACHED_MEMBERS_ONLY)
#define _CXTWIDGETATTACHED_HXX
#endif /* !defined(_CXTWIDGETATTACHED_HXX) && !defined(CXTWIDGETATTACHED_MEMBERS_ONLY) */

#if !defined(CXTWIDGETATTACHED_MEMBERS_ONLY)
#include "cplatform_X11_Shell.h"
#include "cplatform_X11_Intrinsic.h"
#include "ccreated.hxx"
#include "cattached.hxx"
#include "cxobject.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtWidgetAttachedExtendInterface
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cXObjectInterface
cXtWidgetAttachedExtendInterface;
/**
 **********************************************************************
 * Typedef: cXtWidgetAttachedExtendImplement
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cXObjectImplement
cXtWidgetAttachedExtendImplement;
/**
 **********************************************************************
 * Typedef: cXtWidgetAttachedExtend
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cXBase
cXtWidgetAttachedExtend;

class c_INTERFACE_CLASS cXtWidgetAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXtWidgetAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXtWidgetAttachedInterface, 
 Widget, UINT, NULL, cXtWidgetAttachedExtendImplement>
cXtWidgetAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXtWidgetAttachedInterface
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtWidgetAttachedInterface
: virtual public cXtWidgetAttachedInterfaceImplements
{
public:
    typedef cXtWidgetAttachedInterfaceImplements cImplements;
    typedef cXtWidgetAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXtWidgetAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXtWidgetAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXtWidgetAttachedImplement, 
 cXtWidgetAttachedInterface, 
 Widget, UINT, None>
cXtWidgetAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXtWidgetAttachedImplement
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtWidgetAttachedImplement
: virtual public cXtWidgetAttachedExtendImplement,
  virtual public cXtWidgetAttachedImplementImplements
{
public:
    typedef cXtWidgetAttachedImplementImplements cImplements;
    typedef cXtWidgetAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXtWidgetAttached;
/**
 **********************************************************************
 * Typedef: cXtWidgetAttachedExtends
 *
 *  Author: $author$           
 *    Date: 4/26/2010
 **********************************************************************
 */
typedef cAttachedT
<cXtWidgetAttached, 
 cXtWidgetAttachedImplement, 
 cXtWidgetAttachedInterface,
 Widget, UINT, None, cXtWidgetAttachedExtend>
cXtWidgetAttachedExtends;
/**
 **********************************************************************
 *  Class: cXtWidgetAttached
 *
 * Author: $author$           
 *   Date: 4/26/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtWidgetAttached
: public cXtWidgetAttachedExtends
{
public:
    typedef cXtWidgetAttachedExtends cExtends;
    typedef cXtWidgetAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXtWidgetAttached
     *
     *      Author: $author$           
     *        Date: 4/26/2010
     **********************************************************************
     */
    cXtWidgetAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

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

#else /* !defined(CXTWIDGETATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXTWIDGETATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXTWIDGETATTACHED_HXX) || defined(CXTWIDGETATTACHED_MEMBERS_ONLY) */
