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
 *   File: cxtcompositeinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
#if !defined(_CXTCOMPOSITEINTERFACE_HXX) || defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTCOMPOSITEINTERFACE_HXX) && !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY)
#define _CXTCOMPOSITEINTERFACE_HXX
#endif /* !defined(_CXTCOMPOSITEINTERFACE_HXX) && !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY)
#include "cxtcoreinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCompositeInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/23/2010
 **********************************************************************
 */
typedef cXtCoreInterface
cXtCompositeInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtCompositeInterface
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtCompositeInterface
: virtual public cXtCompositeInterfaceImplement
{
public:
    typedef cXtCompositeInterfaceImplement cImplements;
#else /* !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY)
/* include cXtComposite member functions interface
 */
#define CXTCOMPOSITE_MEMBERS_ONLY
#define CXTCOMPOSITE_MEMBER_FUNCS_INTERFACE
//#include "cxtcomposite.hxx"
#undef CXTCOMPOSITE_MEMBER_FUNCS_INTERFACE
#undef CXTCOMPOSITE_MEMBERS_ONLY
};

#if !defined(CXTCOMPOSITEIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXtCompositeImplement
 *
 * Author: $author$           
 *   Date: 6/23/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtCompositeImplement
: virtual public cXtCompositeInterface
{
public:
    typedef cXtCompositeInterface cImplements;
#else /* !defined(CXTCOMPOSITEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTCOMPOSITEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXTCOMPOSITEIMPLEMENT_MEMBERS_ONLY)
/* include cXtComposite member functions implement
 */
#define CXTCOMPOSITE_MEMBERS_ONLY
#define CXTCOMPOSITE_MEMBER_FUNCS_IMPLEMENT
//#include "cxtcomposite.hxx"
#undef CXTCOMPOSITE_MEMBER_FUNCS_IMPLEMENT
#undef CXTCOMPOSITE_MEMBERS_ONLY
};
#else /* !defined(CXTCOMPOSITEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXTCOMPOSITEIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTCOMPOSITEINTERFACE_HXX) || defined(CXTCOMPOSITEINTERFACE_MEMBERS_ONLY) */
