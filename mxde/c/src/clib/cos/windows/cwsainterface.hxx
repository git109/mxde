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
 *   File: cwsainterface.hxx
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
#if !defined(_CWSAINTERFACE_HXX) || defined(CWSAINTERFACE_MEMBERS_ONLY)
#if !defined(_CWSAINTERFACE_HXX) && !defined(CWSAINTERFACE_MEMBERS_ONLY)
#define _CWSAINTERFACE_HXX
#endif /* !defined(_CWSAINTERFACE_HXX) && !defined(CWSAINTERFACE_MEMBERS_ONLY) */

#if !defined(CWSAINTERFACE_MEMBERS_ONLY)
#include "cplatform_socket.h"
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWSAInterface
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cWSAInterface
: virtual public cInterfaceBase
{
public:
    typedef cInterfaceBase cImplements;
#else /* !defined(CWSAINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWSAINTERFACE_MEMBERS_ONLY) */

#if !defined(CWSAINTERFACE_MEMBERS_ONLY)
/* include cWSA member functions interface
 */
#define CWSA_MEMBERS_ONLY
#define CWSA_MEMBER_FUNCS_INTERFACE
#include "cwsa.hxx"
#undef CWSA_MEMBER_FUNCS_INTERFACE
#undef CWSA_MEMBERS_ONLY
};

/**
 **********************************************************************
 *  Class: cWSAImplement
 *
 * Author: $author$
 *   Date: 3/3/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWSAImplement
: virtual public cWSAInterface
{
public:
    typedef cWSAInterface cImplements;

/* include cWSA member functions implement
 */
#define CWSA_MEMBERS_ONLY
#define CWSA_MEMBER_FUNCS_IMPLEMENT
#include "cwsa.hxx"
#undef CWSA_MEMBER_FUNCS_IMPLEMENT
#undef CWSA_MEMBERS_ONLY
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWSAINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWSAINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWSAINTERFACE_HXX) || defined(CWSAINTERFACE_MEMBERS_ONLY) */
