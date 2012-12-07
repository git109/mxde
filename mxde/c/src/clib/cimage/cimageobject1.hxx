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
 *   File: cimageobject.hxx
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
#ifndef _CIMAGEOBJECT_HXX
#define _CIMAGEOBJECT_HXX

#include "cimageinterface.hxx"
#include "clist.hxx"

class cImageObject;
/**
 **********************************************************************
 * Typedef: cImageObjectItemExtends
 *
 *  Author: $author$
 *    Date: 5/28/2009
 **********************************************************************
 */
typedef cListItemT<cImageObject>
cImageObjectItemExtends;
/**
 **********************************************************************
 *  Class: cImageObjectItem
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class cImageObjectItem
: public cImageObjectItemExtends
{
public:
    typedef cImageObjectItemExtends cExtends;
    typedef cImageObjectItem cDerives;
};

/**
 **********************************************************************
 *  Class: cImageObject
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class cImageObject
: virtual public cImageImplement,
  public cImageObjectItem
{
public:
    typedef cImageImplement cImplements;
    typedef cImageObjectItem cExtends;
    typedef cImageObject cDerives;

    cImageInterface& m_image;

    /**
     **********************************************************************
     * Constructor: cImageObject
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cImageObject
    (cImageInterface& image) 
    : m_image(image)
    {
    }

    /**
     **********************************************************************
     * Function: SetAsImage
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual tImageInterface* SetAsImage() 
    {
        tImageInterface* prevImage = m_image.Image();
        m_image.SetImage(this);
        return prevImage;
    }
};

/**
 **********************************************************************
 *  Class: cImageCircle
 *
 * Author: $author$
 *   Date: 5/31/2009
 **********************************************************************
 */
