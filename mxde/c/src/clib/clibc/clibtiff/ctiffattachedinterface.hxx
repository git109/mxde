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
 *   File: ctiffattachedinterface.hxx
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
#if !defined(_CTIFFATTACHEDINTERFACE_HXX) || defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY)
#if !defined(_CTIFFATTACHEDINTERFACE_HXX) && !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY)
#define _CTIFFATTACHEDINTERFACE_HXX
#endif /* !defined(_CTIFFATTACHEDINTERFACE_HXX) && !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY)
#include "cattachedinterface.hxx"
#include "tiffio.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cTIFFAttachedInterface;
/**
 **********************************************************************
 * Typedef: cTIFFAttachedInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cAttachedInterfaceT
<cTIFFAttachedInterface, 
 TIFF*, UINT, NULL, cInterfaceBase>
cTIFFAttachedInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTIFFAttachedInterface
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFAttachedInterface
: virtual public cTIFFAttachedInterfaceImplements
{
public:
    typedef cTIFFAttachedInterfaceImplements cImplements;
    typedef cTIFFAttachedInterface cDerives;
#else /* !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY)
};

class c_IMPLEMENT_CLASS cTIFFAttachedImplement;
/**
 **********************************************************************
 * Typedef: cTIFFAttachedImplementImplements
 *
 *  Author: $author$
 *    Date: 12/24/2009
 **********************************************************************
 */
typedef cAttachedImplementT
<cTIFFAttachedImplement, 
 cTIFFAttachedInterface, 
 TIFF*, UINT, NULL>
cTIFFAttachedImplementImplements;
/**
 **********************************************************************
 *  Class: cTIFFAttachedImplement
 *
 * Author: $author$
 *   Date: 12/24/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTIFFAttachedImplement
: virtual public cTIFFAttachedImplementImplements
{
public:
    typedef cTIFFAttachedImplementImplements cImplements;
    typedef cTIFFAttachedImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFATTACHEDINTERFACE_HXX) || defined(CTIFFATTACHEDINTERFACE_MEMBERS_ONLY) */
