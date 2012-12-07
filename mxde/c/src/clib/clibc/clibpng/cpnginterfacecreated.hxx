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
 *   File: cpnginterfacecreated.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGINTERFACECREATED_HXX) || defined(CPNGINTERFACECREATED_MEMBERS_ONLY)
#if !defined(_CPNGINTERFACECREATED_HXX) && !defined(CPNGINTERFACECREATED_MEMBERS_ONLY)
#define _CPNGINTERFACECREATED_HXX
#endif /* !defined(_CPNGINTERFACECREATED_HXX) && !defined(CPNGINTERFACECREATED_MEMBERS_ONLY) */

#if !defined(CPNGINTERFACECREATED_MEMBERS_ONLY)
#include "cpnginterfaceattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngInterfaceCreatedInterface;
/**
 **********************************************************************
 * Typedef: cPngInterfaceCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cPngInterfaceCreatedInterface, 
 cPngInterfaceAttachedInterface>
cPngInterfaceCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInterfaceCreatedInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInterfaceCreatedInterface
: virtual public cPngInterfaceCreatedInterfaceImplements
{
public:
    typedef cPngInterfaceCreatedInterfaceImplements cImplements;
    typedef cPngInterfaceCreatedInterface cDerives;
};
class c_EXPORT_CLASS cPngInterfaceCreatedImplement;
/**
 **********************************************************************
 * Typedef: cPngInterfaceCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cPngInterfaceCreatedImplement, 
 cPngInterfaceCreatedInterface>
cPngInterfaceCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInterfaceCreatedImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInterfaceCreatedImplement
: virtual public cPngInterfaceCreatedImplementImplements
{
public:
    typedef cPngInterfaceCreatedImplementImplements cImplements;
    typedef cPngInterfaceCreatedImplement cDerives;
};
class c_EXPORT_CLASS cPngInterfaceCreated;
/**
 **********************************************************************
 * Typedef: cPngInterfaceCreatedExtends
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cCreatedT
<cPngInterfaceCreated, 
 cPngInterfaceCreatedImplement, 
 cPngInterfaceAttached>
cPngInterfaceCreatedExtends;
/**
 **********************************************************************
 *  Class: cPngInterfaceCreated
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInterfaceCreated
: public cPngInterfaceCreatedExtends
{
public:
    typedef cPngInterfaceCreatedExtends cExtends;
    typedef cPngInterfaceCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cPngInterfaceCreated
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    cPngInterfaceCreated
    (cPngInterface* attached=0,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cPngInterfaceCreated
     *
     *     Author: $author$
     *       Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cPngInterfaceCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINTERFACECREATED_MEMBERS_ONLY) */
#endif /* !defined(CPNGINTERFACECREATED_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINTERFACECREATED_HXX) || defined(CPNGINTERFACECREATED_MEMBERS_ONLY) */
