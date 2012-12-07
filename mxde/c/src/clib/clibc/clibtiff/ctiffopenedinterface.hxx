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
 *   File: ctiffopenedinterface.hxx
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
#if !defined(_CTIFFOPENEDINTERFACE_HXX) || defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CTIFFOPENEDINTERFACE_HXX) && !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY)
#define _CTIFFOPENEDINTERFACE_HXX
#endif /* !defined(_CTIFFOPENEDINTERFACE_HXX) && !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY)
#include "ctiffattachedinterface.hxx"
#include "copenedinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cTIFFOpenedInterface;
/**
 **********************************************************************
 * Typedef: cTIFFOpenedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cOpenedInterfaceT
<cTIFFOpenedInterface, cTIFFAttachedInterface>
cTIFFOpenedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTIFFOpenedInterface
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFOpenedInterface
: virtual public cTIFFOpenedInterfaceImplements
{
public:
    typedef cTIFFOpenedInterfaceImplements cImplements;
    typedef cTIFFOpenedInterface cDerives;
#else /* !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY)
};

class c_EXPORT_CLASS cTIFFOpenedImplement;
/**
 **********************************************************************
 * Typedef: cTIFFOpenedImplementImplements
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cOpenedImplementT
<cTIFFOpenedImplement, cTIFFOpenedInterface>
cTIFFOpenedImplementImplements;
/**
 **********************************************************************
 *  Class: cTIFFOpenedImplement
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cTIFFOpenedImplement
: virtual public cTIFFOpenedImplementImplements
{
public:
    typedef cTIFFOpenedImplementImplements cImplements;
    typedef cTIFFOpenedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFOPENEDINTERFACE_HXX) || defined(CTIFFOPENEDINTERFACE_MEMBERS_ONLY) */
