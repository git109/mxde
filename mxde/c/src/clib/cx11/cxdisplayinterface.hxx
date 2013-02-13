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
 *   File: cxdisplayinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
#if !defined(_CXDISPLAYINTERFACE_HXX) || defined(CXDISPLAYINTERFACE_MEMBERS_ONLY)
#if !defined(_CXDISPLAYINTERFACE_HXX) && !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY)
#define _CXDISPLAYINTERFACE_HXX
#endif /* !defined(_CXDISPLAYINTERFACE_HXX) && !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY) */
#include "cxdisplayopened.hxx"

#if !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXDisplayInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/28/2010
 **********************************************************************
 */
typedef cXDisplayOpenedInterface
cXDisplayInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXDisplayInterface
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXDisplayInterface
: virtual public cXDisplayInterfaceImplement
{
public:
    typedef cXDisplayInterfaceImplement cImplements;
#else /* !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY) */

#if !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY)
/* include cXDisplay member functions interface
 */
#define CXDISPLAY_MEMBERS_ONLY
#define CXDISPLAY_MEMBER_FUNCS_INTERFACE
#include "cxdisplay.hxx"
#undef CXDISPLAY_MEMBER_FUNCS_INTERFACE
#undef CXDISPLAY_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXDisplayImplement
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXDisplayImplement
: virtual public cXDisplayInterface
{
public:
    typedef cXDisplayInterface cImplements;
/* include cXDisplay member functions implement
 */
#define CXDISPLAY_MEMBERS_ONLY
#define CXDISPLAY_MEMBER_FUNCS_IMPLEMENT
#include "cxdisplay.hxx"
#undef CXDISPLAY_MEMBER_FUNCS_IMPLEMENT
#undef CXDISPLAY_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXDISPLAYINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXDISPLAYINTERFACE_HXX) || defined(CXDISPLAYINTERFACE_MEMBERS_ONLY) */
