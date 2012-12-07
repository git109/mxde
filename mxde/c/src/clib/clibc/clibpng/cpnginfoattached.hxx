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
 *   File: cpnginfoattached.hxx
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
#if !defined(_CPNGINFOATTACHED_HXX) || defined(CPNGINFOATTACHED_MEMBERS_ONLY)
#if !defined(_CPNGINFOATTACHED_HXX) && !defined(CPNGINFOATTACHED_MEMBERS_ONLY)
#define _CPNGINFOATTACHED_HXX
#endif /* !defined(_CPNGINFOATTACHED_HXX) && !defined(CPNGINFOATTACHED_MEMBERS_ONLY) */

#include "cattached.hxx"
#include "cpngbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngInfoAttachedInterface;
/**
 **********************************************************************
 * Typedef: cPngInfoAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cPngInfoAttachedInterface, 
 png_infop, UINT, NULL, cPngInterfaceBase>
cPngInfoAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInfoAttachedInterface
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInfoAttachedInterface
: virtual public cPngInfoAttachedInterfaceImplements
{
public:
    typedef cPngInfoAttachedInterfaceImplements cImplements;
    typedef cPngInfoAttachedInterface cDerives;
};
class c_EXPORT_CLASS cPngInfoAttachedImplement;
/**
 **********************************************************************
 * Typedef: cPngInfoAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cPngInfoAttachedImplement, 
 cPngInfoAttachedInterface, 
 png_infop, UINT, NULL>
cPngInfoAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInfoAttachedImplement
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfoAttachedImplement
: virtual public cPngInfoAttachedImplementImplements
{
public:
    typedef cPngInfoAttachedImplementImplements cImplements;
    typedef cPngInfoAttachedImplement cDerives;
};
class c_EXPORT_CLASS cPngInfoAttached;
/**
 **********************************************************************
 * Typedef: cPngInfoAttachedExtends
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cAttachedT
<cPngInfoAttached, 
 cPngInfoAttachedImplement, 
 cPngInfoAttachedInterface,
 png_infop, UINT, NULL, cPngBase>
cPngInfoAttachedExtends;
/**
 **********************************************************************
 *  Class: cPngInfoAttached
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfoAttached
: public cPngInfoAttachedExtends
{
public:
    typedef cPngInfoAttachedExtends cExtends;
    typedef cPngInfoAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cPngInfoAttached
     *
     *      Author: $author$
     *        Date: 6/10/2009
     **********************************************************************
     */
    cPngInfoAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* !defined(_CPNGINFOATTACHED_HXX) || defined(CPNGINFOATTACHED_MEMBERS_ONLY) */
