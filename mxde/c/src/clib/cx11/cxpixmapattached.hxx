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
 *   File: cxpixmapattached.hxx
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
#if !defined(_CXPIXMAPATTACHED_HXX) || defined(CXPIXMAPATTACHED_MEMBERS_ONLY)
#if !defined(_CXPIXMAPATTACHED_HXX) && !defined(CXPIXMAPATTACHED_MEMBERS_ONLY)
#define _CXPIXMAPATTACHED_HXX
#endif /* !defined(_CXPIXMAPATTACHED_HXX) && !defined(CXPIXMAPATTACHED_MEMBERS_ONLY) */

#if !defined(CXPIXMAPATTACHED_MEMBERS_ONLY)
#include "cattached.hxx"
#include "ccreated.hxx"
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cXPixmapAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXPixmapAttachedImplementsImplement
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXPixmapAttachedImplementsImplement;
/**
 **********************************************************************
 * Typedef: cXPixmapAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXPixmapAttachedInterface, 
 Pixmap, UINT, None, cXPixmapAttachedImplementsImplement>
cXPixmapAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXPixmapAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXPixmapAttachedInterface
: virtual public cXPixmapAttachedInterfaceImplements
{
public:
    typedef cXPixmapAttachedInterfaceImplements cImplements;
    typedef cXPixmapAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXPixmapAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXPixmapAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXPixmapAttachedImplement, 
 cXPixmapAttachedInterface, 
 Pixmap, UINT, None>
cXPixmapAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXPixmapAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXPixmapAttachedImplement
: virtual public cXPixmapAttachedImplementImplements
{
public:
    typedef cXPixmapAttachedImplementImplements cImplements;
    typedef cXPixmapAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXPixmapAttached;
/**
 **********************************************************************
 * Typedef: cXPixmapAttachedExtendsExtend
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cXBase
cXPixmapAttachedExtendsExtend;
/**
 **********************************************************************
 * Typedef: cXPixmapAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cAttachedT
<cXPixmapAttached, 
 cXPixmapAttachedImplement, 
 cXPixmapAttachedInterface,
 Pixmap, UINT, None, cXPixmapAttachedExtendsExtend>
cXPixmapAttachedExtends;
/**
 **********************************************************************
 *  Class: cXPixmapAttached
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXPixmapAttached
: public cXPixmapAttachedExtends
{
public:
    typedef cXPixmapAttachedExtends cExtends;
    typedef cXPixmapAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXPixmapAttached
     *
     *      Author: $author$           
     *        Date: 6/1/2010
     **********************************************************************
     */
    cXPixmapAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXPixmapCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXPixmapCreatedImplementsImplement
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cXPixmapAttachedInterface
cXPixmapCreatedImplementsImplement;
/**
 **********************************************************************
 * Typedef: cXPixmapCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXPixmapCreatedInterface, cXPixmapCreatedImplementsImplement>
cXPixmapCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXPixmapCreatedInterface
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXPixmapCreatedInterface
: virtual public cXPixmapCreatedInterfaceImplements
{
public:
    typedef cXPixmapCreatedInterfaceImplements cImplements;
    typedef cXPixmapCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXPixmapCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXPixmapCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXPixmapCreatedImplement, cXPixmapCreatedInterface>
cXPixmapCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXPixmapCreatedImplement
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXPixmapCreatedImplement
: virtual public cXPixmapCreatedImplementImplements
{
public:
    typedef cXPixmapCreatedImplementImplements cImplements;
    typedef cXPixmapCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXPixmapCreated;
/**
 **********************************************************************
 * Typedef: cXPixmapCreatedExtendsExtend
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cXPixmapAttached
cXPixmapCreatedExtendsExtend;
/**
 **********************************************************************
 * Typedef: cXPixmapCreatedExtends
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cCreatedT
<cXPixmapCreated, 
 cXPixmapCreatedImplement, 
 cXPixmapCreatedExtendsExtend>
cXPixmapCreatedExtends;
/**
 **********************************************************************
 *  Class: cXPixmapCreated
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXPixmapCreated
: public cXPixmapCreatedExtends
{
public:
    typedef cXPixmapCreatedExtends cExtends;
    typedef cXPixmapCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXPixmapCreated
     *
     *      Author: $author$           
     *        Date: 6/1/2010
     **********************************************************************
     */
    cXPixmapCreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXPixmapCreated
     *
     *     Author: $author$           
     *       Date: 6/1/2010
     **********************************************************************
     */
    virtual ~cXPixmapCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPIXMAPATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAPATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXPIXMAPATTACHED_HXX) || defined(CXPIXMAPATTACHED_MEMBERS_ONLY) */
