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
 *   File: cimagereaderitem.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CIMAGEREADERITEM_HXX) || defined(CIMAGEREADERITEM_MEMBERS_ONLY)
#if !defined(_CIMAGEREADERITEM_HXX) && !defined(CIMAGEREADERITEM_MEMBERS_ONLY)
#define _CIMAGEREADERITEM_HXX
#endif /* !defined(_CIMAGEREADERITEM_HXX) && !defined(CIMAGEREADERITEM_MEMBERS_ONLY) */

#if !defined(CIMAGEREADERITEM_MEMBERS_ONLY)
#include "cimagereaderinterface.hxx"
#include "clistitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cImageReaderItem;
/**
 **********************************************************************
 * Typedef: cImageReaderItemExtend
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cListItemT
<cImageReaderItem, cInstanceBase>
cImageReaderItemExtend;
/**
 **********************************************************************
 *  Class: cImageReaderItem
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cImageReaderItem
: //virtual public cImageReaderItemImplement,
  public cImageReaderItemExtend
{
public:
    //typedef cImageReaderItemImplement cImplements;
    typedef cImageReaderItemExtend cExtends;
    
    cImageReaderInterface& m_imageReader;
    
    /**
     **********************************************************************
     *  Constructor: cImageReaderItem
     *
     *       Author: $author$
     *         Date: 11/12/2010
     **********************************************************************
     */
    cImageReaderItem
    (cImageReaderInterface& imageReader)
    : m_imageReader(imageReader)
    {
    }
#else /* !defined(CIMAGEREADERITEM_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADERITEM_MEMBERS_ONLY) */

#if !defined(CIMAGEREADERITEM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEREADERITEM_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADERITEM_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEREADERITEM_HXX) || defined(CIMAGEREADERITEM_MEMBERS_ONLY) */
