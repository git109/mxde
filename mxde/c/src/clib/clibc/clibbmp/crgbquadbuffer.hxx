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
 *   File: crgbquadbuffer.hxx
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
#if !defined(_CRGBQUADBUFFER_HXX) || defined(CRGBQUADBUFFER_MEMBERS_ONLY)
#if !defined(_CRGBQUADBUFFER_HXX) && !defined(CRGBQUADBUFFER_MEMBERS_ONLY)
#define _CRGBQUADBUFFER_HXX
#endif /* !defined(_CRGBQUADBUFFER_HXX) && !defined(CRGBQUADBUFFER_MEMBERS_ONLY) */

#if !defined(CRGBQUADBUFFER_MEMBERS_ONLY)
#include "cbufferbase.hxx"
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INTERFACE_CLASS cRGBQUADBufferInterface;
/**
 **********************************************************************
 * Typedef: cRGBQUADBufferInterfaceImplements
 *
 *  Author: $author$
 *    Date: 1/19/2010
 **********************************************************************
 */
typedef cBufferBaseInterfaceT
<cRGBQUADBufferInterface, cInterfaceBase, RGBQUAD, UINT>
cRGBQUADBufferInterfaceImplements;
/**
 **********************************************************************
 *  Class: cRGBQUADBufferInterface
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cRGBQUADBufferInterface
: virtual public cRGBQUADBufferInterfaceImplements
{
public:
    typedef cRGBQUADBufferInterfaceImplements cImplements;
    typedef cRGBQUADBufferInterface cDerives;
};
class c_IMPLEMENT_CLASS  cRGBQUADBufferImplement;
/**
 **********************************************************************
 * Typedef: cRGBQUADBufferImplementImplements
 *
 *  Author: $author$
 *    Date: 1/19/2010
 **********************************************************************
 */
typedef cBufferBaseImplementT
<cRGBQUADBufferImplement, cRGBQUADBufferInterface, RGBQUAD, UINT>
cRGBQUADBufferImplementImplements;
/**
 **********************************************************************
 *  Class: cRGBQUADBufferImplement
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS  cRGBQUADBufferImplement
: virtual public cRGBQUADBufferImplementImplements
{
public:
    typedef cRGBQUADBufferImplementImplements cImplements;
    typedef cRGBQUADBufferImplement cDerives;
};
class c_INSTANCE_CLASS cRGBQUADBuffer;
/**
 **********************************************************************
 * Typedef: cRGBQUADBufferExtends
 *
 *  Author: $author$
 *    Date: 1/19/2010
 **********************************************************************
 */
typedef cBufferBaseT
<cRGBQUADBuffer, 
 cRGBQUADBufferImplement,
 cRGBQUADBufferInterface,
 cExportBase, 256, RGBQUAD, UINT>
cRGBQUADBufferExtends;
/**
 **********************************************************************
 *  Class: cRGBQUADBuffer
 *
 * Author: $author$
 *   Date: 1/19/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cRGBQUADBuffer
: public cRGBQUADBufferExtends
{
public:
    typedef cRGBQUADBufferExtends cExtends;
    typedef cRGBQUADBuffer cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CRGBQUADBUFFER_MEMBERS_ONLY) */
#endif /* !defined(CRGBQUADBUFFER_MEMBERS_ONLY) */

#endif /* !defined(_CRGBQUADBUFFER_HXX) || defined(CRGBQUADBUFFER_MEMBERS_ONLY) */
