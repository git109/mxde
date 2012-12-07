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
#if !defined(_CPNGINFOREADERINTERFACEATTACHED_HXX) || defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY)
#if !defined(_CPNGINFOREADERINTERFACEATTACHED_HXX) && !defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY)
#define _CPNGINFOREADERINTERFACEATTACHED_HXX
#endif /* !defined(_CPNGINFOREADERINTERFACEATTACHED_HXX) && !defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY) */

#if !defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY)
#include "cpnginforeaderinterface.hxx"
#include "cattached.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngInfoReaderInterfaceAttachedInterface;
/**
 **********************************************************************
 * Typedef: cPngInfoReaderInterfaceAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cPngInfoReaderInterfaceAttachedInterface, 
 cPngInfoReaderInterface*, UINT, NULL, cInterfaceBase>
cPngInfoReaderInterfaceAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInfoReaderInterfaceAttachedInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInfoReaderInterfaceAttachedInterface
: virtual public cPngInfoReaderInterfaceAttachedInterfaceImplements
{
public:
    typedef cPngInfoReaderInterfaceAttachedInterfaceImplements cImplements;
    typedef cPngInfoReaderInterfaceAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cPngInfoReaderInterfaceAttachedImplement;
/**
 **********************************************************************
 * Typedef: cPngInfoReaderInterfaceAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cPngInfoReaderInterfaceAttachedImplement, 
 cPngInfoReaderInterfaceAttachedInterface, 
 cPngInfoReaderInterface*, UINT, NULL>
cPngInfoReaderInterfaceAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInfoReaderInterfaceAttachedImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPngInfoReaderInterfaceAttachedImplement
: virtual public cPngInfoReaderInterfaceAttachedImplementImplements
{
public:
    typedef cPngInfoReaderInterfaceAttachedImplementImplements cImplements;
    typedef cPngInfoReaderInterfaceAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cPngInfoReaderInterfaceAttached;
/**
 **********************************************************************
 * Typedef: cPngInfoReaderInterfaceAttachedExtends
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cAttachedT
<cPngInfoReaderInterfaceAttached, 
 cPngInfoReaderInterfaceAttachedImplement, 
 cPngInfoReaderInterfaceAttachedInterface,
 cPngInfoReaderInterface*, UINT, NULL, cInstanceBase>
cPngInfoReaderInterfaceAttachedExtends;
/**
 **********************************************************************
 *  Class: cPngInfoReaderInterfaceAttached
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cPngInfoReaderInterfaceAttached
: public cPngInfoReaderInterfaceAttachedExtends
{
public:
    typedef cPngInfoReaderInterfaceAttachedExtends cExtends;
    typedef cPngInfoReaderInterfaceAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cPngInfoReaderInterfaceAttached
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    cPngInfoReaderInterfaceAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFOREADERINTERFACEATTACHED_HXX) || defined(CPNGINFOREADERINTERFACEATTACHED_MEMBERS_ONLY) */
