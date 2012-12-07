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
 *   File: cwinbitmapreaderevents.hxx
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAPREADEREVENTS_HXX) || defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY)
#if !defined(_CWINBITMAPREADEREVENTS_HXX) && !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY)
#define _CWINBITMAPREADEREVENTS_HXX
#endif /* !defined(_CWINBITMAPREADEREVENTS_HXX) && !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY) */

#if !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY)
#include "cwinbitmapreadereventsinterface.hxx"
#include "cwinrgbquadpixel.hxx"
#include "cwinrgbtriplepixel.hxx"
#include "cwinbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapReaderEventsExtend
 *
 *  Author: $author$
 *    Date: 12/15/2009
 **********************************************************************
 */
typedef cWinBase
cWinBitmapReaderEventsExtend;
/**
 **********************************************************************
 *  Class: cWinBitmapReaderEvents
 *
 * Author: $author$
 *   Date: 12/15/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmapReaderEvents
: virtual public cWinBitmapReaderEventsImplement,
  public cWinBitmapReaderEventsExtend
{
public:
    typedef cWinBitmapReaderEventsImplement cImplements;
    typedef cWinBitmapReaderEventsExtend cExtends;
    typedef cWinBitmapReaderEvents cDerives;
    
    typedef eError (cDerives::*MOnBitmapCol)
    (BYTE& colByte, TSIZE colBytes, TSIZE rowCol, TSIZE row);

    cWinBitmapReaderEventsInterface* m_delegated;
    MOnBitmapCol m_onBitmapCol;
    TSIZE m_colBytes;
    
    /**
     **********************************************************************
     *  Constructor: cWinBitmapReaderEvents
     *
     *       Author: $author$
     *         Date: 12/15/2009
     **********************************************************************
     */
    cWinBitmapReaderEvents
    (cWinBitmapReaderEventsInterface* delegated=0)
    : m_delegated(delegated),
      m_onBitmapCol(0),
      m_colBytes(0)
    {
    }
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: OnBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnBitmapPixel
    (cWinPixelInterface& pixel,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBitmapPixel
            (pixel,byte,bytes,col,row)))
            return error2;
            
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/18/2009
     **********************************************************************
     */
    virtual eError OnBitmapPixel
    (RGBQUAD& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBitmapPixel
            (rgb,byte,bytes,col,row)))
            return error2;
            
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        cWinRGBQUADPixel pixel(rgb);
        error = OnBitmapPixel(pixel, byte, bytes, col, row);
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBitmapPixel
     *
     *   Author: $author$
     *     Date: 12/18/2009
     **********************************************************************
     */
    virtual eError OnBitmapPixel
    (RGBTRIPLE& rgb,
     BYTE& byte,
     TSIZE bytes,
     TSIZE col,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBitmapPixel
            (rgb,byte,bytes,col,row)))
            return error2;
            
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        cWinRGBTRIPLEPixel pixel(rgb);
        error = OnBitmapPixel(pixel, byte, bytes, col, row);
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBitmapCol
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnBitmapCol
    (BYTE& colByte,
     TSIZE colBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBitmapCol
            (colByte,colBytes,rowCol,row)))
            return error2;
        
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        if ((m_onBitmapCol))
            error = (this->*m_onBitmapCol)
            (colByte, colBytes, rowCol, row);
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginBitmapRow
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginBitmapRow
            (rowByte,rowBytes,rowCols,row)))
            return error2;
            
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndBitmapRow
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnEndBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndBitmapRow
            (rowByte,rowBytes,rowCols,row)))
            return error2;
            
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnBitmapRow
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnBitmapRow
    (BYTE& rowByte,
     TSIZE rowBytes,
     TSIZE rowCols,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBitmapRow
            (rowByte,rowBytes,rowCols,row)))
            return error2;

