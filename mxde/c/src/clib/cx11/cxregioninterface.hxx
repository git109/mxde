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
 *   File: cxregioninterface.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXREGIONINTERFACE_HXX) || defined(CXREGIONINTERFACE_MEMBERS_ONLY)
#if !defined(_CXREGIONINTERFACE_HXX) && !defined(CXREGIONINTERFACE_MEMBERS_ONLY)
#define _CXREGIONINTERFACE_HXX
#endif /* !defined(_CXREGIONINTERFACE_HXX) && !defined(CXREGIONINTERFACE_MEMBERS_ONLY) */

#if !defined(CXREGIONINTERFACE_MEMBERS_ONLY)
#include "cxregionattached.hxx"
#include "cxdisplayinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXRegionInterface
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXRegionInterface
: virtual public cXRegionCreatedInterface
{
public:
    typedef cXRegionCreatedInterface cImplements;
#else /* !defined(CXREGIONINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXREGIONINTERFACE_MEMBERS_ONLY) */

#if !defined(CXREGIONINTERFACE_MEMBERS_ONLY)
/* include cXRegion member functions interface
 */
#define CXREGION_MEMBERS_ONLY
#define CXREGION_MEMBER_FUNCS_INTERFACE
#include "cxregion.hxx"
#undef CXREGION_MEMBER_FUNCS_INTERFACE
#undef CXREGION_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cXRegionImplement
: virtual public cXRegionInterface
{
public:
/* include cXRegion member functions implement
 */
#define CXREGION_MEMBERS_ONLY
#define CXREGION_MEMBER_FUNCS_IMPLEMENT
#include "cxregion.hxx"
#undef CXREGION_MEMBER_FUNCS_IMPLEMENT
#undef CXREGION_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXREGIONINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXREGIONINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXREGIONINTERFACE_HXX) || defined(CXREGIONINTERFACE_MEMBERS_ONLY) */
