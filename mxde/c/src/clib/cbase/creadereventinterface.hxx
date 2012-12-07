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
 *   File: creadereventinterface.hxx
 *
 * Author: $author$
 *   Date: 3/31/2010
 **********************************************************************
 */
#if !defined(_CREADEREVENTINTERFACE_HXX) || defined(CREADEREVENTINTERFACE_MEMBERS_ONLY)
#if !defined(_CREADEREVENTINTERFACE_HXX) && !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY)
#define _CREADEREVENTINTERFACE_HXX
#endif /* !defined(_CREADEREVENTINTERFACE_HXX) && !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY) */

#if !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cReaderEventInterface;

#undef CDB_CLASS
#define CDB_CLASS "cReaderEventInterfaceT"
/**
 **********************************************************************
 *  Class: cReaderEventInterfaceT
 *
 * Author: $author$
 *   Date: 3/31/2010
 **********************************************************************
 */
template
<class TDerives=cReaderEventInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cReaderEventInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY) */

/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY

#if !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY)
/* include cReaderEvent member functions interface
 */
#define CREADEREVENT_MEMBERS_ONLY
#define CREADEREVENT_MEMBER_FUNCS_INTERFACE
#include "creaderevent.hxx"
#undef CREADEREVENT_MEMBER_FUNCS_INTERFACE
#undef CREADEREVENT_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cReaderEventImplement;

/**
 **********************************************************************
 *  Class: cReaderEventImplementT
 *
 * Author: $author$
 *   Date: 3/31/2010
 **********************************************************************
 */
template
<class TDerives=cReaderEventImplement,
 class TReaderEventInterface=cReaderEventInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TReaderEventInterface>

class c_IMPLEMENT_CLASS cReaderEventImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;

/* include cReaderEvent interface member definitions
 */
#define CREADEREVENTINTERFACE_MEMBERS_ONLY
#include "creadereventinterface.hxx"
#undef CREADEREVENTINTERFACE_MEMBERS_ONLY

/* include cReaderEvent member functions implement
 */
#define CREADEREVENT_MEMBERS_ONLY
#define CREADEREVENT_MEMBER_FUNCS_IMPLEMENT
#include "creaderevent.hxx"
#undef CREADEREVENT_MEMBER_FUNCS_IMPLEMENT
#undef CREADEREVENT_MEMBERS_ONLY
};

class c_INTERFACE_CLASS cBYTEReaderEventInterface;
/**
 **********************************************************************
 * Typedef: cBYTEReaderEventInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/1/2010
 **********************************************************************
 */
typedef cReaderEventInterfaceT
<cBYTEReaderEventInterface, BYTE>
cBYTEReaderEventInterfaceImplement;
/**
 **********************************************************************
 *  Class: cBYTEReaderEventInterface
 *
 * Author: $author$
 *   Date: 4/1/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEReaderEventInterface
: public cBYTEReaderEventInterfaceImplement
{
public:
    typedef cBYTEReaderEventInterfaceImplement cExtends;
};
class c_IMPLEMENT_CLASS cBYTEReaderEventImplement;
/**
 **********************************************************************
 * Typedef: cBYTEReaderEventImplementImplement
 *
 *  Author: $author$
 *    Date: 4/1/2010
 **********************************************************************
 */
typedef cReaderEventImplementT
<cBYTEReaderEventImplement, 
 cBYTEReaderEventInterface, BYTE>
cBYTEReaderEventImplementImplement;
/**
 **********************************************************************
 *  Class: cBYTEReaderEventImplement
 *
 * Author: $author$
 *   Date: 4/1/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBYTEReaderEventImplement
: virtual public cBYTEReaderEventImplementImplement
{
public:
    typedef cBYTEReaderEventImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CREADEREVENTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CREADEREVENTINTERFACE_HXX) || defined(CREADEREVENTINTERFACE_MEMBERS_ONLY) */
