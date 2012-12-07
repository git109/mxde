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
 *   File: cwriterinterface.hxx
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
#if !defined(_CWRITERINTERFACE_HXX) || defined(CWRITERINTERFACE_MEMBERS_ONLY)
#if !defined(_CWRITERINTERFACE_HXX) && !defined(CWRITERINTERFACE_MEMBERS_ONLY)
#define _CWRITERINTERFACE_HXX
#endif /* !defined(_CWRITERINTERFACE_HXX) && !defined(CWRITERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWRITERINTERFACE_MEMBERS_ONLY)
#include "csequenceinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWriterInterface;

#undef CDB_CLASS
#define CDB_CLASS "cWriterInterfaceT"
/**
 **********************************************************************
 *  Class: cWriterInterfaceT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cWriterInterface,
 class TSequenceInterface=cSequenceInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TSequenceInterface>
 
class c_INTERFACE_CLASS cWriterInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tWriterInterface;
#else /* !defined(CWRITERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWRITERINTERFACE_MEMBERS_ONLY) */

/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY

#if !defined(CWRITERINTERFACE_MEMBERS_ONLY) 
/* include cWriter member functions interface
 */
#define CWRITER_MEMBERS_ONLY
#define CWRITER_MEMBER_FUNCS_INTERFACE
#include "cwriter.hxx"
#undef CWRITER_MEMBER_FUNCS_INTERFACE
#undef CWRITER_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cWriterImplement;

#undef CDB_CLASS
#define CDB_CLASS "cWriterImplementT"
/**
 **********************************************************************
 *  Class: cWriterImplementT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cWriterImplement,
 class TWriterInterface=cWriterInterface,
 class TSequenceImplement=cSequenceImplement,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TSequenceImplements=TSequenceImplement,
 class TImplements=TWriterInterface>
 
class cWriterImplementT
: virtual public TSequenceImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TWriterInterface tWriterInterface;

/* include cWriter interface member definitions
 */
#define CWRITERINTERFACE_MEMBERS_ONLY
#include "cwriterinterface.hxx"
#undef CWRITERINTERFACE_MEMBERS_ONLY

/* include cWriter member functions implement
 */
#define CWRITER_MEMBERS_ONLY
#define CWRITER_MEMBER_FUNCS_IMPLEMENT
#include "cwriter.hxx"
#undef CWRITER_MEMBER_FUNCS_IMPLEMENT
#undef CWRITER_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INTERFACE_CLASS cWriterInterface;
/**
 **********************************************************************
 * Typedef: cWriterInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/27/2009
 **********************************************************************
 */
typedef cWriterInterfaceT
<cWriterInterface, cSequenceInterface, CHAR>
cWriterInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWriterInterface
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWriterInterface
: virtual public cWriterInterfaceImplements
{
public:
    typedef cWriterInterfaceImplements cImplements;
    typedef cWriterInterface cDerives;
};
class c_IMPLEMENT_CLASS cWriterImplement;
/**
 **********************************************************************
 * Typedef: cWriterImplementImplements
 *
 *  Author: $author$
 *    Date: 2/28/2009
 **********************************************************************
 */
typedef cWriterImplementT
<cWriterImplement, cWriterInterface,
cSequenceImplement, CHAR>
cWriterImplementImplements;
/**
 **********************************************************************
 *  Class: cWriterImplement
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWriterImplement
: virtual public cWriterImplementImplements
{
public:
    typedef cWriterImplementImplements cImplements;
    typedef cWriterImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARWriterInterface;
/**
 **********************************************************************
 * Typedef: cTCHARWriterInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterInterfaceT
<cTCHARWriterInterface, cTCHARSequenceInterface, TCHAR>
cTCHARWriterInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARWriterInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARWriterInterface
: virtual public cTCHARWriterInterfaceImplements
{
public:
    typedef cTCHARWriterInterfaceImplements cImplements;
    typedef cTCHARWriterInterface cDerives;
};
class c_IMPLEMENT_CLASS cTCHARWriterImplement;
/**
 **********************************************************************
 * Typedef: cTCHARWriterImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterImplementT
<cTCHARWriterImplement, cTCHARWriterInterface,
cTCHARSequenceImplement, TCHAR>
cTCHARWriterImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARWriterImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTCHARWriterImplement
: virtual public cTCHARWriterImplementImplements
{
public:
    typedef cTCHARWriterImplementImplements cImplements;
    typedef cTCHARWriterImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARWriterInterface;
/**
 **********************************************************************
 * Typedef: cWCHARWriterInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterInterfaceT
<cWCHARWriterInterface, cWCHARSequenceInterface, WCHAR>
cWCHARWriterInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARWriterInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARWriterInterface
: virtual public cWCHARWriterInterfaceImplements
{
public:
    typedef cWCHARWriterInterfaceImplements cImplements;
    typedef cWCHARWriterInterface cDerives;
};
class c_IMPLEMENT_CLASS cWCHARWriterImplement;
/**
 **********************************************************************
 * Typedef: cWCHARWriterImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterImplementT
<cWCHARWriterImplement, cWCHARWriterInterface,
cWCHARSequenceImplement, WCHAR>
cWCHARWriterImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARWriterImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARWriterImplement
: virtual public cWCHARWriterImplementImplements
{
public:
    typedef cWCHARWriterImplementImplements cImplements;
    typedef cWCHARWriterImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEWriterInterface;
/**
 **********************************************************************
 * Typedef: cBYTEWriterInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterInterfaceT
<cBYTEWriterInterface, cBYTESequenceInterface, BYTE>
cBYTEWriterInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEWriterInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEWriterInterface
: virtual public cBYTEWriterInterfaceImplements
{
public:
    typedef cBYTEWriterInterfaceImplements cImplements;
    typedef cBYTEWriterInterface cDerives;
};
class c_IMPLEMENT_CLASS cBYTEWriterImplement;
/**
 **********************************************************************
 * Typedef: cBYTEWriterImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cWriterImplementT
<cBYTEWriterImplement, cBYTEWriterInterface,
cBYTESequenceImplement, BYTE>
cBYTEWriterImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEWriterImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBYTEWriterImplement
: virtual public cBYTEWriterImplementImplements
{
public:
    typedef cBYTEWriterImplementImplements cImplements;
    typedef cBYTEWriterImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWRITERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWRITERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWRITERINTERFACE_HXX) || defined(CWRITERINTERFACE_MEMBERS_ONLY) */
