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
 *   File: cstoreinterface.hxx
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
#if !defined(_CSTOREINTERFACE_HXX) || defined(CSTOREINTERFACE_MEMBERS_ONLY)
#if !defined(_CSTOREINTERFACE_HXX) && !defined(CSTOREINTERFACE_MEMBERS_ONLY)
#define _CSTOREINTERFACE_HXX
#endif /* !defined(_CSTOREINTERFACE_HXX) && !defined(CSTOREINTERFACE_MEMBERS_ONLY) */

#if !defined(CSTOREINTERFACE_MEMBERS_ONLY)
#include "cplatform_stdio.h"
#include "cstreaminterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cStoreInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStoreInterfaceT"
/**
 **********************************************************************
 *  Class: cStoreInterfaceT
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
template
<class TDerives=cStoreInterface,
 class TStreamInterface=cStreamInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TStreamInterface>
 
class c_INTERFACE_CLASS cStoreInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cStoreInterfaceT cDerives;
#else /* !defined(CSTOREINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTOREINTERFACE_MEMBERS_ONLY) */

/* include cStream interface member definitions
 */
#define CSTREAMINTERFACE_MEMBERS_ONLY
#include "cstreaminterface.hxx"
#undef CSTREAMINTERFACE_MEMBERS_ONLY

    typedef TWhence tWhence;
    enum { vWhenceCurrent = VWhenceCurrent};
    enum { vWhenceBegin = VWhenceBegin};
    enum { vWhenceEnd = VWhenceEnd};

#if !defined(CSTOREINTERFACE_MEMBERS_ONLY)
/* include cStore member functions interface
 */
#define CSTORE_MEMBERS_ONLY
#define CSTORE_MEMBER_FUNCS_INTERFACE
#include "cstore.hxx"
#undef CSTORE_MEMBER_FUNCS_INTERFACE
#undef CSTORE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS  cStoreImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStoreImplementT"
/**
 **********************************************************************
 *  Class: cStoreImplementT
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
template
<class TDerives=cStoreImplement,
 class TStoreInterface=cStoreInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TStoreInterface>
 
class c_IMPLEMENT_CLASS  cStoreImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cStoreImplementT cDerives;

/* include cStore interface member definitions
 */
#define CSTOREINTERFACE_MEMBERS_ONLY
#include "cstoreinterface.hxx"
#undef CSTOREINTERFACE_MEMBERS_ONLY

/* include cStore member functions implement
 */
#define CSTORE_MEMBERS_ONLY
#define CSTORE_MEMBER_FUNCS_IMPLEMENT
#include "cstore.hxx"
#undef CSTORE_MEMBER_FUNCS_IMPLEMENT
#undef CSTORE_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INTERFACE_CLASS cStoreInterface;
/**
 **********************************************************************
 * Typedef: cStoreInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreInterfaceT
<cStoreInterface, cStreamInterface, CHAR>
cStoreInterfaceImplements;
/**
 **********************************************************************
 *  Class: cStoreInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStoreInterface
: virtual public cStoreInterfaceImplements
{
public:
    typedef cStoreInterfaceImplements cImplements;
    typedef cStoreInterface cDerives;
};
class c_IMPLEMENT_CLASS  cStoreImplement;
/**
 **********************************************************************
 * Typedef: cStoreImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreImplementT
<cStoreImplement, cStoreInterface,
 cStreamInterface, CHAR>
cStoreImplementImplements;
/**
 **********************************************************************
 *  Class: cStoreImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cStoreImplement
: virtual public cStoreImplementImplements
{
public:
    typedef cStoreImplementImplements cImplements;
    typedef cStoreImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARStoreInterface;
/**
 **********************************************************************
 * Typedef: cTCHARStoreInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreInterfaceT
<cTCHARStoreInterface, cTCHARStreamInterface, TCHAR>
cTCHARStoreInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARStoreInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARStoreInterface
: virtual public cTCHARStoreInterfaceImplements
{
public:
    typedef cTCHARStoreInterfaceImplements cImplements;
    typedef cTCHARStoreInterface cDerives;
};
class c_IMPLEMENT_CLASS  cTCHARStoreImplement;
/**
 **********************************************************************
 * Typedef: cTCHARStoreImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreImplementT
<cTCHARStoreImplement, cTCHARStoreInterface,
 cTCHARStreamInterface, TCHAR>
cTCHARStoreImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARStoreImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cTCHARStoreImplement
: virtual public cTCHARStoreImplementImplements
{
public:
    typedef cTCHARStoreImplementImplements cImplements;
    typedef cTCHARStoreImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARStoreInterface;
/**
 **********************************************************************
 * Typedef: cWCHARStoreInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreInterfaceT
<cWCHARStoreInterface, cWCHARStreamInterface, WCHAR>
cWCHARStoreInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARStoreInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARStoreInterface
: virtual public cWCHARStoreInterfaceImplements
{
public:
    typedef cWCHARStoreInterfaceImplements cImplements;
    typedef cWCHARStoreInterface cDerives;
};
class c_IMPLEMENT_CLASS  cWCHARStoreImplement;
/**
 **********************************************************************
 * Typedef: cWCHARStoreImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreImplementT
<cWCHARStoreImplement, cWCHARStoreInterface,
 cWCHARStreamInterface, WCHAR>
cWCHARStoreImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARStoreImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cWCHARStoreImplement
: virtual public cWCHARStoreImplementImplements
{
public:
    typedef cWCHARStoreImplementImplements cImplements;
    typedef cWCHARStoreImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEStoreInterface;
/**
 **********************************************************************
 * Typedef: cBYTEStoreInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreInterfaceT
<cBYTEStoreInterface, cBYTEStreamInterface, BYTE>
cBYTEStoreInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEStoreInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStoreInterface
: virtual public cBYTEStoreInterfaceImplements
{
public:
    typedef cBYTEStoreInterfaceImplements cImplements;
    typedef cBYTEStoreInterface cDerives;
};
class c_IMPLEMENT_CLASS  cBYTEStoreImplement;
/**
 **********************************************************************
 * Typedef: cBYTEStoreImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cStoreImplementT
<cBYTEStoreImplement, cBYTEStoreInterface,
 cBYTEStreamInterface, BYTE>
cBYTEStoreImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEStoreImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cBYTEStoreImplement
: virtual public cBYTEStoreImplementImplements
{
public:
    typedef cBYTEStoreImplementImplements cImplements;
    typedef cBYTEStoreImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTOREINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTOREINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSTOREINTERFACE_HXX) || defined(CSTOREINTERFACE_MEMBERS_ONLY) */
