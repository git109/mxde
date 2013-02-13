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
 *   File: cxteventhandler_cases.hxx
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
     *  Function: OnHandleXtEvent
     *
     *    Author: $author$           
     *      Date: 5/21/2010
     **********************************************************************
     *
    virtual eError OnHandleXtEvent
    (Widget xWidget, XtPointer xPointer, 
     XEvent& xEvent, Boolean& continueToDispatch)
    {
        eError error = e_ERROR_NONE;
        continueToDispatch = True;
        switch (xEvent.type)
        {
    */

        case KeyPress:
            DBT(("() KeyPress\n"));
            error = OnHandle_KeyPress_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case KeyRelease:
            DBT(("() KeyRelease\n"));
            error = OnHandle_KeyRelease_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ButtonPress:
            DBT(("() ButtonPress\n"));
            error = OnHandle_ButtonPress_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ButtonRelease:
            DBT(("() ButtonRelease\n"));
            error = OnHandle_ButtonRelease_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case MotionNotify:
            DBT(("() MotionNotify\n"));
            error = OnHandle_MotionNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case EnterNotify:
            DBT(("() EnterNotify\n"));
            error = OnHandle_EnterNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case LeaveNotify:
            DBT(("() LeaveNotify\n"));
            error = OnHandle_LeaveNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case FocusIn:
            DBT(("() FocusIn\n"));
            error = OnHandle_FocusIn_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case FocusOut:
            DBT(("() FocusOut\n"));
            error = OnHandle_FocusOut_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case KeymapNotify:
            DBT(("() KeymapNotify\n"));
            error = OnHandle_KeymapNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case Expose:
            DBT(("() Expose\n"));
            error = OnHandle_Expose_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case GraphicsExpose:
            DBT(("() GraphicsExpose\n"));
            error = OnHandle_GraphicsExpose_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case NoExpose:
            DBT(("() NoExpose\n"));
            error = OnHandle_NoExpose_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case VisibilityNotify:
            DBT(("() VisibilityNotify\n"));
            error = OnHandle_VisibilityNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case CreateNotify:
            DBT(("() CreateNotify\n"));
            error = OnHandle_CreateNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case DestroyNotify:
            DBT(("() DestroyNotify\n"));
            error = OnHandle_DestroyNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case UnmapNotify:
            DBT(("() UnmapNotify\n"));
            error = OnHandle_UnmapNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case MapNotify:
            DBT(("() MapNotify\n"));
            error = OnHandle_MapNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case MapRequest:
            DBT(("() MapRequest\n"));
            error = OnHandle_MapRequest_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ReparentNotify:
            DBT(("() ReparentNotify\n"));
            error = OnHandle_ReparentNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ConfigureNotify:
            DBT(("() ConfigureNotify\n"));
            error = OnHandle_ConfigureNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ConfigureRequest:
            DBT(("() ConfigureRequest\n"));
            error = OnHandle_ConfigureRequest_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case GravityNotify:
            DBT(("() GravityNotify\n"));
            error = OnHandle_GravityNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ResizeRequest:
            DBT(("() ResizeRequest\n"));
            error = OnHandle_ResizeRequest_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case CirculateNotify:
            DBT(("() CirculateNotify\n"));
            error = OnHandle_CirculateNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case CirculateRequest:
            DBT(("() CirculateRequest\n"));
            error = OnHandle_CirculateRequest_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case PropertyNotify:
            DBT(("() PropertyNotify\n"));
            error = OnHandle_PropertyNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case SelectionClear:
            DBT(("() SelectionClear\n"));
            error = OnHandle_SelectionClear_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case SelectionRequest:
            DBT(("() SelectionRequest\n"));
            error = OnHandle_SelectionRequest_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case SelectionNotify:
            DBT(("() SelectionNotify\n"));
            error = OnHandle_SelectionNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ColormapNotify:
            DBT(("() ColormapNotify\n"));
            error = OnHandle_ColormapNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case ClientMessage:
            DBT(("() ClientMessage\n"));
            error = OnHandle_ClientMessage_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

        case MappingNotify:
            DBT(("() MappingNotify\n"));
            error = OnHandle_MappingNotify_XtEvent
            (xWidget, xPointer, xEvent, continueToDispatch);
            break;

    /*
        }
        return error;
    }
    */
/*
};
*/
