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
 *   File: ctiffreadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CTIFFREADEREVENTSINTERFACE_HXX) || defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CTIFFREADEREVENTSINTERFACE_HXX) && !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CTIFFREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CTIFFREADEREVENTSINTERFACE_HXX) && !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"
#include "ctiffinterface.hxx"
#include "cimagepixelinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cTIFFReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cInterfaceBase
cTIFFReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cTIFFReaderEventsInterface
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFReaderEventsInterface
: virtual public cTIFFReaderEventsInterfaceImplement
{
public:
    typedef cTIFFReaderEventsInterfaceImplement cExtends;
#else /* !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cTIFFReaderEvents member functions interface
 */
#define CTIFFREADEREVENTS_MEMBERS_ONLY
#define CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "ctiffreaderevents.hxx"
#undef CTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CTIFFREADEREVENTS_MEMBERS_ONLY
};

#if !defined(CTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cTIFFReaderEventsImplement
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTIFFReaderEventsImplement
: virtual public cTIFFReaderEventsInterface
{
public:
    typedef cTIFFReaderEventsInterface cImplements;
#else /* !defined(CTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/* include cTIFFReaderEvents member functions implement
 */
#define CTIFFREADEREVENTS_MEMBERS_ONLY
#define CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "ctiffreaderevents.hxx"
#undef CTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CTIFFREADEREVENTS_MEMBERS_ONLY
};
#else /* !defined(CTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFREADEREVENTSINTERFACE_HXX) || defined(CTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */
