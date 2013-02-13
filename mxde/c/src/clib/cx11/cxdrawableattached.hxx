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
 *   File: cxdrawableattached.hxx
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
#if !defined(_CXDRAWABLEATTACHED_HXX) || defined(CXDRAWABLEATTACHED_MEMBERS_ONLY)
#if !defined(_CXDRAWABLEATTACHED_HXX) && !defined(CXDRAWABLEATTACHED_MEMBERS_ONLY)
#define _CXDRAWABLEATTACHED_HXX
#endif /* !defined(_CXDRAWABLEATTACHED_HXX) && !defined(CXDRAWABLEATTACHED_MEMBERS_ONLY) */

#if !defined(CXDRAWABLEATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cXDrawableAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXDrawableAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXDrawableAttachedInterface, 
 Drawable, UINT, NULL, cXBaseInterface>
cXDrawableAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXDrawableAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXDrawableAttachedInterface
: virtual public cXDrawableAttachedInterfaceImplements
{
public:
    typedef cXDrawableAttachedInterfaceImplements cImplements;
    typedef cXDrawableAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXDrawableAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXDrawableAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXDrawableAttachedImplement, 
 cXDrawableAttachedInterface, 
 Drawable, UINT, NULL>
cXDrawableAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXDrawableAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXDrawableAttachedImplement
: virtual public cXDrawableAttachedImplementImplements
{
public:
    typedef cXDrawableAttachedImplementImplements cImplements;
    typedef cXDrawableAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXDrawableAttached;
/**
 **********************************************************************
 * Typedef: cXDrawableAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedT
<cXDrawableAttached, 
 cXDrawableAttachedImplement, 
 cXDrawableAttachedInterface,
 Drawable, UINT, NULL, cXBase>
cXDrawableAttachedExtends;
/**
 **********************************************************************
 *  Class: cXDrawableAttached
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXDrawableAttached
: public cXDrawableAttachedExtends
{
public:
    typedef cXDrawableAttachedExtends cExtends;
    typedef cXDrawableAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXDrawableAttached
     *
     *      Author: $author$           
     *        Date: 6/29/2009
     **********************************************************************
     */
    cXDrawableAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXDRAWABLEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXDRAWABLEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXDRAWABLEATTACHED_HXX) || defined(CXDRAWABLEATTACHED_MEMBERS_ONLY) */
