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
 *   File: cwincmdlineparserinterface.hxx
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
#if !defined(_CWINCMDLINEPARSERINTERFACE_HXX) || defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINCMDLINEPARSERINTERFACE_HXX) && !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY)
#define _CWINCMDLINEPARSERINTERFACE_HXX
#endif /* !defined(_CWINCMDLINEPARSERINTERFACE_HXX) && !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY)
#include "cstring.hxx"
#include "ctypes.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinCmdLineParserInterfaceImplement
 *
 *  Author: $author$
 *    Date: 10/6/2010
 **********************************************************************
 */
typedef cInterfaceBase
cWinCmdLineParserInterfaceImplement;
/**
 **********************************************************************
 *  Class: cWinCmdLineParserInterface
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinCmdLineParserInterface
: virtual public cWinCmdLineParserInterfaceImplement
{
public:
    typedef cWinCmdLineParserInterfaceImplement cImplements;
#else /* !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY)
/* include cWinCmdLineParser member functions interface
 */
#define CWINCMDLINEPARSER_MEMBERS_ONLY
#define CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE
#include "cwincmdlineparser.hxx"
#undef CWINCMDLINEPARSER_MEMBER_FUNCS_INTERFACE
#undef CWINCMDLINEPARSER_MEMBERS_ONLY
};

#if !defined(CWINCMDLINEPARSERIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cWinCmdLineParserImplementImplement
 *
 *  Author: $author$
 *    Date: 10/6/2010
 **********************************************************************
 */
typedef cWinCmdLineParserInterface
cWinCmdLineParserImplementImplement;
/**
 **********************************************************************
 *  Class: cWinCmdLineParserImplement
 *
 * Author: $author$
 *   Date: 10/6/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinCmdLineParserImplement
: virtual public cWinCmdLineParserImplementImplement
{
public:
    typedef cWinCmdLineParserImplementImplement cImplements;
#else /* !defined(CWINCMDLINEPARSERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEPARSERIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINCMDLINEPARSERIMPLEMENT_MEMBERS_ONLY)
/* include cWinCmdLineParser member functions implement
 */
#define CWINCMDLINEPARSER_MEMBERS_ONLY
#define CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT
#include "cwincmdlineparser.hxx"
#undef CWINCMDLINEPARSER_MEMBER_FUNCS_IMPLEMENT
#undef CWINCMDLINEPARSER_MEMBERS_ONLY
};
#else /* !defined(CWINCMDLINEPARSERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEPARSERIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINCMDLINEPARSERINTERFACE_HXX) || defined(CWINCMDLINEPARSERINTERFACE_MEMBERS_ONLY) */
