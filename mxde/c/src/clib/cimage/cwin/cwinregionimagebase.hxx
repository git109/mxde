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
 *   File: cwinregionimagebase.hxx
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGEBASE_HXX) || defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGEBASE_HXX) && !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY)
#define _CWINREGIONIMAGEBASE_HXX
#endif /* !defined(_CWINREGIONIMAGEBASE_HXX) && !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY)
#include "cwinregionimagebaseinterface.hxx"
#include "cwinregion.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinRegionImageBase;

#undef CDB_CLASS
#define CDB_CLASS "cWinRegionImageBaseT"
/**
 **********************************************************************
 *  Class: cWinRegionImageBaseT
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
template
<class TDerives=cWinRegionImageBase,
 class TWinRegionImageBaseImplement=cWinRegionImageBaseImplement,
 class TWinRegionImageBaseInterface=cWinRegionImageBaseInterface,
 class TImageBaseInterface=cImageBaseInterface,
 class TWinRegion=cWinRegion,
 class TAttachedTo=HRGN,
 class TUnattached=LONG,
 TUnattached VUnattached=NULL,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TImplements=TWinRegionImageBaseImplement,
 class TExtends=TWinRegion>

class c_EXPORT_CLASS cWinRegionImageBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    
/* include cWinRegionImageBase interface member definitions
 */
#define CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cwinregionimagebaseinterface.hxx"
#undef CWINREGIONIMAGEBASEINTERFACE_MEMBERS_ONLY

    /**
     **********************************************************************
     *  Constructor: cWinRegionImageBaseT
     *
     *       Author: $author$
     *         Date: 11/28/2009
     **********************************************************************
     */
    cWinRegionImageBaseT
    (tImageBaseInterface& image,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false)
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cWinRegionImageBaseT
     *
     *       Author: $author$
     *         Date: 11/24/2009
     **********************************************************************
     */
    cWinRegionImageBaseT
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isCreated=false)
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRegionImageBaseT
     *
     *      Author: $author$
     *        Date: 11/24/2009
     **********************************************************************
     */
    virtual ~cWinRegionImageBaseT()
    {
    }
#else /* !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinRegionImageBaseExtends
 *
 *  Author: $author$
 *    Date: 11/24/2009
 **********************************************************************
 */
typedef cWinRegionImageBaseT<>
cWinRegionImageBaseExtends;
/**
 **********************************************************************
 *  Class: cWinRegionImageBase
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRegionImageBase
: public cWinRegionImageBaseExtends
{
public:
    typedef cWinRegionImageBaseExtends cExtends;
    typedef cWinRegionImageBase cDerives;
    /**
     **********************************************************************
     * Constructor: cWinRegionImageBase
     *
     *      Author: $author$
     *        Date: 11/24/2009
     **********************************************************************
     */
    cWinRegionImageBase
    (HRGN attached=NULL,
     bool isCreated=false)
    : cExtends(attached, isCreated) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinRegionImageBase
     *
     *     Author: $author$
     *       Date: 11/24/2009
     **********************************************************************
     */
    virtual ~cWinRegionImageBase()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGEBASE_HXX) || defined(CWINREGIONIMAGEBASE_MEMBERS_ONLY) */
