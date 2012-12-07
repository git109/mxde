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
 *   File: cimagepixel.hxx
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
#if !defined(_CIMAGEPIXEL_HXX) || defined(CIMAGEPIXEL_MEMBERS_ONLY)
#if !defined(_CIMAGEPIXEL_HXX) && !defined(CIMAGEPIXEL_MEMBERS_ONLY)
#define _CIMAGEPIXEL_HXX
#endif /* !defined(_CIMAGEPIXEL_HXX) && !defined(CIMAGEPIXEL_MEMBERS_ONLY) */

#if !defined(CIMAGEPIXEL_MEMBERS_ONLY)
#include "cimagepixelinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cImagePixel;

#undef CDB_CLASS
#define CDB_CLASS "cImagePixelT"
/**
 **********************************************************************
 *  Class: cImagePixelT
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
template
<class TDerives=cImagePixel,
 class TImagePixelImplement=cImagePixelImplement,
 class TImagePixelExtend=cInstanceBase,
 class TColorSample=UINT,
 class TColorScale=eImagePixelColorScale,
 TColorScale VColorScale=e_IMAGEPIXEL_COLOR_SCALE_RGBA,
 TColorScale VColorScales=e_IMAGEPIXEL_COLOR_SCALES,
 class TColorChannel=eImagePixelColorChannel,
 TColorChannel VColorChannels=e_IMAGEPIXEL_COLOR_CHANNELS,
 class TImplements=TImagePixelImplement,
 class TExtends=TImagePixelExtend>

class c_INSTANCE_CLASS cImagePixelT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TDerives cDerives;
    
/* include cImagePixel interface member definitions
 */
#define CIMAGEPIXELINTERFACE_MEMBERS_ONLY
#include "cimagepixelinterface.hxx"
#undef CIMAGEPIXELINTERFACE_MEMBERS_ONLY

    tColorScale m_colorScale;
    tColorChannel m_colorChannels;
    tColorChannel m_channel[vColorChannels];
    
    /**
     **********************************************************************
     *  Constructor: cImagePixelT
     *
     *       Author: $author$
     *         Date: 1/10/2010
     **********************************************************************
     */
    cImagePixelT
    (tColorChannel channel0=0,
     tColorChannel channel1=0,
     tColorChannel channel2=0,
     tColorChannel channel3=0,
     tColorScale colorScale=vColorScale,
     UINT colorChannels=vColorChannels)
    : m_colorScale(colorScale),
      m_colorChannels(colorChannels)
    {
        m_channel[0] = channel0;
        m_channel[1] = channel1;
        m_channel[2] = channel2;
        m_channel[3] = channel3;
    }
    /**
     **********************************************************************
     *  Destructor: ~cImagePixelT
     *
     *      Author: $author$
     *        Date: 1/10/2010
     **********************************************************************
     */
    virtual ~cImagePixelT()
    {
    }
