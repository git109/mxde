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
 *   File: cxfontattached.hxx
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
#if !defined(_CXFONTATTACHED_HXX) || defined(CXFONTATTACHED_MEMBERS_ONLY)
#if !defined(_CXFONTATTACHED_HXX) && !defined(CXFONTATTACHED_MEMBERS_ONLY)
#define _CXFONTATTACHED_HXX
#endif /* !defined(_CXFONTATTACHED_HXX) && !defined(CXFONTATTACHED_MEMBERS_ONLY) */

#if !defined(CXFONTATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "cloaded.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXFontAttachedImplementBase
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXFontAttachedImplementBase;
/**
 **********************************************************************
 * Typedef: cXFontAttachedExtendBase
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cXBase
cXFontAttachedExtendBase;

class c_INTERFACE_CLASS cXFontAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXFontAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXFontAttachedInterface, 
 Font, UINT, None, cXFontAttachedImplementBase>
cXFontAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXFontAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXFontAttachedInterface
: virtual public cXFontAttachedInterfaceImplements
{
public:
    typedef cXFontAttachedInterfaceImplements cImplements;
    typedef cXFontAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXFontAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXFontAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXFontAttachedImplement, 
 cXFontAttachedInterface, 
 Font, UINT, None>
cXFontAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXFontAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXFontAttachedImplement
: virtual public cXFontAttachedImplementImplements
{
public:
    typedef cXFontAttachedImplementImplements cImplements;
    typedef cXFontAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXFontAttached;
/**
 **********************************************************************
 * Typedef: cXFontAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cAttachedT
<cXFontAttached, 
 cXFontAttachedImplement, 
 cXFontAttachedInterface,
 Font, UINT, None, cXFontAttachedExtendBase>
cXFontAttachedExtends;
/**
 **********************************************************************
 *  Class: cXFontAttached
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXFontAttached
: public cXFontAttachedExtends
{
public:
    typedef cXFontAttachedExtends cExtends;
    typedef cXFontAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXFontAttached
     *
     *      Author: $author$           
     *        Date: 6/14/2010
     **********************************************************************
     */
    cXFontAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXFontLoadedInterface;
/**
 **********************************************************************
 * Typedef: cXFontLoadedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cLoadedInterfaceT
<cXFontLoadedInterface, cXFontAttachedInterface>
cXFontLoadedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXFontLoadedInterface
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXFontLoadedInterface
: virtual public cXFontLoadedInterfaceImplements
{
public:
    typedef cXFontLoadedInterfaceImplements cImplements;
    typedef cXFontLoadedInterface cDerives;
};
class c_EXPORT_CLASS cXFontLoadedImplement;
/**
 **********************************************************************
 * Typedef: cXFontLoadedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cLoadedImplementT
<cXFontLoadedImplement, cXFontLoadedInterface>
cXFontLoadedImplementImplements;
/**
 **********************************************************************
 *  Class: cXFontLoadedImplement
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXFontLoadedImplement
: virtual public cXFontLoadedImplementImplements
{
public:
    typedef cXFontLoadedImplementImplements cImplements;
    typedef cXFontLoadedImplement cDerives;
};
class c_EXPORT_CLASS cXFontLoaded;
/**
 **********************************************************************
 * Typedef: cXFontLoadedExtends
 *
 *  Author: $author$           
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cLoadedT
<cXFontLoaded, 
 cXFontLoadedImplement, 
 cXFontAttached>
cXFontLoadedExtends;
/**
 **********************************************************************
 *  Class: cXFontLoaded
 *
 * Author: $author$           
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXFontLoaded
: public cXFontLoadedExtends
{
public:
    typedef cXFontLoadedExtends cExtends;
    typedef cXFontLoaded cDerives;

    /**
     **********************************************************************
     * Constructor: cXFontLoaded
     *
     *      Author: $author$           
     *        Date: 6/14/2010
     **********************************************************************
     */
    cXFontLoaded
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isLoaded=false) 
    : cExtends(isLoaded)
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXFontLoaded
     *
     *     Author: $author$           
     *       Date: 6/14/2010
     **********************************************************************
     */
    virtual ~cXFontLoaded()
    {
        eError error;
        if ((error = UnLoaded()))
            throw(error);
    }
#include "cloadedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXFONTATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXFONTATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXFONTATTACHED_HXX) || defined(CXFONTATTACHED_MEMBERS_ONLY) */
