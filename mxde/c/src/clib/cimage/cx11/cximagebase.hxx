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
 *   File: cximagebase.hxx
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
#if !defined(_CXIMAGEBASE_HXX) || defined(CXIMAGEBASE_MEMBERS_ONLY)
#if !defined(_CXIMAGEBASE_HXX) && !defined(CXIMAGEBASE_MEMBERS_ONLY)
#define _CXIMAGEBASE_HXX
#endif /* !defined(_CXIMAGEBASE_HXX) && !defined(CXIMAGEBASE_MEMBERS_ONLY) */

#if !defined(CXIMAGEBASE_MEMBERS_ONLY)
#include "cximagebaseinterface.hxx"
#include "cxgcinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class cXImageBase;

#undef CDB_CLASS
#define CDB_CLASS "cXImageBase"
/**
 **********************************************************************
 *  Class: cXImageBaseT
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
template
<class TDerives=cXImageBase,
 class TXImageBaseImplement=cXImageBaseImplement,
 class TXImageBaseInterface=cXImageBaseInterface,
 class TImageBaseInterface=cImageBaseInterface,
 class TXGCInterface=cXGCInterface,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TXBase=cXBase,
 class TImplements=TXImageBaseImplement,
 class TExtends=TXBase>

class cXImageBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;

/* include cXImageBase interface member definitions
 */
#define CXIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cximagebaseinterface.hxx"
#undef CXIMAGEBASEINTERFACE_MEMBERS_ONLY

    tXGCInterface& m_gc;

    /**
     **********************************************************************
     *  Constructor: cXImageBaseT
     *
     *       Author: $author$
     *         Date: 7/1/2009
     **********************************************************************
     */
    cXImageBaseT
    (tXGCInterface& gc)
    : m_gc(gc)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXImageBaseT
     *
     *      Author: $author$
     *        Date: 7/1/2009
     **********************************************************************
     */
    virtual ~cXImageBaseT()
    {
    }
#else /* !defined(CXIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEBASE_MEMBERS_ONLY) */

#if !defined(CXIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) 
    /**
     **********************************************************************
     * Function: GCInterface
     *
     *   Author: $author$
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual tXGCInterface& GCInterface() const
#if defined(CXIMAGEBASE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXIMAGEBASE_MEMBER_FUNCS_INTERFACE */
    {
        return m_gc;
    }
#endif /* defined(CXIMAGEBASE_MEMBER_FUNCS_INTERFACE) */
#else /* !defined(CXIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXIMAGEBASE_MEMBER_FUNCS_IMPLEMENT) */

#if !defined(CXIMAGEBASE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cXImageBaseExtends
 *
 *  Author: $author$
 *    Date: 7/1/2009
 **********************************************************************
 */
typedef cXImageBaseT<>
cXImageBaseExtends;
/**
 **********************************************************************
 *  Class: cXImageBase
 *
 * Author: $author$
 *   Date: 7/1/2009
 **********************************************************************
 */
class cXImageBase
: public cXImageBaseExtends
{
public:
    typedef cXImageBaseExtends cExtends;
    typedef cXImageBase cDerives;
    /**
     **********************************************************************
     * Constructor: cXImageBase
     *
     *      Author: $author$
     *        Date: 7/1/2009
     **********************************************************************
     */
    cXImageBase
    (cXGCInterface& gc) 
    : cExtends(gc)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXImageBase
     *
     *     Author: $author$
     *       Date: 7/1/2009
     **********************************************************************
     */
    virtual ~cXImageBase()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEBASE_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGEBASE_HXX) || defined(CXIMAGEBASE_MEMBERS_ONLY) */
