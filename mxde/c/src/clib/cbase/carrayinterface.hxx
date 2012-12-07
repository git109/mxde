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
 *   File: carrayinterface.hxx
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
#if !defined(_CARRAYINTERFACE_HXX) || defined(CARRAYINTERFACE_MEMBERS_ONLY)
#if !defined(_CARRAYINTERFACE_HXX) && !defined(CARRAYINTERFACE_MEMBERS_ONLY)
#define _CARRAYINTERFACE_HXX
#endif /* !defined(_CARRAYINTERFACE_HXX) && !defined(CARRAYINTERFACE_MEMBERS_ONLY) */

#if !defined(CARRAYINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cArrayInterface;

#undef CDB_CLASS
#define CDB_CLASS "cArrayInterfaceT"
/**
 **********************************************************************
 *  Class: cArrayInterfaceT
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
template
<class TDerives=cArrayInterface,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplement=cInterfaceBase,
 class TImplements=TImplement>

class c_INTERFACE_CLASS cArrayInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives TArrayInterface;
#else /* !defined(CARRAYINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CARRAYINTERFACE_MEMBERS_ONLY) */

    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vUndefinedLength = VUndefinedLength };
    typedef TArrayInterface tArrayInterface;
    
#if !defined(CARRAYINTERFACE_MEMBERS_ONLY)
/* include cArray member functions interface
 */
#define CARRAY_MEMBERS_ONLY
#define CARRAY_MEMBER_FUNCS_INTERFACE
#include "carray.hxx"
#undef CARRAY_MEMBER_FUNCS_INTERFACE
#undef CARRAY_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cArrayImplement;

#undef CDB_CLASS
#define CDB_CLASS "cArrayImplementT"
/**
 **********************************************************************
 *  Class: cArrayImplementT
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
template
<class TDerives=cArrayImplement,
 class TArrayInterface=cArrayInterface,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=TArrayInterface>

class c_IMPLEMENT_CLASS cArrayImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
/* include cArray interface member definitions
 */
#define CARRAYINTERFACE_MEMBERS_ONLY
#include "carrayinterface.hxx"
#undef CARRAYINTERFACE_MEMBERS_ONLY

/* include cArray member functions implement
 */
#define CARRAY_MEMBERS_ONLY
#define CARRAY_MEMBER_FUNCS_IMPLEMENT
#include "carray.hxx"
#undef CARRAY_MEMBER_FUNCS_IMPLEMENT
#undef CARRAY_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cArrayInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/25/2010
 **********************************************************************
 */
typedef cArrayInterfaceT<>
cArrayInterfaceImplement;
/**
 **********************************************************************
 *  Class: cArrayInterface
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cArrayInterface
: virtual public cArrayInterfaceImplement
{
public:
    typedef cArrayInterfaceImplement cImplements;
};
/**
 **********************************************************************
 * Typedef: cArrayImplementImplement
 *
 *  Author: $author$
 *    Date: 1/25/2010
 **********************************************************************
 */
typedef cArrayImplementT<>
cArrayImplementImplement;
/**
 **********************************************************************
 *  Class: cArrayImplement
 *
 * Author: $author$
 *   Date: 1/25/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cArrayImplement
: virtual public cArrayImplementImplement
{
public:
    typedef cArrayImplementImplement cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CARRAYINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CARRAYINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CARRAYINTERFACE_HXX) || defined(CARRAYINTERFACE_MEMBERS_ONLY) */
