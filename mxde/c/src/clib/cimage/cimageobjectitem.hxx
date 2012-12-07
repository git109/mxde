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
 *   File: cimageobjectitem.hxx
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
#if !defined(_CIMAGEOBJECTITEM_HXX) || defined(CIMAGEOBJECTITEM_MEMBERS_ONLY)
#if !defined(_CIMAGEOBJECTITEM_HXX) && !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY)
#define _CIMAGEOBJECTITEM_HXX
#endif /* !defined(_CIMAGEOBJECTITEM_HXX) && !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY) */

#if !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY)
#include "cimageobjectinterface.hxx"
#include "clist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cImageObjectItem;
/**
 **********************************************************************
 * Typedef: cImageObjectItemExtends
 *
 *  Author: $author$
 *    Date: 7/16/2009
 **********************************************************************
 */
typedef cListItemT<cImageObjectItem>
cImageObjectItemExtends;
/**
 **********************************************************************
 *  Class: cImageObjectItem
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cImageObjectItem
: public cImageObjectItemExtends
{
public:
    typedef cImageObjectItemExtends cExtends;

    cImageObjectInterface& m_imageObject;

    /**
     **********************************************************************
     *  Constructor: cImageObjectItem
     *
     *       Author: $author$
     *         Date: 7/16/2009
     **********************************************************************
     */
    cImageObjectItem
    (cImageObjectInterface& imageObject)
    : m_imageObject(imageObject)
    {
    }
#else /* !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY) */

#if !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECTITEM_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEOBJECTITEM_HXX) || defined(CIMAGEOBJECTITEM_MEMBERS_ONLY) */
