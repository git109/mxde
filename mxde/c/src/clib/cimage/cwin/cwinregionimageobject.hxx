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
 *   File: cwinregionimageobject.hxx
 *
 * Author: $author$
 *   Date: 2/14/2010
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGEOBJECT_HXX) || defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGEOBJECT_HXX) && !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY)
#define _CWINREGIONIMAGEOBJECT_HXX
#endif /* !defined(_CWINREGIONIMAGEOBJECT_HXX) && !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY)
#include "cwinregionimage.hxx"
#include "cwinregion.hxx"
#include "cimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRegionImageObject
 *
 * Author: $author$
 *   Date: 2/14/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRegionImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    
    cWinRegionImage& m_regionImage;
    cWinRegionInterface& m_region;
    
    /**
     **********************************************************************
     *  Constructor: cWinRegionImageObject
     *
     *       Author: $author$
     *         Date: 2/14/2010
     **********************************************************************
     */
    cWinRegionImageObject
    (cWinRegionImage& regionImage,
     cWinRegionInterface& region,
     tSize width=1, tSize height=1)
    : cExtends(regionImage, width, height),
      m_regionImage(regionImage),
      m_region(region)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRegionImageObject
     *
     *      Author: $author$
     *        Date: 2/14/2010
     **********************************************************************
     */
    virtual ~cWinRegionImageObject()
    {
    }
#else /* !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/14/2010
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h) 
    {
        eError error = e_ERROR_NONE;
        //if (!(m_region.SetRect(x,y, x+w*m_width,y+h*m_height)))
        if (!(m_region.SetRect(x,y, x+w+m_width-1,y+h+m_height-1)))
            m_regionImage.CombineRegion(m_region);
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGEOBJECT_HXX) || defined(CWINREGIONIMAGEOBJECT_MEMBERS_ONLY) */
