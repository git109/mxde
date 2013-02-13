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
 *   File: cxtconstraintinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTCONSTRAINTINTERFACE_HXX) || defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTCONSTRAINTINTERFACE_HXX) && !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY)
#define _CXTCONSTRAINTINTERFACE_HXX
#endif /* !defined(_CXTCONSTRAINTINTERFACE_HXX) && !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY)
#include "cxtcompositeinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtConstraintInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtCompositeInterface
cXtConstraintInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtConstraintInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtConstraintInterface
: virtual public cXtConstraintInterfaceImplement
{
public:
    typedef cXtConstraintInterfaceImplement cImplements;
#else /* !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY)
/* include cXtConstraint member functions interface
 */
#define CXTCONSTRAINT_MEMBERS_ONLY
#define CXTCONSTRAINT_MEMBER_FUNCS_INTERFACE
#include "cxtconstraint.hxx"
#undef CXTCONSTRAINT_MEMBER_FUNCS_INTERFACE
#undef CXTCONSTRAINT_MEMBERS_ONLY
};

#if !defined(CXTCONSTRAINTIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtConstraintImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtConstraintImplement
: virtual public cXtConstraintInterface
{
public:
    typedef cXtConstraintInterface cImplements;
#else /* !defined(CXTCONSTRAINTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTCONSTRAINTIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTCONSTRAINTIMPLEMENT_MEMBERS_ONLY)
/* include cXtConstraint member functions implement
 */
#define CXTCONSTRAINT_MEMBERS_ONLY
#define CXTCONSTRAINT_MEMBER_FUNCS_IMPLEMENT
#include "cxtconstraint.hxx"
#undef CXTCONSTRAINT_MEMBER_FUNCS_IMPLEMENT
#undef CXTCONSTRAINT_MEMBERS_ONLY
};
#else /* !defined(CXTCONSTRAINTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTCONSTRAINTIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTCONSTRAINTINTERFACE_HXX) || defined(CXTCONSTRAINTINTERFACE_MEMBERS_ONLY) */
