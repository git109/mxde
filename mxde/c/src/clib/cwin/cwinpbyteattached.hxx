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
 *   File: cwinpbyteattached.hxx
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
#if !defined(_CWINPBYTEATTACHED_HXX) || defined(CWINPBYTEATTACHED_MEMBERS_ONLY)
#if !defined(_CWINPBYTEATTACHED_HXX) && !defined(CWINPBYTEATTACHED_MEMBERS_ONLY)
#define _CWINPBYTEATTACHED_HXX
#endif /* !defined(_CWINPBYTEATTACHED_HXX) && !defined(CWINPBYTEATTACHED_MEMBERS_ONLY) */

#if !defined(CWINPBYTEATTACHED_MEMBERS_ONLY)
#include "cwinbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWinPBYTEAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinPBYTEAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/14/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinPBYTEAttachedInterface, 
 PBYTE, UINT, NULL, cInterfaceBase>
cWinPBYTEAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinPBYTEAttachedInterface
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinPBYTEAttachedInterface
: virtual public cWinPBYTEAttachedInterfaceImplements
{
public:
    typedef cWinPBYTEAttachedInterfaceImplements cImplements;
    typedef cWinPBYTEAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cWinPBYTEAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinPBYTEAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 12/14/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinPBYTEAttachedImplement, 
 cWinPBYTEAttachedInterface, 
 PBYTE, UINT, NULL>
cWinPBYTEAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinPBYTEAttachedImplement
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinPBYTEAttachedImplement
: virtual public cWinPBYTEAttachedImplementImplements
{
public:
    typedef cWinPBYTEAttachedImplementImplements cImplements;
    typedef cWinPBYTEAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cWinPBYTEAttached;
/**
 **********************************************************************
 * Typedef: cWinPBYTEAttachedExtends
 *
 *  Author: $author$
 *    Date: 12/14/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinPBYTEAttached, 
 cWinPBYTEAttachedImplement, 
 cWinPBYTEAttachedInterface,
 PBYTE, UINT, NULL, cBase>
cWinPBYTEAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinPBYTEAttached
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinPBYTEAttached
: public cWinPBYTEAttachedExtends
{
public:
    typedef cWinPBYTEAttachedExtends cExtends;
    typedef cWinPBYTEAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinPBYTEAttached
     *
     *      Author: $author$
     *        Date: 12/14/2009
     **********************************************************************
     */
    cWinPBYTEAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPBYTEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CWINPBYTEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CWINPBYTEATTACHED_HXX) || defined(CWINPBYTEATTACHED_MEMBERS_ONLY) */
