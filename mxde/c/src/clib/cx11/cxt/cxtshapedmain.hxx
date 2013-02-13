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
 *   File: cxtshapedmain.hxx
 *
 * Author: $author$           
 *   Date: 5/21/2010
 **********************************************************************
 */
#if !defined(_CXTSHAPEDMAIN_HXX) || defined(CXTSHAPEDMAIN_MEMBERS_ONLY)
#if !defined(_CXTSHAPEDMAIN_HXX) && !defined(CXTSHAPEDMAIN_MEMBERS_ONLY)
#define _CXTSHAPEDMAIN_HXX
#endif /* !defined(_CXTSHAPEDMAIN_HXX) && !defined(CXTSHAPEDMAIN_MEMBERS_ONLY) */

#if !defined(CXTSHAPEDMAIN_MEMBERS_ONLY)
#include "cxtapplicationshellmain.hxx"
#include "cximagesolidbrush.hxx"
#include "cximagebase.hxx"
#include "cxcolor.hxx"
#include "cxcolormap.hxx"
#include "cxgc.hxx"
#include "cxwindow.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtShapedMainExtend
 *
 *  Author: $author$           
 *    Date: 5/21/2010
 **********************************************************************
 */
typedef cXtApplicationShellMain
cXtShapedMainExtend;
/**
 **********************************************************************
 *  Class: cXtShapedMain
 *
 * Author: $author$           
 *   Date: 5/21/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtShapedMain
: /*virtual public cXtShapedMainImplement,
  */public cXtShapedMainExtend
{
public:
    /*typedef cXtShapedMainImplement cImplements;
    */typedef cXtShapedMainExtend cExtends;

    cXColormap m_colormap;
    cXColor m_fgColor;
    cXColor m_bgColor;

    cXGC m_imageGC;
    cXImageBase m_image;
    cXImageSolidBrush m_fgRegionBrush;
    cXImageSolidBrush m_bgRegionBrush;
    cXImageSolidBrush m_fgBrush;
    cXImageSolidBrush m_bgBrush;

    /**
     **********************************************************************
     *  Constructor: cXtShapedMain
     *
     *       Author: $author$           
     *         Date: 5/21/2010
     **********************************************************************
     */
    cXtShapedMain
    (const String xtNameChars = DEFAULT_CXTMAIN_NAME,
     const String xtClassNameChars = DEFAULT_CXTMAIN_CLASS_NAME,
     const tChar* displayNameChars=DEFAULT_CXMAIN_DISPLAY_NAME,
     int displayScreen=DEFAULT_CXMAIN_DISPLAY_SCREEN)
    : cExtends
      (xtNameChars, xtClassNameChars, 
       displayNameChars, displayScreen),

      m_colormap(m_display),
      m_fgColor(m_display, m_colormap),
      m_bgColor(m_display, m_colormap),

      m_imageGC(m_display),
      m_image(m_imageGC),
      m_fgRegionBrush(m_image, 1),
      m_bgRegionBrush(m_image, 0),
      m_fgBrush(m_image),
      m_bgBrush(m_image)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtShapedMain
     *
     *      Author: $author$           
     *        Date: 5/21/2010
     **********************************************************************
     */
    virtual ~cXtShapedMain()
    {
    }
#else /* !defined(CXTSHAPEDMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTSHAPEDMAIN_MEMBERS_ONLY) */

    /**
     **********************************************************************
     *  Function: BeforeCreateShapedApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError BeforeCreateShapedApplicationShell
    (cXImageSolidBrush& fgRegionBrush,
     cXImageSolidBrush& bgRegionBrush,
     cXImageSolidBrush& fgBrush,
     cXImageSolidBrush& bgBrush,
     cXColormap& colormap,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTSHAPEDMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTSHAPEDMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTSHAPEDMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTSHAPEDMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTSHAPEDMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTSHAPEDMAIN_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     *  Function: AfterCreateShapedApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError AfterCreateShapedApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXImageSolidBrush& fgRegionBrush,
     cXImageSolidBrush& bgRegionBrush,
     cXImageSolidBrush& fgBrush,
     cXImageSolidBrush& bgBrush,
     cXColormap& colormap,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
#if defined(CXTSHAPEDMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* defined(CXTSHAPEDMAIN_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTSHAPEDMAIN_MEMBER_FUNCS_IMPLEMENT)
#else /* !defined(CXTSHAPEDMAIN_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTSHAPEDMAIN_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTSHAPEDMAIN_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXTSHAPEDMAIN_MEMBERS_ONLY)
    /**
     **********************************************************************
     *  Function: BeforeCreateApplicationShell
     *
     *    Author: $author$           
     *      Date: 5/24/2010
     **********************************************************************
     */
    virtual eError BeforeCreateApplicationShell
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;

        if (None != (m_colormap.AttachDefault()))
        if (!(error = m_fgColor.AllocateBYTE(255, 128, 0)))
        {
            if (!(error = m_bgColor.AllocateBYTE(255, 255, 0xDD)))
            {
                m_fgBrush.Attach(m_fgColor.Attached());
                m_bgBrush.Attach(m_bgColor.Attached());

                if (!(error = BeforeCreateShapedApplicationShell
                    (m_fgRegionBrush, m_bgRegionBrush, 
                     m_fgBrush, m_bgBrush, m_colormap, 
                     display, rootXWindow, argc, argv, env)))
                    return error;
            }
            m_fgColor.Free();
        }
        return error;
    }
    /**
     **********************************************************************
     *  Function: AfterCreateApplicationShell
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual eError AfterCreateApplicationShell
    (cXtApplicationShellInterface& shellWidget,
     cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env)
    {
        eError error = e_ERROR_NONE;
        error = AfterCreateShapedApplicationShell
        (shellWidget, m_fgRegionBrush, m_bgRegionBrush, 
         m_fgBrush, m_bgBrush, m_colormap, 
         display, rootXWindow, argc, argv, env);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_Expose_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_Expose_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_NoExpose_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_NoExpose_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_MapNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_MapNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: OnHandle_UnmapNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_UnmapNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     *  Function: MainEventHandlerMask
     *
     *    Author: $author$           
     *      Date: 5/21/2010
     **********************************************************************
     */
    virtual EventMask MainEventHandlerMask() const
    {
        EventMask xEventMask 
        = NoEventMask | ExposureMask | StructureNotifyMask;
        return xEventMask;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTSHAPEDMAIN_MEMBERS_ONLY) */
#endif /* !defined(CXTSHAPEDMAIN_MEMBERS_ONLY) */

#endif /* !defined(_CXTSHAPEDMAIN_HXX) || defined(CXTSHAPEDMAIN_MEMBERS_ONLY) */
