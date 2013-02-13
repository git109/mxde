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
 *   File: cxmlabelinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
#if !defined(_CXMLABELINTERFACE_HXX) || defined(CXMLABELINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMLABELINTERFACE_HXX) && !defined(CXMLABELINTERFACE_MEMBERS_ONLY)
#define _CXMLABELINTERFACE_HXX
#endif /* !defined(_CXMLABELINTERFACE_HXX) && !defined(CXMLABELINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMLABELINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_Label.h"
#include "cxmprimitiveinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmLabelInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 7/12/2010
 **********************************************************************
 */
typedef cXmPrimitiveInterface
cXmLabelInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmLabelInterface
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmLabelInterface
: virtual public cXmLabelInterfaceImplement
{
public:
    typedef cXmLabelInterfaceImplement cImplements;
#else /* !defined(CXMLABELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMLABELINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMLABELINTERFACE_MEMBERS_ONLY)
/* include cXmLabel member functions interface
 */
#define CXMLABEL_MEMBERS_ONLY
#define CXMLABEL_MEMBER_FUNCS_INTERFACE
#include "cxmlabel.hxx"
#undef CXMLABEL_MEMBER_FUNCS_INTERFACE
#undef CXMLABEL_MEMBERS_ONLY
};

#if !defined(CXMLABELIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cXmLabelImplementImplement
 *
 *  Author: $author$           
 *    Date: 7/12/2010
 **********************************************************************
 */
typedef cXmLabelInterface
cXmLabelImplementImplement;
/**
 **********************************************************************
 *  Class: cXmLabelImplement
 *
 * Author: $author$           
 *   Date: 7/12/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmLabelImplement
: virtual public cXmLabelImplementImplement
{
public:
    typedef cXmLabelImplementImplement cImplements;
#else /* !defined(CXMLABELIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMLABELIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMLABELIMPLEMENT_MEMBERS_ONLY)
/* include cXmLabel member functions implement
 */
#define CXMLABEL_MEMBERS_ONLY
#define CXMLABEL_MEMBER_FUNCS_IMPLEMENT
#include "cxmlabel.hxx"
#undef CXMLABEL_MEMBER_FUNCS_IMPLEMENT
#undef CXMLABEL_MEMBERS_ONLY
};
#else /* !defined(CXMLABELIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMLABELIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMLABELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMLABELINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMLABELINTERFACE_HXX) || defined(CXMLABELINTERFACE_MEMBERS_ONLY) */
