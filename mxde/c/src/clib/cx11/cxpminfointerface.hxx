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
 *   File: cxpminfointerface.hxx
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
#if !defined(_CXPMINFOINTERFACE_HXX) || defined(CXPMINFOINTERFACE_MEMBERS_ONLY)
#if !defined(_CXPMINFOINTERFACE_HXX) && !defined(CXPMINFOINTERFACE_MEMBERS_ONLY)
#define _CXPMINFOINTERFACE_HXX
#endif /* !defined(_CXPMINFOINTERFACE_HXX) && !defined(CXPMINFOINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPMINFOINTERFACE_MEMBERS_ONLY)
#include "cplatform_X11_xpm.h"
#include "cxbaseinterface.hxx"
#include "ccreatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXpmInfoCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXpmInfoCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXpmInfoCreatedInterface, cInterfaceBase>
cXpmInfoCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXpmInfoCreatedInterface
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXpmInfoCreatedInterface
: virtual public cXpmInfoCreatedInterfaceImplements
{
public:
    typedef cXpmInfoCreatedInterfaceImplements cImplements;
    typedef cXpmInfoCreatedInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cXpmInfoInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cXpmInfoCreatedInterface
cXpmInfoInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXpmInfoInterface
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXpmInfoInterface
: virtual public cXpmInfoInterfaceImplement
{
public:
    typedef cXpmInfoInterfaceImplement cImplements;
#else /* !defined(CXPMINFOINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPMINFOINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPMINFOINTERFACE_MEMBERS_ONLY)
/* include cXpmInfo member functions interface
 */
#define CXPMINFO_MEMBERS_ONLY
#define CXPMINFO_MEMBER_FUNCS_INTERFACE
#include "cxpminfo.hxx"
#undef CXPMINFO_MEMBER_FUNCS_INTERFACE
#undef CXPMINFO_MEMBERS_ONLY
};

#if !defined(CXPMINFOIMPLEMENT_MEMBERS_ONLY)
class c_EXPORT_CLASS cXpmInfoCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXpmInfoCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXpmInfoCreatedImplement, cXpmInfoCreatedInterface>
cXpmInfoCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXpmInfoCreatedImplement
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXpmInfoCreatedImplement
: virtual public cXpmInfoCreatedImplementImplements
{
public:
    typedef cXpmInfoCreatedImplementImplements cImplements;
    typedef cXpmInfoCreatedImplement cDerives;
};
/**
 **********************************************************************
 *  Class: cXpmInfoImplement
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXpmInfoImplement
: virtual public cXpmInfoInterface,
  virtual public cXpmInfoCreatedImplement
{
public:
    typedef cXpmInfoInterface cImplements;
#else /* !defined(CXPMINFOIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPMINFOIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXPMINFOIMPLEMENT_MEMBERS_ONLY)
/* include cXpmInfo member functions implement
 */
#define CXPMINFO_MEMBERS_ONLY
#define CXPMINFO_MEMBER_FUNCS_IMPLEMENT
#include "cxpminfo.hxx"
#undef CXPMINFO_MEMBER_FUNCS_IMPLEMENT
#undef CXPMINFO_MEMBERS_ONLY
};
#else /* !defined(CXPMINFOIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPMINFOIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPMINFOINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPMINFOINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXPMINFOINTERFACE_HXX) || defined(CXPMINFOINTERFACE_MEMBERS_ONLY) */
