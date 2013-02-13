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
 *   File: cxfontstructinterface.hxx
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
#if !defined(_CXFONTSTRUCTINTERFACE_HXX) || defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY)
#if !defined(_CXFONTSTRUCTINTERFACE_HXX) && !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY)
#define _CXFONTSTRUCTINTERFACE_HXX
#endif /* !defined(_CXFONTSTRUCTINTERFACE_HXX) && !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY)
#include "cxfontstructattached.hxx"
#include "cxobjectinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cXFontStructInterfaceImplement
 *
 *  Author: $author$           
 *    Date: 6/13/2010
 **********************************************************************
 */
typedef cXFontStructAllocatedInterface
cXFontStructInterfaceImplement;
/**
 **********************************************************************
 *  Class: cXFontStructInterface
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cXFontStructInterface
: virtual public cXFontStructInterfaceImplement,
  virtual public cXObjectInterface
{
public:
    typedef cXFontStructInterfaceImplement cImplements;
#else /* !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY) */

#if !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY)
/* include cXFontStruct member functions interface
 */
#define CXFONTSTRUCT_MEMBERS_ONLY
#define CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE
#include "cxfontstruct.hxx"
#undef CXFONTSTRUCT_MEMBER_FUNCS_INTERFACE
#undef CXFONTSTRUCT_MEMBERS_ONLY
};

#if !defined(CXFONTSTRUCTIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cXFontStructImplement
 *
 * Author: $author$           
 *   Date: 6/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cXFontStructImplement
: virtual public cXFontStructInterface,
  virtual public cXObjectImplement
{
public:
    typedef cXFontStructInterface cImplements;
#else /* !defined(CXFONTSTRUCTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCTIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CXFONTSTRUCTIMPLEMENT_MEMBERS_ONLY)
/* include cXFontStruct member functions implement
 */
#define CXFONTSTRUCT_MEMBERS_ONLY
#define CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT
#include "cxfontstruct.hxx"
#undef CXFONTSTRUCT_MEMBER_FUNCS_IMPLEMENT
#undef CXFONTSTRUCT_MEMBERS_ONLY
};
#else /* !defined(CXFONTSTRUCTIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCTIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CXFONTSTRUCTINTERFACE_HXX) || defined(CXFONTSTRUCTINTERFACE_MEMBERS_ONLY) */
