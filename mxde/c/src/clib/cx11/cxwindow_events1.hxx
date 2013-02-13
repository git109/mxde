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
 *   File: cxwindow_events.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#ifndef _CXWINDOW_EVENTS_HXX
#define _CXWINDOW_EVENTS_HXX

#if defined(CXWINDOW_EVENTS_CLASS) 
/**
 **********************************************************************
 *  Class: cXWindow
 *
 * Author: $author$           
 *   Date: 7/6/2009
 **********************************************************************
 */
class cXWindow
{
public:
#endif /* defined(CXWINDOW_EVENTS_CLASS) */

    /**
     **********************************************************************
     * Function: OnExposeXEvent
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual eError OnExposeXEvent
    (const XEvent& xEvent) 
#if defined(CXWINDOW_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXWINDOW_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) 
        cXRectangle rect(xEvent.xexpose);
        Region xRegion;

        DBI(("() \n"));

        if (None == (xRegion = m_paintRegion.Attached()))
        if ((error = m_paintRegion.Create()))
            return error;

        if (1 > (m_exposeEventCount++))
            m_paintRect.Set(rect);
        else
        m_paintRect.Include(rect);

        if (1 > xEvent.xexpose.count)
        {
            error = OnPaint(xEvent);
            m_paintRegion.Destroy();
            m_exposeEventCount = 0;
        }
#else /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXWINDOW_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXWINDOW_MEMBER_FUNCS_INTERFACE) */

#if defined(CXWINDOW_EVENTS_CLASS) 
};
#endif /* defined(CXWINDOW_EVENTS_CLASS) */

#endif /* _CXWINDOW_EVENTS_HXX */
