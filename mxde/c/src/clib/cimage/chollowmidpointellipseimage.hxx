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
 *   File: chollowmidpointellipseimage.hxx
 *
 * Author: $author$
 *   Date: 2/9/2010
 **********************************************************************
 */
#if !defined(_CHOLLOWMIDPOINTELLIPSEIMAGE_HXX) || defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
#if !defined(_CHOLLOWMIDPOINTELLIPSEIMAGE_HXX) && !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
#define _CHOLLOWMIDPOINTELLIPSEIMAGE_HXX
#endif /* !defined(_CHOLLOWMIDPOINTELLIPSEIMAGE_HXX) && !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

#if !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
#include "chollowmidpointellipse.hxx"
#include "cbaseimage.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cHollowMidpointEllipseImage;
/**
 **********************************************************************
 * Typedef: cHollowMidpointEllipseImageExtend
 *
 *  Author: $author$
 *    Date: 2/9/2010
 **********************************************************************
 */
typedef cHollowMidpointEllipseT
<cHollowMidpointEllipseImage, cBaseImage, cImageInterface>
cHollowMidpointEllipseImageExtend;
/**
 **********************************************************************
 *  Class: cHollowMidpointEllipseImage
 *
 * Author: $author$
 *   Date: 2/9/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cHollowMidpointEllipseImage
: public cHollowMidpointEllipseImageExtend
{
public:
    typedef cHollowMidpointEllipseImageExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cHollowMidpointEllipseImage
     *
     *       Author: $author$
     *         Date: 2/9/2010
     **********************************************************************
     */
    cHollowMidpointEllipseImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
#else /* !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotEllipse
     *
     *   Author: $author$
     *     Date: 2/9/2010
     **********************************************************************
     */
    virtual void PlotEllipse
    (tImageInterface& image, 
     tInt cx,tInt cy, tInt a,tInt b, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        EllipseStart();
        MidpointEllipseT<cExtends, tPixel, tInt>
        (*this, image, cx,cy, a,b, q);
        EllipseFinish(image);
#else /* !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CHOLLOWMIDPOINTELLIPSEIMAGE_HXX) || defined(CHOLLOWMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
