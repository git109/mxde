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
 *   File: cstreaminterface.hxx
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
#if defined(CSTREAMINTERFACE_MEMBERS_ONLY) 
#if defined(_CSTREAMINTERFACE_HXX) 
#define _CSTREAMINTERFACE_HXX_OLD 
#undef _CSTREAMINTERFACE_HXX
#endif /* defined(_CSTREAMINTERFACE_HXX) */
#endif /* defined(CSTREAMINTERFACE_MEMBERS_ONLY) */

#ifndef _CSTREAMINTERFACE_HXX
#define _CSTREAMINTERFACE_HXX

#if !defined(CSTREAMINTERFACE_MEMBERS_ONLY)
#include "creaderinterface.hxx"
#include "cwriterinterface.hxx"

class c_INTERFACE_CLASS cStreamInterface;

#undef CDB_CLASS
#define CDB_CLASS "cStreamInterfaceT"
/**
 **********************************************************************
 *  Class: cStreamInterfaceT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cStreamInterface,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TReaderInterface=cReaderInterface,
 class TWriterInterface=cWriterInterface,
 class TReaderImplements=TReaderInterface,
 class TWriterImplements=TWriterInterface>
 
class c_INTERFACE_CLASS cStreamInterfaceT
: virtual public TReaderImplements,
  virtual public TWriterImplements
{
public:
    typedef TReaderImplements cReaderImplements;
    typedef TWriterImplements cWriterImplements;
    typedef TDerives cDerives;
#else /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */

#define CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstreaminterfacebase.hxx"
#undef CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY

#if !defined(CSTREAMINTERFACE_MEMBERS_ONLY)
#define CSTREAM_MEMBER_FUNCS_ONLY
#define CSTREAM_MEMBER_FUNCS_INTERFACE
#include "cstream.hxx"
#undef CSTREAM_MEMBER_FUNCS_INTERFACE
#undef CSTREAM_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStreamInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/28/2009
 **********************************************************************
 */
typedef cStreamInterfaceT
<cStreamInterface, CHAR>
cStreamInterfaceImplements;
/**
 **********************************************************************
 *  Class: cStreamInterface
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStreamInterface
: virtual public cStreamInterfaceImplements
{
public:
    typedef cStreamInterfaceImplements cImplements;
    typedef cStreamInterface cDerives;
};

class cStreamImplement;

#undef CDB_CLASS
#define CDB_CLASS "cStreamImplementT"
/**
 **********************************************************************
 *  Class: cStreamImplementT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cStreamImplement,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TStreamInterface=cStreamInterface,
 class TReaderImplements=cReaderImplement,
 class TWriterImplements=cWriterImplement,
 class TImplements=TStreamInterface>
 
class cStreamImplementT
: virtual public TReaderImplements,
  virtual public TWriterImplements,
  virtual public TImplements
{
public:
    typedef TReaderImplements cReaderImplements;
    typedef TWriterImplements cWriterImplements;
    typedef TImplements cImplements;
    typedef TDerives cDerives;

#define CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstreaminterfacebase.hxx"
#undef CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY

#define CSTREAM_MEMBER_FUNCS_ONLY
#define CSTREAM_MEMBER_FUNCS_IMPLEMENT
#include "cstream.hxx"
#undef CSTREAM_MEMBER_FUNCS_IMPLEMENT
#undef CSTREAM_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 2/28/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cStreamImplement, CHAR>
cStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cStreamImplement
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
class cStreamImplement
: virtual public cStreamImplementImplements
{
public:
    typedef cStreamImplementImplements cImplements;
    typedef cStreamImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARStreamInterface;
/**
 **********************************************************************
 * Typedef: cTCHARStreamInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamInterfaceT
<cTCHARStreamInterface,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARReaderInterface, cTCHARWriterInterface>
cTCHARStreamInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARStreamInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARStreamInterface
: virtual public cTCHARStreamInterfaceImplements
{
public:
    typedef cTCHARStreamInterfaceImplements cImplements;
    typedef cTCHARStreamInterface cDerives;
};
class cTCHARStreamImplement;
/**
 **********************************************************************
 * Typedef: cTCHARStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cTCHARStreamImplement,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARStreamInterface,
 cTCHARReaderImplement, cTCHARWriterImplement>
cTCHARStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARStreamImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARStreamImplement
: virtual public cTCHARStreamImplementImplements
{
public:
    typedef cTCHARStreamImplementImplements cImplements;
    typedef cTCHARStreamImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARStreamInterface;
/**
 **********************************************************************
 * Typedef: cWCHARStreamInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamInterfaceT
<cWCHARStreamInterface,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARReaderInterface, cWCHARWriterInterface>
cWCHARStreamInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARStreamInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARStreamInterface
: virtual public cWCHARStreamInterfaceImplements
{
public:
    typedef cWCHARStreamInterfaceImplements cImplements;
    typedef cWCHARStreamInterface cDerives;
};
class cWCHARStreamImplement;
/**
 **********************************************************************
 * Typedef: cWCHARStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cWCHARStreamImplement,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARStreamInterface,
 cWCHARReaderImplement, cWCHARWriterImplement>
cWCHARStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARStreamImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARStreamImplement
: virtual public cWCHARStreamImplementImplements
{
public:
    typedef cWCHARStreamImplementImplements cImplements;
    typedef cWCHARStreamImplement cDerives;
};
#else /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */

#endif /* _CSTREAMINTERFACE_HXX */

#if defined(CSTREAMINTERFACE_MEMBERS_ONLY) 
#if defined(_CSTREAMINTERFACE_HXX_OLD) 
#define _CSTREAMINTERFACE_HXX
#undef _CSTREAMINTERFACE_HXX_OLD
#endif /* defined(_CSTREAMINTERFACE_HXX_OLD) */
#endif /* defined(CSTREAMINTERFACE_MEMBERS_ONLY) */
