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
 *   File: cxcolormapattached.hxx
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
#if !defined(_CXCOLORMAPATTACHED_HXX) || defined(CXCOLORMAPATTACHED_MEMBERS_ONLY)
#if !defined(_CXCOLORMAPATTACHED_HXX) && !defined(CXCOLORMAPATTACHED_MEMBERS_ONLY)
#define _CXCOLORMAPATTACHED_HXX
#endif /* !defined(_CXCOLORMAPATTACHED_HXX) && !defined(CXCOLORMAPATTACHED_MEMBERS_ONLY) */

#if !defined(CXCOLORMAPATTACHED_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cXColormapAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXColormapAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/2/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXColormapAttachedInterface, 
 Colormap, UINT, NULL, cXBaseInterface>
cXColormapAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXColormapAttachedInterface
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXColormapAttachedInterface
: virtual public cXColormapAttachedInterfaceImplements
{
public:
    typedef cXColormapAttachedInterfaceImplements cImplements;
    typedef cXColormapAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXColormapAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXColormapAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/2/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cXColormapAttachedImplement, 
 cXColormapAttachedInterface, 
 Colormap, UINT, NULL>
cXColormapAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXColormapAttachedImplement
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXColormapAttachedImplement
: virtual public cXColormapAttachedImplementImplements
{
public:
    typedef cXColormapAttachedImplementImplements cImplements;
    typedef cXColormapAttachedImplement cDerives;
};
class c_EXPORT_CLASS cXColormapAttached;
/**
 **********************************************************************
 * Typedef: cXColormapAttachedExtends
 *
 *  Author: $author$           
 *    Date: 7/2/2009
 **********************************************************************
 */
typedef cAttachedT
<cXColormapAttached, 
 cXColormapAttachedImplement, 
 cXColormapAttachedInterface,
 Colormap, UINT, NULL, cXBase>
cXColormapAttachedExtends;
/**
 **********************************************************************
 *  Class: cXColormapAttached
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXColormapAttached
: public cXColormapAttachedExtends
{
public:
    typedef cXColormapAttachedExtends cExtends;
    typedef cXColormapAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXColormapAttached
     *
     *      Author: $author$           
     *        Date: 7/2/2009
     **********************************************************************
     */
    cXColormapAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXColormapCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXColormapCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/4/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXColormapCreatedInterface, cXColormapAttachedInterface>
cXColormapCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXColormapCreatedInterface
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXColormapCreatedInterface
: virtual public cXColormapCreatedInterfaceImplements
{
public:
    typedef cXColormapCreatedInterfaceImplements cImplements;
    typedef cXColormapCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXColormapCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXColormapCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/4/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cXColormapCreatedImplement, cXColormapCreatedInterface>
cXColormapCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXColormapCreatedImplement
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXColormapCreatedImplement
: virtual public cXColormapCreatedImplementImplements
{
public:
    typedef cXColormapCreatedImplementImplements cImplements;
    typedef cXColormapCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXColormapCreated;
/**
 **********************************************************************
 * Typedef: cXColormapCreatedExtends
 *
 *  Author: $author$           
 *    Date: 7/4/2009
 **********************************************************************
 */
typedef cCreatedT
<cXColormapCreated, 
 cXColormapCreatedImplement, 
 cXColormapAttached>
cXColormapCreatedExtends;
/**
 **********************************************************************
 *  Class: cXColormapCreated
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXColormapCreated
: public cXColormapCreatedExtends
{
public:
    typedef cXColormapCreatedExtends cExtends;
    typedef cXColormapCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXColormapCreated
     *
     *      Author: $author$           
     *        Date: 7/4/2009
     **********************************************************************
     */
    cXColormapCreated
    (Colormap attached=None,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXColormapCreated
     *
     *     Author: $author$           
     *       Date: 7/4/2009
     **********************************************************************
     */
    virtual ~cXColormapCreated()
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

#else /* !defined(CXCOLORMAPATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORMAPATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXCOLORMAPATTACHED_HXX) || defined(CXCOLORMAPATTACHED_MEMBERS_ONLY) */
