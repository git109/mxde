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
 *   File: cxmtextinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/2/2010
 **********************************************************************
 */
#if !defined(_CXMTEXTINTERFACE_HXX) || defined(CXMTEXTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMTEXTINTERFACE_HXX) && !defined(CXMTEXTINTERFACE_MEMBERS_ONLY)
#define _CXMTEXTINTERFACE_HXX
#endif /* !defined(_CXMTEXTINTERFACE_HXX) && !defined(CXMTEXTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMTEXTINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_Text.h"
#include "cxmprimitiveinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmTextInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 7/2/2010
 **********************************************************************
 */
typedef cXmPrimitiveInterface
cXmTextInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmTextInterface
 *
 * Author: $author$           
 *   Date: 7/2/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmTextInterface
: virtual public cXmTextInterfaceImplement
{
public:
    typedef cXmTextInterfaceImplement cImplements;
#else /* !defined(CXMTEXTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMTEXTINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXMTEXTIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXmTextImplement
 *
 * Author: $author$           
 *   Date: 7/2/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmTextImplement
: virtual public cXmTextInterface
{
public:
    typedef cXmTextInterface cImplements;
#else /* !defined(CXMTEXTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMTEXTIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXMTEXTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMTEXTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMTEXTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMTEXTINTERFACE_HXX) || defined(CXMTEXTINTERFACE_MEMBERS_ONLY) */
