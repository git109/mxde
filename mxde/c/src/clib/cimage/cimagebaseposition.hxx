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
 *   File: cimagebaseposition.hxx
 *
 * Author: $author$
 *   Date: 7/26/2009
 **********************************************************************
 */
#if !defined(_CIMAGEBASEPOSITION_HXX) || defined(CIMAGEBASEPOSITION_MEMBERS_ONLY)
#if !defined(_CIMAGEBASEPOSITION_HXX) && !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY)
#define _CIMAGEBASEPOSITION_HXX
#endif /* !defined(_CIMAGEBASEPOSITION_HXX) && !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY) */

#if !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY)
#include "cimagebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cImageBasePositionExtends
 *
 *  Author: $author$
 *    Date: 7/26/2009
 **********************************************************************
 */
typedef cImageBase
cImageBasePositionExtends;
/**
 **********************************************************************
 *  Class: cImageBasePosition
 *
 * Author: $author$
 *   Date: 7/26/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageBasePosition
: public cImageBasePositionExtends
{
public:
    typedef cImageBasePositionExtends cExtends;

    tOffset m_x, m_y;
    bool m_isIn;

    /**
     **********************************************************************
     *  Constructor: cImageBasePosition
     *
     *       Author: $author$
     *         Date: 7/26/2009
     **********************************************************************
     */
    cImageBasePosition
    (tOffset x=0, tOffset y=0,
     bool isIn=false)
    : cExtends(*this),
      m_x(x),
      m_y(y),
      m_isIn(isIn)
    {
    }

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 7/26/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y) 
    {
        eError error = e_ERROR_NONE;
        if ((m_x == x) && (m_y == y))
            SetIsIn();
        return error;
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 6/7/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageBaseInterface& pixel,
     tOffset x,tOffset y, tSize w,tSize h) 
    {
        eError error = e_ERROR_NONE;
        if ((m_x >= x) && (m_x < (x+(tOffset)(w))) 
            && (m_y >= y) && (m_y < (y+(tOffset)(h))))
            SetIsIn();
        return error;
    }
#else /* !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetIsIn
     *
     *   Author: $author$
     *     Date: 7/26/2009
     **********************************************************************
     */
    virtual int SetIsIn
    (bool isTrue=true) 
#if defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGEBASEPOSITION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_IMPLEMENT) 
        int isIn = (m_isIn = isTrue);
#else /* !defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_IMPLEMENT) */
        int isTrue = false;
#endif /* !defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_IMPLEMENT) */
        return isIn;
    }
#endif /* defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: IsIn
     *
     *   Author: $author$
     *     Date: 7/26/2009
     **********************************************************************
     */
    virtual bool IsIn() const 
#if defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CIMAGEBASEPOSITION_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_IMPLEMENT) 
        bool isIn = m_isIn;
#else /* !defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_IMPLEMENT) */
        bool isIn = false;
#endif /* !defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_IMPLEMENT) */
        return isIn;
    }
#endif /* defined(CIMAGEBASEPOSITION_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEBASEPOSITION_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEBASEPOSITION_HXX) || defined(CIMAGEBASEPOSITION_MEMBERS_ONLY) */
