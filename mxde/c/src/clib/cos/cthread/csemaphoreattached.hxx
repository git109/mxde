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
 *   File: csemaphoreattached.hxx
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
#if !defined(_CSEMAPHOREATTACHED_HXX) || defined(CSEMAPHOREATTACHED_MEMBERS_ONLY)
#if !defined(_CSEMAPHOREATTACHED_HXX) && !defined(CSEMAPHOREATTACHED_MEMBERS_ONLY)
#define _CSEMAPHOREATTACHED_HXX
#endif /* !defined(_CSEMAPHOREATTACHED_HXX) && !defined(CSEMAPHOREATTACHED_MEMBERS_ONLY) */

#if !defined(CSEMAPHOREATTACHED_MEMBERS_ONLY)
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cplatform_semaphore.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cSEMAPHOREAttachedInterface;
/**
 **********************************************************************
 * Typedef: cSEMAPHOREAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cSEMAPHOREAttachedInterface, 
 SEMAPHORE, UINT, NULL, cInterfaceBase>
cSEMAPHOREAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cSEMAPHOREAttachedInterface
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cSEMAPHOREAttachedInterface
: virtual public cSEMAPHOREAttachedInterfaceImplements
{
public:
    typedef cSEMAPHOREAttachedInterfaceImplements cImplements;
    typedef cSEMAPHOREAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cSEMAPHOREAttachedImplement;
/**
 **********************************************************************
 * Typedef: cSEMAPHOREAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cSEMAPHOREAttachedImplement, 
 cSEMAPHOREAttachedInterface, 
 SEMAPHORE, UINT, NULL>
cSEMAPHOREAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cSEMAPHOREAttachedImplement
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cSEMAPHOREAttachedImplement
: virtual public cSEMAPHOREAttachedImplementImplements
{
public:
    typedef cSEMAPHOREAttachedImplementImplements cImplements;
    typedef cSEMAPHOREAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cSEMAPHOREAttached;
/**
 **********************************************************************
 * Typedef: cSEMAPHOREAttachedExtends
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cAttachedT
<cSEMAPHOREAttached, 
 cSEMAPHOREAttachedImplement, 
 cSEMAPHOREAttachedInterface,
 SEMAPHORE, UINT, NULL, cBase>
cSEMAPHOREAttachedExtends;
/**
 **********************************************************************
 *  Class: cSEMAPHOREAttached
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cSEMAPHOREAttached
: public cSEMAPHOREAttachedExtends
{
public:
    typedef cSEMAPHOREAttachedExtends cExtends;
    typedef cSEMAPHOREAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cSEMAPHOREAttached
     *
     *      Author: $author$
     *        Date: 10/24/2010
     **********************************************************************
     */
    cSEMAPHOREAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cSEMAPHORECreatedInterface;
/**
 **********************************************************************
 * Typedef: cSEMAPHORECreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cSEMAPHORECreatedInterface, cSEMAPHOREAttachedInterface>
cSEMAPHORECreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cSEMAPHORECreatedInterface
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cSEMAPHORECreatedInterface
: virtual public cSEMAPHORECreatedInterfaceImplements
{
public:
    typedef cSEMAPHORECreatedInterfaceImplements cImplements;
    typedef cSEMAPHORECreatedInterface cDerives;
};
class c_EXPORT_CLASS cSEMAPHORECreatedImplement;
/**
 **********************************************************************
 * Typedef: cSEMAPHORECreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cSEMAPHORECreatedImplement, cSEMAPHORECreatedInterface>
cSEMAPHORECreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cSEMAPHORECreatedImplement
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cSEMAPHORECreatedImplement
: virtual public cSEMAPHORECreatedImplementImplements
{
public:
    typedef cSEMAPHORECreatedImplementImplements cImplements;
    typedef cSEMAPHORECreatedImplement cDerives;
};
class c_EXPORT_CLASS cSEMAPHORECreated;
/**
 **********************************************************************
 * Typedef: cSEMAPHORECreatedExtends
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cCreatedT
<cSEMAPHORECreated, 
 cSEMAPHORECreatedImplement, 
 cSEMAPHOREAttached>
cSEMAPHORECreatedExtends;
/**
 **********************************************************************
 *  Class: cSEMAPHORECreated
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cSEMAPHORECreated
: public cSEMAPHORECreatedExtends
{
public:
    typedef cSEMAPHORECreatedExtends cExtends;
    typedef cSEMAPHORECreated cDerives;

    /**
     **********************************************************************
     * Constructor: cSEMAPHORECreated
     *
     *      Author: $author$
     *        Date: 10/24/2010
     **********************************************************************
     */
    cSEMAPHORECreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cSEMAPHORECreated
     *
     *     Author: $author$
     *       Date: 10/24/2010
     **********************************************************************
     */
    virtual ~cSEMAPHORECreated()
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

#else /* !defined(CSEMAPHOREATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHOREATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CSEMAPHOREATTACHED_HXX) || defined(CSEMAPHOREATTACHED_MEMBERS_ONLY) */
