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
 *   File: csequenceinterface.hxx
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
#if !defined(_CSEQUENCEINTERFACE_HXX) || defined(CSEQUENCEINTERFACE_MEMBERS_ONLY)
#if !defined(_CSEQUENCEINTERFACE_HXX) && !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY)
#define _CSEQUENCEINTERFACE_HXX
#endif /* !defined(_CSEQUENCEINTERFACE_HXX) && !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY) */

#if !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cSequenceInterface;

#undef CDB_CLASS
#define CDB_CLASS "cSequenceInterfaceT"
/**
 **********************************************************************
 *  Class: cSequenceInterfaceT
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
template
<class TDerives=cSequenceInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cSequenceInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cSequenceInterfaceT cDerives;
#else /* !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY) */

    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TEndWhat tEndWhat;
    enum { vUndefinedLength = VUndefinedLength};
    enum { vEndWhat = VEndWhat};

#if !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY)
/* include cSequence member functions interface
 */
#define CSEQUENCE_MEMBERS_ONLY
#define CSEQUENCE_MEMBER_FUNCS_INTERFACE
#include "csequence.hxx"
#undef CSEQUENCE_MEMBER_FUNCS_INTERFACE
#undef CSEQUENCE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cSequenceImplement;

#undef CDB_CLASS
#define CDB_CLASS "cSequenceImplementT"
/**
 **********************************************************************
 *  Class: cSequenceImplementT
 *
 * Author: $author$
 *   Date: 3/15/2009
 **********************************************************************
 */
template
<class TDerives=cSequenceImplement,
 class TSequenceInterface=cSequenceInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TSequenceInterface>
 
class c_IMPLEMENT_CLASS cSequenceImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cSequenceImplementT cDerives;
/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY

/* include cSequence member functions implement
 */
#define CSEQUENCE_MEMBERS_ONLY
#define CSEQUENCE_MEMBER_FUNCS_IMPLEMENT
#include "csequence.hxx"
#undef CSEQUENCE_MEMBER_FUNCS_IMPLEMENT
#undef CSEQUENCE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cSequenceInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceInterfaceT<>
cSequenceInterfaceImplements;
/**
 **********************************************************************
 *  Class: cSequenceInterface
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cSequenceInterface
: virtual public cSequenceInterfaceImplements
{
public:
    typedef cSequenceInterfaceImplements cImplements;
    typedef cSequenceInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cSequenceImplementImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceImplementT<>
cSequenceImplementImplements;
/**
 **********************************************************************
 *  Class: cSequenceImplement
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cSequenceImplement
: virtual public cSequenceImplementImplements
{
public:
    typedef cSequenceImplementImplements cImplements;
    typedef cSequenceImplement cDerives;
};

/*
 * TCHAR
 */
class c_INTERFACE_CLASS cTCHARSequenceInterface;
/**
 **********************************************************************
 * Typedef: cTCHARSequenceInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceInterfaceT
<cTCHARSequenceInterface,TCHAR>
cTCHARSequenceInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTCHARSequenceInterface
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTCHARSequenceInterface
: virtual public cTCHARSequenceInterfaceImplements
{
public:
    typedef cTCHARSequenceInterfaceImplements cImplements;
    typedef cTCHARSequenceInterface cDerives;
};
class c_IMPLEMENT_CLASS cTCHARSequenceImplement;
/**
 **********************************************************************
 * Typedef: cTCHARSequenceImplementImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceImplementT
<cTCHARSequenceImplement,cTCHARSequenceInterface,TCHAR>
cTCHARSequenceImplementImplements;
/**
 **********************************************************************
 *  Class: cTCHARSequenceImplement
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTCHARSequenceImplement
: virtual public cTCHARSequenceImplementImplements
{
public:
    typedef cTCHARSequenceImplementImplements cImplements;
    typedef cTCHARSequenceImplement cDerives;
};

/*
 * WCHAR
 */
class c_INTERFACE_CLASS cWCHARSequenceInterface;
/**
 **********************************************************************
 * Typedef: cWCHARSequenceInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceInterfaceT
<cWCHARSequenceInterface,WCHAR>
cWCHARSequenceInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWCHARSequenceInterface
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWCHARSequenceInterface
: virtual public cWCHARSequenceInterfaceImplements
{
public:
    typedef cWCHARSequenceInterfaceImplements cImplements;
    typedef cWCHARSequenceInterface cDerives;
};
class c_IMPLEMENT_CLASS cWCHARSequenceImplement;
/**
 **********************************************************************
 * Typedef: cWCHARSequenceImplementImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceImplementT
<cWCHARSequenceImplement,cWCHARSequenceInterface,WCHAR>
cWCHARSequenceImplementImplements;
/**
 **********************************************************************
 *  Class: cWCHARSequenceImplement
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWCHARSequenceImplement
: virtual public cWCHARSequenceImplementImplements
{
public:
    typedef cWCHARSequenceImplementImplements cImplements;
    typedef cWCHARSequenceImplement cDerives;
};


/*
 * BYTE
 */
class c_INTERFACE_CLASS cBYTESequenceInterface;
/**
 **********************************************************************
 * Typedef: cBYTESequenceInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceInterfaceT
<cBYTESequenceInterface,BYTE>
cBYTESequenceInterfaceImplements;
/**
 **********************************************************************
 *  Class: cBYTESequenceInterface
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cBYTESequenceInterface
: virtual public cBYTESequenceInterfaceImplements
{
public:
    typedef cBYTESequenceInterfaceImplements cImplements;
    typedef cBYTESequenceInterface cDerives;
};
class c_IMPLEMENT_CLASS cBYTESequenceImplement;
/**
 **********************************************************************
 * Typedef: cBYTESequenceImplementImplements
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceImplementT
<cBYTESequenceImplement,cBYTESequenceInterface,BYTE>
cBYTESequenceImplementImplements;
/**
 **********************************************************************
 *  Class: cBYTESequenceImplement
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBYTESequenceImplement
: virtual public cBYTESequenceImplementImplements
{
public:
    typedef cBYTESequenceImplementImplements cImplements;
    typedef cBYTESequenceImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSEQUENCEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSEQUENCEINTERFACE_HXX) || defined(CSEQUENCEINTERFACE_MEMBERS_ONLY) */
