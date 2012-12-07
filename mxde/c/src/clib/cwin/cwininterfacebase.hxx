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
 *   File: cwininterfacebase.hxx
 *
 * Author: $author$
 *   Date: 1/4/2010
 **********************************************************************
 */
#if !defined(_CWININTERFACEBASE_HXX) || defined(CWININTERFACEBASE_MEMBERS_ONLY)
#if !defined(_CWININTERFACEBASE_HXX) && !defined(CWININTERFACEBASE_MEMBERS_ONLY)
#define _CWININTERFACEBASE_HXX
#endif /* !defined(_CWININTERFACEBASE_HXX) && !defined(CWININTERFACEBASE_MEMBERS_ONLY) */

#if !defined(CWININTERFACEBASE_MEMBERS_ONLY)
#include "cplatform_windows.hxx"
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinInterfaceBase
 *
 * Author: $author$
 *   Date: 1/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinInterfaceBase
{
public:
#else /* !defined(CWININTERFACEBASE_MEMBERS_ONLY) */
#endif /* !defined(CWININTERFACEBASE_MEMBERS_ONLY) */

#if !defined(CWININTERFACEBASE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWININTERFACEBASE_MEMBERS_ONLY) */
#endif /* !defined(CWININTERFACEBASE_MEMBERS_ONLY) */

#endif /* !defined(_CWININTERFACEBASE_HXX) || defined(CWININTERFACEBASE_MEMBERS_ONLY) */
