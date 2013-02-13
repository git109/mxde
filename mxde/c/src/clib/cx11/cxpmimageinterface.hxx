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
 *   File: cxpmimageinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
#if !defined(_CXPMIMAGEINTERFACE_HXX) || defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXPMIMAGEINTERFACE_HXX) && !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY)
#define _CXPMIMAGEINTERFACE_HXX
#endif /* !defined(_CXPMIMAGEINTERFACE_HXX) && !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY)
#include "cplatform_X11_xpm.h"
#include "cxbaseinterface.hxx"
#include "ccreatedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cXpmImageCreatedInterface;
/**
 **********************************************************************
 * Typedef: cXpmImageCreatedInterfaceImplements
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cCreatedInterfaceT
<cXpmImageCreatedInterface, cXBaseInterface>
cXpmImageCreatedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cXpmImageCreatedInterface
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXpmImageCreatedInterface
: virtual public cXpmImageCreatedInterfaceImplements
{
public:
    typedef cXpmImageCreatedInterfaceImplements cImplements;
    typedef cXpmImageCreatedInterface cDerives;
};
/**
 **********************************************************************
 * Typedef: cXpmImageInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cXpmImageCreatedInterface
cXpmImageInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXpmImageInterface
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXpmImageInterface
: virtual public cXpmImageInterfaceImplement
{
public:
    typedef cXpmImageInterfaceImplement cImplements;
#else /* !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY)
/* include cXpmImage member functions interface
 */
#define CXPMIMAGE_MEMBERS_ONLY
#define CXPMIMAGE_MEMBER_FUNCS_INTERFACE
#include "cxpmimage.hxx"
#undef CXPMIMAGE_MEMBER_FUNCS_INTERFACE
#undef CXPMIMAGE_MEMBERS_ONLY
};

#if !defined(CXPMIMAGEIMPLEMENT_MEMBERS_ONLY)
class c_EXPORT_CLASS cXpmImageCreatedImplement;
/**
 **********************************************************************
 * Typedef: cXpmImageCreatedImplementImplements
 *
 *  Author: $author$           
 *    Date: 6/4/2010
 **********************************************************************
 */
typedef cCreatedImplementT
<cXpmImageCreatedImplement, cXpmImageCreatedInterface>
cXpmImageCreatedImplementImplements;
/**
 **********************************************************************
 *  Class: cXpmImageCreatedImplement
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cXpmImageCreatedImplement
: virtual public cXpmImageCreatedImplementImplements
{
public:
    typedef cXpmImageCreatedImplementImplements cImplements;
    typedef cXpmImageCreatedImplement cDerives;
};
/**
 **********************************************************************
 *  Class: cXpmImageImplement
 *
 * Author: $author$           
 *   Date: 6/4/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXpmImageImplement
: virtual public cXpmImageInterface,
  virtual public cXpmImageCreatedImplement
{
public:
    typedef cXpmImageInterface cImplements;
#else /* !defined(CXPMIMAGEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMAGEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXPMIMAGEIMPLEMENT_MEMBERS_ONLY)
/* include cXpmImage member functions implement
 */
#define CXPMIMAGE_MEMBERS_ONLY
#define CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT
#include "cxpmimage.hxx"
#undef CXPMIMAGE_MEMBER_FUNCS_IMPLEMENT
#undef CXPMIMAGE_MEMBERS_ONLY
};
#else /* !defined(CXPMIMAGEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMAGEIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXPMIMAGEINTERFACE_HXX) || defined(CXPMIMAGEINTERFACE_MEMBERS_ONLY) */
