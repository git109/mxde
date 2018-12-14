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
 *   File: cimage.cxx
 *
 * Author: $author$
 *   Date: 1/23/2006
 *
 *    $Id$
 **********************************************************************
 */

#include "cimage.hxx"

/**
 **********************************************************************
 *  Class: cImage
 *
 * Author: $author$
 *   Date: 1/23/2006
 **********************************************************************
 */

/**
 **********************************************************************
 * Function: cImage::CreateFilledCircleImage
 *
 *   Author: $author$
 *     Date: 1/23/2006
 **********************************************************************
 */
cImageInterface* cImage::CreateFilledCircleImage
(cImageInterface& color, int r, int q) 
{
    cImageInterface* image = 0;
    cFilledCircleImage* circle;

    if ((circle = new cFilledCircleImage(color, r, q)))
    {
        m_list.Add(&circle->m_item);
        image = circle;
    }
    return image;
}

/**
 **********************************************************************
 * Function: cImage::CreateFilledEllipseImage
 *
 *   Author: $author$
 *     Date: 1/23/2006
 **********************************************************************
 */
cImageInterface* cImage::CreateFilledEllipseImage
(cImageInterface& color, int w, int h) 
{
    cImageInterface* image = 0;
    cFilledEllipseImage* ellipse;

    if ((ellipse = new cFilledEllipseImage(color, w, h)))
    {
        m_list.Add(&ellipse->m_item);
        image = ellipse;
    }
    return image;
}

