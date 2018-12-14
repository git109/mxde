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
 *   File: cimageinterface.hxx
 *
 * Author: $author$
 *   Date: 2/29/2004
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CIMAGEINTERFACE_HXX
#define _CIMAGEINTERFACE_HXX

#include "cinterface.hxx"
#include "cimplement.hxx"
#include "cattributevalue.hxx"
#include "cdocumentinterface.hxx"

/**
 **********************************************************************
 *  Class: cImageColor
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cImageColor
{
public:
    int m_w,m_h,m_r,m_g,m_b,m_o;

    /**
     **********************************************************************
     * Constructor: cImageColor
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cImageColor
    (int w=0,int h=0,int r=0,int g=0,int b=0,int o=-1)
    : m_w(w),m_h(h),m_r(r),m_g(g),m_b(b),m_o(o)
    {
    }
    /**
     **********************************************************************
     * Constructor: cImageColor
     *
     *      Author: $author$
     *        Date: 3/29/2004
     **********************************************************************
     */
    cImageColor(cImageColor &color) 
    : m_w(color.m_w),m_h(color.m_h),
      m_r(color.m_r),m_g(color.m_g),m_b(color.m_b),m_o(color.m_o)
    {
    }
    /**
     **********************************************************************
     * Function: PutX
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    int PutX(char *text, int size)
    {
        char nibble;
        int i,j,n,rgb[3];

        if (0 >= size)
            return -e_ERROR_INVALID_PARAMETER_SIZE;

        rgb[0] = m_r;
        rgb[1] = m_g;
        rgb[2] = m_b;
        j = n = 0;

        for (i=0; i<size; i++)
        {
            if (0 < (nibble = DtoX((rgb[j]>>4) & 15)))
            {
                text[i] = nibble;

                if (1 < ++n)
                {
                    n = 0;

                    if (2 < ++j)
                    {
                        if (++i < size)
                            text[i]=0;
                        break;
                    }
                }
                else rgb[j] <<= 4;
            }
        }
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetX
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    int GetX(const char *text, int length=-1)
    {
        char c,nibble;
        int i,j,n,*rgb[3];

        if (0 > length)
            length = strlen(text);

        if (0 < length)
        {
            rgb[0] = &m_r;
            rgb[1] = &m_g;
            rgb[2] = &m_b;
            j = n = 0;
            m_r = m_g = m_b = 0;

            for (i=0; i<length; i++)
            {
                if (0 <= (nibble = XtoD(c=text[i])))
                {
                    *(rgb[j]) = (*(rgb[j]) << 4) | nibble;

                    if (1 < ++n)
                    {
                        n = 0;

                        if (2 < ++j)
                            break;
                    }
                }
            }
        }

        return length;
    }
    /**
     **********************************************************************
     * Function: XtoD
     *
     *   Author: $author$
     *     Date: 4/1/2004
     **********************************************************************
     */
    char XtoD(char c)
    {
        if (('0' <= c) && ('9' >= c))
            return c - '0';

        if (('a' <= c) && ('f' >= c))
            return c - 'a' + 10;

        if (('A' <= c) && ('F' >= c))
            return c - 'A' + 10;

        return -1;
    }
    /**
     **********************************************************************
     * Function: DtoX
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    char DtoX(char c)
    {
        if ((0 <= c) && (9 >= c))
            return c + '0';

        if ((10 <= c) && (15 >= c))
            return c - 10 + 'a';

        return -1;
    }
};

/**
 **********************************************************************
 *  Class: cImageColorProperty
 *
 * Author: $author$
 *   Date: 4/14/2004
 **********************************************************************
 */
