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
 *   File: cpngcolorattached.hxx
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
#if !defined(_CPNGCOLORATTACHED_HXX) || defined(CPNGCOLORATTACHED_MEMBERS_ONLY)
#if !defined(_CPNGCOLORATTACHED_HXX) && !defined(CPNGCOLORATTACHED_MEMBERS_ONLY)
#define _CPNGCOLORATTACHED_HXX
#endif /* !defined(_CPNGCOLORATTACHED_HXX) && !defined(CPNGCOLORATTACHED_MEMBERS_ONLY) */

#if !defined(CPNGCOLORATTACHED_MEMBERS_ONLY)
#include "cpnginfointerface.hxx"
#include "cpngstructinterface.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngColorAttachedInterface;
/**
 **********************************************************************
 * Typedef: cPngColorAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/14/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cPngColorAttachedInterface, 
 png_colorp, UINT, NULL, cPngInterfaceBase>
cPngColorAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngColorAttachedInterface
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngColorAttachedInterface
: virtual public cPngColorAttachedInterfaceImplements
{
public:
    typedef cPngColorAttachedInterfaceImplements cImplements;
    typedef cPngColorAttachedInterface cDerives;
};
class c_EXPORT_CLASS cPngColorAttachedImplement;
/**
 **********************************************************************
 * Typedef: cPngColorAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 6/14/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cPngColorAttachedImplement, 
 cPngColorAttachedInterface, 
 png_colorp, UINT, NULL>
cPngColorAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngColorAttachedImplement
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngColorAttachedImplement
: virtual public cPngColorAttachedImplementImplements
{
public:
    typedef cPngColorAttachedImplementImplements cImplements;
    typedef cPngColorAttachedImplement cDerives;
};
class c_EXPORT_CLASS cPngColorAttached;
/**
 **********************************************************************
 * Typedef: cPngColorAttachedExtends
 *
 *  Author: $author$
 *    Date: 6/14/2009
 **********************************************************************
 */
typedef cAttachedT
<cPngColorAttached, 
 cPngColorAttachedImplement, 
 cPngColorAttachedInterface,
 png_colorp, UINT, NULL, cPngBase>
cPngColorAttachedExtends;
/**
 **********************************************************************
 *  Class: cPngColorAttached
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngColorAttached
: public cPngColorAttachedExtends
{
public:
    typedef cPngColorAttachedExtends cExtends;
    typedef cPngColorAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cPngColorAttached
     *
     *      Author: $author$
     *        Date: 6/14/2009
     **********************************************************************
     */
    cPngColorAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGCOLORATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CPNGCOLORATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CPNGCOLORATTACHED_HXX) || defined(CPNGCOLORATTACHED_MEMBERS_ONLY) */
