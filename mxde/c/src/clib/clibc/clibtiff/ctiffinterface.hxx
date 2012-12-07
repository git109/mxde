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
 *   File: ctiffinterface.hxx
 *
 * Author: $author$
 *   Date: 12/25/2009
 **********************************************************************
 */
#if !defined(_CTIFFINTERFACE_HXX) || defined(CTIFFINTERFACE_MEMBERS_ONLY)
#if !defined(_CTIFFINTERFACE_HXX) && !defined(CTIFFINTERFACE_MEMBERS_ONLY)
#define _CTIFFINTERFACE_HXX
#endif /* !defined(_CTIFFINTERFACE_HXX) && !defined(CTIFFINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFINTERFACE_MEMBERS_ONLY)
#include "ctiffopenedinterface.hxx"
#include "cfileinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum:  eTIFFPhotometricInterpretation
 *
 * Author: $author$
 *   Date: 12/26/2009
 **********************************************************************
 */
typedef int eTIFFPhotometricInterpretation;
enum
{
    e_TIFF_PHOTOMETRIC_RGB     = 2,
    e_TIFF_PHOTOMETRIC_PALETTE = 3,
};

/**
 **********************************************************************
 * Typedef: cTIFFInterfaceImplements
 *
 *  Author: $author$
 *    Date: 12/25/2009
 **********************************************************************
 */
typedef cTIFFOpenedInterface
cTIFFInterfaceImplements;
/**
 **********************************************************************
 *  Class: cTIFFInterface
 *
 * Author: $author$
 *   Date: 12/25/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTIFFInterface
: virtual public cTIFFInterfaceImplements
{
public:
    typedef cTIFFInterfaceImplements cImplements;
#else /* !defined(CTIFFINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFINTERFACE_MEMBERS_ONLY) */

#if !defined(CTIFFINTERFACE_MEMBERS_ONLY)
/* include cTIFF member functions interface
 */
#define CTIFF_MEMBERS_ONLY
#define CTIFF_MEMBER_FUNCS_INTERFACE
#include "ctiff.hxx"
#undef CTIFF_MEMBER_FUNCS_INTERFACE
#undef CTIFF_MEMBERS_ONLY
};

#if !defined(CTIFFIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cTIFFImplement
 *
 * Author: $author$
 *   Date: 12/25/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cTIFFImplement
: virtual public cTIFFInterface
{
public:
    typedef cTIFFInterface cImplements;
#else /* !defined(CTIFFIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTIFFIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CTIFFIMPLEMENT_MEMBERS_ONLY)
/* include cTIFF member functions implement
 */
#define CTIFF_MEMBERS_ONLY
#define CTIFF_MEMBER_FUNCS_IMPLEMENT
#include "ctiff.hxx"
#undef CTIFF_MEMBER_FUNCS_IMPLEMENT
#undef CTIFF_MEMBERS_ONLY
};
#else /* !defined(CTIFFIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CTIFFIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CTIFFINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CTIFFINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CTIFFINTERFACE_HXX) || defined(CTIFFINTERFACE_MEMBERS_ONLY) */
