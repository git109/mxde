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
 *   File: ctiffreaderinterface.hxx
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
#if !defined(_CTIFFREADERINTERFACE_HXX) || defined(CTIFFREADERINTERFACE_MEMBERS_ONLY)
#if !defined(_CTIFFREADERINTERFACE_HXX) && !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY)
#define _CTIFFREADERINTERFACE_HXX
#endif /* !defined(_CTIFFREADERINTERFACE_HXX) && !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY)
#include "ctiffreadereventsinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cTIFFReaderInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/30/2009
 **********************************************************************
 */
typedef cTIFFReaderEventsInterface
cTIFFReaderInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTIFFReaderInterface
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFReaderInterface
: virtual public cTIFFReaderInterfaceImplements
{
public:
    typedef cTIFFReaderInterfaceImplements cImplements;
#else /* !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY)
};

#if !defined(CTIFFREADERIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cTIFFReaderImplement
 *
 * Author: $author$
 *   Date: 12/30/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTIFFReaderImplement
: virtual public cTIFFReaderInterface
{
public:
    typedef cTIFFReaderInterface cImplements;
#else /* !defined(CTIFFREADERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADERIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CTIFFREADERIMPLEMENT_MEMBERS_ONLY)
};
#else /* !defined(CTIFFREADERIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADERIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFREADERINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFREADERINTERFACE_HXX) || defined(CTIFFREADERINTERFACE_MEMBERS_ONLY) */
