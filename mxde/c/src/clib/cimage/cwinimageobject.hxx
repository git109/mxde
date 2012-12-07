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
 *   File: cwinimageobject.hxx
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
#ifndef _CWINIMAGEOBJECT_HXX
#define _CWINIMAGEOBJECT_HXX

#include "cwinimageinterface.hxx"
#include "cimageobject.hxx"
#include "cwinhbrush.hxx"
#include "cwinrect.hxx"

/**
 **********************************************************************
 *  Class: cWinImageObject
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageObject
: public cImageObject
{
public:
    typedef cImageObject cExtends;
    typedef cWinImageObject cDerives;

    cWinImageInterface& m_winImage;

    /**
     **********************************************************************
     * Constructor: cWinImageObject
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cWinImageObject
    (cWinImageInterface& winImage) 
    : cExtends(winImage),
      m_winImage(winImage)
    {
    }
};

/**
 **********************************************************************
 *  Class: cWinImageColor
 *
 * Author: $author$
 *   Date: 5/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinImageColor
: virtual public cWinHBRUSHImplement,
  public cWinImageObject
{
public:
    typedef cWinImageObject cExtends;
    typedef cWinImageColor cDerives;

    tSize m_r, m_g, m_b, m_o;
    tSize m_width, m_height;
    HBRUSH m_attached;
    bool m_isCreated;

    /**
     **********************************************************************
     * Constructor: cWinImageColor
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cWinImageColor
    (cWinImageInterface& winImage,
     tSize r=0, tSize g=0, tSize b=0, tSize o=0,
     tSize width=1, tSize height=1,
     HBRUSH attached=NULL,
     bool isCreated=false) 
    : cExtends(winImage),
      m_r(r), m_g(g), m_b(b), m_o(o),
      m_width(width), m_height(height),
      m_attached(attached),
      m_isCreated(isCreated)
    {
    }
    /**
     **********************************************************************
     * Constructor: cWinImageColor
     *
     *      Author: $author$
     *        Date: 5/28/2009
     **********************************************************************
     */
    cWinImageColor
    (cWinImageInterface& winImage,
     const cWinImageColor& color,
     tOffset rbgOffset=0,
     tOffset oOffset=0,
     HBRUSH attached=NULL,
     bool isCreated=false) 
    : cExtends(winImage),
      m_r(color.m_r+rbgOffset), 
      m_g(color.m_g+rbgOffset), 
      m_b(color.m_b+rbgOffset), 
      m_o(color.m_o+oOffset),
      m_width(color.m_width), 
      m_height(color.m_height),
      m_attached(attached),
      m_isCreated(isCreated)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImageColor
     *
     *     Author: $author$
     *       Date: 5/28/2009
     **********************************************************************
     */
    virtual ~cWinImageColor()
    {
        eError error;
        if ((error = Destroyed()))
            throw(error);
    }

    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h) 
    {
        cWinDCInterface& dc=m_winImage.DC();
        cWinRECT rect(x,y, x+w+m_width-1,y+h+m_height-1);
        eError error = e_ERROR_NONE;
        HDC hDC;
        HBRUSH hBrush;
        if ((hDC = dc.Attached()))
        if ((hBrush = CreatedOrAttached()))
            FillRect(hDC, &rect, hBrush);
        return error;
    }

    /**
     **********************************************************************
     * Function: CreatedOrAttached
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual HBRUSH CreatedOrAttached
    (bool onlyCreated=false) 
    {
        HBRUSH attached;
        eError error;
        if (!(attached = Attached()))
        if (!(error = Created(onlyCreated)))
            attached = Attached();
        return attached;
    }

    /**
     **********************************************************************
     * Function: CreateDestroyed
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual eError CreateDestroyed() 
    {
        eError error = e_ERROR_FAILED;
        COLORREF color = RGB(m_r, m_g, m_b);
        HBRUSH attached, detached;
        if ((detached = CreateDetached(error, color)))
        if (detached != (attached = Attach(detached)))
        {
            error = e_ERROR_ATTACH;
            DestroyDetached(detached);
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: DestroyCreated
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual eError DestroyCreated() 
    {
        eError error = e_ERROR_FAILED;
        HBRUSH detached;
        if ((detached = Detach()))
            error = DestroyDetached(detached);
        return error;
    }

    /**
     **********************************************************************
     * Function: SetIsCreated
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual int SetIsCreated
    (bool is=true) 
    {
        int isCreated = (m_isCreated = is);
        return isCreated;
    }
    /**
     **********************************************************************
     * Function: IsCreated
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual bool IsCreated() const 
    {
        return m_isCreated;
    }

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual HBRUSH Attach
    (HBRUSH attached) 
    {
        m_attached = attached;
        return attached;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual HBRUSH Detach() 
    {
        HBRUSH attached = m_attached;
        m_attached = NULL;
        return attached;
    }
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 5/28/2009
     **********************************************************************
     */
    virtual HBRUSH Attached() const 
    {
        return m_attached;
    }
};
#endif /* _CWINIMAGEOBJECT_HXX */
