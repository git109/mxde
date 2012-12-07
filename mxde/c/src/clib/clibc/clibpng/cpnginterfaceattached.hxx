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
 *   File: cpnginterfaceattached.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGINTERFACEATTACHED_HXX) || defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY)
#if !defined(_CPNGINTERFACEATTACHED_HXX) && !defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY)
#define _CPNGINTERFACEATTACHED_HXX
#endif /* !defined(_CPNGINTERFACEATTACHED_HXX) && !defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY) */

#if !defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY)
#include "cpnginterface.hxx"
#include "cattached.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngInterfaceAttachedInterface;
/**
 **********************************************************************
 * Typedef: cPngInterfaceAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cPngInterfaceAttachedInterface, 
 cPngInterface*, UINT, NULL, cInterfaceBase>
cPngInterfaceAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInterfaceAttachedInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInterfaceAttachedInterface
: virtual public cPngInterfaceAttachedInterfaceImplements
{
public:
    typedef cPngInterfaceAttachedInterfaceImplements cImplements;
    typedef cPngInterfaceAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cPngInterfaceAttachedImplement;
/**
 **********************************************************************
 * Typedef: cPngInterfaceAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cPngInterfaceAttachedImplement, 
 cPngInterfaceAttachedInterface, 
 cPngInterface*, UINT, NULL>
cPngInterfaceAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInterfaceAttachedImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPngInterfaceAttachedImplement
: virtual public cPngInterfaceAttachedImplementImplements
{
public:
    typedef cPngInterfaceAttachedImplementImplements cImplements;
    typedef cPngInterfaceAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cPngInterfaceAttached;
/**
 **********************************************************************
 * Typedef: cPngInterfaceAttachedExtends
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cAttachedT
<cPngInterfaceAttached, 
 cPngInterfaceAttachedImplement, 
 cPngInterfaceAttachedInterface,
 cPngInterface*, UINT, NULL, cInstanceBase>
cPngInterfaceAttachedExtends;
/**
 **********************************************************************
 *  Class: cPngInterfaceAttached
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cPngInterfaceAttached
: public cPngInterfaceAttachedExtends
{
public:
    typedef cPngInterfaceAttachedExtends cExtends;
    typedef cPngInterfaceAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cPngInterfaceAttached
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    cPngInterfaceAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINTERFACEATTACHED_HXX) || defined(CPNGINTERFACEATTACHED_MEMBERS_ONLY) */
