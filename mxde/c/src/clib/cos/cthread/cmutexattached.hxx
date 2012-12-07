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
 *   File: cmutexattached.hxx
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
#if !defined(_CMUTEXATTACHED_HXX) || defined(CMUTEXATTACHED_MEMBERS_ONLY)
#if !defined(_CMUTEXATTACHED_HXX) && !defined(CMUTEXATTACHED_MEMBERS_ONLY)
#define _CMUTEXATTACHED_HXX
#endif /* !defined(_CMUTEXATTACHED_HXX) && !defined(CMUTEXATTACHED_MEMBERS_ONLY) */

#if !defined(CMUTEXATTACHED_MEMBERS_ONLY)
#include "cplatform_mutex.h"
#include "cattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cMUTEXAttachedInterface;
/**
 **********************************************************************
 * Typedef: cMUTEXAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cMUTEXAttachedInterface, 
 MUTEX, UINT, NULL, cInterfaceBase>
cMUTEXAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cMUTEXAttachedInterface
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cMUTEXAttachedInterface
: virtual public cMUTEXAttachedInterfaceImplements
{
public:
    typedef cMUTEXAttachedInterfaceImplements cImplements;
    typedef cMUTEXAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cMUTEXAttachedImplement;
/**
 **********************************************************************
 * Typedef: cMUTEXAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cMUTEXAttachedImplement, 
 cMUTEXAttachedInterface, 
 MUTEX, UINT, NULL>
cMUTEXAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cMUTEXAttachedImplement
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cMUTEXAttachedImplement
: virtual public cMUTEXAttachedImplementImplements
{
public:
    typedef cMUTEXAttachedImplementImplements cImplements;
    typedef cMUTEXAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cMUTEXAttached;
/**
 **********************************************************************
 * Typedef: cMUTEXAttachedExtends
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cAttachedT
<cMUTEXAttached, 
 cMUTEXAttachedImplement, 
 cMUTEXAttachedInterface,
 MUTEX, UINT, NULL, cBase>
cMUTEXAttachedExtends;
/**
 **********************************************************************
 *  Class: cMUTEXAttached
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cMUTEXAttached
: public cMUTEXAttachedExtends
{
public:
    typedef cMUTEXAttachedExtends cExtends;
    typedef cMUTEXAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cMUTEXAttached
     *
     *      Author: $author$
     *        Date: 10/31/2010
     **********************************************************************
     */
    cMUTEXAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cMUTEXCreatedInterface;
/**
 **********************************************************************
 * Typedef: cMUTEXCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cMUTEXCreatedInterface, cMUTEXAttachedInterface>
cMUTEXCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cMUTEXCreatedInterface
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cMUTEXCreatedInterface
: virtual public cMUTEXCreatedInterfaceImplements
{
public:
    typedef cMUTEXCreatedInterfaceImplements cImplements;
    typedef cMUTEXCreatedInterface cDerives;
};
class c_EXPORT_CLASS cMUTEXCreatedImplement;
/**
 **********************************************************************
 * Typedef: cMUTEXCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cMUTEXCreatedImplement, cMUTEXCreatedInterface>
cMUTEXCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cMUTEXCreatedImplement
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cMUTEXCreatedImplement
: virtual public cMUTEXCreatedImplementImplements
{
public:
    typedef cMUTEXCreatedImplementImplements cImplements;
    typedef cMUTEXCreatedImplement cDerives;
};
class c_EXPORT_CLASS cMUTEXCreated;
/**
 **********************************************************************
 * Typedef: cMUTEXCreatedExtends
 *
 *  Author: $author$
 *    Date: 10/31/2010
 **********************************************************************
 */
typedef cCreatedT
<cMUTEXCreated, 
 cMUTEXCreatedImplement, 
 cMUTEXAttached>
cMUTEXCreatedExtends;
/**
 **********************************************************************
 *  Class: cMUTEXCreated
 *
 * Author: $author$
 *   Date: 10/31/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cMUTEXCreated
: public cMUTEXCreatedExtends
{
public:
    typedef cMUTEXCreatedExtends cExtends;
    typedef cMUTEXCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cMUTEXCreated
     *
     *      Author: $author$
     *        Date: 10/31/2010
     **********************************************************************
     */
    cMUTEXCreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cMUTEXCreated
     *
     *     Author: $author$
     *       Date: 10/31/2010
     **********************************************************************
     */
    virtual ~cMUTEXCreated()
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

#else /* !defined(CMUTEXATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CMUTEXATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CMUTEXATTACHED_HXX) || defined(CMUTEXATTACHED_MEMBERS_ONLY) */
