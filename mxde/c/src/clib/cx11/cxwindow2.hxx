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
 *   File: cxwindow.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXWINDOW_HXX) || defined(CXWINDOW_MEMBERS_ONLY)
#if !defined(_CXWINDOW_HXX) && !defined(CXWINDOW_MEMBERS_ONLY)
#define _CXWINDOW_HXX
#endif /* !defined(_CXWINDOW_HXX) && !defined(CXWINDOW_MEMBERS_ONLY) */

#if !defined(CXWINDOW_MEMBERS_ONLY)
#include "cxwindowinterface.hxx"
#include "cxdisplayinterface.hxx"
#include "cxrectangle.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXWindow
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class cXWindow
: virtual public cXWindowImplement,
  public cXWindowCreated
{
public:
    typedef cXWindowImplement cImplements;
    typedef cXWindowCreated cExtends;

    static XContext m_defaultXContext;
    static long m_defaultXEventMask;
    static long m_defaultGrabXEventMask;

    cXDisplayInterface& m_display;

    XContext m_xContext, m_savedXContext;

    long m_xEventMask, m_selectedXEventMask;
    long m_grabXEventMask, m_grabbedXEventMask;

    unsigned int m_exposeEventCount;

    cXEventTargetInterface* m_delegateAfterTo;
    cXEventTargetInterface* m_delegateBeforeTo;

    /**
     **********************************************************************
     *  Constructor: cXWindow
     *
     *       Author: $author$           
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXWindow
    (cXDisplayInterface& display,
     Window attached=None,
     bool isCreated=false,
     cXEventTargetInterface* delegateAfterTo=0,
     cXEventTargetInterface* delegateBeforeTo=0)
    : cExtends(attached,isCreated), 
      m_display(display),
      m_xContext(m_defaultXContext),
      m_savedXContext(0),
      m_xEventMask(m_defaultXEventMask),
      m_selectedXEventMask(0),
      m_grabXEventMask(m_defaultGrabXEventMask),
      m_grabbedXEventMask(0),
      m_exposeEventCount(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXWindow
     *
     *      Author: $author$           
     *        Date: 7/5/2009
     **********************************************************************
     */
    virtual ~cXWindow()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }
#else /* !defined(CXWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOW_MEMBERS_ONLY) */

#if !defined(CXWINDOW_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOW_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOW_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOW_HXX) || defined(CXWINDOW_MEMBERS_ONLY) */
