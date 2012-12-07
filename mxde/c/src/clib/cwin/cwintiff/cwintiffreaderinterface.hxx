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
 *   File: cwintiffreaderinterface.hxx
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
#if !defined(_CWINTIFFREADERINTERFACE_HXX) || defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINTIFFREADERINTERFACE_HXX) && !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY)
#define _CWINTIFFREADERINTERFACE_HXX
#endif /* !defined(_CWINTIFFREADERINTERFACE_HXX) && !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY)
#include "cwintiffreadereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinTIFFReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/26/2009
 **********************************************************************
 */
typedef cWinTIFFReaderEventsInterface
cWinTIFFReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cWinTIFFReaderInterface
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinTIFFReaderInterface
: virtual public cWinTIFFReaderInterfaceImplements
{
public:
    typedef cWinTIFFReaderInterfaceImplements cImplements;
#else /* !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY)
/* include cWinTIFFReader member functions interface
 */
#define CWINTIFFREADER_MEMBERS_ONLY
#define CWINTIFFREADER_MEMBER_FUNCS_INTERFACE
#include "cwintiffreader.hxx"
#undef CWINTIFFREADER_MEMBER_FUNCS_INTERFACE
#undef CWINTIFFREADER_MEMBERS_ONLY
};

#if !defined(CWINTIFFREADERIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinTIFFReaderImplement
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinTIFFReaderImplement
: virtual public cWinTIFFReaderInterface
{
public:
    typedef cWinTIFFReaderInterface cImplements;
#else /* !defined(CWINTIFFREADERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADERIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINTIFFREADERIMPLEMENT_MEMBERS_ONLY)
/* include cWinTIFFReader member functions implement
 */
#define CWINTIFFREADER_MEMBERS_ONLY
#define CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT
#include "cwintiffreader.hxx"
#undef CWINTIFFREADER_MEMBER_FUNCS_IMPLEMENT
#undef CWINTIFFREADER_MEMBERS_ONLY
};
#else /* !defined(CWINTIFFREADERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADERIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINTIFFREADERINTERFACE_HXX) || defined(CWINTIFFREADERINTERFACE_MEMBERS_ONLY) */
