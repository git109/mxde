/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: ccharinterface.hxx
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
#if !defined(_CCHARINTERFACE_HXX) || defined(CCHARINTERFACE_MEMBERS_ONLY)
#if !defined(_CCHARINTERFACE_HXX) && !defined(CCHARINTERFACE_MEMBERS_ONLY)
#define _CCHARINTERFACE_HXX
#endif /* !defined(_CCHARINTERFACE_HXX) && !defined(CCHARINTERFACE_MEMBERS_ONLY) */

#if !defined(CCHARINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cCharInterface;

#undef CDB_CLASS
#define CDB_CLASS "cCharInterfaceT"
/**
 **********************************************************************
 *  Class: cCharInterfaceT
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
template
<class TDerives=cCharInterface,
 class TChar=WCHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cCharInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
#else /* !defined(CCHARINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCHARINTERFACE_MEMBERS_ONLY) */

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vUndefinedLength = VUndefinedLength};
    enum { vEndChar = VEndChar};

    typedef tChar tWhat;
    enum { vEndWhat = vEndChar};

#if !defined(CCHARINTERFACE_MEMBERS_ONLY)
/* include cChar member functions interface
 */
#define CCHAR_MEMBERS_ONLY
#define CCHAR_MEMBER_FUNCS_INTERFACE
#include "cchar.hxx"
#undef CCHAR_MEMBER_FUNCS_INTERFACE
#undef CCHAR_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cCharImplement;
/**
 **********************************************************************
 *  Class: cCharImplementT
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
template
<class TDerives=cCharImplement,
 class TCharInterface=cCharInterface,
 class TChar=WCHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TImplements=TCharInterface>

class c_IMPLEMENT_CLASS cCharImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;

/* include cChar interface member definitions
 */
#define CCHARINTERFACE_MEMBERS_ONLY
#include "ccharinterface.hxx"
#undef CCHARINTERFACE_MEMBERS_ONLY

/* include cChar member functions implement
 */
#define CCHAR_MEMBERS_ONLY
#define CCHAR_MEMBER_FUNCS_IMPLEMENT
#include "cchar.hxx"
#undef CCHAR_MEMBER_FUNCS_IMPLEMENT
#undef CCHAR_MEMBERS_ONLY
};

class c_INTERFACE_CLASS cCharInterface;
/**
 **********************************************************************
 * Typedef: cCharInterfaceImplement
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cCharInterfaceT<>
cCharInterfaceImplement;
/**
 **********************************************************************
 *  Class: cCharInterface
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cCharInterface
: virtual public cCharInterfaceImplement
{
public:
    typedef cCharInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cCharImplement;
/**
 **********************************************************************
 * Typedef: cCharImplementImplement
 *
 *  Author: $author$
 *    Date: 4/7/2010
 **********************************************************************
 */
typedef cCharImplementT<>
cCharImplementImplement;
/**
 **********************************************************************
 *  Class: cCharImplement
 *
 * Author: $author$
 *   Date: 4/7/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cCharImplement
: virtual public cCharImplementImplement
{
public:
    typedef cCharImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CCHARINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CCHARINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CCHARINTERFACE_HXX) || defined(CCHARINTERFACE_MEMBERS_ONLY) */
