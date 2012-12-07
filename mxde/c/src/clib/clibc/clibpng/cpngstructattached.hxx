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
 *   File: cpngstructattached.hxx
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
#if !defined(_CPNGSTRUCTATTACHED_HXX) || defined(CPNGSTRUCTATTACHED_MEMBERS_ONLY)
#if !defined(_CPNGSTRUCTATTACHED_HXX) && !defined(CPNGSTRUCTATTACHED_MEMBERS_ONLY)
#define _CPNGSTRUCTATTACHED_HXX
#endif /* !defined(_CPNGSTRUCTATTACHED_HXX) && !defined(CPNGSTRUCTATTACHED_MEMBERS_ONLY) */

#include "cpngbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngStructAttachedInterface;
/**
 **********************************************************************
 * Typedef: cPngStructAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/11/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cPngStructAttachedInterface, 
 png_structp, UINT, NULL, cPngInterfaceBase>
cPngStructAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngStructAttachedInterface
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngStructAttachedInterface
: virtual public cPngStructAttachedInterfaceImplements
{
public:
    typedef cPngStructAttachedInterfaceImplements cImplements;
    typedef cPngStructAttachedInterface cDerives;
};
class c_EXPORT_CLASS cPngStructAttachedImplement;
/**
 **********************************************************************
 * Typedef: cPngStructAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 6/11/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cPngStructAttachedImplement, 
 cPngStructAttachedInterface, 
 png_structp, UINT, NULL>
cPngStructAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngStructAttachedImplement
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngStructAttachedImplement
: virtual public cPngStructAttachedImplementImplements
{
public:
    typedef cPngStructAttachedImplementImplements cImplements;
    typedef cPngStructAttachedImplement cDerives;
};
class c_EXPORT_CLASS cPngStructAttached;
/**
 **********************************************************************
 * Typedef: cPngStructAttachedExtends
 *
 *  Author: $author$
 *    Date: 6/11/2009
 **********************************************************************
 */
typedef cAttachedT
<cPngStructAttached, 
 cPngStructAttachedImplement, 
 cPngStructAttachedInterface,
 png_structp, UINT, NULL, cPngBase>
cPngStructAttachedExtends;
/**
 **********************************************************************
 *  Class: cPngStructAttached
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngStructAttached
: public cPngStructAttachedExtends
{
public:
    typedef cPngStructAttachedExtends cExtends;
    typedef cPngStructAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cPngStructAttached
     *
     *      Author: $author$
     *        Date: 6/11/2009
     **********************************************************************
     */
    cPngStructAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* !defined(_CPNGSTRUCTATTACHED_HXX) || defined(CPNGSTRUCTATTACHED_MEMBERS_ONLY) */
