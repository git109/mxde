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
 *   File: cacquiredinterface.hxx
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
#if !defined(_CACQUIREDINTERFACE_HXX) || defined(CACQUIREDINTERFACE_MEMBERS_ONLY)
#if !defined(_CACQUIREDINTERFACE_HXX) && !defined(CACQUIREDINTERFACE_MEMBERS_ONLY)
#define _CACQUIREDINTERFACE_HXX
#endif /* !defined(_CACQUIREDINTERFACE_HXX) && !defined(CACQUIREDINTERFACE_MEMBERS_ONLY) */

#if !defined(CACQUIREDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cAcquired interface definition
 */
class c_INTERFACE_CLASS cAcquiredInterface;

#undef CDB_CLASS
#define CDB_CLASS "cAcquiredInterfaceT"
/**
 **********************************************************************
 *  Class: cAcquiredInterfaceT
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
template
<class TDerives=cAcquiredInterface,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cAcquiredInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cAcquiredInterfaceT cDerives;
#else /* !defined(CACQUIREDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CACQUIREDINTERFACE_MEMBERS_ONLY) */

#if !defined(CACQUIREDINTERFACE_MEMBERS_ONLY) 
/* include cAcquired member functions interface
 */
#define CACQUIRED_MEMBERS_ONLY
#define CACQUIRED_MEMBER_FUNCS_INTERFACE
#include "cacquired.hxx"
#undef CACQUIRED_MEMBER_FUNCS_INTERFACE
#undef CACQUIRED_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cAcquired implement definition
 */
class c_IMPLEMENT_CLASS  cAcquiredImplement;

#undef CDB_CLASS
#define CDB_CLASS "cAcquiredImplementT"
/**
 **********************************************************************
 *  Class: cAcquiredImplementT
 *
 * Author: $author$
 *   Date: 5/26/2009
 **********************************************************************
 */
template
<class TDerives=cAcquiredImplement,
 class TImplements=cAcquiredInterface>
 
class c_IMPLEMENT_CLASS  cAcquiredImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cAcquiredImplementT cDerives;

/* include cAcquired interface member definitions
 */
#define CACQUIREDINTERFACE_MEMBERS_ONLY
#include "cacquiredinterface.hxx"
#undef CACQUIREDINTERFACE_MEMBERS_ONLY

/* include cAcquired member functions implement
 */
#define CACQUIRED_MEMBERS_ONLY
#define CACQUIRED_MEMBER_FUNCS_IMPLEMENT
#include "cacquired.hxx"
#undef CACQUIRED_MEMBER_FUNCS_IMPLEMENT
#undef CACQUIRED_MEMBERS_ONLY
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CACQUIREDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CACQUIREDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CACQUIREDINTERFACE_HXX) || defined(CACQUIREDINTERFACE_MEMBERS_ONLY) */
