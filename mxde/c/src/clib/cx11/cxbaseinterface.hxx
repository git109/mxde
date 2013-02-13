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
 *   File: cxbaseinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
#if !defined(_CXBASEINTERFACE_HXX) || defined(CXBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXBASEINTERFACE_HXX) && !defined(CXBASEINTERFACE_MEMBERS_ONLY)
#define _CXBASEINTERFACE_HXX
#endif /* !defined(_CXBASEINTERFACE_HXX) && !defined(CXBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXBASEINTERFACE_MEMBERS_ONLY)
#include "cplatform_X11_Xlib.h"
#include "cplatform_X11_Xutil.h"
#include "cplatform_X11_xpm.h"
#include "cplatform_X11_extensions_shape.h"
#include "cinterfacebase.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXBaseInterface
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXBaseInterface
: virtual public cInterfaceBase
{
public:
#else /* !defined(CXBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXBASEINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cXBaseImplement
 *
 * Author: $author$           
 *   Date: 6/20/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXBaseImplement
: virtual public cXBaseInterface
{
public:
#else /* !defined(CXBASEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXBASEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXBASEIMPLEMENT_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXBASEINTERFACE_HXX) || defined(CXBASEINTERFACE_MEMBERS_ONLY) */
