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
 *   File: ccreatedinterface.hxx
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
#if !defined(_CCREATEDINTERFACE_HXX) || defined(CCREATEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CCREATEDINTERFACE_HXX) && !defined(CCREATEDINTERFACE_MEMBERS_ONLY)
#define _CCREATEDINTERFACE_HXX
#endif /* !defined(_CCREATEDINTERFACE_HXX) && !defined(CCREATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CCREATEDINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cCreated interface definition
 */
class c_INTERFACE_CLASS cCreatedInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCreatedInterfaceT"
/**
 **********************************************************************
 *  Class: cCreatedInterfaceT
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
template
<class TDerives=cCreatedInterface,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cCreatedInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCreatedInterfaceT cDerives;
#else /* !defined(CCREATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCREATEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CCREATEDINTERFACE_MEMBERS_ONLY) 
/* include cCreated member functions interface
 */
#define CCREATED_MEMBERS_ONLY
#define CCREATED_MEMBER_FUNCS_INTERFACE
#include "ccreated.hxx"
#undef CCREATED_MEMBER_FUNCS_INTERFACE
#undef CCREATED_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cCreated implement definition
 */
class c_IMPLEMENT_CLASS  cCreatedImplement;

#undef CDB_CLASS
#define CDB_CLASS "cCreatedImplementT"
/**
 **********************************************************************
 *  Class: cCreatedImplementT
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
template
<class TDerives=cCreatedImplement,
 class TCreatedInterface=cCreatedInterface,
 class TImplements=TCreatedInterface>
 
class c_IMPLEMENT_CLASS  cCreatedImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cCreatedImplementT cDerives;

/* include cCreated interface member definitions
 */
#define CCREATEDINTERFACE_MEMBERS_ONLY
#include "ccreatedinterface.hxx"
#undef CCREATEDINTERFACE_MEMBERS_ONLY

/* include cCreated member functions implement
 */
#define CCREATED_MEMBERS_ONLY
#define CCREATED_MEMBER_FUNCS_IMPLEMENT
#include "ccreated.hxx"
#undef CCREATED_MEMBER_FUNCS_IMPLEMENT
#undef CCREATED_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cCreatedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/4/2009
 **********************************************************************
 */
typedef cCreatedInterfaceT<>
cCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cCreatedInterface
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cCreatedInterface
: virtual public cCreatedInterfaceImplements
{
public:
    typedef cCreatedInterfaceImplements cImplements;
    typedef cCreatedInterface cDerives;
};

/**
 **********************************************************************
 * Typedef: cCreatedImplementImplements
 *
 *  Author: $author$
 *    Date: 5/4/2009
 **********************************************************************
 */
typedef cCreatedImplementT<>
cCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cCreatedImplement
 *
 * Author: $author$
 *   Date: 5/4/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cCreatedImplement
: virtual public cCreatedImplementImplements
{
public:
    typedef cCreatedImplementImplements cImplements;
    typedef cCreatedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCREATEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCREATEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCREATEDINTERFACE_HXX) || defined(CCREATEDINTERFACE_MEMBERS_ONLY) */
