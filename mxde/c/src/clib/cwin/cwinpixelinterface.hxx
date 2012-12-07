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
 *   File: cwinpixelinterface.hxx
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
#if !defined(_CWINPIXELINTERFACE_HXX) || defined(CWINPIXELINTERFACE_MEMBERS_ONLY)
#if !defined(_CWINPIXELINTERFACE_HXX) && !defined(CWINPIXELINTERFACE_MEMBERS_ONLY)
#define _CWINPIXELINTERFACE_HXX
#endif /* !defined(_CWINPIXELINTERFACE_HXX) && !defined(CWINPIXELINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINPIXELINTERFACE_MEMBERS_ONLY)
#include "cwinpbyteattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWinPixelInterface
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cWinPixelInterface
: virtual public cWinPBYTEAttachedInterface
{
public:
    typedef cWinPBYTEAttachedInterface cImplements;
#else /* !defined(CWINPIXELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINPIXELINTERFACE_MEMBERS_ONLY) */

#if !defined(CWINPIXELINTERFACE_MEMBERS_ONLY)
/* include cWinPixel member functions interface
 */
#define CWINPIXEL_MEMBERS_ONLY
#define CWINPIXEL_MEMBER_FUNCS_INTERFACE
#include "cwinpixel.hxx"
#undef CWINPIXEL_MEMBER_FUNCS_INTERFACE
#undef CWINPIXEL_MEMBERS_ONLY
};

#if !defined(CWINPIXELIMPLEMENT_MEMBERS_ONLY)
/**
 **********************************************************************
 *  Class: cWinPixelImplement
 *
 * Author: $author$
 *   Date: 12/14/2009
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cWinPixelImplement
: virtual public cWinPixelInterface
{
public:
    typedef cWinPixelInterface cImplements;
#else /* !defined(CWINPIXELIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINPIXELIMPLEMENT_MEMBERS_ONLY) */

#if !defined(CWINPIXELIMPLEMENT_MEMBERS_ONLY)
/* include cWinPixel member functions implement
 */
#define CWINPIXEL_MEMBERS_ONLY
#define CWINPIXEL_MEMBER_FUNCS_IMPLEMENT
#include "cwinpixel.hxx"
#undef CWINPIXEL_MEMBER_FUNCS_IMPLEMENT
#undef CWINPIXEL_MEMBERS_ONLY
};
#else /* !defined(CWINPIXELIMPLEMENT_MEMBERS_ONLY) */
#endif /* !defined(CWINPIXELIMPLEMENT_MEMBERS_ONLY) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINPIXELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CWINPIXELINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CWINPIXELINTERFACE_HXX) || defined(CWINPIXELINTERFACE_MEMBERS_ONLY) */
