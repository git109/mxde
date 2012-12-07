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
 *   File: cfilepathinterface.hxx
 *
 * Author: $author$
 *   Date: 10/10/2009
 **********************************************************************
 */
#if !defined(_CFILEPATHINTERFACE_HXX) || defined(CFILEPATHINTERFACE_MEMBERS_ONLY)
#if !defined(_CFILEPATHINTERFACE_HXX) && !defined(CFILEPATHINTERFACE_MEMBERS_ONLY)
#define _CFILEPATHINTERFACE_HXX
#endif /* !defined(_CFILEPATHINTERFACE_HXX) && !defined(CFILEPATHINTERFACE_MEMBERS_ONLY) */

#if !defined(CFILEPATHINTERFACE_MEMBERS_ONLY)
#include "cplatform_path.hxx"
#include "cstringinterface.hxx"
#include "cseparatorinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cFilePathInterface;

#undef CDB_CLASS
#define CDB_CLASS "cFilePathInterfaceT"
/**
 **********************************************************************
 *  Class: cFilePathInterfaceT
 *
 * Author: $author$
 *   Date: 10/10/2009
 **********************************************************************
 */
template
<class TDerives=cFilePathInterface,
 class TStringInterface=cStringInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TStringInterface>

class c_INTERFACE_CLASS cFilePathInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;    
#else /* !defined(CFILEPATHINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATHINTERFACE_MEMBERS_ONLY) */

/* include cString interface member definitions
 */
#define CSTRINGINTERFACE_MEMBERS_ONLY
#include "cstringinterface.hxx"
#undef CSTRINGINTERFACE_MEMBERS_ONLY

    typedef TStringInterface tStringInterface;
    
#if !defined(CFILEPATHINTERFACE_MEMBERS_ONLY)
/* include cFilePath member functions interface
 */
#define CFILEPATH_MEMBERS_ONLY
#define CFILEPATH_MEMBER_FUNCS_INTERFACE
#include "cfilepath.hxx"
#undef CFILEPATH_MEMBER_FUNCS_INTERFACE
#undef CFILEPATH_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cFilePathImplement;

/**
 **********************************************************************
 *  Class: cFilePathImplementT
 *
 * Author: $author$
 *   Date: 10/10/2009
 **********************************************************************
 */
template
<class TDerives=cFilePathImplement,
 class TFilePathInterface=cFilePathInterface,
 class TStringInterface=cStringInterface,
 class TChar=CHAR,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TFilePathInterface>

class c_IMPLEMENT_CLASS cFilePathImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    
/* include cFilePath interface member definitions
 */
#define CFILEPATHINTERFACE_MEMBERS_ONLY
#include "cfilepathinterface.hxx"
#undef CFILEPATHINTERFACE_MEMBERS_ONLY

/* include cFilePath member functions implement
 */
#define CFILEPATH_MEMBERS_ONLY
#define CFILEPATH_MEMBER_FUNCS_IMPLEMENT
#include "cfilepath.hxx"
#undef CFILEPATH_MEMBER_FUNCS_IMPLEMENT
#undef CFILEPATH_MEMBERS_ONLY
};

/**
 **********************************************************************
 * Typedef: cFilePathInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/11/2009
 **********************************************************************
 */
typedef cFilePathInterfaceT<>
cFilePathInterfaceImplements;
/**
 **********************************************************************
 *  Class: cFilePathInterface
 *
 * Author: $author$
 *   Date: 10/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cFilePathInterface
: virtual public cFilePathInterfaceImplements
{
public:
    typedef cFilePathInterfaceImplements cImplements;
};
/**
 **********************************************************************
 * Typedef: cFilePathImplementImplements
 *
 *  Author: $author$
 *    Date: 10/11/2009
 **********************************************************************
 */
typedef cFilePathImplementT<>
cFilePathImplementImplements;
/**
 **********************************************************************
 *  Class: cFilePathImplement
 *
 * Author: $author$
 *   Date: 10/11/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cFilePathImplement
: virtual public cFilePathImplementImplements
{
public:
    typedef cFilePathImplementImplements cImplements;
};

/*
 * WCHAR
 */
 
class c_INTERFACE_CLASS cWFilePathInterface;
/**
 **********************************************************************
 * Typedef: cWFilePathInterfaceImplements
 *
 *  Author: $author$
 *    Date: 10/11/2009
 **********************************************************************
 */
typedef cFilePathInterfaceT
<cWFilePathInterface, cWCHARStringInterface, WCHAR>
cWFilePathInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWFilePathInterface
 *
 * Author: $author$
 *   Date: 10/11/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWFilePathInterface
: virtual public cWFilePathInterfaceImplements
{
public:
    typedef cWFilePathInterfaceImplements cImplements;
};
class c_IMPLEMENT_CLASS cWFilePathImplement;
/**
 **********************************************************************
 * Typedef: cWFilePathImplementImplements
 *
 *  Author: $author$
 *    Date: 10/11/2009
 **********************************************************************
 */
typedef cFilePathImplementT
<cWFilePathImplement, cWFilePathInterface, 
 cWCHARStringInterface, WCHAR>
cWFilePathImplementImplements;
/**
 **********************************************************************
 *  Class: cWFilePathImplement
 *
 * Author: $author$
 *   Date: 10/11/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWFilePathImplement
: virtual public cWFilePathImplementImplements
{
public:
    typedef cWFilePathImplementImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILEPATHINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CFILEPATHINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CFILEPATHINTERFACE_HXX) || defined(CFILEPATHINTERFACE_MEMBERS_ONLY) */
