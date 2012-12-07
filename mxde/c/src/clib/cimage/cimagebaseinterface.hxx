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
 *   File: cimagebaseinterface.hxx
 *
 * Author: $author$
 *   Date: 6/7/2009
 **********************************************************************
 */
#if !defined(_CIMAGEBASEINTERFACE_HXX) || defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGEBASEINTERFACE_HXX) && !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY)
#define _CIMAGEBASEINTERFACE_HXX
#endif /* !defined(_CIMAGEBASEINTERFACE_HXX) && !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

/**
 **********************************************************************
 *   Enum: eOctant
 *
 * Author: $author$
 *   Date: 7/17/2009
 **********************************************************************
 */
typedef int eOctant;
enum
{
    e_OCTANT_NONE = 0,

    e_OCTANT_1 = (1 << 1),
    e_OCTANT_2 = (1 << 2),

    e_OCTANT_3 = (1 << 3),
    e_OCTANT_4 = (1 << 4),

    e_OCTANT_5 = (1 << 5),
    e_OCTANT_6 = (1 << 6),

    e_OCTANT_7 = (1 << 7),
    e_OCTANT_8 = (1 << 8),

    e_OCTANT_NEXT = (e_OCTANT_8 << 1),
    e_OCTANT_ALL  = (e_OCTANT_NEXT-1)
};

/**
 **********************************************************************
 *   Enum: eQuadrant
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
typedef int eQuadrant;
enum
{
    e_QUADRANT_ALL = e_OCTANT_ALL,

    e_QUADRANT_1 = (e_OCTANT_1|e_OCTANT_2),
    e_QUADRANT_2 = (e_OCTANT_3|e_OCTANT_4),
    e_QUADRANT_3 = (e_OCTANT_5|e_OCTANT_6),
    e_QUADRANT_4 = (e_OCTANT_7|e_OCTANT_8),

    e_QUADRANT_TOP_RIGHT    = (e_QUADRANT_1),
    e_QUADRANT_BOTTOM_RIGHT = (e_QUADRANT_2),
    e_QUADRANT_BOTTOM_LEFT  = (e_QUADRANT_3),
    e_QUADRANT_TOP_LEFT     = (e_QUADRANT_4)
};

/* cImageBase interface definition
 */
class c_INTERFACE_CLASS cImageBaseInterface;

#undef CDB_CLASS
#define CDB_CLASS "cImageBaseInterfaceT"
/**
 **********************************************************************
 *  Class: cImageBaseInterfaceT
 *
 * Author: $author$
 *   Date: 6/7/2009
 **********************************************************************
 */
template
<class TDerives=cImageBaseInterface,
 class TInterfaceBase=cInterfaceBase,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cImageBaseInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tImageBaseInterface;
#else /* !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) */
    typedef TImageBaseInterface tImageBaseInterface;
#endif /* !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) */

    typedef TInt tInt;
    typedef TSize tSize;
    typedef TOffset tOffset;

#if !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) 
/* include cImageBase member functions interface
 */
#define CIMAGEBASE_MEMBERS_ONLY
#define CIMAGEBASE_MEMBER_FUNCS_INTERFACE
#include "cimagebase.hxx"
#undef CIMAGEBASE_MEMBER_FUNCS_INTERFACE
#undef CIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

/* cImageBase implement definition
 */
class c_IMPLEMENT_CLASS cImageBaseImplement;

#undef CDB_CLASS
#define CDB_CLASS "cImageBaseImplementT"
/**
 **********************************************************************
 *  Class: cImageBaseImplementT
 *
 * Author: $author$
 *   Date: 6/7/2009
 **********************************************************************
 */
template
<class TDerives=cImageBaseImplement,
 class TImageBaseInterface=cImageBaseInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TImplements=TImageBaseInterface>
 
class c_IMPLEMENT_CLASS cImageBaseImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cImageBaseImplementT cDerives;

/* include cImageBase interface member definitions
 */
#define CIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cimagebaseinterface.hxx"
#undef CIMAGEBASEINTERFACE_MEMBERS_ONLY

/* include cImageBase member functions implement
 */
#define CIMAGEBASE_MEMBERS_ONLY
#define CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#include "cimagebase.hxx"
#undef CIMAGEBASE_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGEBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImageBaseInterfaceImplements
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cImageBaseInterfaceT<>
cImageBaseInterfaceImplements;
/**
 **********************************************************************
 *  Class: cImageBaseInterface
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageBaseInterface
: virtual public cImageBaseInterfaceImplements
{
public:
    typedef cImageBaseInterfaceImplements cImplements;
    typedef cImageBaseInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cImageBaseImplementImplements
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cImageBaseImplementT<>
cImageBaseImplementImplements;
/**
 **********************************************************************
 *  Class: cImageBaseImplement
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImageBaseImplement
: virtual public cImageBaseImplementImplements
{
public:
    typedef cImageBaseImplementImplements cImplements;
    typedef cImageBaseImplement cDerives;
};

#else /* !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEBASEINTERFACE_HXX) || defined(CIMAGEBASEINTERFACE_MEMBERS_ONLY) */
