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
 *   File: cpnginfointerface.hxx
 *
 * Author: $author$
 *   Date: 6/14/2009
 **********************************************************************
 */
#if !defined(_CPNGINFOINTERFACE_HXX) || defined(CPNGINFOINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGINFOINTERFACE_HXX) && !defined(CPNGINFOINTERFACE_MEMBERS_ONLY)
#define _CPNGINFOINTERFACE_HXX
#endif /* !defined(_CPNGINFOINTERFACE_HXX) && !defined(CPNGINFOINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGINFOINTERFACE_MEMBERS_ONLY)
#include "cpnginfoattached.hxx"
#include "cpngstructinterface.hxx"
#include "ccreatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngInfoInterface;
/**
 **********************************************************************
 * Typedef: cPngInfoInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cPngInfoInterface, cPngInfoAttachedInterface>
cPngInfoInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngInfoInterface
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInfoInterface
: virtual public cPngInfoInterfaceImplements
{
public:
    typedef cPngInfoInterfaceImplements cImplements;
    typedef cPngInfoInterface cDerives;
#else /* !defined(CPNGINFOINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGINFOINTERFACE_MEMBERS_ONLY) 
/* include cPngInfo member functions interface
 */
#define CPNGINFO_MEMBERS_ONLY
#define CPNGINFO_MEMBER_FUNCS_INTERFACE
#include "cpnginfo.hxx"
#undef CPNGINFO_MEMBER_FUNCS_INTERFACE
#undef CPNGINFO_MEMBERS_ONLY
};
class c_EXPORT_CLASS cPngInfoImplement;
/**
 **********************************************************************
 * Typedef: cPngInfoImplementImplements
 *
 *  Author: $author$
 *    Date: 6/10/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cPngInfoImplement, cPngInfoInterface>
cPngInfoImplementImplements;
/**
 **********************************************************************
 *  Class: cPngInfoImplement
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cPngInfoImplement
: virtual public cPngInfoImplementImplements
{
public:
    typedef cPngInfoImplementImplements cImplements;
    typedef cPngInfoImplement cDerives;

/* include cPngInfo member functions implement
 */
#define CPNGINFO_MEMBERS_ONLY
#define CPNGINFO_MEMBER_FUNCS_IMPLEMENT
#include "cpnginfo.hxx"
#undef CPNGINFO_MEMBER_FUNCS_IMPLEMENT
#undef CPNGINFO_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINFO_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFO_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFO_HXX) || defined(CPNGINFO_MEMBERS_ONLY) */
