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
 *   File: cwinhbitmapattached.hxx
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
#if !defined(_CWINHBITMAPATTACHED_HXX) || defined(CWINHBITMAPATTACHED_MEMBERS_ONLY)
#if !defined(_CWINHBITMAPATTACHED_HXX) && !defined(CWINHBITMAPATTACHED_MEMBERS_ONLY)
#define _CWINHBITMAPATTACHED_HXX
#endif /* !defined(_CWINHBITMAPATTACHED_HXX) && !defined(CWINHBITMAPATTACHED_MEMBERS_ONLY) */

#if !defined(CWINHBITMAPATTACHED_MEMBERS_ONLY)
#include "cwinbaseinterface.hxx"
#include "cwinbase.hxx"
#include "cattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cWinHBITMAPAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHBITMAPAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHBITMAPAttachedInterface, 
 HBITMAP, UINT, NULL, cWinBaseInterface>
cWinHBITMAPAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHBITMAPAttachedInterface
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHBITMAPAttachedInterface
: virtual public cWinHBITMAPAttachedInterfaceImplements
{
public:
    typedef cWinHBITMAPAttachedInterfaceImplements cImplements;
    typedef cWinHBITMAPAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cWinHBITMAPAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHBITMAPAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHBITMAPAttachedImplement, 
 cWinHBITMAPAttachedInterface, 
 HBITMAP, UINT, NULL>
cWinHBITMAPAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHBITMAPAttachedImplement
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinHBITMAPAttachedImplement
: virtual public cWinHBITMAPAttachedImplementImplements
{
public:
    typedef cWinHBITMAPAttachedImplementImplements cImplements;
    typedef cWinHBITMAPAttachedImplement cDerives;
};
class c_EXPORT_CLASS cWinHBITMAPAttached;
/**
 **********************************************************************
 * Typedef: cWinHBITMAPAttachedExtends
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinHBITMAPAttached, 
 cWinHBITMAPAttachedImplement, 
 cWinHBITMAPAttachedInterface,
 HBITMAP, UINT, NULL, cWinBase>
cWinHBITMAPAttachedExtends;
/**
 **********************************************************************
 *  Class: cWinHBITMAPAttached
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBITMAPAttached
: public cWinHBITMAPAttachedExtends
{
public:
    typedef cWinHBITMAPAttachedExtends cExtends;
    typedef cWinHBITMAPAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHBITMAPAttached
     *
     *      Author: $author$
     *        Date: 7/24/2009
     **********************************************************************
     */
    cWinHBITMAPAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cWinHBITMAPInterface;
/**
 **********************************************************************
 * Typedef: cWinHBITMAPInterfaceImplements
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cWinHBITMAPInterface, cWinHBITMAPAttachedInterface>
cWinHBITMAPInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHBITMAPInterface
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHBITMAPInterface
: virtual public cWinHBITMAPInterfaceImplements
{
public:
    typedef cWinHBITMAPInterfaceImplements cImplements;
    typedef cWinHBITMAPInterface cDerives;
};
class c_EXPORT_CLASS cWinHBITMAPImplement;
/**
 **********************************************************************
 * Typedef: cWinHBITMAPImplementImplements
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cWinHBITMAPImplement, cWinHBITMAPInterface>
cWinHBITMAPImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHBITMAPImplement
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBITMAPImplement
: virtual public cWinHBITMAPImplementImplements
{
public:
    typedef cWinHBITMAPImplementImplements cImplements;
    typedef cWinHBITMAPImplement cDerives;
};
class c_EXPORT_CLASS cWinHBITMAP;
/**
 **********************************************************************
 * Typedef: cWinHBITMAPExtends
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cCreatedT
<cWinHBITMAP, 
 cWinHBITMAPImplement, 
 cWinHBITMAPAttached>
cWinHBITMAPExtends;
/**
 **********************************************************************
 *  Class: cWinHBITMAP
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHBITMAP
: public cWinHBITMAPExtends
{
public:
    typedef cWinHBITMAPExtends cExtends;
    typedef cWinHBITMAP cDerives;

    /**
     **********************************************************************
     * Constructor: cWinHBITMAP
     *
     *      Author: $author$
     *        Date: 7/24/2009
     **********************************************************************
     */
    cWinHBITMAP
    (HBITMAP attached=NULL,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cWinHBITMAP
     *
     *     Author: $author$
     *       Date: 7/24/2009
     **********************************************************************
     */
    virtual ~cWinHBITMAP()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHBITMAPATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CWINHBITMAPATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CWINHBITMAPATTACHED_HXX) || defined(CWINHBITMAPATTACHED_MEMBERS_ONLY) */
