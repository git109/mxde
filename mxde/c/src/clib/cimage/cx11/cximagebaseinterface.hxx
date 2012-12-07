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
 *   File: cximagebaseinterface.hxx
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
#if !defined(_CXIMAGEBASEINTERFACE_HXX) || defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXIMAGEBASEINTERFACE_HXX) && !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY)
#define _CXIMAGEBASEINTERFACE_HXX
#endif /* !defined(_CXIMAGEBASEINTERFACE_HXX) && !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY)
#include "cimagebaseinterface.hxx"
#include "cxgcinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXImageBaseInterface;

#undef CDB_CLASS
#define CDB_CLASS "cXImageBaseInterfaceT"
/**
 **********************************************************************
 *  Class: cXImageBaseInterfaceT
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
template
<class TDerives=cXImageBaseInterface,
 class TImageBaseInterface=cImageBaseInterface,
 class TXGCInterface=cXGCInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TImplements=TImageBaseInterface>

class c_INTERFACE_CLASS cXImageBaseInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives tXImageBaseInterface;
#else /* !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY) */
    typedef TXImageBaseInterface tXImageBaseInterface;
#endif /* !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY) */

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    typedef TXGCInterface tXGCInterface;

#if !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY)
/* include cXImageBase member functions interface
 */
#define CXIMAGEBASE_MEMBERS_ONLY
#define CXIMAGEBASE_MEMBER_FUNCS_INTERFACE
#include "cximagebase.hxx"
#undef CXIMAGEBASE_MEMBER_FUNCS_INTERFACE
#undef CXIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cXImageBaseImplement;

#undef CDB_CLASS
#define CDB_CLASS "cXImageBaseImplementT"
/**
 **********************************************************************
 *  Class: cXImageBaseImplementT
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
template
<class TDerives=cXImageBaseImplement,
 class TXImageBaseInterface=cXImageBaseInterface,
 class TImageBaseImplement=cImageBaseImplement,
 class TImageBaseInterface=cImageBaseInterface,
 class TXGCInterface=cXGCInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TImageBaseImplements=TImageBaseImplement,
 class TImplements=TXImageBaseInterface>

class c_IMPLEMENT_CLASS cXImageBaseImplementT
: virtual public TImageBaseImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;

/* include cXImageBase interface member definitions
 */
#define CXIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cximagebaseinterface.hxx"
#undef CXIMAGEBASEINTERFACE_MEMBERS_ONLY

/* include cXImageBase member functions implement
 */
#define CXIMAGEBASE_MEMBERS_ONLY
#define CXIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#include "cximagebase.hxx"
#undef CXIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#undef CXIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cXImageBaseInterfaceImplements
 *
 *  Author: $author$
 *    Date: 7/1/2009
 **********************************************************************
 */
typedef cXImageBaseInterfaceT<>
cXImageBaseInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXImageBaseInterface
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXImageBaseInterface
: virtual public cXImageBaseInterfaceImplements
{
public:
    typedef cXImageBaseInterfaceImplements cImplements;
    typedef cXImageBaseInterface cDerives;
};

/**
 **********************************************************************
 * Typedef: cXImageBaseImplementImplements
 *
 *  Author: $author$
 *    Date: 7/1/2009
 **********************************************************************
 */
typedef cXImageBaseImplementT<>
cXImageBaseImplementImplements;
/**
 **********************************************************************
 *  Class: cXImageBaseImplement
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXImageBaseImplement
: virtual public cXImageBaseImplementImplements
{
public:
    typedef cXImageBaseImplementImplements cImplements;
    typedef cXImageBaseImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGEBASEINTERFACE_HXX) || defined(CXIMAGEBASEINTERFACE_MEMBERS_ONLY) */
