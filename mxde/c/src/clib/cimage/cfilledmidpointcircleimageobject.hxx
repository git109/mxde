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
 *   File: cfilledmidpointcircleimageobject.hxx
 *
 * Author: $author$
 *   Date: 8/10/2009
 **********************************************************************
 */
#if !defined(_CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_HXX) || defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
#if !defined(_CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_HXX) && !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
#define _CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_HXX
#endif /* !defined(_CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_HXX) && !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
#include "cimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFilledMidpointCircleImageObject
 *
 * Author: $author$
 *   Date: 8/10/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cFilledMidpointCircleImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    
    tSize m_radius;
    eQuadrant m_quadrant;
    
    /**
     **********************************************************************
     *  Constructor: cFilledMidpointCircleImageObject
     *
     *       Author: $author$
     *         Date: 8/10/2009
     **********************************************************************
     */
    cFilledMidpointCircleImageObject
    (cImageInterface& image,
     tSize radius=1,
     eQuadrant quadrant=e_QUADRANT_ALL)
    : cExtends(image, radius*2-1,radius*2-1),
      m_radius(radius),
      m_quadrant(quadrant)
    {
    }
#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */

#if !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 8/10/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x,tOffset y) 
#if defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT)
        if (&m_image != this)
            error = m_image.FillCircle(x,y, m_radius, m_quadrant); 
#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 8/10/2009
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,tOffset y,
     tSize w,tSize h) 
#if defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBER_FUNCS_INTERFACE) */
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */
#endif /* !defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */

#endif /* !defined(_CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_HXX) || defined(CFILLEDMIDPOINTCIRCLEIMAGEOBJECT_MEMBERS_ONLY) */
