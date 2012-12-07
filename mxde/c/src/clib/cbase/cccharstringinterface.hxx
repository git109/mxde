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
 *   File: cccharstringinterface.hxx
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
#if !defined(_CCCHARSTRINGINTERFACE_HXX) || defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY)
#if !defined(_CCCHARSTRINGINTERFACE_HXX) && !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY)
#define _CCCHARSTRINGINTERFACE_HXX
#endif /* !defined(_CCCHARSTRINGINTERFACE_HXX) && !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY) */

#if !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY)
#include "cstringbaseinterface.hxx"
#include "cstringinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: ccCharStringInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cStringInterfaceT<>
ccCharStringInterfaceImplement;
/**
 **********************************************************************
 *  Class: ccCharStringInterface
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS ccCharStringInterface
: virtual public ccCharStringInterfaceImplement
{
public:
    typedef ccCharStringInterfaceImplement cImplements;
#else /* !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY) */

#if !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCCHARSTRINGINTERFACE_HXX) || defined(CCCHARSTRINGINTERFACE_MEMBERS_ONLY) */
