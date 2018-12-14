/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cimageinterface.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CIMAGEINTERFACE_HXX
#define _CIMAGEINTERFACE_HXX

#include "cimagecolorinterface.hxx"
#include "ccreateinterface.hxx"
#include "cinterface.hxx"

/**
 **********************************************************************
 *  Class: cImageInterface
 *
 * Author: $author$
 *   Date: 2/29/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageInterface
: virtual public cCreateInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateColorImage
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColorImage
    (const cImageColorInterface &color, int w, int h) = 0;
    /**
     **********************************************************************
     * Function: CreateColorImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColorImage
    (int w, int h, int r, int g, int b, int o=-1)=0;
    /**
     **********************************************************************
     * Function: CreateFilledCircleImage
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateFilledCircleImage
    (cImageInterface& color, int r, int q=-1) = 0;
    /**
     **********************************************************************
     * Function: CreateFilledEllipseImage
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateFilledEllipseImage
    (cImageInterface& color, int w, int h) = 0;
    /**
     **********************************************************************
     * Function: CreateImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateImage(int w, int h)=0;
    /**
     **********************************************************************
     * Function: DestroyImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual eError DestroyImage(cImageInterface& image)=0;

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *SetImage(cImageInterface *image)=0;
    /**
     **********************************************************************
     * Function: GetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *GetImage() const=0;

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Plot(int x, int y)=0;
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Fill(int x, int y, int w, int h)=0;
    /**
     **********************************************************************
     * Function: Draw
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Draw(int x1, int y1, int x2, int y2)=0;

    /**
     **********************************************************************
     * Function: DrawCircle
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void DrawCircle
    (int x, int y, int r, int quadrant=-1)=0;
    /**
     **********************************************************************
     * Function: FillCircle
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void FillCircle
    (int x, int y, int r, int quadrant=-1)=0;

    /**
     **********************************************************************
     * Function: DrawEllipse
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void DrawEllipse
    (int x, int y, int a, int b, int quadrant=-1)=0;
    /**
     **********************************************************************
     * Function: FillEllipse
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void FillEllipse
    (int x, int y, int a, int b, int quadrant=-1)=0;
};

/**
 **********************************************************************
 *  Class: cImageImplement
 *
 * Author: $author$
 *   Date: 2/29/2004
 **********************************************************************
 */
class cImageImplement
: virtual public cImageInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateColorImage
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColorImage
    (const cImageColorInterface &color, int w, int h)
    {
        cImageInterface *im = CreateColorImage
        (w, h, color.GetRed(),color.GetGreen(),
         color.GetBlue(),color.GetOpacity());
        return im;
    }
    /**
     **********************************************************************
     * Function: CreateColorImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColorImage
    (int w, int h, int r, int g, int b, int o=-1)
    {
        cImageInterface *color=0;
        return color;
    }
    /**
     **********************************************************************
     * Function: CreateFilledCircleImage
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateFilledCircleImage
    (cImageInterface& color, int r, int q=-1) 
    {
        cImageInterface* image = 0;
        return image;
    }
    /**
     **********************************************************************
     * Function: CreateFilledEllipseImage
     *
     *   Author: $author$
     *     Date: 1/23/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateFilledEllipseImage
    (cImageInterface& color, int w, int h) 
    {
        cImageInterface* image = 0;
        return image;
    }
    /**
     **********************************************************************
     * Function: CreateImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateImage(int w, int h)
    {
        cImageInterface *image=0;
        return image;
    }
    /**
     **********************************************************************
     * Function: DestroyImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual eError DestroyImage(cImageInterface& image)
    {
        eError error=e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *SetImage(cImageInterface *image)
    {
        cImageInterface *old_image=0;
        return old_image;
    }
    /**
     **********************************************************************
     * Function: GetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *GetImage() const
    {
        cImageInterface *image=0;
        return image;
    }

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Plot(int x, int y)
    {
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Fill(int x, int y, int w, int h)
    {
    }
    /**
     **********************************************************************
     * Function: Draw
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void Draw(int x1, int y1, int x2, int y2)
    {
    }

    /**
     **********************************************************************
     * Function: DrawCircle
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void DrawCircle
    (int x, int y, int r, int quadrant=-1)
    {
    }
    /**
     **********************************************************************
     * Function: FillCircle
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void FillCircle
    (int x, int y, int r, int quadrant=-1)
    {
    }

    /**
     **********************************************************************
     * Function: DrawEllipse
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void DrawEllipse
    (int x, int y, int a, int b, int quadrant=-1)
    {
    }
    /**
     **********************************************************************
     * Function: FillEllipse
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual void FillEllipse
    (int x, int y, int a, int b, int quadrant=-1)
    {
    }
};

#endif /* _CIMAGEINTERFACE_HXX */


