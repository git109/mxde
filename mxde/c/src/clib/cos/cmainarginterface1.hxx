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
 *   File: cmainarginterface.hxx
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
#if defined(CMAINARGINTERFACE_MEMBERS_ONLY) 
#if defined(_CMAINARGINTERFACE_HXX) 
#define _CMAINARGINTERFACE_HXX_OLD 
#undef _CMAINARGINTERFACE_HXX
#endif /* defined(_CMAINARGINTERFACE_HXX) */
#endif /* defined(CMAINARGINTERFACE_MEMBERS_ONLY) */

#ifndef _CMAINARGINTERFACE_HXX
#define _CMAINARGINTERFACE_HXX

#if !defined(CMAINARGINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

class c_INTERFACE_CLASS cMainArgInterface;

#undef CDB_CLASS
#define CDB_CLASS "cMainArgInterfaceT"
/**
 **********************************************************************
 *  Class: cMainArgInterfaceT
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
template
<class TDerives=cMainArgInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cMainArgInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMainArgInterfaceT cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

#define CMAINARG_MEMBERS_ONLY
#define CMAINARG_MEMBER_FUNCS_INTERFACE
#include "cmainarg.hxx"
#undef CMAINARG_MEMBER_FUNCS_INTERFACE
#undef CMAINARG_MEMBERS_ONLY

#else /* !defined(CMAINARGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CMAINARGINTERFACE_MEMBERS_ONLY) */

#if !defined(CMAINARGINTERFACE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cMainArgInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/26/2009
 **********************************************************************
 */
typedef cMainArgInterfaceT
<cMainArgInterface, char, int>
cMainArgInterfaceImplements;
/**
 **********************************************************************
 *  Class: cMainArgInterface
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cMainArgInterface
: virtual public cMainArgInterfaceImplements
{
public:
    typedef cMainArgInterfaceImplements cImplements;
    typedef cMainArgInterface cDerives;
};

class cMainArgImplement;

#undef CDB_CLASS
#define CDB_CLASS "cMainArgImplementT"
/**
 **********************************************************************
 *  Class: cMainArgImplementT
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
template
<class TDerives=cMainArgImplement,
 class TMainArgInterface=cMainArgInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TMainArgInterface>
 
class cMainArgImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cMainArgImplementT cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

#define CMAINARG_MEMBERS_ONLY
#define CMAINARG_MEMBER_FUNCS_IMPLEMENT
#include "cmainarg.hxx"
#undef CMAINARG_MEMBER_FUNCS_IMPLEMENT
#undef CMAINARG_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cMainArgImplementImplements
 *
 *  Author: $author$
 *    Date: 2/26/2009
 **********************************************************************
 */
typedef cMainArgImplementT
<cMainArgImplement, cMainArgInterface, char, int>
cMainArgImplementImplements;
/**
 **********************************************************************
 *  Class: cMainArgImplement
 *
 * Author: $author$
 *   Date: 2/26/2009
 **********************************************************************
 */
class cMainArgImplement
: virtual public cMainArgImplementImplements
{
public:
    typedef cMainArgImplementImplements cImplements;
    typedef cMainArgImplement cDerives;
};

/*
 * tmain
 */
class c_INTERFACE_CLASS cTMainArgInterface;
/**
 **********************************************************************
 * Typedef: cTMainArgInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgInterfaceT
<cTMainArgInterface, TCHAR, int>
cTMainArgInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTMainArgInterface
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTMainArgInterface
: virtual public cTMainArgInterfaceImplements
{
public:
    typedef cTMainArgInterfaceImplements cImplements;
    typedef cTMainArgInterface cDerives;
};
class cTMainArgImplement;
/**
 **********************************************************************
 * Typedef: cTMainArgImplementImplements
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainArgImplementT
<cTMainArgImplement, cTMainArgInterface, TCHAR, int>
cTMainArgImplementImplements;
/**
 **********************************************************************
 *  Class: cTMainArgImplement
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class cTMainArgImplement
: virtual public cTMainArgImplementImplements
{
public:
    typedef cTMainArgImplementImplements cImplements;
    typedef cTMainArgImplement cDerives;
};
#else /* !defined(CMAINARGINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CMAINARGINTERFACE_MEMBERS_ONLY) */
#endif /* _CMAINARGINTERFACE_HXX */

#if defined(CMAINARGINTERFACE_MEMBERS_ONLY) 
#if defined(_CMAINARGINTERFACE_HXX_OLD) 
#define _CMAINARGINTERFACE_HXX
#undef _CMAINARGINTERFACE_HXX_OLD
#endif /* defined(_CMAINARGINTERFACE_HXX_OLD) */
#endif /* defined(CMAINARGINTERFACE_MEMBERS_ONLY) */
