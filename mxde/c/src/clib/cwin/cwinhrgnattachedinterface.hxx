/**
 **********************************************************************
 * Copyright (c) 1988-2009 $organization$
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
 *   File: cwinhrgnattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
#if !defined(_CWINHRGNATTACHEDINTERFACE_HXX) || defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINHRGNATTACHEDINTERFACE_HXX) && !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY)
#define _CWINHRGNATTACHEDINTERFACE_HXX
#endif /* !defined(_CWINHRGNATTACHEDINTERFACE_HXX) && !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY)
#include "cwininterfacebase.hxx"
#include "cattachedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWinHRGNAttachedInterface;
/**
 **********************************************************************
 * Typedef: cWinHRGNAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/20/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinHRGNAttachedInterface, 
 HRGN, UINT, NULL, cWinInterfaceBase>
cWinHRGNAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinHRGNAttachedInterface
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinHRGNAttachedInterface
: virtual public cWinHRGNAttachedInterfaceImplements
{
public:
    typedef cWinHRGNAttachedInterfaceImplements cImplements;
    typedef cWinHRGNAttachedInterface cDerives;
#else /* !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY)
/* include cWinHRGNAttached member functions interface
 */
#define CWINHRGNATTACHED_MEMBERS_ONLY
#define CWINHRGNATTACHED_MEMBER_FUNCS_INTERFACE
#include "cwinhrgnattached.hxx"
#undef CWINHRGNATTACHED_MEMBER_FUNCS_INTERFACE
#undef CWINHRGNATTACHED_MEMBERS_ONLY
};
class c_EXPORT_CLASS cWinHRGNAttachedImplement;
/**
 **********************************************************************
 * Typedef: cWinHRGNAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/20/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinHRGNAttachedImplement, 
 cWinHRGNAttachedInterface, 
 HRGN, UINT, NULL>
cWinHRGNAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cWinHRGNAttachedImplement
 *
 * Author: $author$
 *   Date: 5/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinHRGNAttachedImplement
: virtual public cWinHRGNAttachedImplementImplements
{
public:
    typedef cWinHRGNAttachedImplementImplements cImplements;
    typedef cWinHRGNAttachedImplement cDerives;
    
/* include cWinHRGNAttached member functions implement
 */
#define CWINHRGNATTACHED_MEMBERS_ONLY
#define CWINHRGNATTACHED_MEMBER_FUNCS_IMPLEMENT
#include "cwinhrgnattached.hxx"
#undef CWINHRGNATTACHED_MEMBER_FUNCS_IMPLEMENT
#undef CWINHRGNATTACHED_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINHRGNATTACHEDINTERFACE_HXX) || defined(CWINHRGNATTACHEDINTERFACE_MEMBERS_ONLY) */
