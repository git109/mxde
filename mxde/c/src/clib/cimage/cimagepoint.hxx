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
 *   File: cimagepoint.hxx
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
#if !defined(_CIMAGEPOINT_HXX) || defined(CIMAGEPOINT_MEMBERS_ONLY)
#if !defined(_CIMAGEPOINT_HXX) && !defined(CIMAGEPOINT_MEMBERS_ONLY)
#define _CIMAGEPOINT_HXX
#endif /* !defined(_CIMAGEPOINT_HXX) && !defined(CIMAGEPOINT_MEMBERS_ONLY) */

#if !defined(CIMAGEPOINT_MEMBERS_ONLY)
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cImagePoint;

#undef CDB_CLASS
#define CDB_CLASS "cImagePointT"
/**
 **********************************************************************
 *  Class: cImagePointT
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
template
<class TDerives=cImagePoint,
 class TExtend=cExportBase,
 class TInt=INT,
 class TExtends=TExtend>

class c_EXPORT_CLASS cImagePointT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TInt tInt;
    
    tInt m_x, m_y;
    
    /**
     **********************************************************************
     *  Constructor: cImagePointT
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePointT
    (tInt x, tInt y)
    : m_x(x),
      m_y(y)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cImagePointT
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePointT()
    : m_x(0),
      m_y(0)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cImagePointT
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePointT
    (const cImagePointT& point)
    : m_x(point.m_x),
      m_y(point.m_y)
    {
    }
#else /* !defined(CIMAGEPOINT_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPOINT_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/27/2010
     **********************************************************************
     */
    virtual tInt Compare
    (const cImagePointT& toPoint) const 
#if defined(CIMAGEPOINT_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPOINT_MEMBER_FUNCS_INTERFACE) */
    {
        tInt unequal = 0;
#if !defined(CIMAGEPOINT_MEMBER_FUNCS_IMPLEMENT) 
        if (m_y > toPoint.m_y)
            unequal = 1;
        else
        if (m_y < toPoint.m_y)
            unequal = -1;
        else
        if (m_x > toPoint.m_x)
            unequal = 1;
        else
        if (m_x < toPoint.m_x)
            unequal = -1;
#else /* !defined(CIMAGEPOINT_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPOINT_MEMBER_FUNCS_IMPLEMENT) */
        return unequal;
    }
#endif /* defined(CIMAGEPOINT_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEPOINT_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImagePointExtend
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cImagePointT<>
cImagePointExtend;
/**
 **********************************************************************
 *  Class: cImagePoint
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cImagePoint
: public cImagePointExtend
{
public:
    typedef cImagePointExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cImagePoint
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePoint
    (tInt x, tInt y)
    : cExtends(x,y)
    {
    }
    /**
     **********************************************************************
     *  Constructor: cImagePoint
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePoint()
    {
    }
    /**
     **********************************************************************
     *  Constructor: cImagePoint
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePoint
    (const cImagePoint& point)
    {
        m_x = point.m_x;
        m_y = point.m_y;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEPOINT_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPOINT_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEPOINT_HXX) || defined(CIMAGEPOINT_MEMBERS_ONLY) */
