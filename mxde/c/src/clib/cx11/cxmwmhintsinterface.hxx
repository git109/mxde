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
 *   File: cxmwmhintsinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/26/2010
 **********************************************************************
 */
#if !defined(_CXMWMHINTSINTERFACE_HXX) || defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMWMHINTSINTERFACE_HXX) && !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY)
#define _CXMWMHINTSINTERFACE_HXX
#endif /* !defined(_CXMWMHINTSINTERFACE_HXX) && !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_MwmUtil.h"
#include "cxpropertyinterface.hxx"

#if !defined(MWM_DECOR_NONE)
#define MWM_DECOR_NONE 0
#endif /* !defined(MWM_DECOR_NONE) */

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXMwmHintsInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/26/2010
 **********************************************************************
 */
typedef cXPropertyInterface
cXMwmHintsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXMwmHintsInterface
 *
 * Author: $author$           
 *   Date: 6/26/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMwmHintsInterface
: virtual public cXMwmHintsInterfaceImplement
{
public:
    typedef cXMwmHintsInterfaceImplement cImplements;
#else /* !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY)
/* include cXMwmHints member functions interface
 */
#define CXMWMHINTS_MEMBERS_ONLY
#define CXMWMHINTS_MEMBER_FUNCS_INTERFACE
#include "cxmwmhints.hxx"
#undef CXMWMHINTS_MEMBER_FUNCS_INTERFACE
#undef CXMWMHINTS_MEMBERS_ONLY
};

#if !defined(CXMWMHINTSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXMwmHintsImplement
 *
 * Author: $author$           
 *   Date: 6/26/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXMwmHintsImplement
: virtual public cXMwmHintsInterface
{
public:
    typedef cXMwmHintsInterface cImplements;
#else /* !defined(CXMWMHINTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMWMHINTSIMPLEMENT_MEMBERS_ONLY)
/* include cXMwmHints member functions implement
 */
#define CXMWMHINTS_MEMBERS_ONLY
#define CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT
#include "cxmwmhints.hxx"
#undef CXMWMHINTS_MEMBER_FUNCS_IMPLEMENT
#undef CXMWMHINTS_MEMBERS_ONLY
};
#else /* !defined(CXMWMHINTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMWMHINTSINTERFACE_HXX) || defined(CXMWMHINTSINTERFACE_MEMBERS_ONLY) */
