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
 *   File: cwinregionimagebrush.hxx
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGEBRUSH_HXX) || defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGEBRUSH_HXX) && !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY)
#define _CWINREGIONIMAGEBRUSH_HXX
#endif /* !defined(_CWINREGIONIMAGEBRUSH_HXX) && !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY)
#include "cwinregionimagebase.hxx"
#include "cwinregion.hxx"
#include "cwinrect.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRegionImageBrush
 *
 * Author: $author$
 *   Date: 11/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRegionImageBrush
: virtual public cWinRegionImageBaseImplement,
  public cWinRegion
{
public:
    typedef cWinRegionImageBaseImplement cImplements;
    typedef cWinRegion cExtends;
    
    cWinRegionImageBase& m_winRegionImage;
    
    /**
     **********************************************************************
     *  Constructor: cWinRegionImageBrush
     *
     *       Author: $author$
     *         Date: 11/24/2009
     **********************************************************************
     */
    cWinRegionImageBrush
    (cWinRegionImageBase& winRegionImage,
     HRGN attached=NULL,
     bool isCreated=false) 
    : cExtends(attached, isCreated),
      m_winRegionImage(winRegionImage)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRegionImageBrush
     *
     *      Author: $author$
     *        Date: 11/24/2009
     **********************************************************************
     */
    virtual ~cWinRegionImageBrush()
    {
    }
#else /* !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Plot
     *
     *    Author: $author$
     *      Date: 11/24/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageBaseInterface& image,
     tOffset x, tOffset y)
#if defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        Fill(image, x,y, 1,1);
#if !defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Fill
     *
     *    Author: $author$
     *      Date: 11/24/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageBaseInterface& image,
     tOffset x, tOffset y, tSize w, tSize h)
#if defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_IMPLEMENT)
        cWinRECT rect(x,y, x+w,y+h);
        int iMode = RGN_OR;
        HRGN hBrush;
        HRGN hRGN;
        if ((hBrush = Attached()))
        if ((hRGN = m_winRegionImage.Attached()))
        if ((SetRectRgn
            (hBrush, rect.left, rect.top, 
             rect.right, rect.bottom)))
        {
            CombineRgn(hRGN, hRGN, hBrush, iMode);
        }
#else /* !defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGIONIMAGEBRUSH_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGEBRUSH_HXX) || defined(CWINREGIONIMAGEBRUSH_MEMBERS_ONLY) */
