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
 *   File: cwinimagebaseinterface.hxx
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGEBASEINTERFACE_HXX) || defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINIMAGEBASEINTERFACE_HXX) && !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY)
#define _CWINIMAGEBASEINTERFACE_HXX
#endif /* !defined(_CWINIMAGEBASEINTERFACE_HXX) && !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY)
#include "cimagebaseinterface.hxx"
#include "cwinhdcattachedinterface.hxx"

/* cWinImageBase interface definition
 */
class c_INTERFACE_CLASS cWinImageBaseInterface;

#undef CDB_CLASS
#define CDB_CLASS "cWinImageBaseInterfaceT"
/**
 **********************************************************************
 *  Class: cWinImageBaseInterfaceT
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
template
<class TDerives=cWinImageBaseInterface,
 class TImageBaseInterface=cImageBaseInterface,
 class TWinHDCAttachedInterface=cWinHDCAttachedInterface,
 class TAttachedTo=HDC,
 class TUnattached=LONG,
 TUnattached VUnattached=NULL,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TWinHDCAttachedImplements=TWinHDCAttachedInterface,
 class TImplements=TImageBaseInterface>
 
class c_INTERFACE_CLASS cWinImageBaseInterfaceT
: virtual public TImplements,
  virtual public TWinHDCAttachedImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
#else /* !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) */

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

    typedef TAttachedTo tAttachedTo;
    enum { vUnattached = VUnattached };

#if !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) 
/* include cWinImageBase member functions interface
 */
#define CWINIMAGEBASE_MEMBERS_ONLY
#define CWINIMAGEBASE_MEMBER_FUNCS_INTERFACE
#include "cwinimagebase.hxx"
#undef CWINIMAGEBASE_MEMBER_FUNCS_INTERFACE
#undef CWINIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cWinImageBase implement definition
 */
class c_IMPLEMENT_CLASS cWinImageBaseImplement;

#undef CDB_CLASS
#define CDB_CLASS "cWinImageBaseImplementT"
/**
 **********************************************************************
 *  Class: cWinImageBaseImplementT
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
template
<class TDerives=cWinImageBaseImplement,
 class TWinImageBaseInterface=cWinImageBaseInterface,
 class TImageBaseImplement=cImageBaseImplement,
 class TImageBaseInterface=cImageBaseInterface,
 class TWinHDCAttachedImplement=cWinHDCAttachedImplement,
 class TWinHDCAttachedInterface=cWinHDCAttachedInterface,
 class TAttachedTo=HDC,
 class TUnattached=LONG,
 TUnattached VUnattached=NULL,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TWinHDCAttachedImplements=TWinHDCAttachedImplement,
 class TImageBaseImplements=TImageBaseImplement,
 class TImplements=TWinImageBaseInterface>
 
class cWinImageBaseImplementT
: virtual public TWinHDCAttachedImplements,
  virtual public TImageBaseImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cWinImageBaseImplementT cDerives;

/* include cWinImageBase interface member definitions
 */
#define CWINIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cwinimagebaseinterface.hxx"
#undef CWINIMAGEBASEINTERFACE_MEMBERS_ONLY

/* include cWinImageBase member functions implement
 */
#define CWINIMAGEBASE_MEMBERS_ONLY
#define CWINIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#include "cwinimagebase.hxx"
#undef CWINIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#undef CWINIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinImageBaseInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cWinImageBaseInterfaceT<>
cWinImageBaseInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinImageBaseInterface
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinImageBaseInterface
: virtual public cWinImageBaseInterfaceImplements
{
public:
    typedef cWinImageBaseInterfaceImplements cImplements;
    typedef cWinImageBaseInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cWinImageBaseImplementImplements
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cWinImageBaseImplementT<>
cWinImageBaseImplementImplements;
/**
 **********************************************************************
 *  Class: cWinImageBaseImplement
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinImageBaseImplement
: virtual public cWinImageBaseImplementImplements
{
public:
    typedef cWinImageBaseImplementImplements cImplements;
    typedef cWinImageBaseImplement cDerives;
};

#else /* !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEBASEINTERFACE_HXX) || defined(CWINIMAGEBASEINTERFACE_MEMBERS_ONLY) */
