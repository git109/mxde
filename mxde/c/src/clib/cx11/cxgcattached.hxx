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
 *   File: cxgcattached.hxx
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
#if !defined(_CXGCATTACHED_HXX) || defined(CXGCATTACHED_MEMBERS_ONLY)
#if !defined(_CXGCATTACHED_HXX) && !defined(CXGCATTACHED_MEMBERS_ONLY)
#define _CXGCATTACHED_HXX
#endif /* !defined(_CXGCATTACHED_HXX) && !defined(CXGCATTACHED_MEMBERS_ONLY) */

#if !defined(CXGCATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cXGCAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXGCAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXGCAttachedInterface, 
 GC, UINT, NULL, cXBaseInterface>
cXGCAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXGCAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXGCAttachedInterface
: virtual public cXGCAttachedInterfaceImplements
{
public:
    typedef cXGCAttachedInterfaceImplements cImplements;
    typedef cXGCAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXGCAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXGCAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXGCAttachedImplement, 
 cXGCAttachedInterface, 
 GC, UINT, NULL>
cXGCAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXGCAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXGCAttachedImplement
: virtual public cXGCAttachedImplementImplements
{
public:
    typedef cXGCAttachedImplementImplements cImplements;
    typedef cXGCAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXGCAttached;
/**
 **********************************************************************
 * Typedef: cXGCAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cAttachedT
<cXGCAttached, 
 cXGCAttachedImplement, 
 cXGCAttachedInterface,
 GC, UINT, NULL, cXBase>
cXGCAttachedExtends;
/**
 **********************************************************************
 *  Class: cXGCAttached
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXGCAttached
: public cXGCAttachedExtends
{
public:
    typedef cXGCAttachedExtends cExtends;
    typedef cXGCAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXGCAttached
     *
     *      Author: $author$           
     *        Date: 6/29/2009
     **********************************************************************
     */
    cXGCAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXGCCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXGCCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXGCCreatedInterface, cXGCAttachedInterface>
cXGCCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXGCCreatedInterface
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXGCCreatedInterface
: virtual public cXGCCreatedInterfaceImplements
{
public:
    typedef cXGCCreatedInterfaceImplements cImplements;
    typedef cXGCCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXGCCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXGCCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cXGCCreatedImplement, cXGCCreatedInterface>
cXGCCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXGCCreatedImplement
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXGCCreatedImplement
: virtual public cXGCCreatedImplementImplements
{
public:
    typedef cXGCCreatedImplementImplements cImplements;
    typedef cXGCCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXGCCreated;
/**
 **********************************************************************
 * Typedef: cXGCCreatedExtends
 *
 *  Author: $author$           
 *    Date: 6/29/2009
 **********************************************************************
 */
typedef cCreatedT
<cXGCCreated, 
 cXGCCreatedImplement, 
 cXGCAttached>
cXGCCreatedExtends;
/**
 **********************************************************************
 *  Class: cXGCCreated
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXGCCreated
: public cXGCCreatedExtends
{
public:
    typedef cXGCCreatedExtends cExtends;
    typedef cXGCCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXGCCreated
     *
     *      Author: $author$           
     *        Date: 6/29/2009
     **********************************************************************
     */
    cXGCCreated
    (GC attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXGCCreated
     *
     *     Author: $author$           
     *       Date: 6/29/2009
     **********************************************************************
     */
    virtual ~cXGCCreated()
    {
        eError error;
        if ((error = Destroyed()))
        {
            DBE(("()\n throwing error=%d\n", (int)(error)));
            throw (error);
        }
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXGCATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXGCATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXGCATTACHED_HXX) || defined(CXGCATTACHED_MEMBERS_ONLY) */
