/**
 **********************************************************************
 * Copyright (c) 1988-2004 $organization$.
 *
 * This software is provided by the author and contributors ``as is'' and
 * any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed.  In no event shall the author or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute goods
 * or services; loss of use, data, or profits; or business interruption)
 * however caused and on any theory of liability, whether in contract, strict
 * liability, or tort (including negligence or otherwise) arising in any way
 * out of the use of this software, even if advised of the possibility of
 * such damage.
 *
 *   File: cimage.hxx
 *
 * Author: $author$
 *   Date: 3/27/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIMAGE_HXX
#define _CIMAGE_HXX

#include <stdlib.h>

#include "cproperty.hxx"
#include "cattributevalue.hxx"
#include "clistt.hxx"
#include "cavltreet.hxx"
#include "cinstance.hxx"
#include "cimageinterface.hxx"

class cImageObject;

/**
 **********************************************************************
 *  Class: cImageObjectSet
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cImageObjectSet
: virtual public cImageObjectSetInterface,
  virtual public cImageObjectSetImplement,
  public cDynamicListT<cImageObject,cImageObjectSet,cInstance>
{
public:
    typedef cDynamicListT<cImageObject,cImageObjectSet,cInstance> cIs;

    /**
     **********************************************************************
     * Function: GetFirstObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetFirstObject() const
    {
        return (cImageObjectInterface*)cListIs::GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetLastObject() const
    {
        return (cImageObjectInterface*)cListIs::GetLast();
    }
};

/**
 **********************************************************************
 *  Class: cImageObject
 *
 * Author: $author$
 *   Date: 3/27/2004
 **********************************************************************
 */
