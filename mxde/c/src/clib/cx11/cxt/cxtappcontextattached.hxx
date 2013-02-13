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
 *   File: cxtappcontextattached.hxx
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
#if !defined(_CXTAPPCONTEXTATTACHED_HXX) || defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY)
#if !defined(_CXTAPPCONTEXTATTACHED_HXX) && !defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY)
#define _CXTAPPCONTEXTATTACHED_HXX
#endif /* !defined(_CXTAPPCONTEXTATTACHED_HXX) && !defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY) */

#if !defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY)
#include "cplatform_X11_Intrinsic.h"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXtAppContextAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXtAppContextAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXtAppContextAttachedInterface, 
 XtAppContext, UINT, NULL, cXBaseInterface>
cXtAppContextAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXtAppContextAttachedInterface
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtAppContextAttachedInterface
: virtual public cXtAppContextAttachedInterfaceImplements
{
public:
    typedef cXtAppContextAttachedInterfaceImplements cImplements;
    typedef cXtAppContextAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXtAppContextAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXtAppContextAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXtAppContextAttachedImplement, 
 cXtAppContextAttachedInterface, 
 XtAppContext, UINT, NULL>
cXtAppContextAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXtAppContextAttachedImplement
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtAppContextAttachedImplement
: virtual public cXtAppContextAttachedImplementImplements
{
public:
    typedef cXtAppContextAttachedImplementImplements cImplements;
    typedef cXtAppContextAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXtAppContextAttached;
/**
 **********************************************************************
 * Typedef: cXtAppContextAttachedExtends
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cAttachedT
<cXtAppContextAttached, 
 cXtAppContextAttachedImplement, 
 cXtAppContextAttachedInterface,
 XtAppContext, UINT, NULL, cXBase>
cXtAppContextAttachedExtends;
/**
 **********************************************************************
 *  Class: cXtAppContextAttached
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtAppContextAttached
: public cXtAppContextAttachedExtends
{
public:
    typedef cXtAppContextAttachedExtends cExtends;
    typedef cXtAppContextAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXtAppContextAttached
     *
     *      Author: $author$           
     *        Date: 4/22/2010
     **********************************************************************
     */
    cXtAppContextAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXtAppContextCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXtAppContextCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXtAppContextCreatedInterface, cXtAppContextAttachedInterface>
cXtAppContextCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXtAppContextCreatedInterface
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtAppContextCreatedInterface
: virtual public cXtAppContextCreatedInterfaceImplements
{
public:
    typedef cXtAppContextCreatedInterfaceImplements cImplements;
    typedef cXtAppContextCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXtAppContextCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXtAppContextCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXtAppContextCreatedImplement, cXtAppContextCreatedInterface>
cXtAppContextCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXtAppContextCreatedImplement
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXtAppContextCreatedImplement
: virtual public cXtAppContextCreatedImplementImplements
{
public:
    typedef cXtAppContextCreatedImplementImplements cImplements;
    typedef cXtAppContextCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXtAppContextCreated;
/**
 **********************************************************************
 * Typedef: cXtAppContextCreatedExtends
 *
 *  Author: $author$           
 *    Date: 4/22/2010
 **********************************************************************
 */
typedef cCreatedT
<cXtAppContextCreated, 
 cXtAppContextCreatedImplement, 
 cXtAppContextAttached>
cXtAppContextCreatedExtends;
/**
 **********************************************************************
 *  Class: cXtAppContextCreated
 *
 * Author: $author$           
 *   Date: 4/22/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXtAppContextCreated
: public cXtAppContextCreatedExtends
{
public:
    typedef cXtAppContextCreatedExtends cExtends;
    typedef cXtAppContextCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXtAppContextCreated
     *
     *      Author: $author$           
     *        Date: 4/22/2010
     **********************************************************************
     */
    cXtAppContextCreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXtAppContextCreated
     *
     *     Author: $author$           
     *       Date: 4/22/2010
     **********************************************************************
     */
    virtual ~cXtAppContextCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXTAPPCONTEXTATTACHED_HXX) || defined(CXTAPPCONTEXTATTACHED_MEMBERS_ONLY) */
