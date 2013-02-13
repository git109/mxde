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
 *   File: cxmtextfieldinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/15/2010
 **********************************************************************
 */
#if !defined(_CXMTEXTFIELDINTERFACE_HXX) || defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMTEXTFIELDINTERFACE_HXX) && !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY)
#define _CXMTEXTFIELDINTERFACE_HXX
#endif /* !defined(_CXMTEXTFIELDINTERFACE_HXX) && !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_TextF.h"
#include "cxmprimitiveinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmTextFieldInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 7/15/2010
 **********************************************************************
 */
typedef cXmPrimitiveInterface
cXmTextFieldInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmTextFieldInterface
 *
 * Author: $author$           
 *   Date: 7/15/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmTextFieldInterface
: virtual public cXmTextFieldInterfaceImplement
{
public:
    typedef cXmTextFieldInterfaceImplement cImplements;
#else /* !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY)
};


#if !defined(CXMTEXTFIELDIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cXmTextFieldImplementImplement
 *
 *  Author: $author$           
 *    Date: 7/15/2010
 **********************************************************************
 */
typedef cXmTextFieldInterface
cXmTextFieldImplementImplement;
/**
 **********************************************************************
 *  Class: cXmTextFieldImplement
 *
 * Author: $author$           
 *   Date: 7/15/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmTextFieldImplement
: virtual public cXmTextFieldImplementImplement
{
public:
    typedef cXmTextFieldImplementImplement cImplements;
#else /* !defined(CXMTEXTFIELDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTFIELDIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMTEXTFIELDIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXMTEXTFIELDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTFIELDIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMTEXTFIELDINTERFACE_HXX) || defined(CXMTEXTFIELDINTERFACE_MEMBERS_ONLY) */
