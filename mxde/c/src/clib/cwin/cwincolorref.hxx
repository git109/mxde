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
 *   File: cwincolorref.hxx
 *
 * Author: $author$
 *   Date: 5/23/2009
 **********************************************************************
 */
#ifndef _CWINCOLORREF_HXX
#define _CWINCOLORREF_HXX

#include "cattached.hxx"
#include "cwininterfacebase.hxx"
#include "cwinrgb.hxx"
#include "cwinbase.hxx"

#define RED(cref) (cref & 0xFF)
#define GREEN(cref) ((cref >> 8) & 0xFF)
#define BLUE(cref) ((cref >> 16) & 0xFF)

class c_INTERFACE_CLASS cWinCOLORREFInterface;
/**
 **********************************************************************
 * Typedef: cWinCOLORREFInterfaceImplements
 *
 *  Author: $author$
 *    Date: 5/24/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cWinCOLORREFInterface, 
 COLORREF, UINT, 0, cWinInterfaceBase>
cWinCOLORREFInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinCOLORREFInterface
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinCOLORREFInterface
: virtual public cWinCOLORREFInterfaceImplements
{
public:
    typedef cWinCOLORREFInterfaceImplements cImplements;
    typedef cWinCOLORREFInterface cDerives;
};
class c_EXPORT_CLASS cWinCOLORREFImplement;
/**
 **********************************************************************
 * Typedef: cWinCOLORREFImplementImplements
 *
 *  Author: $author$
 *    Date: 5/24/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cWinCOLORREFImplement, 
 cWinCOLORREFInterface, 
 COLORREF, UINT, 0>
cWinCOLORREFImplementImplements;
/**
 **********************************************************************
 *  Class: cWinCOLORREFImplement
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinCOLORREFImplement
: virtual public cWinCOLORREFImplementImplements
{
public:
    typedef cWinCOLORREFImplementImplements cImplements;
    typedef cWinCOLORREFImplement cDerives;
};
class c_EXPORT_CLASS cWinCOLORREF;
/**
 **********************************************************************
 * Typedef: cWinCOLORREFExtends
 *
 *  Author: $author$
 *    Date: 5/24/2009
 **********************************************************************
 */
typedef cAttachedT
<cWinCOLORREF, 
 cWinCOLORREFImplement, 
 cWinCOLORREFInterface,
 COLORREF, UINT, 0, cWinBase>
cWinCOLORREFExtends;
/**
 **********************************************************************
 *  Class: cWinCOLORREF
 *
 * Author: $author$
 *   Date: 5/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinCOLORREF
: public cWinCOLORREFExtends
{
public:
    typedef cWinCOLORREFExtends cExtends;
    typedef cWinCOLORREF cDerives;

    /**
     **********************************************************************
     * Constructor: cWinCOLORREF
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cWinCOLORREF
    (int r, int g, int b) 
    : cExtends(RGB(r, g, b)) 
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinCOLORREF
     *
     *      Author: $author$
     *        Date: 5/24/2009
     **********************************************************************
     */
    cWinCOLORREF
    (tAttachedTo attached=(tAttachedTo)(vUnattached)) 
    : cExtends(attached) 
    {
    }

    /**
     **********************************************************************
     * Function: =
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator =
    (const cWinRED& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = c.m_value;
        int g = GREEN(m_attached);
        int b = BLUE(m_attached);
        m_attached = RGB(r, g, b);
        return color;
    }
    /**
     **********************************************************************
     * Function: +=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator +=
    (const cWinRED& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached) + c.m_value;
        int g = GREEN(m_attached);
        int b = BLUE(m_attached);
        m_attached = RGB(r, g, b);
        return color;
    }
    /**
     **********************************************************************
     * Function: -=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator -=
    (const cWinRED& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached) - c.m_value;
        int g = GREEN(m_attached);
        int b = BLUE(m_attached);
        m_attached = RGB(r, g, b);
        return color;
    }

    /**
     **********************************************************************
     * Function: =
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator =
    (const cWinGREEN& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached);
        int g = c.m_value;
        int b = BLUE(m_attached);
        m_attached = RGB(r, g, b);
        return color;
    }
    /**
     **********************************************************************
     * Function: +=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator +=
    (const cWinGREEN& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached);
        int g = GREEN(m_attached) + c.m_value;
        int b = BLUE(m_attached);
        m_attached = RGB(r, g, b);
        return color;
    }
    /**
     **********************************************************************
     * Function: -=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator -=
    (const cWinGREEN& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached);
        int g = GREEN(m_attached) - c.m_value;
        int b = BLUE(m_attached);
        m_attached = RGB(r, g, b);
        return color;
    }

    /**
     **********************************************************************
     * Function: =
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator =
    (const cWinBLUE& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached);
        int g = GREEN(m_attached);
        int b = c.m_value;
        m_attached = RGB(r, g, b);
        return color;
    }
    /**
     **********************************************************************
     * Function: +=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator +=
    (const cWinBLUE& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached);
        int g = GREEN(m_attached);
        int b = BLUE(m_attached) + c.m_value;
        m_attached = RGB(r, g, b);
        return color;
    }
    /**
     **********************************************************************
     * Function: -=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator -=
    (const cWinBLUE& c) 
    {
        cWinCOLORREF& color = (*this);
        int r = RED(m_attached);
        int g = GREEN(m_attached);
        int b = BLUE(m_attached) - c.m_value;
        m_attached = RGB(r, g, b);
        return color;
    }

    /**
     **********************************************************************
     * Function: =
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator =
    (int value) 
    {
        cWinCOLORREF& color = (*this);
        m_attached = value;
        return color;
    }
    /**
     **********************************************************************
     * Function: +=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator +=
    (int value) 
    {
        cWinCOLORREF& color = (*this);
        m_attached += value;
        return color;
    }
    /**
     **********************************************************************
     * Function: -=
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual cWinCOLORREF& operator -=
    (int value) 
    {
        cWinCOLORREF& color = (*this);
        m_attached -= value;
        return color;
    }

    /**
     **********************************************************************
     * Function: COLORREF
     *
     *   Author: $author$
     *     Date: 5/24/2009
     **********************************************************************
     */
    virtual operator COLORREF() const 
    {
        return m_attached;
    }
};
#endif /* _CWINCOLORREF_HXX */

