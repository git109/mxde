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
 *   File: cwinregionimageinterface.hxx
 *
 * Author: $author$
 *   Date: 11/26/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONIMAGEINTERFACE_HXX) || defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINREGIONIMAGEINTERFACE_HXX) && !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY)
#define _CWINREGIONIMAGEINTERFACE_HXX
#endif /* !defined(_CWINREGIONIMAGEINTERFACE_HXX) && !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY)
#include "cimageinterface.hxx"
#include "cwinregionimagebaseinterface.hxx"
#include "cwinregioninterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRegionImageInterface
 *
 * Author: $author$
 *   Date: 11/26/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinRegionImageInterface
: virtual public cWinRegionImageBaseInterface,
  virtual public cImageInterface
{
public:
    typedef cImageInterface cImplements;
#else /* !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY)
};

#if !defined(CWINREGIONIMAGEIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinRegionImageImplement
 *
 * Author: $author$
 *   Date: 11/26/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinRegionImageImplement
: virtual public cWinRegionImageBaseImplement,
  virtual public cWinRegionImageInterface
{
public:
    typedef cWinRegionImageInterface cImplements;
#else /* !defined(CWINREGIONIMAGEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMAGEIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CWINREGIONIMAGEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONIMAGEINTERFACE_HXX) || defined(CWINREGIONIMAGEINTERFACE_MEMBERS_ONLY) */
