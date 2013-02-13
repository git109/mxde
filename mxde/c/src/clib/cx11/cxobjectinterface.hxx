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
 *   File: cxobjectinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
#if !defined(_CXOBJECTINTERFACE_HXX) || defined(CXOBJECTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXOBJECTINTERFACE_HXX) && !defined(CXOBJECTINTERFACE_MEMBERS_ONLY)
#define _CXOBJECTINTERFACE_HXX
#endif /* !defined(_CXOBJECTINTERFACE_HXX) && !defined(CXOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXOBJECTINTERFACE_MEMBERS_ONLY)
#include "cxdisplayinterface.hxx"
#include "cxbaseinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXObjectInterface
 *
 * Author: $author$           
 *   Date: 7/2/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXObjectInterface
: virtual public cXBaseInterface
{
public:
    typedef cXBaseInterface cImplements;
#else /* !defined(CXOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXOBJECTINTERFACE_MEMBERS_ONLY)
/* include cXObject member functions implement
 */
#define CXOBJECT_MEMBERS_ONLY
#define CXOBJECT_MEMBER_FUNCS_INTERFACE
#include "cxobject.hxx"
#undef CXOBJECT_MEMBER_FUNCS_INTERFACE
#undef CXOBJECT_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cXObjectImplement
: virtual public cXObjectInterface
{
public:
/* include cXObject interface member definitions
 */
#define CXOBJECTINTERFACE_MEMBERS_ONLY
#include "cxobjectinterface.hxx"
#undef CXOBJECTINTERFACE_MEMBERS_ONLY

/* include cXObject member functions implement
 */
#define CXOBJECT_MEMBERS_ONLY
#define CXOBJECT_MEMBER_FUNCS_IMPLEMENT
#include "cxobject.hxx"
#undef CXOBJECT_MEMBER_FUNCS_IMPLEMENT
#undef CXOBJECT_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXOBJECTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXOBJECTINTERFACE_HXX) || defined(CXOBJECTINTERFACE_MEMBERS_ONLY) */
