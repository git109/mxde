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
 *   File: cxtarglistinterface.hxx
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
#if !defined(_CXTARGLISTINTERFACE_HXX) || defined(CXTARGLISTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTARGLISTINTERFACE_HXX) && !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY)
#define _CXTARGLISTINTERFACE_HXX
#endif /* !defined(_CXTARGLISTINTERFACE_HXX) && !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY)
#include "cxtarginterface.hxx"
#include "cxtbaseinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtArgListInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/25/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXtArgListInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtArgListInterface
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtArgListInterface
: virtual public cXtArgListInterfaceImplement
{
public:
    typedef cXtArgListInterfaceImplement cImplements;
#else /* !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY)
/* include cXtArgList member functions interface
 */
#define CXTARGLIST_MEMBERS_ONLY
#define CXTARGLIST_MEMBER_FUNCS_INTERFACE
#include "cxtarglist.hxx"
#undef CXTARGLIST_MEMBER_FUNCS_INTERFACE
#undef CXTARGLIST_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXtArgListImplement
 *
 * Author: $author$           
 *   Date: 4/25/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtArgListImplement
: virtual public cXtArgListInterface
{
public:
    typedef cXtArgListInterface cImplements;

/* include cXtArgList member functions implement
 */
#define CXTARGLIST_MEMBERS_ONLY
#define CXTARGLIST_MEMBER_FUNCS_IMPLEMENT
#include "cxtarglist.hxx"
#undef CXTARGLIST_MEMBER_FUNCS_IMPLEMENT
#undef CXTARGLIST_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTARGLISTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTARGLISTINTERFACE_HXX) || defined(CXTARGLISTINTERFACE_MEMBERS_ONLY) */
