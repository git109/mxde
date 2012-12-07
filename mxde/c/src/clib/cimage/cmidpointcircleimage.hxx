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
 *   File: cmidpointcircleimage.hxx
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
#if !defined(_CMIDPOINTCIRCLEIMAGE_HXX) || defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY)
#if !defined(_CMIDPOINTCIRCLEIMAGE_HXX) && !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY)
#define _CMIDPOINTCIRCLEIMAGE_HXX
#endif /* !defined(_CMIDPOINTCIRCLEIMAGE_HXX) && !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */

#if !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY)
#include "cmidpointcircle.hxx"
#include "cbaseimage.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cMidpointCircleImage;
/**
 **********************************************************************
 * Typedef: cMidpointCircleImageExtends
 *
 *  Author: $author$
 *    Date: 7/20/2009
 **********************************************************************
 */
typedef cMidpointCircleT
<cMidpointCircleImage, cBaseImage, cImageInterface>
cMidpointCircleImageExtends;
/**
 **********************************************************************
 *  Class: cMidpointCircleImage
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cMidpointCircleImage
: public cMidpointCircleImageExtends
{
public:
    typedef cMidpointCircleImageExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cMidpointCircleImage
     *
     *       Author: $author$
     *         Date: 7/20/2009
     **********************************************************************
     */
    cMidpointCircleImage
    (cImageInterface& image)
    : cExtends(image)
    {
    }
#else /* !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotCircle
     *
     *   Author: $author$
     *     Date: 7/20/2009
     **********************************************************************
     */
    virtual void PlotCircle
    (tImageBaseInterface& image, tInt cx,tInt cy, tInt r,
     eCircleOctant o=e_CIRCLE_OCTANT_ALL) 
#if defined(CMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        MidpointCircleT<cExtends, tPixel, tInt>
        (*this, image, cx,cy, r, o);
#else /* !defined(CMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY)
};

#if !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY)
class c_EXPORT_CLASS cFilledMidpointCircleImage;
/**
 **********************************************************************
 * Typedef: cFilledMidpointCircleImageExtends
 *
 *  Author: $author$
 *    Date: 7/20/2009
 **********************************************************************
 */
typedef cFilledMidpointCircleT
<cFilledMidpointCircleImage, cBaseImage, cImageInterface>
cFilledMidpointCircleImageExtends;
/**
 **********************************************************************
 *  Class: cFilledMidpointCircleImage
 *
 * Author: $author$
 *   Date: 7/20/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledMidpointCircleImage
: public cFilledMidpointCircleImageExtends
{
public:
    typedef cFilledMidpointCircleImageExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cFilledMidpointCircleImage
     *
     *       Author: $author$
     *         Date: 7/20/2009
     **********************************************************************
     */
    cFilledMidpointCircleImage
    (cImageInterface& image)
    : cExtends(image)
    {
    }
#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: PlotCircle
     *
     *   Author: $author$
     *     Date: 7/20/2009
     **********************************************************************
     */
    virtual void PlotCircle
    (tImageBaseInterface& image, tInt cx,tInt cy, tInt r,
     eCircleQuadrant q=e_CIRCLE_QUADRANT_ALL) 
#if defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CFILLEDMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_IMPLEMENT) 
        MidpointCircleT<cExtends, tPixel, tInt>
        (*this, image, cx,cy, r, q);
#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY)
};
#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */
#endif /* !defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */

#endif /* !defined(_CMIDPOINTCIRCLEIMAGE_HXX) || defined(CMIDPOINTCIRCLEIMAGE_MEMBERS_ONLY) */
