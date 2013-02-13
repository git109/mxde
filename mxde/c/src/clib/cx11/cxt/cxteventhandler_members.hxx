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
 *   File: cxteventhandler_members.hxx
 *
 * Author: $author$           
 *   Date: 5/21/2010
 **********************************************************************
 */

/**
 **********************************************************************
 *  Class: cXtEventHandler
 *
 * Author: $author$           
 *   Date: 5/21/2010
 **********************************************************************
 *
class c_INSTANCE_CLASS cXtEventHandler
: virtual public cXtEventHandlerImplement,
  public cXtEventHandlerExtend
{
public:
    typedef cXtEventHandlerImplement cImplements;
    typedef cXtEventHandlerExtend cExtends;
*/

    /**
     **********************************************************************
     * Function: OnHandle_KeyPress_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_KeyPress_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_KeyRelease_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_KeyRelease_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ButtonPress_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ButtonPress_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ButtonRelease_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ButtonRelease_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_MotionNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_MotionNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_EnterNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_EnterNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_LeaveNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_LeaveNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_FocusIn_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_FocusIn_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_FocusOut_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_FocusOut_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_KeymapNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_KeymapNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_GraphicsExpose_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_GraphicsExpose_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_VisibilityNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_VisibilityNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_CreateNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_CreateNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_DestroyNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_DestroyNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
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
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_MapRequest_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_MapRequest_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ReparentNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ReparentNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ConfigureNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ConfigureNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ConfigureRequest_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ConfigureRequest_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_GravityNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_GravityNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ResizeRequest_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ResizeRequest_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_CirculateNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_CirculateNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_CirculateRequest_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_CirculateRequest_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_PropertyNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_PropertyNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_SelectionClear_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_SelectionClear_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_SelectionRequest_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_SelectionRequest_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_SelectionNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_SelectionNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ColormapNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ColormapNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_ClientMessage_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_ClientMessage_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnHandle_MappingNotify_XtEvent
     *
     *   Author: $author$           
     *     Date: 5/21/2010
     **********************************************************************
     */
    virtual eError OnHandle_MappingNotify_XtEvent
    (Widget xWidget, XtPointer xPointer,
     XEvent& xEvent, Boolean& continueToDispatch) 
#if defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE) */

/*
};
*/
