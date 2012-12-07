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
 *   File: cstreaminterfacebase.hxx
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
#if defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) 
#if defined(_CSTREAMINTERFACEBASE_HXX) 
#define _CSTREAMINTERFACEBASE_HXX_OLD 
#undef _CSTREAMINTERFACEBASE_HXX
#endif /* defined(_CSTREAMINTERFACEBASE_HXX) */
#endif /* defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) */

#ifndef _CSTREAMINTERFACEBASE_HXX
#define _CSTREAMINTERFACEBASE_HXX

#if !defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) 
#include "cinterfacebase.hxx"

class c_INTERFACE_CLASS cStreamInterfaceBase;

#undef CDB_CLASS
#define CDB_CLASS "cStreamInterfaceBaseT"
/**
 **********************************************************************
 *  Class: cStreamInterfaceBaseT
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
template
<class TDerives=cStreamInterfaceBase,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TInterfaceBase=cInterfaceBase,
 class TImplements=TInterfaceBase>
 
class c_INTERFACE_CLASS cStreamInterfaceBaseT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
#else /* !defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) */
#endif /* !defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) */

    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TEndWhat tEndWhat;
    enum { vUndefinedLength = VUndefinedLength};
    enum { vEndWhat = VEndWhat};

#if !defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) 
#define CSTREAMBASE_MEMBER_FUNCS_ONLY
#define CSTREAMBASE_MEMBER_FUNCS_INTERFACE
#include "cstreambase.hxx"
#undef CSTREAMBASE_MEMBER_FUNCS_INTERFACE
#undef CSTREAMBASE_MEMBER_FUNCS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cStreamInterfaceBaseImplements
 *
 *  Author: $author$
 *    Date: 2/27/2009
 **********************************************************************
 */
typedef cStreamInterfaceBaseT<cStreamInterfaceBase>
cStreamInterfaceBaseImplements;
/**
 **********************************************************************
 *  Class: cStreamInterfaceBase
 *
 * Author: $author$
 *   Date: 2/27/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cStreamInterfaceBase
: virtual public cStreamInterfaceBaseImplements
{
public:
    typedef cStreamInterfaceBaseImplements cImplements;
    typedef cStreamInterfaceBase cDerives;
};

class cTCHARStreamInterfaceBase;
/**
 **********************************************************************
 * Typedef: cTCHARStreamInterfaceBaseImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamInterfaceBaseT<cTCHARStreamInterfaceBase,TCHAR>
cTCHARStreamInterfaceBaseImplements;
/**
 **********************************************************************
 *  Class: cTCHARStreamInterfaceBase
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cTCHARStreamInterfaceBase
: public cTCHARStreamInterfaceBaseImplements
{
public:
    typedef cTCHARStreamInterfaceBaseImplements cExtends;
    typedef cTCHARStreamInterfaceBase cDerives;
};

class cWCHARStreamInterfaceBase;
/**
 **********************************************************************
 * Typedef: cWCHARStreamInterfaceBaseImplements
 *
 *  Author: $author$
 *    Date: 3/3/2009
 **********************************************************************
 */
typedef cStreamInterfaceBaseT<cWCHARStreamInterfaceBase,WCHAR>
cWCHARStreamInterfaceBaseImplements;
/**
 **********************************************************************
 *  Class: cWCHARStreamInterfaceBase
 *
 * Author: $author$
 *   Date: 3/3/2009
 **********************************************************************
 */
class cWCHARStreamInterfaceBase
: public cWCHARStreamInterfaceBaseImplements
{
public:
    typedef cWCHARStreamInterfaceBaseImplements cExtends;
    typedef cWCHARStreamInterfaceBase cDerives;
};
#else /* !defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) */
#endif /* !defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) */

#endif /* _CSTREAMINTERFACEBASE_HXX */

#if defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) 
#if defined(_CSTREAMINTERFACEBASE_HXX_OLD) 
#define _CSTREAMINTERFACEBASE_HXX 
#undef _CSTREAMINTERFACEBASE_HXX_OLD
#endif /* defined(_CSTREAMINTERFACEBASE_HXX_OLD) */
#endif /* defined(CSTREAMINTERFACEBASE_MEMBER_DEFS_ONLY) */
