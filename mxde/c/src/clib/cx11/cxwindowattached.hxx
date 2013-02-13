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
 *   File: cxwindowattached.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
#if !defined(_CXWINDOWATTACHED_HXX) || defined(CXWINDOWATTACHED_MEMBERS_ONLY)
#if !defined(_CXWINDOWATTACHED_HXX) && !defined(CXWINDOWATTACHED_MEMBERS_ONLY)
#define _CXWINDOWATTACHED_HXX
#endif /* !defined(_CXWINDOWATTACHED_HXX) && !defined(CXWINDOWATTACHED_MEMBERS_ONLY) */

#if !defined(CXWINDOWATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXWindowAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXWindowAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/23/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXWindowAttachedInterface, 
 Window, UINT, None, cXBaseInterface>
cXWindowAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXWindowAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXWindowAttachedInterface
: virtual public cXWindowAttachedInterfaceImplements
{
public:
    typedef cXWindowAttachedInterfaceImplements cImplements;
    typedef cXWindowAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXWindowAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXWindowAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/23/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXWindowAttachedImplement, 
 cXWindowAttachedInterface, 
 Window, UINT, None>
cXWindowAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXWindowAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXWindowAttachedImplement
: virtual public cXWindowAttachedImplementImplements
{
public:
    typedef cXWindowAttachedImplementImplements cImplements;
    typedef cXWindowAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXWindowAttached;
/**
 **********************************************************************
 * Typedef: cXWindowAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/23/2009
 **********************************************************************
 */
typedef cAttachedT
<cXWindowAttached, 
 cXWindowAttachedImplement, 
 cXWindowAttachedInterface,
 Window, UINT, None, cXBase>
cXWindowAttachedExtends;
/**
 **********************************************************************
 *  Class: cXWindowAttached
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXWindowAttached
: public cXWindowAttachedExtends
{
public:
    typedef cXWindowAttachedExtends cExtends;
    typedef cXWindowAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXWindowAttached
     *
     *      Author: $author$           
     *        Date: 6/23/2009
     **********************************************************************
     */
    cXWindowAttached
    (Window attached = None) 
    : cExtends(attached) 
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOWATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOWATTACHED_HXX) || defined(CXWINDOWATTACHED_MEMBERS_ONLY) */
