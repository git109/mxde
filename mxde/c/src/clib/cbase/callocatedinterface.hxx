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
 *   File: callocatedinterface.hxx
 *
 * Author: $author$
 *   Date: 7/2/2009
 **********************************************************************
 */
#if !defined(_CALLOCATEDINTERFACE_HXX) || defined(ALLOCATEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CALLOCATEDINTERFACE_HXX) && !defined(ALLOCATEDINTERFACE_MEMBERS_ONLY)
#define _CALLOCATEDINTERFACE_HXX
#endif /* !defined(_CALLOCATEDINTERFACE_HXX) && !defined(ALLOCATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CALLOCATEDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cAllocated interface definition
 */
class c_INTERFACE_CLASS cAllocatedInterface;

#undef CDB_CLASS
#define CDB_CLASS "cAllocatedInterfaceT"
/**
 **********************************************************************
 *  Class: cAllocatedInterfaceT
 *
 * Author: $author$
 *   Date: 7/2/2009
 **********************************************************************
 */
template
<class TDerives=cAllocatedInterface,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cAllocatedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CALLOCATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CALLOCATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CALLOCATEDINTERFACE_MEMBERS_ONLY)
/* include cAllocated member functions interface
 */
#define CALLOCATED_MEMBERS_ONLY
#define CALLOCATED_MEMBER_FUNCS_INTERFACE
#include "callocated.hxx"
#undef CALLOCATED_MEMBER_FUNCS_INTERFACE
#undef CALLOCATED_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cAllocated implement definition
 */
class c_IMPLEMENT_CLASS cAllocatedImplement;

#undef CDB_CLASS
#define CDB_CLASS "cAllocatedImplementT"
/**
 **********************************************************************
 *  Class: cAllocatedImplementT
 *
 * Author: $author$
 *   Date: 7/2/2009
 **********************************************************************
 */
template
<class TDerives=cAllocatedImplement,
 class TAllocatedInterface=cAllocatedInterface,
 class TImplements=TAllocatedInterface>

class c_IMPLEMENT_CLASS cAllocatedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;

/* include cAllocated interface member definitions
 */
#define CALLOCATEDINTERFACE_MEMBERS_ONLY
#include "callocatedinterface.hxx"
#undef CALLOCATEDINTERFACE_MEMBERS_ONLY

/* include cAllocated member functions implement
 */
#define CALLOCATED_MEMBERS_ONLY
#define CALLOCATED_MEMBER_FUNCS_IMPLEMENT
#include "callocated.hxx"
#undef CALLOCATED_MEMBER_FUNCS_IMPLEMENT
#undef CALLOCATED_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cAllocatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 7/3/2009
 **********************************************************************
 */
typedef cAllocatedInterfaceT<>
cAllocatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cAllocatedInterface
 *
 * Author: $author$
 *   Date: 7/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cAllocatedInterface
: virtual public cAllocatedInterfaceImplements
{
public:
    typedef cAllocatedInterfaceImplements cImplements;
    typedef cAllocatedInterface cDerives;
};

/**
 **********************************************************************
 * Typedef: cAllocatedImplementImplements
 *
 *  Author: $author$
 *    Date: 7/3/2009
 **********************************************************************
 */
typedef cAllocatedImplementT<>
cAllocatedImplementImplements;
/**
 **********************************************************************
 *  Class: cAllocatedImplement
 *
 * Author: $author$
 *   Date: 7/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cAllocatedImplement
: virtual public cAllocatedImplementImplements
{
public:
    typedef cAllocatedImplementImplements cImplements;
    typedef cAllocatedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CALLOCATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CALLOCATEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CALLOCATEDINTERFACE_HXX) || defined(ALLOCATEDINTERFACE_MEMBERS_ONLY) */
