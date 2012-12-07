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
 *   File: cimagepointarray.hxx
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
#if !defined(_CIMAGEPOINTARRAY_HXX) || defined(CIMAGEPOINTARRAY_MEMBERS_ONLY)
#if !defined(_CIMAGEPOINTARRAY_HXX) && !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY)
#define _CIMAGEPOINTARRAY_HXX
#endif /* !defined(_CIMAGEPOINTARRAY_HXX) && !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */

#if !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY)
#include "cimagepoint.hxx"
#include "carray.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cImagePointArrayInterface;
/**
 **********************************************************************
 * Typedef: cImagePointArrayInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayInterfaceT
<cImagePointArrayInterface, cImagePoint>
cImagePointArrayInterfaceImplement;
/**
 **********************************************************************
 *  Class: cImagePointArrayInterface
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cImagePointArrayInterface
: virtual public cImagePointArrayInterfaceImplement
{
public:
    typedef cImagePointArrayInterfaceImplement cImplements;
};
class c_IMPLEMENT_CLASS cImagePointArrayImplement;
/**
 **********************************************************************
 * Typedef: cImagePointArrayImplementImplement
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayImplementT
<cImagePointArrayImplement, 
 cImagePointArrayInterface,
 cImagePoint>
cImagePointArrayImplementImplement;
/**
 **********************************************************************
 *  Class: cImagePointArrayImplement
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImagePointArrayImplement
: virtual public cImagePointArrayImplementImplement
{
public:
    typedef cImagePointArrayImplementImplement cImplements;
};
class c_EXPORT_CLASS cImagePointArray;
/**
 **********************************************************************
 * Typedef: cImagePointArrayExtend
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayT
<cImagePointArray,
 cImagePointArrayImplement,
 cImagePointArrayInterface,
 cImagePoint>
cImagePointArrayExtend;
/**
 **********************************************************************
 *  Class: cImagePointArray
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cImagePointArray
: public cImagePointArrayExtend
{
public:
    typedef cImagePointArrayExtend cExtends;
#else /* !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Points
     *
     *   Author: $author$
     *     Date: 1/28/2010
     **********************************************************************
     */
    virtual tWhat* Points
    (tLength& pointsSize, tLength& pointsLength) const 
#if defined(CIMAGEPOINTARRAY_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPOINTARRAY_MEMBER_FUNCS_INTERFACE) */
    {
        tWhat* points = Elements(pointsSize, pointsLength);
#if !defined(CIMAGEPOINTARRAY_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CIMAGEPOINTARRAY_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPOINTARRAY_MEMBER_FUNCS_IMPLEMENT) */
        return points;
    }
#endif /* defined(CIMAGEPOINTARRAY_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY)
};

class c_EXPORT_CLASS cImagePointTriangle;
/**
 **********************************************************************
 * Typedef: cImagePointTriangleExtend
 *
 *  Author: $author$
 *    Date: 1/27/2010
 **********************************************************************
 */
typedef cArrayT
<cImagePointTriangle,
 cImagePointArrayImplement,
 cImagePointArrayInterface,
 cImagePoint, 3>
cImagePointTriangleExtend;
/**
 **********************************************************************
 *  Class: cImagePointTriangle
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cImagePointTriangle
: public cImagePointTriangleExtend
{
public:
    typedef cImagePointArrayExtend cExtends;
    typedef cImagePoint::tInt tInt;
    
    /**
     **********************************************************************
     *  Constructor: cImagePointTriangle
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cImagePointTriangle
    (tInt x1,tInt y1, 
     tInt x2,tInt y2, 
     tInt x3,tInt y3)
    {
        m_defaultElements[0].m_x = x1;
        m_defaultElements[0].m_y = y1;
        m_defaultElements[1].m_x = x2;
        m_defaultElements[1].m_y = y2;
        m_defaultElements[2].m_x = x3;
        m_defaultElements[2].m_y = y3;
        m_elementsLength = 3;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 1/28/2010
     **********************************************************************
     */
    virtual int Compare
    (tSize iFirst, tSize iLast) const
    {
        int unequal = 0;
        if ((iFirst >= 0) && (iLast <= 2))
            unequal = m_defaultElements[iFirst].Compare
            (m_defaultElements[iLast]);
        return unequal;
    }
};
/**
 **********************************************************************
 *  Class: cSortedImagePointTriangle
 *
 * Author: $author$
 *   Date: 1/27/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cSortedImagePointTriangle
: public cImagePointTriangle
{
public:
    typedef cImagePointTriangle cExtends;
    /**
     **********************************************************************
     *  Constructor: cSortedImagePointTriangle
     *
     *       Author: $author$
     *         Date: 1/27/2010
     **********************************************************************
     */
    cSortedImagePointTriangle
    (tInt x1,tInt y1,
     tInt x2,tInt y2,
     tInt x3,tInt y3)
    : cExtends(x1,y1, x2,y2, x3,y3)
    {
        QSort();
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEPOINTARRAY_HXX) || defined(CIMAGEPOINTARRAY_MEMBERS_ONLY) */
