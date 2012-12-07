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
 *   File: cmidpointellipseimage.hxx
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
#if !defined(_CMIDPOINTELLIPSEIMAGE_HXX) || defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
#if !defined(_CMIDPOINTELLIPSEIMAGE_HXX) && !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
#define _CMIDPOINTELLIPSEIMAGE_HXX
#endif /* !defined(_CMIDPOINTELLIPSEIMAGE_HXX) && !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

#if !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
#include "cmidpointellipse.hxx"
#include "cbaseimage.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cMidpointEllipseImage;
/**
 **********************************************************************
 * Typedef: cMidpointEllipseImageExtends
 *
 *  Author: $author$
 *    Date: 7/18/2009
 **********************************************************************
 */
typedef cMidpointEllipseT
<cMidpointEllipseImage, cBaseImage, cImageInterface>
cMidpointEllipseImageExtends;
/**
 **********************************************************************
 *  Class: cMidpointEllipseImage
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cMidpointEllipseImage
: public cMidpointEllipseImageExtends
{
public:
    typedef cMidpointEllipseImageExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cMidpointEllipseImage
     *
     *       Author: $author$
     *         Date: 7/18/2009
     **********************************************************************
     */
    cMidpointEllipseImage
    (cImageInterface& image) 
    : cExtends(image)
    {
    }
#else /* !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotEllipse
     *
     *   Author: $author$
     *     Date: 7/18/2009
     **********************************************************************
     */
    virtual void PlotEllipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        MidpointEllipseT<cExtends, tPixel, tInt>
        (*this, image, cx,cy, a,b, q);
#else /* !defined(CMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
};

#if !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
class c_EXPORT_CLASS cFilledMidpointEllipseImage;
/**
 **********************************************************************
 * Typedef: cFilledMidpointEllipseImageExtends
 *
 *  Author: $author$
 *    Date: 7/18/2009
 **********************************************************************
 */
typedef cFilledMidpointEllipseT
<cFilledMidpointEllipseImage, cBaseImage, cImageInterface>
cFilledMidpointEllipseImageExtends;
/**
 **********************************************************************
 *  Class: cFilledMidpointEllipseImage
 *
 * Author: $author$
 *   Date: 7/18/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledMidpointEllipseImage
: public cFilledMidpointEllipseImageExtends
{
public:
    typedef cFilledMidpointEllipseImageExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cFilledMidpointEllipseImage
     *
     *       Author: $author$
     *         Date: 7/18/2009
     **********************************************************************
     */
    cFilledMidpointEllipseImage
    (cImageInterface& image)
    : cExtends(image)
    {
    }
#else /* !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotEllipse
     *
     *   Author: $author$
     *     Date: 7/18/2009
     **********************************************************************
     */
    virtual void PlotEllipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b, 
     eEllipseQuadrant q=e_ELLIPSE_QUADRANT_ALL) 
#if defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CFILLEDMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        MidpointEllipseT<cExtends, tPixel, tInt>
        (*this, image, cx,cy, a,b, q);
#else /* !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY)
};
#else /* !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CMIDPOINTELLIPSEIMAGE_HXX) || defined(CMIDPOINTELLIPSEIMAGE_MEMBERS_ONLY) */
