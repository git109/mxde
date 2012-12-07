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
 *   File: cpngstructinterface.hxx
 *
 * Author: $author$
 *   Date: 6/13/2009
 **********************************************************************
 */
#if !defined(_CPNGSTRUCTINTERFACE_HXX) || defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGSTRUCTINTERFACE_HXX) && !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY)
#define _CPNGSTRUCTINTERFACE_HXX
#endif /* !defined(_CPNGSTRUCTINTERFACE_HXX) && !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY)
#include "cpngstructattached.hxx"
#include "ccreatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cPngStructInterface;
/**
 **********************************************************************
 * Typedef: cPngStructInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/11/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cPngStructInterface, cPngStructAttachedInterface>
cPngStructInterfaceImplements;
/**
 **********************************************************************
 *  Class: cPngStructInterface
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngStructInterface
: virtual public cPngStructInterfaceImplements
{
public:
    typedef cPngStructInterfaceImplements cImplements;
    typedef cPngStructInterface cDerives;
#else /* !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) 
/* include cPngStruct member functions interface
 */
#define CPNGSTRUCT_MEMBERS_ONLY
#define CPNGSTRUCT_MEMBER_FUNCS_INTERFACE
#include "cpngstruct.hxx"
#undef CPNGSTRUCT_MEMBER_FUNCS_INTERFACE
#undef CPNGSTRUCT_MEMBERS_ONLY
};
class c_IMPLEMENT_CLASS cPngStructImplement;
/**
 **********************************************************************
 * Typedef: cPngStructImplementImplements
 *
 *  Author: $author$
 *    Date: 6/11/2009
 **********************************************************************
 */
typedef cCreatedImplementT
<cPngStructImplement, cPngStructInterface>
cPngStructImplementImplements;
/**
 **********************************************************************
 *  Class: cPngStructImplement
 *
 * Author: $author$
 *   Date: 6/11/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPngStructImplement
: virtual public cPngStructImplementImplements
{
public:
    typedef cPngStructImplementImplements cImplements;
    typedef cPngStructImplement cDerives;

/* include cPngStruct member functions implement
 */
#define CPNGSTRUCT_MEMBERS_ONLY
#define CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT
#include "cpngstruct.hxx"
#undef CPNGSTRUCT_MEMBER_FUNCS_IMPLEMENT
#undef CPNGSTRUCT_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGSTRUCTINTERFACE_HXX) || defined(CPNGSTRUCTINTERFACE_MEMBERS_ONLY) */
