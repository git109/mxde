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
 *   File: cmaininterface.hxx
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
#if defined(CMAININTERFACE_MEMBERS_ONLY) 
#if defined(_CMAININTERFACE_HXX) 
#define _CMAININTERFACE_HXX_OLD 
#undef _CMAININTERFACE_HXX
#endif /* defined(_CMAININTERFACE_HXX) */
#endif /* defined(CMAININTERFACE_MEMBERS_ONLY) */

#ifndef _CMAININTERFACE_HXX
#define _CMAININTERFACE_HXX

#if !defined(CMAININTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

class c_INTERFACE_CLASS cMainInterface;

#undef CDB_CLASS
#define CDB_CLASS "cMainInterfaceT"
/**
 **********************************************************************
 *  Class: cMainInterfaceT
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
template
<class TMainInterface=cMainInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cMainInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TMainInterface cDerives;
#else /* !defined(CMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CMAININTERFACE_MEMBERS_ONLY) */

    typedef TInt tInt;
    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TEndChar tEndChar;
    enum {vEndChar = VEndChar};
    enum {vUndefinedLength = VUndefinedLength};

#if !defined(CMAININTERFACE_MEMBERS_ONLY) 
    static TMainInterface* m_theMainInterface;

    /**
     **********************************************************************
     * Function: GetMainInterface
     *
     *   Author: $author$
     *     Date: 2/23/2009
     **********************************************************************
     */
    static TMainInterface* GetMainInterface() 
    {
        return m_theMainInterface;
    }

#define CMAIN_MEMBERS_ONLY
#define CMAIN_MEMBER_FUNCS_INTERFACE
#include "cmain.hxx"
#undef CMAIN_MEMBER_FUNCS_INTERFACE
#undef CMAIN_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_INTERFACE_CLASS cMainInterface;
/**
 **********************************************************************
 * Typedef: cMainInterfaceImplements
 *
 *  Author: $author$
 *    Date: 2/23/2009
 **********************************************************************
 */
typedef cMainInterfaceT
<cMainInterface,char,int>
cMainInterfaceImplements;
/**
 **********************************************************************
 *  Class: cMainInterface
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cMainInterface
: virtual public cMainInterfaceImplements
{
public:
    typedef cMainInterfaceImplements cImplements;
    typedef cMainInterface cDerives;
};

class cMainImplement;

#undef CDB_CLASS
#define CDB_CLASS "cMainImplementT"
/**
 **********************************************************************
 *  Class: cMainImplementT
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
template
<class TDerives=cMainImplement,
 class TMainInterface=cMainInterface,
 class TChar=CHAR,
 class TInt=INT,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TMainInterface>
 
class cMainImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;

#define CMAININTERFACE_MEMBERS_ONLY
#include "cmaininterface.hxx"
#undef CMAININTERFACE_MEMBERS_ONLY

#define CMAIN_MEMBERS_ONLY
#define CMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cmain.hxx"
#undef CMAIN_MEMBER_FUNCS_IMPLEMENT
#undef CMAIN_MEMBERS_ONLY
};
#undef CDB_CLASS

/*
 * main
 */
class cMainImplement;
/**
 **********************************************************************
 * Typedef: cMainImplementImplements
 *
 *  Author: $author$
 *    Date: 2/23/2009
 **********************************************************************
 */
typedef cMainImplementT
<cMainImplement,cMainInterface,char,int>
cMainImplementImplements;
/**
 **********************************************************************
 *  Class: cMainImplement
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
class cMainImplement
: virtual public cMainImplementImplements
{
public:
    typedef cMainImplementImplements cImplements;
    typedef cMainImplement cDerives;
};

/*
 * tmain
 */
class c_INTERFACE_CLASS cTMainInterface;
/**
 **********************************************************************
 * Typedef: cTMainInterfaceImplements
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainInterfaceT
<cTMainInterface,TCHAR,int>
cTMainInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTMainInterface
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTMainInterface
: virtual public cTMainInterfaceImplements
{
public:
    typedef cTMainInterfaceImplements cImplements;
    typedef cTMainInterface cDerives;
};
class cTMainImplement;
/**
 **********************************************************************
 * Typedef: cTMainImplementImplements
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainImplementT
<cTMainImplement,cTMainInterface,TCHAR,int>
cTMainImplementImplements;
/**
 **********************************************************************
 *  Class: cTMainImplement
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class cTMainImplement
: virtual public cTMainImplementImplements
{
public:
    typedef cTMainImplementImplements cImplements;
    typedef cTMainImplement cDerives;
};
#else /* !defined(CMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CMAININTERFACE_MEMBERS_ONLY) */
#endif /* _CMAININTERFACE_HXX */

#if defined(CMAININTERFACE_MEMBERS_ONLY) 
#if defined(_CMAININTERFACE_HXX_OLD) 
#define _CMAININTERFACE_HXX
#undef _CMAININTERFACE_HXX_OLD
#endif /* defined(_CMAININTERFACE_HXX_OLD) */
#endif /* defined(CMAININTERFACE_MEMBERS_ONLY) */
