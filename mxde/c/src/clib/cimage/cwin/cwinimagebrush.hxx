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
 *   File: cwinimagebrush.hxx
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
#ifndef _CWINIMAGEBRUSH_HXX
#define _CWINIMAGEBRUSH_HXX

#include "cwinimagebase.hxx"
#include "cwinbrush.hxx"
#include "cwinrect.hxx"

/**
 **********************************************************************
 *  Class: cWinImageBrush
 *
 * Author: $author$
 *   Date: 6/8/2009
 **********************************************************************
 */
class cWinImageBrush
: virtual public cImageBaseImplement,
  public cWinBrush
{
public:
    typedef cImageBaseImplement cImplements;
    typedef cWinBrush cExtends;
    typedef cWinImageBrush cDerives;

    cWinImageBase& m_winImage;

    /**
     **********************************************************************
     * Constructor: cWinImageBrush
     *
     *      Author: $author$
     *        Date: 6/8/2009
     **********************************************************************
     */
    cWinImageBrush
    (cWinImageBase& winImage,
     HBRUSH attached=NULL,
     bool isCreated=false) 
    : cExtends(attached,isCreated),
      m_winImage(winImage)
    {
    }

    /**
     **********************************************************************
     * Function: Plot
     *
     *   Author: $author$
     *     Date: 6/8/2009
     **********************************************************************
     */
    virtual eError Plot
    (tImageBaseInterface& image,
     tOffset x, tOffset y) 
    {
        eError error = e_ERROR_NONE;
        Fill(image, x,y, 1,1);
        return error;
    }
    /**
     **********************************************************************
     * Function: Fill
     *
     *   Author: $author$
     *     Date: 6/8/2009
     **********************************************************************
     */
    virtual eError Fill
    (tImageBaseInterface& image,
     tOffset x, tOffset y, tSize w, tSize h) 
    {
        eError error = e_ERROR_NONE;
        cWinRECT rect(x,y, x+w,y+h);
        HBRUSH hBrush;
        HDC hDC;
        if ((hBrush = Attached()))
        if ((hDC = m_winImage.Attached()))
            FillRect(hDC, &rect, hBrush);
        return error;
    }
};
#endif /* _CWINIMAGEBRUSH_HXX */
