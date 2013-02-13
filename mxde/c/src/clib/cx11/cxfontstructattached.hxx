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
 *   File: cxfontstructattached.hxx
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
#if !defined(_CXFONTSTRUCTATTACHED_HXX) || defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY)
#if !defined(_CXFONTSTRUCTATTACHED_HXX) && !defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY)
#define _CXFONTSTRUCTATTACHED_HXX
#endif /* !defined(_CXFONTSTRUCTATTACHED_HXX) && !defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY) */

#if !defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY)
#include "cxbase.hxx"
#include "cattached.hxx"
#include "callocated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXFontStructAttachedImplementsBase
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXFontStructAttachedImplementsBase;
/**
 **********************************************************************
 * Typedef: cXFontStructAttachedExtendsBase
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cXBase
cXFontStructAttachedExtendsBase;

class c_INTERFACE_CLASS cXFontStructAttachedInterface;
/**
 **********************************************************************
 * Typedef: cXFontStructAttachedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cXFontStructAttachedInterface, 
 XFontStruct*, UINT, NULL, cXFontStructAttachedImplementsBase>
cXFontStructAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXFontStructAttachedInterface
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXFontStructAttachedInterface
: virtual public cXFontStructAttachedInterfaceImplements
{
public:
    typedef cXFontStructAttachedInterfaceImplements cImplements;
    typedef cXFontStructAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cXFontStructAttachedImplement;
/**
 **********************************************************************
 * Typedef: cXFontStructAttachedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cXFontStructAttachedImplement, 
 cXFontStructAttachedInterface, 
 XFontStruct*, UINT, NULL>
cXFontStructAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cXFontStructAttachedImplement
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXFontStructAttachedImplement
: virtual public cXFontStructAttachedImplementImplements
{
public:
    typedef cXFontStructAttachedImplementImplements cImplements;
    typedef cXFontStructAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cXFontStructAttached;
/**
 **********************************************************************
 * Typedef: cXFontStructAttachedExtends
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cAttachedT
<cXFontStructAttached, 
 cXFontStructAttachedImplement, 
 cXFontStructAttachedInterface,
 XFontStruct*, UINT, NULL, cXFontStructAttachedExtendsBase>
cXFontStructAttachedExtends;
/**
 **********************************************************************
 *  Class: cXFontStructAttached
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXFontStructAttached
: public cXFontStructAttachedExtends
{
public:
    typedef cXFontStructAttachedExtends cExtends;
    typedef cXFontStructAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cXFontStructAttached
     *
     *      Author: $author$           
     *        Date: 6/13/2010
     **********************************************************************
     */
    cXFontStructAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cXFontStructAllocatedInterface;
/**
 **********************************************************************
 * Typedef: cXFontStructAllocatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cAllocatedInterfaceT
<cXFontStructAllocatedInterface, cXFontStructAttachedInterface>
cXFontStructAllocatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXFontStructAllocatedInterface
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXFontStructAllocatedInterface
: virtual public cXFontStructAllocatedInterfaceImplements
{
public:
    typedef cXFontStructAllocatedInterfaceImplements cImplements;
    typedef cXFontStructAllocatedInterface cDerives;

/* include cAllocatedAttached member functions interface
 */
#define CALLOCATEDATTACHED_MEMBERS_ONLY
#define CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE
#include "callocatedattached_members.hxx"
#undef CALLOCATEDATTACHED_MEMBER_FUNCS_INTERFACE
#undef CALLOCATEDATTACHED_MEMBERS_ONLY
};
class c_EXPORT_CLASS cXFontStructAllocatedImplement;
/**
 **********************************************************************
 * Typedef: cXFontStructAllocatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cAllocatedImplementT
<cXFontStructAllocatedImplement, cXFontStructAllocatedInterface>
cXFontStructAllocatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXFontStructAllocatedImplement
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXFontStructAllocatedImplement
: virtual public cXFontStructAllocatedImplementImplements
{
public:
    typedef cXFontStructAllocatedImplementImplements cImplements;
    typedef cXFontStructAllocatedImplement cDerives;

/* include cAllocatedAttached member functions implement
 */
#define CALLOCATEDATTACHED_MEMBERS_ONLY
#define CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT
#include "callocatedattached_members.hxx"
#undef CALLOCATEDATTACHED_MEMBER_FUNCS_IMPLEMENT
#undef CALLOCATEDATTACHED_MEMBERS_ONLY
};
class c_EXPORT_CLASS cXFontStructAllocated;
/**
 **********************************************************************
 * Typedef: cXFontStructAllocatedExtends
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cAllocatedT
<cXFontStructAllocated, 
 cXFontStructAllocatedImplement, 
 cXFontStructAttached>
cXFontStructAllocatedExtends;
/**
 **********************************************************************
 *  Class: cXFontStructAllocated
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXFontStructAllocated
: public cXFontStructAllocatedExtends
{
public:
    typedef cXFontStructAllocatedExtends cExtends;
    typedef cXFontStructAllocated cDerives;

    /**
     **********************************************************************
     * Constructor: cXFontStructAllocated
     *
     *      Author: $author$           
     *        Date: 6/13/2010
     **********************************************************************
     */
    cXFontStructAllocated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isAllocated=false) 
    : cExtends(isAllocated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXFontStructAllocated
     *
     *     Author: $author$           
     *       Date: 6/13/2010
     **********************************************************************
     */
    virtual ~cXFontStructAllocated()
    {
        eError error;
        if ((error = Freed()))
            throw(error);
    }
#include "callocatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CXFONTSTRUCTATTACHED_HXX) || defined(CXFONTSTRUCTATTACHED_MEMBERS_ONLY) */
