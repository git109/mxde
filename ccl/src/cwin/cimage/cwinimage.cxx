/**
 **********************************************************************
 * Copyright (c) 1988-2006 $organization$
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
 *   File: cwinimage.cxx
 *
 * Author: $author$
 *   Date: 1/22/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "cwinimage.hxx"

/**
 **********************************************************************
 *  Class: cWinImage
 *
 * Author: $author$
 *   Date: 1/22/2006
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cWinImage::CreateColorImage
 *
 *   Author: $author$
 *     Date: 1/22/2006
 **********************************************************************
 */
cImageInterface* cWinImage::CreateColorImage
(int w, int h, int r, int g, int b, int o) 
{
    cImageInterface* image = 0;
    cWinColorImage* color;
    eError error;

    if ((color = new cWinColorImage(m_dc, true)))
    if ((error = color->CreateColor(w, h, r, g, b, o)))
        delete color;
    else
    {
        m_list.Add(&color->m_item);
        image = color;
    }
    return image;
}

