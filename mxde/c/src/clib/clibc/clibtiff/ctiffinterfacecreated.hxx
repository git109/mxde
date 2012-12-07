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
 *   File: ctiffinterfacecreated.hxx
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
#if !defined(_CTIFFINTERFACECREATED_HXX) || defined(CTIFFINTERFACECREATED_MEMBERS_ONLY)
#if !defined(_CTIFFINTERFACECREATED_HXX) && !defined(CTIFFINTERFACECREATED_MEMBERS_ONLY)
#define _CTIFFINTERFACECREATED_HXX
#endif /* !defined(_CTIFFINTERFACECREATED_HXX) && !defined(CTIFFINTERFACECREATED_MEMBERS_ONLY) */

#if !defined(CTIFFINTERFACECREATED_MEMBERS_ONLY)
#include "ctiffinterfaceattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cTIFFInterfaceCreatedInterface;
/**
 **********************************************************************
 * Typedef: cTIFFInterfaceCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cTIFFInterfaceCreatedInterface, cTIFFInterfaceAttachedInterface>
cTIFFInterfaceCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTIFFInterfaceCreatedInterface
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFInterfaceCreatedInterface
: virtual public cTIFFInterfaceCreatedInterfaceImplements
{
public:
    typedef cTIFFInterfaceCreatedInterfaceImplements cImplements;
    typedef cTIFFInterfaceCreatedInterface cDerives;
};
class c_EXPORT_CLASS cTIFFInterfaceCreatedImplement;
/**
 **********************************************************************
 * Typedef: cTIFFInterfaceCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cTIFFInterfaceCreatedImplement, cTIFFInterfaceCreatedInterface>
cTIFFInterfaceCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cTIFFInterfaceCreatedImplement
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cTIFFInterfaceCreatedImplement
: virtual public cTIFFInterfaceCreatedImplementImplements
{
public:
    typedef cTIFFInterfaceCreatedImplementImplements cImplements;
    typedef cTIFFInterfaceCreatedImplement cDerives;
};
class c_EXPORT_CLASS cTIFFInterfaceCreated;
/**
 **********************************************************************
 * Typedef: cTIFFInterfaceCreatedExtends
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cCreatedT
<cTIFFInterfaceCreated, 
 cTIFFInterfaceCreatedImplement, 
 cTIFFInterfaceAttached>
cTIFFInterfaceCreatedExtends;
/**
 **********************************************************************
 *  Class: cTIFFInterfaceCreated
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cTIFFInterfaceCreated
: public cTIFFInterfaceCreatedExtends
{
public:
    typedef cTIFFInterfaceCreatedExtends cExtends;
    typedef cTIFFInterfaceCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cTIFFInterfaceCreated
     *
     *      Author: $author$
     *        Date: 1/10/2010
     **********************************************************************
     */
    cTIFFInterfaceCreated
    (cTIFFInterface* attached=0,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cTIFFInterfaceCreated
     *
     *     Author: $author$
     *       Date: 1/10/2010
     **********************************************************************
     */
    virtual ~cTIFFInterfaceCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
    
    /**
     **********************************************************************
     * Function: CreatedAttached
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual cTIFFInterface* CreatedAttached
    (eError& error, bool onlyCreated=false)
    {
        cTIFFInterface* attached = 0;
        if (!(error = Created(onlyCreated)))
            attached = Attached();
        return attached;
    }
    /**
     **********************************************************************
     * Function: CreateDestroyed
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual eError CreateDestroyed() 
    {
        eError error = e_ERROR_NONE;
        cTIFFInterface* detached = 0;
        if ((detached = CreateDetached(error)))
        if (detached != (Attach(detached)))
        {
            DestroyDetached(*detached);
            error = e_ERROR_FAILED;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyCreated
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual eError DestroyCreated() 
    {
        eError error = e_ERROR_NOT_ATTACHED;
        cTIFFInterface* detached = 0;
        if ((detached = Detach()))
            error = DestroyDetached(*detached);
        return error;
    }
    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual cTIFFInterface* CreateDetached
    (eError& error) const 
    {
        cTIFFInterface* detached = cTIFFInterface::CreateInstance(error);
        return detached;
    }
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 1/11/2010
     **********************************************************************
     */
    virtual eError DestroyDetached
    (cTIFFInterface& detached) const 
    {
        eError error = cTIFFInterface::DestroyInstance(detached);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFINTERFACECREATED_MEMBERS_ONLY) */
#endif /* !defined(CTIFFINTERFACECREATED_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFINTERFACECREATED_HXX) || defined(CTIFFINTERFACECREATED_MEMBERS_ONLY) */
