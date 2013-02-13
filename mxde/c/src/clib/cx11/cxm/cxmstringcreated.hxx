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
 *   File: cxmstringcreated.hxx
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
#if !defined(_CXMSTRINGCREATED_HXX) || defined(CXMSTRINGCREATED_MEMBERS_ONLY)
#if !defined(_CXMSTRINGCREATED_HXX) && !defined(CXMSTRINGCREATED_MEMBERS_ONLY)
#define _CXMSTRINGCREATED_HXX
#endif /* !defined(_CXMSTRINGCREATED_HXX) && !defined(CXMSTRINGCREATED_MEMBERS_ONLY) */

#if !defined(CXMSTRINGCREATED_MEMBERS_ONLY)
#include "cxmstringattached.hxx"
#include "ccreated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXmStringCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXmStringCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXmStringCreatedInterface, cXmStringAttachedInterface>
cXmStringCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXmStringCreatedInterface
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmStringCreatedInterface
: virtual public cXmStringCreatedInterfaceImplements
{
public:
    typedef cXmStringCreatedInterfaceImplements cImplements;
    typedef cXmStringCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXmStringCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXmStringCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXmStringCreatedImplement, cXmStringCreatedInterface>
cXmStringCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXmStringCreatedImplement
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXmStringCreatedImplement
: virtual public cXmStringCreatedImplementImplements
{
public:
    typedef cXmStringCreatedImplementImplements cImplements;
    typedef cXmStringCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXmStringCreated;
/**
 **********************************************************************
 * Typedef: cXmStringCreatedExtends
 *
 *  Author: $author$           
 *    Date: 7/13/2010
 **********************************************************************
 */
typedef cCreatedT
<cXmStringCreated, 
 cXmStringCreatedImplement, 
 cXmStringAttached>
cXmStringCreatedExtends;
/**
 **********************************************************************
 *  Class: cXmStringCreated
 *
 * Author: $author$           
 *   Date: 7/13/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXmStringCreated
: public cXmStringCreatedExtends
{
public:
    typedef cXmStringCreatedExtends cExtends;
    typedef cXmStringCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXmStringCreated
     *
     *      Author: $author$           
     *        Date: 7/13/2010
     **********************************************************************
     */
    cXmStringCreated
    (XmString attached=0,
     bool isCreated=false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXmStringCreated
     *
     *     Author: $author$           
     *       Date: 7/13/2010
     **********************************************************************
     */
    virtual ~cXmStringCreated()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMSTRINGCREATED_MEMBERS_ONLY) */
#endif /* !defined(CXMSTRINGCREATED_MEMBERS_ONLY) */

#endif /* !defined(_CXMSTRINGCREATED_HXX) || defined(CXMSTRINGCREATED_MEMBERS_ONLY) */