#else /* !defined(CIMAGEPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPIXEL_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: SetRed
     *
     *   Author: $author$
     *     Date: 1/23/2010
     **********************************************************************
     */
    virtual tColorSample SetRed
    (tColorSample toValue) 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = RedColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = (m_channel[colorChannel] = toValue);
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */

        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetGreen
     *
     *   Author: $author$
     *     Date: 1/23/2010
     **********************************************************************
     */
    virtual tColorSample SetGreen
    (tColorSample toValue) 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = GreenColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = (m_channel[colorChannel] = toValue);
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetBlue
     *
     *   Author: $author$
     *     Date: 1/23/2010
     **********************************************************************
     */
    virtual tColorSample SetBlue
    (tColorSample toValue) 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = BlueColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = (m_channel[colorChannel] = toValue);
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetAlpha
     *
     *   Author: $author$
     *     Date: 1/23/2010
     **********************************************************************
     */
    virtual tColorSample SetAlpha
    (tColorSample toValue) 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = AlphaColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = (m_channel[colorChannel] = toValue);
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Red
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorSample Red() const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = RedColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = m_channel[colorChannel];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Green
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorSample Green() const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = GreenColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = m_channel[colorChannel];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Blue
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorSample Blue() const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = BlueColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = m_channel[colorChannel];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Alpha
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorSample Alpha() const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorSample colorSample = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        tColorChannel colorChannel = AlphaColorChannel(m_colorScale);
        if ((0 <= colorChannel) && (colorChannel < vColorChannels))
            colorSample = m_channel[colorChannel];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorSample;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: RedColorChannel
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorChannel RedColorChannel
    (tColorScale colorScale) const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorChannel colorChannel = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT)
        static tColorChannel thisColorChannel[e_IMAGEPIXEL_COLOR_SCALES] =
        { 0,2,0,2,1,3 };
        if ((0 <= colorScale) && (e_IMAGEPIXEL_COLOR_SCALES > colorScale))
            colorChannel = thisColorChannel[colorScale];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorChannel;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: GreenColorChannel
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorChannel GreenColorChannel
    (tColorScale colorScale) const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorChannel colorChannel = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        static tColorChannel thisColorChannel[e_IMAGEPIXEL_COLOR_SCALES] =
        { 1,1,1,1,2,2 };
        if ((0 <= colorScale) && (e_IMAGEPIXEL_COLOR_SCALES > colorScale))
            colorChannel = thisColorChannel[colorScale];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorChannel;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BlueColorChannel
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorChannel BlueColorChannel
    (tColorScale colorScale) const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorChannel colorChannel = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        static tColorChannel thisColorChannel[e_IMAGEPIXEL_COLOR_SCALES] =
        { 2,0,2,0,3,1 };
        if ((0 <= colorScale) && (e_IMAGEPIXEL_COLOR_SCALES > colorScale))
            colorChannel = thisColorChannel[colorScale];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorChannel;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: AlphaColorChannel
     *
     *   Author: $author$
     *     Date: 1/10/2010
     **********************************************************************
     */
    virtual tColorChannel AlphaColorChannel
    (tColorScale colorScale) const 
#if defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */
    {
        tColorChannel colorChannel = 0;
#if !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) 
        static tColorChannel thisColorChannel[e_IMAGEPIXEL_COLOR_SCALES] =
        { 3,3,3,3,0,0 };
        if ((0 <= colorScale) && (e_IMAGEPIXEL_COLOR_SCALES > colorScale))
            colorChannel = thisColorChannel[colorScale];
#else /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CIMAGEPIXEL_MEMBER_FUNCS_IMPLEMENT) */
        return colorChannel;
    }
#endif /* defined(CIMAGEPIXEL_MEMBER_FUNCS_INTERFACE) */

#if !defined(CIMAGEPIXEL_MEMBERS_ONLY)
};
#undef CDB_CLASS

/**
 **********************************************************************
 * Typedef: cImagePixelExtend
 *
 *  Author: $author$
 *    Date: 1/10/2010
 **********************************************************************
 */
typedef cImagePixelT
<cImagePixel, cImagePixelImplement, cInstanceBase,
 UINT, eImagePixelColorScale, e_IMAGEPIXEL_COLOR_SCALE_RGBA>
cImagePixelExtend;
/**
 **********************************************************************
 *  Class: cImagePixel
 *
 * Author: $author$
 *   Date: 1/10/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cImagePixel
: public cImagePixelExtend
{
public:
    typedef cImagePixelExtend cExtends;
    typedef cImagePixel cDerives;
    /**
     **********************************************************************
     * Constructor: cImagePixel
     *
     *      Author: $author$
     *        Date: 1/10/2010
     **********************************************************************
     */
    cImagePixel
    (tColorSample red=0,
     tColorSample green=0,
     tColorSample blue=0,
     tColorSample alpha=0)
    : cExtends(red, green, blue, alpha)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cImagePixel
     *
     *     Author: $author$
     *       Date: 1/10/2010
     **********************************************************************
     */
    virtual ~cImagePixel()
    {
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CIMAGEPIXEL_MEMBERS_ONLY) */
#endif /* !defined(CIMAGEPIXEL_MEMBERS_ONLY) */

#endif /* !defined(_CIMAGEPIXEL_HXX) || defined(CIMAGEPIXEL_MEMBERS_ONLY) */
