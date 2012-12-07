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
 *   File: cstaticpngimagereaderitem.hxx
 *
 * Author: $author$
 *   Date: 11/12/2010
 **********************************************************************
 */
#if !defined(_CSTATICPNGIMAGEREADERITEM_HXX) || defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY)
#if !defined(_CSTATICPNGIMAGEREADERITEM_HXX) && !defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY)
#define _CSTATICPNGIMAGEREADERITEM_HXX
#endif /* !defined(_CSTATICPNGIMAGEREADERITEM_HXX) && !defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY) */

#if !defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY)
#include "cstaicimagereaderitem.hxx"
#include "cpngimagereader.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 * Typedef: cStaticPNGImageReaderItem
 *
 *  Author: $author$
 *    Date: 11/12/2010
 **********************************************************************
 */
typedef cStaicImageReaderItemT
<cPNGImageReader>
cStaticPNGImageReaderItem;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#else /* !defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY) */
#endif /* !defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY) */

#endif /* !defined(_CSTATICPNGIMAGEREADERITEM_HXX) || defined(CSTATICPNGIMAGEREADERITEM_MEMBERS_ONLY) */
