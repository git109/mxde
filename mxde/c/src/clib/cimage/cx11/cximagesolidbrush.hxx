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
 *   File: cximagesolidbrush.hxx
 *
 * Author: $author$
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXIMAGESOLIDBRUSH_HXX) || defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY)
#if !defined(_CXIMAGESOLIDBRUSH_HXX) && !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY)
#define _CXIMAGESOLIDBRUSH_HXX
#endif /* !defined(_CXIMAGESOLIDBRUSH_HXX) && !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY) */

#if !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY)
#include "cximagebaseinterface.hxx"
#include "cxpixelattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXImageSolidBrush
 *
 * Author: $author$
 *   Date: 7/5/2009
 **********************************************************************
 */
class cXImageSolidBrush
: virtual public cImageBaseImplement,
  public cXPixelAttached
{
public:
    typedef cImageBaseImplement cImplements;
    typedef cXPixelAttached cExtends;

    cXImageBaseInterface& m_xImage;
    tSize m_width, m_height;

    /**
     **********************************************************************
     *  Constructor: cXImageSolidBrush
     *
     *       Author: $author$
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXImageSolidBrush
    (cXImageBaseInterface& xImage,
     Pixel attached=0,
     tSize width=1,
     tSize height=1)
    : cExtends(attached),
      m_xImage(xImage),
      m_width(width),
      m_height(height)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXImageSolidBrush
     *
     *       Author: $author$
     *         Date: 5/27/2010
     **********************************************************************
     */
    cXImageSolidBrush
    (const cXImageSolidBrush& brush,
     tSize width,
     tSize height)
    : cExtends(brush.m_attached),
      m_xImage(brush.m_xImage),
      m_width(width),
      m_height(height)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXImageSolidBrush
     *
     *       Author: $author$
     *         Date: 5/27/2010
     **********************************************************************
     */
    cXImageSolidBrush
    (const cXImageSolidBrush& brush,
     tSize width)
    : cExtends(brush.m_attached),
      m_xImage(brush.m_xImage),
      m_width(width),
      m_height(width)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cXImageSolidBrush
     *
     *       Author: $author$
     *         Date: 5/27/2010
     **********************************************************************
     */
    cXImageSolidBrush
    (const cXImageSolidBrush& brush)
    : cExtends(brush.m_attached),
      m_xImage(brush.m_xImage),
      m_width(brush.m_width),
      m_height(brush.m_height)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXImageSolidBrush
     *
     *      Author: $author$
     *        Date: 7/5/2009
     **********************************************************************
     */
    virtual ~cXImageSolidBrush()
    {
    }
#else /* !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageBaseInterface& image,
     tOffset x, tOffset y) 
#if defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXIMAGESOLIDBRUSH_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_IMPLEMENT) 
        cXGCInterface& gc = m_xImage.GCInterface();
        Pixel pixel = Attached();
        Pixel oldPixel;
        if (!(error = gc.SetForeground(oldPixel, pixel)))
        {
            gc.FillRectangle(x,y, m_width,m_height);
            gc.SetForeground(oldPixel);
        }
#else /* !defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageBaseInterface& image,
     tOffset x, tOffset y, tSize w, tSize h) 
#if defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXIMAGESOLIDBRUSH_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
#if !defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_IMPLEMENT) 
        cXGCInterface& gc = m_xImage.GCInterface();
        Pixel pixel = Attached();
        Pixel oldPixel;
        if (!(error = gc.SetForeground(oldPixel, pixel)))
        {
            gc.FillRectangle(x,y, m_width*w,m_height*h);
            gc.SetForeground(oldPixel);
        }
#else /* !defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CXIMAGESOLIDBRUSH_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGESOLIDBRUSH_HXX) || defined(CXIMAGESOLIDBRUSH_MEMBERS_ONLY) */
