/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: cimageellipse.hxx
 *
 * Author: $author$
 *   Date: 6/4/2008
 **********************************************************************
 */
#ifndef _CIMAGEELLIPSE_HXX
#define _CIMAGEELLIPSE_HXX

#include "cimage.hxx"

/**
 **********************************************************************
 *  Class: cImageEllipse
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cImageEllipse
: public cImageObject
{
public:
    typedef cImageObject cIs;

	int m_quadrant;
    cImageColor m_fg_color;
    cImageColor m_bg_color;
    
    cImageColorProperty m_property_fg_color;
    cImageColorProperty m_property_bg_color;

    /**
     **********************************************************************
     * Constructor: cImageEllipse
     *
     *      Author: $author$
     *        Date: 3/28/2004
     **********************************************************************
     */
    cImageEllipse
    (cImageColor &fg_color, 
     cImageColor &bg_color, 
     int x=0, int y=0, 
	 int width=0, int height=0,
	 int quadrant=-1) 
    : cIs(x,y,width,height),

	  m_quadrant(quadrant),

      m_fg_color(fg_color),
      m_bg_color(bg_color),

      m_property_fg_color(m_property_list,m_fg_color,"fgcolor"),
      m_property_bg_color(m_property_list,m_bg_color,"bgcolor")
    {
    }

    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const
    {
		int x1 = (0>x)?m_x:x;
		int y1 = (0>y)?m_y:y;
		int x_radius = m_width/2;
		int y_radius = m_height/2;
		int cx = x1+x_radius-1;
		int cy = y1+y_radius-1;
        cImageInterface *color;

        if ((color = image.CreateColor(m_bg_color)))
        {
            color->SetImage();
            image.Fill(x1,y1,m_width,m_height);
            image.DestroyImage(color);
        }

        if ((color = image.CreateColor(m_fg_color)))
        {
            color->SetImage();
            image.DrawEllipse(cx,cy,x_radius,y_radius,m_quadrant);
            image.DestroyImage(color);
        }
    }
};

/**
 **********************************************************************
 *  Class: cImageEllipseType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cImageEllipseType
: public cImageObjectType
{
public:
    typedef cImageObjectType cIs;

    /**
     **********************************************************************
     * Constructor: cImageEllipseType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cImageEllipseType(const char *name="ellipse")
    : cIs(name) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObject *CreateObject
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element)
    {
        error=e_ERROR_NOT_IMPLEMENTED;
        cImageObject *object=0;

        cCharPointerAttributeValue file(element,"file",0);

        cImageColorAttributeValue
            fgcolor(element,"fgcolor",1,1,0,0,0,255),
            bgcolor(element,"bgcolor",1,1,255,255,255,255);

        cIntAttributeValue 
            x(element,"x",0),
            y(element,"y",0),
            width(element,"width",100),
            height(element,"height",24),
            quadrant(element,"quadrant",-1);

        if ((object=NewObject
            (fgcolor,bgcolor,x,y,width,height,quadrant)))
        {
            object->SetObjectType(this);

            if (file)
                object->SetFile(file);

            object->SetIsStatic(false);
        }

        return object;
    }
    /**
     **********************************************************************
     * Function: NewObject
     *
     *   Author: $author$
     *     Date: 5/19/2004
     **********************************************************************
     */
    virtual cImageObject *NewObject
    (cImageColor &fg_color, 
     cImageColor &bg_color, 
     int x=0, int y=0, 
	 int width=0, int height=0,
	 int quadrant=-1)
    {
        return new cImageEllipse
        (fg_color,bg_color,x,y,width,height,quadrant);
    }
};

/**
 **********************************************************************
 *  Class: cStaticImageEllipseType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cStaticImageEllipseType
: public cImageEllipseType
{
public:
    typedef cImageEllipseType cIs;

    static cStaticImageEllipseType m_instance;

    cStaticImageObjectType m_static_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageEllipseType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cStaticImageEllipseType()
    : m_static_type(*this) 
    {
    }
};

#endif /* _CIMAGEELLIPSE_HXX */
