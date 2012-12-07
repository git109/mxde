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
 *   File: creaderevent.hxx
 *
 * Author: $author$
 *   Date: 3/31/2010
 **********************************************************************
 */
#if !defined(_CREADEREVENT_HXX) || defined(CREADEREVENT_MEMBERS_ONLY)
#if !defined(_CREADEREVENT_HXX) && !defined(CREADEREVENT_MEMBERS_ONLY)
#define _CREADEREVENT_HXX
#endif /* !defined(_CREADEREVENT_HXX) && !defined(CREADEREVENT_MEMBERS_ONLY) */

#if !defined(CREADEREVENT_MEMBERS_ONLY)
#include "creadereventinterface.hxx"
#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_IMPLEMENT_CLASS cReaderEvent;
class c_IMPLEMENT_CLASS cReaderEventImplement;

#undef CDB_CLASS
#define CDB_CLASS "cReaderEventT"
/**
 **********************************************************************
 *  Class: cReaderEventT
 *
 * Author: $author$
 *   Date: 3/31/2010
 **********************************************************************
 */
template
<class TDerives=cReaderEvent,
 class TReaderEventImplement=cReaderEventImplement,
 class TWhat=CHAR,
 class TEndWhat=TWhat,
 TEndWhat VEndWhat=NULL_CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TBase=cBase,
 class TImplements=TReaderEventImplement,
 class TExtends=TBase>

class c_INSTANCE_CLASS cReaderEventT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;

/* include cReaderEvent interface member definitions
 */
#define CREADEREVENTINTERFACE_MEMBERS_ONLY
#include "creadereventinterface.hxx"
#undef CREADEREVENTINTERFACE_MEMBERS_ONLY

    /**
     **********************************************************************
     *  Constructor: cReaderEventT
     *
     *       Author: $author$
     *         Date: 3/31/2010
     **********************************************************************
     */
    cReaderEventT()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cReaderEventT
     *
     *      Author: $author$
     *        Date: 3/31/2010
     **********************************************************************
     */
    virtual ~cReaderEventT()
    {
    }
#else /* !defined(CREADEREVENT_MEMBERS_ONLY) */
#endif /* !defined(CREADEREVENT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: OnRead
     *
     *    Author: $author$
     *      Date: 4/1/2010
     **********************************************************************
     */
    virtual TLENGTH OnRead
    (tWhat* what, tSize length)
#if defined(CREADEREVENT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CREADEREVENT_MEMBER_FUNCS_INTERFACE) */
    {
        TLENGTH count = 0;
#if !defined(CREADEREVENT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CREADEREVENT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CREADEREVENT_MEMBER_FUNCS_IMPLEMENT) */
        return count;
    }
#endif /* defined(CREADEREVENT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CREADEREVENT_MEMBERS_ONLY)
};
#undef CDB_CLASS

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CREADEREVENT_MEMBERS_ONLY) */
#endif /* !defined(CREADEREVENT_MEMBERS_ONLY) */

#endif /* !defined(_CREADEREVENT_HXX) || defined(CREADEREVENT_MEMBERS_ONLY) */
