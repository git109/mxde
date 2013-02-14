///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2012 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: XosOnXEventCases.hpp
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////

#if defined(XOSONXEVENT_MEMBER_CASES_SWITCH)
        switch(xEvent.type)
        {
#endif // defined(XOSONXEVENT_MEMBER_CASES_SWITCH) 

           case KeyPress:
                error = OnKeyPressXEvent(xEvent);
                break;

           case KeyRelease:
                error = OnKeyReleaseXEvent(xEvent);
                break;

           case ButtonPress:
                error = OnButtonPressXEvent(xEvent);
                break;

           case ButtonRelease:
                error = OnButtonReleaseXEvent(xEvent);
                break;

           case MotionNotify:
                error = OnMotionNotifyXEvent(xEvent);
                break;

           case EnterNotify:
                error = OnEnterNotifyXEvent(xEvent);
                break;

           case LeaveNotify:
                error = OnLeaveNotifyXEvent(xEvent);
                break;

           case FocusIn:
                error = OnFocusInXEvent(xEvent);
                break;

           case FocusOut:
                error = OnFocusOutXEvent(xEvent);
                break;

           case KeymapNotify:
                error = OnKeymapNotifyXEvent(xEvent);
                break;

           case Expose:
                error = OnExposeXEvent(xEvent);
                break;

           case GraphicsExpose:
                error = OnGraphicsExposeXEvent(xEvent);
                break;

           case NoExpose:
                error = OnNoExposeXEvent(xEvent);
                break;

           case VisibilityNotify:
                error = OnVisibilityNotifyXEvent(xEvent);
                break;

           case CreateNotify:
                error = OnCreateNotifyXEvent(xEvent);
                break;

           case DestroyNotify:
                error = OnDestroyNotifyXEvent(xEvent);
                break;

           case UnmapNotify:
                error = OnUnmapNotifyXEvent(xEvent);
                break;

           case MapNotify:
                error = OnMapNotifyXEvent(xEvent);
                break;

           case MapRequest:
                error = OnMapRequestXEvent(xEvent);
                break;

           case ReparentNotify:
                error = OnReparentNotifyXEvent(xEvent);
                break;

           case ConfigureNotify:
                error = OnConfigureNotifyXEvent(xEvent);
                break;

           case ConfigureRequest:
                error = OnConfigureRequestXEvent(xEvent);
                break;

           case GravityNotify:
                error = OnGravityNotifyXEvent(xEvent);
                break;

           case ResizeRequest:
                error = OnResizeRequestXEvent(xEvent);
                break;

           case CirculateNotify:
                error = OnCirculateNotifyXEvent(xEvent);
                break;

           case CirculateRequest:
                error = OnCirculateRequestXEvent(xEvent);
                break;

           case PropertyNotify:
                error = OnPropertyNotifyXEvent(xEvent);
                break;

           case SelectionClear:
                error = OnSelectionClearXEvent(xEvent);
                break;

           case SelectionRequest:
                error = OnSelectionRequestXEvent(xEvent);
                break;

           case SelectionNotify:
                error = OnSelectionNotifyXEvent(xEvent);
                break;

           case ColormapNotify:
                error = OnColormapNotifyXEvent(xEvent);
                break;

           case ClientMessage:
                error = OnClientMessageXEvent(xEvent);
                break;

           case MappingNotify:
                error = OnMappingNotifyXEvent(xEvent);
                break;

#if defined(XOSONXEVENT_MEMBER_CASES_DEFAULT)
           default:
                error = OnXEventDefault(xEvent);
                break;
#endif // defined(XOSONXEVENT_MEMBER_CASES_DEFAULT) 

#if defined(XOSONXEVENT_MEMBER_CASES_SWITCH)
        }
#endif // defined(XOSONXEVENT_MEMBER_CASES_SWITCH) 