class cImageObject
: virtual public cImageObjectSetInterface,
  virtual public cImageObjectInterface,
  virtual public cImageObjectSetImplement,
  virtual public cImageObjectImplement,
  public cDynamicListItemT<cImageObject,cImageObjectSet>
{
public:
    typedef cDynamicListItemT<cImageObject,cImageObjectSet> cIs;

    cImageObjectTypeInterface *m_object_type;

    int m_x, m_y, m_width, m_height, m_style, m_state;
    cCharBuffer m_file;

    cPropertyList m_property_list;
    cIntProperty 
        m_property_x, m_property_y, 
        m_property_width, m_property_height, 
        m_property_style, m_property_state;

    /**
     **********************************************************************
     * Constructor: cImageObject
     *
     *      Author: $author$
     *        Date: 3/27/2004
     **********************************************************************
     */
    cImageObject
    (int x=0, int y=0, int width=0, int height=0,
     int style=0, int state=0)
    : cIs(true),

      m_object_type(0),

      m_x(x), 
      m_y(y),
      m_width(width), 
      m_height(height),
      m_style(style),
      m_state(state),

      m_property_x(m_property_list,m_x,"x"), 
      m_property_y(m_property_list,m_y,"y"),
      m_property_width(m_property_list,m_width,"width"), 
      m_property_height(m_property_list,m_height,"height"),
      m_property_style(m_property_list,m_style,"style"),
      m_property_state(m_property_list,m_state,"state")
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImageObject
     *
     *     Author: $author$
     *       Date: 3/27/2004
     **********************************************************************
     */
    virtual ~cImageObject()
    {
    }

    /**
     **********************************************************************
     * Function: GetFirstProperty
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual cProperty *GetFirstProperty() const
    {
        return m_property_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLastProperty
     *
     *   Author: $author$
     *     Date: 4/12/2004
     **********************************************************************
     */
    virtual cProperty *GetLastProperty() const
    {
        return m_property_list.GetLast();
    }

    /**
     **********************************************************************
     * Function: SetObjectType
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual cImageObjectTypeInterface *SetObjectType
    (cImageObjectTypeInterface *object_type)
    {
        return m_object_type = object_type;
    }
    /**
     **********************************************************************
     * Function: GetObjectType
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual cImageObjectTypeInterface *GetObjectType() const
    {
        return m_object_type;
    }

    /**
     **********************************************************************
     * Function: GetNextObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetNextObject() const
    {
        return cListItemIs::GetNext();
    }
    /**
     **********************************************************************
     * Function: GetPreviousObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetPreviousObject() const
    {
        return cListItemIs::GetPrevious();
    }

    /**
     **********************************************************************
     * Function: SetFile
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    virtual eError SetFile(const char *file, int length=-1)
    {
        return m_file.Copy(file, length);
    }
    /**
     **********************************************************************
     * Function: GetFile
     *
     *   Author: $author$
     *     Date: 4/5/2004
     **********************************************************************
     */
    virtual const char *GetFile(int &length) const
    {
        return m_file.GetBuffer(length);
    }

    /**
     **********************************************************************
     * Function: SetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int SetState(int state)
    {
        int old_state=m_state;

        m_state=state;
        return old_state;
    }
    /**
     **********************************************************************
     * Function: GetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int GetState() const
    {
        return m_state;
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
    }
};

class cImageObjectTypes;

/**
 **********************************************************************
 *  Class: cImageObjectType
 *
 * Author: $author$
 *   Date: 3/31/2004
 **********************************************************************
 */
class cImageObjectType
: virtual public cImageObjectTypeInterface,
  public cAVLTreeBranchT<cImageObjectType>
{
public:
    typedef cAVLTreeBranchT<cImageObjectType> cIs;

    const char *m_name;

    /**
     **********************************************************************
     * Constructor: cImageObjectType
     *
     *      Author: $author$
     *        Date: 3/31/2004
     **********************************************************************
     */
    cImageObjectType(const char *name="")
    : m_name(name) 
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
        cImageObject *object=0;
        error=e_ERROR_NOT_IMPLEMENTED;
        return object;
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    int Compare(cImageObjectType &branch) const
    {
        return Compare(branch.GetName());
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    int Compare(const char *name) const
    {
        int result=-1;
        const char *fname;

        if ((fname = GetName()))
            result = strcmp(name, fname);

        return result;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual const char *GetName() const
    {
        return m_name;
    }
};

/**
 **********************************************************************
 *  Class: cImageObjectTypes
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cImageObjectTypes
: public cAVLTreeT
  <const char *, cImageObjectType, cImageObjectTypes>
{
public:
    typedef cAVLTreeT
    <const char *, cImageObjectType, cImageObjectTypes> cIs;
};

/**
 **********************************************************************
 *  Class: cStaticImageObjectType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cStaticImageObjectType
: public cListItemT<cStaticImageObjectType>
{
public:
    typedef cListItemT<cStaticImageObjectType> cIs;

    /**
     **********************************************************************
     *  Class: cList
     *
     * Author: $author$
     *   Date: 4/1/2004
     **********************************************************************
     */
    class cList
    : public cStaticListT<cStaticImageObjectType,cList>
    {
    public:
        typedef cStaticListT<cStaticImageObjectType,cList> cIs;
    };

    static cList m_list;

    cImageObjectType &m_object_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageObjectType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cStaticImageObjectType(cImageObjectType &object_type) 
    : m_object_type(object_type) 
    {
        m_list.Add(this);
    }

    /**
     **********************************************************************
     * Function: GetObjectType
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    inline cImageObjectType &GetObjectType()
    {
        return m_object_type;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    static inline cStaticImageObjectType *GetFirst()
    {
        return m_list.GetFirst();
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    static inline cStaticImageObjectType *GetLast()
    {
        return m_list.GetLast();
    }
};

/**
 **********************************************************************
 *  Class: cImageGroupType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cImageGroupType
: public cImageObjectType
{
public:
    typedef cImageObjectType cIs;

    /**
     **********************************************************************
     * Constructor: cImageGroupType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cImageGroupType(const char *name="group")
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
        error=e_ERROR_NONE;
        cImageObjectType *object_type=0;
        cImageObject *object=0;
        cElementInterface *e;

        if ((e = element.GetFirstElement()))
        do
        {
            const char *text=e->GetText();

            if ((object_type = object_types.Find(text)))
            if ((object = object_type->CreateObject
                (error, object_set, object_types, *e)))
                object_set.Add(object);
        }
        while ((e = e->GetNextElement()));

        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cStaticImageGroupType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cStaticImageGroupType
: public cImageGroupType
{
public:
    typedef cImageGroupType cIs;

    static cStaticImageGroupType m_instance;

    cStaticImageObjectType m_static_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageGroupType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cStaticImageGroupType()
    : m_static_type(*this) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cImageCanvas
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cImageCanvas
: public cImageObject
{
public:
    typedef cImageObject cIs;

    cImageColor m_bg_color;

    /**
     **********************************************************************
     * Constructor: cImageCanvas
     *
     *      Author: $author$
     *        Date: 3/28/2004
     **********************************************************************
     */
    cImageCanvas
    (cImageColor &bg_color,
     int x=0, int y=0, int width=0, int height=0) 
    : cIs(x,y,width,height),
      m_bg_color(bg_color)
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
        cImageInterface *bg_color;

        if (0 >  x)
            x = m_x;

        if (0 > y)
            y = m_y;

        if ((bg_color = image.CreateColor(m_bg_color)))
        {
            bg_color->SetImage();
            image.Fill(x,y,m_width,m_height);
            image.DestroyImage(bg_color);
        }
    }
};

/**
 **********************************************************************
 *  Class: cImageCanvasType
 *
 * Author: $author$
 *   Date: 4/7/2004
 **********************************************************************
 */
class cImageCanvasType
: public cImageObjectType
{
public:
    typedef cImageObjectType cIs;

    /**
     **********************************************************************
     * Constructor: cImageCanvasType
     *
     *      Author: $author$
     *        Date: 4/7/2004
     **********************************************************************
     */
    cImageCanvasType(const char *name="canvas")
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Function: CreateObject
     *
     *   Author: $author$
     *     Date: 4/7/2004
     **********************************************************************
     */
    virtual cImageObject *CreateObject
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element)
    {
        error=e_ERROR_NONE;
        cImageObject *object=0;

        cCharPointerAttributeValue file(element,"file",0);

        cImageColorAttributeValue 
            bgcolor(element,"bgcolor",1,1,0,0,0,255);

        cIntAttributeValue 
            x(element,"x",0),
            y(element,"y",0),
            width(element,"width",100),
            height(element,"height",100);

        if ((object=new cImageCanvas
            (bgcolor,x,y,width,height)))
        {
            object->SetObjectType(this);

            if (file)
                object->SetFile(file);

            object->SetIsStatic(false);
        }

        return object;
    }
};

