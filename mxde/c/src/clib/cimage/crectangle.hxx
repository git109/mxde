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
 *   File: crectangle.hxx
 *
 * Author: $author$
 *   Date: 8/30/2009
 **********************************************************************
 */
#ifndef _CRECTANGLE_HXX
#define _CRECTANGLE_HXX

#include "cimagebase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *   Enum: eRectangleSide
 *
 * Author: $author$
 *   Date: 8/30/2009
 **********************************************************************
 */
typedef int eRectangleSide;
enum
{
    e_RECTANGLE_SIDE_NONE   = 0,

    e_RECTANGLE_SIDE_LEFT   = (1 << 0),
    e_RECTANGLE_SIDE_TOP    = (1 << 1),
    e_RECTANGLE_SIDE_RIGHT  = (1 << 2),
    e_RECTANGLE_SIDE_BOTTOM = (1 << 3),

    e_RECTANGLE_SIDE_ALL    = (1 << 4)-1
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CRECTANGLE_HXX */

