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
 *   File: cxdisplayattached.hxx
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
#if !defined(_CXDISPLAYATTACHED_HXX) || defined(CXDISPLAYATTACHED_MEMBERS_ONLY)
#if !defined(_CXDISPLAYATTACHED_HXX) && !defined(CXDISPLAYATTACHED_MEMBERS_ONLY)
#define _CXDISPLAYATTACHED_HXX
#endif /* !defined(_CXDISPLAYATTACHED_HXX) && !defined(CXDISPLAYATTACHED_MEMBERS_ONLY) */

#if !defined(CXDISPLAYATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXDisplayAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXDisplayAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/21/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXDisplayAttachedInterface, 
 Display*, UINT, NULL, cXBaseInterface>
cXDisplayAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXDisplayAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXDisplayAttachedInterface
: virtual public cXDisplayAttachedInterfaceImplements
{
public:
    typedef cXDisplayAttachedInterfaceImplements cImplements;
    typedef cXDisplayAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXDisplayAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXDisplayAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/21/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXDisplayAttachedImplement, 
 cXDisplayAttachedInterface, 
 Display*, UINT, NULL>
cXDisplayAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXDisplayAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXDisplayAttachedImplement
: virtual public cXDisplayAttachedImplementImplements
{
public:
    typedef cXDisplayAttachedImplementImplements cImplements;
    typedef cXDisplayAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXDisplayAttached;
/**
 **********************************************************************
 * Typedef: cXDisplayAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/21/2009
 **********************************************************************
 */
typedef cAttachedT
<cXDisplayAttached, 
 cXDisplayAttachedImplement, 
 cXDisplayAttachedInterface,
 Display*, UINT, NULL, cXBase>
cXDisplayAttachedExtends;
/**
 **********************************************************************
 *  Class: cXDisplayAttached
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXDisplayAttached
: public cXDisplayAttachedExtends
{
public:
    typedef cXDisplayAttachedExtends cExtends;
    typedef cXDisplayAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXDisplayAttached
     *
     *      Author: $author$           
     *        Date: 6/21/2009
     **********************************************************************
     */
    cXDisplayAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXDISPLAYATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXDISPLAYATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXDISPLAYATTACHED_HXX) || defined(CXDISPLAYATTACHED_MEMBERS_ONLY) */
