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
 *   File: cxcolormapinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/3/2009
 **********************************************************************
 */
#if !defined(_CXCOLORMAPINTERFACE_HXX) || defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY)
#if !defined(_CXCOLORMAPINTERFACE_HXX) && !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY)
#define _CXCOLORMAPINTERFACE_HXX
#endif /* !defined(_CXCOLORMAPINTERFACE_HXX) && !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY) */

#if !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY)
#include "cxcolormapattached.hxx"
#include "cxdisplayinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXColormapInterface
 *
 * Author: $author$           
 *   Date: 7/3/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXColormapInterface
: virtual public cXColormapCreatedInterface
{
public:
    typedef cXColormapCreatedInterface cImplements;
#else /* !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY) */

#if !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY)
/* include cXColormap member functions interface
 */
#define CXCOLORMAP_MEMBERS_ONLY
#define CXCOLORMAP_MEMBER_FUNCS_INTERFACE
#include "cxcolormap.hxx"
#undef CXCOLORMAP_MEMBER_FUNCS_INTERFACE
#undef CXCOLORMAP_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cXColormapImplement
: virtual public cXColormapInterface
{
public:
/* include cXColormap interface member definitions
 */
#define CXCOLORMAPINTERFACE_MEMBERS_ONLY
#include "cxcolormapinterface.hxx"
#undef CXCOLORMAPINTERFACE_MEMBERS_ONLY

/* include cXColormap member functions implement
 */
#define CXCOLORMAP_MEMBERS_ONLY
#define CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT
#include "cxcolormap.hxx"
#undef CXCOLORMAP_MEMBER_FUNCS_IMPLEMENT
#undef CXCOLORMAP_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXCOLORMAPINTERFACE_HXX) || defined(CXCOLORMAPINTERFACE_MEMBERS_ONLY) */
