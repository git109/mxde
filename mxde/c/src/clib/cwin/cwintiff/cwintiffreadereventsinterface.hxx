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
 *   File: cwintiffreadereventsinterface.hxx
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
#if !defined(_CWINTIFFREADEREVENTSINTERFACE_HXX) || defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINTIFFREADEREVENTSINTERFACE_HXX) && !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
#define _CWINTIFFREADEREVENTSINTERFACE_HXX
#endif /* !defined(_CWINTIFFREADEREVENTSINTERFACE_HXX) && !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
#include "ctiffreaderinterface.hxx"
#include "cwinpixelinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinTIFFReaderEventsInterfaceImplement
 *
 *  Author: $author$
 *    Date: 12/26/2009
 **********************************************************************
 */
typedef cTIFFReaderEventsInterface
cWinTIFFReaderEventsInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinTIFFReaderEventsInterface
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinTIFFReaderEventsInterface
: virtual public cWinTIFFReaderEventsInterfaceImplement
{
public:
    typedef cWinTIFFReaderEventsInterfaceImplement cImplements;
#else /* !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY)
/* include cWinTIFFReaderEvents member functions interface
 */
#define CWINTIFFREADEREVENTS_MEMBERS_ONLY
#define CWINTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE
#include "cwintiffreaderevents.hxx"
#undef CWINTIFFREADEREVENTS_MEMBER_FUNCS_INTERFACE
#undef CWINTIFFREADEREVENTS_MEMBERS_ONLY
};

#if !defined(CWINTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinTIFFReaderEventsImplement
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinTIFFReaderEventsImplement
: virtual public cTIFFReaderEventsImplement,
  virtual public cWinTIFFReaderEventsInterface
{
public:
    typedef cWinTIFFReaderEventsInterface cImplements;
#else /* !defined(CWINTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY)
/* include cWinTIFFReaderEvents member functions implement
 */
#define CWINTIFFREADEREVENTS_MEMBERS_ONLY
#define CWINTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#include "cwintiffreaderevents.hxx"
#undef CWINTIFFREADEREVENTS_MEMBER_FUNCS_IMPLEMENT
#undef CWINTIFFREADEREVENTS_MEMBERS_ONLY
};
#else /* !defined(CWINTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADEREVENTSIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINTIFFREADEREVENTSINTERFACE_HXX) || defined(CWINTIFFREADEREVENTSINTERFACE_MEMBERS_ONLY) */
