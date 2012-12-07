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
 *   File: cdelegatedinterface.hxx
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
#if !defined(_CDELEGATEDINTERFACE_HXX) || defined(CDELEGATEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CDELEGATEDINTERFACE_HXX) && !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY)
#define _CDELEGATEDINTERFACE_HXX
#endif /* !defined(_CDELEGATEDINTERFACE_HXX) && !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cDelegatedInterface;

#undef CDB_CLASS
#define CDB_CLASS "cDelegatedInterface"
/**
 **********************************************************************
 *  Class: cDelegatedInterface
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
template
<class TDerives=cDelegatedInterface,
 class TInterfaceBase=cInterfaceBase,
 class TDelegated=TDerives,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cDelegatedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDelegated tDelegated;
#else /* !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY)
/* include cDelegated member functions interface
 */
#define CDELEGATED_MEMBERS_ONLY
#define CDELEGATED_MEMBER_FUNCS_INTERFACE
#include "cdelegated.hxx"
#undef CDELEGATED_MEMBER_FUNCS_INTERFACE
#undef CDELEGATED_MEMBERS_ONLY
};
#undef CDB_CLASS

#if !defined(CDELEGATEDIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cDelegatedImplement;

#undef CDB_CLASS
#define CDB_CLASS "cDelegatedImplementT"
/**
 **********************************************************************
 *  Class: cDelegatedImplementT
 *
 * Author: $author$
 *   Date: 11/11/2010
 **********************************************************************
 */
template
<class TDerives=cDelegatedImplement,
 class TDelegatedInterface=cDelegatedInterface,
 class TDelegated=TDelegatedInterface,
 class TImplements=TDelegatedInterface>

class c_IMPLEMENT_CLASS cDelegatedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDelegated tDelegated;
#else /* !defined(CDELEGATEDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CDELEGATEDIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CDELEGATEDIMPLEMENT_MEMBERS_ONLY)
/* include cDelegated member functions implement
 */
#define CDELEGATED_MEMBERS_ONLY
#define CDELEGATED_MEMBER_FUNCS_IMPLEMENT
#include "cdelegated.hxx"
#undef CDELEGATED_MEMBER_FUNCS_IMPLEMENT
#undef CDELEGATED_MEMBERS_ONLY
};
#undef CDB_CLASS
#else /* !defined(CDELEGATEDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CDELEGATEDIMPLEMENT_MEMBERS_ONLY) */

/**
 **********************************************************************
 * Typedef: cDelegatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegatedInterfaceT
<cDelegatedInterface>
cDelegatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cDelegatedInterface
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cDelegatedInterface
: virtual public cDelegatedInterfaceImplements
{
public:
    typedef cDelegatedInterfaceImplements cImplements;
    typedef cDelegatedInterface cDerives;
};

/**
 **********************************************************************
 * Typedef: cDelegatedImplementImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cDelegatedImplementT
<cDelegatedImplement, cDelegatedInterface>
cDelegatedImplementImplements;
/**
 **********************************************************************
 *  Class: cDelegatedImplement
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cDelegatedImplement
: virtual public cDelegatedImplementImplements
{
public:
    typedef cDelegatedImplementImplements cImplements;
    typedef cDelegatedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CDELEGATEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CDELEGATEDINTERFACE_HXX) || defined(CDELEGATEDINTERFACE_MEMBERS_ONLY) */
