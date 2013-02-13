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
 *   File: cxwindowinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
#if !defined(_CXWINDOWINTERFACE_HXX) || defined(CXWINDOWINTERFACE_MEMBERS_ONLY)
#if !defined(_CXWINDOWINTERFACE_HXX) && !defined(CXWINDOWINTERFACE_MEMBERS_ONLY)
#define _CXWINDOWINTERFACE_HXX
#endif /* !defined(_CXWINDOWINTERFACE_HXX) && !defined(CXWINDOWINTERFACE_MEMBERS_ONLY) */

#if !defined(CXWINDOWINTERFACE_MEMBERS_ONLY)
#include "cxwindowattached.hxx"
#include "cxeventtargetinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXWindowInterface
 *
 * Author: $author$           
 *   Date: 7/5/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXWindowInterface
: virtual public cXWindowCreatedInterface,
  virtual public cXEventTargetInterface
{
public:
    typedef cXBaseInterface cImplements;
#else /* !defined(CXWINDOWINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWINTERFACE_MEMBERS_ONLY) */

#if !defined(CXWINDOWINTERFACE_MEMBERS_ONLY)
/* include cXWindow member functions interface
 */
#define CXWINDOW_MEMBERS_ONLY
#define CXWINDOW_MEMBER_FUNCS_INTERFACE
#include "cxwindow.hxx"
#undef CXWINDOW_MEMBER_FUNCS_INTERFACE
#undef CXWINDOW_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cXWindowImplement
: virtual public cXWindowCreatedImplement,
  virtual public cXEventTargetImplement,
  virtual public cXWindowInterface
{
public:
/* include cXWindow member functions implement
 */
#define CXWINDOW_MEMBERS_ONLY
#define CXWINDOW_MEMBER_FUNCS_IMPLEMENT
#include "cxwindow.hxx"
#undef CXWINDOW_MEMBER_FUNCS_IMPLEMENT
#undef CXWINDOW_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXWINDOWINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXWINDOWINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXWINDOWINTERFACE_HXX) || defined(CXWINDOWINTERFACE_MEMBERS_ONLY) */
