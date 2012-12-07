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
#ifndef _CSTRINGINTERFACE_HXX
#define _CSTRINGINTERFACE_HXX

#include "cstreaminterface.hxx"

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
 class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TStreamInterface=cStreamInterface,
 class TImplements=TStreamInterface>
 
class c_INTERFACE_CLASS cStringInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cStringInterfaceT cDerives;

#define CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstringinterfacebase.hxx"
#undef CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY

#define CSTRING_MEMBER_FUNCS_ONLY
#define CSTRING_MEMBER_FUNCS_INTERFACE
//#include "cstring.hxx"
#undef CSTRING_MEMBER_FUNCS_INTERFACE
#undef CSTRING_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStringInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cStringInterfaceT
<cStringInterface, CHAR>
cStringInterfaceImplements;
/**
 **********************************************************************
 *  Class: cStringInterface
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStringInterface
: virtual public cStringInterfaceImplements
{
public:
    typedef cStringInterfaceImplements cImplements;
    typedef cStringInterface cDerives;
};

class cStringImplement;

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
 class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TStreamImplement=cStreamImplement,
 class TStringInterface=cStringInterface,
 class TStreamImplements=TStreamImplement,
 class TImplements=TStringInterface>
 
class cStringImplementT
: virtual public TStreamImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cStringImplementT cDerives;

#define CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstringinterfacebase.hxx"
#undef CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY

#define CSTREAMBASE_MEMBER_FUNCS_ONLY
#define CSTREAMBASE_MEMBER_FUNCS_IMPLEMENT
#include "cstreambase.hxx"
#undef CSTREAMBASE_MEMBER_FUNCS_IMPLEMENT
#undef CSTREAMBASE_MEMBER_FUNCS_ONLY

#define CSTRING_MEMBER_FUNCS_ONLY
#define CSTRING_MEMBER_FUNCS_IMPLEMENT
//#include "cstring.hxx"
#undef CSTRING_MEMBER_FUNCS_IMPLEMENT
#undef CSTRING_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/1/2009
 **********************************************************************
 */
typedef cStringImplementT
<cStringImplement, CHAR>
cStringImplementImplements;
/**
 **********************************************************************
 *  Class: cStringImplement
 *
 * Author: $author$
 *   Date: 3/1/2009
 **********************************************************************
 */
class cStringImplement
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
<cTCHARStringInterface,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARStreamInterface>
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
class cTCHARStringImplement;
/**
 **********************************************************************
 * Typedef: cTCHARStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringImplementT
<cTCHARStringImplement,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARStreamImplement, cTCHARStringInterface>
cTCHARStringImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARStringImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARStringImplement
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
<cWCHARStringInterface,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARStreamInterface>
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
class cWCHARStringImplement;
/**
 **********************************************************************
 * Typedef: cWCHARStringImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStringImplementT
<cWCHARStringImplement,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARStreamImplement, cWCHARStringInterface>
cWCHARStringImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARStringImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARStringImplement
: virtual public cWCHARStringImplementImplements
{
public:
    typedef cWCHARStringImplementImplements cImplements;
    typedef cWCHARStringImplement cDerives;
};
#endif /* _CSTRINGINTERFACE_HXX */
