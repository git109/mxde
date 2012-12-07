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
 *   File: cwindibitmap.hxx
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
#if !defined(_CWINDIBITMAP_HXX) || defined(CWINDIBITMAP_MEMBERS_ONLY)
#if !defined(_CWINDIBITMAP_HXX) && !defined(CWINDIBITMAP_MEMBERS_ONLY)
#define _CWINDIBITMAP_HXX
#endif /* !defined(_CWINDIBITMAP_HXX) && !defined(CWINDIBITMAP_MEMBERS_ONLY) */

#if !defined(CWINDIBITMAP_MEMBERS_ONLY)
#include "cwinbitmap.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinDIBitmapExtends
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cWinBitmap
cWinDIBitmapExtends;
/**
 **********************************************************************
 *  Class: cWinDIBitmap
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinDIBitmap
: public cWinDIBitmapExtends
{
public:
    typedef cWinDIBitmapExtends cExtends;
    typedef cWinDIBitmap cDerives;

    typedef BYTE* (cDerives::*MRow)
    (TLENGTH& length, TSIZE index) const;

    TSIZE m_bits, m_planes;
    TSIZE m_rowSize, m_imageSize;
    PBYTE m_pixel;

    MRow m_mRow;

    /**
     **********************************************************************
     *  Constructor: cWinDIBitmap
     *
     *       Author: $author$
     *         Date: 7/24/2009
     **********************************************************************
     */
    cWinDIBitmap
    (TSIZE width=0,
     TSIZE height=0,
     HBITMAP attached=NULL,
     bool isCreated=false)
    : cExtends(width, height, attached, isCreated),
      m_bits(0),
      m_planes(0),
      m_rowSize(0),
      m_imageSize(0),
      m_pixel(0),
      m_mRow(0)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinDIBitmap
     *
     *      Author: $author$
     *        Date: 7/24/2009
     **********************************************************************
     */
    virtual ~cWinDIBitmap()
    {
    }
    /**
     **********************************************************************
     * Function: Init
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    void Init()
    {
        m_width = 0;
        m_height = 0;
        m_bits = 0;
        m_planes = 0;
        m_rowSize = 0;
        m_imageSize = 0;
        m_pixel = 0;
        m_mRow = 0;
    }
#else /* !defined(CWINDIBITMAP_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAP_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    virtual eError Create
    (BITMAPINFO& bmi, HDC hDC,
     bool onlyDestroyed=false) 
#if defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_FAILED;
        eError error2;
        HBITMAP detached;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if ((detached = CreateDetached
            (error2, bmi, hDC, m_pixel)))
        {
            if (detached == (Attach(detached)))
            if (0 < (SetIsCreated()))
            {
                m_width = bmi.bmiHeader.biWidth;
                m_height = bmi.bmiHeader.biHeight;
                m_bits = bmi.bmiHeader.biBitCount;
                m_planes = bmi.bmiHeader.biPlanes;

                if (1 == m_planes)
                {
                    if (8 == m_bits)
                        m_rowSize = RowSizeOf(m_width);
                    else
                    if (24 == m_bits)
                        m_rowSize = RowSizeOf(m_width*3);
                    else
                    m_rowSize = 0;

                    if (m_rowSize)
                    {
                        m_imageSize = m_rowSize*m_height;
                        m_mRow = &cDerives::Row1Plane;
                        return e_ERROR_NONE;
                    }
                }
            }
            else Detach();

            DestroyDetached(detached);
            Init();
        }
#else /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        HBITMAP detached;

        if ((error = Created(onlyCreated, true)))
            return error;

        SetIsCreated(false);

        if ((detached = Detach()))
        if (!(DeleteObject(detached)))
            error = e_ERROR_FAILED;

        Init();
#else /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    virtual HBITMAP CreateDetached
    (eError& error, BITMAPINFO& bmi, HDC hDC, 
     PBYTE& pixel, UINT bmiColors=DIB_RGB_COLORS, 
     HANDLE hSection=NULL, DWORD dwOffset=0) 
#if defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAP_MEMBER_FUNCS_INTERFACE */
    {
        HBITMAP detached = NULL;
#if !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        if ((detached = CreateDIBSection
            (hDC, &bmi, bmiColors, 
             (void**)(&pixel), hSection, dwOffset)))
            error = e_ERROR_NONE;
        else
        error = e_ERROR_FAILED;
#else /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return detached;
    }
#endif /* defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 7/24/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (HBITMAP detached) 
#if defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        if (detached)
        if ((DeleteObject(detached)))
            error = e_ERROR_NONE;
#else /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: Row
     *
     *   Author: $author$
     *     Date: 7/25/2009
     **********************************************************************
     */
    virtual BYTE* Row
    (TLENGTH& length, TSIZE index) const 
#if defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINDIBITMAP_MEMBER_FUNCS_INTERFACE */
    {
        BYTE* byte = 0;
#if !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        length = -e_ERROR_NOT_ALLOWED;
        if (m_mRow)
            byte = (this->*m_mRow)(length, index);
#else /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        length = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINDIBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return byte;
    }
#endif /* defined(CWINDIBITMAP_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINDIBITMAP_MEMBERS_ONLY)
    /**
     **********************************************************************
     * Function: Row1Plane
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    BYTE* Row1Plane
    (TLENGTH& length, TSIZE index) const 
    {
        BYTE* byte = 0;

        if ((m_pixel) && (m_imageSize > (index *= m_rowSize)))
        {
            byte = (m_pixel + index);
            length = m_rowSize;
        }
        else
        length = -e_ERROR_FAILED;

        return byte;
    }
    /**
     **********************************************************************
     * Function: RowSizeOf
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual TSIZE RowSizeOf
    (TSIZE width) const
    {
        TSIZE size = width+((4-(width & 3)) & 3);
        return size;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINDIBITMAP_MEMBERS_ONLY) */
#endif /* !defined(CWINDIBITMAP_MEMBERS_ONLY) */

#endif /* !defined(_CWINDIBITMAP_HXX) || defined(CWINDIBITMAP_MEMBERS_ONLY) */
