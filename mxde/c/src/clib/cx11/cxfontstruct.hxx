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
 *   File: cxfontstruct.hxx
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
#if !defined(_CXFONTSTRUCT_HXX) || defined(CXFONTSTRUCT_MEMBERS_ONLY)
#if !defined(_CXFONTSTRUCT_HXX) && !defined(CXFONTSTRUCT_MEMBERS_ONLY)
#define _CXFONTSTRUCT_HXX
#endif /* !defined(_CXFONTSTRUCT_HXX) && !defined(CXFONTSTRUCT_MEMBERS_ONLY) */

#if !defined(CXFONTSTRUCT_MEMBERS_ONLY)
#include "cxfontstructinterface.hxx"
#include "cxfontstructattached.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXFontStructExtend
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cXFontStructAllocated
cXFontStructExtend;
/**
 **********************************************************************
 *  Class: cXFontStruct
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXFontStruct
: virtual public cXFontStructImplement,
  public cXFontStructExtend
{
public:
    typedef cXFontStructImplement cImplements;
    typedef cXFontStructExtend cExtends;

    cXDisplayInterface& m_display;

    /**
     **********************************************************************
     *  Constructor: cXFontStruct
     *
     *       Author: $author$           
     *         Date: 6/13/2010
     **********************************************************************
     */
    cXFontStruct
    (cXDisplayInterface& display,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isAllocated=false) 
    : cExtends(attached, isAllocated),
      m_display(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXFontStruct
     *
     *      Author: $author$           
     *        Date: 6/13/2010
     **********************************************************************
     */
    virtual ~cXFontStruct()
    {
        eError error;
        DBE_THROW_ERROR(error, Freed());
    }
#else /* !defined(CXFONTSTRUCT_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: LoadQuery
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual eError LoadQuery
    (const char* name,
     bool onlyFreed = false)
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        LoadQueryAttached(error, name, onlyFreed);
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: LoadQueryAttached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual XFontStruct* LoadQueryAttached
    (eError& error, const char* name,
     bool onlyFreed = false)
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* detached = 0;

#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        if (!(error = Freed(onlyFreed)))
        if ((detached = LoadQueryDetached(error, name)))
        {
            if (detached == (AttachAllocated(detached)))
                return detached;
            FreeDetached(*detached);
        }
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return 0;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Query
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual eError Query
    (GC xGC,
     bool onlyFreed = false)
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        DBF(("(xGC=%p)\n", xGC));
        QueryAttached(error, xGC, onlyFreed);
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: Query
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual eError Query
    (XID xID,
     bool onlyFreed = false)
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_FAILED;
        DBF(("(xID=0x%x)\n", xID));
        QueryAttached(error, xID, onlyFreed);
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryAttached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual XFontStruct* QueryAttached
    (eError& error, GC xGC,
     bool onlyFreed = false)
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* detached = 0;

#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(error=%d, xGC=%p)\n", error, xGC));
        if (!(error = Freed(onlyFreed)))
        if ((detached = QueryDetached(error, xGC)))
        {
            if (detached == (AttachAllocated(detached)))
                return detached;
            FreeDetached(*detached);
        }
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return 0;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryAttached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual XFontStruct* QueryAttached
    (eError& error, XID xID,
     bool onlyFreed = false)
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* detached = 0;

#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        DBF(("(error=%d, xID=0x%x)...\n", error, xID));

        if (!(error = Freed(onlyFreed)))
        if ((detached = QueryDetached(error, xID)))
        {
            if (detached == (AttachAllocated(detached)))
                return detached;
            FreeDetached(*detached);
        }
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return 0;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: TextExtents
     *
     *    Author: $author$           
     *      Date: 7/15/2010
     **********************************************************************
     */
    virtual eError TextExtents
    (int& direction, int& ascent, 
     int& descent, XCharStruct& overall,
     const char* chars, int length = UNDEFINED_LENGTH) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        XFontStruct* attached;
        int status;

        if ((0 > length) && (chars))
            length = cCHARS::Count(chars);
                            
        if ((chars))
        if ((attached = Attached()))
        if ((status = XTextExtents
             (attached, chars, length, 
              &direction, &ascent, &descent, &overall)))
              error = e_ERROR_NONE;
        else
        DBE(("()\n failed status = %d on XTextExtents"
             "(attached = %p, chars = \"%s\", length = %d,...)\n",
             status, attached, chars, length));
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: MaxRectangle
     *
     *    Author: $author$           
     *      Date: 6/17/2010
     **********************************************************************
     */
    virtual eError MaxRectangle
    (XRectangle& rect) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        XFontStruct* attached;

        if ((attached = Attached()))
        {
            rect.x = attached->max_bounds.lbearing;
            rect.y = attached->max_bounds.ascent;
            rect.width = attached->max_bounds.width;
            rect.height = attached->max_bounds.ascent+attached->max_bounds.descent;
            error = e_ERROR_NONE;
        }
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: MinRectangle
     *
     *    Author: $author$           
     *      Date: 6/17/2010
     **********************************************************************
     */
    virtual eError MinRectangle
    (XRectangle& rect) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
        XFontStruct* attached;

        if ((attached = Attached()))
        {
            rect.x = attached->min_bounds.lbearing;
            rect.y = attached->min_bounds.ascent;
            rect.width = attached->min_bounds.width;
            rect.height = attached->min_bounds.ascent+attached->max_bounds.descent;
            error = e_ERROR_NONE;
        }
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: LoadQueryDetached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual XFontStruct* LoadQueryDetached
    (eError& error, const char* name) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* detached = 0;
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;

        error = e_ERROR_FAILED;

        if ((name))
        DBF(("(error=%d, name=\"%s\")...\n", error, name));

        if ((name))
        if ((xDisplay = DisplayAttached()))
        if ((detached = XLoadQueryFont(xDisplay, name)))
            error = e_ERROR_NONE;
        else
        DBE
        (("()\n failed on XLoadQueryFont"
          "(xDisplay=%p, name=\"%s\")\n", xDisplay, name));
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryDetached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual XFontStruct* QueryDetached
    (eError& error, GC xGC) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* detached = 0;
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        XID xID;

        error = e_ERROR_FAILED;

        DBF(("(error=%d, xGC=%p)...\n", error, xGC));

        if ((xGC))
        if (None != (xID = XGContextFromGC(xGC)))
            detached = QueryDetached(error, xID);
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: QueryDetached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual XFontStruct* QueryDetached
    (eError& error, XID xID) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        XFontStruct* detached = 0;
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;

        error = e_ERROR_FAILED;

        DBF(("(error=%d, xID=0x%x)...\n", error, xID));

        if (None != (xID))
        if ((xDisplay = DisplayAttached()))
        if ((detached = XQueryFont(xDisplay, xID)))
            error = e_ERROR_NONE;
        else
        DBE
        (("()\n failed on XQueryFont"
          "(xDisplay=%p, xID=0x%x)\n", xDisplay, xID));
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FreeDetached
     *
     *    Author: $author$           
     *      Date: 6/13/2010
     **********************************************************************
     */
    virtual eError FreeDetached
    (XFontStruct& detached) const
#if defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT)
        Display* xDisplay;
        int status;

        DBF(("(detached=%p)...\n", &detached));

        if ((xDisplay = DisplayAttached()))
        if (!(status = XFreeFont(xDisplay, &detached)))
            error = e_ERROR_NONE;
        else
        DBE
        (("()\n failed status = %n on XFreeFont"
          "(xDisplay=%p, &detached=%p)\n", status, xDisplay, &detached));
#else /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXFONTSTRUCT_MEMBERS_ONLY)
#include "cxobjectimplement_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXFONTSTRUCT_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCT_MEMBERS_ONLY) */

#endif /* !defined(_CXFONTSTRUCT_HXX) || defined(CXFONTSTRUCT_MEMBERS_ONLY) */
