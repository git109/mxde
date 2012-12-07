/**
 **********************************************************************
 * Copyright (c) 1988-2010 $organization$
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
 *   File: cximagecolor.hxx
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXIMAGECOLOR_HXX) || defined(CXIMAGECOLOR_MEMBERS_ONLY)
#if !defined(_CXIMAGECOLOR_HXX) && !defined(CXIMAGECOLOR_MEMBERS_ONLY)
#define _CXIMAGECOLOR_HXX
#endif /* !defined(_CXIMAGECOLOR_HXX) && !defined(CXIMAGECOLOR_MEMBERS_ONLY) */

#if !defined(CXIMAGECOLOR_MEMBERS_ONLY)
#include "cximageobject.hxx"
#include "cxcolor.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXImageColorExtend
 *
 *  Author: $author$
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cXImageObject
cXImageColorExtend;
/**
 **********************************************************************
 *  Class: cXImageColor
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cXImageColor
: /*virtual public cXImageColorImplement,*/
   virtual public cXColorImplement,
   public cXImageColorExtend
{
public:
    /*typedef cXImageColorImplement cImplements;*/
    typedef cXColorImplement cColorImplements;
    typedef cXImageColorExtend cExtends;

    tSize m_r, m_g, m_b;
    tSize m_width, m_height;
    cXColor m_color;

    /**
     **********************************************************************
     *  Constructor: cXImageColor
     *
     *       Author: $author$
     *         Date: 6/9/2010
     **********************************************************************
     */
    cXImageColor
    (cXImageInterface& xImage,
     cXColormapInterface& colormap,
     tSize r=0, tSize g=0, tSize b=0,
     tSize width=1, tSize height=1,
     Pixel attached=0,
     bool isAllocated=false) 
    : cExtends(xImage),
      m_r(r), m_g(g), m_b(b),
      m_width(width), m_height(height),
      m_color
      (xImage.DisplayInterface(), 
       colormap, attached, isAllocated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cXImageColor
     *
     *      Author: $author$
     *        Date: 6/9/2010
     **********************************************************************
     */
    virtual ~cXImageColor()
    {
        eError error;
        if ((error = Freed()))
        {
            DBE(("() throwing error = %d\n", error));
            throw (error);
        }
    }
#else /* !defined(CXIMAGECOLOR_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGECOLOR_MEMBERS_ONLY) */

#if !defined(CXIMAGECOLOR_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError Fill
    (tOffset x,
     tOffset y,
     tSize w,
     tSize h) 
    {
        eError error = e_ERROR_NONE;
        cXGCInterface& gc = m_xImage.GCInterface();
        Pixel pixel = Attached();
        Pixel oldPixel;
        if (!(error = gc.SetForeground(oldPixel, pixel)))
        {
            gc.FillRectangle(x,y, w+m_width-1,h+m_height-1);
            gc.SetForeground(oldPixel);
        }
        return error;
    }

    /**
     **********************************************************************
     * Function: AllocateBYTE
     *
     *   Author: $author$
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError AllocateBYTE
    (bool onlyFreed=false) 
    {
        eError error = AllocateBYTE
        ((BYTE)m_r,(BYTE)m_g,(BYTE)m_b,onlyFreed);
        return error;
    }
    /**
     **********************************************************************
     * Function: AllocateBYTE
     *
     *   Author: $author$
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual eError AllocateBYTE
    (BYTE r, BYTE g, BYTE b,
     bool onlyFreed=false) 
    {
        eError error;
        DBI(("(%d, %d, %d)...\n", r,g,b));
        error = m_color.AllocateBYTE(r,g,b,onlyFreed);
        return error;
    }
    /**
     **********************************************************************
     *  Function: Free
     *
     *    Author: $author$
     *      Date: 6/9/2010
     **********************************************************************
     */
    virtual eError Free
    (bool onlyAllocated = false)
    {
        eError error = m_color.Free(onlyAllocated);
        return error;
    }
    /**
     **********************************************************************
     *  Function: IsAllocated
     *
     *    Author: $author$
     *      Date: 6/9/2010
     **********************************************************************
     */
    virtual bool IsAllocated() const
    {
        bool isTrue = m_color.IsAllocated();
        return isTrue;
    }
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual Pixel Attach
    (Pixel detached,
     bool onlyUnattached=false) 
    {
        Pixel attached = m_color.Attach(detached, onlyUnattached);
        return attached;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual Pixel Detach() 
    {
        Pixel detached = m_color.Detach();
        return detached;
    }
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 6/9/2010
     **********************************************************************
     */
    virtual Pixel Attached() const
    {
        Pixel attached = m_color.Attached();
        return attached;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGECOLOR_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGECOLOR_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGECOLOR_HXX) || defined(CXIMAGECOLOR_MEMBERS_ONLY) */
