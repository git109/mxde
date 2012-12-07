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
 *   File: cpnginforeaderinterfacecreated.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGINFOREADERINTERFACECREATED_HXX) || defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
#if !defined(_CPNGINFOREADERINTERFACECREATED_HXX) && !defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
#define _CPNGINFOREADERINTERFACECREATED_HXX
#endif /* !defined(_CPNGINFOREADERINTERFACECREATED_HXX) && !defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) */

#if !defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY)
#include "cpnginforeaderinterfaceattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngInfoReaderInterfaceCreatedInterface;
/**
 **********************************************************************
 * Typedef: cPngInfoReaderInterfaceCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cPngInfoReaderInterfaceCreatedInterface, 
 cPngInfoReaderInterfaceAttachedInterface>
cPngInfoReaderInterfaceCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInfoReaderInterfaceCreatedInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInfoReaderInterfaceCreatedInterface
: virtual public cPngInfoReaderInterfaceCreatedInterfaceImplements
{
public:
    typedef cPngInfoReaderInterfaceCreatedInterfaceImplements cImplements;
    typedef cPngInfoReaderInterfaceCreatedInterface cDerives;
};
class c_EXPORT_CLASS cPngInfoReaderInterfaceCreatedImplement;
/**
 **********************************************************************
 * Typedef: cPngInfoReaderInterfaceCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cPngInfoReaderInterfaceCreatedImplement, 
 cPngInfoReaderInterfaceCreatedInterface>
cPngInfoReaderInterfaceCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInfoReaderInterfaceCreatedImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfoReaderInterfaceCreatedImplement
: virtual public cPngInfoReaderInterfaceCreatedImplementImplements
{
public:
    typedef cPngInfoReaderInterfaceCreatedImplementImplements cImplements;
    typedef cPngInfoReaderInterfaceCreatedImplement cDerives;
};
class c_EXPORT_CLASS cPngInfoReaderInterfaceCreated;
/**
 **********************************************************************
 * Typedef: cPngInfoReaderInterfaceCreatedExtends
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cCreatedT
<cPngInfoReaderInterfaceCreated, 
 cPngInfoReaderInterfaceCreatedImplement, 
 cPngInfoReaderInterfaceAttached>
cPngInfoReaderInterfaceCreatedExtends;
/**
 **********************************************************************
 *  Class: cPngInfoReaderInterfaceCreated
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfoReaderInterfaceCreated
: public cPngInfoReaderInterfaceCreatedExtends
{
public:
    typedef cPngInfoReaderInterfaceCreatedExtends cExtends;
    typedef cPngInfoReaderInterfaceCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cPngInfoReaderInterfaceCreated
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    cPngInfoReaderInterfaceCreated
    (cPngInfoReaderInterface* attached=0,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cPngInfoReaderInterfaceCreated
     *
     *     Author: $author$
     *       Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cPngInfoReaderInterfaceCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
    
    /**
     **********************************************************************
     * Function: CreateDestroyed
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError CreateDestroyed() 
    {
        eError error = e_ERROR_FAILED;
        cPngInfoReaderInterface* detached;
        if ((detached = cPngInfoReaderInterface::CreateInstance(error)))
        if (!(error = detached->Create()))
            Attach(detached);
        else
        cPngInfoReaderInterface::DestroyInstance(*detached);
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyCreated
     *
     *   Author: $author$
     *     Date: 1/15/2010
     **********************************************************************
     */
    virtual eError DestroyCreated() 
    {
        eError error = e_ERROR_FAILED;
        cPngInfoReaderInterface* detached;
        if ((detached = Detach()))
            error = cPngInfoReaderInterface::DestroyInstance(*detached);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFOREADERINTERFACECREATED_HXX) || defined(CPNGINFOREADERINTERFACECREATED_MEMBERS_ONLY) */
