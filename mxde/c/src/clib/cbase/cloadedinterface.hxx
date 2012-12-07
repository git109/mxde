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
 *   File: cloadedinterface.hxx
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
#if !defined(_CLOADEDINTERFACE_HXX) || defined(CLOADEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CLOADEDINTERFACE_HXX) && !defined(CLOADEDINTERFACE_MEMBERS_ONLY)
#define _CLOADEDINTERFACE_HXX
#endif /* !defined(_CLOADEDINTERFACE_HXX) && !defined(CLOADEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CLOADEDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum: 
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
enum
{
    e_PREV_ERROR_LOAD = e_LAST_ERROR,

    e_ERROR_LOAD,
    e_ERROR_UNLOAD,
    e_ERROR_NOT_LOADED,
    e_ERROR_ALREADY_LOADED,
};

class c_INTERFACE_CLASS cLoadedInterface;
#undef CDB_CLASS
#define CDB_CLASS "cLoadedInterfaceT"
/**
 **********************************************************************
 *  Class: cLoadedInterfaceT
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
template
<class TDerives=cLoadedInterface,
 class TInterfaceBase=cInterfaceBase,
 class TBool=bool,
 TBool VTrue=true,
 TBool VFalse=false,
 class TInt=int,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cLoadedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CLOADEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CLOADEDINTERFACE_MEMBERS_ONLY) */

typedef TInt tInt;
typedef TBool tBool;
enum { vTrue = VTrue, vFalse = VFalse };

#if !defined(CLOADEDINTERFACE_MEMBERS_ONLY)
/* include cLoaded member functions interface
 */
#define CLOADED_MEMBERS_ONLY
#define CLOADED_MEMBER_FUNCS_INTERFACE
#include "cloaded.hxx"
#undef CLOADED_MEMBER_FUNCS_INTERFACE
#undef CLOADED_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CLOADEDIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cLoadedImplement;
#undef CDB_CLASS
#define CDB_CLASS "cLoadedImplementT"
/**
 **********************************************************************
 *  Class: cLoadedImplementT
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
template
<class TDerives=cLoadedImplement,
 class TLoadedInterface=cLoadedInterface,
 class TBool=bool,
 TBool VTrue=true,
 TBool VFalse=false,
 class TInt=int,
 class TImplements=TLoadedInterface>

class c_IMPLEMENT_CLASS cLoadedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CLOADEDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CLOADEDIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CLOADEDIMPLEMENT_MEMBERS_ONLY)
/* include cLoaded interface member definitions
 */
#define CLOADEDINTERFACE_MEMBERS_ONLY
#include "cloadedinterface.hxx"
#undef CLOADEDINTERFACE_MEMBERS_ONLY

/* include cLoaded member functions implement
 */
#define CLOADED_MEMBERS_ONLY
#define CLOADED_MEMBER_FUNCS_IMPLEMENT
#include "cloaded.hxx"
#undef CLOADED_MEMBER_FUNCS_IMPLEMENT
#undef CLOADED_MEMBERS_ONLY
};
#undef CDB_CLASS
#else /* !defined(CLOADEDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CLOADEDIMPLEMENT_MEMBERS_ONLY) */

/**
 **********************************************************************
 * Typedef: cLoadedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cLoadedInterfaceT<>
cLoadedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cLoadedInterface
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cLoadedInterface
: virtual public cLoadedInterfaceImplements
{
public:
    typedef cLoadedInterfaceImplements cImplements;
    typedef cLoadedInterface cDerives;
};

/**
 **********************************************************************
 * Typedef: cLoadedImplementImplements
 *
 *  Author: $author$
 *    Date: 6/14/2010
 **********************************************************************
 */
typedef cLoadedImplementT<>
cLoadedImplementImplements;
/**
 **********************************************************************
 *  Class: cLoadedImplement
 *
 * Author: $author$
 *   Date: 6/14/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cLoadedImplement
: virtual public cLoadedImplementImplements
{
public:
    typedef cLoadedImplementImplements cImplements;
    typedef cLoadedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CLOADEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CLOADEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CLOADEDINTERFACE_HXX) || defined(CLOADEDINTERFACE_MEMBERS_ONLY) */
