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
 *   File: cxtcallbackinterface.hxx
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
#if !defined(_CXTCALLBACKINTERFACE_HXX) || defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTCALLBACKINTERFACE_HXX) && !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY)
#define _CXTCALLBACKINTERFACE_HXX
#endif /* !defined(_CXTCALLBACKINTERFACE_HXX) && !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY)
#include "cxtbaseinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCallbackInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 5/19/2010
 **********************************************************************
 */
typedef cXtBaseInterface
cXtCallbackInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtCallbackInterface
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtCallbackInterface
: virtual public cXtCallbackInterfaceImplement
{
public:
    typedef cXtCallbackInterfaceImplement cImplements;
#else /* !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY)
/* include cXtCallback member functions interface
 */
#define CXTCALLBACK_MEMBERS_ONLY
#define CXTCALLBACK_MEMBER_FUNCS_INTERFACE
#include "cxtcallback.hxx"
#undef CXTCALLBACK_MEMBER_FUNCS_INTERFACE
#undef CXTCALLBACK_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXtCallbackImplement
 *
 * Author: $author$           
 *   Date: 5/19/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtCallbackImplement
: virtual public cXtCallbackInterface
{
public:
    typedef cXtCallbackInterface cImplements;

/* include cXtCallback member functions implement
 */
#define CXTCALLBACK_MEMBERS_ONLY
#define CXTCALLBACK_MEMBER_FUNCS_IMPLEMENT
#include "cxtcallback.hxx"
#undef CXTCALLBACK_MEMBER_FUNCS_IMPLEMENT
#undef CXTCALLBACK_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTCALLBACKINTERFACE_HXX) || defined(CXTCALLBACKINTERFACE_MEMBERS_ONLY) */
