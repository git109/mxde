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
 *   File: cwinregionimagebaseinterface.hxx
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGEBASEINTERFACE_HXX) || defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGEBASEINTERFACE_HXX) && !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY)
#define _CWINREGIONIMAGEBASEINTERFACE_HXX
#endif /* !defined(_CWINREGIONIMAGEBASEINTERFACE_HXX) && !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY)
#include "cimagebaseinterface.hxx"
#include "cwinhrgnattachedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cWinRegionImageBaseInterface;

#undef CDB_CLASS
#define CDB_CLASS "cWinRegionImageBaseInterfaceT"
/**
 **********************************************************************
 *  Class: cWinRegionImageBaseInterfaceT
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
template
<class TDerives=cWinRegionImageBaseInterface,
 class TImageBaseInterface=cImageBaseInterface,
 class TWinHRGNAttachedInterface=cWinHRGNAttachedInterface,
 class TAttachedTo=HRGN,
 class TUnattached=LONG,
 TUnattached VUnattached=NULL,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TWinHRGNAttachedImplements=TWinHRGNAttachedInterface,
 class TImplements=TImageBaseInterface>

class c_INTERFACE_CLASS cWinRegionImageBaseInterfaceT
: virtual public TImplements,
  virtual public TWinHRGNAttachedImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
#else /* !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY) */

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    typedef TAttachedTo tAttachedTo;
    enum { vUnattached = VUnattached };

#if !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY)
/* include cWinRegionImageBase member functions interface
 */
#define CWINREGIONIMAGEBASE_MEMBERS_ONLY
#define CWINREGIONIMAGEBASE_MEMBER_FUNCS_INTERFACE
#include "cwinregionimagebase.hxx"
#undef CWINREGIONIMAGEBASE_MEMBER_FUNCS_INTERFACE
#undef CWINREGIONIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cWinRegionImageBaseImplement;

#undef CDB_CLASS
#define CDB_CLASS "cWinRegionImageBaseImplementT"
/**
 **********************************************************************
 *  Class: cWinRegionImageBaseImplementT
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
template
<class TDerives=cWinRegionImageBaseImplement,
 class TWinRegionImageBaseInterface=cWinRegionImageBaseInterface,
 class TImageBaseImplement=cImageBaseImplement,
 class TImageBaseInterface=cImageBaseInterface,
 class TWinHRGNAttachedImplement=cWinHRGNAttachedImplement,
 class TWinHRGNAttachedInterface=cWinHRGNAttachedInterface,
 class TAttachedTo=HRGN,
 class TUnattached=LONG,
 TUnattached VUnattached=NULL,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TWinHRGNAttachedImplements=TWinHRGNAttachedImplement,
 class TImageBaseImplements=TImageBaseImplement,
 class TImplements=TWinRegionImageBaseInterface>

class c_IMPLEMENT_CLASS cWinRegionImageBaseImplementT
: virtual public TWinHRGNAttachedImplements,
  virtual public TImageBaseImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;

/* include cWinRegionImageBase interface member definitions
 */
#define CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cwinregionimagebaseinterface.hxx"
#undef CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY

/* include cWinRegionImageBase member functions implement
 */
#define CWINREGIONIMAGEBASE_MEMBERS_ONLY
#define CWINREGIONIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#include "cwinregionimagebase.hxx"
#undef CWINREGIONIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#undef CWINREGIONIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinRegionImageBaseInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/24/2009
 **********************************************************************
 */
typedef cWinRegionImageBaseInterfaceT<>
cWinRegionImageBaseInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinRegionImageBaseInterface
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinRegionImageBaseInterface
: virtual public cWinRegionImageBaseInterfaceImplements
{
public:
    typedef cWinRegionImageBaseInterfaceImplements cImplements;
    typedef cWinRegionImageBaseInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cWinRegionImageBaseImplementImplements
 *
 *  Author: $author$
 *    Date: 11/24/2009
 **********************************************************************
 */
typedef cWinRegionImageBaseImplementT<>
cWinRegionImageBaseImplementImplements;
/**
 **********************************************************************
 *  Class: cWinRegionImageBaseImplement
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
class cWinRegionImageBaseImplement
: virtual public cWinRegionImageBaseImplementImplements
{
public:
    typedef cWinRegionImageBaseImplementImplements cImplements;
    typedef cWinRegionImageBaseImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGEBASEINTERFACE_HXX) || defined(CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY) */
