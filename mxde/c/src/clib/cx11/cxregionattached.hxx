/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$     
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
 *   File: cxregionattached.hxx
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
#if !defined(_CXREGIONATTACHED_HXX) || defined(CXREGIONATTACHED_MEMBERS_ONLY)
#if !defined(_CXREGIONATTACHED_HXX) && !defined(CXREGIONATTACHED_MEMBERS_ONLY)
#define _CXREGIONATTACHED_HXX
#endif /* !defined(_CXREGIONATTACHED_HXX) && !defined(CXREGIONATTACHED_MEMBERS_ONLY) */

#if !defined(CXREGIONATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXRegionAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXRegionAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXRegionAttachedInterface, 
 Region, UINT, NULL, cXBaseInterface>
cXRegionAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXRegionAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXRegionAttachedInterface
: virtual public cXRegionAttachedInterfaceImplements
{
public:
    typedef cXRegionAttachedInterfaceImplements cImplements;
    typedef cXRegionAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXRegionAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXRegionAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXRegionAttachedImplement, 
 cXRegionAttachedInterface, 
 Region, UINT, NULL>
cXRegionAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXRegionAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXRegionAttachedImplement
: virtual public cXRegionAttachedImplementImplements
{
public:
    typedef cXRegionAttachedImplementImplements cImplements;
    typedef cXRegionAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXRegionAttached;
/**
 **********************************************************************
 * Typedef: cXRegionAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedT
<cXRegionAttached, 
 cXRegionAttachedImplement, 
 cXRegionAttachedInterface,
 Region, UINT, NULL, cXBase>
cXRegionAttachedExtends;
/**
 **********************************************************************
 *  Class: cXRegionAttached
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXRegionAttached
: public cXRegionAttachedExtends
{
public:
    typedef cXRegionAttachedExtends cExtends;
    typedef cXRegionAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXRegionAttached
     *
     *      Author: $author$           
     *        Date: 6/29/2009
     **********************************************************************
     */
    cXRegionAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXRegionCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXRegionCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXRegionCreatedInterface, cXRegionAttachedInterface>
cXRegionCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXRegionCreatedInterface
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXRegionCreatedInterface
: virtual public cXRegionCreatedInterfaceImplements
{
public:
    typedef cXRegionCreatedInterfaceImplements cImplements;
    typedef cXRegionCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXRegionCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXRegionCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cXRegionCreatedImplement, cXRegionCreatedInterface>
cXRegionCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXRegionCreatedImplement
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXRegionCreatedImplement
: virtual public cXRegionCreatedImplementImplements
{
public:
    typedef cXRegionCreatedImplementImplements cImplements;
    typedef cXRegionCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXRegionCreated;
/**
 **********************************************************************
 * Typedef: cXRegionCreatedExtends
 *
 *  Author: $author$           
 *    Date: 7/5/2009
 **********************************************************************
 */
typedef cCreatedT
<cXRegionCreated, 
 cXRegionCreatedImplement, 
 cXRegionAttached>
cXRegionCreatedExtends;
/**
 **********************************************************************
 *  Class: cXRegionCreated
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXRegionCreated
: public cXRegionCreatedExtends
{
public:
    typedef cXRegionCreatedExtends cExtends;
    typedef cXRegionCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXRegionCreated
     *
     *      Author: $author$           
     *        Date: 7/5/2009
     **********************************************************************
     */
    cXRegionCreated
    (Region attached=0,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXRegionCreated
     *
     *     Author: $author$           
     *       Date: 7/5/2009
     **********************************************************************
     */
    virtual ~cXRegionCreated()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("()\n throwing error=%d\n", (int)(error)));
            throw (error);
        }
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXREGIONATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXREGIONATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXREGIONATTACHED_HXX) || defined(CXREGIONATTACHED_MEMBERS_ONLY) */
