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
#if !defined(_CSTREAMINTERFACE_HXX) || defined(CSTREAMINTERFACE_MEMBERS_ONLY)
#if !defined(_CSTREAMINTERFACE_HXX) && !defined(CSTREAMINTERFACE_MEMBERS_ONLY)
#define _CSTREAMINTERFACE_HXX
#endif /* !defined(_CSTREAMINTERFACE_HXX) && !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */

#if !defined(CSTREAMINTERFACE_MEMBERS_ONLY)
#include "creaderinterface.hxx"
#include "cwriterinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

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
 class TReaderInterface=cReaderInterface,
 class TWriterInterface=cWriterInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
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
    typedef TReaderImplements tReaderInterface;
    typedef TWriterImplements tWriterInterface;
    typedef TDerives tStreamInterface;
#else /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */

/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY

#if !defined(CSTREAMINTERFACE_MEMBERS_ONLY)
/* include cStream member functions interface
 */
#define CSTREAM_MEMBERS_ONLY
#define CSTREAM_MEMBER_FUNCS_INTERFACE
#include "cstream.hxx"
#undef CSTREAM_MEMBER_FUNCS_INTERFACE
#undef CSTREAM_MEMBERS_ONLY
};
#undef CDB_CLASS

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
 class TStreamInterface=cStreamInterface,
 class TReaderImplements=cReaderImplement,
 class TWriterImplements=cWriterImplement,
 class TReaderInterface=cReaderInterface,
 class TWriterInterface=cWriterInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
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
    typedef TReaderInterface tReaderInterface;
    typedef TWriterInterface tWriterInterface;
    typedef TStreamInterface tStreamInterface;

/* include cStream interface member definitions
 */
#define CSTREAMINTERFACE_MEMBERS_ONLY
#include "cstreaminterface.hxx"
#undef CSTREAMINTERFACE_MEMBERS_ONLY

/* include cStream member functions implement
 */
#define CSTREAM_MEMBERS_ONLY
#define CSTREAM_MEMBER_FUNCS_IMPLEMENT
#include "cstream.hxx"
#undef CSTREAM_MEMBER_FUNCS_IMPLEMENT
#undef CSTREAM_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INTERFACE_CLASS cStreamInterface;
/**
 **********************************************************************
 * Typedef: cStreamInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamInterfaceT
<cStreamInterface, cReaderInterface,
 cWriterInterface, CHAR>
cStreamInterfaceImplements;
/**
 **********************************************************************
 *  Class: cStreamInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStreamInterface
: virtual public cStreamInterfaceImplements
{
public:
    typedef cStreamInterfaceImplements cImplements;
    typedef cStreamInterface cDerives;
};
class c_IMPLEMENT_CLASS cStreamImplement;
/**
 **********************************************************************
 * Typedef: cStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cStreamImplement, cStreamInterface,
 cReaderImplement, cWriterImplement,
 cReaderInterface, cWriterInterface, CHAR>
cStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cStreamImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cStreamImplement
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
<cTCHARStreamInterface, cTCHARReaderInterface,
 cTCHARWriterInterface, TCHAR>
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
class c_IMPLEMENT_CLASS cTCHARStreamImplement;
/**
 **********************************************************************
 * Typedef: cTCHARStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cTCHARStreamImplement, cTCHARStreamInterface,
 cTCHARReaderImplement, cTCHARWriterImplement,
 cTCHARReaderInterface, cTCHARWriterInterface, TCHAR>
cTCHARStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARStreamImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTCHARStreamImplement
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
<cWCHARStreamInterface, cWCHARReaderInterface,
 cWCHARWriterInterface, WCHAR>
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
class c_IMPLEMENT_CLASS cWCHARStreamImplement;
/**
 **********************************************************************
 * Typedef: cWCHARStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cWCHARStreamImplement, cWCHARStreamInterface,
 cWCHARReaderImplement, cWCHARWriterImplement,
 cWCHARReaderInterface, cWCHARWriterInterface, WCHAR>
cWCHARStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARStreamImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARStreamImplement
: virtual public cWCHARStreamImplementImplements
{
public:
    typedef cWCHARStreamImplementImplements cImplements;
    typedef cWCHARStreamImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEStreamInterface;
/**
 **********************************************************************
 * Typedef: cBYTEStreamInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamInterfaceT
<cBYTEStreamInterface, cBYTEReaderInterface,
 cBYTEWriterInterface, BYTE>
cBYTEStreamInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEStreamInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEStreamInterface
: virtual public cBYTEStreamInterfaceImplements
{
public:
    typedef cBYTEStreamInterfaceImplements cImplements;
    typedef cBYTEStreamInterface cDerives;
};
class c_IMPLEMENT_CLASS cBYTEStreamImplement;
/**
 **********************************************************************
 * Typedef: cBYTEStreamImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamImplementT
<cBYTEStreamImplement, cBYTEStreamInterface,
 cBYTEReaderImplement, cBYTEWriterImplement,
 cBYTEReaderInterface, cBYTEWriterInterface, BYTE>
cBYTEStreamImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEStreamImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBYTEStreamImplement
: virtual public cBYTEStreamImplementImplements
{
public:
    typedef cBYTEStreamImplementImplements cImplements;
    typedef cBYTEStreamImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSTREAMINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSTREAMINTERFACE_HXX) || defined(CSTREAMINTERFACE_MEMBERS_ONLY) */
