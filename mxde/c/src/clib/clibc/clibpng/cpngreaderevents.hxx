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
 *   File: cpngreaderevents.hxx
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
#if !defined(_CPNGREADEREVENTS_HXX) || defined(CPNGREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CPNGREADEREVENTS_HXX) && !defined(CPNGREADEREVENTS_MEMBERS_ONLY)
#define _CPNGREADEREVENTS_HXX
#endif /* !defined(_CPNGREADEREVENTS_HXX) && !defined(CPNGREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CPNGREADEREVENTS_MEMBERS_ONLY)
#include "cpngreadereventsinterface.hxx"
#include "cinstancebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cPNGReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 1/13/2010
 **********************************************************************
 */
typedef cInstanceBase
cPNGReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cPNGReaderEvents
 *
 * Author: $author$
 *   Date: 1/13/2010
 **********************************************************************
 */
class c_INSTANCE_CLASS cPNGReaderEvents
: virtual public cPNGReaderEventsImplement,
  public cPNGReaderEventsExtend
{
public:
    typedef cPNGReaderEventsImplement cImplements;
    typedef cPNGReaderEventsExtend cExtends;
    
    cPNGReaderEventsInterface* m_delegated;
    
    /**
     **********************************************************************
     *  Constructor: cPNGReaderEvents
     *
     *       Author: $author$
     *         Date: 1/13/2010
     **********************************************************************
     */
    cPNGReaderEvents
    (cPNGReaderEventsInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cPNGReaderEvents
     *
     *      Author: $author$
     *        Date: 1/13/2010
     **********************************************************************
     */
    virtual ~cPNGReaderEvents()
    {
    }
#else /* !defined(CPNGREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnPNGPixel
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGPixel
    (cImagePixelInterface& pixel,
     BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGPixel
            (pixel, colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnBeginPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginPNGCol
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnEndPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndPNGCol
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPNGCol
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGCol
    (BYTE* colByte, TSIZE colBytes, TSIZE col, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGCol
            (colByte, colBytes, col, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginPNGRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnBeginPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginPNGRow
            (rowByte, rowBytes, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndPNGRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnEndPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndPNGRow
            (rowByte, rowBytes, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPNGRow
     *
     *   Author: $author$
     *     Date: 1/17/2010
     **********************************************************************
     */
    virtual eError OnPNGRow
    (BYTE* rowByte, TSIZE rowBytes, 
     TSIZE row, TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGRow
            (rowByte, rowBytes, row, 
             height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginPNGImage
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError OnBeginPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndPNGImage
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError OnEndPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnPNGImage
     *
     *   Author: $author$
     *     Date: 1/16/2010
     **********************************************************************
     */
    virtual eError OnPNGImage
    (TSIZE height, TSIZE width, 
     TSIZE bitDepth, TSIZE colorChannels,
     UINT colorType, UINT filterType, 
     UINT interlaceType, UINT compressionType) 
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cPNGReaderEventsInterface* delegated = 0;
        eError error2; 
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnPNGImage
            (height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType)))
            return error2;
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 1/13/2010
     **********************************************************************
     */
    virtual cPNGReaderEventsInterface* Delegated
    (cPNGReaderEventsInterface* delegated) const
#if defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        delegated = m_delegated;
#else /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        delegated = 0;
#endif /* !defined(CPNGREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CPNGREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CPNGREADEREVENTS_MEMBERS_ONLY)
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CPNGREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CPNGREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CPNGREADEREVENTS_HXX) || defined(CPNGREADEREVENTS_MEMBERS_ONLY) */
