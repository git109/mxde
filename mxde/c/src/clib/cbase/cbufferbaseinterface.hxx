/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cbufferbaseinterface.hxx
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
#if !defined(_CBUFFERBASEINTERFACE_HXX) || defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CBUFFERBASEINTERFACE_HXX) && !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY)
#define _CBUFFERBASEINTERFACE_HXX
#endif /* !defined(_CBUFFERBASEINTERFACE_HXX) && !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY)
#include "cstoreinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cBufferBaseInterface;

#undef CDB_CLASS
#define CDB_CLASS "cBufferBaseInterfaceT"
/**
 **********************************************************************
 *  Class: cBufferBaseInterfaceT
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
template
<class TDerives=cBufferBaseInterface,
 class TInterfaceBase=cInterfaceBase,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TInterfaceBase>

class c_INTERFACE_CLASS cBufferBaseInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives tBufferBaseInterface;
#else /* !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY) */
    typedef TBufferBaseInterface tBufferBaseInterface;
#endif /* !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY) */

/* include cStore interface member definitions
 */
#define CSTOREINTERFACE_MEMBERS_ONLY
#include "cstoreinterface.hxx"
#undef CSTOREINTERFACE_MEMBERS_ONLY

#if !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY)
/* include cBufferBase member functions interface
 */
#define CBUFFERBASE_MEMBERS_ONLY
#define CBUFFERBASE_MEMBER_FUNCS_INTERFACE
#include "cbufferbase.hxx"
#undef CBUFFERBASE_MEMBER_FUNCS_INTERFACE
#undef CBUFFERBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cBufferBaseImplement;

#undef CDB_CLASS
#define CDB_CLASS "cBufferBaseImplementT"
/**
 **********************************************************************
 *  Class: cBufferBaseImplementT
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
template
<class TDerives=cBufferBaseImplement,
 class TBufferBaseInterface=cBufferBaseInterface,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TWhence=eSeek,
 TWhence VWhenceCurrent=e_SEEK_CUR,
 TWhence VWhenceBegin=e_SEEK_SET,
 TWhence VWhenceEnd=e_SEEK_END,
 class TImplements=TBufferBaseInterface>

class c_IMPLEMENT_CLASS cBufferBaseImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    
/* include cBufferBase interface member definitions
 */
#define CBUFFERBASEINTERFACE_MEMBERS_ONLY
#include "cbufferbaseinterface.hxx"
#undef CBUFFERBASEINTERFACE_MEMBERS_ONLY

/* include cBufferBase member functions implement
 */
#define CBUFFERBASE_MEMBERS_ONLY
#define CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT
#include "cbufferbase.hxx"
#undef CBUFFERBASE_MEMBER_FUNCS_IMPLEMENT
#undef CBUFFERBASE_MEMBERS_ONLY
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CBUFFERBASEINTERFACE_HXX) || defined(CBUFFERBASEINTERFACE_MEMBERS_ONLY) */