/**
 **********************************************************************
 *  Class: cStaticImageCanvasType
 *
 * Author: $author$
 *   Date: 4/7/2004
 **********************************************************************
 */
class cStaticImageCanvasType
: public cImageCanvasType
{
public:
    typedef cImageCanvasType cIs;

    static cStaticImageCanvasType m_instance;

    cStaticImageObjectType m_static_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageCanvasType
     *
     *      Author: $author$
     *        Date: 4/7/2004
     **********************************************************************
     */
    cStaticImageCanvasType() 
    : m_static_type(*this) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cImageTab
 *
 * Author: $author$
 *   Date: 3/28/2004
 **********************************************************************
 */
class cImageTab
: public cImageObject
{
public:
    typedef cImageObject cIs;

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 3/28/2004
     **********************************************************************
     */
    enum
    {
        e_DEFAULT_STATE,
        e_STATE_BOTTOM = e_DEFAULT_STATE,
        e_STATE_TOP,
        e_STATES
    };

    /**
     **********************************************************************
     *   Enum: 
     *
     * Author: $author$
     *   Date: 5/3/2004
     **********************************************************************
     */
    enum
    {
        e_DEFAULT_STYLE,
        e_STYLE_TOP = e_DEFAULT_STYLE,
        e_STYLE_LEFT,
        e_STYLE_RIGHT,
        e_STYLE_BOTTOM,
        e_STYLES
    };

    int m_left_border,m_right_border;
    int m_top_border,m_bottom_border;
    int m_edge,m_radius;
    bool m_previous_sibling,m_next_sibling;

    cImageColor m_fg_color;
    cImageColor m_bg_color;
    cImageColor m_edge_color;

    cIntProperty m_property_radius;
    cImageColorProperty 
        m_property_fg_color,
        m_property_bg_color,
        m_property_edge_color;

    /**
     **********************************************************************
     * Constructor: cImageTab
     *
     *      Author: $author$
     *        Date: 3/28/2004
     **********************************************************************
     */
    cImageTab
    (cImageColor &fg_color, 
     cImageColor &bg_color,
     cImageColor &edge_color,
     int x=0, int y=0, int width=0, int height=0,
     int left_border=0, int right_border=0,
     int top_border=0, int bottom_border=0, 
     int edge=0, int radius=0, bool previous_sibling=false, 
     bool next_sibling=false, int style=e_DEFAULT_STYLE, 
     int state=e_DEFAULT_STATE) 
    : cIs(x,y,width,height,style,state),
      m_fg_color(fg_color),
      m_bg_color(bg_color),
      m_edge_color(edge_color),
      m_left_border(left_border),
      m_right_border(right_border),
      m_top_border(top_border),
      m_bottom_border(bottom_border),
      m_edge(edge),
      m_radius(radius),
      m_previous_sibling(previous_sibling),
      m_next_sibling(next_sibling),

      m_property_fg_color(m_property_list,m_fg_color,"fgcolor"),
      m_property_bg_color(m_property_list,m_bg_color,"bgcolor"),
      m_property_edge_color(m_property_list,m_edge_color,"edgecolor"),
      m_property_radius(m_property_list,m_radius,"radius")
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
        int edge=0, bottom=0, bottom_border=m_bottom_border;
        bool is_on_edge=false;
        cImageInterface *color;

		if (e_STATE_BOTTOM != m_state)
		switch(m_style)
		{
		case e_STYLE_TOP:
			bottom_border = 0;
			break;
		}

        if (0 >  x)
            x = m_x;

        if (0 > y)
            y = m_y;

        if ((color = image.CreateColor(m_bg_color)))
        {
            color->SetImage();

            image.Fill(x,y,m_width,m_height);
            image.DestroyImage(color);
        }

        if (0 < m_edge)
        {
            is_on_edge = true;
            color = image.CreateColor(m_edge_color);
        }
        else 
        {
            bottom = bottom_border;
            color = image.CreateColor(m_fg_color);
        }

        if (color)
        do
        {
            color->SetImage();

            if ((e_STYLE_TOP == m_style) 
                || (e_STYLE_LEFT == m_style) 
                || (e_STYLES == m_style))
            {
				/* top left radius
				 */
                image.FillCircle
                (x+m_left_border+m_radius-1,
                 y+m_top_border+m_radius-1,m_radius-edge);
            }
            else
            {
                image.Fill
                (x+m_left_border+edge, 
                 y+m_top_border+edge,
                 m_radius-edge, m_radius-edge);
            }

            if ((e_STYLE_TOP == m_style) 
                || (e_STYLE_RIGHT == m_style) 
                || (e_STYLES == m_style))
            {
                /* top right radius
                 */
                image.FillCircle
                (x+m_width-m_right_border-m_radius,
                 y+m_top_border+m_radius-1,m_radius-edge);
            }
            else
            {
                image.Fill
                (x+m_width-m_right_border-m_radius,
                 y+m_top_border+edge,
                 m_radius-edge, m_radius-edge);
            }

            /* fill between radii
             */
            image.Fill
            (x+m_left_border+m_radius-1,y+m_top_border+edge,
             m_width-m_left_border-m_right_border-m_radius-m_radius+1,
             m_radius+m_radius-edge-edge-1);

            /* fill below radii
             */
            image.Fill
            (x+m_left_border+edge,y+m_top_border+m_radius-1,
             m_width-m_left_border-m_right_border-edge-edge,
             m_height-m_top_border-bottom-m_radius+1);

            if (is_on_edge)
            {
                if (m_previous_sibling && (0 < m_left_border))
                    image.Fill
                    (x,y+m_height-m_bottom_border,
                     m_left_border,m_bottom_border);

                if (m_next_sibling && (0 < m_right_border))
                    image.Fill
                    (x+m_width-m_right_border,
                     y+m_height-m_bottom_border,
                     m_right_border,m_bottom_border);
            }

            image.DestroyImage(color);
            color = 0;

            if (is_on_edge)
            {
                edge = m_edge;
                bottom = bottom_border;
                color = image.CreateColor(m_fg_color);
            }

            is_on_edge = false;
        }
        while (color);

    }
};

