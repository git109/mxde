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
 *   File: cstaicjpegimagereaderitem.hxx
 *
 * Author: $author$
 *   Date: 11/13/2010
 **********************************************************************
 */
#ifndef _CSTAICJPEGIMAGEREADERITEM_HXX
#define _CSTAICJPEGIMAGEREADERITEM_HXX

#include "cstaicimagereaderitem.hxx"
#include "cjpegimagereader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cStaicJPEGImageReaderItem
 *
 *  Author: $author$
 *    Date: 11/13/2010
 **********************************************************************
 */
typedef cStaicImageReaderItemT
<cJPEGImageReader>
cStaicJPEGImageReaderItem;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CSTAICJPEGIMAGEREADERITEM_HXX */
