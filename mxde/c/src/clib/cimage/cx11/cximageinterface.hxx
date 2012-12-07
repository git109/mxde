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
 *   File: cximageinterface.hxx
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXIMAGEINTERFACE_HXX) || defined(CXIMAGEINTERFACE_MEMBERS_ONLY)
#if !defined(_CXIMAGEINTERFACE_HXX) && !defined(CXIMAGEINTERFACE_MEMBERS_ONLY)
#define _CXIMAGEINTERFACE_HXX
#endif /* !defined(_CXIMAGEINTERFACE_HXX) && !defined(CXIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXIMAGEINTERFACE_MEMBERS_ONLY)
#include "cimageinterface.hxx"
#include "cxgc.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXImageInterfaceImplement
 *
 *  Author: $author$
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cImageInterface
cXImageInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXImageInterface
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXImageInterface
: virtual public cXImageInterfaceImplement
{
public:
    typedef cXImageInterfaceImplement cImplements;
#else /* !defined(CXIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEINTERFACE_MEMBERS_ONLY) */

#if !defined(CXIMAGEINTERFACE_MEMBERS_ONLY)
/* include cXImage member functions interface
 */
#define CXIMAGE_MEMBERS_ONLY
#define CXIMAGE_MEMBER_FUNCS_INTERFACE
#include "cximage.hxx"
#undef CXIMAGE_MEMBER_FUNCS_INTERFACE
#undef CXIMAGE_MEMBERS_ONLY
};

#if !defined(CXIMAGEIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXImageImplement
 *
 * Author: $author$
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXImageImplement
: virtual public cXImageInterface
{
public:
    typedef cXImageInterface cImplements;
#else /* !defined(CXIMAGEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXIMAGEIMPLEMENT_MEMBERS_ONLY)
/* include cXImage member functions implement
 */
#define CXIMAGE_MEMBERS_ONLY
#define CXIMAGE_MEMBER_FUNCS_IMPLEMENT
#include "cximage.hxx"
#undef CXIMAGE_MEMBER_FUNCS_IMPLEMENT
#undef CXIMAGE_MEMBERS_ONLY
};
#else /* !defined(CXIMAGEIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXIMAGEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXIMAGEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXIMAGEINTERFACE_HXX) || defined(CXIMAGEINTERFACE_MEMBERS_ONLY) */
