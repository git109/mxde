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
 *   File: cgifpixeltypebuffer.hxx
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
#if !defined(_CGIFPIXELTYPEBUFFER_HXX) || defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY)
#if !defined(_CGIFPIXELTYPEBUFFER_HXX) && !defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY)
#define _CGIFPIXELTYPEBUFFER_HXX
#endif /* !defined(_CGIFPIXELTYPEBUFFER_HXX) && !defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY) */

#if !defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY)
#include "cbuffer.hxx"
#include "gif_lib.h"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */


class c_INTERFACE_CLASS cGifPixelTypeBufferInterface;
/**
 **********************************************************************
 * Typedef: cGifPixelTypeBufferInterfaceImplements
 *
 *  Author: $author$
 *    Date: 11/7/2010
 **********************************************************************
 */
typedef cBufferInterfaceT
<cGifPixelTypeBufferInterface, cInterfaceBase, GifPixelType>
cGifPixelTypeBufferInterfaceImplements;
/**
 **********************************************************************
 *  Class: cGifPixelTypeBufferInterface
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cGifPixelTypeBufferInterface
: virtual public cGifPixelTypeBufferInterfaceImplements
{
public:
    typedef cGifPixelTypeBufferInterfaceImplements cImplements;
    typedef cGifPixelTypeBufferInterface cDerives;
};
class c_IMPLEMENT_CLASS  cGifPixelTypeBufferImplement;
/**
 **********************************************************************
 * Typedef: cGifPixelTypeBufferImplementImplements
 *
 *  Author: $author$
 *    Date: 11/7/2010
 **********************************************************************
 */
typedef cBufferImplementT
<cGifPixelTypeBufferImplement, cGifPixelTypeBufferInterface, GifPixelType>
cGifPixelTypeBufferImplementImplements;
/**
 **********************************************************************
 *  Class: cGifPixelTypeBufferImplement
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cGifPixelTypeBufferImplement
: virtual public cGifPixelTypeBufferImplementImplements
{
public:
    typedef cGifPixelTypeBufferImplementImplements cImplements;
    typedef cGifPixelTypeBufferImplement cDerives;
};
class c_INSTANCE_CLASS cGifPixelTypeBuffer;
/**
 **********************************************************************
 * Typedef: cGifPixelTypeBufferExtends
 *
 *  Author: $author$
 *    Date: 11/7/2010
 **********************************************************************
 */
typedef cBufferT
<cGifPixelTypeBuffer, 
 cGifPixelTypeBufferImplement,
 cGifPixelTypeBufferInterface,
 cBase, GifPixelType>
cGifPixelTypeBufferExtends;
/**
 **********************************************************************
 *  Class: cGifPixelTypeBuffer
 *
 * Author: $author$
 *   Date: 11/7/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifPixelTypeBuffer
: public cGifPixelTypeBufferExtends
{
public:
    typedef cGifPixelTypeBufferExtends cExtends;
    typedef cGifPixelTypeBuffer cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY) */
#endif /* !defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY) */

#endif /* !defined(_CGIFPIXELTYPEBUFFER_HXX) || defined(CGIFPIXELTYPEBUFFER_MEMBERS_ONLY) */
