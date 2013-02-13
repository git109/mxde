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
 *   File: cxmstringattached.hxx
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
#if !defined(_CXMSTRINGATTACHED_HXX) || defined(CXMSTRINGATTACHED_MEMBERS_ONLY)
#if !defined(_CXMSTRINGATTACHED_HXX) && !defined(CXMSTRINGATTACHED_MEMBERS_ONLY)
#define _CXMSTRINGATTACHED_HXX
#endif /* !defined(_CXMSTRINGATTACHED_HXX) && !defined(CXMSTRINGATTACHED_MEMBERS_ONLY) */

#if !defined(CXMSTRINGATTACHED_MEMBERS_ONLY)
#include "cplatform_Xm_Xm.h"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXmStringAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXmStringAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXmStringAttachedInterface, 
 XmString, UINT, NULL, cInterfaceBase>
cXmStringAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXmStringAttachedInterface
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmStringAttachedInterface
: virtual public cXmStringAttachedInterfaceImplements
{
public:
    typedef cXmStringAttachedInterfaceImplements cImplements;
    typedef cXmStringAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXmStringAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXmStringAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXmStringAttachedImplement, 
 cXmStringAttachedInterface, 
 XmString, UINT, NULL>
cXmStringAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXmStringAttachedImplement
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmStringAttachedImplement
: virtual public cXmStringAttachedImplementImplements
{
public:
    typedef cXmStringAttachedImplementImplements cImplements;
    typedef cXmStringAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXmStringAttached;
/**
 **********************************************************************
 * Typedef: cXmStringAttachedExtends
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cAttachedT
<cXmStringAttached, 
 cXmStringAttachedImplement, 
 cXmStringAttachedInterface,
 XmString, UINT, NULL, cBase>
cXmStringAttachedExtends;
/**
 **********************************************************************
 *  Class: cXmStringAttached
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXmStringAttached
: public cXmStringAttachedExtends
{
public:
    typedef cXmStringAttachedExtends cExtends;
    typedef cXmStringAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXmStringAttached
     *
     *      Author: $author$           
     *        Date: 7/13/2010
     **********************************************************************
     */
    cXmStringAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMSTRINGATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXMSTRINGATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXMSTRINGATTACHED_HXX) || defined(CXMSTRINGATTACHED_MEMBERS_ONLY) */