/**
 **********************************************************************
 *  Class: cImageTag
 *
 * Author: $author$
 *   Date: 5/19/2004
 **********************************************************************
 */
class cImageTag
: public cImageTab
{
public:
    typedef cImageTab cIs;

    /**
     **********************************************************************
     * Constructor: cImageTag
     *
     *      Author: $author$
     *        Date: 5/19/2004
     **********************************************************************
     */
    cImageTag
    (cImageColor &fg_color, 
     cImageColor &bg_color,
     cImageColor &edge_color,
     int x=0, int y=0, int width=0, int height=0,
     int left_border=0, int right_border=0,
     int top_border=0, int bottom_border=0, 
     int edge=0, int radius=0, bool previous_sibling=false, 
     bool next_sibling=false, int style=e_DEFAULT_STYLE, 
     int state=e_DEFAULT_STATE) 
    : cIs
      (fg_color,bg_color,edge_color,x,y,width,height,
       left_border,right_border,top_border,bottom_border,
       edge,radius,previous_sibling,next_sibling,
       style,state) 
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
        int edge=0;
        int left=0, left_border=m_left_border;
        int right=0, right_border=m_right_border;
        int top=0, top_border=m_top_border;
        int bottom=0, bottom_border=m_bottom_border;
        bool is_on_edge=false;
        cImageInterface *color;

        if (0 >  x)
            x = m_x;

        if (0 > y)
            y = m_y;

        if ((color = image.CreateColor(m_bg_color)))
        {
            color->SetImage();

            image.Fill(x,y,m_width,m_height);
            image.DestroyImage(color);
        }

        if (0 < m_edge)
        {
            is_on_edge = true;
            color = image.CreateColor(m_edge_color);
        }
        else 
        {
            left = left_border;
            right = right_border;
            top = top_border;
            bottom = bottom_border;
            color = image.CreateColor(m_fg_color);
        }

        if (color)
        do
        {
            color->SetImage();

            /* top left radius
             */
            if ((e_STYLE_TOP == m_style) 
                || (e_STYLE_LEFT == m_style) 
                || (e_STYLES == m_style))
            {
                image.FillCircle
                (x+m_left_border+m_radius-1,
                 y+m_top_border+m_radius-1,m_radius-edge);
            }
            else
            {
                image.Fill
                (x+m_left_border+edge, 
                 y+m_top_border+edge,
                 m_radius-edge, m_radius-edge);
            }

            /* bottom left radius
             */
            if ((e_STYLE_BOTTOM == m_style) 
                || (e_STYLE_LEFT == m_style) 
                || (e_STYLES == m_style))
            {
                image.FillCircle
                (x+m_left_border+m_radius-1,
                 y+m_height-m_bottom_border-m_radius,
                 m_radius-edge);
            }
            else
            {
                image.Fill
                (x+m_left_border+edge, 
                 y+m_height-m_bottom_border-m_radius,
                 m_radius-edge, m_radius-edge);
            }

            /* top right radius
             */
            if ((e_STYLE_TOP == m_style) 
                || (e_STYLE_RIGHT == m_style) 
                || (e_STYLES == m_style))
            {
                image.FillCircle
                (x+m_width-m_right_border-m_radius,
                 y+m_top_border+m_radius-1,m_radius-edge);
            }
            else
            {
                image.Fill
                (x+m_width-m_right_border-m_radius,
                 y+m_top_border+edge,
                 m_radius-edge, m_radius-edge);
            }

            /* bottom right radius
             */
            if ((e_STYLE_BOTTOM == m_style) 
                || (e_STYLE_RIGHT == m_style) 
                || (e_STYLES == m_style))
            {
                image.FillCircle
                (x+m_width-m_right_border-m_radius,
                 y+m_height-m_bottom_border-m_radius,
                 m_radius-edge);
            }
            else
            {
                image.Fill
                (x+m_width-m_right_border-m_radius,
                 y+m_height-m_bottom_border-m_radius,
                 m_radius-edge, m_radius-edge);
            }

            image.Fill
            (x+m_left_border+m_radius-1,
             y+m_top_border+edge,
             m_width-m_left_border-m_right_border-m_radius-m_radius+2,
             m_height-m_top_border-m_bottom_border-edge-edge);

            image.Fill
            (x+m_left_border+edge,
             y+m_top_border+m_radius-1,
             m_width-m_left_border-m_right_border-edge-edge,
             m_height-m_top_border-m_bottom_border-m_radius-m_radius+2);

            image.DestroyImage(color);
            color = 0;

            if (is_on_edge)
            {
                edge = m_edge;
                left = left_border;
                right = right_border;
                top = top_border;
                bottom = bottom_border;
                color = image.CreateColor(m_fg_color);
            }

            is_on_edge = false;
        }
        while (color);
    }
};

