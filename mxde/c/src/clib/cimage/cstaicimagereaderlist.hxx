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
 *   File: cstaicimagereaderlist.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CSTAICIMAGEREADERLIST_HXX) || defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY)
#if !defined(_CSTAICIMAGEREADERLIST_HXX) && !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY)
#define _CSTAICIMAGEREADERLIST_HXX
#endif /* !defined(_CSTAICIMAGEREADERLIST_HXX) && !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY) */

#if !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY)
#include "cimagereaderitem.hxx"
#include "clist.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class cStaicImageReaderList;
/**
 **********************************************************************
 * Typedef: cStaicImageReaderListExtend
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cStaticListT
<cStaicImageReaderList, 
 cImageReaderItem, 
 cInstanceBase>
cStaicImageReaderListExtend;
/**
 **********************************************************************
 *  Class: cStaicImageReaderList
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
class cStaicImageReaderList
: //virtual public cStaicImageReaderListImplement,
  public cStaicImageReaderListExtend
{
public:
    //typedef cStaicImageReaderListImplement cImplements;
    typedef cStaicImageReaderListExtend cExtends;
    static cStaicImageReaderList m_instance;
#else /* !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY) */
#endif /* !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY) */

#if !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY) */
#endif /* !defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY) */

#endif /* !defined(_CSTAICIMAGEREADERLIST_HXX) || defined(CSTAICIMAGEREADERLIST_MEMBERS_ONLY) */
