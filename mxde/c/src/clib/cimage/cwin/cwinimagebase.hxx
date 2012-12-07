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
 *   File: cwinimagebase.hxx
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
#if !defined(_CWINIMAGEBASE_HXX) || defined(CWINIMAGEBASE_MEMBERS_ONLY)
#if !defined(_CWINIMAGEBASE_HXX) && !defined(CWINIMAGEBASE_MEMBERS_ONLY)
#define _CWINIMAGEBASE_HXX
#endif /* !defined(_CWINIMAGEBASE_HXX) && !defined(CWINIMAGEBASE_MEMBERS_ONLY) */

#if !defined(CWINIMAGEBASE_MEMBERS_ONLY)
#include "cwinimagebaseinterface.hxx"
#include "cwindc.hxx"

/* cWinImageBase definition
 */
class c_EXPORT_CLASS cWinImageBase;

#undef CDB_CLASS
#define CDB_CLASS "cWinImageBaseT"
/**
 **********************************************************************
 *  Class: cWinImageBaseT
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
template
<class TDerives=cWinImageBase,
 class TWinImageBaseImplement=cWinImageBaseImplement,
 class TWinImageBaseInterface=cWinImageBaseInterface,
 class TImageBaseInterface=cImageBaseInterface,
 class TWinDC=cWinDC,
 class TAttachedTo=HDC,
 class TUnattached=LONG,
 TUnattached VUnattached=NULL,
 class TInt=INT,
 class TSize=TSIZE,
 class TOffset=TOFFSET,
 class TImplements=TWinImageBaseImplement,
 class TExtends=TWinDC>
 
class cWinImageBaseT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;

/* include cWinImageBase interface member definitions
 */
#define CWINIMAGEBASEINTERFACE_MEMBERS_ONLY
#include "cwinimagebaseinterface.hxx"
#undef CWINIMAGEBASEINTERFACE_MEMBERS_ONLY

    /**
     **********************************************************************
     * Constructor: cWinImageBaseT
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cWinImageBaseT
    (tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isAcquired=false)
    : cExtends(attached, isAcquired)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImageBaseT
     *
     *     Author: $author$
     *       Date: 6/8/2009
     **********************************************************************
     */
    virtual ~cWinImageBaseT()
    {
        eError error;
        if ((error = CTHIS Released()))
            throw(error);
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cWinImageBaseExtends
 *
 *  Author: $author$
 *    Date: 6/8/2009
 **********************************************************************
 */
typedef cWinImageBaseT<>
cWinImageBaseExtends;
/**
 **********************************************************************
 *  Class: cWinImageBase
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageBase
: public cWinImageBaseExtends
{
public:
    typedef cWinImageBaseExtends cExtends;
    typedef cWinImageBase cDerives;
    /**
     **********************************************************************
     * Constructor: cWinImageBase
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cWinImageBase
    (HDC attached=NULL,
     bool isAcquired=false)
    : cExtends(attached, isAcquired)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImageBase
     *
     *     Author: $author$
     *       Date: 6/8/2009
     **********************************************************************
     */
    virtual ~cWinImageBase()
    {
        eError error;
        if ((error = Released()))
            throw(error);
    }
};

#else /* !defined(CWINIMAGEBASE_MEMBERS_ONLY) */
#endif /* !defined(CWINIMAGEBASE_MEMBERS_ONLY) */

#endif /* !defined(_CWINIMAGEBASE_HXX) || defined(CWINIMAGEBASE_MEMBERS_ONLY) */
