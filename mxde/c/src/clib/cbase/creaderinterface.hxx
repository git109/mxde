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
 *   File: creaderinterface.hxx
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
#if !defined(_CREADERINTERFACE_HXX) || defined(CREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CREADERINTERFACE_HXX) && !defined(CREADERINTERFACE_MEMBERS_ONLY)
#define _CREADERINTERFACE_HXX
#endif /* !defined(_CREADERINTERFACE_HXX) && !defined(CREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CREADERINTERFACE_MEMBERS_ONLY) 
#include "csequenceinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cReaderInterface;

#undef CDB_CLASS
#define CDB_CLASS "cReaderInterfaceT"
/**
 **********************************************************************
 *  Class: cReaderInterfaceT
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
template
<class TDerives=cReaderInterface,
 class TSequenceInterface=cSequenceInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TSequenceInterface>
 
class c_INTERFACE_CLASS cReaderInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tReaderInterface;
#else /* !defined(CREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CREADERINTERFACE_MEMBERS_ONLY) */

/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY

#if !defined(CREADERINTERFACE_MEMBERS_ONLY) 
/* include cReader member functions interface
 */
#define CREADER_MEMBERS_ONLY
#define CREADER_MEMBER_FUNCS_INTERFACE
#include "creader.hxx"
#undef CREADER_MEMBER_FUNCS_INTERFACE
#undef CREADER_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cReaderImplement;

#undef CDB_CLASS
#define CDB_CLASS "cReaderImplementT"
/**
 **********************************************************************
 *  Class: cReaderImplementT
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
template
<class TDerives=cReaderImplement,
 class TReaderInterface=cReaderInterface,
 class TSequenceImplement=cSequenceImplement,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TSequenceImplements=TSequenceImplement,
 class TImplements=TReaderInterface>
 
class c_IMPLEMENT_CLASS cReaderImplementT
: virtual public TSequenceImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TReaderInterface tReaderInterface;

/* include cReader interface member definitions
 */
#define CREADERINTERFACE_MEMBERS_ONLY
#include "creaderinterface.hxx"
#undef CREADERINTERFACE_MEMBERS_ONLY

/* include cReader member functions implement
 */
#define CREADER_MEMBERS_ONLY
#define CREADER_MEMBER_FUNCS_IMPLEMENT
#include "creader.hxx"
#undef CREADER_MEMBER_FUNCS_IMPLEMENT
#undef CREADER_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * CHAR
 */
class c_INTERFACE_CLASS cReaderInterface;
/**
 **********************************************************************
 * Typedef: cReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/26/2009
 **********************************************************************
 */
typedef cReaderInterfaceT
<cReaderInterface, cSequenceInterface, CHAR>
cReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cReaderInterface
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cReaderInterface
: virtual public cReaderInterfaceImplements
{
public:
    typedef cReaderInterfaceImplements cImplements;
    typedef cReaderInterface cDerives;
};
class c_IMPLEMENT_CLASS cReaderImplement;
/**
 **********************************************************************
 * Typedef: cReaderImplementImplements
 *
 *  Author: $author$
 *    Date: 2/26/2009
 **********************************************************************
 */
typedef cReaderImplementT
<cReaderImplement, cReaderInterface,
 cSequenceImplement, CHAR>
cReaderImplementImplements;
/**
 **********************************************************************
 *  Class: cReaderImplement
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cReaderImplement
: virtual public cReaderImplementImplements
{
public:
    typedef cReaderImplementImplements cImplements;
    typedef cReaderImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARReaderInterface;
/**
 **********************************************************************
 * Typedef: cTCHARReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderInterfaceT
<cTCHARReaderInterface, cTCHARSequenceInterface, TCHAR>
cTCHARReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARReaderInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARReaderInterface
: virtual public cTCHARReaderInterfaceImplements
{
public:
    typedef cTCHARReaderInterfaceImplements cImplements;
    typedef cTCHARReaderInterface cDerives;
};
class c_IMPLEMENT_CLASS cTCHARReaderImplement;
/**
 **********************************************************************
 * Typedef: cTCHARReaderImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderImplementT
<cTCHARReaderImplement, cTCHARReaderInterface,
 cTCHARSequenceImplement, TCHAR>
cTCHARReaderImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARReaderImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTCHARReaderImplement
: virtual public cTCHARReaderImplementImplements
{
public:
    typedef cTCHARReaderImplementImplements cImplements;
    typedef cTCHARReaderImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARReaderInterface;
/**
 **********************************************************************
 * Typedef: cWCHARReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderInterfaceT
<cWCHARReaderInterface, cWCHARSequenceInterface, WCHAR>
cWCHARReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARReaderInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARReaderInterface
: virtual public cWCHARReaderInterfaceImplements
{
public:
    typedef cWCHARReaderInterfaceImplements cImplements;
    typedef cWCHARReaderInterface cDerives;
};
class c_IMPLEMENT_CLASS cWCHARReaderImplement;
/**
 **********************************************************************
 * Typedef: cWCHARReaderImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderImplementT
<cWCHARReaderImplement, cWCHARReaderInterface,
 cWCHARSequenceImplement, WCHAR>
cWCHARReaderImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARReaderImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARReaderImplement
: virtual public cWCHARReaderImplementImplements
{
public:
    typedef cWCHARReaderImplementImplements cImplements;
    typedef cWCHARReaderImplement cDerives;
};

/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTEReaderInterface;
/**
 **********************************************************************
 * Typedef: cBYTEReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderInterfaceT
<cBYTEReaderInterface, cBYTESequenceInterface, BYTE>
cBYTEReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTEReaderInterface
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTEReaderInterface
: virtual public cBYTEReaderInterfaceImplements
{
public:
    typedef cBYTEReaderInterfaceImplements cImplements;
    typedef cBYTEReaderInterface cDerives;
};
class c_IMPLEMENT_CLASS cBYTEReaderImplement;
/**
 **********************************************************************
 * Typedef: cBYTEReaderImplementImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cReaderImplementT
<cBYTEReaderImplement, cBYTEReaderInterface,
 cBYTESequenceImplement, BYTE>
cBYTEReaderImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTEReaderImplement
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBYTEReaderImplement
: virtual public cBYTEReaderImplementImplements
{
public:
    typedef cBYTEReaderImplementImplements cImplements;
    typedef cBYTEReaderImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CREADERINTERFACE_HXX) || defined(CREADERINTERFACE_MEMBERS_ONLY) */
