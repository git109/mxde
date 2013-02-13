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
 *   File: cxmforminterface.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMFORMINTERFACE_HXX) || defined(CXMFORMINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMFORMINTERFACE_HXX) && !defined(CXMFORMINTERFACE_MEMBERS_ONLY)
#define _CXMFORMINTERFACE_HXX
#endif /* !defined(_CXMFORMINTERFACE_HXX) && !defined(CXMFORMINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMFORMINTERFACE_MEMBERS_ONLY)
#include "cplatform_Xm_Form.h"
#include "cxmbulletinboardinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXmFormInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXmBulletinBoardInterface
cXmFormInterfaceImplement;
/**
 **********************************************************************
 * Typedef: cXmBulletinBoardInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/27/2010
 **********************************************************************
 */
typedef cXmManagerInterface
cXmBulletinBoardInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXmFormInterface
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmFormInterface
: virtual public cXmFormInterfaceImplement
{
public:
    typedef cXmFormInterfaceImplement cImplements;
#else /* !defined(CXMFORMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMFORMINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMFORMINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXMFORMIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXmFormImplement
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmFormImplement
: virtual public cXmFormInterface
{
public:
    typedef cXmFormInterface cImplements;
#else /* !defined(CXMFORMIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMFORMIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMFORMIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXMFORMIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMFORMIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMFORMINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMFORMINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMFORMINTERFACE_HXX) || defined(CXMFORMINTERFACE_MEMBERS_ONLY) */
