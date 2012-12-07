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
 *   File: csemaphoreinterface.hxx
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
#if !defined(_CSEMAPHOREINTERFACE_HXX) || defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
#if !defined(_CSEMAPHOREINTERFACE_HXX) && !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
#define _CSEMAPHOREINTERFACE_HXX
#endif /* !defined(_CSEMAPHOREINTERFACE_HXX) && !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) */

#if !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
#include "csemaphoreattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cSemaphoreInterfaceImplement
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cSEMAPHORECreatedInterface
cSemaphoreInterfaceImplement;
/**
 **********************************************************************
 *  Class: cSemaphoreInterface
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cSemaphoreInterface
: virtual public cSemaphoreInterfaceImplement
{
public:
    typedef cSemaphoreInterfaceImplement cImplements;
#else /* !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) */

#if !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY)
/* include cSemaphore member functions interface
 */
#define CSEMAPHORE_MEMBERS_ONLY
#define CSEMAPHORE_MEMBER_FUNCS_INTERFACE
#include "csemaphore.hxx"
#undef CSEMAPHORE_MEMBER_FUNCS_INTERFACE
#undef CSEMAPHORE_MEMBERS_ONLY
};

#if !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 * Typedef: cSemaphoreImplementImplement
 *
 *  Author: $author$
 *    Date: 10/24/2010
 **********************************************************************
 */
typedef cSemaphoreInterface
cSemaphoreImplementImplement;
/**
 **********************************************************************
 *  Class: cSemaphoreImplement
 *
 * Author: $author$
 *   Date: 10/24/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cSemaphoreImplement
: virtual public cSemaphoreImplementImplement
{
public:
    typedef cSemaphoreImplementImplement cImplements;
#else /* !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY)
/* include cSemaphore member functions implement
 */
#define CSEMAPHORE_MEMBERS_ONLY
#define CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT
#include "csemaphore.hxx"
#undef CSEMAPHORE_MEMBER_FUNCS_IMPLEMENT
#undef CSEMAPHORE_MEMBERS_ONLY
};
#else /* !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHOREIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CSEMAPHOREINTERFACE_HXX) || defined(CSEMAPHOREINTERFACE_MEMBERS_ONLY) */
