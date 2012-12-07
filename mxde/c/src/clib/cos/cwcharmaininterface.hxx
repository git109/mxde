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
 *   File: cwcharmaininterface.hxx
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
#if !defined(_CWCHARMAININTERFACE_HXX) || defined(CWCHARMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CWCHARMAININTERFACE_HXX) && !defined(CWCHARMAININTERFACE_MEMBERS_ONLY)
#define _CWCHARMAININTERFACE_HXX
#endif /* !defined(_CWCHARMAININTERFACE_HXX) && !defined(CWCHARMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CWCHARMAININTERFACE_MEMBERS_ONLY)
#include "cmaininterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWCHARMainInterface;
/**
 **********************************************************************
 * Typedef: cWCHARMainInterfaceImplement
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cMainInterfaceT
<cWCHARMainInterface,
 cWCHARFileInterface, cWCHARStreamInterface, WCHAR, int>
cWCHARMainInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWCHARMainInterface
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARMainInterface
: virtual public cWCHARMainInterfaceImplement
{
public:
    typedef cWCHARMainInterfaceImplement cImplements;
#else /* !defined(CWCHARMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CWCHARMAININTERFACE_MEMBERS_ONLY)
};

#if !defined(CWCHARMAINIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cWCHARMainImplement;
/**
 **********************************************************************
 * Typedef: cWCHARMainImplementImplement
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cMainImplementT
<cWCHARMainImplement, cWCHARMainInterface,
 cWCHARFileInterface, cWCHARStreamInterface, WCHAR, int>
cWCHARMainImplementImplement;
/**
 **********************************************************************
 *  Class: cWCHARMainImplement
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARMainImplement
: virtual public cWCHARMainImplementImplement
{
public:
    typedef cWCHARMainImplementImplement cImplements;
#else /* !defined(CWCHARMAINIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAINIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWCHARMAINIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWCHARMAINIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAINIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWCHARMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWCHARMAININTERFACE_HXX) || defined(CWCHARMAININTERFACE_MEMBERS_ONLY) */
