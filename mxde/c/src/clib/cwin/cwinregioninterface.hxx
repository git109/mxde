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
 *   File: cwinregioninterface.hxx
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
#if !defined(_CWINREGIONINTERFACE_HXX) || defined(CWINREGIONINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINREGIONINTERFACE_HXX) && !defined(CWINREGIONINTERFACE_MEMBERS_ONLY)
#define _CWINREGIONINTERFACE_HXX
#endif /* !defined(_CWINREGIONINTERFACE_HXX) && !defined(CWINREGIONINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINREGIONINTERFACE_MEMBERS_ONLY)
#include "cwinhrgn.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinRegionInterface
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinRegionInterface
: virtual public cWinHRGNInterface
{
public:
    typedef cWinHRGNInterface cImplements;
#else /* !defined(CWINREGIONINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINREGIONINTERFACE_MEMBERS_ONLY)
/* include cWinRegion member functions interface
 */
#define CWINREGION_MEMBERS_ONLY
#define CWINREGION_MEMBER_FUNCS_INTERFACE
#include "cwinregion.hxx"
#undef CWINREGION_MEMBER_FUNCS_INTERFACE
#undef CWINREGION_MEMBERS_ONLY
};

#if !defined(CWINREGIONIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinRegionImplement
 *
 * Author: $author$
 *   Date: 11/23/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinRegionImplement
: virtual public cWinRegionInterface
{
public:
    typedef cWinRegionInterface cImplements;
#else /* !defined(CWINREGIONIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINREGIONIMPLEMENT_MEMBERS_ONLY)
/* include cWinRegion member functions implement
 */
#define CWINREGION_MEMBERS_ONLY
#define CWINREGION_MEMBER_FUNCS_IMPLEMENT
#include "cwinregion.hxx"
#undef CWINREGION_MEMBER_FUNCS_IMPLEMENT
#undef CWINREGION_MEMBERS_ONLY
};
#else /* !defined(CWINREGIONIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINREGIONINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINREGIONINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINREGIONINTERFACE_HXX) || defined(CWINREGIONINTERFACE_MEMBERS_ONLY) */
