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
 *   File: csequencebase.hxx
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
#if defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) 
#if defined(_CSEQUENCEBASE_HXX) 
#undef _CSEQUENCEBASE_HXX
#define _CSEQUENCEBASE_HXX_OLD
#endif /* defined(_CSEQUENCEBASE_HXX) */
#endif /* defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) */

#ifndef _CSEQUENCEBASE_HXX
#define _CSEQUENCEBASE_HXX

#if !defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) 
#include "cbase.hxx"

class cSequenceBase;

#undef CDB_CLASS
#define CDB_CLASS "cSequenceBaseT"
/**
 **********************************************************************
 *  Class: cSequenceBaseT
 *
 * Author: $author$
 *   Date: 3/4/2009
 **********************************************************************
 */
template
<class TDerives=cSequenceBase,
 class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TBase=cBase,
 class TExtends=TBase>
 
class cSequenceBaseT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;
#else /* !defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) */
#endif /* !defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) */

    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TEndWhat tEndWhat;
    enum { vUndefinedLength = VUndefinedLength};
    enum { vEndWhat = VEndWhat};

#if !defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) 
};
#undef CDB_CLASS
#else /* !defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) */
#endif /* !defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) */

#endif /* _CSEQUENCEBASE_HXX */

#if defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) 
#if defined(_CSEQUENCEBASE_HXX) 
#undef _CSEQUENCEBASE_HXX_OLD
#define _CSEQUENCEBASE_HXX
#endif /* defined(_CSEQUENCEBASE_HXX) */
#endif /* defined(CSEQUENCEBASE_MEMBER_DEFS_ONLY) */
