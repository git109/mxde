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
 *   File: cxtcryptoapplicationshell.hxx
 *
 * Author: $author$           
 *   Date: 6/25/2010
 **********************************************************************
 */
#if !defined(_CXTCRYPTOAPPLICATIONSHELL_HXX) || defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY)
#if !defined(_CXTCRYPTOAPPLICATIONSHELL_HXX) && !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY)
#define _CXTCRYPTOAPPLICATIONSHELL_HXX
#endif /* !defined(_CXTCRYPTOAPPLICATIONSHELL_HXX) && !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY)
#include "cxtellipticalroundedapplicationshell.hxx"
#include "cxcolormap.hxx"
#include "cximagecolor.hxx"
#include "cxfontstruct.hxx"
#include "cxfont.hxx"
#include "ckeyiconimageobject.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtCryptoApplicationShellExtend
 *
 *  Author: $author$           
 *    Date: 6/25/2010
 **********************************************************************
 */
typedef cXtEllipticalRoundedApplicationShell
cXtCryptoApplicationShellExtend;
/**
 **********************************************************************
 *  Class: cXtCryptoApplicationShell
 *
 * Author: $author$           
 *   Date: 6/25/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXtCryptoApplicationShell
: /*virtual public cXtCryptoApplicationShellImplement,*/
  public cXtCryptoApplicationShellExtend
{
public:
    /*typedef cXtCryptoApplicationShellImplement cImplements;*/
    typedef cXtCryptoApplicationShellExtend cExtends;

    typedef char tChar;

    cXColormap m_colormap;
    cXImage m_objectImage;
    cXImageColor m_blackColor;
    cXImageColor m_greyColor;
    cXImageColor m_regionColor;

    TSIZE m_keyIconWidth;
    TSIZE m_keyIconHeight;
    cKeyIconImageObject m_keyIcon;
    cKeyIconImageObject m_keyIconRegion;
    cXFont m_keyIconFont;
    cXFontStruct m_keyIconFontStruct;

    /**
     **********************************************************************
     *  Constructor: cXtCryptoApplicationShell
     *
     *       Author: $author$           
     *         Date: 6/25/2010
     **********************************************************************
     */
    cXtCryptoApplicationShell
    (cXDisplayInterface& display,
     TSIZE cornerRadiusWidth = CXTELLIPTICALROUNDEDAPPLICATIONSHELL_CORNER_RADIUS_WIDTH,
     TSIZE cornerRadiusHeight = CXTELLIPTICALROUNDEDAPPLICATIONSHELL_CORNER_RADIUS_HEIGHT,
     TSIZE edgeThickness = CXTELLIPTICALROUNDEDAPPLICATIONSHELL_EDGE_THICKNESS,
     const XtChar* name = CXTAPPLICATIONSHELL_NAME,
     const XtChar* className = CXTAPPLICATIONSHELL_CLASS_NAME,
     WidgetClass widgetClassAttached = CXTAPPLICATIONSHELL_WIDGET_CLASS,
     Widget attached = None,
     bool isCreated = false)
    : cExtends
      (display, cornerRadiusWidth, cornerRadiusHeight, edgeThickness, 
       name, className, widgetClassAttached, attached, isCreated),

      m_colormap(display),
      m_objectImage(m_imageGC),
      m_blackColor(m_objectImage, m_colormap, 0,0,0),
      m_greyColor(m_objectImage, m_colormap, 128,128,128),
      m_regionColor(m_objectImage, m_colormap, 1,1,1),

      m_keyIconWidth(64),
      m_keyIconHeight(32),
      m_keyIcon
      (m_objectImage, 
       m_blackColor,m_greyColor,m_blackColor, 
       m_keyIconWidth,m_keyIconHeight),
      m_keyIconRegion
      (m_objectImage, 
       m_regionColor,m_regionColor,m_regionColor, 
       m_keyIconWidth,m_keyIconHeight),
      m_keyIconFont(display),
      m_keyIconFontStruct(display)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXtCryptoApplicationShell
     *
     *      Author: $author$           
     *        Date: 6/25/2010
     **********************************************************************
     */
    virtual ~cXtCryptoApplicationShell()
    {
    }
#else /* !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY) */

#if !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: OnAfterXtPaintRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError OnAfterXtPaintRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xGC, Widget xWidget, 
     Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;

        cy = cy-m_cornerRadiusHeight-m_topMargin+m_edgeThickness+1;
        m_keyIcon.Plot(cx,cy);
        return error;
    }
    /**
     **********************************************************************
     * Function: OnAfterXtShapeRoundedRectangle
     *
     *   Author: $author$           
     *     Date: 6/10/2010
     **********************************************************************
     */
    virtual eError OnAfterXtShapeRoundedRectangle
    (tInt cx, tInt cy, tSize cWidth, tSize cHeight,
     XRectangle& rect, GC xPixmapGC, Pixmap xPixmap,
     Widget xWidget, Window xWindow, Display& xDisplay) 
    {
        eError error = e_ERROR_NONE;
        GC xGCAttached = m_imageGC.Attached();

        if ((m_imageGC.Attach(xPixmapGC)))
        {
            Drawable xGCDrawable = m_imageGC.SelectDrawable(xPixmap);

            cy = cy-m_cornerRadiusHeight-m_topMargin+m_edgeThickness+1;
            m_keyIconRegion.Plot(cx,cy);

            m_imageGC.SelectDrawable(xGCDrawable);
        }
        m_imageGC.Attach(xGCAttached);
        return error;
    }
    /**
     **********************************************************************
     * Function: BeforeCreateShapedApplicationShell
     *
     *   Author: $author$           
     *     Date: 6/9/2010
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
    {
        eError error = e_ERROR_NONE;

        DBF(("()...\n"));

        m_fgBrush.Attach(fgBrush.Attached());
        m_bgBrush.Attach(bgBrush.Attached());

        m_fgRegionBrush.Attach(fgRegionBrush.Attached());
        m_bgRegionBrush.Attach(bgRegionBrush.Attached());

        if (None != (m_colormap.Attach(colormap.Attached())))
        {
            m_blackColor.AllocateBYTE();
            m_greyColor.AllocateBYTE();
            m_regionColor.Attach(fgRegionBrush.Attached());
        }
        m_topMargin = m_keyIconHeight/2;
        return error;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY) */
#endif /* !defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY) */

#endif /* !defined(_CXTCRYPTOAPPLICATIONSHELL_HXX) || defined(CXTCRYPTOAPPLICATIONSHELL_MEMBERS_ONLY) */
