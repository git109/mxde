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
///   File: XosOnXEventMembers.hpp
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////

#if defined(XOSONXEVENT_MEMBERS_CLASS)
///////////////////////////////////////////////////////////////////////
///  Class: XosOnXEvent
///
/// Author: $author$
///   Date: 4/29/2012
///////////////////////////////////////////////////////////////////////
class XosOnXEvent
{
public:
#endif // defined(XOSONXEVENT_MEMBERS_CLASS) 

    ///////////////////////////////////////////////////////////////////////
    /// Function: OnKeyPressXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnKeyPressXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnKeyPressXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnKeyReleaseXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnKeyReleaseXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnKeyReleaseXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnButtonPressXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnButtonPressXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnButtonPressXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnButtonReleaseXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnButtonReleaseXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnButtonReleaseXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMotionNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnMotionNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnMotionNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnEnterNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnEnterNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnEnterNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnLeaveNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnLeaveNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnLeaveNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnFocusInXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnFocusInXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnFocusInXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnFocusOutXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnFocusOutXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnFocusOutXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnKeymapNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnKeymapNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnKeymapNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnExposeXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnExposeXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnExposeXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnGraphicsExposeXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnGraphicsExposeXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnGraphicsExposeXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnNoExposeXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnNoExposeXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnNoExposeXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnVisibilityNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnVisibilityNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnVisibilityNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnCreateNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnCreateNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnCreateNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnDestroyNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnDestroyNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnDestroyNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnUnmapNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnUnmapNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnUnmapNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMapNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnMapNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnMapNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMapRequestXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnMapRequestXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnMapRequestXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnReparentNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnReparentNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnReparentNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnConfigureNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnConfigureNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnConfigureNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnConfigureRequestXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnConfigureRequestXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnConfigureRequestXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnGravityNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnGravityNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnGravityNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnResizeRequestXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnResizeRequestXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnResizeRequestXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnCirculateNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnCirculateNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnCirculateNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnCirculateRequestXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnCirculateRequestXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnCirculateRequestXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnPropertyNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnPropertyNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnPropertyNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnSelectionClearXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnSelectionClearXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnSelectionClearXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnSelectionRequestXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnSelectionRequestXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnSelectionRequestXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnSelectionNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnSelectionNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnSelectionNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnColormapNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnColormapNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnColormapNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnClientMessageXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnClientMessageXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnClientMessageXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnMappingNotifyXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnMappingNotifyXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DELEGATED)
        if ((m_delegated))
             error = m_delegated->OnMappingNotifyXEvent(xEvent);
        else
#endif // defined(XOSONXEVENT_MEMBERS_DELEGATED) 
        error = OnXEventDefault(xEvent);
        return error;
    }

#if defined(XOSONXEVENT_MEMBERS_DEFAULT)
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnXEventDefault
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnXEventDefault(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
#if defined(XOSONXEVENT_MEMBERS_DEFAULT_HANDLER)
        error = DefaultXEventHandler(xEvent);
#endif // defined(XOSONXEVENT_MEMBERS_DEFAULT_HANDLER) 
        return error;
    }
#endif // defined(XOSONXEVENT_MEMBERS_DEFAULT) 

#if defined(XOSONXEVENT_MEMBERS_ONXEVENT)
    ///////////////////////////////////////////////////////////////////////
    /// Function: OnXEvent
    ///
    ///   Author: $author$
    ///     Date: 4/29/2012
    ///////////////////////////////////////////////////////////////////////
    virtual XosError OnXEvent(const XEvent& xEvent) 
    {
        XosError error = XOS_ERROR_NONE;
        switch(xEvent.type)
        {
#include "XosOnXEventCases.hpp"
        default:
            error = OnXEventDefault(xEvent);
        }
        //error = DefaultXEventHandler(xEvent);
        return error;
    }
#endif // defined(XOSONXEVENT_MEMBERS_ONXEVENT) 

#if defined(XOSONXEVENT_MEMBERS_CLASS)
};
#endif // defined(XOSONXEVENT_MEMBERS_CLASS) 
