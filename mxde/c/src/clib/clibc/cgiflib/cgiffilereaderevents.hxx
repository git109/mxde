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
 *   File: cgiffilereaderevents.hxx
 *
 * Author: $author$
 *   Date: 11/10/2010
 **********************************************************************
 */
#if !defined(_CGIFFILEREADEREVENTS_HXX) || defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CGIFFILEREADEREVENTS_HXX) && !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY)
#define _CGIFFILEREADEREVENTS_HXX
#endif /* !defined(_CGIFFILEREADEREVENTS_HXX) && !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY)
#include "cgiffilereadereventsinterface.hxx"
#include "cgiffileinterface.hxx"
#include "cdelegated.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cGifFileReaderEvents;
/**
 **********************************************************************
 * Typedef: cGifFileReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 11/10/2010
 **********************************************************************
 */
typedef cDelegatedT
<cGifFileReaderEvents,
 cGifFileReaderEventsImplement,
 cGifFileReaderEventsInterface>
cGifFileReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cGifFileReaderEvents
 *
 * Author: $author$
 *   Date: 11/10/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cGifFileReaderEvents
: virtual public cGifFileReaderEventsImplement,
  public cGifFileReaderEventsExtend
{
public:
    typedef cGifFileReaderEventsImplement cImplements;
    typedef cGifFileReaderEventsExtend cExtends;

    /**
     **********************************************************************
     *  Constructor: cGifFileReaderEvents
     *
     *       Author: $author$
     *         Date: 11/10/2010
     **********************************************************************
     */
    cGifFileReaderEvents
    (tDelegated* delegated=0)
    : cExtends(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cGifFileReaderEvents
     *
     *      Author: $author$
     *        Date: 11/10/2010
     **********************************************************************
     */
    virtual ~cGifFileReaderEvents()
    {
    }
#else /* !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnGifImage
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBeginGifImage
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnBeginGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndGifImage
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnEndGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnGifLine
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBeginGifLine
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnBeginGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndGifLine
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnEndGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnGifColumn
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnGifColumn
            (pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBeginGifColumn
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnBeginGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnBeginGifColumn
            (pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndGifColumn
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnEndGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnEndGifColumn
            (pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnGifPixelColor
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifPixelColor
    (GifColorType& color,GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnGifPixelColor
            (color, pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnGifPixel
     *
     *   Author: $author$
     *     Date: 11/10/2010
     **********************************************************************
     */
    virtual eError OnGifPixel
    (cImagePixelInterface& pixel,
     GifColorType& color,GifPixelType& columnPixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
#if defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            return delegated->OnGifPixel
            (pixel, color, columnPixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
#if !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CGIFFILEREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
#if !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CGIFFILEREADEREVENTS_HXX) || defined(CGIFFILEREADEREVENTS_MEMBERS_ONLY) */