#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        TSIZE rowCol;
        BYTE* colByte;
        
        if (!(error = OnBeginBitmapRow
            (rowByte, rowBytes, rowCols, row)))
        {
            for (colByte = &rowByte, rowCol = 0; 
                 rowCol < rowCols; rowCol++, colByte += m_colBytes)
            {
                if ((error = OnBitmapCol
                    (*colByte, m_colBytes, rowCol, row)))
                    return error;
            }
            error = OnEndBitmapRow
            (rowByte, rowBytes, rowCols, row);
        }
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: OnBeginBitmap
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnBeginBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnBeginBitmap
            (bits,cols,rows,planes)))
            return error2;
            
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: OnEndBitmap
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError OnEndBitmap
    (TSIZE bits,
     TSIZE cols,
     TSIZE rows,
     TSIZE planes) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NONE;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        eError error = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        cWinBitmapReaderEventsInterface* delegated = 0;
        eError error2;
        
        if ((delegated = Delegated(delegated)))
        if (0 <= (error2 = delegated->OnEndBitmap
            (bits,cols,rows,planes)))
            return error2;
            
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Delegated
     *
     *   Author: $author$
     *     Date: 12/19/2009
     **********************************************************************
     */
    virtual cWinBitmapReaderEventsInterface* Delegated
    (cWinBitmapReaderEventsInterface* delegated=0) const 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        delegated = (m_delegated); 
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return delegated;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: On2ColorBitmapCol
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError On2ColorBitmapCol
    (BYTE& colByte,
     TSIZE colBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: On256ColorBitmapCol
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError On256ColorBitmapCol
    (BYTE& colByte,
     TSIZE colBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: On16BitColorBitmapCol
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError On16BitColorBitmapCol
    (BYTE& colByte,
     TSIZE colBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: On24BitColorBitmapCol
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError On24BitColorBitmapCol
    (BYTE& colByte,
     TSIZE colBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        RGBTRIPLE& rgb = (((RGBTRIPLE&)(colByte)));
        error = OnBitmapPixel(rgb, colByte, colBytes, rowCol, row);
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: On32BitColorBitmapCol
     *
     *   Author: $author$
     *     Date: 12/16/2009
     **********************************************************************
     */
    virtual eError On32BitColorBitmapCol
    (BYTE& colByte,
     TSIZE colBytes,
     TSIZE rowCol,
     TSIZE row) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        eError error = e_ERROR_NONE;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        RGBQUAD& rgb = (((RGBQUAD&)(colByte)));
        error = OnBitmapPixel(rgb, colByte, colBytes, rowCol, row);
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetIs256ColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual int SetIs256ColorBitmap
    (bool isTrue=true) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        int is = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        is = (0 != (m_onBitmapCol = (isTrue?&cDerives::On256ColorBitmapCol:0)));
        m_colBytes = (isTrue)?1:0;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Is256ColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual bool Is256ColorBitmap() const 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        bool is = false;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        is = (0 != (m_onBitmapCol == &cDerives::On256ColorBitmapCol));
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetIs16BitColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual int SetIs16BitColorBitmap
    (bool isTrue=true) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        int is = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT)
        is = (0 != (m_onBitmapCol = (isTrue?&cDerives::On16BitColorBitmapCol:0)));
        m_colBytes = (isTrue)?2:0;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Is16BitColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual bool Is16BitColorBitmap() const 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        bool is = false;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        is = (0 != (m_onBitmapCol == &cDerives::On16BitColorBitmapCol));
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetIs24BitColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual int SetIs24BitColorBitmap
    (bool isTrue=true) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        int is = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        is = (0 != (m_onBitmapCol = (isTrue?&cDerives::On24BitColorBitmapCol:0)));
        m_colBytes = (isTrue)?3:0;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Is24BitColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual bool Is24BitColorBitmap() const 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        bool is = false;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        is = (0 != (m_onBitmapCol == &cDerives::On24BitColorBitmapCol));
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: SetIs32BitColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual int SetIs32BitColorBitmap
    (bool isTrue=true) 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        int is = -e_ERROR_NOT_IMPLEMENTED;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        is = (0 != (m_onBitmapCol = (isTrue?&cDerives::On32BitColorBitmapCol:0)));
        m_colBytes = (isTrue)?4:0;
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Is32BitColorBitmap
     *
     *   Author: $author$
     *     Date: 12/17/2009
     **********************************************************************
     */
    virtual bool Is32BitColorBitmap() const 
#if defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE)
     = 0;
#else /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
    {
        bool is = false;
#if !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) 
        is = (0 != (m_onBitmapCol == &cDerives::On32BitColorBitmapCol));
#else /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_IMPLEMENT) */
        return is;
    }
#endif /* defined(CWINBITMAPREADEREVENTS_MEMBER_FUNCS_INTERFACE) */
};


#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAPREADEREVENTS_HXX) || defined(CWINBITMAPREADEREVENTS_MEMBERS_ONLY) */
