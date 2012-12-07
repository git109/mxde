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
 *   File: cimageobjectinterface.hxx
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
#if !defined(_CIMAGEOBJECTINTERFACE_HXX) || defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGEOBJECTINTERFACE_HXX) && !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY)
#define _CIMAGEOBJECTINTERFACE_HXX
#endif /* !defined(_CIMAGEOBJECTINTERFACE_HXX) && !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY)
#include "cimageinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cImageObjectInterface
 *
 * Author: $author$
 *   Date: 7/16/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageObjectInterface
: virtual public cImageInterface
{
public:
    typedef cImageInterface cImplements;
#else /* !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY)
/* include cImageObject member functions interface
 */
#define CIMAGEOBJECT_MEMBERS_ONLY
#define CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE
#include "cimageobject.hxx"
#undef CIMAGEOBJECT_MEMBER_FUNCS_INTERFACE
#undef CIMAGEOBJECT_MEMBERS_ONLY
};

class c_IMPLEMENT_CLASS cImageObjectImplement
: virtual public cImageObjectInterface,
  virtual public cImageImplement
{
public:
/* include cImageObject member functions implement
 */
#define CIMAGEOBJECT_MEMBERS_ONLY
#define CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT
#include "cimageobject.hxx"
#undef CIMAGEOBJECT_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGEOBJECT_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEOBJECTINTERFACE_HXX) || defined(CIMAGEOBJECTINTERFACE_MEMBERS_ONLY) */
