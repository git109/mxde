/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
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
 *   File: cimagecolor.hxx
 *
 * Author: $author$
 *   Date: 6/5/2007
 *
 *    $Id$
 **********************************************************************
 */

#ifndef _CIMAGECOLOR_HXX
#define _CIMAGECOLOR_HXX

#include "cimagecolorinterface.hxx"
#include "cattributevalue.hxx"
#include "cdocumentinterface.hxx"
#include "cinstance.hxx"

/**
 **********************************************************************
 *  Class: cImageColor
 *
 * Author: $author$
 *   Date: 3/29/2004
 **********************************************************************
 */
class cImageColor
: virtual public cImageColorImplement,
  public cInstance
{
public:
    typedef cImageColorImplement cImplements;
    typedef cInstance cExtends;

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

    /**
     **********************************************************************
     * Function: GetRed
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetRed() const 
    {
        return m_r;
    }
    /**
     **********************************************************************
     * Function: GetGreen
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetGreen() const 
    {
        return m_g;
    }
    /**
     **********************************************************************
     * Function: GetBlue
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetBlue() const 
    {
        return m_b;
    }
    /**
     **********************************************************************
     * Function: GetOpacity
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual int GetOpacity() const 
    {
        return m_o;
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

#endif /* _CIMAGECOLOR_HXX */
