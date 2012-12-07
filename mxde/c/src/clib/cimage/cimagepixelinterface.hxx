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
 *   File: cimagepixelinterface.hxx
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
#if !defined(_CIMAGEPIXELINTERFACE_HXX) || defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY)
#if !defined(_CIMAGEPIXELINTERFACE_HXX) && !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY)
#define _CIMAGEPIXELINTERFACE_HXX
#endif /* !defined(_CIMAGEPIXELINTERFACE_HXX) && !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY) */

#if !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY)
#include "cinterfacebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum: eImagePixelValueInterpretation
 *
 * Author: $author$
 *   Date: 1/12/2010
 **********************************************************************
 */
typedef UINT eImagePixelValueInterpretation;
enum
{
    e_IMAGEPIXEL_VALUE_INTERPRETATION_PALETTE = (UINT)(-1),
    
    e_IMAGEPIXEL_VALUE_INTERPRETATION_RGB = 0,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_BGR,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_RGBA,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_BGRA,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_ARGB,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_ABGR,

    e_IMAGEPIXEL_VALUE_INTERPRETATION_NEXT,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_FIRST = e_IMAGEPIXEL_VALUE_INTERPRETATION_RGB,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_LAST = e_IMAGEPIXEL_VALUE_INTERPRETATION_NEXT-1,
    e_IMAGEPIXEL_VALUE_INTERPRETATION_COUNT = e_IMAGEPIXEL_VALUE_INTERPRETATION_LAST-e_IMAGEPIXEL_VALUE_INTERPRETATION_FIRST+1
};

/**
 **********************************************************************
 *   Enum: eImagePixelColorScale
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
typedef UINT eImagePixelColorScale;
enum
{
    e_IMAGEPIXEL_COLOR_SCALE_RGB = 0,
    e_IMAGEPIXEL_COLOR_SCALE_BGR,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA,
    e_IMAGEPIXEL_COLOR_SCALE_BGRA,
    e_IMAGEPIXEL_COLOR_SCALE_ARGB,
    e_IMAGEPIXEL_COLOR_SCALE_ABGR,

    e_IMAGEPIXEL_COLOR_SCALE_NEXT,
    e_IMAGEPIXEL_COLOR_SCALE_FIRST = e_IMAGEPIXEL_COLOR_SCALE_RGB,
    e_IMAGEPIXEL_COLOR_SCALE_LAST = e_IMAGEPIXEL_COLOR_SCALE_NEXT-1,
    e_IMAGEPIXEL_COLOR_SCALES = e_IMAGEPIXEL_COLOR_SCALE_LAST-e_IMAGEPIXEL_COLOR_SCALE_FIRST+1
};

/**
 **********************************************************************
 *   Enum: eImagePixelColorChannel
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
typedef UINT eImagePixelColorChannel;

/**
 **********************************************************************
 *   Enum: eImagePixelColorScaleRGBA
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
typedef eImagePixelColorChannel eImagePixelColorScaleRGBA;
enum
{
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_RED = 0,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_GREEN,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_BLUE,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_ALPHA,

    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_NEXT,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_FIRST = e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_RED,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_LAST = e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_NEXT-1,
    e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNELS = e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_LAST-e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNEL_FIRST+1
};

enum
{
    e_IMAGEPIXEL_COLOR_CHANNELS = e_IMAGEPIXEL_COLOR_SCALE_RGBA_CHANNELS
};

class c_INTERFACE_CLASS cImagePixelInterface;

#undef CDB_CLASS
#define CDB_CLASS "cImagePixelInterfaceT"
/**
 **********************************************************************
 *  Class: cImagePixelInterfaceT
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
template
<class TDerives=cImagePixelInterface,
 class TImagePixelInterfaceImplement=cInterfaceBase,
 class TColorSample=UINT,
 class TColorScale=eImagePixelColorScale,
 TColorScale VColorScale=e_IMAGEPIXEL_COLOR_SCALE_RGBA,
 TColorScale VColorScales=e_IMAGEPIXEL_COLOR_SCALES,
 class TColorChannel=eImagePixelColorChannel,
 TColorChannel VColorChannels=e_IMAGEPIXEL_COLOR_CHANNELS,
 class TImplements=TImagePixelInterfaceImplement>

class c_INTERFACE_CLASS cImagePixelInterfaceT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
    typedef TDerives cDerives;
    typedef TDerives TImagePixelInterface;
#else /* !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY) */

    typedef TColorSample tColorSample;
    typedef TColorScale tColorScale;
    enum { vColorScale = VColorScale };
    typedef TColorChannel tColorChannel;
    enum { vColorChannels = VColorChannels };
    
#if !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY)
/* include cImagePixel member functions interface
 */
#define CIMAGEPIXEL_MEMBERS_ONLY
#define CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE
#include "cimagepixel.hxx"
#undef CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE
#undef CIMAGEPIXEL_MEMBERS_ONLY
};
#undef CDB_CLASS

class c_IMPLEMENT_CLASS cImagePixelImplement;

#undef CDB_CLASS
#define CDB_CLASS "cImagePixelImplementT"

/**
 **********************************************************************
 *  Class: cImagePixelImplementT
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
template
<class TDerives=cImagePixelImplement,
 class TImagePixelInterface=cImagePixelInterface,
 class TColorSample=UINT,
 class TColorScale=eImagePixelColorScale,
 TColorScale VColorScale=e_IMAGEPIXEL_COLOR_SCALE_RGBA,
 TColorScale VColorScales=e_IMAGEPIXEL_COLOR_SCALES,
 class TColorChannel=eImagePixelColorChannel,
 TColorChannel VColorChannels=e_IMAGEPIXEL_COLOR_CHANNELS,
 class TImplements=TImagePixelInterface>

class c_IMPLEMENT_CLASS cImagePixelImplementT
: virtual public TImplements
{
public:
    typedef TImplements cImplements;
/* include cImagePixel interface member definitions
 */
#define CIMAGEPIXELINTERFACE_MEMBERS_ONLY
#include "cimagepixelinterface.hxx"
#undef CIMAGEPIXELINTERFACE_MEMBERS_ONLY

/* include cImagePixel member functions implement
 */
#define CIMAGEPIXEL_MEMBERS_ONLY
#define CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT
#include "cimagepixel.hxx"
#undef CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT
#undef CIMAGEPIXEL_MEMBERS_ONLY
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImagePixelInterfaceImplement
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cImagePixelInterfaceT<>
cImagePixelInterfaceImplement;
/**
 **********************************************************************
 *  Class: cImagePixelInterface
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_INTERFACE_CLASS cImagePixelInterface
: virtual public cImagePixelInterfaceImplement
{
public:
    typedef cImagePixelInterfaceImplement cImplements;
    typedef cImagePixelInterface cDerives;
};

/**
 **********************************************************************
 * Typedef: cImagePixelImplementImplement
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cImagePixelImplementT<>
cImagePixelImplementImplement;
/**
 **********************************************************************
 *  Class: cImagePixelImplement
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_IMPLEMENT_CLASS cImagePixelImplement
: virtual public cImagePixelImplementImplement
{
public:
    typedef cImagePixelImplementImplement cImplements;
    typedef cImagePixelImplement cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEPIXELINTERFACE_HXX) || defined(CIMAGEPIXELINTERFACE_MEMBERS_ONLY) */
