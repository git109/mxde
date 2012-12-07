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
 *   File: cstringbaseinterface.hxx
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
#if !defined(_CSTRINGBASEINTERFACE_HXX) || defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CSTRINGBASEINTERFACE_HXX) && !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY)
#define _CSTRINGBASEINTERFACE_HXX
#endif /* !defined(_CSTRINGBASEINTERFACE_HXX) && !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"
#include "cchar.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cStringBaseInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStringBaseInterfaceT"
/**
 **********************************************************************
 *  Class: cStringBaseInterfaceT
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
template
<class TDerives=cStringBaseInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cStringBaseInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY) */

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vUndefinedLength = VUndefinedLength};
    enum { vEndChar = VEndChar};

    typedef tChar tWhat;
    enum { vEndWhat = vEndChar};

#if !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY)
/* include cStringBase member functions interface
 */
#define CSTRINGBASE_MEMBERS_ONLY
#define CSTRINGBASE_MEMBER_FUNCS_INTERFACE
#include "cstringbase.hxx"
#undef CSTRINGBASE_MEMBER_FUNCS_INTERFACE
#undef CSTRINGBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cStringBaseImplement;
/**
 **********************************************************************
 *  Class: cStringBaseImplementT
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
template
<class TDerives=cStringBaseImplement,
 class TStringBaseInterface=cStringBaseInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TStringBaseInterface>

class c_IMPLEMENT_CLASS cStringBaseImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;

/* include cStringBase interface member definitions
 */
#define CSTRINGBASEINTERFACE_MEMBERS_ONLY
#include "cstringbaseinterface.hxx"
#undef CSTRINGBASEINTERFACE_MEMBERS_ONLY

/* include cStringBase member functions implement
 */
#define CSTRINGBASE_MEMBERS_ONLY
#define CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT
#include "cstringbase.hxx"
#undef CSTRINGBASE_MEMBER_FUNCS_IMPLEMENT
#undef CSTRINGBASE_MEMBERS_ONLY
};

/*
 * CHAR
 */
 
class c_INTERFACE_CLASS cStringBaseInterface;
/**
 **********************************************************************
 * Typedef: cStringBaseInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/24/2010
 **********************************************************************
 */
typedef cStringBaseInterfaceT
<cStringBaseInterface, CHAR, CHAR>
cStringBaseInterfaceImplement;
/**
 **********************************************************************
 *  Class: cStringBaseInterface
 *
 * Author: $author$
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cStringBaseInterface
: virtual public cStringBaseInterfaceImplement
{
public:
    typedef cStringBaseInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cStringBaseImplement;
/**
 **********************************************************************
 * Typedef: cStringBaseImplementImplement
 *
 *  Author: $author$
 *    Date: 4/24/2010
 **********************************************************************
 */
typedef cStringBaseImplementT
<cStringBaseImplement, 
 cStringBaseInterface, CHAR, CHAR>
cStringBaseImplementImplement;
/**
 **********************************************************************
 *  Class: cStringBaseImplement
 *
 * Author: $author$
 *   Date: 4/24/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cStringBaseImplement
: virtual public cStringBaseImplementImplement
{
public:
    typedef cStringBaseImplementImplement cImplements;
};

/*
 * TCHAR
 */
 
#if !defined(CTCHARSTRINGBASEINTERFACE_MEMBERS_ONLY)
class c_INTERFACE_CLASS cTCHARStringBaseInterface;
/**
 **********************************************************************
 * Typedef: cTCHARStringBaseInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cStringBaseInterfaceT
<cTCHARStringBaseInterface, TCHAR, TCHAR>
cTCHARStringBaseInterfaceImplement;
/**
 **********************************************************************
 *  Class: cTCHARStringBaseInterface
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARStringBaseInterface
: virtual public cTCHARStringBaseInterfaceImplement
{
public:
    typedef cTCHARStringBaseInterfaceImplement cImplements;
#else /* !defined(CTCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CTCHARSTRINGBASEINTERFACE_MEMBERS_ONLY)
};
#else /* !defined(CTCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CTCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cTCHARStringBaseImplement;
/**
 **********************************************************************
 * Typedef: cTCHARStringBaseImplementImplement
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cStringBaseImplementT
<cTCHARStringBaseImplement, 
 cTCHARStringBaseInterface, TCHAR, TCHAR>
cTCHARStringBaseImplementImplement;
/**
 **********************************************************************
 *  Class: cTCHARStringBaseImplement
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTCHARStringBaseImplement
: virtual public cTCHARStringBaseImplementImplement
{
public:
    typedef cTCHARStringBaseImplementImplement cImplements;
#else /* !defined(CTCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CTCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CTCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */

/*
 * WCHAR
 */
 
#if !defined(CWCHARSTRINGBASEINTERFACE_MEMBERS_ONLY)
class c_INTERFACE_CLASS cWCHARStringBaseInterface;
/**
 **********************************************************************
 * Typedef: cWCHARStringBaseInterfaceImplement
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cStringBaseInterfaceT
<cWCHARStringBaseInterface, WCHAR, WCHAR>
cWCHARStringBaseInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWCHARStringBaseInterface
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARStringBaseInterface
: virtual public cWCHARStringBaseInterfaceImplement
{
public:
    typedef cWCHARStringBaseInterfaceImplement cImplements;
#else /* !defined(CWCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWCHARSTRINGBASEINTERFACE_MEMBERS_ONLY)
};
#else /* !defined(CWCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWCHARSTRINGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY)
class c_IMPLEMENT_CLASS cWCHARStringBaseImplement;
/**
 **********************************************************************
 * Typedef: cWCHARStringBaseImplementImplement
 *
 *  Author: $author$
 *    Date: 7/29/2010
 **********************************************************************
 */
typedef cStringBaseImplementT
<cWCHARStringBaseImplement, 
 cWCHARStringBaseInterface, WCHAR, WCHAR>
cWCHARStringBaseImplementImplement;
/**
 **********************************************************************
 *  Class: cWCHARStringBaseImplement
 *
 * Author: $author$
 *   Date: 7/29/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARStringBaseImplement
: virtual public cWCHARStringBaseImplementImplement
{
public:
    typedef cWCHARStringBaseImplementImplement cImplements;
#else /* !defined(CWCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWCHARSTRINGBASEIMPLEMENT_MEMBERS_ONLY) */

/*
 * cChar
 */
 
class c_INTERFACE_CLASS ccCharStringBaseInterface;
/**
 **********************************************************************
 * Typedef: ccCharStringBaseInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cStringBaseInterfaceT
<ccCharStringBaseInterface, cChar, WCHAR>
ccCharStringBaseInterfaceImplement;
/**
 **********************************************************************
 *  Class: ccCharStringBaseInterface
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS ccCharStringBaseInterface
: virtual public ccCharStringBaseInterfaceImplement
{
public:
    typedef ccCharStringBaseInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS ccCharStringBaseImplement;
/**
 **********************************************************************
 * Typedef: ccCharStringBaseImplementImplement
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cStringBaseImplementT
<ccCharStringBaseImplement, 
 ccCharStringBaseInterface, cChar, WCHAR>
ccCharStringBaseImplementImplement;
/**
 **********************************************************************
 *  Class: ccCharStringBaseImplement
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS ccCharStringBaseImplement
: virtual public ccCharStringBaseImplementImplement
{
public:
    typedef ccCharStringBaseImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSTRINGBASEINTERFACE_HXX) || defined(CSTRINGBASEINTERFACE_MEMBERS_ONLY) */
