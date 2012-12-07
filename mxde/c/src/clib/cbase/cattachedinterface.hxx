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
 *   File: cattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
#if !defined(_CATTACHEDINTERFACE_HXX) || defined(CATTACHEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CATTACHEDINTERFACE_HXX) && !defined(CATTACHEDINTERFACE_MEMBERS_ONLY)
#define _CATTACHEDINTERFACE_HXX
#endif /* !defined(_CATTACHEDINTERFACE_HXX) && !defined(CATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CATTACHEDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cAttached interface definition
 */
class c_INTERFACE_CLASS cAttachedInterface;

#undef CDB_CLASS
#define CDB_CLASS "cAttachedInterfaceT"
/**
 **********************************************************************
 *  Class: cAttachedInterfaceT
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
template
<class TDerives=cAttachedInterface,
 class TAttachedTo=PVOID,
 class TUnattached=INT,
 TUnattached VUnattached=0,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cAttachedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
#else /* !defined(CATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CATTACHEDINTERFACE_MEMBERS_ONLY) */
 
    typedef TAttachedTo tAttachedTo;
    typedef TUnattached tUnattached;
    enum { vUnattached = VUnattached };

#if !defined(CATTACHEDINTERFACE_MEMBERS_ONLY) 
/* include cAttached member functions interface
 */
#define CATTACHED_MEMBERS_ONLY
#define CATTACHED_MEMBER_FUNCS_INTERFACE
#include "cattached.hxx"
#undef CATTACHED_MEMBER_FUNCS_INTERFACE
#undef CATTACHED_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cAttached implement definition
 */
class c_IMPLEMENT_CLASS cAttachedImplement;

#undef CDB_CLASS
#define CDB_CLASS "cAttachedImplementT"
/**
 **********************************************************************
 *  Class: cAttachedImplementT
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
template
<class TDerives=cAttachedImplement,
 class TAttachedInterface=cAttachedInterface,
 class TAttachedTo=PVOID,
 class TUnattached=INT,
 TUnattached VUnattached=0,
 class TImplements=TAttachedInterface>
 
class c_IMPLEMENT_CLASS cAttachedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;

/* include cAttached interface member definitions
 */
#define CATTACHEDINTERFACE_MEMBERS_ONLY
#include "cattachedinterface.hxx"
#undef CATTACHEDINTERFACE_MEMBERS_ONLY

/* include cAttached member functions implement
 */
#define CATTACHED_MEMBERS_ONLY
#define CATTACHED_MEMBER_FUNCS_IMPLEMENT
#include "cattached.hxx"
#undef CATTACHED_MEMBER_FUNCS_IMPLEMENT
#undef CATTACHED_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/6/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cAttachedInterface, cAttachedInterface*>
cAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cAttachedInterface
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cAttachedInterface
: virtual public cAttachedInterfaceImplements
{
public:
    typedef cAttachedInterfaceImplements cImplements;
    typedef cAttachedInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/6/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cAttachedImplement, cAttachedInterface, cAttachedInterface*>
cAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cAttachedImplement
 *
 * Author: $author$
 *   Date: 5/6/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cAttachedImplement
: virtual public cAttachedImplementImplements
{
public:
    typedef cAttachedImplementImplements cImplements;
    typedef cAttachedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CATTACHEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CATTACHEDINTERFACE_HXX) || defined(CATTACHEDINTERFACE_MEMBERS_ONLY) */
