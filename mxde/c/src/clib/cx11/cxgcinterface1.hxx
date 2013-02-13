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
 *   File: cxgcinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
#if !defined(_CXGCINTERFACE_HXX) || defined(CXGCINTERFACE_MEMBERS_ONLY)
#if !defined(_CXGCINTERFACE_HXX) && !defined(CXGCINTERFACE_MEMBERS_ONLY)
#define _CXGCINTERFACE_HXX
#endif /* !defined(_CXGCINTERFACE_HXX) && !defined(CXGCINTERFACE_MEMBERS_ONLY) */

#if !defined(CXGCINTERFACE_MEMBERS_ONLY)
#include "cxdisplayinterface.hxx"
#include "cxdrawableattached.hxx"
#include "cxregionattached.hxx"
#include "cxgcattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXGCInterface
 *
 * Author: $author$           
 *   Date: 6/29/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXGCInterface
: virtual public cXGCCreatedInterface
{
public:
#else /* !defined(CXGCINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXGCINTERFACE_MEMBERS_ONLY) */

#if !defined(CXGCINTERFACE_MEMBERS_ONLY)
/* include cXGC member functions interface
 */
#define CXGC_MEMBERS_ONLY
#define CXGC_MEMBER_FUNCS_INTERFACE
#include "cxgc.hxx"
#undef CXGC_MEMBER_FUNCS_INTERFACE
#undef CXGC_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cXGCImplement
: virtual public cXGCInterface
{
public:
/* include cXGC member functions implement
 */
#define CXGC_MEMBERS_ONLY
#define CXGC_MEMBER_FUNCS_IMPLEMENT
#include "cxgc.hxx"
#undef CXGC_MEMBER_FUNCS_IMPLEMENT
#undef CXGC_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXGCINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXGCINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXGCINTERFACE_HXX) || defined(CXGCINTERFACE_MEMBERS_ONLY) */