class cImageColorProperty
: public cProperty
{
public:
    typedef cProperty cIs;

    cImageColor &m_value;
    mutable cCharBuffer m_value_buffer;

    /**
     **********************************************************************
     * Constructor: cImageColorProperty
     *
     *      Author: $author$
     *        Date: 4/14/2004
     **********************************************************************
     */
    cImageColorProperty
    (cImageColor &value, const char *name=0, int length=-1) 
    : cIs(name, length),
      m_value(value) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cImageColorProperty
     *
     *      Author: $author$
     *        Date: 4/14/2004
     **********************************************************************
     */
    cImageColorProperty
    (cPropertyList &list, cImageColor &value, const char *name=0, int length=-1) 
    : cIs(list, name, length),
      m_value(value) 
    {
    }

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual int SetValue(const char *buffer, int length=-1)
    {
        length = m_value.GetX(buffer, length);
        return length;
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 4/14/2004
     **********************************************************************
     */
    virtual const char *GetValue(int &length) const
    {
        int size;
        char *buffer=0;

        if ((buffer = m_value_buffer.GetWriteBuffer(size,length)))
            length = m_value.PutX(buffer,size);
        return buffer;
    }
};

/**
 **********************************************************************
 *  Class: cImageColorAttributeValue
 *
 * Author: $author$
 *   Date: 4/9/2004
 **********************************************************************
 */
class cImageColorAttributeValue
: public cAttributeValue
{
public:
    typedef cAttributeValue cIs;

    cImageColor m_value;

    /**
     **********************************************************************
     * Constructor: cImageColorAttributeValue
     *
     *      Author: $author$
     *        Date: 4/9/2004
     **********************************************************************
     */
    cImageColorAttributeValue 
    (cElementInterface &element, 
     const char *name, int w, int h, int r, int g, int b, int o)
    : cIs(element, name),
      m_value(w,h,r,g,b,o)
    {
        const char *text;
        int textlen;

        if (m_attribute)
        if ((text = m_attribute->GetText(textlen)))
        if (0 < textlen)
            m_value.GetX(text, textlen);
    }

    /**
     **********************************************************************
     * Operator: cImageColor &
     *
     *   Author: $author$
     *     Date: 4/9/2004
     **********************************************************************
     */
    inline operator cImageColor &()
    {
        return m_value;
    }
};

/**
 **********************************************************************
 *  Class: cImageInterface
 *
 * Author: $author$
 *   Date: 2/29/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageInterface
: virtual public cInterface
{
public:
    /**
     **********************************************************************
     * Function: CreateColor
     *
     *   Author: $author$
     *     Date: 3/29/2004
     **********************************************************************
     */
    cImageInterface *CreateColor(const cImageColor &color)
    {
        cImageInterface *im=CreateColor
        (color.m_w,color.m_h, 
         color.m_r,color.m_g,color.m_b,color.m_o);
        return im;
    }
    /**
     **********************************************************************
     * Function: CreateColor
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColor
    (int w, int h, int r, int g, int b, int o=-1)=0;
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
    virtual eError DestroyImage(cImageInterface *image)=0;

    /**
     **********************************************************************
     * Function: SetImage
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *SetImage()=0;
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
    virtual void Plot(int x, int y, int w, int h)=0;
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
: virtual public cImageInterface,
  virtual public cImplement
{
public:
    /**
     **********************************************************************
     * Function: CreateColor
     *
     *   Author: $author$
     *     Date: 2/29/2004
     **********************************************************************
     */
    virtual cImageInterface *CreateColor
    (int w, int h, int r, int g, int b, int o=-1)
    {
        cImageInterface *color=0;
        return color;
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
    virtual eError DestroyImage(cImageInterface *image)
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
    virtual cImageInterface *SetImage()
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
    virtual void Plot(int x, int y, int w, int h)
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

class c_INTERFACE_CLASS cImageObjectInterface;

/**
 **********************************************************************
 *  Class: cImageObjectSetInterface
 *
 * Author: $author$
 *   Date: 3/31/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectSetInterface
: virtual public cInterface
{
public:
    typedef cInterface cIs;

    /**
     **********************************************************************
     * Function: AddObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *AddObject
    (eError &error,cElementInterface &element)=0;
    /**
     **********************************************************************
     * Function: DeleteObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual eError DeleteObject(cImageObjectInterface &object)=0;

    /**
     **********************************************************************
     * Function: GetFirstObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetFirstObject() const=0;
    /**
     **********************************************************************
     * Function: GetLastObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetLastObject() const=0;
};

class c_INTERFACE_CLASS cImageObjectTypeInterface;

/**
 **********************************************************************
 *  Class: cImageObjectInterface
 *
 * Author: $author$
 *   Date: 3/27/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectInterface
: virtual public cImageObjectSetInterface
{
public:
    /**
     **********************************************************************
     * Function: GetObjectType
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual cImageObjectTypeInterface *GetObjectType() const=0;
    /**
     **********************************************************************
     * Function: GetNextObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetNextObject() const=0;
    /**
     **********************************************************************
     * Function: GetPreviousObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *GetPreviousObject() const=0;
    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 3/27/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const=0;
};

/**
 **********************************************************************
 *  Class: cImageObjectTypeInterface
 *
 * Author: $author$
 *   Date: 5/14/2004
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectTypeInterface
{
public:
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 5/14/2004
     **********************************************************************
     */
    virtual const char *GetName() const = 0;
};

/**
 **********************************************************************
 *  Class: cImageObjectSetImplement
 *
 * Author: $author$
 *   Date: 3/31/2004
 **********************************************************************
 */
class cImageObjectSetImplement
: virtual public cImageObjectSetInterface
{
public:
    /**
     **********************************************************************
     * Function: AddObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual cImageObjectInterface *AddObject
    (eError &error,cElementInterface &element)
    {
        cImageObjectInterface *object=0;
        error=e_ERROR_NOT_IMPLEMENTED;
        return object;
    }
    /**
     **********************************************************************
     * Function: DeleteObject
     *
     *   Author: $author$
     *     Date: 3/31/2004
     **********************************************************************
     */
    virtual eError DeleteObject(cImageObjectInterface &object)
    {
        eError error=e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

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
        return 0;
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
        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cImageObjectImplement
 *
 * Author: $author$
 *   Date: 3/27/2004
 **********************************************************************
 */
class cImageObjectImplement
: virtual public cImageObjectInterface,
  virtual public cImageObjectSetImplement
{
public:
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
        return 0;
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
        return 0;
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
        return 0;
    }

    /**
     **********************************************************************
     * Function: SetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int SetState(int state)=0;
    /**
     **********************************************************************
     * Function: GetState
     *
     *   Author: $author$
     *     Date: 3/28/2004
     **********************************************************************
     */
    virtual int GetState() const=0;

    /**
     **********************************************************************
     * Function: Paint
     *
     *   Author: $author$
     *     Date: 3/27/2004
     **********************************************************************
     */
    virtual void Paint
    (cImageInterface &image,
     int x=-1, int y=-1, int state=-1) const
    {
    }
};

#endif /* ndef _CIMAGEINTERFACE_HXX */
