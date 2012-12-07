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
 *   File: cargmaininterface.hxx
 *
 * Author: $author$
 *   Date: 3/20/2009
 **********************************************************************
 */
#if !defined(_CARGMAININTERFACE_HXX) || defined(CARGMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CARGMAININTERFACE_HXX) && !defined(CARGMAININTERFACE_MEMBERS_ONLY)
#define _CARGMAININTERFACE_HXX
#endif /* !defined(_CARGMAININTERFACE_HXX) && !defined(CARGMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CARGMAININTERFACE_MEMBERS_ONLY)
/* cArgMain interface definition
 */
#include "cmaininterface.hxx"

class c_INTERFACE_CLASS cArgMainInterface;

#undef CDB_CLASS
#define CDB_CLASS "cArgMainInterfaceT"
/**
 **********************************************************************
 *  Class: cArgMainInterfaceT
 *
 * Author: $author$
 *   Date: 3/20/2009
 **********************************************************************
 */
template
<class TDerives=cArgMainInterface,
 class TMainInterface=cMainInterface,
 class TFileInterface=cFileInterface,
 class TStreamInterface=cStreamInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TMainInterface>
 
class c_INTERFACE_CLASS cArgMainInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives TArgMainInterface;
#else /* !defined(CARGMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CARGMAININTERFACE_MEMBERS_ONLY) */

/* include cMain interface member definitions
 */
#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

#if !defined(CARGMAININTERFACE_MEMBERS_ONLY)
    static TArgMainInterface* m_theArgMainInterface;

    /**
     **********************************************************************
     * Function: GetArgMainInterface
     *
     *   Author: $author$
     *     Date: 5/3/2009
     **********************************************************************
     */
    static TArgMainInterface* GetArgMainInterface() 
    {
        return m_theArgMainInterface;
    }

/* include cArgMain member functions interface
 */
#define CARGMAIN_MEMBERS_ONLY
#define CARGMAIN_MEMBER_FUNCS_INTERFACE
#include "cargmain.hxx"
#undef CARGMAIN_MEMBER_FUNCS_INTERFACE
#undef CARGMAIN_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cArgMain implement definition
 */
class c_IMPLEMENT_CLASS  cArgMainImplement;

#undef CDB_CLASS
#define CDB_CLASS "cArgMainImplementT"
/**
 **********************************************************************
 *  Class: cArgMainImplementT
 *
 * Author: $author$
 *   Date: 3/23/2009
 **********************************************************************
 */
template
<class TDerives=cArgMainImplement,
 class TArgMainInterface=cArgMainInterface,
 class TFileInterface=cFileInterface,
 class TStreamInterface=cStreamInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TArgMainInterface>
 
class c_IMPLEMENT_CLASS  cArgMainImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;

/* include cArgMain interface member definitions
 */
#define CARGMAININTERFACE_MEMBERS_ONLY
#include "cargmaininterface.hxx"
#undef CARGMAININTERFACE_MEMBERS_ONLY

/* include cArgMain member functions implement
 */
#define CARGMAIN_MEMBERS_ONLY
#define CARGMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cargmain.hxx"
#undef CARGMAIN_MEMBER_FUNCS_IMPLEMENT
#undef CARGMAIN_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * main
 */
/**
 **********************************************************************
 * Typedef: cArgMainInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/23/2009
 **********************************************************************
 */
typedef cArgMainInterfaceT
<cArgMainInterface, cMainInterface, 
 cFileInterface, cStreamInterface, char, int>
cArgMainInterfaceImplements;
/**
 **********************************************************************
 *  Class: cArgMainInterface
 *
 * Author: $author$
 *   Date: 3/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cArgMainInterface
: virtual public cArgMainInterfaceImplements
{
public:
    typedef cArgMainInterfaceImplements cImplements;
    typedef cArgMainInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cArgMainImplementImplements
 *
 *  Author: $author$
 *    Date: 3/23/2009
 **********************************************************************
 */
typedef cArgMainImplementT
<cArgMainImplement, cArgMainInterface, 
 cFileInterface, cStreamInterface, char, int>
cArgMainImplementImplements;
/**
 **********************************************************************
 *  Class: cArgMainImplement
 *
 * Author: $author$
 *   Date: 3/23/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cArgMainImplement
: virtual public cArgMainImplementImplements
{
public:
    typedef cArgMainImplementImplements cImplements;
    typedef cArgMainImplement cDerives;
};

/*
 * tmain
 */
class c_INTERFACE_CLASS cArgTMainInterface;
/**
 **********************************************************************
 * Typedef: cArgTMainInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/23/2009
 **********************************************************************
 */
typedef cArgMainInterfaceT
<cArgTMainInterface, cTMainInterface, 
 cTCHARFileInterface, cTCHARStreamInterface, TCHAR, int>
cArgTMainInterfaceImplements;
/**
 **********************************************************************
 *  Class: cArgTMainInterface
 *
 * Author: $author$
 *   Date: 3/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cArgTMainInterface
: virtual public cArgTMainInterfaceImplements
{
public:
    typedef cArgTMainInterfaceImplements cImplements;
    typedef cArgTMainInterface cDerives;
};
class c_IMPLEMENT_CLASS  cArgTMainImplement;
/**
 **********************************************************************
 * Typedef: cArgTMainImplementImplements
 *
 *  Author: $author$
 *    Date: 3/23/2009
 **********************************************************************
 */
typedef cArgMainImplementT
<cArgTMainImplement, cArgTMainInterface, 
 cTCHARFileInterface, cTCHARStreamInterface, TCHAR, int>
cArgTMainImplementImplements;
/**
 **********************************************************************
 *  Class: cArgTMainImplement
 *
 * Author: $author$
 *   Date: 3/23/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cArgTMainImplement
: virtual public cArgTMainImplementImplements
{
public:
    typedef cArgTMainImplementImplements cImplements;
    typedef cArgTMainImplement cDerives;
};
#else /* !defined(CARGMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CARGMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CARGMAININTERFACE_HXX) || defined(CARGMAININTERFACE_MEMBERS_ONLY) */
