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
 *   File: cwinimage.hxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */
#ifndef _CWINIMAGE_HXX
#define _CWINIMAGE_HXX

#include "cimage.hxx"
#include "cimageinterface.hxx"
#include "cinstance.hxx"
#include "cwinbrush.hxx"
#include "cwindc.hxx"

/**
 **********************************************************************
 *  Class: cWinImage
 *
 * Author: $author$
 *   Date: 2/29/2004
 **********************************************************************
 */
class cWinImage
: public cImage
{
public:
    typedef cImage cIs;

    cWinDC& m_dc;

    /**
     **********************************************************************
     * Constructor: cWinImage
     *
     *      Author: $author$
     *        Date: 2/29/2004
     **********************************************************************
     */
    cWinImage
    (cWinDC &dc, 
     bool is_dynamic=false, 
     cImageInterface *image=0)
    : cIs(is_dynamic, image),
      m_dc(dc)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cWinImage
     *
     *     Author: $author$
     *       Date: 2/29/2004
     **********************************************************************
     */
    virtual ~cWinImage()
    {
    }

    /**
     **********************************************************************
     * Function: CreateColorImage
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual cImageInterface* CreateColorImage
    (int w, int h, int r, int g, int b, int o=-1);
};

/**
 **********************************************************************
 *  Class: cWinColorImage
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */
class cWinColorImage
: public cWinImage
{
public:
    typedef cWinImage cIs;

    cWinBrush m_brush;
    int m_width, m_height;

    /**
     **********************************************************************
     * Constructor: cWinColorImage
     *
     *      Author: $author$
     *        Date: 1/22/2006
     **********************************************************************
     */
    cWinColorImage
    (cWinDC &dc, bool is_dynamic=false, 
     int w=1, int h=1, int r=-1, int g=-1, int b=-1, int o=-1)
    : cIs(dc, is_dynamic),
      m_width(w),
      m_height(h)
    {
    }

    /**
     **********************************************************************
     * Function: DeleteInstance
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual eError DeleteInstance()
    {
        if (m_is_dynamic)
        {
            delete this;
            return e_ERROR_NONE;
        }
        return e_ERROR_NOT_ALLOWED;
    }

    /**
     **********************************************************************
     * Function: CreateColor
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual eError CreateColor
    (int w, int h, int r, int g, int b, int o=-1)
    {
        eError error;

        if (!(error = m_brush.CreateSolid(r,g,b)))
        {
            m_width = w;
            m_height = h;
            m_is_created = true;
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 1/22/2006
     **********************************************************************
     */
    virtual eError Destroy()
    {
        eError error = e_ERROR_NONE;

        if (!m_is_created)
            return e_ERROR_NOT_CREATED;

        error = m_brush.Destroy();
        m_is_created = false;
        return error;
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
        HBRUSH hbrush = m_brush.GetHandle();

        m_dc.FillRect
        (x, y, x+m_width, y+m_height, hbrush);
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
        HBRUSH hbrush = m_brush.GetHandle();

        m_dc.FillRect
        (x, y, x+w+m_width-1, y+h+m_height-1, hbrush);
    }
};

#endif /* _CWINIMAGE_HXX */