/**
 **********************************************************************
 *  Class: cImageTabType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cImageTabType
: public cImageObjectType
{
public:
    typedef cImageObjectType cIs;

    /**
     **********************************************************************
     * Constructor: cImageTabType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cImageTabType(const char *name="tab")
    : cIs(name) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateObject
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual cImageObject *CreateObject
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element)
    {
        cImageObject *object = CreateObjectEx
		(error, object_set, object_types, element);
        return object;
	}
    /**
     **********************************************************************
     * Function: CreateObjectEx
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObject *CreateObjectEx
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element,
	 int defaultStyle=cImageTab::e_DEFAULT_STYLE, 
	 int defaultState=cImageTab::e_DEFAULT_STATE)
    {
        static const char *styles[cImageTab::e_STYLES]=
        {
            "top",
            "left",
            "right",
            "bottom"
        };

        static const char *states[cImageTab::e_STATES]=
        {
            "bottom",
            "top"
        };

        error=e_ERROR_NOT_IMPLEMENTED;
        cImageObject *object=0;

        cCharPointerAttributeValue file(element,"file",0);

        cImageColorAttributeValue
            fgcolor(element,"fgcolor",1,1,255,255,255,255),
            bgcolor(element,"bgcolor",1,1,0,0,0,255),
            edgecolor(element,"edgecolor",1,1,0,0,0,255);

        cIntAttributeValue 
            x(element,"x",0),
            y(element,"y",0),
            width(element,"width",100),
            height(element,"height",24),
            edge(element,"edge",0),
            radius(element,"radius",10),
            lborder(element,"lborder",1),
            rborder(element,"rborder",1),
            tborder(element,"tborder",1),
            bborder(element,"bborder",2);

        cBoolAttributeValue
            lsibling(element,"lsibling",false),
            rsibling(element,"rsibling",false);

        cEnumAttributeValue 
         style
         (element,"style",styles,
          cImageTab::e_STYLE_TOP,
          cImageTab::e_STYLE_BOTTOM,
          defaultStyle),
         state
         (element,"state",states,
          cImageTab::e_STATE_BOTTOM,
          cImageTab::e_STATE_TOP,
          defaultState);

        if ((object=NewObject
            (fgcolor,bgcolor,edgecolor,x,y,width,height,
            lborder,rborder,tborder,bborder,edge,radius,
            lsibling,rsibling,style,state)))
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
     cImageColor &edge_color,
     int x=0, int y=0, int width=0, int height=0,
     int left_border=0, int right_border=0,
     int top_border=0, int bottom_border=0, 
     int edge=0, int radius=0, bool previous_sibling=false, 
     bool next_sibling=false, int style=0, 
     int state=0)
    {
        return new cImageTab
        (fg_color,bg_color,edge_color,x,y,width,height,
         left_border,right_border,top_border,bottom_border,edge,radius,
         previous_sibling,next_sibling,style,state);
    }
};

/**
 **********************************************************************
 *  Class: cImageTagType
 *
 * Author: $author$
 *   Date: 5/19/2004
 **********************************************************************
 */
