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
 *   File: cjpegreaderevents.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#if !defined(_CJPEGREADEREVENTS_HXX) || defined(CJPEGREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CJPEGREADEREVENTS_HXX) && !defined(CJPEGREADEREVENTS_MEMBERS_ONLY)
#define _CJPEGREADEREVENTS_HXX
#endif /* !defined(_CJPEGREADEREVENTS_HXX) && !defined(CJPEGREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CJPEGREADEREVENTS_MEMBERS_ONLY)
#include "cjpegreadereventsinterface.hxx"
#include "cjpegbase.hxx"
#include "cdelegated.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_INSTANCE_CLASS cJPEGReaderEvents;
/**
 **********************************************************************
 * Typedef: cJPEGReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cDelegatedT
<cJPEGReaderEvents,
 cJPEGReaderEventsImplement,
 cJPEGReaderEventsInterface,
 cJPEGReaderEventsInterface,
 cJPEGBase>
cJPEGReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cJPEGReaderEvents
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cJPEGReaderEvents
: virtual public cJPEGReaderEventsImplement,
  public cJPEGReaderEventsExtend
{
public:
    typedef cJPEGReaderEventsImplement cImplements;
    typedef cJPEGReaderEventsExtend cExtends;
    /**
     **********************************************************************
     *  Constructor: cJPEGReaderEvents
     *
     *       Author: $author$
     *         Date: 11/13/2010
     **********************************************************************
     */
    cJPEGReaderEvents
    (tDelegated* delegated=0) 
    : cExtends(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cJPEGReaderEvents
     *
     *      Author: $author$
     *        Date: 11/13/2010
     **********************************************************************
     */
    virtual ~cJPEGReaderEvents()
    {
    }
#else /* !defined(CJPEGREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnJPEGImage
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnJPEGImage
    (JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnJPEGImage
            (outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBeginJPEGImage
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnBeginJPEGImage
    (JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnBeginJPEGImage
            (outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndJPEGImage
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnEndJPEGImage
    (JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnEndJPEGImage
            (outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnJPEGSampleRow
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnJPEGSampleRow
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnJPEGSampleRow
            (samples, samplesSize, samplesRow, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBeginJPEGSampleRow
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnBeginJPEGSampleRow
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnBeginJPEGSampleRow
            (samples, samplesSize, samplesRow, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndJPEGSampleRow
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnEndJPEGSampleRow
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnEndJPEGSampleRow
            (samples, samplesSize, samplesRow, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnJPEGSampleCol
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnJPEGSampleCol
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnJPEGSampleCol
            (samples, samplesSize, samplesRow, samplesCol, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBeginJPEGSampleCol
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnBeginJPEGSampleCol
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnBeginJPEGSampleCol
            (samples, samplesSize, samplesRow, samplesCol, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndJPEGSampleCol
     *
     *   Author: $author$
     *     Date: 11/15/2010
     **********************************************************************
     */
    virtual eError OnEndJPEGSampleCol
    (JSAMPROW samples,
     TSIZE samplesSize,
     TSIZE samplesRow,
     TSIZE samplesCol,
     JDIMENSION outputHeight,
     JDIMENSION outputWidth,
     int outputComponents,
     int outColorComponents,
     int actualNumberOfColors,
     J_COLOR_SPACE outColorSpace,
     JSAMPARRAY colorMap) 
#if defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        tDelegated* delegated;
        if ((delegated = Delegated()))
            error = delegated->OnEndJPEGSampleCol
            (samples, samplesSize, samplesRow, samplesCol, 
             outputHeight, outputWidth, outputComponents, 
             outColorComponents, actualNumberOfColors,
             outColorSpace, colorMap);
#if !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CJPEGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CJPEGREADEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CJPEGREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CJPEGREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CJPEGREADEREVENTS_HXX) || defined(CJPEGREADEREVENTS_MEMBERS_ONLY) */
