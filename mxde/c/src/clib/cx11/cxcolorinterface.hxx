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
 *   File: cxcolorinterface.hxx
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
#if !defined(_CXCOLORINTERFACE_HXX) || defined(CXCOLORINTERFACE_MEMBERS_ONLY)
#if !defined(_CXCOLORINTERFACE_HXX) && !defined(CXCOLORINTERFACE_MEMBERS_ONLY)
#define _CXCOLORINTERFACE_HXX
#endif /* !defined(_CXCOLORINTERFACE_HXX) && !defined(CXCOLORINTERFACE_MEMBERS_ONLY) */

#if !defined(CXCOLORINTERFACE_MEMBERS_ONLY)
#include "cxcolormapinterface.hxx"
#include "cxpixelattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cXColorInterface
 *
 * Author: $author$           
 *   Date: 7/4/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cXColorInterface
: virtual public cXPixelAllocatedInterface
{
public:
    typedef cXPixelAllocatedInterface cImplements;
#else /* !defined(CXCOLORINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORINTERFACE_MEMBERS_ONLY) */

#if !defined(CXCOLORINTERFACE_MEMBERS_ONLY)
/* include cXColor member functions interface
 */
#define CXCOLOR_MEMBERS_ONLY
#define CXCOLOR_MEMBER_FUNCS_INTERFACE
#include "cxcolor.hxx"
#undef CXCOLOR_MEMBER_FUNCS_INTERFACE
#undef CXCOLOR_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cXColorImplement
: virtual public cXPixelAllocatedImplement,
  virtual public cXColorInterface
{
public:
/* include cXColor interface member definitions
 */
#define CXCOLORINTERFACE_MEMBERS_ONLY
#include "cxcolorinterface.hxx"
#undef CXCOLORINTERFACE_MEMBERS_ONLY

/* include cXColor member functions implement
 */
#define CXCOLOR_MEMBERS_ONLY
#define CXCOLOR_MEMBER_FUNCS_IMPLEMENT
#include "cxcolor.hxx"
#undef CXCOLOR_MEMBER_FUNCS_IMPLEMENT
#undef CXCOLOR_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXCOLORINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXCOLORINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXCOLORINTERFACE_HXX) || defined(CXCOLORINTERFACE_MEMBERS_ONLY) */
