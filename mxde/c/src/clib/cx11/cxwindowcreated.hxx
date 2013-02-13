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
 *   File: cxwindowcreated.hxx
 *
 * Author: $author$           
 *   Date: 6/28/2010
 **********************************************************************
 */
#if !defined(_CXWINDOWCREATED_HXX) || defined(CXWINDOWCREATED_MEMBERS_ONLY)
#if !defined(_CXWINDOWCREATED_HXX) && !defined(CXWINDOWCREATED_MEMBERS_ONLY)
#define _CXWINDOWCREATED_HXX
#endif /* !defined(_CXWINDOWCREATED_HXX) && !defined(CXWINDOWCREATED_MEMBERS_ONLY) */

#if !defined(CXWINDOWCREATED_MEMBERS_ONLY)
#include "cxwindowattached.hxx"
#include "ccreated.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXWindowCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXWindowCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/23/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXWindowCreatedInterface, cXWindowAttachedInterface>
cXWindowCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXWindowCreatedInterface
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXWindowCreatedInterface
: virtual public cXWindowCreatedInterfaceImplements
{
public:
    typedef cXWindowCreatedInterfaceImplements cImplements;
    typedef cXWindowCreatedInterface cDerives;
};
class c_EXPORT_CLASS cXWindowCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXWindowCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/23/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cXWindowCreatedImplement, cXWindowCreatedInterface>
cXWindowCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXWindowCreatedImplement
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXWindowCreatedImplement
: virtual public cXWindowAttachedImplement,
  virtual public cXWindowCreatedImplementImplements
{
public:
    typedef cXWindowCreatedImplementImplements cImplements;
    typedef cXWindowCreatedImplement cDerives;
};
class c_EXPORT_CLASS cXWindowCreated;
/**
 **********************************************************************
 * Typedef: cXWindowCreatedExtends
 *
 *  Author: $author$           
 *    Date: 6/23/2009
 **********************************************************************
 */
typedef cCreatedT
<cXWindowCreated, 
 cXWindowCreatedImplement, 
 cXWindowAttached>
cXWindowCreatedExtends;
/**
 **********************************************************************
 *  Class: cXWindowCreated
 *
 * Author: $author$           
 *   Date: 6/23/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cXWindowCreated
: public cXWindowCreatedExtends
{
public:
    typedef cXWindowCreatedExtends cExtends;
    typedef cXWindowCreated cDerives;

    /**
     **********************************************************************
     * Constructor: cXWindowCreated
     *
     *      Author: $author$           
     *        Date: 6/23/2009
     **********************************************************************
     */
    cXWindowCreated
    (Window attached = None,
     bool isCreated = false) 
    : cExtends(isCreated) 
    {
        m_attached = attached;
    }
    /**
     **********************************************************************
     * Destructor: ~cXWindowCreated
     *
     *     Author: $author$           
     *       Date: 6/23/2009
     **********************************************************************
     */
    virtual ~cXWindowCreated()
    {
        eError error;
        DBE_THROW_ERROR(error, Destroyed());
    }
#include "ccreatedattached_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOWCREATED_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWCREATED_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOWCREATED_HXX) || defined(CXWINDOWCREATED_MEMBERS_ONLY) */
