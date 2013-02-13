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
 *   File: cxtarginterface.hxx
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
#if !defined(_CXTARGINTERFACE_HXX) || defined(CXTARGINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTARGINTERFACE_HXX) && !defined(CXTARGINTERFACE_MEMBERS_ONLY)
#define _CXTARGINTERFACE_HXX
#endif /* !defined(_CXTARGINTERFACE_HXX) && !defined(CXTARGINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTARGINTERFACE_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cxtstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtArgInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/24/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXtArgInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtArgInterface
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtArgInterface
: virtual public cXtArgInterfaceImplement
{
public:
    typedef cXtArgInterfaceImplement cImplements;
#else /* !defined(CXTARGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTARGINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTARGINTERFACE_MEMBERS_ONLY)
/* include cXtArg member functions interface
 */
#define CXTARG_MEMBERS_ONLY
#define CXTARG_MEMBER_FUNCS_INTERFACE
#include "cxtarg.hxx"
#undef CXTARG_MEMBER_FUNCS_INTERFACE
#undef CXTARG_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXtArgImplement
 *
 * Author: $author$           
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtArgImplement
: virtual public cXtArgInterface
{
public:
    typedef cXtArgInterface cImplements;

/* include cXtArg member functions implement
 */
#define CXTARG_MEMBERS_ONLY
#define CXTARG_MEMBER_FUNCS_IMPLEMENT
#include "cxtarg.hxx"
#undef CXTARG_MEMBER_FUNCS_IMPLEMENT
#undef CXTARG_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTARGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTARGINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTARGINTERFACE_HXX) || defined(CXTARGINTERFACE_MEMBERS_ONLY) */
