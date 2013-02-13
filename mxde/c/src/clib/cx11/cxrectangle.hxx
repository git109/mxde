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
 *   File: cxrectangle.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXRECTANGLE_HXX) || defined(CXRECTANGLE_MEMBERS_ONLY)
#if !defined(_CXRECTANGLE_HXX) && !defined(CXRECTANGLE_MEMBERS_ONLY)
#define _CXRECTANGLE_HXX
#endif /* !defined(_CXRECTANGLE_HXX) && !defined(CXRECTANGLE_MEMBERS_ONLY) */

#if !defined(CXRECTANGLE_MEMBERS_ONLY)
#include "cxbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXRectangle
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class cXRectangle
: public XRectangle
{
public:
    typedef XRectangle cExtends;
    /**
     **********************************************************************
     *  Constructor: cXRectangle
     *
     *       Author: $author$           
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXRectangle
    (short p_x=0, short p_y=0, 
     unsigned short p_width=0, unsigned short p_height=0)
    {
        x = p_x;
        y = p_y;
        width = p_width;
        height = p_height;
    }
    /**
     **********************************************************************
     *  Constructor: cXRectangle
     *
     *       Author: $author$           
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXRectangle
    (const XExposeEvent& xEvent)
    {
        x = xEvent.x;
        y = xEvent.y;
        width = xEvent.width;
        height = xEvent.height;
    }
    /**
     **********************************************************************
     *  Constructor: cXRectangle
     *
     *       Author: $author$           
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXRectangle
    (const cXRectangle& rectangle)
    {
        Set(rectangle);
    }
    /**
     **********************************************************************
     *  Constructor: cXRectangle
     *
     *       Author: $author$           
     *         Date: 7/5/2009
     **********************************************************************
     */
    cXRectangle
    (const XRectangle& xRectangle)
    {
        Set(xRectangle);
    }
#else /* !defined(CXRECTANGLE_MEMBERS_ONLY) */
#endif /* !defined(CXRECTANGLE_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$           
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual void Set
    (const XRectangle& xRectangle) 
#if defined(CXRECTANGLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXRECTANGLE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXRECTANGLE_MEMBER_FUNCS_IMPLEMENT) 
        x = xRectangle.x;
        y = xRectangle.y;
        width = xRectangle.width;
        height = xRectangle.height;
#else /* !defined(CXRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CXRECTANGLE_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Include
     *
     *   Author: $author$           
     *     Date: 7/5/2009
     **********************************************************************
     */
    virtual void Include
    (const XRectangle& xRectangle) 
#if defined(CXRECTANGLE_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CXRECTANGLE_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CXRECTANGLE_MEMBER_FUNCS_IMPLEMENT) 
        int x2,y2,z;

        if ((x2 = x+width) < (z = xRectangle.x+xRectangle.width))
          x2=z;

        if ((y2 = y+height) < (z = xRectangle.y+xRectangle.height))
          y2=z;

        if (x>xRectangle.x)
          x = xRectangle.x;

        if (y>xRectangle.y)
          y = xRectangle.y;

        width = x2-x;
        height = y2-y;
#else /* !defined(CXRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CXRECTANGLE_MEMBER_FUNCS_IMPLEMENT) */
    }
#endif /* defined(CXRECTANGLE_MEMBER_FUNCS_INTERFACE) */

#if !defined(CXRECTANGLE_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXRECTANGLE_MEMBERS_ONLY) */
#endif /* !defined(CXRECTANGLE_MEMBERS_ONLY) */

#endif /* !defined(_CXRECTANGLE_HXX) || defined(CXRECTANGLE_MEMBERS_ONLY) */
