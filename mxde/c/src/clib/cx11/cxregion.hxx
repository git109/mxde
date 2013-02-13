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
 *   File: cxregion.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXREGION_HXX) || defined(CXREGION_MEMBERS_ONLY)
#if !defined(_CXREGION_HXX) && !defined(CXREGION_MEMBERS_ONLY)
#define _CXREGION_HXX
#endif /* !defined(_CXREGION_HXX) && !defined(CXREGION_MEMBERS_ONLY) */

#if !defined(CXREGION_MEMBERS_ONLY)
#include "cxregioninterface.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXRegion
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class cXRegion
: virtual public cXRegionImplement,
  public cXRegionCreated
{
public:
    typedef cXRegionImplement cImplements;
    typedef cXRegionCreated cExtends;

    cXDisplayInterface& m_display;

    /**
     **********************************************************************
     *  Constructor: cXRegion
     *
     *       Author: $author$           
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXRegion
    (cXDisplayInterface& display,
     Region attached=0,
     bool isCreated=false)
    : cExtends(attached,isCreated), 
      m_display(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXRegion
     *
     *      Author: $author$           
     *        Date: 7/5/2009
     **********************************************************************
     */
    virtual ~cXRegion()
    {
    }
#else /* !defined(CXREGION_MEMBERS_ONLY) */
#endif /* !defined(CXREGION_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Create
    (bool onlyDestroyed=false) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        eError error2;
        Region detached;
        int isTrue;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if ((detached = CreateDetached(error2)))
        {
            if (detached == (Attach(detached)))
            if (0 < (isTrue = SetIsCreated()))
                return e_ERROR_NONE;
            else
            Detach();

            DestroyDetached(detached);
        }
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        eError error2;
        Region detached;
        int isTrue;

        if ((error2 = Created(onlyCreated,false)))
            return error2;

        if (0 > (isTrue = SetIsCreated(false)))
            return error = -isTrue;

        if ((detached = Detach()))
            error = DestroyDetached(detached);

#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Intersect
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Intersect
    (const cXRegionInterface& region) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        Region xRegion;
        if ((xRegion = region.Attached()))
            error = Intersect(xRegion);
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Union
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Union
    (const cXRegionInterface& region) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        Region xRegion;
        if ((xRegion = region.Attached()))
            error = Union(xRegion);
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Intersect
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Intersect
    (Region xRegion) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        Region attached;
        Bool isTrue;

        if (xRegion && (attached = Attached()))
        if ((isTrue = XIntersectRegion(xRegion, attached, attached)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XIntersectRegion(%p,%p,%p)\n", xRegion, attached, attached));
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Union
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Union
    (Region xRegion) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        Region attached;
        Bool isTrue;

        if (xRegion && (attached = Attached()))
        if ((isTrue = XUnionRegion(xRegion, attached, attached)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XUnionRegion(%p,%p,%p)\n", xRegion, attached, attached));
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Intersect
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Intersect
    (XRectangle& xRectangle) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        eError error2;
        Region detached;
        Region attached;
        Bool isTrue;

        if ((attached = Attached()))
        if ((detached = CreateDetached(error2)))
        {
            if ((isTrue = XUnionRectWithRegion
                (&xRectangle, detached, detached)))
                error = Intersect(detached);
            else
            DBE(("() failed on XUnionRectWithRegion(...,%p,%p)\n", detached, detached));

            DestroyDetached(detached);
        }
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Union
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Union
    (XRectangle& xRectangle) 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        Region attached;
        Bool isTrue;

        if ((attached = Attached()))
        if ((isTrue = XUnionRectWithRegion
            (&xRectangle, attached, attached)))
            return e_ERROR_NONE;
        else
        DBE(("() failed on XUnionRectWithRegion(...,%p,%p)\n", attached, attached));
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual Region CreateDetached
    (eError& error) const 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
        Region detached = 0;
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        error = e_ERROR_FAILED;

        if ((detached = XCreateRegion()))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XCreateRegion()\n"));
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (Region detached) const 
#if defined(CXREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXREGION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        Bool isTrue;
        if (detached)
        if ((isTrue = XDestroyRegion(detached)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XDestroyRegion(%p)\n", detached));
#else /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXREGION_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXREGION_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXREGION_MEMBERS_ONLY) */
#endif /* !defined(CXREGION_MEMBERS_ONLY) */

#endif /* !defined(_CXREGION_HXX) || defined(CXREGION_MEMBERS_ONLY) */
