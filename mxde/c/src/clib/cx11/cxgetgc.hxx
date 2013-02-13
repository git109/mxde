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
 *   File: cxgetgc.hxx
 *
 * Author: $author$           
 *   Date: 5/30/2010
 **********************************************************************
 */
#if !defined(_CXGETGC_HXX) || defined(CXGETGC_MEMBERS_ONLY)
#if !defined(_CXGETGC_HXX) && !defined(CXGETGC_MEMBERS_ONLY)
#define _CXGETGC_HXX
#endif /* !defined(_CXGETGC_HXX) && !defined(CXGETGC_MEMBERS_ONLY) */

#if !defined(CXGETGC_MEMBERS_ONLY)
#include "cxgetgcinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXGetGCExtend
 *
 *  Author: $author$           
 *    Date: 5/30/2010
 **********************************************************************
 */
typedef cXBase
cXGetGCExtend;
/**
 **********************************************************************
 *  Class: cXGetGC
 *
 * Author: $author$           
 *   Date: 5/30/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXGetGC
: virtual public cXGetGCImplement,
  public cXGetGCExtend
{
public:
    typedef cXGetGCImplement cImplements;
    typedef cXGetGCExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cXGetGC
     *
     *       Author: $author$           
     *         Date: 5/30/2010
     **********************************************************************
     */
    cXGetGC()
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXGetGC
     *
     *      Author: $author$           
     *        Date: 5/30/2010
     **********************************************************************
     */
    virtual ~cXGetGC()
    {
    }
#else /* !defined(CXGETGC_MEMBERS_ONLY) */
#endif /* !defined(CXGETGC_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: GetGC
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual cXGCInterface* GetGC
    (eError& error,
     bool onlyFreed=false)
#if defined(CXGETGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    {
        cXGCInterface* gc = 0;
#if !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT)
        error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        return gc;
    }
#endif /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FreeGC
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual eError FreeGC
    (cXGCInterface& gc,
     bool onlyGotten=false)
#if defined(CXGETGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT)
        eError error = e_ERROR_NOT_ATTACHED;
#else /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetGCAttached
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual GC GetGCAttached
    (eError& error,
     bool onlyFreed=false)
#if defined(CXGETGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    {
        GC xGC = 0;
#if !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        return xGC;
    }
#endif /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FreeGCAttached
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual eError FreeGCAttached
    (GC xGC, 
     bool onlyGotten=false)
#if defined(CXGETGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
#if !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: GetGCDetached
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual GC GetGCDetached
    (eError& error,
     Display& xDisplay, 
     Drawable xDrawable, 
     unsigned long xGCValueMask=0, 
     XGCValues* xGCValues=0) const
#if defined(CXGETGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    {
        GC xGC = 0;
        error = e_ERROR_FAILED;
#if !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT)
        if ((xGC = XCreateGC
            (&xDisplay, xDrawable, xGCValueMask, xGCValues)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XCreateGC(%p,0x%x)\n", &xDisplay, (int)xDrawable));
#else /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        return xGC;
    }
#endif /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: FreeGCDetached
     *
     *    Author: $author$           
     *      Date: 5/30/2010
     **********************************************************************
     */
    virtual eError FreeGCDetached
    (Display& xDisplay, 
     GC xGC) const
#if defined(CXGETGC_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
#if !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT)
        int err;

        if ((xGC))
        if (!(err = XFreeGC(&xDisplay, xGC)))
            error = e_ERROR_NONE;
        else
        DBE(("() failed on XFreeGC(%p,%p)\n", &xDisplay, xGC));
#else /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXGETGC_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXGETGC_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXGETGC_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXGETGC_MEMBERS_ONLY) */
#endif /* !defined(CXGETGC_MEMBERS_ONLY) */

#endif /* !defined(_CXGETGC_HXX) || defined(CXGETGC_MEMBERS_ONLY) */
