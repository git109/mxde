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
 *   File: cxatomattached.hxx
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
#if !defined(_CXATOMATTACHED_HXX) || defined(CXATOMATTACHED_MEMBERS_ONLY)
#if !defined(_CXATOMATTACHED_HXX) && !defined(CXATOMATTACHED_MEMBERS_ONLY)
#define _CXATOMATTACHED_HXX
#endif /* !defined(_CXATOMATTACHED_HXX) && !defined(CXATOMATTACHED_MEMBERS_ONLY) */

#if !defined(CXATOMATTACHED_MEMBERS_ONLY)
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cxdisplayinterface.hxx"
#include "cxdisplayattached.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXAtomAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXAtomAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXAtomAttachedInterface, 
 Atom, UINT, NULL, cXBaseInterface>
cXAtomAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXAtomAttachedInterface
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXAtomAttachedInterface
: virtual public cXAtomAttachedInterfaceImplements
{
public:
    typedef cXAtomAttachedInterfaceImplements cImplements;
    typedef cXAtomAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXAtomAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXAtomAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXAtomAttachedImplement, 
 cXAtomAttachedInterface, 
 Atom, UINT, NULL>
cXAtomAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXAtomAttachedImplement
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXAtomAttachedImplement
: virtual public cXAtomAttachedImplementImplements
{
public:
    typedef cXAtomAttachedImplementImplements cImplements;
    typedef cXAtomAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXAtomAttached;
/**
 **********************************************************************
 * Typedef: cXAtomAttachedExtends
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cAttachedT
<cXAtomAttached, 
 cXAtomAttachedImplement, 
 cXAtomAttachedInterface,
 Atom, UINT, NULL, cXBase>
cXAtomAttachedExtends;
/**
 **********************************************************************
 *  Class: cXAtomAttached
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXAtomAttached
: public cXAtomAttachedExtends
{
public:
    typedef cXAtomAttachedExtends cExtends;
    typedef cXAtomAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXAtomAttached
     *
     *      Author: $author$           
     *        Date: 4/14/2010
     **********************************************************************
     */
    cXAtomAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXAtomCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXAtomCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXAtomCreatedInterface, cXAtomAttachedInterface>
cXAtomCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXAtomCreatedInterface
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXAtomCreatedInterface
: virtual public cXAtomCreatedInterfaceImplements
{
public:
    typedef cXAtomCreatedInterfaceImplements cImplements;
    typedef cXAtomCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXAtomCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXAtomCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXAtomCreatedImplement, cXAtomCreatedInterface>
cXAtomCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXAtomCreatedImplement
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXAtomCreatedImplement
: virtual public cXAtomCreatedImplementImplements
{
public:
    typedef cXAtomCreatedImplementImplements cImplements;
    typedef cXAtomCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXAtomCreated;
/**
 **********************************************************************
 * Typedef: cXAtomCreatedExtends
 *
 *  Author: $author$           
 *    Date: 4/14/2010
 **********************************************************************
 */
typedef cCreatedT
<cXAtomCreated, 
 cXAtomCreatedImplement, 
 cXAtomAttached>
cXAtomCreatedExtends;
/**
 **********************************************************************
 *  Class: cXAtomCreated
 *
 * Author: $author$           
 *   Date: 4/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXAtomCreated
: public cXAtomCreatedExtends
{
public:
    typedef cXAtomCreatedExtends cExtends;
    typedef cXAtomCreated cDerives;

    cXDisplayAttached m_display;

    /**
     **********************************************************************
     * Constructor: cXAtomCreated
     *
     *      Author: $author$           
     *        Date: 4/14/2010
     **********************************************************************
     */
    cXAtomCreated
    (Display* xDisplay = 0,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated),
      m_display(xDisplay)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXAtomCreated
     *
     *     Author: $author$           
     *       Date: 4/14/2010
     **********************************************************************
     */
    virtual ~cXAtomCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXATOMATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXATOMATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXATOMATTACHED_HXX) || defined(CXATOMATTACHED_MEMBERS_ONLY) */
