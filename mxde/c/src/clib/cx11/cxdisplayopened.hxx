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
 *   File: cxdisplayopened.hxx
 *
 * Author: $author$           
 *   Date: 6/28/2010
 **********************************************************************
 */
#if !defined(_CXDISPLAYOPENED_HXX) || defined(CXDISPLAYOPENED_MEMBERS_ONLY)
#if !defined(_CXDISPLAYOPENED_HXX) && !defined(CXDISPLAYOPENED_MEMBERS_ONLY)
#define _CXDISPLAYOPENED_HXX
#endif /* !defined(_CXDISPLAYOPENED_HXX) && !defined(CXDISPLAYOPENED_MEMBERS_ONLY) */

#if !defined(CXDISPLAYOPENED_MEMBERS_ONLY)
#include "cxdisplayattached.hxx"
#include "copened.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXDisplayOpenedInterface;
/**
 **********************************************************************
 * Typedef: cXDisplayOpenedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/21/2009
 **********************************************************************
 */
typedef cOpenedInterfaceT
<cXDisplayOpenedInterface, cXDisplayAttachedInterface>
cXDisplayOpenedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXDisplayOpenedInterface
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXDisplayOpenedInterface
: virtual public cXDisplayOpenedInterfaceImplements
{
public:
    typedef cXDisplayOpenedInterfaceImplements cImplements;
    typedef cXDisplayOpenedInterface cDerives;
};
class c_EXPORT_CLASS cXDisplayOpenedImplement;
/**
 **********************************************************************
 * Typedef: cXDisplayOpenedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/21/2009
 **********************************************************************
 */
typedef cOpenedImplementT
<cXDisplayOpenedImplement, cXDisplayOpenedInterface>
cXDisplayOpenedImplementImplements;
/**
 **********************************************************************
 *  Class: cXDisplayOpenedImplement
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXDisplayOpenedImplement
: virtual public cXDisplayOpenedImplementImplements
{
public:
    typedef cXDisplayOpenedImplementImplements cImplements;
    typedef cXDisplayOpenedImplement cDerives;
};
class c_EXPORT_CLASS cXDisplayOpened;
/**
 **********************************************************************
 * Typedef: cXDisplayOpenedExtends
 *
 *  Author: $author$           
 *    Date: 6/21/2009
 **********************************************************************
 */
typedef cOpenedT
<cXDisplayOpened, 
 cXDisplayOpenedImplement, 
 cXDisplayAttached>
cXDisplayOpenedExtends;
/**
 **********************************************************************
 *  Class: cXDisplayOpened
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXDisplayOpened
: public cXDisplayOpenedExtends
{
public:
    typedef cXDisplayOpenedExtends cExtends;
    typedef cXDisplayOpened cDerives;

    /**
     **********************************************************************
     * Constructor: cXDisplayOpened
     *
     *      Author: $author$           
     *        Date: 6/21/2009
     **********************************************************************
     */
    cXDisplayOpened
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isOpen=false) 
    : cExtends(isOpen) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXDisplayOpened
     *
     *     Author: $author$           
     *       Date: 6/21/2009
     **********************************************************************
     */
    virtual ~cXDisplayOpened()
    {
        eError error;
        DBE_THROW_ERROR(error, Closed());
    }
#include "copenedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXDISPLAYOPENED_MEMBERS_ONLY) */
#endif /* !defined(CXDISPLAYOPENED_MEMBERS_ONLY) */

#endif /* !defined(_CXDISPLAYOPENED_HXX) || defined(CXDISPLAYOPENED_MEMBERS_ONLY) */
