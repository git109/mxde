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
 *   File: cpnginterfacebase.hxx
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
#if !defined(_CPNGBASEINTERFACE_HXX) || defined(CPNGBASEINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGBASEINTERFACE_HXX) && !defined(CPNGBASEINTERFACE_MEMBERS_ONLY)
#define _CPNGBASEINTERFACE_HXX
#endif /* !defined(_CPNGBASEINTERFACE_HXX) && !defined(CPNGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGBASEINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"
#include "cpng.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPngBaseInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cInterfaceBase
cPngBaseInterfaceImplement;
/**
 **********************************************************************
 *  Class: cPngBaseInterface
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cPngBaseInterface
: virtual public cPngBaseInterfaceImplement
{
public:
    typedef cPngBaseInterfaceImplement cImplements;
#else /* !defined(CPNGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGBASEINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGBASEINTERFACE_MEMBERS_ONLY) 
/* include cPngBase member functions interface
 */
#define CPNGBASE_MEMBERS_ONLY
#define CPNGBASE_MEMBER_FUNCS_INTERFACE
#include "cpngbase.hxx"
#undef CPNGBASE_MEMBER_FUNCS_INTERFACE
#undef CPNGBASE_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cPngBaseImplement
 *
 * Author: $author$
 *   Date: 6/10/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPngBaseImplement
: virtual public cPngBaseInterface
{
public:
    typedef cPngBaseInterface cImplements;
/* include cPngBase member functions implement
 */
#define CPNGBASE_MEMBERS_ONLY
#define CPNGBASE_MEMBER_FUNCS_IMPLEMENT
#include "cpngbase.hxx"
#undef CPNGBASE_MEMBER_FUNCS_IMPLEMENT
#undef CPNGBASE_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGBASEINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGBASEINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGBASEINTERFACE_HXX) || defined(CPNGBASEINTERFACE_MEMBERS_ONLY) */
