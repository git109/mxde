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
 *   File: cxmaininterface.hxx
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
#if !defined(_CXMAININTERFACE_HXX) || defined(CXMAININTERFACE_MEMBERS_ONLY)
#if !defined(_CXMAININTERFACE_HXX) && !defined(CXMAININTERFACE_MEMBERS_ONLY)
#define _CXMAININTERFACE_HXX
#endif /* !defined(_CXMAININTERFACE_HXX) && !defined(CXMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CXMAININTERFACE_MEMBERS_ONLY)
#include "cargmaininterface.hxx"
#include "cxdisplayinterface.hxx"
#include "cxwindowinterface.hxx"
#include "cxeventtargetinterface.hxx"
#include "cxobjectinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXMainInterface
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXMainInterface
: virtual public cArgMainInterface,
  virtual public cXEventTargetInterface,
  virtual public cXObjectInterface
{
public:
#else /* !defined(CXMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMAININTERFACE_MEMBERS_ONLY) */

#if !defined(CXMAININTERFACE_MEMBERS_ONLY)
/* include cXMain member functions interface
 */
#define CXMAIN_MEMBERS_ONLY
#define CXMAIN_MEMBER_FUNCS_INTERFACE
#include "cxmain.hxx"
#undef CXMAIN_MEMBER_FUNCS_INTERFACE
#undef CXMAIN_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cXMainImplement
 *
 * Author: $author$           
 *   Date: 6/21/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXMainImplement
: virtual public cXMainInterface,
  virtual public cXEventTargetImplement,
  virtual public cXObjectImplement
{
public:
/* include cXMain member functions implement
 */
#define CXMAIN_MEMBERS_ONLY
#define CXMAIN_MEMBER_FUNCS_IMPLEMENT
#include "cxmain.hxx"
#undef CXMAIN_MEMBER_FUNCS_IMPLEMENT
#undef CXMAIN_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXMAININTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXMAININTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXMAININTERFACE_HXX) || defined(CXMAININTERFACE_MEMBERS_ONLY) */
