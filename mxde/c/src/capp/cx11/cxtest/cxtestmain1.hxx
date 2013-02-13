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
 *   File: cxtestmain.hxx
 *
 * Author: $author$           
 *   Date: 6/22/2009
 **********************************************************************
 */
#ifndef _CXTESTMAIN_HXX
#define _CXTESTMAIN_HXX

#include "cxmain.hxx"
#include "cximagesolidbrush.hxx"
#include "cximagebase.hxx"
#include "cxcolor.hxx"
#include "cxcolormap.hxx"
#include "cmidpointcircle.hxx"
#include "cmidpointellipse.hxx"
#include "cbresenham.hxx"

/**
 **********************************************************************
 *  Class: cXTestMainWindow
 *
 * Author: $author$           
 *   Date: 7/7/2009
 **********************************************************************
 */
class cXTestMainWindow
: public cXWindow
{
public:
    typedef cXWindow cExtends;
    typedef cXTestMainWindow cDerives;

    cXColormap m_colormap;
    cXColor m_foregroundColor;
    cXImageBase m_image;
    cXImageSolidBrush m_foregroundBrush;
    cMidpointCircle m_midpointCircle;
    cFilledMidpointCircle m_filledMidpointCircle;
    cMidpointEllipse m_midpointEllipse;
    cFilledMidpointEllipse m_filledMidpointEllipse;

    typedef cBresenhamFilledCircleT
    <cImageBaseInterface, cImageBaseInterface, cImageBase>
    cBresenhamFilledCircle;

    cBresenhamFilledCircle m_filledCircle;

    /**
     **********************************************************************
     * Constructor: cXTestMainWindow
     *
     *      Author: $author$           
     *        Date: 7/7/2009
     **********************************************************************
     */
    cXTestMainWindow
    (cXDisplayInterface& display) 
    : cExtends(display),
      m_colormap(display),
      m_foregroundColor(display, m_colormap),
      m_image(cExtends::m_gc),
      m_foregroundBrush(m_image),
      m_midpointCircle(m_image),
      m_filledMidpointCircle(m_image),
      m_midpointEllipse(m_image),
      m_filledMidpointEllipse(m_image),
      m_filledCircle(m_image)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXTestMainWindow
     *
     *     Author: $author$           
     *       Date: 7/7/2009
     **********************************************************************
     */
    virtual ~cXTestMainWindow()
    {
    }
    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError Paint
    (cXGCInterface& gc,
     cXRegionInterface& region,
     cXRectangle& rect) 
    {
        eError error = e_ERROR_NONE;
        int width = 50;
        int height = 25;
        int radius = 25;
        XRectangle r;

        //XGetWindowAttributes(xDisplay, attached, xWindowAttributes);

        //gc.FillRectangle(0,0, 25,25, m_foregroundColor.Attached());

        if (!(GetWindowRectangle(r)))
        {
            width = (r.width/2);
            height = (r.height/2);

            if (width < height)
                radius = (width/2);
            else radius = (height/2);
        }

        BresenhamCircleT
        <cBresenhamFilledCircle, cImageBaseInterface>
        (m_filledCircle, m_foregroundBrush, radius*3,radius,radius);

        m_midpointCircle.PlotCircle
        (m_foregroundBrush, radius,radius,radius, 
         e_CIRCLE_QUADRANT_1 | e_CIRCLE_QUADRANT_3);

        m_filledMidpointCircle.PlotCircle
        (m_foregroundBrush, radius,radius,radius, 
         e_CIRCLE_QUADRANT_2 | e_CIRCLE_QUADRANT_4);

        m_filledMidpointEllipse.PlotEllipse
        (m_foregroundBrush, width,height, width,height, 
         e_CIRCLE_QUADRANT_1 | e_CIRCLE_QUADRANT_3);

        m_midpointEllipse.PlotEllipse
        (m_foregroundBrush, width,height, width,height, 
         e_CIRCLE_QUADRANT_2 | e_CIRCLE_QUADRANT_4);
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cXTestMain
 *
 * Author: $author$           
 *   Date: 6/22/2009
 **********************************************************************
 */
class cXTestMain
: public cXMain
{
public:
    typedef cXMain cExtends;
    typedef cXTestMain cDerives;

    cXTestMainWindow m_mainWindow;

    /**
     **********************************************************************
     * Constructor: cXTestMain
     *
     *      Author: $author$           
     *        Date: 7/6/2009
     **********************************************************************
     */
    cXTestMain() 
    : m_mainWindow(cExtends::m_display)
    {
    }
    /**
     **********************************************************************
     * Function: BeforeOpenMainWindow
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError BeforeOpenMainWindow
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        eError error = e_ERROR_NONE;
        if (None != (m_mainWindow.m_colormap.AttachDefault()))
        if (!(error = m_mainWindow.m_foregroundColor.AllocateBYTE(255, 0, 0)))
            m_mainWindow.m_foregroundBrush.Attach
            (m_mainWindow.m_foregroundColor.Attached());
        return error;
    }
    /**
     **********************************************************************
     * Function: AfterCloseMainWindow
     *
     *   Author: $author$           
     *     Date: 7/7/2009
     **********************************************************************
     */
    virtual eError AfterCloseMainWindow
    (cXDisplayInterface& display,
     Window rootXWindow,
     tInt argc,
     const tChar** argv,
     const tChar** env) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: MainWindow
     *
     *   Author: $author$           
     *     Date: 7/6/2009
     **********************************************************************
     */
    virtual cXWindowInterface* MainWindow
    (eError& error) 
    {
        cXWindowInterface* window = &m_mainWindow;
        error = e_ERROR_NONE;
        return window;
    }
};
#endif /* _CXTESTMAIN_HXX */
