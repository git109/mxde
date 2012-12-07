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
 *   File: cstringinterface.hxx
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
#if !defined(_CSTRINGINTERFACE_HXX) || defined(CSTRINGINTERFACE_MEMBERS_ONLY)
#if !defined(_CSTRINGINTERFACE_HXX) && !defined(CSTRINGINTERFACE_MEMBERS_ONLY)
#define _CSTRINGINTERFACE_HXX
#endif /* !defined(_CSTRINGINTERFACE_HXX) && !defined(CSTRINGINTERFACE_MEMBERS_ONLY) */

#if !defined(CSTRINGINTERFACE_MEMBERS_ONLY)
#include "cstreaminterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cStringInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStringInterfaceT"
/**
 **********************************************************************
 *  Class: cStringInterfaceT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cStringInterface,
 class TStreamInterface=cStreamInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TStreamInterface>
 
class c_INTERFACE_CLASS cStringInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tStringInterface;
#else /* !defined(CSTRINGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTRINGINTERFACE_MEMBERS_ONLY) */

    typedef TChar TWhat;
    typedef TEndChar TEndWhat;
    enum { VEndWhat = VEndChar};

/* include cStream interface member definitions
 */
#define CSTREAMINTERFACE_MEMBERS_ONLY
#include "cstreaminterface.hxx"
#undef CSTREAMINTERFACE_MEMBERS_ONLY

    typedef TChar tChar;
    typedef TEndChar tEndChar;
    enum { vEndChar = VEndChar};

#if !defined(CSTRINGINTERFACE_MEMBERS_ONLY) 
/* include cString member functions interface
 */
#define CSTRING_MEMBERS_ONLY
#define CSTRING_MEMBER_FUNCS_INTERFACE
#include "cstring.hxx"
#undef CSTRING_MEMBER_FUNCS_INTERFACE
#undef CSTRING_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS  cStringImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStringImplementT"
/**
 **********************************************************************
 *  Class: cStringImplementT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cStringImplement,
 class TStringInterface=cStringInterface,
 class TStreamImplement=cStreamImplement,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TStreamImplements=TStreamImplement,
 class TImplements=TStringInterface>
 
class c_IMPLEMENT_CLASS  cStringImplementT
: virtual public TStreamImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TStringInterface tStringInterface;

/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

/* include cString member functions implement
 */
#define CSTRING_MEMBERS_ONLY
#define CSTRING_MEMBER_FUNCS_IMPLEMENT
#include "cstring.hxx"
#undef CSTRING_MEMBER_FUNCS_IMPLEMENT
#undef CSTRING_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INTERFACE_CLASS cStringInterface;
/**
 **********************************************************************
 * Typedef: cStringInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringInterfaceT
<cStringInterface, cStreamInterface, CHAR>
cStringInterfaceImplements;
/**
 **********************************************************************
 *  Class: cStringInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStringInterface
: virtual public cStringInterfaceImplements
{
public:
    typedef cStringInterfaceImplements cImplements;
    typedef cStringInterface cDerives;
};
class c_IMPLEMENT_CLASS  cStringImplement;
/**
 **********************************************************************
 * Typedef: cStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringImplementT
<cStringImplement, cStringInterface,
 cStreamImplement, CHAR>
cStringImplementImplements;
/**
 **********************************************************************
 *  Class: cStringImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cStringImplement
: virtual public cStringImplementImplements
{
public:
    typedef cStringImplementImplements cImplements;
    typedef cStringImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARStringInterface;
/**
 **********************************************************************
 * Typedef: cTCHARStringInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringInterfaceT
<cTCHARStringInterface, cTCHARStreamInterface, TCHAR>
cTCHARStringInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARStringInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARStringInterface
: virtual public cTCHARStringInterfaceImplements
{
public:
    typedef cTCHARStringInterfaceImplements cImplements;
    typedef cTCHARStringInterface cDerives;
};
class c_IMPLEMENT_CLASS  cTCHARStringImplement;
/**
 **********************************************************************
 * Typedef: cTCHARStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringImplementT
<cTCHARStringImplement, cTCHARStringInterface,
 cTCHARStreamImplement, TCHAR>
cTCHARStringImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARStringImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cTCHARStringImplement
: virtual public cTCHARStringImplementImplements
{
public:
    typedef cTCHARStringImplementImplements cImplements;
    typedef cTCHARStringImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARStringInterface;
/**
 **********************************************************************
 * Typedef: cWCHARStringInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringInterfaceT
<cWCHARStringInterface, cWCHARStreamInterface, WCHAR>
cWCHARStringInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARStringInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARStringInterface
: virtual public cWCHARStringInterfaceImplements
{
public:
    typedef cWCHARStringInterfaceImplements cImplements;
    typedef cWCHARStringInterface cDerives;
};
class c_IMPLEMENT_CLASS  cWCHARStringImplement;
/**
 **********************************************************************
 * Typedef: cWCHARStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringImplementT
<cWCHARStringImplement, cWCHARStringInterface,
 cWCHARStreamImplement, WCHAR>
cWCHARStringImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARStringImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cWCHARStringImplement
: virtual public cWCHARStringImplementImplements
{
public:
    typedef cWCHARStringImplementImplements cImplements;
    typedef cWCHARStringImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEStringInterface;
/**
 **********************************************************************
 * Typedef: cBYTEStringInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringInterfaceT
<cBYTEStringInterface, cBYTEStreamInterface, BYTE>
cBYTEStringInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEStringInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStringInterface
: virtual public cBYTEStringInterfaceImplements
{
public:
    typedef cBYTEStringInterfaceImplements cImplements;
    typedef cBYTEStringInterface cDerives;
};
class c_IMPLEMENT_CLASS  cBYTEStringImplement;
/**
 **********************************************************************
 * Typedef: cBYTEStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringImplementT
<cBYTEStringImplement, cBYTEStringInterface,
 cBYTEStreamImplement, BYTE>
cBYTEStringImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEStringImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cBYTEStringImplement
: virtual public cBYTEStringImplementImplements
{
public:
    typedef cBYTEStringImplementImplements cImplements;
    typedef cBYTEStringImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTRINGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTRINGINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSTRINGINTERFACE_HXX) || defined(CSTRINGINTERFACE_MEMBERS_ONLY) */