class cImageTagType
: public cImageTabType
{
public:
    typedef cImageTabType cIs;

    /**
     **********************************************************************
     * Constructor: cImageTagType
     *
     *      Author: $author$
     *        Date: 5/19/2004
     **********************************************************************
     */
    cImageTagType(const char *name="tag")
    : cIs(name) 
    {
    }
    /**
     **********************************************************************
     * Function: CreateObject
     *
     *   Author: $author$
     *     Date: 11/12/2008
     **********************************************************************
     */
    virtual cImageObject *CreateObject
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element)
    {
        cImageObject *object = CreateObjectEx
		(error, object_set, object_types, element,
		 cImageTab::e_STYLES);
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
     cImageColor &edge_color,
     int x=0, int y=0, int width=0, int height=0,
     int left_border=0, int right_border=0,
     int top_border=0, int bottom_border=0, 
     int edge=0, int radius=0, bool previous_sibling=false, 
     bool next_sibling=false, int style=0, 
     int state=0)
    {
        return new cImageTag
        (fg_color,bg_color,edge_color,x,y,width,height,
         left_border,right_border,top_border,bottom_border,edge,radius,
         previous_sibling,next_sibling,style,state);
    }
};

/**
 **********************************************************************
 *  Class: cStaticImageTabType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cStaticImageTabType
: public cImageTabType
{
public:
    typedef cImageTabType cIs;

    static cStaticImageTabType m_instance;

    cStaticImageObjectType m_static_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageTabType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cStaticImageTabType()
    : m_static_type(*this) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cStaticImageTagType
 *
 * Author: $author$
 *   Date: 4/1/2004
 **********************************************************************
 */
