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
 *   File: cxpixelinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
#if !defined(_CXPIXELINTERFACE_HXX) || defined(CXPIXELINTERFACE_MEMBERS_ONLY)
#if !defined(_CXPIXELINTERFACE_HXX) && !defined(CXPIXELINTERFACE_MEMBERS_ONLY)
#define _CXPIXELINTERFACE_HXX
#endif /* !defined(_CXPIXELINTERFACE_HXX) && !defined(CXPIXELINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPIXELINTERFACE_MEMBERS_ONLY)
#include "cxpixelattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXPixelInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/9/2010
 **********************************************************************
 */
typedef cXPixelAllocatedInterface
cXPixelInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXPixelInterface
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXPixelInterface
: virtual public cXPixelInterfaceImplement
{
public:
    typedef cXPixelInterfaceImplement cImplements;
#else /* !defined(CXPIXELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPIXELINTERFACE_MEMBERS_ONLY)
/* include cXPixel member functions interface
 */
#define CXPIXEL_MEMBERS_ONLY
#define CXPIXEL_MEMBER_FUNCS_INTERFACE
#include "cxpixel.hxx"
#undef CXPIXEL_MEMBER_FUNCS_INTERFACE
#undef CXPIXEL_MEMBERS_ONLY
};

#if !defined(CXPIXELIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXPixelImplement
 *
 * Author: $author$           
 *   Date: 6/9/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXPixelImplement
: virtual public cXPixelInterface
{
public:
    typedef cXPixelInterface cImplements;
#else /* !defined(CXPIXELIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXPIXELIMPLEMENT_MEMBERS_ONLY)
/* include cXPixel member functions implement
 */
#define CXPIXEL_MEMBERS_ONLY
#define CXPIXEL_MEMBER_FUNCS_IMPLEMENT
#include "cxpixel.hxx"
#undef CXPIXEL_MEMBER_FUNCS_IMPLEMENT
#undef CXPIXEL_MEMBERS_ONLY
};
#else /* !defined(CXPIXELIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPIXELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPIXELINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXPIXELINTERFACE_HXX) || defined(CXPIXELINTERFACE_MEMBERS_ONLY) */
