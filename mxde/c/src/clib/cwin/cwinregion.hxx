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
 *   File: cwinregion.hxx
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
#if !defined(_CWINREGION_HXX) || defined(CWINREGION_MEMBERS_ONLY)
#if !defined(_CWINREGION_HXX) && !defined(CWINREGION_MEMBERS_ONLY)
#define _CWINREGION_HXX
#endif /* !defined(_CWINREGION_HXX) && !defined(CWINREGION_MEMBERS_ONLY) */

#if !defined(CWINREGION_MEMBERS_ONLY)
#include "cwinregioninterface.hxx"
#include "cwinhrgn.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRegion
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
class c_INSTANCE_CLASS cWinRegion
: virtual public cWinRegionImplement,
  public cWinHRGN
{
public:
    typedef cWinRegionImplement cImplements;
    typedef cWinHRGN cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRegion
     *
     *       Author: $author$
     *         Date: 11/23/2009
     **********************************************************************
     */
    cWinRegion
    (HRGN attached=NULL,
     bool isCreated=false) 
    : cExtends(attached, isCreated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRegion
     *
     *      Author: $author$
     *        Date: 11/23/2009
     **********************************************************************
     */
    virtual ~cWinRegion()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CWINREGION_MEMBERS_ONLY) */
#endif /* !defined(CWINREGION_MEMBERS_ONLY) */


    /**
     **********************************************************************
     * Function: CreatePolyPolygon
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual eError CreatePolyPolygon
    (const POINT* points,
     const INT* counts,
     int nCounts,
     int polyFillMode=WINDING) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        HRGN hRgn, attached;
        if ((hRgn = CreatePolyPolygonRgn
            (points, counts, nCounts, polyFillMode)))
        {
            if ((attached = Attach(hRgn)))
            if ((SetIsCreated()))
                return e_ERROR_NONE;

            DestroyDetached(hRgn);
        }
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CreatePolygon
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual eError CreatePolygon
    (const POINT* points, int cPoints,
     int polyFillMode=WINDING)
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        HRGN hRgn, attached;
        if ((hRgn = CreatePolygonRgn
            (points, cPoints, polyFillMode)))
        {
            if ((attached = Attach(hRgn)))
            if ((SetIsCreated()))
                return e_ERROR_NONE;

            DestroyDetached(hRgn);
        }
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: CreateElliptic
     *
     *    Author: $author$
     *      Date: 11/23/2009
     **********************************************************************
     */
    virtual eError CreateElliptic
    (int left, int top, int right, int bottom)
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT)
        HRGN hRgn, attached;
        if ((hRgn = CreateEllipticRgn
            (left,top, right,bottom)))
        {
            if ((attached = Attach(hRgn)))
            if ((SetIsCreated()))
                return e_ERROR_NONE;

            DestroyDetached(hRgn);
        }
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CreateRoundRect
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual eError CreateRoundRect
    (int left, int top, int right, int bottom, int width, int height) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        HRGN hRgn, attached;
        if ((hRgn = CreateRoundRectRgn
            (left,top, right,bottom, width,height)))
        {
            if ((attached = Attach(hRgn)))
            if ((SetIsCreated()))
                return e_ERROR_NONE;

            DestroyDetached(hRgn);
        }
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CreateRoundRectAttached
     *
     *   Author: $author$
     *     Date: 12/30/2009
     **********************************************************************
     */
    virtual HRGN CreateRoundRectAttached
    (eError& error, int left, int top, int right, 
     int bottom, int width, int height) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    {
        HRGN hRgn = NULL;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        if (!(error = CreateRoundRect
            (left,top, right,bottom, width,height)))
            hRgn = Attached();
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return hRgn;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: CreateRect
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual eError CreateRect
    (int left, int top, int right, int bottom) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        HRGN hRgn, attached;
        if ((hRgn = CreateRectRgn
            (left,top, right,bottom)))
        {
            if ((attached = Attach(hRgn)))
            if ((SetIsCreated()))
                return e_ERROR_NONE;

            DestroyDetached(hRgn);
        }
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (HRGN detached) const 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT)
        if (detached)
        if (DeleteRgn(detached))
            return e_ERROR_NONE;
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Copy
     *
     *   Author: $author$
     *     Date: 2/17/2010
     **********************************************************************
     */
    virtual eError Copy
    (HRGN hRgn) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        HRGN attached;
        int result;
        if (hRgn)
        if ((attached = Attached()))
        if (ERROR != (result = CombineRgn
            (attached, hRgn, attached, RGN_COPY)))
            return e_ERROR_NONE;
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: Combine
     *
     *    Author: $author$
     *      Date: 11/28/2009
     **********************************************************************
     */
    virtual eError Combine
    (const cWinRegionInterface& region,
     int combineMode=RGN_OR)
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        HRGN hRgn;
        if ((hRgn = region.Attached()))
            error = Combine(hRgn, combineMode);
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Combine
     *
     *   Author: $author$
     *     Date: 5/20/2009
     **********************************************************************
     */
    virtual eError Combine
    (HRGN hRgn,
     int combineMode=RGN_OR) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        HRGN attached;
        int result;
        if (hRgn)
        if ((attached = Attached()))
        if (ERROR != (result = CombineRgn
            (attached, attached, hRgn, combineMode)))
            return e_ERROR_NONE;
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetRect
     *
     *   Author: $author$
     *     Date: 11/28/2009
     **********************************************************************
     */
    virtual eError SetRect
    (int left, int top, int right, int bottom) 
#if defined(CWINREGION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINREGION_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) 
        HRGN hRgn;
        if ((hRgn = Attached()))
        if ((SetRectRgn(hRgn, left,top, right,bottom)))
            error = e_ERROR_NONE;
#else /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINREGION_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINREGION_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINREGION_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGION_MEMBERS_ONLY) */
#endif /* !defined(CWINREGION_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGION_HXX) || defined(CWINREGION_MEMBERS_ONLY) */