class cImageCircle
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    typedef cImageCircle cDerives;

    cImageObject& m_color;
    tSize m_radius;
    eQuadrant m_quadrant;

    /**
     **********************************************************************
     * Constructor: cImageCircle
     *
     *      Author: $author$
     *        Date: 5/31/2009
     **********************************************************************
     */
    cImageCircle
    (cImageInterface& image,
     cImageObject& color,
     tSize radius,
     eQuadrant quadrant=e_QUADRANT_ALL) 
    : cExtends(image),
      m_color(color),
      m_radius(radius),
      m_quadrant(quadrant)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageCircle
     *
     *     Author: $author$
     *       Date: 5/31/2009
     **********************************************************************
     */
    virtual ~cImageCircle()
    {
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = m_color.SetAsImage();
        m_image.DrawCircle(x, y, m_radius, m_quadrant);
        if (image) 
            image->SetAsImage();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cImageSolidCircle
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class cImageSolidCircle
: public cImageCircle
{
public:
    typedef cImageCircle cExtends;
    typedef cImageSolidCircle cDerives;

    /**
     **********************************************************************
     * Constructor: cImageSolidCircle
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cImageSolidCircle
    (cImageInterface& image,
     cImageObject& color,
     tSize radius,
     eQuadrant quadrant=e_QUADRANT_ALL) 
    : cExtends(image,color,radius,quadrant)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageSolidCircle
     *
     *     Author: $author$
     *       Date: 5/28/2009
     **********************************************************************
     */
    virtual ~cImageSolidCircle()
    {
    }

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = m_color.SetAsImage();
        m_image.FillCircle(x, y, m_radius, m_quadrant);
        if (image) 
            image->SetAsImage();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cImageRoundedRectangle
 *
 * Author: $author$
 *   Date: 5/31/2009
 **********************************************************************
 */
class cImageRoundedRectangle
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    typedef cImageRoundedRectangle cDerives;

    cImageObject& m_topLeftColor;
    cImageObject& m_topColor;
    cImageObject& m_topRightColor;
    cImageObject& m_rightColor;
    cImageObject& m_bottomRightColor;
    cImageObject& m_bottomColor;
    cImageObject& m_bottomLeftColor;
    cImageObject& m_leftColor;
    tSize m_radius, m_width, m_height, m_thick;

    /**
     **********************************************************************
     * Constructor: cImageRoundedRectangle
     *
     *      Author: $author$
     *        Date: 5/31/2009
     **********************************************************************
     */
    cImageRoundedRectangle
    (cImageInterface& image,
     cImageObject& color,
     tSize radius, 
     tSize width, 
     tSize height,
     tSize thick=1) 
    : cExtends(image),
       m_topLeftColor(color),
       m_topColor(color),
       m_topRightColor(color),
       m_rightColor(color),
       m_bottomRightColor(color),
       m_bottomColor(color),
       m_bottomLeftColor(color),
       m_leftColor(color),
       m_radius(radius),
       m_width(width),
       m_height(height),
       m_thick(thick)
    {
    }
    /**
     **********************************************************************
     * Constructor: cImageRoundedRectangle
     *
     *      Author: $author$
     *        Date: 5/31/2009
     **********************************************************************
     */
    cImageRoundedRectangle
    (cImageInterface& image,
     cImageObject& topLeftColor,
     cImageObject& topColor,
     cImageObject& topRightColor,
     cImageObject& rightColor,
     cImageObject& bottomRightColor,
     cImageObject& bottomColor,
     cImageObject& bottomLeftColor,
     cImageObject& leftColor,
     tSize radius, 
     tSize width, 
     tSize height,
     tSize thick=1) 
    : cExtends(image),
       m_topLeftColor(topLeftColor),
       m_topColor(topColor),
       m_topRightColor(topRightColor),
       m_rightColor(rightColor),
       m_bottomRightColor(bottomRightColor),
       m_bottomColor(bottomColor),
       m_bottomLeftColor(bottomLeftColor),
       m_leftColor(leftColor),
       m_radius(radius),
       m_width(width),
       m_height(height),
       m_thick(thick)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageRoundedRectangle
     *
     *     Author: $author$
     *       Date: 5/31/2009
     **********************************************************************
     */
    virtual ~cImageRoundedRectangle()
    {
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image = 
            
        m_topLeftColor.SetAsImage();
        m_image.DrawCircle(x, y, m_radius, e_QUADRANT_TOP_LEFT);

        m_topColor.SetAsImage();
        m_image.Fill(x, y-m_radius+1, m_width-m_thick+1, 1);

        m_topRightColor.SetAsImage();
        m_image.DrawCircle(x+m_width-m_thick, y, m_radius, e_QUADRANT_TOP_RIGHT);

        m_rightColor.SetAsImage();
        m_image.Fill(x+m_width+m_radius-m_thick-1, y, 1, m_height-m_thick+1);

        m_bottomRightColor.SetAsImage();
        m_image.DrawCircle(x+m_width-m_thick, y+m_height-m_thick, m_radius, e_QUADRANT_BOTTOM_RIGHT);

        m_bottomColor.SetAsImage();
        m_image.Fill(x, y+m_height+m_radius-m_thick-1, m_width-m_thick+1, 1);

        m_bottomLeftColor.SetAsImage();
        m_image.DrawCircle(x, y+m_height-m_thick, m_radius, e_QUADRANT_BOTTOM_LEFT);

        m_leftColor.SetAsImage();
        m_image.Fill(x-m_radius+1, y, 1, m_height-m_thick+1);

        if (image) 
            image->SetAsImage();
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cImageRectangle
 *
 * Author: $author$
 *   Date: 5/31/2009
 **********************************************************************
 */
class cImageRectangle
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    typedef cImageRectangle cDerives;

    cImageObject& m_topColor;
    cImageObject& m_rightColor;
    cImageObject& m_bottomColor;
    cImageObject& m_leftColor;
    tSize m_width, m_height, m_thick;

    /**
     **********************************************************************
     * Constructor: cImageRectangle
     *
     *      Author: $author$
     *        Date: 5/31/2009
     **********************************************************************
     */
    cImageRectangle
    (cImageInterface& image,
     cImageObject& topColor,
     cImageObject& rightColor,
     cImageObject& bottomColor,
     cImageObject& leftColor,
     tSize width, tSize height, tSize thick=1) 
    : cExtends(image),
       m_topColor(topColor),
       m_rightColor(rightColor),
       m_bottomColor(bottomColor),
       m_leftColor(leftColor),
       m_width(width),
       m_height(height),
       m_thick(thick)
    {
    }
    /**
     **********************************************************************
     * Constructor: cImageRectangle
     *
     *      Author: $author$
     *        Date: 5/31/2009
     **********************************************************************
     */
    cImageRectangle
    (cImageInterface& image,
     cImageObject& color,
     tSize width, tSize height, tSize thick=1) 
    : cExtends(image),
       m_topColor(color),
       m_rightColor(color),
       m_bottomColor(color),
       m_leftColor(color),
       m_width(width),
       m_height(height),
       m_thick(thick)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageRectangle
     *
     *     Author: $author$
     *       Date: 5/31/2009
     **********************************************************************
     */
    virtual ~cImageRectangle()
    {
    }
    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 5/31/2009
     **********************************************************************
     */
    virtual eError Plot
    (tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        cImageInterface* image;
        
        image = m_topColor.SetAsImage();
        m_image.Fill(x, y, m_width-m_thick+1, 1);
        if (image) 
            image->SetAsImage();

        image = m_rightColor.SetAsImage();
        m_image.Fill(x+m_width-m_thick, y, 1, m_height-m_thick+1);
        if (image) 
            image->SetAsImage();

        image = m_bottomColor.SetAsImage();
        m_image.Fill(x, y+m_height-m_thick, m_width-m_thick+1, 1);
        if (image) 
            image->SetAsImage();

        image = m_leftColor.SetAsImage();
        m_image.Fill(x, y, 1, m_height-m_thick+1);
        if (image) 
            image->SetAsImage();

        return error;
    }
};

#endif /* _CIMAGEOBJECT_HXX */
