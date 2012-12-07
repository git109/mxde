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
 *   File: cimagereadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 1/12/2010
 **********************************************************************
 */
#if !defined(_CIMAGEREADEREVENTSINTERFACE_HXX) || defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGEREADEREVENTSINTERFACE_HXX) && !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CIMAGEREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CIMAGEREADEREVENTSINTERFACE_HXX) && !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cimagepixelinterface.hxx"
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cImageReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/12/2010
 **********************************************************************
 */
typedef cInterfaceBase
cImageReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cImageReaderEventsInterface
 *
 * Author: $author$
 *   Date: 1/12/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cImageReaderEventsInterface
: virtual public cImageReaderEventsInterfaceImplement
{
public:
    typedef cImageReaderEventsInterfaceImplement cImplements;
#else /* !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cImageReaderEvents member functions interface
 */
#define CIMAGEREADEREVENTS_MEMBERS_ONLY
#define CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cimagereaderevents.hxx"
#undef CIMAGEREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CIMAGEREADEREVENTS_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cImageReaderEventsImplement
 *
 * Author: $author$
 *   Date: 1/12/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImageReaderEventsImplement
: virtual public cImageReaderEventsInterface
{
public:
    typedef cImageReaderEventsInterface cImplements;
/* include cImageReaderEvents member functions implement
 */
#define CIMAGEREADEREVENTS_MEMBERS_ONLY
#define CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cimagereaderevents.hxx"
#undef CIMAGEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGEREADEREVENTS_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEREADEREVENTSINTERFACE_HXX) || defined(CIMAGEREADEREVENTSINTERFACE_MEMBERS_ONLY) */
