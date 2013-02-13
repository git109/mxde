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
 *   File: cxtshapedapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 5/29/2010
 **********************************************************************
 */
#if !defined(_CXTSHAPEDAPPLICATIONSHELL_HXX) || defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXTSHAPEDAPPLICATIONSHELL_HXX) && !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXTSHAPEDAPPLICATIONSHELL_HXX
#endif /* !defined(_CXTSHAPEDAPPLICATIONSHELL_HXX) && !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cxtapplicationshell.hxx"
#include "cximagesolidbrush.hxx"
#include "cximagebase.hxx"
#include "cximage.hxx"
#include "cxgc.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtShapedApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 5/29/2010
 **********************************************************************
 */
typedef cXtApplicationShell
cXtShapedApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXtShapedApplicationShell
 *
 * Author: $author$           
 *   Date: 5/29/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtShapedApplicationShell
: /*virtual public cXtShapedApplicationShellImplement,
  */public cXtShapedApplicationShellExtend
{
public:
    /*typedef cXtShapedApplicationShellImplement cImplements;
    */typedef cXtShapedApplicationShellExtend cExtends;

    cXGC m_imageGC;
    cXImageBase m_image;

    cXImageSolidBrush m_fgRegionBrush;
    cXImageSolidBrush m_bgRegionBrush;
    cXImageSolidBrush m_fgBrush;
    cXImageSolidBrush m_bgBrush;

    /**
     **********************************************************************
     *  Constructor: cXtShapedApplicationShell
     *
     *       Author: $author$           
     *         Date: 5/29/2010
     **********************************************************************
     */
    cXtShapedApplicationShell
    (cXDisplayInterface& display,
     const XtChar* name = CXTAPPLICATIONSHELL_NAME,
     const XtChar* className = CXTAPPLICATIONSHELL_CLASS_NAME,
     WidgetClass widgetClassAttached = CXTAPPLICATIONSHELL_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, name, className,
       widgetClassAttached, attached, isCreated),

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
     *  Destructor: ~cXtShapedApplicationShell
     *
     *      Author: $author$           
     *        Date: 5/29/2010
     **********************************************************************
     */
    virtual ~cXtShapedApplicationShell()
    {
    }
#else /* !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY)
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
    {
        cXGCInterface* gc = 0;
        error = e_ERROR_NOT_ATTACHED;
        return gc;
    }
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
    {
        eError error = e_ERROR_NOT_ATTACHED;
        return error;
    }
    /**
     **********************************************************************
     *  Function: GetGCAttached
     *
     *    Author: $author$           
     *      Date: 6/1/2010
     **********************************************************************
     */
    virtual GC GetGCAttached
    (bool onlyFreed=false)
    {
        eError error = e_ERROR_NONE;
        GC xGC = GetGCAttached(error, onlyFreed);
        return xGC;
    }
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
    {
        GC xGC = 0;
        Window xWindow;

        error = e_ERROR_NOT_ATTACHED;

        if ((xGC = m_imageGC.Attached()))
        {
            if (onlyFreed)
                error = e_ERROR_ALREADY_ATTACHED;
            else
                error = e_ERROR_NONE;
        }
        else
        if (None != (xWindow = WindowAttached()))
        {
            DBF(("() m_imageGC.CreateAttached()...\n"));
            if ((xGC = m_imageGC.CreateAttached(error, xWindow)))
            {
                m_imageGC.SetForeground(m_fgBrush.Attached());
                m_imageGC.SetBackground(m_bgBrush.Attached());
            }
        }
        return xGC;
    }
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
    {
        eError error = e_ERROR_NOT_ATTACHED;
        if (!(xGC != (m_imageGC.Attached())))
            error = e_ERROR_NONE;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTSHAPEDAPPLICATIONSHELL_HXX) || defined(CXTSHAPEDAPPLICATIONSHELL_MEMBERS_ONLY) */
