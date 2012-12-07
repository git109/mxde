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
 *   File: cbmpreaderinterface.hxx
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
#if !defined(_CBMPREADERINTERFACE_HXX) || defined(CBMPREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CBMPREADERINTERFACE_HXX) && !defined(CBMPREADERINTERFACE_MEMBERS_ONLY)
#define _CBMPREADERINTERFACE_HXX
#endif /* !defined(_CBMPREADERINTERFACE_HXX) && !defined(CBMPREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CBMPREADERINTERFACE_MEMBERS_ONLY)
#include "cbmpreadereventsinterface.hxx"
#include "creaderinterface.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cBMPReaderInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/19/2010
 **********************************************************************
 */
typedef cBMPReaderEventsInterface
cBMPReaderInterfaceImplement;
/**
 **********************************************************************
 *  Class: cBMPReaderInterface
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cBMPReaderInterface
: virtual public cBMPReaderInterfaceImplement
{
public:
    typedef cBMPReaderInterfaceImplement cImplements;
#else /* !defined(CBMPREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CBMPREADERINTERFACE_MEMBERS_ONLY)
/* include cBMPReader member functions interface
 */
#define CBMPREADER_MEMBERS_ONLY
#define CBMPREADER_MEMBER_FUNCS_INTERFACE
#include "cbmpreader.hxx"
#undef CBMPREADER_MEMBER_FUNCS_INTERFACE
#undef CBMPREADER_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cBMPReaderImplement
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cBMPReaderImplement
: virtual public cBMPReaderInterface
{
public:
    typedef cBMPReaderInterface cImplements;
/* include cBMPReader member functions implement
 */
#define CBMPREADER_MEMBERS_ONLY
#define CBMPREADER_MEMBER_FUNCS_IMPLEMENT
#include "cbmpreader.hxx"
#undef CBMPREADER_MEMBER_FUNCS_IMPLEMENT
#undef CBMPREADER_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBMPREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CBMPREADERINTERFACE_HXX) || defined(CBMPREADERINTERFACE_MEMBERS_ONLY) */
