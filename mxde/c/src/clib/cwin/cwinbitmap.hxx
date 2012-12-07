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
 *   File: cwinbitmap.hxx
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
#if !defined(_CWINBITMAP_HXX) || defined(CWINBITMAP_MEMBERS_ONLY)
#if !defined(_CWINBITMAP_HXX) && !defined(CWINBITMAP_MEMBERS_ONLY)
#define _CWINBITMAP_HXX
#endif /* !defined(_CWINBITMAP_HXX) && !defined(CWINBITMAP_MEMBERS_ONLY) */

#if !defined(CWINBITMAP_MEMBERS_ONLY)
#include "cwinhbitmapattached.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cWinBitmapExtends
 *
 *  Author: $author$
 *    Date: 7/24/2009
 **********************************************************************
 */
typedef cWinHBITMAP
cWinBitmapExtends;
/**
 **********************************************************************
 *  Class: cWinBitmap
 *
 * Author: $author$
 *   Date: 7/24/2009
 **********************************************************************
 */
class c_EXPORT_CLASS cWinBitmap
: public cWinBitmapExtends
{
public:
    typedef cWinBitmapExtends cExtends;
    
    TSIZE m_width, m_height;

    /**
     **********************************************************************
     *  Constructor: cWinBitmap
     *
     *       Author: $author$
     *         Date: 7/24/2009
     **********************************************************************
     */
    cWinBitmap
    (TSIZE width=0,
     TSIZE height=0,
     HBITMAP attached=NULL,
     bool isCreated=false)
    : cExtends(attached,isCreated),
      m_width(width),
      m_height(height)
    {
    }
    /**
     **********************************************************************
     *  Destructor: ~cWinBitmap
     *
     *      Author: $author$
     *        Date: 7/24/2009
     **********************************************************************
     */
    virtual ~cWinBitmap()
    {
    }
#else /* !defined(CWINBITMAP_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAP_MEMBERS_ONLY) */

    /**
     **********************************************************************
     * Function: Create
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual eError Create
    (HDC hDC, int width, int height,
     bool onlyDestroyed=false) 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        eError error2;
        HBITMAP detached;

        if ((error2 = Destroyed(onlyDestroyed)))
            return error2;

        if (!(detached = CreateDetached(error2, hDC, width,height)))
            return error2;

        if ((Attach(detached)))
        if ((SetIsCreated()))
            return e_ERROR_NONE;
        else
        Detach();

        DestroyDetached(detached);
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Destroy
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual eError Destroy
    (bool onlyCreated=false) 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NONE;
        eError error2;
        HBITMAP detached;

        if ((error2 = Created(onlyCreated, true)))
            return error2;

        SetIsCreated(false);

        if ((detached = Detach()))
            error = DestroyDetached(detached);

#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: CreateDetached
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual HBITMAP CreateDetached
    (eError& error, HDC hDC, int width, int height) const 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
        HBITMAP hBitmap = 0;
        error = e_ERROR_FAILED;
        if (hDC && (0 < width) && (0 < height))
        if (hBitmap = (CreateCompatibleBitmap(hDC, width,height)))
            error = e_ERROR_NONE;
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return hBitmap;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: DestroyDetached
     *
     *   Author: $author$
     *     Date: 8/5/2009
     **********************************************************************
     */
    virtual eError DestroyDetached
    (HBITMAP hBitmap) const 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
        eError error = e_ERROR_NOT_ATTACHED;
        if (hBitmap)
        if ((DeleteObject(hBitmap)))
            error = e_ERROR_NONE;
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: MaskedBlockTransferBits
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual eError MaskedBlockTransferBits
    (HDC hDC2,
     int x2,
     int y2,
     int width,
     int height,
     HDC hDC,
     HBITMAP mBitmap,
     int mX=0,
     int mY=0,
     int x=0,
     int y=0,
     DWORD mRop=SRCERASE,
     DWORD rop=SRCINVERT) 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        HBITMAP attached;
        HGDIOBJ hGDI;
        if ((hDC2) && (hDC) && (mBitmap))
        if ((attached = Attached()))
        {
            hGDI = SelectObject(hDC, mBitmap);
            error = e_ERROR_FAILED;

            if ((BitBlt(hDC2, x2,y2, width,height, hDC, mX,mY, mRop)))
            if ((SelectObject(hDC, attached)))
            if ((BitBlt(hDC2, x2,y2, width,height, hDC, x,y, rop)))
                error = e_ERROR_NONE;

            SelectObject(hDC, hGDI);
        }
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: BlockTransferBits
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual eError BlockTransferBits
    (HDC hDC2,
     int x2,
     int y2,
     int width,
     int height,
     HDC hDC,
     int x=0,
     int y=0,
     DWORD rop=SRCCOPY) const
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    = 0;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        eError error = e_ERROR_NOT_ATTACHED;
        HBITMAP attached;
        HGDIOBJ hGDI;
        if ((hDC2) && (hDC))
        if ((attached = Attached()))
        {
            hGDI = SelectObject(hDC, attached);

            if ((BitBlt(hDC2, x2,y2, width,height, hDC, x,y, rop)))
                error = e_ERROR_NONE;
            else error = e_ERROR_FAILED;

            SelectObject(hDC, hGDI);
        }
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        eError error = e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return error;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetWidth
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual TLENGTH SetWidth
    (TSIZE toWidth) 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    ;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH width = (m_width = toWidth);
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH width = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return width;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Width
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual TSIZE Width() const 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    ;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        TSIZE width = m_width;
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        TSIZE width = 0;
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return width;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */

    /**
     **********************************************************************
     * Function: SetHeight
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual TLENGTH SetHeight
    (TSIZE toHeight) 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    ;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        TLENGTH height = (m_height = toHeight);
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        TLENGTH height = -e_ERROR_NOT_IMPLEMENTED;
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return height;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */
    /**
     **********************************************************************
     * Function: Height
     *
     *   Author: $author$
     *     Date: 8/4/2009
     **********************************************************************
     */
    virtual TSIZE Height() const 
#if defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE)
    ;
#else /* CWINBITMAP_MEMBER_FUNCS_INTERFACE */
    {
#if !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) 
        TSIZE height = m_height;
#else /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        TSIZE height = 0;
#endif /* !defined(CWINBITMAP_MEMBER_FUNCS_IMPLEMENT) */
        return height;
    }
#endif /* defined(CWINBITMAP_MEMBER_FUNCS_INTERFACE) */

#if !defined(CWINBITMAP_MEMBERS_ONLY)
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CWINBITMAP_MEMBERS_ONLY) */
#endif /* !defined(CWINBITMAP_MEMBERS_ONLY) */

#endif /* !defined(_CWINBITMAP_HXX) || defined(CWINBITMAP_MEMBERS_ONLY) */
