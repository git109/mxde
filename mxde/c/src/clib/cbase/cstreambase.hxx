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
 *   File: cstreambase.hxx
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
#if defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) 
#if defined(_CSTREAMBASE_HXX) 
#define _CSTREAMBASE_HXX_OLD
#undef _CSTREAMBASE_HXX
#endif /* defined(_CSTREAMBASE_HXX) */
#endif /* defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) */

#ifndef _CSTREAMBASE_HXX
#define _CSTREAMBASE_HXX

#if !defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) 
#include "cstreaminterfacebase.hxx"
#include "cbase.hxx"

class cStreamBase;

#undef CDB_CLASS
#define CDB_CLASS "cStreamBaseT"
/**
 **********************************************************************
 *  Class: cStreamBaseT
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
template
<class TDerives=cStreamBase,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TInterfaceBase=cStreamInterfaceBase,
 class TBase=cBase,
 class TImplements=TInterfaceBase,
 class TExtends=TBase>
 
class cStreamBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

#define CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY
#include "cstreaminterfacebase.hxx"
#undef CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY

#else /* !defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) */

    /**
     **********************************************************************
     * Function: LengthOf
     *
     *   Author: $author$
     *     Date: 3/2/2009
     **********************************************************************
     */
    virtual tLength LengthOf
    (const tWhat* what) const 
#if defined(CSTREAMBASE_MEMBER_FUNCS_INTERFACE) 
    = 0;
#else /* defined(CSTREAMBASE_MEMBER_FUNCS_INTERFACE) */
    {
        tLength count = 0;
        if (what)
        while ((*what++) != vEndWhat)
            count++;
        return count;
    }
#endif /* defined(CSTREAMBASE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) 
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStreamBaseExtends
 *
 *  Author: $author$
 *    Date: 3/2/2009
 **********************************************************************
 */
typedef cStreamBaseT<cStreamBase>
cStreamBaseExtends;
/**
 **********************************************************************
 *  Class: cStreamBase
 *
 * Author: $author$
 *   Date: 3/2/2009
 **********************************************************************
 */
class cStreamBase
: public cStreamBaseExtends
{
public:
    typedef cStreamBaseExtends cExtends;
    typedef cStreamBase cDerives;
};

/*
 * TCHAR
 */
class cTCHARStreamBase;
/**
 **********************************************************************
 * Typedef: cTCHARStreamBaseExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamBaseT
<cTCHARStreamBase,
 TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 TCHAR, NULL_TCHAR, cTCHARStreamInterfaceBase>
cTCHARStreamBaseExtends;
/**
 **********************************************************************
 *  Class: cTCHARStreamBase
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARStreamBase
: public cTCHARStreamBaseExtends
{
public:
    typedef cTCHARStreamBaseExtends cExtends;
    typedef cTCHARStreamBase cDerives;
};

/*
 * WCHAR
 */
class cWCHARStreamBase;
/**
 **********************************************************************
 * Typedef: cWCHARStreamBaseExtends
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamBaseT
<cWCHARStreamBase,
 WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 WCHAR, NULL_WCHAR, cWCHARStreamInterfaceBase>
cWCHARStreamBaseExtends;
/**
 **********************************************************************
 *  Class: cWCHARStreamBase
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARStreamBase
: public cWCHARStreamBaseExtends
{
public:
    typedef cWCHARStreamBaseExtends cExtends;
    typedef cWCHARStreamBase cDerives;
};
#else /* !defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) */
#endif /* !defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) */

#endif /* _CSTREAMBASE_HXX */

#if defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) 
#if defined(_CSTREAMBASE_HXX_OLD) 
#define _CSTREAMBASE_HXX
#undef _CSTREAMBASE_HXX_OLD
#endif /* defined(_CSTREAMBASE_HXX_OLD) */
#endif /* defined(CSTREAMBASE_MEMBER_FUNCS_ONLY) */
