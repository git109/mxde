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
 *   File: cnamevalueeventinterface.hxx
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
#if !defined(_CNAMEVALUEEVENTINTERFACE_HXX) || defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY)
#if !defined(_CNAMEVALUEEVENTINTERFACE_HXX) && !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY)
#define _CNAMEVALUEEVENTINTERFACE_HXX
#endif /* !defined(_CNAMEVALUEEVENTINTERFACE_HXX) && !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY) */

#if !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY)
/* cNameValueEvent interface definition
 */
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cNameValueEventInterface;

#undef CDB_CLASS
#define CDB_CLASS "cNameValueEventInterfaceT"
/**
 **********************************************************************
 *  Class: cNameValueEventInterfaceT
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
template
<class TDerives=cNameValueEventInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cNameValueEventInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tNameValueEventInterface;
#else /* !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY) */
    typedef TNameValueEventInterface tNameValueEventInterface;
#endif /* !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY) */

/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

#if !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY)
/* include cNameValueEvent member functions interface
 */
#define CNAMEVALUEEVENT_MEMBERS_ONLY
#define CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE
#include "cnamevalueevent.hxx"
#undef CNAMEVALUEEVENT_MEMBER_FUNCS_INTERFACE
#undef CNAMEVALUEEVENT_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cNameValueEvent implement definition
 */
class c_IMPLEMENT_CLASS  cNameValueEventImplement;

#undef CDB_CLASS
#define CDB_CLASS "cNameValueEventImplementT"
/**
 **********************************************************************
 *  Class: cNameValueEventImplementT
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
template
<class TDerives=cNameValueEventImplement,
 class TNameValueEventInterface=cNameValueEventInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TNameValueEventInterface>
 
class c_IMPLEMENT_CLASS  cNameValueEventImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;

/* include cNameValueEvent interface member definitions
 */
#define CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY
#include "cnamevalueeventinterface.hxx"
#undef CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY

/* include cNameValueEvent member functions implement
 */
#define CNAMEVALUEEVENT_MEMBERS_ONLY
#define CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT
#include "cnamevalueevent.hxx"
#undef CNAMEVALUEEVENT_MEMBER_FUNCS_IMPLEMENT
#undef CNAMEVALUEEVENT_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cNameValueEventInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/22/2009
 **********************************************************************
 */
typedef cNameValueEventInterfaceT
<cNameValueEventInterface,CHAR>
cNameValueEventInterfaceImplements;
/**
 **********************************************************************
 *  Class: cNameValueEventInterface
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cNameValueEventInterface
: virtual public cNameValueEventInterfaceImplements
{
public:
    typedef cNameValueEventInterfaceImplements cImplements;
    typedef cNameValueEventInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cNameValueEventImplementImplements
 *
 *  Author: $author$
 *    Date: 3/22/2009
 **********************************************************************
 */
typedef cNameValueEventImplementT
<cNameValueEventImplement, cNameValueEventInterface, CHAR>
cNameValueEventImplementImplements;
/**
 **********************************************************************
 *  Class: cNameValueEventImplement
 *
 * Author: $author$
 *   Date: 3/22/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cNameValueEventImplement
: virtual public cNameValueEventImplementImplements
{
public:
    typedef cNameValueEventImplementImplements cImplements;
    typedef cNameValueEventImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CNAMEVALUEEVENTINTERFACE_HXX) || defined(CNAMEVALUEEVENTINTERFACE_MEMBERS_ONLY) */
