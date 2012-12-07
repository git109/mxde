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
 *   File: cfilepathseparatoreventsinterface.hxx
 *
 * Author: $author$
 *   Date: 10/13/2009
 **********************************************************************
 */
#if !defined(_CFILEPATHSEPARATOREVENTSINTERFACE_HXX) || defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILEPATHSEPARATOREVENTSINTERFACE_HXX) && !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY)
#define _CFILEPATHSEPARATOREVENTSINTERFACE_HXX
#endif /* !defined(_CFILEPATHSEPARATOREVENTSINTERFACE_HXX) && !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cFilePathSeparatorEventsInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathSeparatorEventsInterfaceT"
/**
 **********************************************************************
 *  Class: cFilePathSeparatorEventsInterfaceT
 *
 * Author: $author$
 *   Date: 10/13/2009
 **********************************************************************
 */
template
<class TDerives=cFilePathSeparatorEventsInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cFilePathSeparatorEventsInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY) */

/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

#if !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY)
/* include cFilePathSeparatorEvents member functions interface
 */
#define CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY
#define CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE
#include "cfilepathseparatorevents.hxx"
#undef CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_INTERFACE
#undef CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cFilePathSeparatorEventsImplement;

/**
 **********************************************************************
 *  Class: cFilePathSeparatorEventsImplementT
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
template
<class TDerives=cFilePathSeparatorEventsImplement,
 class TFilePathSeparatorEventsInterface=cFilePathSeparatorEventsInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TFilePathSeparatorEventsInterface>

class c_IMPLEMENT_CLASS cFilePathSeparatorEventsImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    
/* include cFilePathSeparatorEvents interface member definitions
 */
#define CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY
#include "cfilepathseparatoreventsinterface.hxx"
#undef CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY

/* include cFilePathSeparatorEvents member functions implement
 */
#define CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY
#define CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cfilepathseparatorevents.hxx"
#undef CFILEPATHSEPARATOREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CFILEPATHSEPARATOREVENTS_MEMBERS_ONLY
};

/**
 **********************************************************************
 * Typedef: cFilePathSeparatorEventsInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cFilePathSeparatorEventsInterfaceT<>
cFilePathSeparatorEventsInterfaceImplements;
/**
 **********************************************************************
 *  Class: cFilePathSeparatorEventsInterface
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cFilePathSeparatorEventsInterface
: virtual public cFilePathSeparatorEventsInterfaceImplements
{
public:
    typedef cFilePathSeparatorEventsInterfaceImplements cImplements;
    typedef cFilePathSeparatorEventsInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cFilePathSeparatorEventsImplementImplements
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cFilePathSeparatorEventsImplementT<>
cFilePathSeparatorEventsImplementImplements;
/**
 **********************************************************************
 *  Class: cFilePathSeparatorEventsImplement
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cFilePathSeparatorEventsImplement
: virtual public cFilePathSeparatorEventsImplementImplements
{
public:
    typedef cFilePathSeparatorEventsImplementImplements cImplements;
    typedef cFilePathSeparatorEventsImplement cDerives;
};

/*
 * WCHAR
 */
 
class c_INTERFACE_CLASS cWFilePathSeparatorEventsInterface;
/**
 **********************************************************************
 * Typedef: cWFilePathSeparatorEventsInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cFilePathSeparatorEventsInterfaceT
<cWFilePathSeparatorEventsInterface, WCHAR>
cWFilePathSeparatorEventsInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWFilePathSeparatorEventsInterface
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWFilePathSeparatorEventsInterface
: virtual public cWFilePathSeparatorEventsInterfaceImplements
{
public:
    typedef cWFilePathSeparatorEventsInterfaceImplements cImplements;
    typedef cWFilePathSeparatorEventsInterface cDerives;
};
class c_IMPLEMENT_CLASS cWFilePathSeparatorEventsImplement;
/**
 **********************************************************************
 * Typedef: cWFilePathSeparatorEventsImplementImplements
 *
 *  Author: $author$
 *    Date: 10/14/2009
 **********************************************************************
 */
typedef cFilePathSeparatorEventsImplementT
<cWFilePathSeparatorEventsImplement, 
 cWFilePathSeparatorEventsInterface, WCHAR>
cWFilePathSeparatorEventsImplementImplements;
/**
 **********************************************************************
 *  Class: cWFilePathSeparatorEventsImplement
 *
 * Author: $author$
 *   Date: 10/14/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWFilePathSeparatorEventsImplement
: virtual public cWFilePathSeparatorEventsImplementImplements
{
public:
    typedef cWFilePathSeparatorEventsImplementImplements cImplements;
    typedef cWFilePathSeparatorEventsImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CFILEPATHSEPARATOREVENTSINTERFACE_HXX) || defined(CFILEPATHSEPARATOREVENTSINTERFACE_MEMBERS_ONLY) */
