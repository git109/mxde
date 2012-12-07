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
 *   File: cbufferinterface.hxx
 *
 * Author: $author$
 *   Date: 5/12/2009
 **********************************************************************
 */
#if !defined(_CBUFFERINTERFACE_HXX) || defined(CBUFFERINTERFACE_MEMBERS_ONLY)
#if !defined(_CBUFFERINTERFACE_HXX) && !defined(CBUFFERINTERFACE_MEMBERS_ONLY)
#define _CBUFFERINTERFACE_HXX
#endif /* !defined(_CBUFFERINTERFACE_HXX) && !defined(CBUFFERINTERFACE_MEMBERS_ONLY) */

#if !defined(CBUFFERINTERFACE_MEMBERS_ONLY)
#include "cstoreinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/* cBuffer interface definition
 */
class c_INTERFACE_CLASS cBufferInterface;

#undef CDB_CLASS
#define CDB_CLASS "cBufferInterfaceT"
/**
 **********************************************************************
 *  Class: cBufferInterfaceT
 *
 * Author: $author$
 *   Date: 5/12/2009
 **********************************************************************
 */
template
<class TDerives=cBufferInterface,
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
 
class c_INTERFACE_CLASS cBufferInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tBufferInterface;
#else /* !defined(CBUFFERINTERFACE_MEMBERS_ONLY) */
    typedef TBufferInterface tBufferInterface;
#endif /* !defined(CBUFFERINTERFACE_MEMBERS_ONLY) */

/* include cStore interface member definitions
 */
#define CSTOREINTERFACE_MEMBERS_ONLY
#include "cstoreinterface.hxx"
#undef CSTOREINTERFACE_MEMBERS_ONLY

#if !defined(CBUFFERINTERFACE_MEMBERS_ONLY) 
/* include cBuffer member functions interface
 */
#define CBUFFER_MEMBERS_ONLY
#define CBUFFER_MEMBER_FUNCS_INTERFACE
#include "cbuffer.hxx"
#undef CBUFFER_MEMBER_FUNCS_INTERFACE
#undef CBUFFER_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cBuffer implement definition
 */
class c_IMPLEMENT_CLASS  cBufferImplement;

#undef CDB_CLASS
#define CDB_CLASS "cBufferImplementT"
/**
 **********************************************************************
 *  Class: cBufferImplementT
 *
 * Author: $author$
 *   Date: 5/12/2009
 **********************************************************************
 */
template
<class TDerives=cBufferImplement,
 class TBufferInterface=cBufferInterface,
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
 class TImplements=TBufferInterface>
 
class c_IMPLEMENT_CLASS  cBufferImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cBufferImplementT cDerives;

/* include cBuffer interface member definitions
 */
#define CBUFFERINTERFACE_MEMBERS_ONLY
#include "cbufferinterface.hxx"
#undef CBUFFERINTERFACE_MEMBERS_ONLY

/* include cBuffer member functions implement
 */
#define CBUFFER_MEMBERS_ONLY
#define CBUFFER_MEMBER_FUNCS_IMPLEMENT
#include "cbuffer.hxx"
#undef CBUFFER_MEMBER_FUNCS_IMPLEMENT
#undef CBUFFER_MEMBERS_ONLY
};
#undef CDB_CLASS


/**
 **********************************************************************
 * Typedef: cBufferInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferInterfaceT
<cBufferInterface, cStoreInterface, CHAR>
cBufferInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBufferInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBufferInterface
: virtual public cBufferInterfaceImplements
{
public:
    typedef cBufferInterfaceImplements cImplements;
    typedef cBufferInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cBufferImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferImplementT
<cBufferImplement, cBufferInterface, CHAR>
cBufferImplementImplements;
/**
 **********************************************************************
 *  Class: cBufferImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cBufferImplement
: virtual public cBufferImplementImplements
{
public:
    typedef cBufferImplementImplements cImplements;
    typedef cBufferImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARBufferInterface;
/**
 **********************************************************************
 * Typedef: cTCHARBufferInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferInterfaceT
<cTCHARBufferInterface, cTCHARStoreInterface, TCHAR>
cTCHARBufferInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARBufferInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARBufferInterface
: virtual public cTCHARBufferInterfaceImplements
{
public:
    typedef cTCHARBufferInterfaceImplements cImplements;
    typedef cTCHARBufferInterface cDerives;
};
class c_IMPLEMENT_CLASS  cTCHARBufferImplement;
/**
 **********************************************************************
 * Typedef: cTCHARBufferImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferImplementT
<cTCHARBufferImplement, cTCHARBufferInterface, TCHAR>
cTCHARBufferImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARBufferImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cTCHARBufferImplement
: virtual public cTCHARBufferImplementImplements
{
public:
    typedef cTCHARBufferImplementImplements cImplements;
    typedef cTCHARBufferImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARBufferInterface;
/**
 **********************************************************************
 * Typedef: cWCHARBufferInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferInterfaceT
<cWCHARBufferInterface, cWCHARStoreInterface, WCHAR>
cWCHARBufferInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARBufferInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARBufferInterface
: virtual public cWCHARBufferInterfaceImplements
{
public:
    typedef cWCHARBufferInterfaceImplements cImplements;
    typedef cWCHARBufferInterface cDerives;
};
class c_IMPLEMENT_CLASS  cWCHARBufferImplement;
/**
 **********************************************************************
 * Typedef: cWCHARBufferImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferImplementT
<cWCHARBufferImplement, cWCHARBufferInterface, WCHAR>
cWCHARBufferImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARBufferImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cWCHARBufferImplement
: virtual public cWCHARBufferImplementImplements
{
public:
    typedef cWCHARBufferImplementImplements cImplements;
    typedef cWCHARBufferImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEBufferInterface;
/**
 **********************************************************************
 * Typedef: cBYTEBufferInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferInterfaceT
<cBYTEBufferInterface, cBYTEStoreInterface, BYTE>
cBYTEBufferInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEBufferInterface
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEBufferInterface
: virtual public cBYTEBufferInterfaceImplements
{
public:
    typedef cBYTEBufferInterfaceImplements cImplements;
    typedef cBYTEBufferInterface cDerives;
};
class c_IMPLEMENT_CLASS  cBYTEBufferImplement;
/**
 **********************************************************************
 * Typedef: cBYTEBufferImplementImplements
 *
 *  Author: $author$
 *    Date: 3/19/2009
 **********************************************************************
 */
typedef cBufferImplementT
<cBYTEBufferImplement, cBYTEBufferInterface, BYTE>
cBYTEBufferImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEBufferImplement
 *
 * Author: $author$
 *   Date: 3/19/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cBYTEBufferImplement
: virtual public cBYTEBufferImplementImplements
{
public:
    typedef cBYTEBufferImplementImplements cImplements;
    typedef cBYTEBufferImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBUFFERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBUFFERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CBUFFERINTERFACE_HXX) || defined(CBUFFERINTERFACE_MEMBERS_ONLY) */
