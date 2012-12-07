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
 *   File: cbmpreaderevents.hxx
 *
 * Author: $author$
 *   Date: 1/18/2010
 **********************************************************************
 */
#if !defined(_CBMPREADEREVENTS_HXX) || defined(CBMPREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CBMPREADEREVENTS_HXX) && !defined(CBMPREADEREVENTS_MEMBERS_ONLY)
#define _CBMPREADEREVENTS_HXX
#endif /* !defined(_CBMPREADEREVENTS_HXX) && !defined(CBMPREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CBMPREADEREVENTS_MEMBERS_ONLY)
#include "cbmpreadereventsinterface.hxx"
#include "cexportbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cBMPReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 1/18/2010
 **********************************************************************
 */
typedef cExportBase
cBMPReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cBMPReaderEvents
 *
 * Author: $author$
 *   Date: 1/18/2010
 **********************************************************************
 */
class c_EXPORT_CLASS cBMPReaderEvents
: virtual public cBMPReaderEventsImplement,
  public cBMPReaderEventsExtend
{
public:
    typedef cBMPReaderEventsImplement cImplements;
    typedef cBMPReaderEventsExtend cExtends;
    
    cBMPReaderEventsInterface* m_delegated;
    
    /**
     **********************************************************************
     *  Constructor: cBMPReaderEvents
     *
     *       Author: $author$
     *         Date: 1/18/2010
     **********************************************************************
     */
    cBMPReaderEvents
    (cBMPReaderEventsInterface* delegated=0)
    : m_delegated(delegated)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cBMPReaderEvents
     *
     *      Author: $author$
     *        Date: 1/18/2010
     **********************************************************************
     */
    virtual ~cBMPReaderEvents()
    {
    }
#else /* !defined(CBMPREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnBMPPixel
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPPixel
    (RGBQUAD& rgb,
     BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBMPPixel
            (rgb, colByte, colBytes, col, row, plane, 
             bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBMPPixel
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPPixel
    (RGBTRIPLE& rgb, 
     BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBMPPixel
            (rgb, colByte, colBytes, col, row, plane, 
             bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBMPCol
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPCol
    (BYTE& colByte, TSIZE colBytes, 
     TSIZE col, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBMPCol
            (colByte, colBytes, col, row, plane, 
             bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginBMPRow
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBeginBMPRow
    (BYTE& rowByte, TSIZE rowBytes, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginBMPRow
            (rowByte, rowBytes, row, plane, 
             bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndBMPRow
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnEndBMPRow
    (BYTE& rowByte, TSIZE rowBytes, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndBMPRow
            (rowByte, rowBytes, row, plane, 
             bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBMPRow
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPRow
    (BYTE& rowByte, TSIZE rowBytes, TSIZE row, TSIZE plane,
     TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBMPRow
            (rowByte, rowBytes, row, plane, 
             bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginBMPImage
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBeginBMPImage
    (TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginBMPImage
            (bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndBMPImage
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnEndBMPImage
    (TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndBMPImage
            (bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBMPImage
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual eError OnBMPImage
    (TSIZE bits, TSIZE cols, TSIZE rows, TSIZE planes) 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
        cBMPReaderEventsInterface* delegated = 0;
        eError error2;        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBMPImage
            (bits, cols, rows, planes)))
            return error2;
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 1/19/2010
     **********************************************************************
     */
    virtual cBMPReaderEventsInterface* Delegated
    (cBMPReaderEventsInterface* delegated) const 
#if defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        delegated = (m_delegated);
#else /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        delegated = 0;
#endif /* !defined(CBMPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CBMPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CBMPREADEREVENTS_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CBMPREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CBMPREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CBMPREADEREVENTS_HXX) || defined(CBMPREADEREVENTS_MEMBERS_ONLY) */
