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
 *   File: cxfont.hxx
 *
 * Author: $author$           
 *   Date: 6/15/2010
 **********************************************************************
 */
#if !defined(_CXFONT_HXX) || defined(CXFONT_MEMBERS_ONLY)
#if !defined(_CXFONT_HXX) && !defined(CXFONT_MEMBERS_ONLY)
#define _CXFONT_HXX
#endif /* !defined(_CXFONT_HXX) && !defined(CXFONT_MEMBERS_ONLY) */

#if !defined(CXFONT_MEMBERS_ONLY)
#include "cxfontinterface.hxx"
#include "cxfontattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXFontExtend
 *
 *  Author: $author$           
 *    Date: 6/15/2010
 **********************************************************************
 */
typedef cXFontLoaded
cXFontExtend;
/**
 **********************************************************************
 *  Class: cXFont
 *
 * Author: $author$           
 *   Date: 6/15/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXFont
: virtual public cXFontImplement,
  public cXFontExtend
{
public:
    typedef cXFontImplement cImplements;
    typedef cXFontExtend cExtends;

    cXDisplayInterface& m_display;

    /**
     **********************************************************************
     *  Constructor: cXFont
     *
     *       Author: $author$           
     *         Date: 6/15/2010
     **********************************************************************
     */
    cXFont
    (cXDisplayInterface& display,
     tAttachedTo attached=(tAttachedTo)(vUnattached),
     bool isLoaded=false) 
    : cExtends(attached, isLoaded),
      m_display(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXFont
     *
     *      Author: $author$           
     *        Date: 6/15/2010
     **********************************************************************
     */
    virtual ~cXFont()
    {
        eError error;
        DBE_THROW_ERROR(error, UnLoaded());
    }
#else /* !defined(CXFONT_MEMBERS_ONLY) */
#endif /* !defined(CXFONT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: Load
     *
     *    Author: $author$           
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual eError Load
    (const char* name,
     bool onlyUnLoaded = false)
#if defined(CXFONT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        LoadAttached(error, name, onlyUnLoaded);
#if !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: LoadAttached
     *
     *    Author: $author$           
     *      Date: 6/17/2010
     **********************************************************************
     */
    virtual Font LoadAttached
    (const char* name,
     bool onlyUnLoaded = false)
#if defined(CXFONT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        Font detached = LoadAttached(error, name, onlyUnLoaded);
#if !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: LoadAttached
     *
     *    Author: $author$           
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual Font LoadAttached
    (eError& error, const char* name,
     bool onlyUnLoaded = false)
#if defined(CXFONT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    {
        Font detached = None;

        if (!(error = UnLoaded(onlyUnLoaded)))
        if (None != (detached = LoadDetached(error, name)))
        if (detached != (AttachLoaded(detached)))
            UnLoadDetached(detached);

#if !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: UnLoad
     *
     *    Author: $author$           
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual eError UnLoad
    (bool onlyLoaded = false)
#if defined(CXFONT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        Font detached;

        if (None != (detached = Detach()))
            error = UnLoadDetached(detached);
        else
        if ((onlyLoaded))
            error = e_ERROR_FAILED;

#if !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     *  Function: LoadDetached
     *
     *    Author: $author$           
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual Font LoadDetached
    (eError& error, const char* name) const
#if defined(CXFONT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    {
        Font detached = None;
        Display* xDisplay;

        DBF(("(error=%d, name=\"%s\")...\n", error, name));

        error = e_ERROR_FAILED;

        if ((name))
        if ((xDisplay = DisplayAttached()))
        if (None != (detached = XLoadFont(xDisplay, name)))
        {
            DBF(("()\n detached=0x%x\n", detached));
            error = e_ERROR_NONE;
        }
        else
        DBE
        (("()\n failed on XLoadFont"
          "(xDisplay=%p, name=\"%s\")\n", xDisplay, name));

#if !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: UnLoadDetached
     *
     *    Author: $author$           
     *      Date: 6/15/2010
     **********************************************************************
     */
    virtual eError UnLoadDetached
    (Font detached) const
#if defined(CXFONT_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_FAILED;
        Display* xDisplay;
        int status;

        if (None != (detached))
        if ((xDisplay = DisplayAttached()))
        if (!(status = XUnloadFont(xDisplay, detached)))
            error = e_ERROR_NONE;
        else
        DBE
        (("()\n failed status = %d on XUnloadFont"
          "(xDisplay=%p, detached=0x%x)\n", 
          status, xDisplay, detached));

#if !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXFONT_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXFONT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXFONT_MEMBERS_ONLY)
#include "cxobjectimplement_members.hxx"
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXFONT_MEMBERS_ONLY) */
#endif /* !defined(CXFONT_MEMBERS_ONLY) */

#endif /* !defined(_CXFONT_HXX) || defined(CXFONT_MEMBERS_ONLY) */
