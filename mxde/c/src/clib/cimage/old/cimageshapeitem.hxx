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
 *   File: cimageshapeitem.hxx
 *
 * Author: $author$
 *   Date: 8/6/2009
 **********************************************************************
 */
#if !defined(_CIMAGESHAPEITEM_HXX) || defined(CIMAGESHAPEITEM_MEMBERS_ONLY)
#if !defined(_CIMAGESHAPEITEM_HXX) && !defined(CIMAGESHAPEITEM_MEMBERS_ONLY)
#define _CIMAGESHAPEITEM_HXX
#endif /* !defined(_CIMAGESHAPEITEM_HXX) && !defined(CIMAGESHAPEITEM_MEMBERS_ONLY) */

#if !defined(CIMAGESHAPEITEM_MEMBERS_ONLY)
#include "cimageshapeinterface.hxx"
#include "clist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cImageShapeItem;
/**
 **********************************************************************
 * Typedef: cImageShapeItemExtends
 *
 *  Author: $author$
 *    Date: 8/6/2009
 **********************************************************************
 */
typedef cListItemT<cImageShapeItem>
cImageShapeItemExtends;
/**
 **********************************************************************
 *  Class: cImageShapeItem
 *
 * Author: $author$
 *   Date: 8/6/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageShapeItem
: public cImageShapeItemExtends
{
public:
    typedef cImageShapeItemExtends cExtends;
    
    cImageShapeInterface& m_imageShape;
    
    /**
     **********************************************************************
     *  Constructor: cImageShapeItem
     *
     *       Author: $author$
     *         Date: 8/6/2009
     **********************************************************************
     */
    cImageShapeItem
    (cImageShapeInterface& imageShape)
    : m_imageShape(imageShape)
    {
    }
#else /* !defined(CIMAGESHAPEITEM_MEMBERS_ONLY) */
#endif /* !defined(CIMAGESHAPEITEM_MEMBERS_ONLY) */

#if !defined(CIMAGESHAPEITEM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGESHAPEITEM_MEMBERS_ONLY) */
#endif /* !defined(CIMAGESHAPEITEM_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGESHAPEITEM_HXX) || defined(CIMAGESHAPEITEM_MEMBERS_ONLY) */
