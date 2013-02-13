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
 *   File: cxpminterface.hxx
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
#if !defined(_CXPMINTERFACE_HXX) || defined(CXPMINTERFACE_MEMBERS_ONLY)
#if !defined(_CXPMINTERFACE_HXX) && !defined(CXPMINTERFACE_MEMBERS_ONLY)
#define _CXPMINTERFACE_HXX
#endif /* !defined(_CXPMINTERFACE_HXX) && !defined(CXPMINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPMINTERFACE_MEMBERS_ONLY)
#include "cplatform_X11_xpm.h"
#include "cxbaseinterface.hxx"
#include "cxpmimageinterface.hxx"
#include "cxpminfointerface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXpmInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXpmInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXpmInterface
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXpmInterface
: virtual public cXpmInterfaceImplement
{
public:
    typedef cXpmInterfaceImplement cImplements;
#else /* !defined(CXPMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPMINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPMINTERFACE_MEMBERS_ONLY)
/* include cXpm member functions interface
 */
#define CXPM_MEMBERS_ONLY
#define CXPM_MEMBER_FUNCS_INTERFACE
#include "cxpm.hxx"
#undef CXPM_MEMBER_FUNCS_INTERFACE
#undef CXPM_MEMBERS_ONLY
};

#if !defined(CXPMIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXpmImplement
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXpmImplement
: virtual public cXpmInterface
{
public:
    typedef cXpmInterface cImplements;
#else /* !defined(CXPMIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXPMIMPLEMENT_MEMBERS_ONLY)
/* include cXpm member functions implement
 */
#define CXPM_MEMBERS_ONLY
#define CXPM_MEMBER_FUNCS_IMPLEMENT
#include "cxpm.hxx"
#undef CXPM_MEMBER_FUNCS_IMPLEMENT
#undef CXPM_MEMBERS_ONLY
};
#else /* !defined(CXPMIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPMINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXPMINTERFACE_HXX) || defined(CXPMINTERFACE_MEMBERS_ONLY) */