class cStaticImageTagType
: public cImageTagType
{
public:
    typedef cImageTagType cIs;

    static cStaticImageTagType m_instance;

    cStaticImageObjectType m_static_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageTagType
     *
     *      Author: $author$
     *        Date: 4/1/2004
     **********************************************************************
     */
    cStaticImageTagType()
    : m_static_type(*this) 
    {
    }
};

/**
 **********************************************************************
 *  Class: cImageFilledCircleQuadrant
 *
 * Author: $author$
 *   Date: 4/7/2004
 **********************************************************************
 */
class cImageFilledCircleQuadrant
: public cImageObject
{
public:
    typedef cImageObject cIs;

    int m_quadrant,m_radius;
    cImageColor m_fg_color;
    cImageColor m_bg_color;

    /**
     **********************************************************************
     * Constructor: cImageFilledCircleQuadrant
     *
     *      Author: $author$
     *        Date: 4/7/2004
     **********************************************************************
     */
    cImageFilledCircleQuadrant
    (cImageColor &fg_color, cImageColor &bg_color,
     int quadrant=0, int x=0, int y=0, int radius=0) 
    : cIs(x,y,radius,radius),
      m_fg_color(fg_color),
      m_bg_color(bg_color),
      m_quadrant(quadrant),
      m_radius(radius)
    {
        switch(quadrant)
        {
        case 4:
        case 6:
            m_height += (m_height-1);
            break;
        case 5:
        case 7:
            m_width += (m_width-1);
            break;
        }
    }
    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 4/7/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const
    {
        int cx,cy;
        cImageInterface *color;

        if (0 >  x)
            x = m_x;

        if (0 > y)
            y = m_y;

        switch(m_quadrant)
        {
        case 0:
        case 4:
            cx = x;
            cy = y+m_radius-1;
            break;

        case 1:
        case 7:
            cx = x;
            cy = y;
            break;

        case 2:
        case 5:
            cx = x+m_radius-1;
            cy = y;
            break;

        case 3:
        case 6:
        default:
            cx = x+m_radius-1;
            cy = y+m_radius-1;
            break;
        }

        if ((color = image.CreateColor(m_bg_color)))
        {
            color->SetImage();

            image.Fill(x,y,m_width,m_height);
            image.DestroyImage(color);
        }

        if ((color = image.CreateColor(m_fg_color)))
        {
            color->SetImage();

            image.FillCircle(cx,cy,m_radius,m_quadrant);
            image.DestroyImage(color);
        }
    }
};

