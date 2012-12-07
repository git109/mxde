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
 *   File: cstaicimagereaderitem.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CSTAICIMAGEREADERITEM_HXX) || defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY)
#if !defined(_CSTAICIMAGEREADERITEM_HXX) && !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY)
#define _CSTAICIMAGEREADERITEM_HXX
#endif /* !defined(_CSTAICIMAGEREADERITEM_HXX) && !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY) */

#if !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY)
#include "cstaicimagereaderlist.hxx"
#include "cimagereaderitem.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cStaicImageReaderItemT
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
template
<class TImageReader,
 class TImageReaderItem=cImageReaderItem,
 class TExtends=cInstanceBase>
class c_INSTANCE_CLASS cStaicImageReaderItemT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef TImageReader tImageReader;
    typedef TImageReaderItem tImageReaderItem;
    
    tImageReader m_imageReader;
    tImageReaderItem m_imageReaderItem;
    
    /**
     **********************************************************************
     *  Constructor: cStaicImageReaderItemT
     *
     *       Author: $author$
     *         Date: 11/12/2010
     **********************************************************************
     */
    cStaicImageReaderItemT()
    : m_imageReaderItem(m_imageReader)
    {
        cStaicImageReaderList::m_instance.AddItem(m_imageReaderItem);
    }
    /**
     **********************************************************************
     *  Destructor: ~cStaicImageReaderItemT
     *
     *      Author: $author$
     *        Date: 11/12/2010
     **********************************************************************
     */
    virtual ~cStaicImageReaderItemT()
    {
        cStaicImageReaderList::m_instance.DeleteItem(m_imageReaderItem);
    }
#else /* !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY) */
#endif /* !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY) */

#if !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY) */
#endif /* !defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY) */

#endif /* !defined(_CSTAICIMAGEREADERITEM_HXX) || defined(CSTAICIMAGEREADERITEM_MEMBERS_ONLY) */
