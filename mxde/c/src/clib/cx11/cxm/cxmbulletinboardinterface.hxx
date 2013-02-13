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
 *   File: cxmbulletinboardinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
#if !defined(_CXMBULLETINBOARDINTERFACE_HXX) || defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY)
#if !defined(_CXMBULLETINBOARDINTERFACE_HXX) && !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY)
#define _CXMBULLETINBOARDINTERFACE_HXX
#endif /* !defined(_CXMBULLETINBOARDINTERFACE_HXX) && !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY)
#include "cxmmanagerinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

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
 *  Class: cXmBulletinBoardInterface
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXmBulletinBoardInterface
: virtual public cXmBulletinBoardInterfaceImplement
{
public:
    typedef cXmBulletinBoardInterfaceImplement cImplements;
#else /* !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY) */

#if !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY)
};

#if !defined(CXMBULLETINBOARDIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXmBulletinBoardImplement
 *
 * Author: $author$           
 *   Date: 6/27/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXmBulletinBoardImplement
: virtual public cXmBulletinBoardInterface
{
public:
    typedef cXmBulletinBoardInterface cImplements;
#else /* !defined(CXMBULLETINBOARDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMBULLETINBOARDIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXMBULLETINBOARDIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CXMBULLETINBOARDIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXMBULLETINBOARDIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMBULLETINBOARDINTERFACE_HXX) || defined(CXMBULLETINBOARDINTERFACE_MEMBERS_ONLY) */
