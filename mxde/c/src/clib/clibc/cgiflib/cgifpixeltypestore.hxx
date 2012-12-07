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
 *   File: cgifpixeltypestore.hxx
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
#if !defined(_CGIFPIXELTYPESTORE_HXX) || defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY)
#if !defined(_CGIFPIXELTYPESTORE_HXX) && !defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY)
#define _CGIFPIXELTYPESTORE_HXX
#endif /* !defined(_CGIFPIXELTYPESTORE_HXX) && !defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY) */

#if !defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY)
#include "cstore.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cGifPixelTypeStoreInterface;
/**
 **********************************************************************
 * Typedef: cGifPixelTypeStoreInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/7/2010
 **********************************************************************
 */
typedef cStoreInterfaceT
<cGifPixelTypeStoreInterface, cGifPixelTypeStreamInterface, GifPixelType>
cGifPixelTypeStoreInterfaceImplements;
/**
 **********************************************************************
 *  Class: cGifPixelTypeStoreInterface
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifPixelTypeStoreInterface
: virtual public cGifPixelTypeStoreInterfaceImplements
{
public:
    typedef cGifPixelTypeStoreInterfaceImplements cImplements;
    typedef cGifPixelTypeStoreInterface cDerives;
};
class c_IMPLEMENT_CLASS  cGifPixelTypeStoreImplement;
/**
 **********************************************************************
 * Typedef: cGifPixelTypeStoreImplementImplements
 *
 *  Author: $author$
 *    Date: 11/7/2010
 **********************************************************************
 */
typedef cStoreImplementT
<cGifPixelTypeStoreImplement, cGifPixelTypeStoreInterface, GifPixelType>
cGifPixelTypeStoreImplementImplements;
/**
 **********************************************************************
 *  Class: cGifPixelTypeStoreImplement
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cGifPixelTypeStoreImplement
: virtual public cGifPixelTypeStoreImplementImplements
{
public:
    typedef cGifPixelTypeStoreImplementImplements cImplements;
    typedef cGifPixelTypeStoreImplement cDerives;
};
class c_INSTANCE_CLASS cGifPixelTypeStore;
/**
 **********************************************************************
 * Typedef: cGifPixelTypeStoreExtends
 *
 *  Author: $author$
 *    Date: 11/7/2010
 **********************************************************************
 */
typedef cStoreT
<cGifPixelTypeStore, 
 cGifPixelTypeStoreImplement,
 cGifPixelTypeStream, GifPixelType>
cGifPixelTypeStoreExtends;
/**
 **********************************************************************
 *  Class: cGifPixelTypeStore
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifPixelTypeStore
: public cGifPixelTypeStoreExtends
{
public:
    typedef cGifPixelTypeStoreExtends cExtends;
    typedef cGifPixelTypeStore cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY) */
#endif /* !defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY) */

#endif /* !defined(_CGIFPIXELTYPESTORE_HXX) || defined(CGIFPIXELTYPESTORE_MEMBERS_ONLY) */
