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
 *   File: csequence.hxx
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
#if !defined(_CSEQUENCE_HXX) || defined(CSEQUENCE_MEMBERS_ONLY)
#if !defined(_CSEQUENCE_HXX) && !defined(CSEQUENCE_MEMBERS_ONLY)
#define _CSEQUENCE_HXX
#endif /* !defined(_CSEQUENCE_HXX) && !defined(CSEQUENCE_MEMBERS_ONLY) */

#if !defined(CSEQUENCE_MEMBERS_ONLY)
#include "csequenceinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cSequence;

#undef CDB_CLASS
#define CDB_CLASS "cSequenceT"
/**
 **********************************************************************
 *  Class: cSequenceT
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
template
<class TDerives=cSequence,
 class TSequenceImplement=cSequenceImplement,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cInstanceBase,
 class TImplements=TSequenceImplement,
 class TExtends=TBase>
 
class c_INSTANCE_CLASS cSequenceT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cSequenceT cDerives;

/* include cSequence interface member definitions
 */
#define CSEQUENCEINTERFACE_MEMBERS_ONLY
#include "csequenceinterface.hxx"
#undef CSEQUENCEINTERFACE_MEMBERS_ONLY
#else /* !defined(CSEQUENCE_MEMBERS_ONLY) */
#endif /* !defined(CSEQUENCE_MEMBERS_ONLY) */

#define CTYPES_MEMBERS_ONLY
#define CTYPES_MEMBERS_STATIC virtual
#define CTYPES_MEMBERS_INLINE 
#define CTYPES_MEMBERS_CONST const

#if defined(CSEQUENCE_MEMBER_FUNCS_INTERFACE) 
/* include cTypes member functions interface
 */
#define CTYPES_MEMBER_FUNCS_INTERFACE
#include "ctypes.hxx"
#undef CTYPES_MEMBER_FUNCS_INTERFACE
#else /* defined(CSEQUENCE_MEMBER_FUNCS_INTERFACE) */
#if defined(CSEQUENCE_MEMBER_FUNCS_IMPLEMENT) 
/* include cTypes member functions implement
 */
#define CTYPES_MEMBER_FUNCS_IMPLEMENT
#include "ctypes.hxx"
#undef CTYPES_MEMBER_FUNCS_IMPLEMENT
#else /* defined(CSEQUENCE_MEMBER_FUNCS_IMPLEMENT) */
/* include cTypes member functions
 */
#include "ctypes.hxx"
#endif /* defined(CSEQUENCE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* defined(CSEQUENCE_MEMBER_FUNCS_INTERFACE) */

#undef CTYPES_MEMBERS_CONST
#undef CTYPES_MEMBERS_INLINE
#undef CTYPES_MEMBERS_STATIC
#undef CTYPES_MEMBERS_ONLY

    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 3/16/2009
     **********************************************************************
     */
    virtual tLength LengthOf
    (const tWhat* what) const 
#if defined(CSEQUENCE_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSEQUENCE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = Count(what);
        return count;
    }
#endif /* defined(CSEQUENCE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSEQUENCE_MEMBERS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cSequenceExtends
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceT<>
cSequenceExtends;
/**
 **********************************************************************
 *  Class: cSequence
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cSequence
: virtual public cSequenceImplement,
  public cSequenceExtends
{
public:
    typedef cSequenceImplement cImplements;
    typedef cSequenceExtends cExtends;
    typedef cSequence cDerives;
};

/*
 * TCHAR
 */
class c_INSTANCE_CLASS cTCHARSequence;
/**
 **********************************************************************
 * Typedef: cTCHARSequenceExtends
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceT
<cTCHARSequence,cTCHARSequenceImplement,TCHAR>
cTCHARSequenceExtends;
/**
 **********************************************************************
 *  Class: cTCHARSequence
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cTCHARSequence
: virtual public cTCHARSequenceImplement,
  public cTCHARSequenceExtends
{
public:
    typedef cTCHARSequenceImplement cImplements;
    typedef cTCHARSequenceExtends cExtends;
    typedef cTCHARSequence cDerives;
};


/*
 * WCHAR
 */
class c_INSTANCE_CLASS cWCHARSequence;
/**
 **********************************************************************
 * Typedef: cWCHARSequenceExtends
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceT
<cWCHARSequence,cWCHARSequenceImplement,WCHAR>
cWCHARSequenceExtends;
/**
 **********************************************************************
 *  Class: cWCHARSequence
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWCHARSequence
: virtual public cWCHARSequenceImplement,
  public cWCHARSequenceExtends
{
public:
    typedef cWCHARSequenceImplement cImplements;
    typedef cWCHARSequenceExtends cExtends;
    typedef cWCHARSequence cDerives;
};


/*
 * BYTE
 */
class c_INSTANCE_CLASS cBYTESequence;
/**
 **********************************************************************
 * Typedef: cBYTESequenceExtends
 *
 *  Author: $author$
 *    Date: 3/16/2009
 **********************************************************************
 */
typedef cSequenceT
<cBYTESequence,cBYTESequenceImplement,BYTE>
cBYTESequenceExtends;
/**
 **********************************************************************
 *  Class: cBYTESequence
 *
 * Author: $author$
 *   Date: 3/16/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cBYTESequence
: virtual public cBYTESequenceImplement,
  public cBYTESequenceExtends
{
public:
    typedef cBYTESequenceImplement cImplements;
    typedef cBYTESequenceExtends cExtends;
    typedef cBYTESequence cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSEQUENCE_MEMBERS_ONLY) */
#endif /* !defined(CSEQUENCE_MEMBERS_ONLY) */

#endif /* !defined(_CSEQUENCE_HXX) || defined(CSEQUENCE_MEMBERS_ONLY) */
