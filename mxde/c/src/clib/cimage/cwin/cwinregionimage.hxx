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
 *   File: cwinregionimage.hxx
 *
 * Author: $author$
 *   Date: 11/26/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGE_HXX) || defined(CWINREGIONIMAGE_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGE_HXX) && !defined(CWINREGIONIMAGE_MEMBERS_ONLY)
#define _CWINREGIONIMAGE_HXX
#endif /* !defined(_CWINREGIONIMAGE_HXX) && !defined(CWINREGIONIMAGE_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGE_MEMBERS_ONLY)
#include "cwinregionimageinterface.hxx"
#include "cwinregion.hxx"
#include "cimage.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRegionImage
 *
 * Author: $author$
 *   Date: 11/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRegionImage
: virtual public cWinRegionImageImplement,
  public cImage
{
public:
    typedef cWinRegionImageImplement cImplements;
    typedef cImage cExtends;
    
    cWinRegionInterface& m_region;
    
    /**
     **********************************************************************
     *  Constructor: cWinRegionImage
     *
     *       Author: $author$
     *         Date: 11/26/2009
     **********************************************************************
     */
    cWinRegionImage
    (cWinRegionInterface& region,
     cImageInterface* image=0) 
    : cExtends(image),
      m_region(region)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRegionImage
     *
     *      Author: $author$
     *        Date: 11/26/2009
     **********************************************************************
     */
    virtual ~cWinRegionImage()
    {
    }
#else /* !defined(CWINREGIONIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: CombineRegion
     *
     *   Author: $author$
     *     Date: 2/14/2010
     **********************************************************************
     */
    virtual eError CombineRegion
    (cWinRegionInterface& region, INT combineMode = RGN_OR) 
#if defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_ATTACHED;
        HRGN hRgn;
        if ((hRgn = region.Attached()))
            error = CombineRegion(hRgn, combineMode);
#if !defined(CWINREGIONIMAGE_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINREGIONIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGIONIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CombineRegion
     *
     *   Author: $author$
     *     Date: 2/14/2010
     **********************************************************************
     */
    virtual eError CombineRegion
    (HRGN hRgn, INT combineMode = RGN_OR) 
#if defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINREGIONIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        eError error2;
        HRGN hRgn2;
        
        if ((hRgn2 = m_region.Attached()))
            error = m_region.Combine(hRgn, combineMode);
        else
        if (combineMode != RGN_AND)
        {
            if (!(error = m_region.CreateRect(0,0, 1,1)))
                error = m_region.Copy(hRgn);
        }       
        else
        return e_ERROR_NONE;
#else /* !defined(CWINREGIONIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINREGIONIMAGE_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Region
     *
     *    Author: $author$
     *      Date: 11/26/2009
     **********************************************************************
     */
    virtual cWinRegionInterface& Region() const
#if defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
        cWinRegionInterface& region = (cWinRegionInterface&)(m_region);
        return region;
    }
#endif /* defined(CWINREGIONIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINREGIONIMAGE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGE_HXX) || defined(CWINREGIONIMAGE_MEMBERS_ONLY) */
