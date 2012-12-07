/**
 **********************************************************************
 * Copyright (c) 1988-2011 $organization$
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
 *   File: coptmaininterface.hxx
 *
 * Author: $author$
 *   Date: 2/21/2011
 **********************************************************************
 */
#if !defined(_COPTMAININTERFACE_HXX) || defined(COPTMAININTERFACE_MEMBERS_ONLY)
#if !defined(_COPTMAININTERFACE_HXX) && !defined(COPTMAININTERFACE_MEMBERS_ONLY)
#define _COPTMAININTERFACE_HXX
#endif /* !defined(_COPTMAININTERFACE_HXX) && !defined(COPTMAININTERFACE_MEMBERS_ONLY) */

#if !defined(COPTMAININTERFACE_MEMBERS_ONLY)
#include "cmaininterface.hxx"
#include <getopt.h>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cOptMainInterfaceImplement
 *
 *  Author: $author$
 *    Date: 2/21/2011
 **********************************************************************
 */
typedef cMainInterface
cOptMainInterfaceImplement;
/**
 **********************************************************************
 *  Class: cOptMainInterface
 *
 * Author: $author$
 *   Date: 2/21/2011
 **********************************************************************
 */
class c_INTERFACE_CLASS cOptMainInterface
: virtual public cOptMainInterfaceImplement
{
public:
    typedef cOptMainInterfaceImplement cImplements;
#else /* !defined(COPTMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(COPTMAININTERFACE_MEMBERS_ONLY) */

#if !defined(COPTMAININTERFACE_MEMBERS_ONLY)
};

#if !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cOptMainImplement
 *
 * Author: $author$
 *   Date: 2/21/2011
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cOptMainImplement
: virtual public cOptMainInterface
{
public:
    typedef cOptMainInterface cImplements;
#else /* !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) */

#if !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(COPTMAINIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(COPTMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(COPTMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_COPTMAININTERFACE_HXX) || defined(COPTMAININTERFACE_MEMBERS_ONLY) */
