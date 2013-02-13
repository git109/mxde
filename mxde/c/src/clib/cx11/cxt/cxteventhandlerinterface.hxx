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
 *   File: cxteventhandlerinterface.hxx
 *
 * Author: $author$           
 *   Date: 4/28/2010
 **********************************************************************
 */
#if !defined(_CXTEVENTHANDLERINTERFACE_HXX) || defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY)
#if !defined(_CXTEVENTHANDLERINTERFACE_HXX) && !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY)
#define _CXTEVENTHANDLERINTERFACE_HXX
#endif /* !defined(_CXTEVENTHANDLERINTERFACE_HXX) && !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY)
#include "cplatform_X11_Intrinsic.h"
#include "cxbaseinterface.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXtEventHandlerInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 4/28/2010
 **********************************************************************
 */
typedef cXBaseInterface
cXtEventHandlerInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXtEventHandlerInterface
 *
 * Author: $author$           
 *   Date: 4/28/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXtEventHandlerInterface
: virtual public cXtEventHandlerInterfaceImplement
{
public:
    typedef cXtEventHandlerInterfaceImplement cImplements;
#else /* !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY) */

#if !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY)
/* include cXtEventHandler member functions interface
 */
#define CXTEVENTHANDLER_MEMBERS_ONLY
#define CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE
#include "cxteventhandler.hxx"
#undef CXTEVENTHANDLER_MEMBER_FUNCS_INTERFACE
#undef CXTEVENTHANDLER_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXtEventHandlerImplement
 *
 * Author: $author$           
 *   Date: 4/28/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXtEventHandlerImplement
: virtual public cXtEventHandlerInterface
{
public:
    typedef cXtEventHandlerInterface cImplements;
/* include cXtEventHandler member functions implement
 */
#define CXTEVENTHANDLER_MEMBERS_ONLY
#define CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT
#include "cxteventhandler.hxx"
#undef CXTEVENTHANDLER_MEMBER_FUNCS_IMPLEMENT
#undef CXTEVENTHANDLER_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXTEVENTHANDLERINTERFACE_HXX) || defined(CXTEVENTHANDLERINTERFACE_MEMBERS_ONLY) */
