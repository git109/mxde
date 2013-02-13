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
 *   File: cxeventtargetinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
#if !defined(_CXEVENTTARGETINTERFACE_HXX) || defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY)
#if !defined(_CXEVENTTARGETINTERFACE_HXX) && !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY)
#define _CXEVENTTARGETINTERFACE_HXX
#endif /* !defined(_CXEVENTTARGETINTERFACE_HXX) && !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY) */

#if !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY)
#include "cxbaseinterface.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXEventTargetInterface
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXEventTargetInterface
: virtual public cXBaseInterface
{
public:
#else /* !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY) */

#if !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY)
/* include cXEventTarget member functions interface
 */
#define CXEVENTTARGET_MEMBERS_ONLY
#define CXEVENTTARGET_MEMBER_FUNCS_INTERFACE
#include "cxeventtarget.hxx"
#undef CXEVENTTARGET_MEMBER_FUNCS_INTERFACE
#undef CXEVENTTARGET_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXEventTargetImplement
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXEventTargetImplement
: virtual public cXEventTargetInterface
{
public:
/* include cXEventTarget member functions implement
 */
#define CXEVENTTARGET_MEMBERS_ONLY
#define CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT
#include "cxeventtarget.hxx"
#undef CXEVENTTARGET_MEMBER_FUNCS_IMPLEMENT
#undef CXEVENTTARGET_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXEVENTTARGETINTERFACE_HXX) || defined(CXEVENTTARGETINTERFACE_MEMBERS_ONLY) */
