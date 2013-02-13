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
 *   File: cxpixmapinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
#if !defined(_CXPIXMAPINTERFACE_HXX) || defined(CXPIXMAPINTERFACE_MEMBERS_ONLY)
#if !defined(_CXPIXMAPINTERFACE_HXX) && !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY)
#define _CXPIXMAPINTERFACE_HXX
#endif /* !defined(_CXPIXMAPINTERFACE_HXX) && !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY)
#include "cxpixmapattached.hxx"
#include "cxdisplayinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXPixmapInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/1/2010
 **********************************************************************
 */
typedef cXPixmapCreatedInterface
cXPixmapInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXPixmapInterface
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXPixmapInterface
: virtual public cXPixmapInterfaceImplement
{
public:
    typedef cXPixmapInterfaceImplement cImplements;
#else /* !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY) */

#if !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY)
/* include cXPixmap member functions interface
 */
#define CXPIXMAP_MEMBERS_ONLY
#define CXPIXMAP_MEMBER_FUNCS_INTERFACE
#include "cxpixmap.hxx"
#undef CXPIXMAP_MEMBER_FUNCS_INTERFACE
#undef CXPIXMAP_MEMBERS_ONLY
};

#if !defined(CXPIXMAPIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXPixmapImplement
 *
 * Author: $author$           
 *   Date: 6/1/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXPixmapImplement
: virtual public cXPixmapInterface
{
public:
    typedef cXPixmapInterface cImplements;
#else /* !defined(CXPIXMAPIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAPIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXPIXMAPIMPLEMENT_MEMBERS_ONLY)
/* include cXPixmap member functions implement
 */
#define CXPIXMAP_MEMBERS_ONLY
#define CXPIXMAP_MEMBER_FUNCS_IMPLEMENT
#include "cxpixmap.hxx"
#undef CXPIXMAP_MEMBER_FUNCS_IMPLEMENT
#undef CXPIXMAP_MEMBERS_ONLY
};
#else /* !defined(CXPIXMAPIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAPIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXPIXMAPINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXPIXMAPINTERFACE_HXX) || defined(CXPIXMAPINTERFACE_MEMBERS_ONLY) */