/**
 **********************************************************************
 *  Class: cImageFilledCircleQuadrantType
 *
 * Author: $author$
 *   Date: 4/7/2004
 **********************************************************************
 */
class cImageFilledCircleQuadrantType
: public cImageObjectType
{
public:
    typedef cImageObjectType cIs;

    /**
     **********************************************************************
     * Constructor: cImageFilledCircleQuadrantType
     *
     *      Author: $author$
     *        Date: 4/7/2004
     **********************************************************************
     */
    cImageFilledCircleQuadrantType
    (const char *name="filled-circle-quadrant")
    : cIs(name) 
    {
    }

    /**
     **********************************************************************
     * Function: CreateObject
     *
     *   Author: $author$
     *     Date: 4/7/2004
     **********************************************************************
     */
    virtual cImageObject *CreateObject
    (eError &error, cImageObjectSet &object_set, 
     cImageObjectTypes &object_types, cElementInterface &element)
    {
        error=e_ERROR_NONE;
        cImageObject *object=0;

        cCharPointerAttributeValue file(element,"file",0);

        cImageColorAttributeValue 
            bgcolor(element,"bgcolor",1,1,255,255,255,255),
            fgcolor(element,"fgcolor",1,1,0,0,0,255);

        cIntAttributeValue 
            x(element,"x",0),
            y(element,"y",0),
            quadrant(element,"quadrant",0),
            radius(element,"radius",10);

        if ((object=new cImageFilledCircleQuadrant
            (fgcolor,bgcolor,quadrant,x,y,radius)))
        {
            object->SetObjectType(this);

            if (file)
                object->SetFile(file);

            object->SetIsStatic(false);
        }
        return object;
    }
};

/**
 **********************************************************************
 *  Class: cStaticImageFilledCircleQuadrantType
 *
 * Author: $author$
 *   Date: 4/7/2004
 **********************************************************************
 */
class cStaticImageFilledCircleQuadrantType
: public cImageFilledCircleQuadrantType
{
public:
    typedef cImageFilledCircleQuadrantType cIs;

    static cStaticImageFilledCircleQuadrantType m_instance;

    cStaticImageObjectType m_static_type;

    /**
     **********************************************************************
     * Constructor: cStaticImageFilledCircleQuadrantType
     *
     *      Author: $author$
     *        Date: 4/7/2004
     **********************************************************************
     */
    cStaticImageFilledCircleQuadrantType() 
    : m_static_type(*this) 
    {
    }
};

#endif /* ndef _CIMAGE_HXX */
