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
 *   File: cwcharargmaininterface.hxx
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
#if !defined(_CWCHARARGMAININTERFACE_HXX) || defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CWCHARARGMAININTERFACE_HXX) && !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY)
#define _CWCHARARGMAININTERFACE_HXX
#endif /* !defined(_CWCHARARGMAININTERFACE_HXX) && !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY)
#include "cargmaininterface.hxx"
#include "cwcharmaininterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWCHARArgMainInterface;
/**
 **********************************************************************
 * Typedef: cWCHARArgMainInterfaceImplement
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cArgMainInterfaceT
<cWCHARArgMainInterface, cWCHARMainInterface, 
 cWCHARFileInterface, cWCHARStreamInterface, WCHAR, int>
cWCHARArgMainInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWCHARArgMainInterface
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARArgMainInterface
: virtual public cWCHARArgMainInterfaceImplement
{
public:
    typedef cWCHARArgMainInterfaceImplement cImplements;
#else /* !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY)
};

#if !defined(CWCHARARGMAINIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cWCHARArgMainImplement;
/**
 **********************************************************************
 * Typedef: cWCHARArgMainImplementImplement
 *
 *  Author: $author$
 *    Date: 8/7/2010
 **********************************************************************
 */
typedef cArgMainImplementT
<cWCHARArgMainImplement, cWCHARArgMainInterface, 
 cWCHARFileInterface, cWCHARStreamInterface, WCHAR, int>
cWCHARArgMainImplementImplement;
/**
 **********************************************************************
 *  Class: cWCHARArgMainImplement
 *
 * Author: $author$
 *   Date: 8/7/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARArgMainImplement
: virtual public cWCHARArgMainImplementImplement
{
public:
    typedef cWCHARArgMainImplementImplement cImplements;
#else /* !defined(CWCHARARGMAINIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWCHARARGMAINIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWCHARARGMAINIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWCHARARGMAINIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWCHARARGMAINIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWCHARARGMAININTERFACE_HXX) || defined(CWCHARARGMAININTERFACE_MEMBERS_ONLY) */
