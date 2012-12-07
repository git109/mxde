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
 *   File: cwinregionimageextend.hxx
 *
 * Author: $author$
 *   Date: 11/28/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGEEXTEND_HXX) || defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGEEXTEND_HXX) && !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY)
#define _CWINREGIONIMAGEEXTEND_HXX
#endif /* !defined(_CWINREGIONIMAGEEXTEND_HXX) && !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY)
#include "cwinregionimagebase.hxx"
#include "cimageextend.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cWinRegionImageExtend;
/**
 **********************************************************************
 * Typedef: cWinRegionImageExtendExtends
 *
 *  Author: $author$
 *    Date: 11/28/2009
 **********************************************************************
 */
typedef cImageExtendT
<cWinRegionImageExtend, 
 cWinRegionImageBase, 
 cWinRegionImageBaseInterface>
cWinRegionImageExtendExtends;
/**
 **********************************************************************
 *  Class: cWinRegionImageExtend
 *
 * Author: $author$
 *   Date: 11/28/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinRegionImageExtend
: public cWinRegionImageExtendExtends
{
public:
    typedef cWinRegionImageExtendExtends cExtends;
    /**
     **********************************************************************
     *  Constructor: cWinRegionImageExtend
     *
     *       Author: $author$
     *         Date: 11/28/2009
     **********************************************************************
     */
    cWinRegionImageExtend
    (HRGN attached=NULL,
     bool isCreated=false)
    : cExtends(*this)
    {
        m_attached = attached;
        m_isCreated = isCreated;
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinRegionImageExtend
     *
     *      Author: $author$
     *        Date: 11/28/2009
     **********************************************************************
     */
    virtual ~cWinRegionImageExtend()
    {
    }
#else /* !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGEEXTEND_HXX) || defined(CWINREGIONIMAGEEXTEND_MEMBERS_ONLY) */
