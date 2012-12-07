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
 *   File: cpngreaderiinterface.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGREADERINTERFACE_HXX) || defined(CPNGREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CPNGREADERINTERFACE_HXX) && !defined(CPNGREADERINTERFACE_MEMBERS_ONLY)
#define _CPNGREADERINTERFACE_HXX
#endif /* !defined(_CPNGREADERINTERFACE_HXX) && !defined(CPNGREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGREADERINTERFACE_MEMBERS_ONLY)
#include "cpngreadereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPNGReaderInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cPNGReaderEventsInterface
cPNGReaderInterfaceImplement;
/**
 **********************************************************************
 *  Class: cPNGReaderInterface
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cPNGReaderInterface
: virtual public cPNGReaderInterfaceImplement
{
public:
    typedef cPNGReaderInterfaceImplement cImplements;
#else /* !defined(CPNGREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CPNGREADERINTERFACE_MEMBERS_ONLY)
};

/**
 **********************************************************************
 *  Class: cPNGReaderImplement
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cPNGReaderImplement
: virtual public cPNGReaderInterface
{
public:
    typedef cPNGReaderInterface cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CPNGREADERINTERFACE_HXX) || defined(CPNGREADERINTERFACE_MEMBERS_ONLY) */
