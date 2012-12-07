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
 *   File: cpnginforeaderinterface.hxx
 *
 * Author: $author$
 *   Date: 1/15/2010
 **********************************************************************
 */
#if !defined(_CPNGINFOREADERINTERFACE_HXX) || defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGINFOREADERINTERFACE_HXX) && !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY)
#define _CPNGINFOREADERINTERFACE_HXX
#endif /* !defined(_CPNGINFOREADERINTERFACE_HXX) && !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY)
#include "cpnginfointerface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPngInfoReaderInterface
 *
 * Author: $author$
 *   Date: 1/15/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngInfoReaderInterface
: virtual public cPngInfoInterface
{
public:
    typedef cPngInfoInterface cImplements;
#else /* !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY)
/* include cPngInfoReader member functions interface
 */
#define CPNGINFOREADER_MEMBERS_ONLY
#define CPNGINFOREADER_MEMBER_FUNCS_INTERFACE
#include "cpnginforeader.hxx"
#undef CPNGINFOREADER_MEMBER_FUNCS_INTERFACE
#undef CPNGINFOREADER_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cPngInfoReaderImplement
 *
 * Author: $author$
 *   Date: 1/15/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPngInfoReaderImplement
: virtual public cPngInfoReaderInterface
{
public:
    typedef cPngInfoReaderInterface cImplements;
/* include cPngInfoReader member functions implement
 */
#define CPNGINFOREADER_MEMBERS_ONLY
#define CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT
#include "cpnginforeader.hxx"
#undef CPNGINFOREADER_MEMBER_FUNCS_IMPLEMENT
#undef CPNGINFOREADER_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGINFOREADERINTERFACE_HXX) || defined(CPNGINFOREADERINTERFACE_MEMBERS_ONLY) */
