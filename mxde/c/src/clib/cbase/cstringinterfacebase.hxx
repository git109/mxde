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
 *   File: cstringinterfacebase.hxx
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
#if defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) 
#define _CSTRINGINTERFACEBASE_HXX_OLD _CSTRINGINTERFACEBASE_HXX
#undef _CSTRINGINTERFACEBASE_HXX
#endif /* defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) */

#ifndef _CSTRINGINTERFACEBASE_HXX
#define _CSTRINGINTERFACEBASE_HXX

#if !defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) 
#include "cstreaminterfacebase.hxx"

class c_INTERFACE_CLASS cStringInterfaceBase;

#undef CDB_CLASS
#define CDB_CLASS "cStringInterfaceBaseT"
/**
 **********************************************************************
 *  Class: cStringInterfaceBaseT
 *
 * Author: $author$
 *   Date: 2/28/2009
 **********************************************************************
 */
template
<class TDerives=cStringInterfaceBase,
 class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TEndChar=TChar,
 TEndChar VEndChar=NULL_CHAR,
 class TStreamInterfaceBase=cStreamInterfaceBase,
 class TImplements=TStreamInterfaceBase>
 
class c_INTERFACE_CLASS cStringInterfaceBaseT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef cStringInterfaceBaseT cDerives;
#else /* !defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) */
#endif /* !defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) */

    typedef TChar tChar;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vUndefinedLength = VUndefinedLength};
    enum { vEndChar = VEndChar};

    typedef tChar tWhat;
    enum { vEndWhat = vEndChar};

#if !defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) 
};
#undef CDB_CLASS
#else /* !defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) */
#endif /* !defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) */

#endif /* _CSTRINGINTERFACEBASE_HXX */

#if defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) 
#undef _CSTRINGINTERFACEBASE_HXX
#define _CSTRINGINTERFACEBASE_HXX _CSTRINGINTERFACEBASE_HXX_OLD
#undef _CSTRINGINTERFACEBASE_HXX_OLD
#endif /* defined(CSTRINGINTERFACEBASE_MEMBER_DEFS_ONLY) */
