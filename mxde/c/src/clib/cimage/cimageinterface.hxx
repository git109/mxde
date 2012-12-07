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
 *   File: cimageinterface.hxx
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
#if !defined(_CIMAGEINTERFACE_HXX) || defined(CIMAGEINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGEINTERFACE_HXX) && !defined(CIMAGEINTERFACE_MEMBERS_ONLY)
#define _CIMAGEINTERFACE_HXX
#endif /* !defined(_CIMAGEINTERFACE_HXX) && !defined(CIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEINTERFACE_MEMBERS_ONLY)
#include "cimagebaseinterface.hxx"

/* cImage interface definition
 */
class c_INTERFACE_CLASS cImageInterface;

#undef CDB_CLASS
#define CDB_CLASS "cImageInterfaceT"
/**
 **********************************************************************
 *  Class: cImageInterfaceT
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
template
<class TDerives=cImageInterface,
 class TInt=INT,
 class TOffset=TOFFSET,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TInterfaceBase=cImageBaseInterface,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cImageInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tImageInterface;
#else /* !defined(CIMAGEINTERFACE_MEMBERS_ONLY) */
    typedef TImageInterface tImageInterface;
#endif /* !defined(CIMAGEINTERFACE_MEMBERS_ONLY) */

    typedef TInt tInt;
    typedef TOffset tOffset;
    typedef TSize tSize;
    typedef TLength tLength;

#if !defined(CIMAGEINTERFACE_MEMBERS_ONLY) 
/* include cImage member functions interface
 */
#define CIMAGE_MEMBERS_ONLY
#define CIMAGE_MEMBER_FUNCS_INTERFACE
#include "cimage.hxx"
#undef CIMAGE_MEMBER_FUNCS_INTERFACE
#undef CIMAGE_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cImage implement definition
 */
class c_IMPLEMENT_CLASS cImageImplement;

#undef CDB_CLASS
#define CDB_CLASS "cImageImplementT"
/**
 **********************************************************************
 *  Class: cImageImplementT
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
template
<class TDerives=cImageImplement,
 class TImageInterface=cImageInterface,
 class TBaseImplements=cImageBaseImplement,
 class TInt=INT,
 class TOffset=TOFFSET,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TImplements=TImageInterface>
 
class cImageImplementT
: virtual public TBaseImplements,
  virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cImageImplementT cDerives;

/* include cImage interface member definitions
 */
#define CIMAGEINTERFACE_MEMBERS_ONLY
#include "cimageinterface.hxx"
#undef CIMAGEINTERFACE_MEMBERS_ONLY

/* include cImage member functions implement
 */
#define CIMAGE_MEMBERS_ONLY
#define CIMAGE_MEMBER_FUNCS_IMPLEMENT
#include "cimage.hxx"
#undef CIMAGE_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImageInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cImageInterfaceT<cImageInterface>
cImageInterfaceImplements;
/**
 **********************************************************************
 *  Class: cImageInterface
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageInterface
: virtual public cImageInterfaceImplements
{
public:
    typedef cImageInterfaceImplements cImplements;
    typedef cImageInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cImageImplementImplements
 *
 *  Author: $author$
 *    Date: 5/27/2009
 **********************************************************************
 */
typedef cImageImplementT
<cImageImplement,cImageInterface>
cImageImplementImplements;
/**
 **********************************************************************
 *  Class: cImageImplement
 *
 * Author: $author$
 *   Date: 5/27/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImageImplement
: virtual public cImageImplementImplements
{
public:
    typedef cImageImplementImplements cImplements;
    typedef cImageImplement cDerives;
};

#else /* !defined(CIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEINTERFACE_HXX) || defined(CIMAGEINTERFACE_MEMBERS_ONLY) */
