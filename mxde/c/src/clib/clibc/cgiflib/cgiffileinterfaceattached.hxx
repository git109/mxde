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
 *   File: cgiffileinterfaceattached.hxx
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
#if !defined(_CGIFFILEINTERFACEATTACHED_HXX) || defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY)
#if !defined(_CGIFFILEINTERFACEATTACHED_HXX) && !defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY)
#define _CGIFFILEINTERFACEATTACHED_HXX
#endif /* !defined(_CGIFFILEINTERFACEATTACHED_HXX) && !defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY) */

#if !defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY)
#include "cgiffileinterface.hxx"
#include "cinstancebase.hxx"
#include "ccreated.hxx"
#include "cattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cGifFileInterfaceAttachedInterface;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/14/2010
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cGifFileInterfaceAttachedInterface, 
 cGifFileInterface*, UINT, NULL, cInterfaceBase>
cGifFileInterfaceAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cGifFileInterfaceAttachedInterface
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifFileInterfaceAttachedInterface
: virtual public cGifFileInterfaceAttachedInterfaceImplements
{
public:
    typedef cGifFileInterfaceAttachedInterfaceImplements cImplements;
    typedef cGifFileInterfaceAttachedInterface cDerives;
};
class c_IMPLEMENT_CLASS cGifFileInterfaceAttachedImplement;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 11/14/2010
 **********************************************************************
 */
typedef cAttachedImplementT
<cGifFileInterfaceAttachedImplement, 
 cGifFileInterfaceAttachedInterface, 
 cGifFileInterface*, UINT, NULL>
cGifFileInterfaceAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cGifFileInterfaceAttachedImplement
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cGifFileInterfaceAttachedImplement
: virtual public cGifFileInterfaceAttachedImplementImplements
{
public:
    typedef cGifFileInterfaceAttachedImplementImplements cImplements;
    typedef cGifFileInterfaceAttachedImplement cDerives;
};
class c_INSTANCE_CLASS cGifFileInterfaceAttached;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceAttachedExtends
 *
 *  Author: $author$
 *    Date: 11/14/2010
 **********************************************************************
 */
typedef cAttachedT
<cGifFileInterfaceAttached, 
 cGifFileInterfaceAttachedImplement, 
 cGifFileInterfaceAttachedInterface,
 cGifFileInterface*, UINT, NULL, cInstanceBase>
cGifFileInterfaceAttachedExtends;
/**
 **********************************************************************
 *  Class: cGifFileInterfaceAttached
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifFileInterfaceAttached
: public cGifFileInterfaceAttachedExtends
{
public:
    typedef cGifFileInterfaceAttachedExtends cExtends;
    typedef cGifFileInterfaceAttached cDerives;

    /**
     **********************************************************************
     * Constructor: cGifFileInterfaceAttached
     *
     *      Author: $author$
     *        Date: 11/14/2010
     **********************************************************************
     */
    cGifFileInterfaceAttached
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }
};

class c_INTERFACE_CLASS cGifFileInterfaceCreatedInterface;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/14/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cGifFileInterfaceCreatedInterface, cGifFileInterfaceAttachedInterface>
cGifFileInterfaceCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cGifFileInterfaceCreatedInterface
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifFileInterfaceCreatedInterface
: virtual public cGifFileInterfaceCreatedInterfaceImplements
{
public:
    typedef cGifFileInterfaceCreatedInterfaceImplements cImplements;
    typedef cGifFileInterfaceCreatedInterface cDerives;
};
class c_EXPORT_CLASS cGifFileInterfaceCreatedImplement;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 11/14/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cGifFileInterfaceCreatedImplement, cGifFileInterfaceCreatedInterface>
cGifFileInterfaceCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cGifFileInterfaceCreatedImplement
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cGifFileInterfaceCreatedImplement
: virtual public cGifFileInterfaceCreatedImplementImplements
{
public:
    typedef cGifFileInterfaceCreatedImplementImplements cImplements;
    typedef cGifFileInterfaceCreatedImplement cDerives;
};
class c_EXPORT_CLASS cGifFileInterfaceCreated;
/**
 **********************************************************************
 * Typedef: cGifFileInterfaceCreatedExtends
 *
 *  Author: $author$
 *    Date: 11/14/2010
 **********************************************************************
 */
typedef cCreatedT
<cGifFileInterfaceCreated, 
 cGifFileInterfaceCreatedImplement, 
 cGifFileInterfaceAttached>
cGifFileInterfaceCreatedExtends;
/**
 **********************************************************************
 *  Class: cGifFileInterfaceCreated
 *
 * Author: $author$
 *   Date: 11/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cGifFileInterfaceCreated
: public cGifFileInterfaceCreatedExtends
{
public:
    typedef cGifFileInterfaceCreatedExtends cExtends;
    typedef cGifFileInterfaceCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cGifFileInterfaceCreated
     *
     *      Author: $author$
     *        Date: 11/14/2010
     **********************************************************************
     */
    cGifFileInterfaceCreated
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cGifFileInterfaceCreated
     *
     *     Author: $author$
     *       Date: 11/14/2010
     **********************************************************************
     */
    virtual ~cGifFileInterfaceCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 11/14/2010
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
    {
        eError error = e_ERROR_FAILED;
        cGifFileInterface* detached;
        if (!(error = Destroyed(onlyDestroyed)))
        if ((detached = cGifFileInterface::CreateInstance(error)))
        if (detached != (AttachCreated(detached)))
        {
            cGifFileInterface::DestroyInstance(*detached);
            error = e_ERROR_FAILED;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 11/14/2010
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
    {
        eError error = e_ERROR_NONE;
        cGifFileInterface* detached;
        if ((detached = Detach()))
            error = cGifFileInterface::DestroyInstance(*detached);
        else
        if (onlyCreated)
            error = e_ERROR_NOT_ATTACHED;
        return error;
    }
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILEINTERFACEATTACHED_HXX) || defined(CGIFFILEINTERFACEATTACHED_MEMBERS_ONLY) */
