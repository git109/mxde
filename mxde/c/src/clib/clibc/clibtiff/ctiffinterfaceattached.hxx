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
 *   File: ctiffinterfaceattached.hxx
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
#if !defined(_CTIFFINTERFACEATTACHED_HXX) || defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY)
#if !defined(_CTIFFINTERFACEATTACHED_HXX) && !defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY)
#define _CTIFFINTERFACEATTACHED_HXX
#endif /* !defined(_CTIFFINTERFACEATTACHED_HXX) && !defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY) */

#if !defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY)
#include "cattached.hxx"
#include "ctiffinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cTIFFInterfaceAttachedInterface;
/**
 **********************************************************************
 * Typedef: cTIFFInterfaceAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cTIFFInterfaceAttachedInterface, 
 cTIFFInterface*, UINT, NULL, cInterfaceBase>
cTIFFInterfaceAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTIFFInterfaceAttachedInterface
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFInterfaceAttachedInterface
: virtual public cTIFFInterfaceAttachedInterfaceImplements
{
public:
    typedef cTIFFInterfaceAttachedInterfaceImplements cImplements;
    typedef cTIFFInterfaceAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cTIFFInterfaceAttachedImplement;
/**
 **********************************************************************
 * Typedef: cTIFFInterfaceAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cTIFFInterfaceAttachedImplement, 
 cTIFFInterfaceAttachedInterface, 
 cTIFFInterface*, UINT, NULL>
cTIFFInterfaceAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cTIFFInterfaceAttachedImplement
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTIFFInterfaceAttachedImplement
: virtual public cTIFFInterfaceAttachedImplementImplements
{
public:
    typedef cTIFFInterfaceAttachedImplementImplements cImplements;
    typedef cTIFFInterfaceAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cTIFFInterfaceAttached;
/**
 **********************************************************************
 * Typedef: cTIFFInterfaceAttachedExtends
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cAttachedT
<cTIFFInterfaceAttached, 
 cTIFFInterfaceAttachedImplement, 
 cTIFFInterfaceAttachedInterface,
 cTIFFInterface*, UINT, NULL, cBase>
cTIFFInterfaceAttachedExtends;
/**
 **********************************************************************
 *  Class: cTIFFInterfaceAttached
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cTIFFInterfaceAttached
: public cTIFFInterfaceAttachedExtends
{
public:
    typedef cTIFFInterfaceAttachedExtends cExtends;
    typedef cTIFFInterfaceAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cTIFFInterfaceAttached
     *
     *      Author: $author$
     *        Date: 1/10/2010
     **********************************************************************
     */
    cTIFFInterfaceAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFINTERFACEATTACHED_HXX) || defined(CTIFFINTERFACEATTACHED_MEMBERS_ONLY) */
