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
#if !defined(_CMAININTERFACE_HXX) || defined(CMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CMAININTERFACE_HXX) && !defined(CMAININTERFACE_MEMBERS_ONLY)
#define _CMAININTERFACE_HXX
#endif /* !defined(_CMAININTERFACE_HXX) && !defined(CMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CMAININTERFACE_MEMBERS_ONLY)
#include "cfileinterface.hxx"
#include "cstreaminterface.hxx"
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

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
 class TFileInterface=cFileInterface,
 class TStreamInterface=cStreamInterface,
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
    typedef TFileInterface tFileInterface;
    typedef TStreamInterface tStreamInterface;
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

class c_IMPLEMENT_CLASS  cMainImplement;

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
 
class c_IMPLEMENT_CLASS  cMainImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TFileInterface tFileInterface;
    typedef TStreamInterface tStreamInterface;

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
<cMainInterface,cFileInterface,cStreamInterface,char,int>
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
class c_IMPLEMENT_CLASS  cMainImplement;
/**
 **********************************************************************
 * Typedef: cMainImplementImplements
 *
 *  Author: $author$
 *    Date: 2/23/2009
 **********************************************************************
 */
typedef cMainImplementT
<cMainImplement,cMainInterface,
 cFileInterface,cStreamInterface,char,int>
cMainImplementImplements;
/**
 **********************************************************************
 *  Class: cMainImplement
 *
 * Author: $author$
 *   Date: 2/23/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cMainImplement
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
<cTMainInterface,cTCHARFileInterface,cTCHARStreamInterface,TCHAR,int>
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
class c_IMPLEMENT_CLASS  cTMainImplement;
/**
 **********************************************************************
 * Typedef: cTMainImplementImplements
 *
 *  Author: $author$
 *    Date: 3/5/2009
 **********************************************************************
 */
typedef cMainImplementT
<cTMainImplement,cTMainInterface,
 cTCHARFileInterface,cTCHARStreamInterface,TCHAR,int>
cTMainImplementImplements;
/**
 **********************************************************************
 *  Class: cTMainImplement
 *
 * Author: $author$
 *   Date: 3/5/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cTMainImplement
: virtual public cTMainImplementImplements
{
public:
    typedef cTMainImplementImplements cImplements;
    typedef cTMainImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CMAININTERFACE_HXX) || defined(CMAININTERFACE_MEMBERS_ONLY) */
