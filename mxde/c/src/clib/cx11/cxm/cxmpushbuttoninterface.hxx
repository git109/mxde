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
 *   File: cxmpushbuttoninterface.hxx
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
#if !defined(_CXMPUSHBUTTONINTERFACE_HXX) || defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMPUSHBUTTONINTERFACE_HXX) && !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY)
#define _CXMPUSHBUTTONINTERFACE_HXX
#endif /* !defined(_CXMPUSHBUTTONINTERFACE_HXX) && !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_PushB.h"
#include "cxmlabelinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmPushButtonInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 7/12/2010
 **********************************************************************
 */
typedef cXmLabelInterface
cXmPushButtonInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmPushButtonInterface
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmPushButtonInterface
: virtual public cXmPushButtonInterfaceImplement
{
public:
    typedef cXmPushButtonInterfaceImplement cImplements;
#else /* !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY)
/* include cXmPushButton member functions interface
 */
#define CXMPUSHBUTTON_MEMBERS_ONLY
#define CXMPUSHBUTTON_MEMBER_FUNCS_INTERFACE
#include "cxmpushbutton.hxx"
#undef CXMPUSHBUTTON_MEMBER_FUNCS_INTERFACE
#undef CXMPUSHBUTTON_MEMBERS_ONLY
};

#if !defined(CXMPUSHBUTTONIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cXmPushButtonImplementImplement
 *
 *  Author: $author$           
 *    Date: 7/12/2010
 **********************************************************************
 */
typedef cXmPushButtonInterface
cXmPushButtonImplementImplement;
/**
 **********************************************************************
 *  Class: cXmPushButtonImplement
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmPushButtonImplement
: virtual public cXmPushButtonImplementImplement
{
public:
    typedef cXmPushButtonImplementImplement cImplements;
#else /* !defined(CXMPUSHBUTTONIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMPUSHBUTTONIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMPUSHBUTTONIMPLEMENT_MEMBERS_ONLY)
/* include cXmPushButton member functions implement
 */
#define CXMPUSHBUTTON_MEMBERS_ONLY
#define CXMPUSHBUTTON_MEMBER_FUNCS_IMPLEMENT
#include "cxmpushbutton.hxx"
#undef CXMPUSHBUTTON_MEMBER_FUNCS_IMPLEMENT
#undef CXMPUSHBUTTON_MEMBERS_ONLY
};
#else /* !defined(CXMPUSHBUTTONIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMPUSHBUTTONIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMPUSHBUTTONINTERFACE_HXX) || defined(CXMPUSHBUTTONINTERFACE_MEMBERS_ONLY) */
